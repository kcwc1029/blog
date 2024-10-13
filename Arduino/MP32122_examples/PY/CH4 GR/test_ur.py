import time
import pygame
import serial

COM_PORT ='COM7' #8 UNO
BAUD_RATES =9600   
ser = serial.Serial(COM_PORT, BAUD_RATES)
#print(ser)
#-------------------------------------------------
def ur_c():
    ins = ser.read()
    ind = ins.decode()   
#   print('data ins：', ins) 
#   print('data com：', ind)
    return ind
      
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
screen.blit(bg1, (0, 0))  
pygame.display.flip()

#loop--------------------------------------------------------
done = False                        
while  not done:
    while ser.in_waiting:          
         c=ur_c()
         if c=='1':print('1')                      
         if c=='2':print('2')
         if c=='3':print('3')
         
#--------------------------
#key scan ..........  
    keys = pygame.key.get_pressed()
    if keys[pygame.K_ESCAPE]: done = True
    if keys[pygame.K_1]:
       print('tx 1')
       ser.write(b'1')
       time.sleep(1)
       
    if keys[pygame.K_2]:
       print('tx 2')
       ser.write(b'2')
       time.sleep(1)
       
    if keys[pygame.K_3]:
       print('tx 3')
       ser.write(b'3')       
       time.sleep(1)
#exit---------------------------------------        
    for event in pygame.event.get():             
        if event.type == pygame.QUIT:            
            done = True            
pygame.quit()                                    
