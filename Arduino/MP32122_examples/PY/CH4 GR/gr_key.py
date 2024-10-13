import time
import pygame

def py_mp3(fmp3):
 pygame.mixer.music.load(fmp3)
 pygame.mixer.music.play()
 while pygame.mixer.music.get_busy():
  time.sleep(0.3)  
 pygame.mixer.music.stop()
 pygame.mixer.music.unload()
  
def menu():
    show = pointFont.render('1-test wav 2-mp3 ESC-exit',
                            1, (255, 0, 0))
    screen.blit(show, (0, 35))
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
    if keys[pygame.K_1]:
       hit.play()
             
    if keys[pygame.K_2]:
       py_mp3('t1.mp3')               
                
    if keys[pygame.K_ESCAPE]:
       done = True
#   pygame.display.flip()
# ---------------------------------------
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
    clock.tick(60)
pygame.quit()  




