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

![upgit_20241213_1734098666.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241213_1734098666.png)

-   [simple chatbot](./simple%20chatbot/main.py)
