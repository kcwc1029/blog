# TODO: 執行情感分析任務
import os  
from huggingface_hub import login  # 用於登錄 HuggingFace Hub
from transformers import pipeline  # 用於執行 NLP 任務的高層 API
from dotenv import load_dotenv 

# 加載環境變量
load_dotenv()  # 讀取 .env 文件
hf_token = os.getenv('HUGGING_FACE_TOKEN')  # 獲取 HuggingFace Token
login(hf_token, add_to_git_credential=True)  # 登錄 HuggingFace Hub

# 使用 HuggingFace 的 "sentiment-analysis" 模型
classifier = pipeline("sentiment-analysis")
result = classifier("This idea of yours? Totally groundbreaking… if we were in 1995.") # 該模型只適用於英文
print(result) # [{'label': 'POSITIVE', 'score': 0.9997093081474304}]

