"""
- 增加stream流
- 輸出轉為markdown模式
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

# 處理 GPT 消息（流式處理）
def message_gpt(user_message):
    messages = [
        {"role": "system", "content": CFG.system_message},
        {"role": "user", "content": user_message}
    ]
    stream = openai.chat.completions.create(
        model='gpt-4o-mini',
        messages=messages,
        stream=True # TODO: 增加stream
    )
    result = ""
    for chunk in stream:
        result += chunk.choices[0].delta.content or ""
        yield result

if __name__ == "__main__":
    ##### 啟用 Gradio 界面 ##### 
    view = gr.Interface(
        fn=message_gpt,  # 函數接受輸入參數
        inputs=gr.Textbox(label="Your message:", lines=6),  # 單個輸入
        outputs=gr.Markdown(label="Response:"),  # TODO: Markdown輸出
    )
    view.launch()  # 啟動 Gradio 界面
