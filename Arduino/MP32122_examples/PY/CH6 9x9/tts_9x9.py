from gtts import gTTS
import pygame
import time
import keyboard

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
  

'''
for a in range(1,10):
  for b in range(1,10):
   pro=a*b
   print('%d*%d=%2d ' %(a,b,pro), end='')
  print() '''

def say_99(d):#d乘b=pro 9乘9=81
 for b in range(1,10):    
  pro=d*b
  print('%d*%d=%2d ' %(d,b,pro), end='')
  m=str(d)+'乘'+str(b)+'='+str(pro)
# if keyboard.read_key()=='q'：break
  sayx(m)
#------------------------------------------
'''pro=9  
m=str(9)+'乘'+str(1)+'='+str(pro)
print(m)
pygame.init()
sayx(m)'''

pygame.init()
sayx('python 背九九乘法表')
print('wait key1~9  q--quit')
while 1 :
 if keyboard.read_key()=='1':say_99(1)    
 if keyboard.read_key()=='q':break
 if keyboard.read_key()=='2':say_99(2)    
 if keyboard.read_key()=='3':say_99(3)
 if keyboard.read_key()=='4':say_99(4)    
 if keyboard.read_key()=='5':say_99(5)
 if keyboard.read_key()=='6':say_99(6)    
 if keyboard.read_key()=='7':say_99(7)
 if keyboard.read_key()=='8':say_99(8)    
 if keyboard.read_key()=='9':say_99(9)   
    
pygame.quit()

