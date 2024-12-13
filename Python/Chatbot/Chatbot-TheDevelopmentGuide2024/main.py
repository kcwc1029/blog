import os
from dotenv import load_dotenv
from openai import OpenAI
from fastapi import FastAPI, Form, Request
from typing import Annotated
from fastapi.templating import Jinja2Templates
from fastapi.responses import HTMLResponse

# 加載 .env 文件
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")
openai = OpenAI(api_key=OPENAI_API_KEY)
chat_history = [{"role": "system", "content": "你是一位教授"}] # 初始化對話歷史

# 初始化API
app = FastAPI()
templates = Jinja2Templates(directory="templates")



@app.get("/", response_class=HTMLResponse)
async def chat_page(request: Request):
    return templates.TemplateResponse("index.html", {"request": request, "history": chat_history})











    # # 添加用戶輸入到對話歷史
    # chat_history.append({"role": "user", "content": user_input})
    # # 使用 OpenAI API 生成回應
    # response = openai.chat.completions.create(
    #     model="gpt-3.5-turbo",
    #     messages=chat_history,
    #     temperature=0.7
    # )
    # # 獲取 AI 的回應
    # ai_response = response.choices[0].message.content
    # # 添加 AI 回應到對話歷史
    # chat_history.append({"role": "assistant", "content": ai_response})
    # return ai_response