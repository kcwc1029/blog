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

## 10. Project：OpenAI GPT 和 Gradio 圖形介面的互動聊天應用程式(#PAPER)

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

-   用於展示如何使用 HuggingFace 的 AutoTokenizer 對文本進行 tokenization（編碼）與 解碼 操作。主要操作流程包括：使用 API Token 登錄 HuggingFace 平台，下載特定模型的 Tokenizer，並對文字進行處理。
-   [tokenizer_demo.py](./tokenizer_demo.py)

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

## 25. Chinchilla Scaling Law

-   模型參數的數量應該與訓練數據的數量成正比。
-   如果增加訓練數據（tokens）卻沒有相應調整模型參數數量，模型的性能提升會逐漸遞減（diminishing returns）。

這張圖片列出了 7 種常見的基準測試 (Benchmarks)，用於評估大型語言模型 (LLMs) 的性能。以下是詳細說明：

---

## 26. 種常見的基準測試 (Benchmarks)，用於評估大型語言模型 (LLMs) 的性能

| Benchmark  | What's being evaluated | Description                                                                              |
| ---------- | ---------------------- | ---------------------------------------------------------------------------------------- |
| ARC        | Reasoning              | 用於評估科學推理能力的基準，包含多選題。                                                 |
| DROP       | Language Comp          | 要求從文本中提取細節，然後進行加法、計數或排序等操作，測試模型的語言理解能力。           |
| HellaSwag  | Common Sense           | 測試模型的常識推理能力，題目設計更具挑戰性，包含「更難的結尾、長上下文和低數據量活動」。 |
| MMLU       | Understanding          | 測試模型在 57 個主題上的事實回憶、推理和解決問題的能力。                                 |
| TruthfulQA | Accuracy               | 測試模型在對抗性條件下提供真實回覆的能力，即模型是否能避免生成錯誤或虛假的答案。         |
| Winogrande | Context                | 測試模型是否理解上下文並能解決歧義的能力。                                               |
| GSM8K      | Math                   | 測試模型解決數學問題的能力，題目來自小學和初中的數學和文字題。                           |

## 27. 個特定基準測試

| Benchmark | What's being evaluated | Description                                                                                       |
| --------- | ---------------------- | ------------------------------------------------------------------------------------------------- |
| ELO       | Chat                   | 通過與其他 LLMs 的正面對決 (head-to-head face-offs) 評估性能，類似國際象棋中的 ELO 等級分數評估。 |
| HumanEval | Python Coding          | 包含 164 道基於 docstrings（文檔字符串）的編碼問題，測試模型的 Python 代碼生成能力。              |
| MultiPL-E | Broader Coding         | 將 HumanEval 的問題翻譯成 18 種程式語言，測試模型在多語言編程中的能力。                           |

---

## 28. 選擇和評估大型語言模型 (LLMs)六個排行榜 (Leaderboards)

-   HuggingFace Open LLM(匯總新版本和舊版本的開放式 LLM 模型)
-   HuggingFace BigCode(專注於編程相關的基準和模型)
-   HuggingFace LLM Perf(專注於 LLM 性能的綜合評估)
-   HuggingFace Others(涵蓋 Hugging Face 上針對特定領域的模型排行榜)
-   Vellum(聚焦於 API 使用成本和上下文窗口大小。)
-   SEAL(評估專家技能相關模型的表現)

## 29. RAG 基礎知識

-   建立知識庫：構建專家信息的數據庫，稱為知識庫（Knowledge Base），作為模型的輔助資源。
-   基於用戶問題進行檢索：每當用戶提出問題時，模型會在知識庫中檢索相關的內容。
-   在提示中加入相關細節：將從知識庫中檢索到的相關信息整合到提示中，提供更具針對性的輸出。

![upgit_20241209_1733737187.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241209_1733737187.png)

### 29.1. Vector Embeddings(向量嵌入)

-   表示文本（或其他數據）特徵的數字化方法。
-   將文字、句子甚至整篇文章轉換成數字列表（向量），這些數字捕捉了數據的語意關係。
    -   句子 "我喜歡貓" 可能被轉換成 [0.8, -0.2, 0.6]，而句子 "我愛狗" 可能被轉換成 [0.75, -0.15, 0.65]，因為它們的語意相近，所以它們的向量也很接近。

### 29.2. 向量嵌入的作用

-   捕捉語意：向量嵌入能表示文本的語意，而不只是字面的意思。
-   高效比較：一旦將文本轉換為向量，計算兩個向量的相似性就非常高效
-   支持下游任務：檢索、分類、聚類

### 29.3. RAG 的工作原理

-   RAG 一種結合檢索與生成的技術。

### 29.4. Project：RAG(靜態文件) 和 OpenAI 模型的對話介面

![upgit_20241209_1733744351.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241209_1733744351.png)

-   [rag_chat_interface.py](./rag_chat_interface.py)

## 30. LangChain

-   LangChain 是一個框架，用於構建基於語言模型的應用。
-   它能幫助你將 LLM 與外部工具（如檔案資料庫、檢索系統）結合。
-   LangChain 有自己的宣告式語言，稱為 LangChain Expression Language (LCEL)。
-   安裝套件：`pip install -U langchain-community`
-

### 30.1. Project：RAG 從資料庫中檢索相關的上下文（檔案中的內容）並進行處理

-   演示 RAG 的核心步驟之一：從資料庫中檢索相關的上下文（檔案中的內容）並進行處理。這種處理是為了在生成型 AI（如 GPT 模型）使用時，提供相關上下文來增強答案的準確性和針對性。
-   [rag_base_loader.py](./rag_base_loader.py)

## 31. Vector Embedding Models

-   Word2Vec (2013)：
    -   最早期的向量嵌入模型之一，由 Google 團隊推出。
    -   它基於單詞的上下文窗口學習語義，例如「我喜歡貓」中的「喜歡」和「貓」會有相關聯的向量。
-   BERT (2018)：
    -   Google 開發的雙向語言模型，全名是 "Bidirectional Encoder Representations from Transformers"。
    -   支持句子級別和段落級別的向量嵌入。
-   OpenAI Embeddings (2024 Updates)

### 31.1. Auto-Regressive

-   逐步生成內容：模型的輸出是基於「過去的內容」來預測「下一個詞元」。
-   每次輸出一個詞元（Token），然後將其追加到輸入中，作為下一次生成的基礎。
-   使用自回歸生成方式，適合寫作、問答等創作型任務(GPT-2、GPT-3、GPT-4、Transformer)

### 31.2. Auto-Encoding LLMs

-   基於「完整的輸入」生成結果，而不是逐步生成。
-   例子：Google 的 BERT 模型(常用於分類和嵌入生成任務)。

## 32. Chroma

-   Chroma 是一個用於處理和存儲嵌入向量的高效向量數據庫
-   主要用途是支持基於語義相似度的檢索。
-   可以在 RAG 作為核心組件來存儲和檢索文本的嵌入向量。
-   安裝套件`pip install chromadb` # langchain_chroma 是基於 ChromaDB 的工具
-   安裝套件`pip install -U langchain-chroma`

### 32.1. Project：實現向量存儲(Vector Store)+3D 可視化

-   實現了一個完整的 向量存儲（Vector Store）流程，用於將 Markdown 文件轉換為嵌入向量，存儲到向量數據庫（Chroma）中，並進一步可視化這些向量的分佈。

![upgit_20241209_1733749987.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241209_1733749987.png)

![upgit_20241209_1733750140.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241209_1733750140.png)

-   [vector_store_visualizer.py](./vector_store_visualizer.py)

### 32.2. Project：實現一個基於 LangChain 和 OpenAI 的文檔檢索與聊天機器人系統

![upgit_20241209_1733754008.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241209_1733754008.png)

-   跟 [rag_chat_interface.py](./rag_chat_interface.py)相比，統雖然更複雜，但是能夠處理更多的文檔，提供更豐富的上下文支持
    具體功能包括：
-   Markdown 文件加載與處理
-   文檔切割與向量化處理
-   對話檢索與生成
-   Gradio 聊天介面
-   [langchain_chat_retrieval.py](./langchain_chat_retrieval.py)

## 33. Fine-Tuning Large Language Models

-   尋找&製作數據集
    -   Kaggle
    -   HuggingFace datasets
-   數據處理的六個步驟：
    -   Investigate（調查）：探索和檢查數據，了解數據的來源、結構和內容。
    -   Parse（解析）：將數據拆解成結構化或可操作的形式，方便後續處理。
    -   Visualize（視覺化）：使用圖表或其他可視化方法來呈現數據，幫助更好地理解數據。
    -   Assess Data Quality（評估數據質量）：檢查數據的準確性、完整性以及是否存在異常值或缺失值。
    -   Curate（整理）：根據需求篩選和清理數據，確保數據質量適合分析。
    -   Save（保存）：將處理過的數據存儲下來，供未來分析或應用使用。

## 34. Prompting、RAG 和 Fine-tuning 的優點

-   Prompting (提示調整)
    -   Fast to implement (快速實現)：提示調整很容易部署，幾乎不需要進行額外的模型訓練。
    -   Low cost (成本低)：因為不需要大規模的數據和計算資源，成本相對較低。
    -   Often immediate improvement (通常能帶來即時效果)：通過改變提示設計，可以快速提升模型的效果。
-   RAG (Retrieval-Augmented Generation，檢索增強生成)
    -   Accuracy improvement with low data needs (低數據需求即可提升準確性)：通過結合外部檢索機制，可以在不需要大量數據的情況下顯著提升模型的準確性。
    -   Scalable (可擴展)：可以處理大規模數據和複雜場景，適合多樣化應用。
    -   Efficient (高效)：在處理具有多樣性的查詢時表現良好。
-   Fine-tuning (微調)
    -   Deep expertise & specialist knowledge (專業知識與深度技能)：能夠適配特定領域的需求，學習專業知識。
    -   Nuance (精細調整)：可以捕捉細微差異，表現出更高的靈活性。
    -   Learn a different tone/style (學習不同語調/風格)：適應目標應用的特定表達需求。
    -   Faster and cheaper inference (推斷速度更快，成本更低)：微調後的模型推斷效能更高，適合需要快速回應的場景。
