import time
import pygame
pygame.init()
windowSize = [400, 300] 
screen=pygame.display.set_mode(windowSize)

bg = pygame.image.load('bg1.jpg')#載入背景圖檔
bg = pygame.transform.scale(bg, windowSize) 
screen.blit(bg, (0, 0)) #將圖片顯示出來
pygame.display.flip()

hit  = pygame.mixer.Sound('py.wav')  #播放語音格式為WAV檔
pygame.mixer.init()
hit.play()
time.sleep(1)

pygame.mixer.music.load('py.mp3')           
pygame.mixer.music.play()               
while pygame.mixer.music.get_busy():    
 time.sleep(0.3)                        
pygame.mixer.music.stop()    

time.sleep(1)
pygame.quit()
