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
    pf='p'+str(d)+'.png'
    bg= pygame.image.load(pf)
    bg= pygame.transform.scale(bg, windowSize)
    screen.blit(bg, (0, 0))  
    pygame.display.flip()
    say(d)
    

def say(d):
    if d==1:sayx('pissa')
    if d==2:sayx('滷味')
    if d==3:sayx('海鮮麵')
    if d==4:sayx('海鮮粥')
    if d==5:sayx('蒸蛋')
    
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
     print("No response : {0}".format(e))
     return

def ran_show(d):
    show_pic(d)

def eat():
    r1=r.randint(1,5)  
    show_pic(r1)
    say(r1)
    screen.blit(bg1, (0, 0))
         
def act(a):
    if(a=='說明一下'):
       menu()      
    if(a=='這餐吃什麼'):
       eat()      
    if(a=='早餐吃什麼'):
       eat()         
    if(a=='吃什麼'):
       eat()
    if(a=='海鮮麵'):
       tdo_sea()
def menu():
    sayx('您可以說')
    sayx('吃什麼，說明一下，海鮮麵')

def tdo_sea():
 show_pic(3)
 sayx('1，準備食材約 5 分鐘，開始計時')
 tdo(5*60)
 sayx('時間到')

 sayx('2，煮水沸騰後，注水入食材，加溫5分鐘，開始計時')
 tdo(5*60)
 sayx('時間到')

 sayx('3，燜5分鐘，可以食用，開始計時')
 tdo(5*60)
 sayx('時間到')
 sayx('4，祝您用餐愉快')

def tdo(sec): #秒倒數計時器
    while sec: #秒數=0 離開
        m=sec//60 #除法取商數
        s=sec%60 #除法取餘數
        sec_format = '{:02d}:{:02d} '.format(m, s)
        print(sec_format)
        time.sleep(1) #延遲一秒
        sec -= 1 #秒數減一
        #print('Time out')
        bg= pygame.image.load('p3.png')
        bg= pygame.transform.scale(bg, windowSize)
        screen.blit(bg, (0, 0))        
        show = pointFont.render( str(sec_format), 1, (255, 0, 0))
        screen.blit(show, (5, 120))
        pygame.display.flip() 
                                      
#-----------------------------------------
pygame.init()
hit = pygame.mixer.Sound('py.wav')
pygame.mixer.init()
hit.play()

windowSize = [600, 400]  #800/600 1400 700         
screen=pygame.display.set_mode(windowSize)
# Load images
bg1= pygame.image.load('bg1.jpg')
bg1= pygame.transform.scale(bg1, windowSize)
#clock = pygame.time.Clock()
pointFont = pygame.font.SysFont("Monospace", 90)
screen.blit(bg1, (0, 0))  
pygame.display.flip()
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
         if c=='7':tdo_sea()
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
    if keys[pygame.K_6]:sayx('測試')
    if keys[pygame.K_7]:tdo_sea()
    #time.sleep(0.5)    
#exit---------------------------------------        
    for event in pygame.event.get():             
        if event.type == pygame.QUIT:            
            done = True
            
pygame.quit()                                    
