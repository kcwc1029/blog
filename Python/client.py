# import socket

# # 創建客戶端 Socket
# client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client_socket.connect(("140.116.179.53", 8965))  # 連接到伺服器

# # 要傳輸的字串
# message = "這是一個測試訊息"

# # 將字串編碼為位元組並發送
# client_socket.sendall(message.encode('utf-8'))

# # 接收伺服器的回應
# response = client_socket.recv(1024).decode('utf-8')
# print(f"來自伺服器的回應：{response}")

# client_socket.close()

import socket
import base64

# 要發送的數據
message = "這是一段測試數據"

# 編碼成 Base64
encoded_message = base64.b64encode(message.encode()).decode()
print(f"編碼後的 Base64 數據: {encoded_message}")

# 創建客戶端 Socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('140.116.179.53', 8965))
# client_socket.connect(("140.116.179.53", 8965))  # 連接到伺服器

# 傳送數據
client_socket.send(encoded_message.encode())
print("數據已發送！")

# 關閉連接
client_socket.close()
