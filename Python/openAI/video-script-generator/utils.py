from langchain.prompts import ChatPromptTemplate
from langchain_openai import ChatOpenAI
from dotenv import load_dotenv
import os

# 加載 .env 文件，從中獲取 API 金鑰
load_dotenv()
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")  # 環境變數中獲取 OpenAI 的 API 金鑰


# 定義生成腳本的函式
def generate_script(subject, video_length, creativity, api_key):
    """
    根據主題生成短影片標題和腳本。

    參數:
    - subject: 主題 (string)，如影片的主題
    - video_length: 影片長度 (int)，以分鐘計
    - creativity: 模型的創造性 (float)，範圍 0.0 到 1.0
    - api_key: OpenAI 的 API 金鑰 (string)

    返回:
    - 生成的影片標題 (string)
    - 生成的影片腳本 (string)
    """

    # 定義生成標題的模板
    title_template = ChatPromptTemplate.from_messages(
        [
            # 系統將根據主題 (subject) 生成一個吸引人的標題
            ("human", "請為一個短視頻設計吸引人的標題。主題是「{subject}」，需要讓年輕觀眾感興趣，且標題應該簡短、直接、有趣。"
)
        ]
    )

    # 定義生成腳本的模板
    script_template = ChatPromptTemplate.from_messages(
        [
            # 系統根據標題生成影片腳本
            ("human", """
                你是一位短影片頻道的博主。根據以下標題，為短影片頻道寫一個影片腳本。
                影片標題：{title}，影片時長：{duration}分鐘。
                要求開頭抓住注意力，中間提供干貨內容，結尾有驚喜，腳本格式請按照【開頭、中間，結尾】分隔。
                整體內容的表達方式要盡量輕鬆有趣，吸引年輕人。
            """)
        ]
    )

    # 初始化模型
    model = ChatOpenAI(model="gpt-4",openai_api_key=api_key, temperature=creativity)

    # 將標題生成模板連接到模型
    title_chain = title_template | model

    # 將腳本生成模板連接到模型
    script_chain = script_template | model

    # 調用模型生成標題
    title = title_chain.invoke({"subject": subject}).content

    # 調用模型生成影片腳本
    script = script_chain.invoke({
        "title": title,  # 傳遞生成的標題
        "duration": video_length,  # 傳遞影片時長
    }).content

    # 返回生成的標題和腳本
    return title, script


# 測試函式 (取消註解以測試)
if __name__ == "__main__":
    # 測試生成影片腳本
    try:
        OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")
        title, script = generate_script("人工智慧", 2, 0.7, OPENAI_API_KEY)
        print("生成的影片標題:")
        print(title)
        print("生成的影片腳本:")
        print(script)
    except Exception as e:
        print(f"發生錯誤: {e}")
