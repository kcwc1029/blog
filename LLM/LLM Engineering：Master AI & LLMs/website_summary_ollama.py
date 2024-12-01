# TODO: 此程式是一個網站摘要生成工具，主要功能是抓取指定網站的內容（包括標題和文字），並使用 Ollama 的 llama3.2 模型生成網站內容的簡短摘要。
import ollama
from dotenv import load_dotenv
import os
import requests
from bs4 import BeautifulSoup

# 設定類，集中管理變數
class CFG:
    MODEL = "llama3.2"
    SYSTEM_PROMPT = "你是一個可以分析網站內容的助手，並提供簡短摘要，忽略可能是導航相關的文字。請以 Markdown 格式回應。"
    test_url = "https://publications.eai.eu/index.php/airo/article/view/2983"





##### 從 URL 抓取網站內容 #####
def fetch_website_content(url):
    """
    抓取網站內容，包括標題和純文字內容。

    :param url: 網站的 URL
    :return: 包含標題和內容的字典
    """
    try:
        response = requests.get(url)  # 發送 HTTP GET 請求
        response.raise_for_status()  # 檢查 HTTP 請求是否成功
        soup = BeautifulSoup(response.text, 'html.parser')  # 解析 HTML
        title = soup.title.string if soup.title else "無標題"  # 獲取網站標題
        text = soup.get_text()  # 提取純文字內容
        return {"title": title, "text": text.strip()}  # 返回標題和內容
    except requests.RequestException as e:
        raise RuntimeError(f"無法抓取網站內容：{e}")





##### 根據網站內容生成用戶提示 #####
def user_prompt_for(website):
    """
    接收網站的內容，生成用戶提示。

    :param website: 包含網站標題和內容的字典
    :return: 用戶提示內容（字串）
    """
    return f"""您正在查看一個名為「{website['title']}」的網站。
以下是該網站的內容：
請用 Markdown 格式為這個網站提供簡短的摘要。
如果網站包含新聞或公告，請一併總結。\n\n{website['text']}"""





##### 生成消息列表 #####
def messages_for(website):
    """
    根據網站內容生成消息列表。

    :param website: 包含網站標題和內容的字典
    :return: 消息列表
    """
    return [
        {"role": "system", "content": CFG.SYSTEM_PROMPT},
        {"role": "user", "content": user_prompt_for(website)}
    ]





##### 使用 Ollama 模型生成摘要 #####
def summarize(url):
    """
    使用 Ollama 模型生成摘要。

    :param url: 網站的 URL
    :return: 摘要內容（字串）
    """
    try:
        website = fetch_website_content(url)  # 抓取網站內容
        messages = messages_for(website)  # 構建消息
        response = ollama.chat(model=CFG.MODEL, messages=messages)  # 使用 Ollama 生成摘要
        return response.get("message", {}).get("content", "無法生成摘要")
    except Exception as e:
        return f"摘要生成失敗：{e}"




##### 主函式 #####
if __name__ == "__main__":
    summary = summarize(CFG.test_url)
    print(summary)