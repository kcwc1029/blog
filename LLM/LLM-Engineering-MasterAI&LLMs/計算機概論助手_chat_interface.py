"""
這是一個專為計算機概論課程設計的聊天機器人，
使用 OpenAI 的 API 提供智慧回應，並以 Gradio 提供直覺的操作介面。
"""

import os
import json
from dotenv import load_dotenv
from openai import OpenAI
import gradio as gr

class CFG:
    MODEL = "gpt-4o-mini"
    system_message = """
        你是一位工程科學系計算機概論課程的助教。
        請提供簡潔且清晰的回答，不超過2-3句，適合初學者理解。
        重點放在計算機概論的核心內容，例如程式設計基礎、算法與資料結構。
        如果你不知道答案，請坦誠告知，並建議學生可參考的資源或學習方向。
    """

load_dotenv()
openai_api_key = os.getenv('OPENAI_API_KEY')
openai = OpenAI()

def chat(message, history):
    messages = [{"role": "system", "content": CFG.system_message}] + history + [{"role": "user", "content": message}]
    response = openai.chat.completions.create(model=CFG.MODEL, messages=messages)
    return response.choices[0].message.content

gr.ChatInterface(fn=chat, type="messages").launch()
