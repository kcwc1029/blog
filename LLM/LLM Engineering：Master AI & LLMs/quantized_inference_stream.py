"""
這份程式展示了如何使用 HuggingFace 提供的 Meta-LLaMA 模型進行對話生成。
包含的功能包括：
- 分詞器初始化
- 模型量化
- 推理及文字生成
- GPU 資源管理

- 要安裝的東西 https://reurl.cc/b3EGEM
- 要安裝支持 CUDA 的 bitsandbytes  pip install --upgrade bitsandbytes

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
        {"role": "system", "content": "You are a humorous AI assistant."},
        {"role": "user", "content": "Please tell a science-related joke for an engineering graduate student to make them happy."}
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
def generate(model, messages):
    snapshot_download(CFG.LLAMA)  # 如果模型不存在於本地，會下載到快取中。
    tokenizer = AutoTokenizer.from_pretrained(model)
    tokenizer.pad_token = tokenizer.eos_token
    inputs = tokenizer.apply_chat_template(messages, return_tensors="pt").to("cuda")
    streamer = TextStreamer(tokenizer)
    model = AutoModelForCausalLM.from_pretrained(model, device_map="auto", quantization_config=quant_config)
    outputs = model.generate(inputs, max_new_tokens=200, streamer=streamer)
    print(tokenizer.decode(outputs[0]))

    del tokenizer, streamer, model, inputs, outputs
    torch.cuda.empty_cache()

if __name__ == "__main__":
    generate(CFG.QWEN2, CFG.messages)


