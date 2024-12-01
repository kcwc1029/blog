"""
此專案展示如何使用 OpenAI 的語音合成功能生成音訊，並結合 Pydub 與 FFplay 播放生成的語音。適用於需要語音互動或語音合成的應用場景。

- 設定 OpenAI API 密鑰
- 確保已安裝 FFmpeg 並配置於系統 PATH 中。
    - 測試方法：ffmpeg -version

"""

import tempfile
import subprocess
from io import BytesIO
from pydub import AudioSegment
from dotenv import load_dotenv
import os
import time
from openai import OpenAI

class CFG:
    model="tts-1"
    test_messeage="""
        你好！我是你的虛擬助理。
        我可以幫助你完成各種任務，解答你的問題，或者只是陪你聊聊天。
        科技是不是很神奇呢？讓我們一起探索如何讓你的每一天都更精彩！
        今天你想做些什麼呢？
    """


# 加載環境變數
load_dotenv()
openai_api_key = os.getenv('OPENAI_API_KEY')
openai = OpenAI(api_key=openai_api_key)

def play_audio(audio_segment):
    """
    播放音訊檔案。
    """
    temp_dir = tempfile.gettempdir()
    temp_path = os.path.join(temp_dir, "temp_audio.wav")
    try:
        # 將音訊匯出為 WAV 格式
        audio_segment.export(temp_path, format="wav")
        
        # 使用 FFplay 播放音訊
        subprocess.call([
            "ffplay",
            "-nodisp",  # 不顯示視覺介面
            "-autoexit",  # 自動關閉
            "-hide_banner",  # 隱藏橫幅資訊
            temp_path
        ], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    finally:
        # 清理暫存檔案
        try:
            os.remove(temp_path)
        except Exception as e:
            print(f"無法刪除暫存檔案: {e}")

def talker(message):
    """
    使用 OpenAI 生成音訊並播放。
    """
    try:
        # 呼叫 OpenAI API 生成語音
        response = openai.audio.speech.create(
            model=CFG.model,
            voice="fable",  # 可以嘗試替換為 'alloy'
            input=message
        )
        
        # 將返回的內容轉換為音訊
        audio_stream = BytesIO(response.content)
        audio = AudioSegment.from_file(audio_stream, format="mp3")
        
        # 播放音訊
        play_audio(audio)
    except Exception as e:
        print(f"生成或播放音訊時發生錯誤: {e}")

if __name__ == "__main__":
    # 測試語音播放功能
    talker(CFG.test_messeage)
