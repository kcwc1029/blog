import time
import pygame
import serial
from gtts import gTTS

COM_PORT = 'COM7'    
BAUD_RATES = 9600   

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
#-----------------------------------
ser = serial.Serial(COM_PORT, BAUD_RATES)
pygame.init()
hit   = pygame.mixer.Sound("py.wav")
pygame.mixer.init()
windowSize = [400, 300] 
screen=pygame.display.set_mode(windowSize)

# Load images
bg = pygame.image.load("bg1.jpg")
bg = pygame.transform.scale(bg, windowSize)

# Font for points
pointFont = pygame.font.SysFont("Monospace", 100)
co=0
# Render points for display
screen.blit(bg, (0, 0))    
show = pointFont.render(str(co), 1, (255, 255, 255))
screen.blit(show, (100, 100))
pygame.display.flip()
hit.play()
#loop--------------------------------------------------------
done = False
while  not done:
    while ser.in_waiting:          
            ins = ser.read()  
            ind = ins.decode()               
            c=ind
            print(c)
            if c=='c': 
               print('clr')
               co=0
               screen.blit(bg, (0, 0))    
               show = pointFont.render(str(co), 1, (255, 0, 255))
               screen.blit(show, (100, 100))
               pygame.display.flip()                        
                              
            if c=='i': 
               print('inc')
               co+=1
               hit.play()
               screen.blit(bg, (0, 0))    
               show = pointFont.render(str(co), 1, (255, 0, 255))
               screen.blit(show, (100, 100))
               pygame.display.flip()               
            
    keys = pygame.key.get_pressed()
    if keys[pygame.K_SPACE]:
       sayx('計數=')
       sayx(str(co))   
    if keys[pygame.K_ESCAPE]: done = True
# ---------------------------------------
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
ser.close()  
pygame.quit()
