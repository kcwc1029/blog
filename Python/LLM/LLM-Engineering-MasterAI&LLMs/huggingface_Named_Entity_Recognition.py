# TODO: Named Entity Recognition (NER) 自動識別文本中的命名實體
import os  
from huggingface_hub import login  # 用於登錄 HuggingFace Hub
from transformers import pipeline  # 用於執行 NLP 任務的高層 API
from dotenv import load_dotenv 

# 加載環境變量
load_dotenv()  # 讀取 .env 文件
hf_token = os.getenv('HUGGING_FACE_TOKEN')  # 獲取 HuggingFace Token
login(hf_token, add_to_git_credential=True)  # 登錄 HuggingFace Hub

# Named Entity Recognition
ner = pipeline("ner", grouped_entities=True)
result = ner("Barack Obama was the 44th president of the United States.")
print(result)
# [
#     {'entity_group': 'PER', 'score': 0.99918306, 'word': 'Barack Obama', 'start': 0, 'end': 12},
#     {'entity_group': 'LOC', 'score': 0.9986908, 'word': 'United States', 'start': 43, 'end': 56}
# ]



