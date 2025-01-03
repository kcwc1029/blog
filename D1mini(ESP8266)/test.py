import network
import usocket as socket
import ussl

# 連接 Wi-Fi
def connect_to_wifi(ssid, password):
    sta = network.WLAN(network.STA_IF)
    sta.active(True)
    if not sta.isconnected():
        print("嘗試連接到 Wi-Fi...")
        sta.connect(ssid, password)
        while not sta.isconnected():
            pass
    print("成功連接到 Wi-Fi!")
    print("IP 地址:", sta.ifconfig())

# 發送電子郵件
def send_email(sender_email, app_password, recipient_email, subject, body):
    smtp_server = "smtp.gmail.com"
    smtp_port = 465

    # 建立 TCP 連線
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((smtp_server, smtp_port))

    # 使用 SSL 包裝 Socket
    ssl_sock = ussl.wrap_socket(sock)

    # 發送 SMTP 指令
    def send_command(command):
        ssl_sock.write(command + "\r\n")
        response = ssl_sock.read(1024).decode("utf-8")
        print(response)
        return response

    # 開始 SMTP 會話
    send_command("EHLO esp8266")

    # 登入
    send_command("AUTH LOGIN")
    send_command(sender_email.encode("utf-8").hex())  # 編碼並轉換為 Base64
    send_command(app_password.encode("utf-8").hex())  # 編碼並轉換為 Base64

    # 發送郵件
    send_command(f"MAIL FROM:<{sender_email}>")
    send_command(f"RCPT TO:<{recipient_email}>")
    send_command("DATA")
    send_command(f"Subject: {subject}\r\n\r\n{body}\r\n.")

    # 結束會話
    send_command("QUIT")

    # 關閉連線
    ssl_sock.close()
    sock.close()
    print("郵件已發送！")

# 主程式
if __name__ == "__main__":
    # Wi-Fi 設定
    ssid = "ALHC-guest"
    password = "ALHCguest"

    # 電子郵件設定
    sender_email = "3331363@gmail.com"
    app_password = "ezoeymvwzuuwondr"  # Gmail 的應用程式密碼
    recipient_email = "3331363@gmail.com"
    subject = "測試郵件"
    body = "這是一封來自 D1 Mini 的測試郵件。"

    # 連接 Wi-Fi 並發送郵件
    connect_to_wifi(ssid, password)
    send_email(sender_email, app_password, recipient_email, subject, body)
