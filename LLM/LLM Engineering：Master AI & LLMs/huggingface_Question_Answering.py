# TODO: 執行 Question Answering (QA) 任務，即基於給定的上下文回答問題。
import os  
from huggingface_hub import login  # 用於登錄 HuggingFace Hub
from transformers import pipeline  # 用於執行 NLP 任務的高層 API
from dotenv import load_dotenv 

# 加載環境變量
load_dotenv()  # 讀取 .env 文件
hf_token = os.getenv('HUGGING_FACE_TOKEN')  # 獲取 HuggingFace Token
login(hf_token, add_to_git_credential=True)  # 登錄 HuggingFace Hub

# Question Answering with Context
question_answerer = pipeline("question-answering")
result = question_answerer(question="Who was the 44th president of the United States?", context="Barack Obama was the 44th president of the United States.")
print(result)



