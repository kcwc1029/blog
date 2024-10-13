import os
import time
import pygame
import serial
from gtts import gTTS
import speech_recognition as sr
import random as r

COM_PORT ='COM7' #7
BAUD_RATES =9600   
ser = serial.Serial(COM_PORT, BAUD_RATES)
#-------------------------------------------------
def ur_c():
    ins = ser.read()
    ind = ins.decode()  
    return ind

def show_pic(d):
    pf='p'+str(d)+'.jpg'
    bg= pygame.image.load(pf)
    bg= pygame.transform.scale(bg, windowSize)
    screen.blit(bg, (0, 0))  
    pygame.display.flip()
    say(d)
    
def say(d):
    if d==1:
       sayx('PC python 語音互動平台')
       sayx('應用PC 聽中文、說中文、英文、及跨平台應用')          
    if d==2:sayx('Arduino 說中文')
    
    if d==3:sayx('不須連網Arduino 可控制中文聲控')
    if d==4:sayx('不限語言，立即錄音辨認，說台語、國語、英文、特殊音效都可以辨認')
    if d==5:sayx('程式碼免費下載、教材支援')

   
def sayx(mess): 
 tts=gTTS(text=mess, lang='zh')
 tts.save("temp.mp3")
 pygame.mixer.music.load("temp.mp3")
 pygame.mixer.music.play()
 while pygame.mixer.music.get_busy():
  time.sleep(0.3)
 pygame.mixer.music.stop()
 pygame.mixer.music.unload()

def vc():
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
     print('No response : {0}'.format(e))
     return

         
def act(a):
    if a=='說明一下':
       menu()
    if a=='展示開始':
       for i in range(1,6):
           show_pic(i)
           
    if a=='聲控準嗎':
       sayx('python 可以用軟體來修正，使聲控達到高辨認率，')
       sayx('跨平台的應用中，也可以類似這種方式來做處理，')
       sayx('不同平台，有不同的設計修正方式。')
       
    if a==('arduino說中文' or '阿丟no說中文'):
       sayx('在程式碼中編輯好內碼，便可以說中文，')
       sayx('適合各式單晶片做語音控制應用。')   
    
def menu():
    sayx('您可以說')
    sayx('聲控準嗎，說明一下，展示開始，arduino說中文')                                  
#-----------------------------------------
pygame.init()
hit = pygame.mixer.Sound('py.wav')
pygame.mixer.init()
hit.play()

windowSize = [500, 400]  #800/600 1400 700         
screen=pygame.display.set_mode(windowSize)
# Load images
bg1= pygame.image.load('bg1.jpg')
bg1= pygame.transform.scale(bg1, windowSize)
#clock = pygame.time.Clock()
pointFont = pygame.font.SysFont("Monospace", 90)
screen.blit(bg1, (0, 0))

show = pointFont.render('Tro Pre', 1, (255, 0, 0))
screen.blit(show, (10, 10))

pygame.display.flip()
sayx('探索聲控')
#loop--------------------------------------------------------
done = False                        
while  not done:
    while ser.in_waiting:          
         c=ur_c()
         if c=='1':show_pic(1)
         if c=='2':show_pic(2) 
         if c=='3':show_pic(3)
         if c=='4':show_pic(4)
         if c=='5':show_pic(5)
         if c=='6':sayx('聲控互動')
         if c=='7':
            sayx('展示開始')
            for i in range(1,6):
             show_pic(i)
             
         if c=='8':menu()
         if c=='9':
            hit.play()
            time.sleep(0.3)
            screen.blit(bg1, (0, 0))    
            show = pointFont.render('say?', 1, (255, 0, 0))
            screen.blit(show, (80, 100))
            pygame.display.flip()
            a=vc()
            act(a)   
#--------------------------
#key scan ..........  
    keys = pygame.key.get_pressed()
    if keys[pygame.K_ESCAPE]: done = True
    if keys[pygame.K_SPACE]:
       hit.play()
       time.sleep(0.3)
       screen.blit(bg1, (0, 0))    
       show = pointFont.render('say?', 1, (255, 0, 0))
       screen.blit(show, (80, 100))
       pygame.display.flip()
       a=vc()
       act(a)           
           
    if keys[pygame.K_1]:show_pic(1)       
    if keys[pygame.K_2]:show_pic(2)              
    if keys[pygame.K_3]:show_pic(3)
    if keys[pygame.K_4]:show_pic(4)   
    if keys[pygame.K_5]:show_pic(5)
    time.sleep(0.5)    
#exit---------------------------------------        
    for event in pygame.event.get():             
        if event.type == pygame.QUIT:            
            done = True
            
pygame.quit()                                    #
