import os
import time
import pygame
import serial
from gtts import gTTS
import speech_recognition as sr
import time as t
import pyaudio
COM_PORT ='COM7' #8 UNO
BAUD_RATES =9600   
ser = serial.Serial(COM_PORT, BAUD_RATES)
#print(ser)
#-------------------------------------

#-------------------------------------
def  vcx():
     while(1):
      hit.play()
      time.sleep(0.3)
      a=vc()
      if a=='x':break
      act(a)

def sayx(mess): 
 tts=gTTS(text=mess, lang='zh')
 tts.save('temp.mp3')
 py_mp3('temp.mp3')   
 
def py_mp3(fmp3):
 pygame.mixer.music.load(fmp3)
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
     return 'x'
    except sr.RequestError as e:
     print("No response : {0}".format(e))
     return 'x'

#time test-------------------------
w=['一','二','三','四','五','六','日']    
def say_date():
 t1=t.localtime()
 s= str(t1.tm_year-1911)+'年 '+ '星期'+w[t1.tm_wday]+' '
 s+=str(t1.tm_mon)+'月'+str(t1.tm_mday)+'日'
 print(s)
 sayx(s)

def say_time():
 t1=t.localtime()    
 s=str(t1.tm_hour)+'點'+str(t1.tm_min)+'分'+str(t1.tm_sec)+'秒'
 print(s)
 sayx(s)
 
def tdo1(sec):
    while sec:
        m=sec//60 
        s=sec%60 
        sec_format = '{:02d}:{:02d} '.format(m, s)
        #print(min_sec_format, end='/r')
        print(sec_format)
        time.sleep(1)
        sec -= 1        
    print('Time out')
    
def menu():
    show = pointFont.render('PY_ROB 7-My_dream 8-5min 9-10min', 1, (255, 0, 0))
    screen.blit(show, (5, 5))
    show = pointFont.render('2-talk 3-mp4 4-YT 5-GOO 6VOC', 1, (255, 0, 0))
    screen.blit(show, (5, 35))
    show = pointFont.render('ESC-exit  0-time 1-date  space-vc', 1, (255, 0, 0))
    screen.blit(show, (5, 65))
  

#------------------------------------------------
def ur_c():
    ins = ser.read()
    ind = ins.decode()   
#   print('data ins：', ins) 
#   print('data com：', ind)
    return ind
#---------------------------------------
def act(a):
    if(a=='123'): sayx('456') 
    if(a=='阿偉'):     sayx('請說')  
    if(a=='生日快樂'): sayx('大家生日快樂')
 #test......   
    if(a=='我的夢'):  os.system('song1.bat')
    if(a=='語音輸入'):os.system('test_vce.exe')
    if(a=='Google'):  os.system('GOO_YT.bat')

    if(a=='幾點'):say_time()
    if(a=='幾號'): say_date()
    if(a=='哪些指令'):
      sayx('您可以說')
      sayx('幾點, 幾號, 哪些指令, 介紹一下, 看影片, 谷歌')
      sayx('背單字, 我的夢')
    if(a=='介紹一下'):
      sayx('python聲控機器人是一台會走動的筆電，')
      sayx('以此為基礎，繼續探索其他python可能應用') 

    if(a=='看影片'):os.system('GOO_YT.bat')
    if(a=='谷歌'):os.system('GOO.bat')
    if(a=='背單字'):os.system('test_voc.exe')
    if(a=='我的夢'):os.system('song1.bat')      
    if(a=='倒數五分鐘'):tdo5()
    
    if(a=='前進'): ser.write(b'f')
    if(a=='後退'): ser.write(b'b')
    if(a=='左轉'): ser.write(b'l')
    if(a=='右轉'): ser.write(b'r')
    if(a=='展示'): ser.write(b'd')
    # else：ser.write(b'x')
    
def tdo(sec):
    while sec:
        m=sec//60 
        s=sec%60 
        sec_format = '{:02d}:{:02d} '.format(m, s)
        #print(min_sec_format, end='/r')
        print(sec_format)
        time.sleep(1)
        sec -= 1        
    print('Time out')

def tdo5():
    print('5...') 
    tdo(5)
    hit.play() 
    sayx('時間到')
    
      
# 主程式開始執行-----------------------------------------
pygame.init()
hit= pygame.mixer.Sound('py.wav')
pygame.mixer.init()
windowSize = [600, 300]  #400 300         
screen=pygame.display.set_mode(windowSize)
# Load images
bg1= pygame.image.load('bg1.jpg')
bg1= pygame.transform.scale(bg1, windowSize)
pointFont = pygame.font.SysFont("Monospace", 30)
screen.blit(bg1, (0, 0))  
menu()
pygame.display.flip()
sayx('python 機器人')
hit.play()
#主迴圈---------------------------------------------------
done = False                        
while  not done:
    while ser.in_waiting:          
         c=ur_c()
         if(c=='h'):sayx('python 遙控機器人')
         if(c=='v'):
          hit.play()
          time.sleep(0.3)
          a=vc()
          act(a)          
            
#RC95 dig0~9 功能--------------------------
         if(c=='A'):
            sayx('0')
            say_time()
            
         if(c=='B'):
            sayx('1')
            say_date()
            

         if(c=='C'):
            sayx('2')
            sayx('您可以說')
            sayx('幾點, 幾號, 哪些指令, 介紹一下, 看影片, 谷歌')
            sayx('背單字, 我的夢')
                     
         if(c=='D'):
            sayx('3')            
            sayx('python聲控機器人是一台會走動的筆電，')
            sayx('以此為基礎，繼續探索其他python可能應用')

                              
         if(c=='E'):
            sayx('4')
            os.system('GOO_YT.bat')
            
         if(c=='F'):
            sayx('5')
            os.system('GOO.bat')
               
         if(c=='G'):
            sayx('6')        
            os.system('test_voc.exe')          


         if(c=='H'):#----------------------
            sayx('7')
            os.system('song1.bat')
                      
         if(c=='I'):
            sayx('8')
            sayx('倒數5分鐘')
            tdo(5*60)
            hit.play() 
            sayx('時間到')           
            
         if(c=='J'):
           sayx('9')
           sayx('倒數10分鐘')
           tdo(10*60)
           hit.play() 
           sayx('時間到')
#自己設計的功能可以放在這邊------
           
          
#RC95 go 功能--------------------------         
         if(c=='f'):sayx('前進')
         if(c=='b'):sayx('後退')
         if(c=='l'):sayx('左轉')
         if(c=='r'):sayx('右轉')
         if(c=='d'):sayx('展示')        
#--------------------------
#key scan ..........  
    keys = pygame.key.get_pressed()
    if keys[pygame.K_ESCAPE]: done = True
    if keys[pygame.K_SPACE]:
       hit.play()
       time.sleep(0.3)
       a=vc()
       act(a)
          
       
    if keys[pygame.K_1]:
       '''sayx('倒數')
       tdo(10)
       hit.play() 
       sayx('時間到')'''

       print('tx 1')
       ser.write(b'1')
       time.sleep(1)
       
    if keys[pygame.K_2]:
       print('tx 2')
       ser.write(b'2')
       time.sleep(1)
       
    if keys[pygame.K_3]:
       print('tx 3')
       ser.write(b'3')       
       time.sleep(1)
       
#exit---------------------------------------        
    for event in pygame.event.get():             
        if event.type == pygame.QUIT:            
            done = True            
pygame.quit()
#------------------------


