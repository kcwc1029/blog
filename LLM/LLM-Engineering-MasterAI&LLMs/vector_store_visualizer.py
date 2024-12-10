import os
import glob
from dotenv import load_dotenv
from langchain_community.document_loaders import DirectoryLoader, TextLoader  # 用於加載文檔
from langchain_chroma import Chroma  # 用於向量存儲和檢索
from langchain.text_splitter import CharacterTextSplitter  # 用於分割文檔
from langchain_openai import OpenAIEmbeddings  # 用於生成嵌入向量
from sklearn.manifold import TSNE  # 用於降維（高維向量降為 2D 或 3D）
import numpy as np  # 用於數學運算
import plotly.graph_objects as go  # 用於可視化

# ##### NOTE: 環境變數和 OpenAI API 初始化 #####
load_dotenv()  # 載入 .env 文件中的環境變數
openai_api_key = os.getenv('OPENAI_API_KEY')  # 獲取 OpenAI API 密鑰

class CFG:
    MODEL = "gpt-4o-mini"  # GPT 模型名稱
    db_name = "vector_db"  # 向量數據庫名稱

"""
##### NOTE: 加載 Markdown 文件 #####
從 "knowledge-base" 資料夾中加載所有 Markdown 文件，並將它們存儲為內存中的文檔列表。
"""
text_loader_kwargs = {'encoding': 'utf-8'}
folders = glob.glob("knowledge-base/*")  # 獲取資料夾清單
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
##### NOTE: 檢查向量維度 #####
提取一個樣本向量，並計算其維度。
"""
collection = vectorstore._collection  # 獲取向量集合
sample_embedding = collection.get(limit=1, include=["embeddings"])["embeddings"][0]  # 提取樣本向量
dimensions = len(sample_embedding)  # 計算向量維度
print(f"The vectors have {dimensions:,} dimensions")  # 打印維度

"""
##### NOTE: 2D 向量可視化 #####
使用 TSNE 將高維向量降維到 2D，並使用 Plotly 可視化。
"""
result = collection.get(include=['embeddings', 'documents', 'metadatas'])
vectors = np.array(result['embeddings'])  # 提取嵌入向量
documents = result['documents']  # 提取原始文檔
doc_types = [metadata['doc_type'] for metadata in result['metadatas']]  # 提取文檔類型
colors = [['blue', 'green', 'red', 'orange'][['products', 'employees', 'contracts', 'company'].index(t)] for t in doc_types]  # 類型對應顏色

tsne = TSNE(n_components=2, random_state=42)  # 初始化 TSNE
reduced_vectors = tsne.fit_transform(vectors)  # 將向量降維到 2D

# 創建 2D 圖像
fig = go.Figure(data=[go.Scatter(
    x=reduced_vectors[:, 0], y=reduced_vectors[:, 1],
    mode='markers', marker=dict(size=5, color=colors, opacity=0.8),
    text=[f"Type: {t}<br>Text: {d[:100]}..." for t, d in zip(doc_types, documents)]
)])
fig.update_layout(
    title='2D Chroma Vector Store Visualization',
    width=800, height=600
)
fig.show()

"""
##### NOTE: 3D 向量可視化 #####
將高維向量降維到 3D，並使用 Plotly 可視化。
"""
tsne = TSNE(n_components=3, random_state=42)
reduced_vectors = tsne.fit_transform(vectors)

fig = go.Figure(data=[go.Scatter3d(
    x=reduced_vectors[:, 0], y=reduced_vectors[:, 1], z=reduced_vectors[:, 2],
    mode='markers', marker=dict(size=5, color=colors, opacity=0.8),
    text=[f"Type: {t}<br>Text: {d[:100]}..." for t, d in zip(doc_types, documents)]
)])
fig.update_layout(
    title='3D Chroma Vector Store Visualization',
    width=900, height=700
)
fig.show()
