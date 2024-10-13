from machine import Pin
from time import sleep

# 設定聲音感測器和 LED 的引腳
sound_sensor = Pin(5, Pin.IN)  # D1 引腳作為輸入，用於連接聲音感測器 (GPIO 5)
led = Pin(4, Pin.OUT)          # D2 引腳作為輸出，用於連接 LED (GPIO 4)

# 持續監測聲音感測器的狀態
while True:
    # 讀取聲音感測器的輸出值，HIGH (1) 表示偵測到聲音
    print(sound_sensor.value())
    if sound_sensor.value() == 1:
        print("聲音偵測到!")
        led.on()  # 開啟 LED
    else:
        print("沒聲音")
        led.off()  # 關閉 LED

    sleep(1)  # 每 0.1 秒檢查一次
    
    
    
    
    
    
    
    
    
    
    
    
    
    