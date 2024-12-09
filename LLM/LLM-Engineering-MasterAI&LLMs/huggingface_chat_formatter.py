"""
TODO: 將一組結構化的訊息轉換為模型友好的輸入格式（Prompt）
"""
from dotenv import load_dotenv
import os
from huggingface_hub import login
from transformers import AutoTokenizer

# 加載環境變數
load_dotenv()
hf_token = os.getenv('HUGGING_FACE_TOKEN')
login(hf_token, add_to_git_credential=True) #  自動將 HuggingFace 的登錄憑據（即 Token）添加到 Git 的憑據管理器中。

# NOTE: 使用該模型需要Request Access
tokenizer = AutoTokenizer.from_pretrained('meta-llama/Meta-Llama-3.1-8B-Instruct', trust_remote_code=True)

"""
構建對話訊息列表，包含三種角色：
1. 系統 (system)：描述助理的行為或設定。
2. 用戶 (user)：用戶的輸入或提問。
3. 助理 (assistant)：模型的生成回應（由 Prompt 引導）。
"""
messages = [
    {"role": "system", "content": "You are a helpful assistant"},
    {"role": "user", "content": "Tell a light-hearted joke for a room of Data Scientists"}
  ]

"""
使用 apply_chat_template 方法將訊息格式化為模型友好的 Prompt。
參數說明：
- messages：對話訊息列表。
- tokenize=False：不進行 Token 化，僅生成純文本格式。
- add_generation_prompt=True：附加生成提示，引導模型生成回應。
"""
prompt = tokenizer.apply_chat_template(messages, tokenize=False, add_generation_prompt=True)
print(prompt)
# You are a helpful assistant<|eot_id|><|start_header_id|>user<|end_header_id|>

# Tell a light-hearted joke for a room of Data Scientists<|eot_id|><|start_header_id|>assistant<|end_header_id|>