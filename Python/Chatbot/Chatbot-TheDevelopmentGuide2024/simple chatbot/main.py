import os
from dotenv import load_dotenv
from openai import OpenAI
from fastapi import FastAPI, Form, Request
from typing import Annotated
from fastapi.templating import Jinja2Templates
from fastapi.responses import HTMLResponse

"""
NOTE: 初始化環境變量和 OpenAI API
使用 dotenv 加載環境變量，並初始化 OpenAI API 密鑰。
"""
# 加載 .env 文件
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")
openai = OpenAI(api_key=OPENAI_API_KEY)

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
templates = Jinja2Templates(directory="templates")


"""
NOTE: GET 方法 - 渲染聊天頁面
此方法用於初始頁面加載，顯示 HTML 界面和歷史對話。
"""
@app.get("/", response_class=HTMLResponse)
async def chat_page(request: Request):
    return templates.TemplateResponse("home.html", {"request": request, "chat_response": chat_response})


"""
NOTE: POST 方法 - 處理用戶輸入並生成回應
1. 接收用戶輸入 (user_input)。
2. 調用 OpenAI API 生成回應。
3. 更新對話歷史 (chat_history 和 chat_response)。
4. 將對話記錄返回給 HTML 界面。
"""
@app.post("/", response_class=HTMLResponse)
async def handle_chat(request: Request, user_input: str = Form(...)):  # 使用 Form() 來處理表單數據
    # 添加用戶輸入到對話歷史
    chat_history.append({"role": "user", "content": user_input})
    chat_response.append(f"User: {user_input}")

    # 使用 OpenAI API 生成回應
    response = openai.chat.completions.create(
        model="gpt-3.5-turbo",  # 使用 GPT-3.5-turbo 模型
        messages=chat_history,  # 傳遞對話歷史
        temperature=0.7  # 控制生成的隨機性 (越高越隨機)
    )

    # 獲取 AI 的回應
    ai_response = response.choices[0].message.content
    chat_history.append({"role": "assistant", "content": ai_response})  # 添加 AI 回應到歷史
    chat_response.append(f"Assistant: {ai_response}")

    # 返回更新後的 HTML 頁面
    return templates.TemplateResponse("home.html", {"request": request, "chat_response": chat_response})