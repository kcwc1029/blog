import os
import glob
from dotenv import load_dotenv
from openai import OpenAI
from langchain.document_loaders import DirectoryLoader, TextLoader
from langchain.text_splitter import CharacterTextSplitter


load_dotenv()  # 載入 .env 文件中的環境變數
openai_api_key = os.getenv('OPENAI_API_KEY')  # 獲取環境變數中的 API 密鑰
openai = OpenAI(api_key=openai_api_key)  # 初始化 OpenAI 客戶端

class CFG:
    MODEL = "gpt-4o-mini"  # 使用的 GPT 模型名稱
    DB_NAME = "vector_db"  # 虛擬數據庫的名稱（可用於存儲向量化數據）


"""
##### 加載文件並生成文檔列表 #####
這部分負責從資料夾中加載所有 Markdown 文件，將它們保存為內存中的文檔列表。
每個文件會帶資料夾名稱，用於後續分類和檢索。
"""
text_loader_kwargs = {'encoding': 'utf-8'}  # 加載文件時使用的編碼類型
folders = glob.glob("knowledge-base/*")  # 獲取 "knowledge-base" 資料夾下的所有子資料夾
documents = []  # 用於存儲所有加載的文檔

for folder in folders:
    doc_type = os.path.basename(folder)  # 文件類型由資料夾名稱決定
    loader = DirectoryLoader(
        folder, 
        glob="**/*.md",  # 加載該資料夾內所有 Markdown 文件
        loader_cls=TextLoader,  # 使用 TextLoader 讀取文件內容
        loader_kwargs=text_loader_kwargs
    )
    folder_docs = loader.load()  # 加載文件

    # 為每個文檔添加 metadata 並存入 documents 列表
    for doc in folder_docs:
        doc.metadata["doc_type"] = doc_type  # 設置文件類型 metadata
        documents.append(doc)
print(f"Loaded {len(documents)} documents from knowledge base.")  # 打印加載的文檔數量


"""
##### NOTE: 分割文件為文本塊 #####
使用 CharacterTextSplitter 將每個文檔分割為較小的文本塊。
每塊的大小為 1000 字符，並有 200 字符的重疊部分，確保上下文連貫。
"""
text_splitter = CharacterTextSplitter(chunk_size=1000, chunk_overlap=200)  # 分塊參數
chunks = text_splitter.split_documents(documents)  # 分割文檔
print(f"Generated {len(chunks)} text chunks.")  # 打印生成的小塊數量


"""
遍歷所有文本塊，提取每個文本塊的文檔類型，
並打印出當前資料集中所有不同的類型。
"""
doc_types = set(chunk.metadata['doc_type'] for chunk in chunks)  # 獲取唯一的文檔類型
print(f"Document types found: {', '.join(doc_types)}")  # 打印文件類型清單

##### 關鍵字檢索功能 #####
def search_keyword(chunks, keyword):  # 查找文本塊中包含特定關鍵字的段落
    """
    輸入：
    - chunks: 文本塊的列表
    - keyword: 要查找的關鍵字

    功能：
    - 遍歷所有文本塊，找出包含關鍵字的文本塊。
    - 打印每個符合條件的文本塊。

    輸出：
    - 返回包含關鍵字的文本塊列表。
    """
    results = [chunk for chunk in chunks if keyword in chunk.page_content]  # 過濾包含關鍵字的文本塊
    for result in results:
        print(result)  # 打印文本塊
        print("_________")  # 分隔線，便於閱讀
    return results  # 返回結果列表

##### 查找包含 "CEO" 的文本塊 #####
results = search_keyword(chunks, 'CEO')
