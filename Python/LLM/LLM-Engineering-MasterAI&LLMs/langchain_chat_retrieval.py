"""
TODO: 
實現一個基於 LangChain 和 OpenAI 的文檔檢索與聊天機器人系統。
"""
import os
import glob
from dotenv import load_dotenv
import gradio as gr
from openai import OpenAI
from langchain_community.document_loaders import DirectoryLoader, TextLoader  # 用於加載文檔
from langchain.text_splitter import CharacterTextSplitter  # 用於分割文檔
from langchain.schema import Document
from langchain_openai import OpenAIEmbeddings, ChatOpenAI
from langchain_chroma import Chroma  # 用於向量存儲和檢索
import numpy as np
from sklearn.manifold import TSNE
import plotly.graph_objects as go
from langchain.memory import ConversationBufferMemory
from langchain.chains import ConversationalRetrievalChain

##### NOTE: 環境變數和 OpenAI API 初始化 #####
load_dotenv()  # 載入 .env 文件中的環境變數
openai_api_key = os.getenv('OPENAI_API_KEY')  # 獲取 OpenAI API 密鑰
openai = OpenAI(api_key=openai_api_key)  # 初始化 OpenAI 客戶端

class CFG:
    MODEL = "gpt-4o-mini"  # GPT 模型名稱
    db_name = "vector_db"  # 向量數據庫名稱

"""
##### NOTE: 加載 Markdown 文件 #####
從 "knowledge-base" 資料夾中加載所有 Markdown 文件，並將它們存儲為內存中的文檔列表。
"""
text_loader_kwargs = {'encoding': 'utf-8'}
folders = glob.glob("./誤刪knowledge-base/*")  # 獲取資料夾清單
documents = []  # 用於存儲文檔
for folder in folders:
    doc_type = os.path.basename(folder)  # 獲取文件類型（資料夾名稱）
    loader = DirectoryLoader(
        folder, 
        glob="**/*.md",  # 遍歷資料夾中所有 Markdown 文件
        loader_cls=TextLoader, 
        loader_kwargs=text_loader_kwargs
    )
    folder_docs = loader.load()  # 加載文檔
    # 添加 metadata（例如文件類型）
    for doc in folder_docs:
        doc.metadata["doc_type"] = doc_type
        documents.append(doc)
print(f"加載文件數量：{len(documents)}")  # 打印加載的文檔數量



"""
##### NOTE: 分割文件為文本塊 #####
使用 CharacterTextSplitter 將每個文檔分割為較小的文本塊。
每塊的大小為 2000 字符，並有 400 字符的重疊部分，確保上下文連貫。
"""
text_splitter = CharacterTextSplitter(chunk_size=2000, chunk_overlap=400)  # 分割參數
chunks = text_splitter.split_documents(documents)  # 分割文檔
print(f"生成小塊數量：{len(chunks)}")  # 打印生成的小塊數量




"""
##### NOTE: 建立向量存儲 #####
1. 使用 OpenAI 的嵌入模型將文本塊轉換為高維向量。
2. 將生成的嵌入向量存儲到 Chroma 數據庫中。
"""
embeddings = OpenAIEmbeddings()  # 初始化嵌入模型
if os.path.exists(CFG.db_name):  # 如果向量數據庫已存在，刪除它
    Chroma(persist_directory=CFG.db_name, embedding_function=embeddings).delete_collection()

vectorstore = Chroma.from_documents(
    documents=chunks,  # 文本塊
    embedding=embeddings,  # 嵌入模型
    persist_directory=CFG.db_name  # 持久化數據庫位置
)
print(f"Vectorstore created with {vectorstore._collection.count()} documents")  # 打印存儲的文檔數量

 
"""
##### NOTE: 啟動聊天機器人 #####
1. 使用 ConversationalRetrievalChain 建立檢索型對話鏈。
2. 使用 Gradio 提供一個簡單的聊天界面。
"""
llm = ChatOpenAI(temperature=0.7, model_name=CFG.MODEL)  # 初始化 GPT 模型
retriever = vectorstore.as_retriever()  # 從向量存儲中檢索相關文檔
memory = ConversationBufferMemory(memory_key='chat_history', return_messages=True)  # 記錄對話歷史
conversation_chain = ConversationalRetrievalChain.from_llm(llm=llm, retriever=retriever, memory=memory)

# 聊天邏輯定義
def chat(message, history):
    """
    接收用戶輸入的問題與歷史對話，返回基於文檔的回答。
    """
    result = conversation_chain.invoke({"question": message})
    return result["answer"]
view = gr.ChatInterface(chat, type="messages").launch(inbrowser=True)  # 啟動 Gradio Chat 介面