"""
TODO: 
用於展示如何使用 HuggingFace 的 AutoTokenizer 對文本進行 tokenization（編碼）與 解碼 操作。主要操作流程包括：使用 API Token 登錄 HuggingFace 平台，下載特定模型的 Tokenizer，並對文字進行處理。
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
tokenizer = AutoTokenizer.from_pretrained('meta-llama/Meta-Llama-3.1-8B', trust_remote_code=True)

text = "I am excited to show Tokenizers in action to my LLM engineers"
tokens = tokenizer.encode(text)  # 將文本轉換為 token 編碼列表
print(len(tokens))  # 輸出 token 的數量
print(tokens)  # 輸出 token 的編碼
# 4. 將 tokens 解碼回原始文本
print(tokenizer.decode(tokens))  # 解碼為文本
# 5. 批量解碼（此處與單句解碼類似）
print(tokenizer.batch_decode(tokens))
# 6. 獲取詞彙表中的自定義詞
# print(tokenizer.get_added_vocab())
