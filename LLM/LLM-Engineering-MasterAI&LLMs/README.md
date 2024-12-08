## 1. 安裝最小模型：llama3.2

```bash
// 使用命令拉取模型，例如 llama3.2
ollama pull llama3.2

// 驗證模型是否可用
ollama list

// 測試模型運行
ollama run llama3.2

// 提供一個簡單的輸入測試
ollama run llama3.2 --prompt "Hello, how are you?"
```

## 2. 確認本地 ollama 是否安裝完成

-   [http://localhost:11434/](http://localhost:11434/)

## 3. 將 API_KEY 放到.env

```bash
OPENAI_API_KEY=...
```

## 4. 連接到 OpenAI

```python
from dotenv import load_dotenv
import os

load_dotenv()
api_key = os.getenv('OPENAI_API_KEY')
print(api_key)
```

## 5. 提示類型(Types of prompts )

-   system prompt：告訴他們正在執行什麼任務以及他們應該使用什麼語氣
-   user prompt： 他們應該回復的對話贊助者

## 6. Project：透過 OpenAI API + 爬蟲對網站內容總結

-   website_summary_tool.py

## 7. Project：python 操作 ollama

-   website_summary_ollama.py

## 8. Gradio 框架：構建用戶介面

-   https://www.gradio.app/
-   先做好 openAI 的基本提問程式碼。

```python
import os
from dotenv import load_dotenv
from openai import OpenAI

class CFG:
    system_message = "你是一個有用的助手"
    prompt = "今天禮拜幾"
    MODEL = "gpt-4o-mini"


load_dotenv()
api_key = os.getenv('OPENAI_API_KEY')
openai = OpenAI()




def message_gpt():
    messages = [
        {"role": "system", "content": CFG.system_message},
        {"role": "user", "content": CFG.prompt}
    ]
    completion = openai.chat.completions.create(
        model=CFG.MODEL,
        messages=messages,
    )
    return completion.choices[0].message.content




if __name__ == "__main__":
    summary = message_gpt()
    print(summary)
```

-   使用 gradio 建立基本介面

![upgit_20241130_1732971897.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241130_1732971897.png)

```python
import gradio as gr

def shout(text):
    print(f"Shout has been called with input {text}")
    return text.upper()


if __name__ == "__main__":
    gr.Interface(fn=shout, inputs="textbox", outputs="textbox").launch(share=True)
# NOTE: share=True 會建立一個public link
```

-   Gradio 強制建立 dark mode

```python
import gradio as gr

force_dark_mode = """
function refresh() {
    const url = new URL(window.location);
    if (url.searchParams.get('__theme') !== 'dark') {
        url.searchParams.set('__theme', 'dark');
        window.location.href = url.href;
    }
}
"""


def shout(text):
    print(f"Shout has been called with input {text}")
    return text.upper()


if __name__ == "__main__":
    gr.Interface(fn=shout, inputs="textbox", outputs="textbox", js=force_dark_mode).launch(share=True)
# NOTE: share=True 會建立一個public link
```

## 9. Project：openai 結合 graido 介面

-   [gradio_openai_chat_v1.py](./gradio_openai_chat_v1.py)
-   [gradio_openai_chat_v2.py](./gradio_openai_chat_v2.py)

## 10. Project：OpenAI GPT 和 Gradio 圖形介面的互動聊天應用程式

-   [interactive_openai_chat.py](./interactive_openai_chat.py)

## 11. Project：計算機概論助手

-   計算機概論助手\_chat_interface.py

## 12. Project：openAI 利用 DALL-E 生成圖片(但要注意費用)

![upgit_20241201_1733059794.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241201_1733059794.png)

-   要注意每一張的生成費用
-   dalle_image_generator.py

## 13. openAI 結合音訊

### 13.1. 要先安裝 FFmpeg：

-   【下載點】https://github.com/BtbN/FFmpeg-Builds/releases

![upgit_20241201_1733060485.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241201_1733060485.png)

-   將下載的文件解壓到電腦上的某個位置（例如，C：\ffmpeg）
-   將 FFmpeg bin 資料夾新增到系統 PATH 中：(例如，C：\ffmpeg\bin)
-   測試：`ffmpeg -version`

![upgit_20241201_1733060882.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241201_1733060882.png)

## 14. OpenAI 語音助手範例

-   模型選用 tts-1
-   openai_voice_assistant.py

## 15. Agent Framework(代理 AI)

-   AI Agent 是一個能夠模擬「自主性」並執行複雜任務的人工智慧系統框架。它不僅回應單一提示，而是能夠規劃、協作並使用工具來完成特定目標。

## 16. AI Agent 的核心特性

-   任務分解 (Task Decomposition)
    -   將複雜問題分解為更小的步驟。
    -   使用多個大語言模型 (LLMs) 處理不同專門任務。
-   工具使用 (Tool Utilization)
    -   Agent 能夠使用外部工具來提升自身的能力，如資料分析、執行腳本、或存取 API。
-   代理環境 (Agent Environment)
    -   提供一個協作平台，允許多個 Agents 或 LLMs 之間進行互動與協作。
-   計劃功能 (Planner Role)
    -   某些 LLM 作為 Planner，負責將大型目標拆分為更小的專門任務，並分配給適合的 Agent 執行。
-   自主性 (Autonomy)
    -   Agent 具有一定的自主性，例如記憶功能 (Memory)，能夠保留先前的上下文或操作歷史，進一步執行連貫性任務。

## 17. HuggingFace

-   https://huggingface.co/

-   HuggingFace 是一家專注於人工智慧和機器學習的公司，以其自然語言處理 (NLP) 工具和資源聞名，致力於幫助開發者簡化機器學習技術的使用。
-   開源且易用：HuggingFace 的工具設計簡單易用，即使是初學者也能快速上手，完成自然語言處理任務。

### 17.1. 主要功能與產品

-   Transformers：提供多種預訓練模型（如 BERT、GPT），適用於各類 NLP 任務。
-   Datasets：高效數據集庫，支持數據加載、處理與格式輸出。
-   Hub：共享平台，方便用戶下載或上傳模型、數據集與代碼。
-   Inference API：即時推理服務，無需本地環境配置即可調用模型。

### 17.2. 使用 HuggingFace Pipelines

```bash
pip install -q transformers datasets diffusers
```

```python
# 在HuggingFace設定好API後，放到.env
# 執行，確認是否可以登入
import torch
from huggingface_hub import login
from transformers import pipeline
from diffusers import DiffusionPipeline
from datasets import load_dataset
import soundfile as sf
from dotenv import load_dotenv
import os

load_dotenv()
hf_token = os.getenv('HUGGING_FACE_TOKEN')
login(hf_token, add_to_git_credential=True)
print(hf_token)
```

## 18. Project：Huggingface API 測試：情感分析

-   -   [huggingface_sentiment_analysis.py](./huggingface_sentiment_analysis.py)

## 19. Project：Huggingface API 測試：自動識別文本中的命名實體

-   [huggingface_Named_Entity_Recognition.py](./huggingface_Named_Entity_Recognition.py)

## 20. Project：Huggingface API 測試：回答基於提供的上下文（context）和問題（question）的問題。

-   [huggingface_Question_Answering.py](./huggingface_Question_Answering.py)

## 21. Tokenizer

-   Tokenizer 是用於將文本（Text）轉換為模型可以理解的單位（Tokens）的工具。它是深度學習模型（例如 GPT、BERT）的重要組件之一。

### 21.1. 文本和 Tokens 之間的轉換

-   Tokenizer 可以使用 encode() 和 decode() 方法在 文本（Text） 和 Tokens（模型的基本輸入單位） 之間進行轉換。
-   encode()：將自然語言的句子轉換為數字化的 tokens，這些 tokens 是模型的輸入。
-   decode()：將模型輸出的 tokens 轉換回可讀的自然語言文本。

```python
from transformers import AutoTokenizer
tokenizer = AutoTokenizer.from_pretrained("bert-base-uncased")

# Encode
tokens = tokenizer.encode("Hello, how are you?")
print(tokens)  # [101, 7592, 1010, 2129, 2024, 2017, 102]

# Decode
text = tokenizer.decode(tokens)
print(text)  # "hello, how are you?
```

### 21.2. 包含特殊標記的詞彙表：

-   每個 Tokenizer 都包含一個詞彙表（Vocabulary），用於定義可以被模型處理的單詞或字符。
-   詞彙表中還包括特殊標記（Special Tokens），這些標記用於提示模型，例如：
    -   [CLS]：表示句子的開始。
    -   [SEP]：表示句子之間的分隔符。
    -   [PAD]：用於補齊句子的長度。

### 21.3. 支持對話模板

-   這對於聊天模型（如 GPT 系列）特別有用，因為它們需要知道消息的結構，例如：
    -   用戶輸入的部分
    -   機器回應的部分
    -   上下文信息

```plaintext
// 假設有一段聊天：
User: What's the weather today?
Assistant: It's sunny and warm.

// Tokenized 格式可能會是：
<User>: What's the weather today?
<Assistant>: It's sunny and warm.
```

### 21.4. HuggingFace AutoTokenizer 編碼與解碼操作

-   [tokenizer_demo.py](../LLM%20Engineering：Master%20AI%20&%20LLMs/tokenizer_demo.py)：用於展示如何使用 HuggingFace 的 AutoTokenizer 對文本進行 tokenization（編碼）與 解碼 操作。主要操作流程包括：使用 API Token 登錄 HuggingFace 平台，下載特定模型的 Tokenizer，並對文字進行處理。

## 22. Instruct variants of models

-   Instruct 模型 是經過額外訓練的模型版本，專門用於處理具有結構化提示（prompts）的輸入。
-   它們的名稱通常會在尾部帶有 "Instruct"，例如 Llama-3.1-8B-Instruct。
-   這些模型適合在對話（Chat）中使用，能更好地理解並生成針對性回應。
-   apply_chat_template() 是一個實用方法，可以將傳統對話格式（例如聊天記錄）轉換為模型可以理解的輸入格式。

```
// 假設你有以下對話
用戶：你好！今天的天氣如何？
助手：今天晴天，氣溫25度，非常適合出門。

// 通過 apply_chat_template，可以將它轉換為模型適配的結構化輸入格式
System: 你是一個天氣助手，回答用戶的問題。
User: 你好！今天的天氣如何？
Assistant: 今天晴天，氣溫25度，非常適合出門。
```

-   [huggingface_chat_formatter.py](./huggingface_chat_formatter.py)

## 23. Models

### 23.1. Project: 使用 HuggingFace 提供的 Meta-LLaMA 模型 進行對話式 AI 的開發

![upgit_20241206_1733496602.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241206_1733496602.png)

-   分詞器 (Tokenizer)：將文字輸入轉換為模型可以處理的 tokens。
-   量化 (Quantization)：減少記憶體佔用，讓大型模型能在有限硬體資源下運行。
-   模型推理 (Inference)：生成回應，根據使用者提供的問題給出答案。
-   GPU 整合：利用 CUDA 加速深度學習模型運算。

```bash
# 執行以下指令安裝依賴
pip install  requests torch bitsandbytes transformers sentencepiece accelerate

# 安裝支援 CUDA 的 bitsandbytes
pip install --upgrade bitsandbytes

# 安裝 CUDA 工具包 CUDA https://reurl.cc/b3EGEM
```

-   [quantized_inference.py](./quantized_inference.py)

### 23.2. Project: 針對 quantized_inferene 增加流式輸出功能（Streaming）

-   [quantized_inference_stream.py](./quantized_inference_stream.py)

## 24. Project：會議語音轉文字並生成 Markdown 格式會議記錄

-   安裝套件 `pip install requests torch bitsandbytes transformers sentencepiece accelerate openai httpx==0.27.`

-   [whisper_llama_meeting_summarizer.py](./whisper_llama_meeting_summarizer.py)
