"""
# 旅遊主題圖片生成器(注意花費!!!!)

本程式使用 OpenAI 的 DALL-E 3 模型生成特定城市的旅遊主題圖片：
- 發送 API 請求生成圖片
- 圖片以流行藝術風格展現城市的特色與景點

需求：
- OpenAI API 金鑰
- PIL 庫來處理圖片
"""
import os
import json
from dotenv import load_dotenv
from openai import OpenAI
import base64
from PIL import Image
from io import BytesIO


# 加載環境變數
load_dotenv()
openai_api_key = os.getenv('OPENAI_API_KEY')
openai = OpenAI(api_key=openai_api_key)

class CFG:
    MODEL = "gpt-4o-mini"
    system_message = """
        你是一個飛機助手。
    """

##### 圖片生成函數 #####
def artist(city):
    try:
        # 發送圖片生成請求
        image_response = openai.images.generate(
            model="dall-e-3",
            prompt=f"一張代表在 {city} 度假的圖片，展示了 {city} 的旅遊景點和一切獨特之處，以充滿活力的流行藝術風格呈現",
            size="1024x1024",
            n=1, # 生成 1 張圖片
            response_format="b64_json", # 回傳 base64 格式的圖片數據
        )
        # 獲取 base64 圖片數據
        image_base64 = image_response.data[0].b64_json  # 提取 base64 格式的圖片數據
        image_data = base64.b64decode(image_base64) # 將 base64 數據解碼為二進制格式
        return Image.open(BytesIO(image_data)) # 返回 PIL Image
    except Exception as e:
        print(f"圖片生成失敗: {e}")
        return None

if __name__ == "__main__":
    city_name = "New York City"
    image = artist(city_name)
    if image:
        # 保存圖片到本地
        image.save(f"{city_name}_vacation_image.png")
        print(f"圖片已保存為 {city_name}_vacation_image.png")
    else:
        print("無法生成圖片")
