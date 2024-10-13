import network
import time

# 設定 Wi-Fi 名稱 (SSID) 和密碼
SSID = "ALHC-guest" # "你的WiFi名稱"
PASSWORD = "ALHCguest"# "你的WiFi密碼"

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
