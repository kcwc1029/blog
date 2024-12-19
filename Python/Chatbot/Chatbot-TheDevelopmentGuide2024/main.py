import os
from dotenv import load_dotenv
from openai import OpenAI
"""
NOTE: 初始化環境變量和 OpenAI API
使用 dotenv 加載環境變量，並初始化 OpenAI API 密鑰。
"""
# 加載 .env 文件
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")  # 從 .env 文件讀取 API 密鑰
openai = OpenAI(api_key=OPENAI_API_KEY)  # 初始化 OpenAI 客戶端
 
response = openai.images.generate(
    prompt="幫我生成一個好看的微肉美女",
    n=1,
    size="1024x1024"
)

image_url = response.data[0].url
print(response.data[0])
print()
print(image_url)