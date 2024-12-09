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
    """
    儲存程序配置，包括模型名稱和用戶消息。
    """
    # instruct models
    LLAMA = "meta-llama/Meta-Llama-3.1-8B-Instruct"  # Meta-LLaMA 模型
    PHI3 = "microsoft/Phi-3-mini-4k-instruct"       # Microsoft Phi3 模型
    GEMMA2 = "google/gemma-2-2b-it"                # Google Gemma2 模型
    QWEN2 = "Qwen/Qwen2-7B-Instruct"               # Qwen2 模型
    messages = [
        {"role": "system", "content": "你是一個講笑話大師"},  # 系統角色
        {"role": "user", "content": "請你講一個好笑的笑話。逗逗壓力大的研究生"}  # 使用者請求
    ]


##### 加載環境變數 #####
load_dotenv()  # 從 .env 檔案中載入環境變數。
hf_token = os.getenv('HUGGING_FACE_TOKEN')  # 取得 HuggingFace 的 API Token。
login(hf_token, add_to_git_credential=True)  # 登錄 HuggingFace，並將憑據快取。

##### 設定模型量化參數(quantization) #####
quant_config = BitsAndBytesConfig(
    load_in_4bit=True,  # 啟用 4-bit 量化技術。
    bnb_4bit_use_double_quant=False,  # 若 GPU 支援 CUDA，可啟用雙重量化。
    bnb_4bit_compute_dtype=torch.bfloat16,  # 使用 bfloat16 計算格式，保留精度並降低記憶體需求。
    bnb_4bit_quant_type="nf4"  # 使用最佳化的 "nf4" 量化技術。
)


##### 分詞器初始化 #####
def generate(model, messages):
    """
    用於初始化模型和分詞器，生成輸出並清理資源。
    
    - model: 模型名稱
    - messages: 用戶輸入的對話內容
    """
    snapshot_download(CFG.LLAMA)  # 如果模型不存在於本地，會下載到快取中。
    tokenizer = AutoTokenizer.from_pretrained(model)  # 加載分詞器
    tokenizer.pad_token = tokenizer.eos_token  # 設置填充符號
    inputs = tokenizer.apply_chat_template(messages, return_tensors="pt").to("cuda")  # 將消息轉為 PyTorch 張量
    streamer = TextStreamer(tokenizer)  # 流式生成文字
    model = AutoModelForCausalLM.from_pretrained(model, device_map="auto", quantization_config=quant_config)  # 加載模型
    outputs = model.generate(inputs, max_new_tokens=200, streamer=streamer)  # 生成文字
    del tokenizer, streamer, model, inputs, outputs  # 清理內存
    torch.cuda.empty_cache()  # 釋放 GPU 資源


if __name__ == "__main__":
    generate(CFG.QWEN2, CFG.messages)  # 使用 Qwen2 模型生成對話


