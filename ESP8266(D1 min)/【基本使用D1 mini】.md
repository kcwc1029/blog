- 採用auduino IDE
![upgit_20241009_1728443233.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241009_1728443233.png)

![upgit_20241009_1728443255.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241009_1728443255.png)

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

- 安裝ESP8266庫
![upgit_20241009_1728443327.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241009_1728443327.png)



- 開發版選擇`LOLIN(WEMOS) D1 R2 & mini`
- 【測試】內建的LED燈
```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // 設置內建LED為輸出模式
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // 開啟LED
  delay(1000);                     // 等待1秒
  digitalWrite(LED_BUILTIN, LOW);  // 關閉LED
  delay(1000);                     // 等待1秒
}
```

![upgit_20241009_1728443941.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241009_1728443941.png)


## 如果要使用Micropython
- 首先要先裝python
- 下載Thonny
- 到Micropython去下載燒錄檔 https://micropython.org/download/ESP8266_GENERIC/
- 到你的python環境中(我這邊因為python是用anaconda的，所以我要到anaconda的Anaconda Prompt)
```python
pip install esptool

!esptool.py --port COM9 erase_flash

python -m esptool --port COM9 --baud 460800 write_flash --flash_size=detect 0 "C:\path\to\your\ESP8266_GENERIC-20240602-v1.23.0.bin"
# 燒錄
# 作後一個參數，就是要讓電腦吃到你的燒錄檔
```
- 【測試】利用Micropythond控制D1mini內建的LED
```python
from machine import Pin
from time import sleep

# 建立一個 LED 物件，GPIO 2 通常是 D1 Mini 的內建 LED
led = Pin(2, Pin.OUT)

# 開啟 LED
led.on()  # 或者使用 led.value(1)
sleep(1)  # 保持亮燈 1 秒

# 關閉 LED
led.off()  # 或者使用 led.value(0)
sleep(1)  # 保持熄燈 1 秒

# 讓 LED 持續閃爍
while True:
    led.on()
    sleep(0.5)  # 保持亮燈 0.5 秒
    led.off()
    sleep(0.5)  # 保持熄燈 0.5 秒
```


- 【測試】
```python
import network
import time

# 設定 Wi-Fi 名稱 (SSID) 和密碼
SSID = "ALHC-guest000" # "你的WiFi名稱"
PASSWORD = "ALHCguest000"# "你的WiFi密碼"

# 建立 Wi-Fi STA 模式 (Station 模式)
wifi = network.WLAN(network.STA_IF)
wifi.active(True)  # 啟用 Wi-Fi

# 連接到指定的 Wi-Fi 網路
print(f"正在連接到 Wi-Fi：{SSID}")
wifi.connect(SSID, PASSWORD)

# 等待連線
while not wifi.isconnected():
    print("連接中...")
    time.sleep(1)

# Wi-Fi 連線成功後顯示 IP 位址
print("Wi-Fi 連接成功!")
print("IP 地址:", wifi.ifconfig()[0])
```

## 接腳圖
![upgit_20241009_1728448235.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241009_1728448235.png)








