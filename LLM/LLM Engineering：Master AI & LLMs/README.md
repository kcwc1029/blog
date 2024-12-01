## 安裝最小模型：llama3.2

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

## 確認本地 ollama 是否安裝完成

-   [http://localhost:11434/](http://localhost:11434/)

## 將 API_KEY 放到.env

```bash
OPENAI_API_KEY=...
```

## 連接到 OpenAI

```python
from dotenv import load_dotenv
import os

load_dotenv()
api_key = os.getenv('OPENAI_API_KEY')
print(api_key)
```

## 提示類型(Types of prompts )

-   system prompt：告訴他們正在執行什麼任務以及他們應該使用什麼語氣
-   user prompt： 他們應該回復的對話贊助者

## Project：透過 OpenAI API + 爬蟲對網站內容總結

-   website_summary_tool.py

## Project：python 操作 ollama

-   website_summary_ollama.py

## Gradio 框架：構建用戶介面

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

## Project：openai 結合 graido 介面

-   gradio_openai_chat_v1.py
-   gradio_openai_chat_v2.py

## Project：OpenAI GPT 和 Gradio 圖形介面的互動聊天應用程式

-   interactive_openai_chat.py

## Project：計算機概論助手

-   計算機概論助手\_chat_interface.py

## Project：openAI 利用 DALL-E 生成圖片(但要注意費用)

![upgit_20241201_1733059794.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241201_1733059794.png)

-   要注意每一張的生成費用
-   dalle_image_generator.py

## openAI 結合音訊

### 要先安裝 FFmpeg：

-   【下載點】https://github.com/BtbN/FFmpeg-Builds/releases

![upgit_20241201_1733060485.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241201_1733060485.png)

-   將下載的文件解壓到電腦上的某個位置（例如，C：\ffmpeg）
-   將 FFmpeg bin 資料夾新增到系統 PATH 中：(例如，C：\ffmpeg\bin)
-   測試：`ffmpeg -version`

![upgit_20241201_1733060882.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241201_1733060882.png)

## OpenAI 語音助手範例

-   模型選用 tts-1
-   openai_voice_assistant.py

## Agent Framework(代理 AI)

-   AI Agent 是一個能夠模擬「自主性」並執行複雜任務的人工智慧系統框架。它不僅回應單一提示，而是能夠規劃、協作並使用工具來完成特定目標。

### AI Agent 的核心特性

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

```python

```

```python

```

```python

```

```python

```

Connecting_to_OpenAI.py
