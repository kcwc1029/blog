import time
import pygame
from gtts import gTTS
def py_mp3(fmp3):
 pygame.mixer.music.load(fmp3)
 pygame.mixer.music.play()
 while pygame.mixer.music.get_busy():
  time.sleep(0.3)  
 pygame.mixer.music.stop()
 pygame.mixer.music.unload()

def sayx(mess): 
 tts=gTTS(text=mess, lang='zh')
 tts.save('temp.mp3')
 py_mp3('temp.mp3')
 
def tdo(sec):
    while sec:
        m=sec//60 #除法取商數
        s=sec%60 #除法取餘數
        sec_format = '{:02d}:{:02d} '.format(m, s)
        print(sec_format)
        time.sleep(1)
        sec -= 1
    #print('Time out')
        screen.blit(bg, (0, 0))
        menu()
        show = pointFont.render( str(sec_format), 1, (255, 0, 0))
        screen.blit(show, (5, 120))
        pygame.display.flip() 
def menu():
    show = pointFont.render('1-5min  2-10min ',1, (255, 0, 0))
    screen.blit(show, (0, 0))
    show = pointFont.render('3-20min  ESC-exit',1, (255, 0, 0))
    screen.blit(show, (0, 35))    
#-----------------------------
pygame.init()
hit  = pygame.mixer.Sound("py.wav")
#---------------------------------
pygame.mixer.init()
windowSize = [400, 300] # 400 300
screen=pygame.display.set_mode(windowSize)
clock = pygame.time.Clock()
bg = pygame.image.load("bg1.jpg")
bg = pygame.transform.scale(bg, windowSize)
pointFont = pygame.font.SysFont("Monospace",25)#80
screen.blit(bg, (0, 0))
pygame.display.flip()
menu()
sayx('倒數計時器')
#loop--------------------------------
done = False
while  not done:
    keys = pygame.key.get_pressed()
    #time.sleep(1)
    if keys[pygame.K_1]:
       hit.play()
       tdo(5*60)
       sayx('時間到')
             
    if keys[pygame.K_2]:
       hit.play()
       tdo(10*60)
       sayx('時間到')

    if keys[pygame.K_3]:
       hit.play()
       tdo(20*60)
       sayx('時間到')   
                
    if keys[pygame.K_ESCAPE]:
       done = True
    pygame.display.flip()
# ---------------------------------------
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
pygame.quit()
