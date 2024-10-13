import serial
import time

# 設定串口參數（請確認你的 Arduino 連接的 COM 埠）
COM_PORT = 'COM8'  # 替換為你的 Arduino 所連接的端口
BAUD_RATE = 9600

# 建立 Serial 連接
ser = serial.Serial(COM_PORT, BAUD_RATE)
time.sleep(2)  # 等待 Arduino 重置

def send_number(number):
    """向 Arduino 發送數字"""
    if 0 <= number <= 9999:
        ser.write(f"{number}\n".encode())  # 將數字轉換為字串並發送
        print(f"Sent number: {number}")
    else:
        print("請輸入 0 到 9999 之間的數字")

try:
    while True:
        num = input("請輸入要顯示的數字（0-9999，輸入 'exit' 退出）：")
        if num.lower() == 'exit':
            break
        if num.isdigit():
            send_number(int(num))
        else:
            print("請輸入有效的數字")
finally:
    ser.close()  # 關閉串口
    print("程式結束，串口已關閉。")
