import os
from dotenv import load_dotenv
from openai import OpenAI
from fastapi import FastAPI, Form, Request, WebSocket
from typing import Annotated
from fastapi.templating import Jinja2Templates
from fastapi.responses import HTMLResponse

"""
NOTE: 初始化環境變量和 OpenAI API
使用 dotenv 加載環境變量，並初始化 OpenAI API 密鑰。
"""
# 加載 .env 文件
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")  # 從 .env 文件讀取 API 密鑰
openai = OpenAI(api_key=OPENAI_API_KEY)  # 初始化 OpenAI 客戶端

"""
NOTE: 初始化對話歷史
chat_history 保存所有對話歷史，用於提供上下文給 OpenAI API。
chat_response 是傳遞給前端的對話記錄。
"""
chat_history = [{"role": "system", "content": "你是一位教授"}]  # 初始化對話歷史
chat_response = []  # 用於返回給 HTML 模板的對話記錄

# 初始化 FastAPI 應用
app = FastAPI()

"""
NOTE: 設定模板目錄
Jinja2Templates 用於渲染 HTML 模板文件。
"""
templates = Jinja2Templates(directory="templates")  # 設定模板目錄


"""
NOTE: 使用websocket
"""
@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()  # 接受 WebSocket 連線
    while True:
        user_input = await websocket.receive_text()  # 接收文字訊息
        print(f"收到訊息: {user_input}")

        # STEP 1: 添加用戶輸入到對話歷史
        chat_history.append({"role": "user", "content": user_input})
        chat_response.append(f"User: {user_input}")
        try:
            # STEP 2: 使用 OpenAI API 生成回應
            response = openai.chat.completions.create(
                model="gpt-3.5-turbo",  # 指定 GPT 模型版本
                messages=chat_history,  # 提供完整的對話上下文
                temperature=0.7,  # 控制生成的隨機性 (越高越隨機)
                stream=True
            )
            # STEP 3: 獲取 AI 的回應並更新對話歷史
            ai_response = ""
            for chunk in response:
                if chunk.choices[0].delta.content is not None:
                    ai_response+=chunk.choices[0].delta.content
                    await websocket.send_text(f"{chunk.choices[0].delta.content}")  # 發送回應訊息
            chat_history.append({"role": "assistant", "content": ai_response})  # 將回應添加到歷史記錄
            chat_response.append(f"Assistant: {ai_response}")  # 將回應添加到前端顯示的記錄

            # 生成完後，在一次返回
            # ai_response = response.choices[0].message.content  # 取得 AI 的文本回應
            # await websocket.send_text(f"{ai_response}")  # 發送回應訊息
            # chat_history.append({"role": "assistant", "content": ai_response})  # 將回應添加到歷史記錄
            # chat_response.append(f"Assistant: {ai_response}")  # 將回應添加到前端顯示的記錄

        except Exception as e:
            await websocket.send_text(f"ERROR: {e}")  # 發送回應訊息
            break


"""
NOTE: GET 方法 - 渲染聊天頁面
此方法用於初始頁面加載，顯示 HTML 界面和歷史對話。
"""
@app.get("/", response_class=HTMLResponse)
async def chat_page(request: Request):
    """
    渲染首頁模板並顯示現有對話紀錄
    """
    return templates.TemplateResponse("home.html", {"request": request, "chat_response": chat_response})