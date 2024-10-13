from machine import I2C, Pin
import time

# 初始化I2C，SDA接到D2, SCL接到D1
i2c = I2C(scl=Pin(5), sda=Pin(4))

# 掃描I2C設備
devices = i2c.scan()
if devices:
    print("找到的I2C設備地址: ", [hex(device) for device in devices])
else:
    print("未找到任何I2C設備")
    
    
    
