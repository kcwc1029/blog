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
