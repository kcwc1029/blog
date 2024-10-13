import os
import time
import pygame
import serial
from gtts import gTTS
import speech_recognition as sr

COM_PORT ='COM7' #7
BAUD_RATES =9600   
ser = serial.Serial(COM_PORT, BAUD_RATES)
#print(ser)
#-------------------------------------------------
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
   
def ur_c():
    ins = ser.read()
    ind = ins.decode()   
#   print('data ins：', ins) 
#   print('data com：', ind)
    return ind
def menu():
    show = pointFont.render('song_rcX 0~5 / key 0~5', 1, (255, 0, 0))
    screen.blit(show, (5, 5))
    show = pointFont.render('ESC-exit  SPACE-VC', 1, (255, 0, 0))
    screen.blit(show, (5, 35))

def act(a):
#'''我的夢 火戰車  1812  絕地任務 我的樓蘭'''
    if a=='我的夢':os.system('song1.bat')
    if a=='火戰車':os.system('song2.bat')
    if a=='1812'  :os.system('song3.bat')
    if a=='絕地任務':os.system('song4.bat')
    if a=='我的樓蘭':os.system('song5.bat')       
#-----------------------------------------
pygame.init()
hit= pygame.mixer.Sound('py.wav')
pygame.mixer.init()
hit.play()

windowSize = [400, 300]  #800/600 1400 700         
screen=pygame.display.set_mode(windowSize)
# Load images
bg1= pygame.image.load('bg1.jpg')
bg1= pygame.transform.scale(bg1, windowSize)
pointFont = pygame.font.SysFont("Monospace", 30)
screen.blit(bg1, (0, 0))
menu()
pygame.display.flip()
#loop---------------------------------------
done = False                        
while  not done:
    while ser.in_waiting:         
         c=ur_c()
         if c=='0':os.system('GOO_YT.bat')            
         if c=='1':os.system('song1.bat')
         if c=='2':os.system('song2.bat')
         if c=='3':os.system('song3.bat')
         if c=='4':os.system('song4.bat')
         if c=='5':os.system('song5.bat')
         if c=='9':
            hit.play()
            time.sleep(0.3)             
            a=vc()
            act(a)                            
#--------------------------
#key scan ..........  
    keys = pygame.key.get_pressed()
    if keys[pygame.K_ESCAPE]: done = True
    if keys[pygame.K_0]:os.system('GOO_YT.bat') 
    if keys[pygame.K_1]:os.system('song1.bat')              
    if keys[pygame.K_2]:os.system('song2.bat')
    if keys[pygame.K_3]:os.system('song3.bat')   
    if keys[pygame.K_4]:os.system('song4.bat')
    if keys[pygame.K_5]:os.system('song5.bat')
    if keys[pygame.K_SPACE]:
       hit.play()
       time.sleep(0.3)             
       a=vc()
       act(a)       
    time.sleep(0.5)    
#exit---------------------------------------        
    for event in pygame.event.get():             
        if event.type == pygame.QUIT:            
            done = True            
pygame.quit()                                    
