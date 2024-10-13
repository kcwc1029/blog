## 語音轉文字
- 需要安裝套件
```python
pip install SpeechRecognition
pip install PyAudio
```

```python
import speech_recognition as sr

##############################
# 本程式使用 speech_recognition 套件來實現語音辨識，
# 並使用 Google 語音辨識 API 進行中文語音識別。
# 當你說話時，程式會將語音轉換為文字並顯示出來。
# 說出 "結束" 即可退出程式。

# 需要安裝套件
# pip install SpeechRecognition
# pip install PyAudio
##############################

# 初始化辨識器
r = sr.Recognizer()

def recognize_speech():
    """識別語音並返回結果"""
    with sr.Microphone() as source:
        print('Say ...')
        audio = r.listen(source)  # 監聽使用者的語音
        try:
            # 使用 Google 語音辨識 API 進行語音辨識
            ans = r.recognize_google(audio, language="zh-TW")
            return ans
        except sr.UnknownValueError:
            print("無法識別語音，請再試一次。")
            return ""
        except sr.RequestError as e:
            print(f"Google 語音辨識服務未回應；錯誤：{e}")
            return ""

def main():
    """主程式執行函數"""
    print("開始語音辨識，說 '結束' 即可退出程式。")
    while True:
        result = recognize_speech()
        if result:
            print(result)  # 顯示辨識結果
            if result == "結束":
                print("結束語音辨識。")
                break  # 當識別到 "結束" 時退出循環

# 執行主程式
if __name__ == "__main__":
    main()

```



## 文字轉語音(TTS)
- 需要安裝套件
```python
pip install gtts
```

```python
from gtts import gTTS
tts=gTTS(text='測試', lang='zh')
tts.save('t1.mp3')
# pip install gtts
```