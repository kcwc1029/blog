"""
這是一個基於 OpenAI GPT 模型和 Gradio 圖形介面的互動聊天應用程式

- 使用 OpenAI 的 GPT 模型（預設為 gpt-4o-mini）生成回應。
- 支援多輪對話，記錄歷史訊息以保留上下文。
- Gradio 圖形介面：提供一個即時的聊天界面，用於輸入訊息並接收 GPT 的回應。
    - 使用 gr.ChatInterface，專為聊天應用設計。
- 啟用流式模式 (stream=True)，即時顯示 GPT 回應的逐步內容。
"""

import os
from dotenv import load_dotenv
from openai import OpenAI
import gradio as gr

# 配置類，集中管理變數
class CFG:
    MODEL = 'gpt-4o-mini'
    system_message = "你是一個有用的助手"

# 載入環境變數
load_dotenv()
openai_api_key = os.getenv('OPENAI_API_KEY')
openai = OpenAI()

def chat(message, history):
    messages = [{"role": "system", "content": CFG.system_message}] + history + [{"role": "user", "content": message}]

    print("History is:")
    print(history)
    print("And messages is:")
    print(messages)

    stream = openai.chat.completions.create(model=CFG.MODEL, messages=messages, stream=True)

    response = ""
    for chunk in stream:
        response += chunk.choices[0].delta.content or ''
        yield response

if __name__ == "__main__":
    ##### 啟用 Gradio 界面 #####
    view = gr.ChatInterface(fn=chat, type="messages")
    view.launch(share=True)  # 啟動 Gradio 界面，支持公用鏈接
