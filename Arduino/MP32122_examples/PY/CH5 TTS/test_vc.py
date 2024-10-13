import speech_recognition as sr
r=sr.Recognizer()
with sr.Microphone() as source:
     print('Say ...')
     audio=r.listen(source)
try:
   ans=r.recognize_google(audio, language="zh-TW")  
   if len(ans)!=0:
      print(ans)
except sr.RequestError as e:
   print("No response : {0}".format(e))
