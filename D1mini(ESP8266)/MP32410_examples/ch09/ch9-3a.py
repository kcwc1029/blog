import network
import utime
import urequests

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
    r = urequests.get("https://fchart.github.io/fchart.html")
    if r.status_code == 200:
        print(r.encoding)
        print(r.text)


if __name__ == "__main__":
    ssid = "ALHC-guest"
    password = "ALHCguest"
    config = connect_to_wifi(ssid, password, timeout=10)
    requests_get()
    utime.sleep(3)
    disconnect_from_wifi(0)


    