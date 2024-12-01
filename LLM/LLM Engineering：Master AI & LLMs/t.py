import os
import base64
from io import BytesIO
from PIL import Image
import tempfile
import subprocess
from dotenv import load_dotenv
from pydub import AudioSegment
from openai import OpenAI
import gradio as gr

# 加載環境變數
load_dotenv()
openai_api_key = os.getenv('OPENAI_API_KEY')
if not openai_api_key:
    raise ValueError("環境變數 OPENAI_API_KEY 未設置！請在 .env 文件中設置 API 密鑰。")
openai = OpenAI(api_key=openai_api_key)

# 系統訊息與模型設定
system_message = "你是一個友好的 AI 助理，能回答問題並提供幫助。"
MODEL = "gpt-4o-mini"

##### 圖片生成函數 #####
def artist(city):
    """
    使用 OpenAI 的 DALL-E 3 模型生成特定城市的旅遊圖片。
    """
    try:
        response = openai.images.generate(
            model="dall-e-3",
            prompt=f"一張代表在 {city} 度假的圖片，展示了 {city} 的旅遊景點和一切獨特之處，以充滿活力的流行藝術風格呈現",
            size="1024x1024",
            n=1,
            response_format="b64_json"
        )
        # 獲取 base64 圖片數據並解碼
        image_base64 = response.data[0].b64_json
        image_data = base64.b64decode(image_base64)
        return Image.open(BytesIO(image_data))
    except Exception as e:
        print(f"圖片生成失敗: {e}")
        return None

##### 音訊播放函數 #####
def play_audio(audio_segment):
    """
    播放音訊檔案。
    """
    temp_dir = tempfile.gettempdir()
    temp_path = os.path.join(temp_dir, "temp_audio.wav")
    try:
        audio_segment.export(temp_path, format="wav")
        subprocess.call([
            "ffplay",
            "-nodisp",
            "-autoexit",
            temp_path
        ], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    finally:
        try:
            os.remove(temp_path)
        except Exception as e:
            print(f"無法刪除暫存檔案: {e}")

##### 生成語音並播放 #####
def talker(message):
    """
    使用 OpenAI API 生成語音並播放。
    """
    try:
        response = openai.audio.speech.create(
            model="tts-1",
            voice="fable",
            input=message
        )
        print("語音 API 回應:", response)  # 檢查回應是否正確
        audio_stream = BytesIO(response.content)
        audio = AudioSegment.from_file(audio_stream, format="mp3")
        play_audio(audio)
    except Exception as e:
        print(f"生成或播放音訊時發生錯誤: {e}")

##### Chat 功能 #####
def chat(history):
    """
    Chat 功能：回應訊息，並根據用戶輸入生成圖片或回應語音。
    """
    messages = [{"role": "system", "content": system_message}] + [
        {"role": "user", "content": msg[0]} for msg in history
    ]
    response = openai.chat.completions.create(model=MODEL, messages=messages)
    reply = response.choices[0].message.content

    # 檢查是否需要生成圖片
    if "生成圖片" in history[-1][0]:
        city_name = history[-1][0].replace("生成圖片", "").strip()
        image = artist(city_name)
        if image:
            history.append([history[-1][0], reply])
            return history, image  # 返回圖片
        else:
            reply += "\n抱歉，生成圖片失敗。"
    
    history.append([history[-1][0], reply])
    talker(reply)  # 播放語音
    return history, None

##### Gradio 界面 #####
with gr.Blocks() as ui:
    with gr.Row():
        chatbot = gr.Chatbot(label="Chatbot", height=500)
        image_output = gr.Image(height=500)
    with gr.Row():
        entry = gr.Textbox(label="Chat with our AI Assistant:", placeholder="輸入你的問題...")
    with gr.Row():
        clear = gr.Button("Clear")

    def do_entry(message, history):
        """
        將使用者的輸入加入歷史紀錄。
        """
        history.append([message, None])  # 將訊息加入歷史，但回應為 None，稍後填寫
        return "", history

    entry.submit(do_entry, inputs=[entry, chatbot], outputs=[entry, chatbot]).then(
        chat, inputs=chatbot, outputs=[chatbot, image_output]
    )
    clear.click(lambda: [], inputs=None, outputs=[chatbot, image_output])

# 啟動 Gradio
ui.launch(inbrowser=True)
