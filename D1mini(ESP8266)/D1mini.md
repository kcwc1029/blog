## 1. 安裝事項

-   插入電腦後，要到裝置管理員察看

![upgit_20241225_1735116720.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735116720.png)

-   要安裝 CH340 驅動程式：https://www.wch.cn/download/ch341ser_exe.html

## 2. 燒錄+使用

-   這邊花了窩一整天 QQ

### 2.1. 方式 1：使用 arduino 開發

-   一樣開 arduino IDE
-   在偏好設定添加 ESP8266 的開發版管理員網址：http://arduino.esp8266.com/stable/package_esp8266com_index.json
-   在【開發版管理員】安裝【esp8266】
    ![upgit_20241225_1735127961.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735127961.png)

-   板子記得要選好，不然會燒不進去
    ![upgit_20241225_1735127992.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735127992.png)

-   測試程式碼

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // 設置內建 LED (GPIO2) 為輸出
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);  // 開啟 LED
  delay(1000);                    // 延遲 1 秒
  digitalWrite(LED_BUILTIN, HIGH); // 關閉 LED
  delay(1000);                    // 延遲 1 秒
}
```

### 2.2. 方式 2：使用 micropython 開發

-   在燒錄方式有兩種：

#### 2.2.1. 第一種：thonny 內建燒錄(2024.12.25 使用失敗)

![upgit_20241225_1735128135.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735128135.png)

![upgit_20241225_1735128158.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735128158.png)

![upgit_20241225_1735128185.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735128185.png)

#### 2.2.2. 第 2 種：NodeMCU pyflasher 燒錄(有成功)

-   先去下載韌體：[MicroPython - Python for microcontrollers](https://micropython.org/download/ESP8266_GENERIC/)
-   下載燒入軟體：[Release 5.0 - bumping dependencies · marcelstoer/nodemcu-pyflasher](https://github.com/marcelstoer/nodemcu-pyflasher/releases/tag/v5.0.0)
-   那個 exe 把他載下來
    ![upgit_20241225_1735128522.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735128522.png)

### 2.3. 燒錄完後，執行程式看看

```python
from machine import Pin
import utime

led = Pin(2, Pin.OUT)
while True:
    led.value(0)
    utime.sleep(1)
    led.value(1)
    utime.sleep(1)
```

-   儲存在本地端即可
    ![upgit_20241225_1735128660.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735128660.png)

## 3. D1 mini 接腳圖

![upgit_20241227_1735277114.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241227_1735277114.png)

-   有 11 個數位 IO 腳位，支持以下功能：

    -   GPIO0 (D3): 可作為數位 IO 或其他功能腳位。
    -   GPIO1 (TX): 用於 UART 傳輸數據，也可作為數位 IO。
    -   GPIO2 (D4): 默認接上內部 LED，支持數位 IO。
    -   GPIO3 (RX): 用於 UART 接收數據，也可作為數位 IO。
    -   GPIO4 (D2): 通用數位 IO 腳位。
    -   GPIO5 (D1): 通用數位 IO 腳位。
    -   GPIO12 (D6): 通用數位 IO 腳位。
    -   GPIO13 (D7): 通用數位 IO 腳位。
    -   GPIO14 (D5): 通用數位 IO 腳位。
    -   GPIO15 (D8): 通用數位 IO 腳位，內部有下拉電阻。
    -   GPIO16 (D0): 通用數位 IO 腳位，支持深度睡眠喚醒功能。

-   有一個類比輸入腳位：
    -   A0 (ADC)：可測量的電壓範圍：0 ~ 1.0V。

## 4. 數位輸入/輸出

-   輸出 1/0 與時間控制

```python
from machine import Pin
import utime

led = Pin(2, Pin.OUT)
while True:
    led.value(0) # 輸出0
    utime.sleep(1)
    led.value(1)
    utime.sleep(1) # 輸出1
```

-   讀取腳位狀態值來閃爍 LED

```python
import utime
from machine import Pin

led = Pin(2, Pin.OUT)
led.value(1)
while True:
    v = led.value() # 讀取狀態
    print("狀態值", v)
    v = not v
    print("更改狀態", v)
    led.value(v)
    utime.sleep(1)
```

-   取得按鍵開關的數位輸入值

```python
import utime
from machine import Pin

button = Pin(4, Pin.IN)
while True:
	print(button.value())
	utime.sleep(1)
```

## 5. 類比輸入/輸出

-   PWM

```python
# TODO: 建立PWM物件
from machine import Pin, PWM
import utime

pin = Pin(15, Pin.OUT)
led_pwm = PWM(pin,
			freq=1000 # 切換頻率
			duty=512 # 勤務循環(duty cycle)控致電壓(0-1023)
			)
```

```python
from machine import Pin, PWM
import utime

led_pwm = PWM(Pin(15))

while True:
    for i in range(0, 1024, 10):   #  從0至1023
        led_pwm.duty(i)
        utime.sleep(0.01)
    for i in range(1023, -1, -10): #  從1023至0
        led_pwm.duty(i)
        utime.sleep(0.01)
```

-   3 色 LED 數位輸出：開關按一下亮紅 LED，按一下亮綠 LED，按一下亮藍 LED

```python
from machine import Pin

leds = [Pin(15,Pin.OUT),Pin(12,Pin.OUT),Pin(13,Pin.OUT)]
button = Pin(4, Pin.IN, Pin.PULL_UP)

def leds_off():
   for led in leds:
       led.value(0)

leds_off()
idx = 0
while True:
    if not button():
        leds_off()
        leds[idx].value(1)   # 點亮Pin物件的LED
        idx = idx + 1
        if idx > 2:
            idx = 0
        while not button():  # 過濾多餘的按下按鍵
            pass
```

-   類比輸入：以光敏電阻為例

```python
from machine import ADC
import utime

adc = ADC(0) # 0就是A0

while True:
    adc_value = adc.read()
    print(adc_value)
    utime.sleep(0.5)

```

-   光敏電阻控制 LED

```python
from machine import ADC, Pin
import utime

adc = ADC(0)
led = Pin(15, Pin.OUT)
led.value(0)
while True:
    value = adc.read()
    print(value)
    if value < 100:     # 光線不足
        led.value(1)    # 點亮LED
        utime.sleep(0.5)
    else:               # 否則
        led.value(0)    # 熄滅LED
        utime.sleep(0.5)
```

-   實作全彩 RGB LED

```python
from machine import Pin, PWM
import utime

ledR = PWM(Pin(15))
ledG = PWM(Pin(12))
ledB = PWM(Pin(13))

# 模仿map映射
def map_range(x, in_min, in_max, out_min, out_max):
    return int((x-in_min)*(out_max-out_min)/(in_max-in_min)+out_min)

# 亮LED燈
def rgb(r, g, b):
   ledR.duty(map_range(r, 0, 255, 0, 1023))
   ledG.duty(map_range(g, 0, 255, 0, 1023))
   ledB.duty(map_range(b, 0, 255, 0, 1023))

def led_off():
   ledR.duty(0)
   ledG.duty(0)
   ledB.duty(0)

led_off()
rgb(255, 0, 0)
utime.sleep(1)
led_off()
rgb(0, 255, 0)
utime.sleep(1)
led_off()
rgb(0, 0, 255)
utime.sleep(1)
led_off()
rgb(255, 255, 255)
utime.sleep(1)
led_off()
rgb(255, 255, 0)
utime.sleep(1)
led_off()
```

## 6. 連接 wifi 基地台

-   STA 模式(station)：讓 ESP8266 如同一張 widi 無線網路卡，可以連線至可用基地台
-   AP 模式(access point)：讓 ESP8266 作為熱點

-   顯示可連線 wifi 基地台的 mac 地址

```python
import network
import ubinascii

sta = network.WLAN(network.STA_IF)  # 創建 STA 模式的 WLAN 物件 (Station模式)
sta.active(True)  # 啟用 WLAN
print("當前開發版是否已經連上網路：", sta.isconnected())  # 檢查是否已連接到 Wi-Fi 網絡
print("----------")

aps = sta.scan()  # 掃描附近的 Wi-Fi 熱點
for ap in aps:  # 遍歷掃描結果
    ssid = ap[0].decode()  # 提取 SSID（網絡名稱），並將 bytes 解碼為字串
    mac = ubinascii.hexlify(ap[1], ":").decode()  # 提取 BSSID（MAC 位址），轉換為可讀格式
    print(ssid, mac)  # 打印 SSID 和 MAC 位址

# 輸出
# MPY: soft reboot
# 當前開發版是否已經連上網路： False
# ----------
# MCAS_Lab fc:34:97:d1:f4:10
# 41112 7c:10:c9:e0:86:38
# guest_2.4G fc:34:97:2a:dd:51
#  62:83:e7:29:d2:da
# 16-3A f8:1d:0f:47:51:18
# PASI_LAB c8:3a:35:3b:e4:20
# gedlab_2G a8:5e:45:09:6f:40
# yucheng fc:34:97:2a:e1:31
# ALHC_Lab c8:78:7d:e6:ac:84
# ALHC-guest ca:78:7d:e6:ac:84
```

-   在成功連線 WiFi 基地台後馬上中斷連線

```python
import network
import time

# 連接到指定的 Wi-Fi 熱點。
def connect_to_wifi(ssid, password, timeout=10):
    sta = network.WLAN(network.STA_IF)
    sta.active(True)

    if not sta.isconnected():
        print("嘗試連接到 Wi-Fi...")
        sta.connect(ssid, password)

        start_time = time.time()
        while not sta.isconnected():
            if time.time() - start_time > timeout:
                print("連接超時，請檢查 SSID 和密碼是否正確。")
                return None
            time.sleep(0.5)
    print("成功連接到 Wi-Fi!")
    return sta.ifconfig()

def disconnect_from_wifi():
    """
    斷開 Wi-Fi 連接。
    返回：
        bool: 返回是否仍然保持連接（True 表示連接，False 表示已斷開）。
    """
    sta = network.WLAN(network.STA_IF)
    if sta.isconnected():
        sta.disconnect()
        print("已斷開 Wi-Fi 連線。")
    else:
        print("目前無 Wi-Fi 連線。")
    return sta.isconnected()


if __name__ == "__main__":
    ssid = "ALHC-guest"
    password = "ALHCguest"
    # 連接到 Wi-Fi
    config = connect_to_wifi(ssid, password, timeout=10)
    if config:
        # 輸出：IP、mask、Gateway、DNS
        print("網絡配置:", config)
        time.sleep(3)

        # 斷開連線
        is_connected = disconnect_from_wifi()
        print("連線狀態:", is_connected)
```

## 7. 處裡 HTTP 請求(GET、POST)

![upgit_20241227_1735282313.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241227_1735282313.png)

-   測試工具：https://httpbin.org/
-   URL 的參數如果包含中文的話，需要進行 URL 編碼，可視膽
-   如果要傳中文的話，需要將文字轉成 unicode
-   Google Chrome 的 RestMan 擴充功能提供圖形化介面來送出 HTTP 請求，可以檢視回應資料和格式化顯示回應的 JSON 資料。

```python
# TODO: 使用 urequests 送出 GET 請求
import network
import utime
import urequests
import ujson  # MicroPython 的 JSON 處理模組

# 連接到指定的 Wi-Fi 熱點。
def connect_to_wifi(ssid, password, timeout=10):
    sta = network.WLAN(network.STA_IF)
    sta.active(True)

    if not sta.isconnected():
        print("嘗試連接到 Wi-Fi...")
        sta.connect(ssid, password)

        start_time = utime.time()
        while not sta.isconnected():
            if utime.time() - start_time > timeout:
                print("連接超時，請檢查 SSID 和密碼是否正確。")
                return None
            utime.sleep(0.5)
    print("成功連接到 Wi-Fi!")
    return sta.ifconfig()

# 斷開 Wi-Fi 連接
def disconnect_from_wifi():
    sta = network.WLAN(network.STA_IF)
    if sta.isconnected():sta.disconnect()
    print("已斷開 Wi-Fi 連線。")
    return sta.isconnected()


def requests_get():
    r = urequests.get("http://httpbin.org/get?a=100&b=200")
    print(r.status_code)
    if r.status_code == 200:
        print(r.encoding)
        print("--------------------")
        print(r.text)
        # 解析 JSON 響應
        response_data = ujson.loads(r.text)
        print(response_data)
        print(response_data["args"])



if __name__ == "__main__":
    ssid = "ALHC-guest"
    password = "ALHCguest"
    config = connect_to_wifi(ssid, password, timeout=10)
    requests_get()
    utime.sleep(3)
    disconnect_from_wifi()

```

-   使用 urequests 送出 POST 請求

```python
# TODO: 使用 urequests 送出 POST 請求
import network
import utime
import urequests
import ujson  # MicroPython 的 JSON 處理模組

# 連接到指定的 Wi-Fi 熱點。
def connect_to_wifi(ssid, password, timeout=10):
    sta = network.WLAN(network.STA_IF)
    sta.active(True)

    if not sta.isconnected():
        print("嘗試連接到 Wi-Fi...")
        sta.connect(ssid, password)

        start_time = utime.time()
        while not sta.isconnected():
            if utime.time() - start_time > timeout:
                print("連接超時，請檢查 SSID 和密碼是否正確。")
                return None
            utime.sleep(0.5)
    print("成功連接到 Wi-Fi!")
    return sta.ifconfig()

# 斷開 Wi-Fi 連接
def disconnect_from_wifi():
    sta = network.WLAN(network.STA_IF)
    if sta.isconnected():sta.disconnect()
    print("已斷開 Wi-Fi 連線。")
    return sta.isconnected()


def requests_post():
    data = {"a":100, "b":"TA"}
    headers = {"Content-Type": "application/json"}  # 告知伺服器發送的是 JSON
    r = urequests.post("http://httpbin.org/post", data=ujson.dumps(data), headers=headers)
    print(r.status_code)
    if r.status_code == 200:
        print(r.encoding)
        print("--------------------")
        # print(r.text)
        response_data = ujson.loads(r.text) # 解析 JSON 響應
        print(response_data)


if __name__ == "__main__":
    ssid = "ALHC-guest"
    password = "ALHCguest"
    config = connect_to_wifi(ssid, password, timeout=10)
    requests_post()
    utime.sleep(3)
    disconnect_from_wifi()
```

## 8. 使用 google 圖書 API 查詢

-   查詢的 API：https://www.googleapis.com/books/v1/volumes?q=MicroPython&maxResults=1
-   程式碼並沒有實際跑過，因為 ESP8266 在 MicroPython 中默認的 urequests 模組不支援 SSL/TLS。
-   同時，ESP8266 支持 SSL，但內存較小，可能無法處理較大的證書。

```python
# TODO: 使用 urequests 送出 GET 請求
import network
import utime
import urequests
import ujson  # MicroPython 的 JSON 處理模組

# 連接到指定的 Wi-Fi 熱點
def connect_to_wifi(ssid, password, timeout=10):
    sta = network.WLAN(network.STA_IF)
    sta.active(True)

    if not sta.isconnected():
        print("嘗試連接到 Wi-Fi...")
        sta.connect(ssid, password)

        start_time = utime.time()
        while not sta.isconnected():
            if utime.time() - start_time > timeout:
                print("連接超時，請檢查 SSID 和密碼是否正確。")
                return None
            utime.sleep(0.5)
    print("成功連接到 Wi-Fi!")
    return sta.ifconfig()

# 斷開 Wi-Fi 連接
def disconnect_from_wifi():
    sta = network.WLAN(network.STA_IF)
    if sta.isconnected():
        sta.disconnect()
    print("已斷開 Wi-Fi 連線。")
    return sta.isconnected()

# 發送 GET 請求
def requests_get(url):
    try:
        r = urequests.get(url)
        if r.status_code == 200:
            print("下載: ", len(r.text), "字元")
            info = ujson.loads(r.text)

            print("--------------------------")
            if "items" in info:
                for item in info["items"]:
                    book = item["volumeInfo"]
                    print("圖書名: ", book.get("title", "未知"))
                    print("出版商: ", book.get("publisher", "未知"))
                    print("出版日: ", book.get("publishedDate", "未知"))
                    print("--------------------------")
            else:
                print("沒有找到相關圖書資料")
        else:
            print("請求失敗，狀態碼: ", r.status_code)
        r.close()
    except Exception as e:
        print("發生錯誤: ", e)

if __name__ == "__main__":
    ssid = "ALHC-guest"
    password = "ALHCguest"
    config = connect_to_wifi(ssid, password, timeout=10)

    # Google Books API URL
    url = "https://www.googleapis.com/books/v1/volumes?q=MicroPython&maxResults=1"
    requests_get(url)
    utime.sleep(3)
    disconnect_from_wifi()
```

## 9. 文字寫入與讀取

```python
# TODO: 文字寫入
with open("data.txt", "w") as f:
    f.write("菸酒生")
```

```python
# TODO: 文字讀取
with open("data.txt", "r") as f:
    content = f.read()
    print(content)
```

-   基本檔案、資料夾建立

```python
import uos

# 檢查檔案或資料夾是否存在
def exists(name):
    return name in uos.listdir()

# 建立資料夾（如果不存在）
folder_name = "test"
if not exists(folder_name):
    uos.mkdir(folder_name)

# 顯示當前目錄下的所有檔案和資料夾
print("當前目錄內容:", uos.listdir())

# 切換到資料夾（如果存在）
if exists(folder_name):
    uos.chdir(folder_name)


# 返回上層目錄
uos.chdir("..")
print("返回上層目錄，當前目錄內容:", uos.listdir())

# 刪除資料夾（如果存在）
if exists(folder_name):
    uos.rmdir(folder_name)


# 檔案操作：檢查檔案是否存在並刪除
file_name = "data.txt"
if exists(file_name):
    uos.remove(file_name)
```

## 10. Project：程式模組化並連線到 wifi

-   要將連線 widi 帳密輸入至 config.py
-   [module_connect_wifi](./module_connect_wifi/connect_wifi.py)

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```

-   123

```python

```
