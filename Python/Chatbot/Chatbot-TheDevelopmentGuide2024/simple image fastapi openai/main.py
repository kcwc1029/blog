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

"""
NOTE: 設定模板目錄
Jinja2Templates 用於渲染 HTML 模板文件。
"""
templates = Jinja2Templates(directory="templates")  # 設定模板目錄


@app.get("/")
async def first_api():
    return {
        "message":"hello TA"
    }

@app.get("/image", response_class=HTMLResponse)
async def chat_page(request: Request):
    return templates.TemplateResponse("image.html", {"request": request, "history": chat_history})

@app.post("/image", response_class=HTMLResponse)
async def image_page(request: Request, user_input:Annotated[str, Form()]):
    response = openai.images.generate(
        prompt=user_input,
        n=1,
        size="1024x1024"
    )
    image_url = response.data[0].url
    print("image_url", image_url)
    return templates.TemplateResponse("image.html", {"request": request, "image_url": image_url})