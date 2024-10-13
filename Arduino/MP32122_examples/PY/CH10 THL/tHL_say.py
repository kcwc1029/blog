import time
import pygame
import serial
from gtts import gTTS

COM_PORT ='COM7' #7
BAUD_RATES =9600   
ser = serial.Serial(COM_PORT, BAUD_RATES)
#print(ser)
#-------------------------------------------------
def sayx(mess): 
 tts=gTTS(text=mess, lang='zh')
 tts.save("temp.mp3")
 pygame.mixer.music.load("temp.mp3")
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
#---------------------------------
def wait_ur_c():    
    while 1: 
     while ser.in_waiting:  #scan.....
      c=ur_c()
      return c

def get_data():  #hold here.....rc test .....
    ser.write(b'1')
    c=wait_ur_c() #judge '1' d1 d2
#if c='1' get d1 d2    chr(65)='A' ord('A')=65
    c1=wait_ur_c()
    c2=wait_ur_c()
    if(c=='1'):
     d1=ord(c1)
     d2=ord(c2)
     #print('data:%s %s |%d %d' %(c1,c2,d1,d2))
     print('data:%d %d' %(d1,d2))
     show_data(d1,d2)
     if(d1>26):
       sayx('溫度過高')
       sayx('溫度'+str(d1))
     
def show_data(d1,d2):
    screen.blit(bg1, (0, 0))
    show = pointFont.render('TEMP/ Hum link ', 1, (255, 0, 0))
    screen.blit(show, (5, 5))
    show = pointFont.render(str(d1)+'C', 1, (255, 0, 0))
    screen.blit(show, (5,  45))
    show = pointFont.render(str(d2)+'%', 1, (255, 0, 0))
    screen.blit(show, (85, 45))
    pygame.display.flip()

     
#-----------------------------------------
pygame.init()
crash = pygame.mixer.Sound('py.wav')
pygame.mixer.init()
crash.play()

windowSize = [400, 300]           
screen=pygame.display.set_mode(windowSize)
# Load images
bg1= pygame.image.load('bg1.jpg')
bg1= pygame.transform.scale(bg1, windowSize)
pointFont = pygame.font.SysFont("Monospace", 30)#180
screen.blit(bg1, (0, 0))

show = pointFont.render('TEMP/ Hum link ', 1, (255, 0, 0))
screen.blit(show, (5, 5))
pygame.display.flip()
#loop------------------------------------------------
done = False                        
while  not done:
#check data......
    get_data()
    time.sleep(1)
    while ser.in_waiting:  #no use        
         c=ur_c()
         #if c=='1':print('1')                                       
#--------------------------
#key scan ..........  
    keys = pygame.key.get_pressed()
    if keys[pygame.K_ESCAPE]: done = True
    if keys[pygame.K_1]:
       get_data()
       time.sleep(1)
       
    if keys[pygame.K_2]:
       print('tx 2')
        
    if keys[pygame.K_3]:
       print('tx 3')
       ser.write(b'3')       
        
#exit---------------------------------------        
    for event in pygame.event.get():             
        if event.type == pygame.QUIT:            
            done = True            
pygame.quit()                                    
