from gtts import gTTS
import pygame
import time

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

def voc_mp3(fi):  
     file=''        
     file=fi+'.txt'
     with open(file,'r') as f:
         text=f.readlines()     
     for line in text:       
      tline=''
      tline+=line
      print(tline)
      sayx(tline)
      time.sleep(1)     

pygame.init()
sayx('python 背單字')
voc_mp3('ten1')
pygame.quit()
