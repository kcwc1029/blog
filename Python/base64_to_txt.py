import socket
import base64

# 創建 Server Socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(("140.116.179.51", 8965))  # 綁定地址和端口
server_socket.listen(5)  # 最大等待連接數

print("等待客戶端連接...")
conn, addr = server_socket.accept()  # 接受連接
print(f"客戶端已連接：{addr}")

# 接收和保存數據
try:
    while True:
        data = conn.recv(500000).decode()  # 接收數據
        # print(data)
        if not data:
            print("客戶端已關閉連接。")
            break  # 如果接收到空數據，跳出迴圈
        # data = data[2:]

        # 回應客戶端
        conn.send(f"伺服器已接收數據：{data}".encode())
        
        
        with open("received_data.txt", 'w') as image_file:
            image_file.write(data)
            print("received_data.txt以寫入")


        # 解碼 Base64 字串為二進位數據
        # image_data = base64.b64decode(data)

        # 將二進位數據寫入圖片文件
        # with open("outputg_image.png", 'wb') as image_file:
        #     image_file.write(image_data)
        #     print("圖片已成功保存為 output_image.png")

        
        
except Exception as e:
    print(f"發生錯誤：{e}")
finally:
    conn.close()
    server_socket.close()
    print("伺服器已關閉。")
