import time
import pygame
from gtts import gTTS
import speech_recognition as sr

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

def py_mp3(fmp3):
 pygame.mixer.music.load(fmp3)
 pygame.mixer.music.play()
 while pygame.mixer.music.get_busy():
  time.sleep(0.3)  
 pygame.mixer.music.stop()
 pygame.mixer.music.unload()

def sayx(mess): 
 tts=gTTS(text=mess, lang='zh')
 tts.save("temp.mp3")
 py_mp3('temp.mp3')
 
   
def menu():
    screen.blit(bg, (0, 0))
    show = pointFont.render('1-test wav 2-say ESC-exit',
                            1, (255,0,0))
    screen.blit(show, (0, 35))
    show = pointFont.render('SPACE-VC', 1, (255, 0, 0))
    screen.blit(show, (0, 70))   
    pygame.display.flip()
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
pointFont = pygame.font.SysFont("Monospace", 25)#80
screen.blit(bg, (0, 0))
pygame.display.flip()
menu()
hit.play()
#loop--------------------------------
done = False
while  not done:
    keys = pygame.key.get_pressed()
    if keys[pygame.K_1]:hit.play()
    if keys[pygame.K_2]:sayx('語音互動')
   
    if keys[pygame.K_SPACE]:
       hit.play()
       screen.blit(bg, (0, 0))    
       show = pointFont.render('say?', 1, (255, 0, 0))
       screen.blit(show, (80, 100))
       pygame.display.flip()
       a=vc()
       if(a=='123'):      sayx('456')
       if(a=='hello'):    sayx('請說')
       if(a=='哈囉'):     sayx('請說')
       if(a=='生日快樂'): sayx('大家生日快樂')
       menu()
                       
    if keys[pygame.K_ESCAPE]:
       done = True
    pygame.display.flip()
# ---------------------------------------
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
    clock.tick(60)
pygame.quit()  




