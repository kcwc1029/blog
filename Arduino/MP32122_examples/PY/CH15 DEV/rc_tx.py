import time
import pygame
import serial
from gtts import gTTS
import speech_recognition as sr
COM_PORT ='COM7' #設定通訊埠
BAUD_RATES =9600   
ser = serial.Serial(COM_PORT, BAUD_RATES)#開啟串列介面
#----------------------------------------------
def ur_c():#接收指令
    ins = ser.read()
    ind = ins.decode()   
    return ind
def vc():#聲控副程式
    r=sr.Recognizer()
    with sr.Microphone() as source:
     print('Say ...')
     audio=r.listen(source)
    try:
      ans=r.recognize_google(audio, language="zh-TW")  
      if len(ans)!=0:
         print(ans)
         sayx(ans)
         return ans
    except sr.UnknownValueError:
     print('x')
     return
    except sr.RequestError as e:
     print("No response : {0}".format(e))
     return
#說出訊息副程式-
def sayx(mess): 
 tts=gTTS(text=mess, lang='zh')
 tts.save("temp.mp3")
 pygame.mixer.music.load("temp.mp3")
 pygame.mixer.music.play()
 while pygame.mixer.music.get_busy():
  time.sleep(0.3)
 pygame.mixer.music.stop()
 pygame.mixer.music.unload()
#執行聲控動作
def act(a):
    if(a=='冷氣'):
      ser.write(b'1')      
    if(a=='電視'):
      ser.write(b'2')      
    if(a=='收音機'):
      ser.write(b'3')    
def menu():#顯示按鍵功能
    show = pointFont.render('1—COOL  2 TV   3 RADIO', 1, (255, 0, 0))
    screen.blit(show, (5, 35))
#主程式開始執行----------------------------------
pygame.init()#平台初始化
hit= pygame.mixer.Sound('py.wav')
pygame.mixer.init()
hit.play()
windowSize = [400, 300]  #視窗大小設定
screen=pygame.display.set_mode(windowSize)
# 載入背景圖片
bg1= pygame.image.load('bg1.jpg')
bg1= pygame.transform.scale(bg1, windowSize)
pointFont = pygame.font.SysFont("Monospace", 30)#180
screen.blit(bg1, (0, 0))
menu()#顯示按鍵說明
pygame.display.flip()
#迴圈執行---------------------------------
done = False                        
while  not done:
#掃描串列介面是否有命令傳入
    while ser.in_waiting:          
         c=ur_c()
         if c=='1':print('1')                      
         if c=='2':print('2')
         if c=='3':print('3')
#按鍵掃描-----------------------  
    keys = pygame.key.get_pressed()
    if keys[pygame.K_ESCAPE]: done = True
    if keys[pygame.K_SPACE]:#啟動聲控
       hit.play()
       time.sleep(0.3)
       screen.blit(bg1, (0, 0))    
       show = pointFont.render('say?', 1, (255, 0, 0))
       screen.blit(show, (80, 100))
       pygame.display.flip()
       a=vc()
       act(a)
       screen.blit(bg1, (0, 0))
       pygame.display.flip()
    if keys[pygame.K_1]:
       print('tx 1')
       ser.write(b'1')
       sayx('冷氣')
       time.sleep(1)       
    if keys[pygame.K_2]:
       print('tx 2')
       ser.write(b'2') 
       sayx('電視')
       time.sleep(1)
    if keys[pygame.K_3]:
       print('tx 3')
       ser.write(b'3')       
       sayx('收音機')
       time.sleep(1)
    if keys[pygame.K_8]:
       sayx('您可以說，冷氣，電視，收音機')
       time.sleep(1)
#結束迴圈-----------------------------------        
    for event in pygame.event.get():             
        if event.type == pygame.QUIT:            
            done = True            
ser.close()#關閉通訊介面
pygame.quit()#關閉平台
