import os
import time
import pygame
import serial
COM_PORT ='COM7' #設定通訊埠
BAUD_RATES =9600   
ser = serial.Serial(COM_PORT, BAUD_RATES)
#print(ser)
#接收指令-------------------------------------------
def ur_c():
    ins = ser.read()
    ind = ins.decode()   
    return ind      
#主程式開始執行-----------------------------------
pygame.init()#平台初始化
hit= pygame.mixer.Sound('py.wav')
pygame.mixer.init()
hit.play()
windowSize = [400, 300] #視窗大小設定
screen=pygame.display.set_mode(windowSize)
# 載入背景圖片
bg1= pygame.image.load('bg1.jpg')
bg1= pygame.transform.scale(bg1, windowSize)
#設定顯示字元大小
pointFont = pygame.font.SysFont("Monospace", 30)
screen.blit(bg1, (0, 0))  
#menu() #顯示按鍵說明
pygame.display.flip()
#迴圈執行------------------------------------------------
done = False                        
while  not done:
#掃描串列介面是否有命令傳入
    while ser.in_waiting:          
         c=ur_c()
         if c=='1':os.system('p1.mp4')
         if c=='2':os.system('p2.mp4')   
         if c=='3':os.system('p3.mp4') 
         if c=='4':os.system('p4.mp4')
         if c=='5':os.system('p5.mp4') 
#按鍵掃描--------------
    keys = pygame.key.get_pressed()
    if keys[pygame.K_ESCAPE]: done = True
    if keys[pygame.K_1]: os.system('p1.mp4')
    if keys[pygame.K_2]: os.system('p2.mp4')
    if keys[pygame.K_3]: os.system('p3.mp4')
    if keys[pygame.K_4]: os.system('p4.mp4')
    if keys[pygame.K_5]: os.system('p5.mp4')   
    time.sleep(0.5)                    
#結束迴圈------------------------        
    for event in pygame.event.get():             
        if event.type == pygame.QUIT:            
            done = True            
ser.close()#關閉通訊介面
pygame.quit()#關閉平台
