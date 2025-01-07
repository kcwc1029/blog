## ESP32 接腳圖

![upgit_20250107_1736232321.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250107_1736232321.png)

## Project：使用 ESP32 LODIN D32 發送郵件

![upgit_20241231_1735625527.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241231_1735625527.png)

![upgit_20241231_1735626224.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241231_1735626224.png)

-   [mail_ESP32_LODIND32](./mail_ESP32_LODIND32/main.py)

## 物聯網雲端平台--ThinkSpeak

-   [main.py](./ESP32%20to%20thinkspeak/main.py)

![upgit_20250103_1735887073.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250103_1735887073.png)
![upgit_20250103_1735886923.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250103_1735886923.png)

## 物聯網雲端平台--adafruit.io

-   https://io.adafruit.com/k3331363/dashboards/esp32-ce-shi-adafruit

![upgit_20250103_1735889416.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250103_1735889416.png)

## MQTT

## 8. MQTT

-   MQTT(Message Queuing Telemetry Transport)是 OASIS 標準的一種訊息通訊協定(Message Protocol),這是架構在 TCP/IP 通訊協定
-   針對機器對機器(Machine-to-machine,M2M)的輕量級通訊協定。

![upgit_20250103_1735889491.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250103_1735889491.png)

### 8.1. MQTT 訊息

-   MQTT 訊息包含標頭(2 個字元)、訊息主題(Topic)和訊息內容(Payload)。
-   標頭可以指定：
    -   保留(Retained)訊息：當重新連接後，會保留上一次的最後訊息
    -   服務品質(Quality of Service,QoS)：
        -   0：最多傳送一次(at most once)：平信
        -   1：至少傳送一次(at least once)：掛號
        -   2：確實傳送一次(exactly once)：附回信

### 8.2. MQTT 主題

-   `主題等級/主題等級/主題`
-   MQTT 主題支持使用萬用字元來同時訂閱多個主題。

#### 8.2.1. 單層萬用字元 (Single Level Wildcard)

-   符號：`+`
-   功能：用來替代單層的主題等級。
-   範例：`home/sensor/+/temp`可以同時訂閱以下主題：
    -   `home/sensor/livingroom/temp`
    -   `home/sensor/kitchen/temp`
    -   `home/sensor/restroom/temp`

#### 8.2.2. 多層萬用字元 (Multi-level Wildcard)

-   符號：`#`
-   功能：用來替代多層的主題等級。
-   範例：`home/sensor/#`可以同時訂閱以下主題：
    -   `home/sensor/livingroom/temp`
    -   `home/sensor/kitchen/temp`
    -   `home/sensor/kitchen/brightness`
    -   `home/sensor/firstfloor/livingroom/temp`

### 8.3. MQTT 代理人 (MQTT Broker)

-   接收訊息：負責接收所有發布者的訊息。
-   過濾訊息：決定哪些訂閱者應接收哪些訊息。
-   傳送訊息：將消息發送至所有訂閱該主題的訂閱者。

#### 8.3.1. 公開 MQTT 代理人

-   HiveMQ MQTT
    -   主機名稱：broker.hivemq.com
    -   TCP 埠號：1883
    -   Websocket 埠號：8000
-   Eclipse IoT
    -   主機名稱：mqtt.eclipseprojects.io
    -   TCP 埠號：1883
    -   Websocket 埠號：8883
-   test.mosquitto.org
    -   主機名稱：test.mosquitto.org
    -   TCP 埠號：1883
    -   Websocket 埠號：8080
-   EMQX
    -   主機名稱：broker.emqx.io
    -   TCP 埠號：1883
    -   Websocket 埠號：8083

### 8.4. MQTT 客戶端

-   發送主題：test/topic

#### 8.4.1. 使用 powershell 發送

-   要先安裝[Download | Eclipse Mosquitto](https://mosquitto.org/download/)
-   將安裝位置加入路徑
-   發送消息：mosquitto_pub -h broker.hivemq.com -p 1883 -t "test/topic" -m "Hello MQTT"
-   監聽消息：mosquitto_sub -h broker.hivemq.com -p 1883 -t "test/topic"

#### 8.4.2. 使用 MQTT explorer 發送

-   選擇上述其中一個公開 MQTT 代理人，填入 TCP 跟 port
-   要到 advance 增加要監聽的主題

![upgit_20250103_1735891910.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250103_1735891910.png)

![upgit_20250103_1735891962.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250103_1735891962.png)

## python\*AI 生醫大感測

### 膚電反應

-   生理基礎：當人類說謊或感到緊張時，交感神經系統會被激活，引發血管收縮與汗腺分泌增加。
-   電阻變化：汗液中富含電解質，具有良好的導電性，導致皮膚電阻降低。
-   GSR 技術：基於皮膚電阻變化，GSR (Galvanic Skin Response) 技術可用於測量情緒與壓力。
    -   當皮膚電阻越來越小，就代表說謊可能性提高
-   數據讀取：
    -   ESP32 的 ADC (Analog-to-Digital Converter) 轉換模擬信號為數位數據，便於進一步處理與分析。

### 土壤濕度感測器的應用

-   感測器通過測量電壓變化來反映濕度狀況，類似於測量皮膚電阻的原理。
-   ESP32 開發板可將模擬電壓信號轉換為數位信號，便於後續數據分析與處理。
-   接線方式：壤濕度感測器的連接
    -   VCC → 3V
    -   GND → GND
    -   A0(信號腳) → GPIO36

### ESP32 的 ADC 設定：

-   土壤溫溼度的類比輸出腳位，連接到 ESP32 類比輸入角為，在使用 ADC 類別，變能測量電壓，得知電阻變化
-   atten (衰減量)：用於調整輸入電壓範圍。
    -   ADC.ATTN_0DB：100mV ~ 950mV
    -   ADC.ATTN_2_5DB：100mV ~ 1250mV
    -   ADC.ATTN_6DB：150mV ~ 1750mV
    -   ADC.ATTN_11DB：150mV ~ 2450mV
-   width (位元數)：用於調整 ADC 的取樣位元，位元數越高，解析度越高，數據越精細。
    -   ADC.WIDTH_9BIT： 9 位元 (0 ~ 511)
    -   ADC.WIDTH_10BIT：10 位元 (0 ~ 1023)
    -   ADC.WIDTH_11BIT：11 位元 (0 ~ 2047)
    -   ADC.WIDTH_12BIT：12 位元 (0 ~ 4095)

```py
import time
from machine import Pin, ADC

ADC_PIN=Pin(39)
adc = ADC(ADC_PIN)
adc.width(ADC.WIDTH_9BIT)
adc.atten(ADC.ATTN_11DB)

while True:
    gsr = adc.read()
    print(gsr)
    time.sleep(1)
```

![image](https://cdn.discordapp.com/attachments/1286741860538122281/1326128953165086801/IMG_8836.jpg?ex=677e4d54&is=677cfbd4&hm=688b23bcca18d9e4ad3fe534da15bc1d66b26f389223bb61ff9de7ee824a2bb4&)
