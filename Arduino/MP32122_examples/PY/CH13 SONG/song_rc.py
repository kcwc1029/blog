import os
import time
import pygame
import serial
COM_PORT ='COM7' #7
BAUD_RATES =9600   
ser = serial.Serial(COM_PORT, BAUD_RATES)
#print(ser)
#-------------------------------------------------
def ur_c():
    ins = ser.read()
    ind = ins.decode()   
    return ind
def menu():
    show = pointFont.render('song_rc 0~5 / key 0~5', 1, (255, 0, 0))
    screen.blit(show, (5, 5))
    show = pointFont.render('ESC-exit', 1, (255, 0, 0))
    screen.blit(show, (5, 35))       
#-----------------------------------------
pygame.init()
crash = pygame.mixer.Sound('py.wav')
pygame.mixer.init()
crash.play()

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
    time.sleep(0.5)    
#exit---------------------------------------        
    for event in pygame.event.get():             
        if event.type == pygame.QUIT:            
            done = True            
pygame.quit()                                    
