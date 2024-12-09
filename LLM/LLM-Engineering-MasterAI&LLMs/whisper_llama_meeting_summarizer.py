"""
此腳本的功能是：
1. 使用 OpenAI 的 Whisper 模型進行語音轉文字。
2. 將文字內容通過 Meta Llama 模型生成 Markdown 格式的會議記錄。
"""

import os
from dotenv import load_dotenv
import requests
from openai import OpenAI
from huggingface_hub import login
from transformers import AutoTokenizer, AutoModelForCausalLM, TextStreamer, BitsAndBytesConfig
import torch

# 配置類，定義模型名稱和音頻文件路徑
class CFG:
    """
    此類保存腳本的配置，包括音頻模型名稱和音頻文件的路徑。
    """
    AUDIO_MODEL = "whisper-1"  # OpenAI Whisper 模型名稱
    audio_filename = "./音樂測試.mp3"  # 音頻文件路徑

# 加載環境變數
"""
從 .env 文件中加載環境變數，並初始化 Hugging Face 和 OpenAI 的 API 金鑰。
"""
load_dotenv()  # 加載 .env 文件中的變數
hf_token = os.getenv('HUGGING_FACE_TOKEN')  # Hugging Face Token
login(hf_token, add_to_git_credential=True)  # 登錄 Hugging Face，快取憑據
openai_api_key = os.getenv('OPENAI_API_KEY')  # OpenAI API Key
openai = OpenAI(api_key=openai_api_key)  # 初始化 OpenAI 客戶端

# 語音轉錄部分
"""
使用 OpenAI 的 Whisper 模型將音頻文件轉錄為文字。
"""
audio_file = open(CFG.audio_filename, "rb")  # 以二進制格式打開音頻文件
transcription = openai.audio.transcriptions.create(
    model=CFG.AUDIO_MODEL,  # 使用 Whisper 模型
    file=audio_file,  # 傳入音頻文件
    response_format="text"  # 輸出文字格式
)
print(transcription)  # 打印轉錄結果

# LLAMA 模型部分
"""
將轉錄結果通過 Meta Llama 模型生成 Markdown 格式的會議記錄。
"""
LLAMA = "meta-llama/Meta-Llama-3.1-8B-Instruct"  # 使用的 Llama 模型名稱
system_message = (
    "你是一個助理，負責根據會議的文字記錄生成會議記錄，"
    "包括摘要、關鍵討論點、結論以及行動項目及負責人，格式為 Markdown。"
)  # 系統提示信息

# 構造用戶輸入
"""
將會議轉錄內容與系統提示整合為模型輸入消息。
"""
user_prompt = f"以下是一次丹佛市議會會議的文字記錄摘要。請以 Markdown 格式撰寫會議記錄，包括摘要（參會者、地點和日期）、討論點、結論，以及行動項目和負責人。\n{transcription}"
messages = [
    {"role": "system", "content": system_message},  # 系統角色信息
    {"role": "user", "content": user_prompt}  # 用戶提供的輸入
]

# 配置量化參數
"""
啟用模型量化配置，使用 4-bit 模型以減少內存消耗。
"""
quant_config = BitsAndBytesConfig(
    load_in_4bit=True,  # 啟用 4-bit 量化
    bnb_4bit_use_double_quant=True,  # 使用雙量化技術
    bnb_4bit_compute_dtype=torch.bfloat16,  # 設置計算精度
    bnb_4bit_quant_type="nf4"  # 設置量化類型
)

# 初始化 Tokenizer 和模型
"""
加載 Tokenizer 和 Meta Llama 模型，並將消息轉換為張量格式。
"""
tokenizer = AutoTokenizer.from_pretrained(LLAMA)  # 加載 Llama Tokenizer
tokenizer.pad_token = tokenizer.eos_token  # 設置填充標記
inputs = tokenizer.apply_chat_template(messages, return_tensors="pt").to("cuda")  # 將消息轉換為張量
streamer = TextStreamer(tokenizer)  # 初始化流式輸出器
model = AutoModelForCausalLM.from_pretrained(
    LLAMA,
    device_map="auto",  # 自動分配設備
    quantization_config=quant_config  # 使用量化配置
)

# 生成 Markdown 格式會議記錄
"""
通過模型生成會議記錄，最大生成令牌數為 2000。
"""
outputs = model.generate(inputs, max_new_tokens=2000, streamer=streamer)
