from socket import socket, SOCK_STREAM, AF_INET

client = socket(family=AF_INET, type=SOCK_STREAM)
# 2. 連接到伺服器(需要指定IP位址和port)
client.connect(('192.168.137.125', 5500)) # NOTE: 我要連線的server IP(就是寫pi的)
print('連線成功')
# 3. 從伺服器接收資料
print(client.recv(1024).decode('utf-8'))
client.close()