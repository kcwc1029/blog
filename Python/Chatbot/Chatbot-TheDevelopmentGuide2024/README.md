## 1. FastAPI

-   FastAPI 是一個用於構建 API 的現代、高效的 Python 框架。
-   它設計之初的目的是提供一種快速開發、高性能、並且容易使用的方式來構建基於 Web 的應用程式或 API。
-   安裝`pip install fastapi`
-   啟動方式：終端`uvicorn main:app --reload`
-   可以訪問 FastAPI 提供的 Swagger UI 查看路由是否正確`http://127.0.0.1:8000/docs`

### 1.1. FastAPI Get Request 用法

![upgit_20241212_1734007626.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241212_1734007626.png)

```python
from fastapi import FastAPI

BOOKS = [
    {'title': 'Title One', 'author': 'Author One', 'category': 'science'},
    {'title': 'Title Two', 'author': 'Author Two', 'category': 'science'},
    {'title': 'Title Three', 'author': 'Author Three', 'category': 'history'},
    {'title': 'Title Four', 'author': 'Author Four', 'category': 'math'},
    {'title': 'Title Five', 'author': 'Author Five', 'category': 'math'},
    {'title': 'Title Six', 'author': 'Author Two', 'category': 'math'}
]


app = FastAPI()

@app.get("/")
async def first_api():
    return {
        "message":"hello TA"
    }
```

### 1.2. Path Parameters

```python
from fastapi import FastAPI

BOOKS = [
    {'title': 'Title One', 'author': 'Author One', 'category': 'science'},
    {'title': 'Title Two', 'author': 'Author Two', 'category': 'science'},
    {'title': 'Title Three', 'author': 'Author Three', 'category': 'history'},
    {'title': 'Title Four', 'author': 'Author Four', 'category': 'math'},
    {'title': 'Title Five', 'author': 'Author Five', 'category': 'math'},
    {'title': 'Title Six', 'author': 'Author Two', 'category': 'math'}
]


app = FastAPI()

@app.get("/")
async def first_api():
    return {"message":"hello TA"}
@app.get("/books")
async def reed_all_books():
    return BOOKS
@app.get("/books/{dynamic_parameter}")
async def reed_all_books(dynamic_parameter):
    return {"dynamic_parameter":dynamic_parameter}
```

### 1.3. Query Parameters

```python
from fastapi import FastAPI

app = FastAPI()

@app.get("/")
async def first_api():
    return {
        "message":"hello TA"
    }
# 127.0.0.1:8000/books/?category=science
@app.get("/books")
async def reed_all_books(category:str):
    book_to_return = []
    book_to_return.append(category)
    return book_to_return
```

### 1.4. Post Request

```python
from fastapi import FastAPI, Body

app = FastAPI()
BOOKS = []

@app.get("/")
async def first_api():
    return {"message": "hello TA"}
@app.post("/books/create_book")
async def create_book(new_book: dict = Body(...)):
    BOOKS.append(new_book)
    return {"message": "Book added successfully!", "books": BOOKS}
```

### 1.5. Put Request

-   根據 RESTful 設計原則，put 用於更新現有資源或創建資源

```python
from fastapi import FastAPI, Body

app = FastAPI()
BOOKS = []

@app.get("/")
async def first_api():
    return {"message": "hello TA"}

# POST: Create a new book
@app.post("/books/create_book")
async def create_book(new_book: dict = Body(...)):
    BOOKS.append(new_book)
    return {"message": "Book added successfully!", "books": BOOKS}

# PUT: Update an existing book
@app.put("/books/update_book")
async def update_book(updated_book: dict = Body(...)):
    for book in BOOKS:
        if book.get("id") == updated_book.get("id"):
            book.update(updated_book)
            return {"message": "Book updated successfully!", "books": BOOKS}
    return {"message": "Book not found!", "books": BOOKS}
```

### 1.6. Delete Request

```python
from fastapi import FastAPI, Body

app = FastAPI()
BOOKS = []

@app.get("/")
async def first_api():
    return {"message": "hello TA"}

# POST: Create a new book
@app.post("/books/create_book")
async def create_book(new_book: dict = Body(...)):
    BOOKS.append(new_book)
    return {"message": "Book added successfully!", "books": BOOKS}

# PUT: Update an existing book
@app.put("/books/update_book")
async def update_book(updated_book: dict = Body(...)):
    for book in BOOKS:
        if book.get("id") == updated_book.get("id"):
            book.update(updated_book)
            return {"message": "Book updated successfully!", "books": BOOKS}
    return {"message": "Book not found!", "books": BOOKS}

# DELETE: Delete a book by ID
@app.delete("/books/delete_book/{book_id}")
async def delete_book(book_id: int):
    for book in BOOKS:
        if book["id"] == book_id:
            BOOKS.remove(book)
            return {"message": f"Book with ID {book_id} deleted successfully!", "books": BOOKS}
    return {"message": f"Book with ID {book_id} not found!", "books": BOOKS}
```

### 1.7. BUG：可以開啟終端機，但是瀏覽器開不起來

-   遇到端口占用問題

![upgit_20241217_1734436266.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241217_1734436266.png)

```shell
// 刪除程序30320
taskkill /PID 17056 /F
```

## 2. OpenAI

### 2.1. 基本串接 open api key

```python
import os
from dotenv import load_dotenv
from openai import OpenAI

# 加載 .env 文件
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")
openai = OpenAI(api_key=OPENAI_API_KEY)

response = openai.chat.completions.create(
    model="gpt-3.5-turbo",  # 使用對話模型
    messages=[
        {"role": "system", "content": "你是一位教授"},
        {"role": "user", "content": "請你說一個笑話"}
    ],
    temperature=0.7  # 控制生成的隨機性(0保守、1創意)
)
# 輸出對話結果
print(response.choices[0].message.content)
```

### 2.2. 創建 chat log history

```python
import os
from dotenv import load_dotenv
from openai import OpenAI

# 加載 .env 文件
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")
openai = OpenAI(api_key=OPENAI_API_KEY)

# 初始化對話歷史
chat_history = [{"role": "system", "content": "你是一位教授"}]

while True:
    # 接收用戶輸入
    user_input = input("user: ")
    # 添加用戶輸入到對話歷史
    chat_history.append({"role": "user", "content": user_input})
    # 使用 OpenAI API 生成回應
    response = openai.chat.completions.create(
        model="gpt-3.5-turbo",
        messages=chat_history,
        temperature=0.7
    )
    # 獲取 AI 的回應
    ai_response = response.choices[0].message.content
    print(f"Assistant: {ai_response}")

    # 添加 AI 回應到對話歷史
    chat_history.append({"role": "assistant", "content": ai_response})
```

## 3. 將 FastAPI 整合到應用程序中

-   安裝套建`pip install fastapi uvicorn python-multipart`
-   fastapi：FastAPI 是一個用於構建 API 的現代、高性能 Web 框架。
-   uvicorn：
    -   Uvicorn 是一個 ASGI 伺服器，用於運行 FastAPI 應用程序。
    -   它提供了非同步支持，可以處理高併發請求。
-   python-multipart：
-   該庫用於處理多部分表單數據（multipart/form-data），例如文件上傳。
-   如果您的 FastAPI 應用需要支持文件或圖片上傳，則必須安裝此依賴。

```python
import os
from dotenv import load_dotenv
from openai import OpenAI
from fastapi import FastAPI, Form
from typing import Annotated

# 加載 .env 文件
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")
openai = OpenAI(api_key=OPENAI_API_KEY)

# 初始化API
app = FastAPI()

# 初始化對話歷史
chat_history = [{"role": "system", "content": "你是一位教授"}]



@app.post("/")
async def first_api(user_input: Annotated[str, Form()]):

    # 添加用戶輸入到對話歷史
    chat_history.append({"role": "user", "content": user_input})
    # 使用 OpenAI API 生成回應
    response = openai.chat.completions.create(
        model="gpt-3.5-turbo",
        messages=chat_history,
        temperature=0.7
    )
    # 獲取 AI 的回應
    ai_response = response.choices[0].message.content
    # 添加 AI 回應到對話歷史
    chat_history.append({"role": "assistant", "content": ai_response})
    return ai_response
```

![upgit_20241213_1734094216.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241213_1734094216.png)

## 4. 創建使用者介面

-   Jinja2：是一個 Python 的模板引擎，常用於 Web 開發框架（例如 Flask 和 FastAPI）。它允許你將 HTML、CSS 與 Python 數據整合在一起，生成動態的網頁內容。
-   index.html 要放在 templates 資料夾裡面，才可以被 Jinja2 讀到。

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>chatbot</title>
    </head>
    <body>
        <h1>welcome</h1>
    </body>
</html>
```

```python
import os
from dotenv import load_dotenv
from openai import OpenAI
from fastapi import FastAPI, Form, Request
from typing import Annotated
from fastapi.templating import Jinja2Templates
from fastapi.responses import HTMLResponse

# 加載 .env 文件
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")
openai = OpenAI(api_key=OPENAI_API_KEY)
chat_history = [{"role": "system", "content": "你是一位教授"}] # 初始化對話歷史

# 初始化API
app = FastAPI()
templates = Jinja2Templates(directory="templates")



@app.get("/", response_class=HTMLResponse)
async def chat_page(request: Request):
    return templates.TemplateResponse("index.html", {"request": request, "history": chat_history})
```

### 4.1. Project：增加 bootstrap

![upgit_20241217_1734436715.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241217_1734436715.png)

-   [simple fastapi openai chatbot](./simple%20fastapi%20openai%20chat/main.py)

## 5. DALL·E

-   DALL·E 是由 OpenAI 所開發
-   基於自然語言描述生成圖片
-   我覺得，生成的效果...還是不要用比較好(笑)

![Image](https://oaidalleapiprodscus.blob.core.windows.net/private/org-WYB6CF9VHGthYaYJ7gOVZO1e/user-1wR0pFyX4cLV2P6jpQBHCevE/img-zlzmTsj3HUESujzE1WFP6ex6.png?st=2024-12-17T11%3A14%3A53Z&se=2024-12-17T13%3A14%3A53Z&sp=r&sv=2024-08-04&sr=b&rscd=inline&rsct=image/png&skoid=d505667d-d6c1-4a0a-bac7-5c84a87759f8&sktid=a48cca56-e6da-484e-a814-9c849652bcb3&skt=2024-12-17T11%3A01%3A01Z&ske=2024-12-18T11%3A01%3A01Z&sks=b&skv=2024-08-04&sig=r6c559k4J41QriSf0q0OcREQKfMzSzwE9CWGY69bods%3D)

```python
import os
from dotenv import load_dotenv
from openai import OpenAI
"""
NOTE: 初始化環境變量和 OpenAI API
使用 dotenv 加載環境變量，並初始化 OpenAI API 密鑰。
"""
# 加載 .env 文件
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")  # 從 .env 文件讀取 API 密鑰
openai = OpenAI(api_key=OPENAI_API_KEY)  # 初始化 OpenAI 客戶端

response = openai.images.generate(
    prompt="幫我生成一個好看的微肉美女",
    n=1,
    size="1024x1024"
)

image_url = response.data[0].url
print(response.data[0])
print()
print(image_url)
```

### 5.1. Project：open api 結合 DALL·E 生成圖像

![upgit_20241217_1734443178.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241217_1734443178.png)

-   這份程式碼主要是一個 使用 FastAPI 框架 和 OpenAI API 的網頁應用，讓使用者可以透過輸入文字描述，生成對應的圖片並顯示在網頁上。
-   [simple image fastapi openai](./simple%20image%20fastapi%20openai/main.py)

## 6. WebSocket

-   WebSocket API 提供雙向互動通訊，連接使用者的瀏覽器和伺服器。
-   使用 WebSocket 時，能夠根據事件發送與接收訊息，不需要頻繁輪詢伺服器。
-   適合即時應用，如聊天與遊戲。
-   與傳統 HTTP 請求不同，WebSocket 使用雙向通訊。
-   `pip install websockets`

### 6.1. 建立 FastAPI WebSocket 服務(gpt 生成的，仍未測試)

```python
from fastapi import FastAPI, WebSocket
from fastapi.responses import HTMLResponse

app = FastAPI()

# HTML 測試頁面 (前端介面)
html = """
<!DOCTYPE html>
<html>
    <head>
        <title>WebSocket Test</title>
    </head>
    <body>
        <h1>WebSocket Test</h1>
        <input id="messageInput" type="text" placeholder="Type your message...">
        <button onclick="sendMessage()">Send</button>
        <ul id="messages"></ul>

        <script>
            const ws = new WebSocket("ws://localhost:8000/ws");
            const messages = document.getElementById("messages");

            ws.onmessage = function(event) {
                const message = document.createElement("li");
                message.textContent = event.data;
                messages.appendChild(message);
            };

            function sendMessage() {
                const input = document.getElementById("messageInput");
                ws.send(input.value);
                input.value = "";
            }
        </script>
    </body>
</html>
"""

@app.get("/")
async def get():
    return HTMLResponse(html)

# WebSocket 連接
@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()  # 接受 WebSocket 連線
    while True:
        data = await websocket.receive_text()  # 接收文字訊息
        print(f"收到訊息: {data}")
        await websocket.send_text(f"你發送了: {data}")  # 發送回應訊息

```

## 7. Project：WebSocket with OpenAI & FastAPI

-   PAPER
-   實現了一個 聊天機器人 Web 應用，使用了 FastAPI 作為後端框架、WebSocket 進行即時通訊，並透過 OpenAI GPT-3.5 API 生成回應。同時，使用 Bootstrap 提供簡潔美觀的使用者介面。

![upgit_20241218_1734531528.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241218_1734531528.png)

-   啟動方式：終端`uvicorn main:app --reload`
-   [WebSocket with OpenAI & FastAPI](./WebSocket%20with%20OpenAI%20&%20FastAPI/main.py)
-

## 8. websocket 部屬

-   將 Project[WebSocket with OpenAI & FastAPI](./WebSocket%20with%20OpenAI%20&%20FastAPI/main.py)進行部屬(透過更改 WebSocket URL)的方式。
-   更改 WebSocket URL

```js
let websocketString = "";
if (window.location.hostname === "127.0.0.1") {
    websocketString = "ws://localhost:8000/ws";
} else {
    websocketString = `wss://${window.location.hostname}/ws`;
}

let ws = new WebSocket(websocketString);
```

-   生成安裝包 requiurements.txt `pip freeze > requiurements.txt`

## 9. 部屬方式

### 9.1. 靜態網站部署

-   適合只包含 HTML、CSS、JavaScript 的網站
-   個人作品集、部落格、簡單展示網站。
-   GitHub Pages
-   Vercel
-   Netlify

### 9.2. 動態網站部署

-   Heroku
-   Render
-   Fly.io
-   需要後端邏輯的應用，如部落格、論壇、API 服務。

-   這邊使用 Render 進行部屬

![upgit_20241218_1734533394.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241218_1734533394.png)

![upgit_20241218_1734534810.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241218_1734534810.png)

### 9.3. BUG：部署出錯誤

-   原因：因為 python 環境沒有處裡好
-   重新建造一個虛擬環境

```bash
# 創建 Conda 環境
conda create -n myenv python=3.11

# 激活環境
conda activate myenv

# 安裝 pip（可選）
conda install pip

# 安裝 requirements.txt 內的套件
pip install -r requirements.txt

# 確定本地環境可以運行之後，開始做環境打包文件
pip freeze > requirements.txt
```
