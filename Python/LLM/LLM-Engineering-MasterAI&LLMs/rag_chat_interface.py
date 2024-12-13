"""
基於 Retrieval-Augmented Generation (RAG) 技術的聊天機器人，結合了 OpenAI 的 GPT 模型和 Gradio 界面，用於處理基於特定文件內容的問題回答。

1. 從 Markdown 文件讀取內容並分段處理。
2. 利用分段後的內容提供上下文支持的回答。
3. 使用 Gradio 介面提供互動式聊天功能。
"""

import os
from dotenv import load_dotenv
from openai import OpenAI
import gradio as gr
from langchain.text_splitter import CharacterTextSplitter

class CFG:
    MODEL = "gpt-4o-mini"  # 模型名稱，可以根據需要更改

##### 加載環境變數並初始化 OpenAI 客戶端 #####
load_dotenv()
openai_api_key = os.getenv('OPENAI_API_KEY')
openai = OpenAI(api_key=openai_api_key)

##### 讀取並處理 RAG 文件 #####
file_path = "RAG_test.md"
with open(file_path, "r", encoding="utf-8") as f:
    markdown_content = f.read()

##### 文件分段處理 #####
splitter = CharacterTextSplitter(separator="\n", chunk_size=500, chunk_overlap=50) # 每段長度：500 字符  重疊部分：50 字符
chunks = splitter.split_text(markdown_content)

# NOTE: 查看上下文
print(splitter)
print()
print(chunks)

# 系統訊息設定
"""
定義系統角色的說明與回應規則：
- 明確系統的專業角色（保險問題專家）。
- 強調回答的準確性與誠實性。
"""
system_message = """
你是 Insurellm 這家保險科技公司的問題回答專家，專門提供準確的解答。
請給出簡潔且準確的回答。如果你不知道答案，請直接說不知道。
如果沒有相關上下文支持，請不要編造任何內容。
"""

##### 增加相關上下文的函數 #####
def add_relevant_context(user_message):  # 將使用者的問題與文件上下文結合
    """
    輸入：用戶問題（字串）
    功能：提取文件中的相關上下文，與用戶問題結合。
    輸出：附加上下文的問題字串。
    """
    relevant_context = "\n".join(chunks[:2])  # 此處簡單取前兩段作為範例
    # 調試輸出，打印傳入的問題和生成的上下文
    print("用戶問題：")
    print(user_message)
    print("\n相關上下文：")
    print(relevant_context)
    print("-" * 50)  # 分隔線
    return f"{user_message}\n\n相關內容：\n{relevant_context}"

##### Chat 接口 #####
def chat(message, history):  # 定義聊天邏輯
    """
    輸入：message（用戶輸入的問題），history（歷史對話記錄）
    功能：根據問題與歷史對話，生成基於上下文的回答。
    輸出：ChatGPT 模型的回應（以串流形式返回）。
    """
    # 建構對話歷史和當前問題
    messages = [{"role": "system", "content": system_message}] + history
    message_with_context = add_relevant_context(message)
    messages.append({"role": "user", "content": message_with_context})

    # 生成回應
    stream = openai.chat.completions.create(model=CFG.MODEL, messages=messages, stream=True)
    response = ""
    for chunk in stream:
        response += chunk.choices[0].delta.content or ''
        yield response

##### 啟動 Gradio Chat 介面 #####
view = gr.ChatInterface(chat, type="messages").launch()
