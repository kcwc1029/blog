from langchain_openai import ChatOpenAI
from dotenv import load_dotenv
import os

# 加載 .env 文件，從中獲取 API 金鑰
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")  # 環境變數中獲取 OpenAI 的 API 金鑰


# 定義文本情感分析的函式
def analyze_sentiment(text, api_key):
    """
    對輸入的文本進行情感分析。

    參數:
    - text: 用戶輸入的文本 (string)，需要進行情感分析
    - api_key: OpenAI 的 API 金鑰 (string)

    返回:
    - 情感分類 (string)："正面"、"中性" 或 "負面"
    - 置信度分數 (float)：情感傾向的置信度（0 到 1）
    """

    # 定義情感分析的 prompt
    prompt = f"""
    你是一個情感分析工具。對以下文本進行情感分析：
    「{text}」
    請給出以下輸出：
    - 情感分類（正面、中性或負面）
    - 情感的置信度分數（0 到 1）
    請用以下格式回答：
    分類: <情感分類>
    置信度: <置信度分數>
    """

    # 初始化模型
    model = ChatOpenAI(model="gpt-4", openai_api_key=api_key, temperature=0.0)

    # 調用模型進行情感分析
    response = model.predict(prompt)

    # 解析模型輸出的結果
    try:
        lines = response.split("\n")
        sentiment = lines[0].split(":")[1].strip()  # 提取情感分類
        confidence = float(lines[1].split(":")[1].strip())  # 提取置信度分數
        return sentiment, confidence
    except Exception as e:
        raise ValueError(f"無法解析模型輸出: {response}") from e


# 測試函式 (取消註解以測試)
if __name__ == "__main__":
    try:
        # 測試文本情感分析
        text_to_analyze = "這是一個非常棒的工具，我非常喜歡！"
        OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")
        sentiment, confidence = analyze_sentiment(text_to_analyze, OPENAI_API_KEY)

        print("分析結果：")
        print(f"情感分類：{sentiment}")
        print(f"置信度分數：{confidence}")
    except Exception as e:
        print(f"發生錯誤: {e}")
