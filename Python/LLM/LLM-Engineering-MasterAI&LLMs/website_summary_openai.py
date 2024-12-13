# NOTE: 此程式是一個網站摘要工具，結合 Python 的 requests、BeautifulSoup 和 OpenAI API，用於從指定的網站抓取內容並生成簡短摘要

import requests
from bs4 import BeautifulSoup
from openai import OpenAI
from dotenv import load_dotenv
import os

load_dotenv()
api_key = os.getenv('OPENAI_API_KEY')

class CFG:
    model="gpt-4o-mini"
    # 測試網站 URL
    test_url = "https://publications.eai.eu/index.php/airo/article/view/2983"

    



##### 定義系統提示，用於提供 AI 的角色設定 #####
system_prompt = "你是一個可以分析網站內容的助手，並提供簡短摘要，忽略可能是導航相關的文字。請以 Markdown 格式回應。"

##### 根據網站內容生成用戶提示 #####
def user_prompt_for(website):
    """
    接收網站的內容，生成用戶提示。

    :param website: 包含網站標題和內容的字典
    :return: 用戶提示內容（字串）
    """
    user_prompt = f"""您正在查看一個名為 {website['title']} 的網站。
        以下是該網站的內容；
        請用 Markdown 格式為這個網站提供簡短的摘要。
        如果網站包含新聞或公告，請一併總結。\n\n
    """
    user_prompt += website['text']  # 添加網站的文本內容
    return user_prompt





##### 從 URL 抓取網站內容 #####
def fetch_website_content(url):
    """
    抓取網站內容，包括標題和純文字內容。

    :param url: 網站的 URL
    :return: 包含標題和內容的字典
    """
    response = requests.get(url)  # 發送 HTTP GET 請求
    soup = BeautifulSoup(response.text, 'html.parser')  # 解析 HTML
    title = soup.title.string if soup.title else "無標題"  # 獲取網站標題
    text = soup.get_text()  # 提取純文字內容
    return {"title": title, "text": text}  # 返回標題和內容





##### 生成消息列表，作為 ChatGPT API 的輸入 #####
def messages_for(website):
    """
    根據網站內容生成消息列表。

    :param website: 包含網站標題和內容的字典
    :return: 消息列表（供 OpenAI API 使用）
    """
    return [
        {"role": "system", "content": system_prompt},  # 系統提示
        {"role": "user", "content": user_prompt_for(website)}  # 用戶提示
    ]





##### 定義摘要函式，呼叫 OpenAI 的 ChatGPT API #####
def summarize(url):
    """
    使用 OpenAI API 生成網站內容摘要。

    :param url: 網站的 URL
    :return: ChatGPT 生成的摘要內容
    """
    # 抓取網站內容
    website = fetch_website_content(url)
    # 構造消息列表
    messages = messages_for(website)
    # 初始化 OpenAI 物件
    openai = OpenAI()
    # 呼叫 OpenAI API
    response = openai.chat.completions.create(
        model=CFG.model,  # 使用的模型
        messages=messages  # 消息列表
    )
    return response.choices[0].message.content # 返回 API 回應的摘要內容


if __name__ == "__main__":
    summary = summarize(CFG.test_url) # 生成摘要
    print(summary)
