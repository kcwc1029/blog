from machine import ADC, Pin
import time
import network
from umqtt.simple import MQTTClient

# 設置Wi-Fi連接資訊
SSID = "ALHC-guest"  # "你的Wi-Fi名稱"
PASSWORD = "ALHCguest" # "你的Wi-Fi密碼"

# 設置MQTT伺服器資訊
MQTT_SERVER = "140.116.179.59"  # "你的MQTT伺服器IP(例如 "192.168.1.100)"  
MQTT_PORT = 1883
MQTT_TOPIC01 = "soil/moisture"
MQTT_TOPIC02 = "soil/moisture_percent"

# 連接到Wi-Fi
def connect_wifi():
    wifi = network.WLAN(network.STA_IF)
    wifi.active(True)
    wifi.connect(SSID, PASSWORD)
    while not wifi.isconnected():
        print("正在連接Wi-Fi...")
        time.sleep(1)
    print("Wi-Fi 連接成功，IP地址:", wifi.ifconfig()[0])

# 設置MQTT客戶端
client = MQTTClient("d1_mini_client", MQTT_SERVER, port=MQTT_PORT)

def connect_mqtt():
    client.connect()
    print("已連接到MQTT伺服器:", MQTT_SERVER)

##################################################
# 感測器本身
##################################################

# 初始化ADC（使用A0針腳，D1 mini上的唯一ADC引腳）
adc = ADC(0)  # 直接使用ADC(0)即可讀取A0引腳


def main():
    connect_wifi() # 連接Wi-Fi
    connect_mqtt() # 連接到MQTT伺服器
    while True:
        moisture_value = adc.read() # 讀取ADC值（範圍0-1023）
        moisture_percent = (moisture_value / 1023) * 100 # 將ADC值轉換為百分比，方便理解
        
        # 發布數據到指定的MQTT主題
        client.publish(MQTT_TOPIC01, str(moisture_value))
        client.publish(MQTT_TOPIC02, str(moisture_percent))
        print("已發送數據到MQTT")
        
        # 將數據格式化為字串
        payload = "土壤濕度: {}, 濕度百分比: {:.2f}%".format(moisture_value, moisture_percent)
        print(payload)
        
        # 每5秒上傳一次數據
        time.sleep(5)

# 啟動主程式
try:
    main()
except KeyboardInterrupt:
    print("程序已中斷")
    client.disconnect()
