"""
這份程式展示了如何使用 HuggingFace 提供的 Meta-LLaMA 模型進行對話生成。
包含的功能包括：
- 分詞器初始化
- 模型量化
- 推理及文字生成
- GPU 資源管理

- 要安裝的東西 https://reurl.cc/b3EGEM(確保已安裝支持 GPU 的 CUDA 和 cuDNN。)
- 要安裝支持 CUDA 的 bitsandbytes  pip install --upgrade bitsandbytes
- 將 HuggingFace 的 API Token 儲存在 .env 文件中
"""
from dotenv import load_dotenv
import os
from huggingface_hub import login, snapshot_download
from transformers import AutoTokenizer, AutoModelForCausalLM, TextStreamer, BitsAndBytesConfig
import torch

class CFG:
    # instruct models
    LLAMA = "meta-llama/Meta-Llama-3.1-8B-Instruct"
    PHI3 = "microsoft/Phi-3-mini-4k-instruct"
    GEMMA2 = "google/gemma-2-2b-it"
    QWEN2 = "Qwen/Qwen2-7B-Instruct" # exercise for you
    messages = [
        {"role": "system", "content": "你是一個體貼的好女孩"},
        {"role": "user", "content": "為一個工程科學系研究生講一個笑話，讓他開心一點"}
    ]

##### 加載環境變數 #####
load_dotenv()  # 從 .env 檔案中載入環境變數。
hf_token = os.getenv('HUGGING_FACE_TOKEN')  # 取得 HuggingFace 的 API Token。
login(hf_token, add_to_git_credential=True)  # 登錄 HuggingFace，並將憑據快取。

##### 設定模型量化參數 #####
quant_config = BitsAndBytesConfig(
    load_in_4bit=True,  # 啟用 4-bit 量化技術。
    bnb_4bit_use_double_quant=False,  # 若 GPU 支援 CUDA，可啟用雙重量化。
    bnb_4bit_compute_dtype=torch.bfloat16,  # 使用 bfloat16 計算格式，保留精度並降低記憶體需求。
    bnb_4bit_quant_type="nf4"  # 使用最佳化的 "nf4" 量化技術。
)

##### 分詞器初始化 #####
snapshot_download(CFG.LLAMA)  # 如果模型不存在於本地，會下載到快取中。
tokenizer = AutoTokenizer.from_pretrained(CFG.LLAMA)  # 加載分詞器。
tokenizer.pad_token = tokenizer.eos_token  # 設置填充值為結束符。

##### 準備模型輸入 #####
inputs = tokenizer.apply_chat_template(  # 將對話內容轉換為模型可讀的格式。
    CFG.messages,
    return_tensors="pt"  # 輸出 PyTorch 張量，便於計算。
)

##### 加載模型 #####
model = AutoModelForCausalLM.from_pretrained(
    CFG.LLAMA, 
    device_map="auto",  # 自動將模型分配至 GPU。
    quantization_config=quant_config  # 套用量化設定。
)

##### 生成文字輸出 #####
outputs = model.generate(inputs, max_new_tokens=80)  # 根據輸入生成回應，最大 80 個 tokens。
print(tokenizer.decode(outputs[0]))  # 解碼 tokens 為可讀文字，並輸出。

##### 清理資源 #####
del inputs, outputs, model  # 刪除變數以釋放記憶體。
torch.cuda.empty_cache()  # 清空 GPU 快取記憶體。