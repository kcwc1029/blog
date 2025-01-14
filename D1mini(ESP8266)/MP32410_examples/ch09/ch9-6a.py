from machine import Pin
import network

ledR = Pin(15, Pin.OUT)
ledG = Pin(12, Pin.OUT)
ledB = Pin(13, Pin.OUT)

def connect_wifi(ssid, passwd):
    sta = network.WLAN(network.STA_IF)
    sta.active(True)
    if not sta.isconnected():
       print("Connecting to network...")
       sta.connect(ssid, passwd)
       while not sta.isconnected():
          pass
    print("network config:", sta.ifconfig())

SSID = "<WiFi名稱>"        # WiFi名稱
PASSWORD = "<WiFi密碼>"    # WiFi密碼
connect_wifi(SSID, PASSWORD)

import urequests, ujson

API_key = "<API金鑰>"
city = "Taipei"
country = "TW"
url  = "https://api.openweathermap.org/data/2.5/weather?"
url += "q=" + city + "," + country   # 城市與國別
url += "&units=metric&lang=zh_tw&"   # 單位
url += "appid=" + API_key

try:
    response = urequests.get(url)
    data = ujson.loads(response.text) 
except:
    data = None

if not data:
    print("沒有查詢到天氣資料")
else:    
    print("--------------------------")
    print("天氣描述: ", data["weather"][0]["description"])
    print("--------------------------")
    temp = data["main"]["temp"]
    print("目前溫度: ", temp)
    print("目前溼度: ", data["main"]["humidity"])
    print("--------------------------")
    if temp <= 18.0:
        print("BLUE")
        ledR.value(0)
        ledG.value(0)
        ledB.value(1)
    elif temp <= 25.0:
        print("GREEN")
        ledR.value(0) 
        ledG.value(1)
        ledB.value(0)
    else:        
        print("RED")
        ledR.value(1)
        ledG.value(0)
        ledB.value(0)
        