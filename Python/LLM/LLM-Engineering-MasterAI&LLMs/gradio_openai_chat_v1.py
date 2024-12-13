"""
這是一個基於 OpenAI GPT 模型和 Gradio 圖形介面工具的互動式聊天應用程式

與 GPT 模型交互：
- 使用 OpenAI 的 GPT 模型（預設為 gpt-4o-mini）來生成回應。
- 自訂的系統提示用於設定聊天的背景或角色。

圖形介面：
- 使用 Gradio 提供網頁式的圖形介面，允許使用者輸入訊息並即時接收 GPT 模型的回應。
- 靈活性與可擴展性：

使用方式：
- 透過配置類 (CFG) 集中管理模型名稱和系統消息。
- 使用 .env 檔案管理 OpenAI API 金鑰，確保程式的安全性和靈活性。
"""

import os
from dotenv import load_dotenv
from openai import OpenAI
import gradio as gr

# 配置類，集中管理變數
class CFG:
    system_message = "你是一個有用的助手"
    MODEL = "gpt-4o-mini"

# 載入環境變數
load_dotenv()
api_key = os.getenv('OPENAI_API_KEY')
openai = OpenAI()

# 處理 GPT 消息
def message_gpt(user_message):
    """
    與 GPT 模型交互，返回回應。

    :param user_message: 使用者的輸入訊息
    :return: GPT 的回應
    """
    messages = [
        {"role": "system", "content": CFG.system_message},
        {"role": "user", "content": user_message}
    ]
    completion = openai.chat.completions.create(
        model=CFG.MODEL,
        messages=messages,
        
    )
    return completion.choices[0].message.content

if __name__ == "__main__":
    ##### 啟用 Gradio 界面 ##### 
    view = gr.Interface(
        fn=message_gpt,  # 函數接受輸入參數
        inputs=gr.Textbox(label="Your message:", lines=6),  # 單個輸入
        outputs=gr.Textbox(label="Response:", lines=8),  # 單個輸出
    )
    view.launch()  # 啟動 Gradio 界面
