# D1mini透過Micropython控制buzzer
from machine import Pin, PWM 
from time import sleep

# 設定蜂鳴器的引腳，假設在 GPIO 5
buzzer = PWM(Pin(5))

# 定義音階的頻率 (Hz)
tones = {
    "C": 261,
    "D": 294,
    "E": 329,
    "F": 349,
    "G": 392,
    "A": 440,
    "B": 493,
    "C5": 523
}

# 播放音階
for note, freq in tones.items():
    print(f"Playing {note}")
    buzzer.freq(freq)
    buzzer.duty_u16(32768)  # 開啟蜂鳴器
    sleep(0.5)              # 播放 0.5 秒
    buzzer.duty_u16(0)      # 關閉蜂鳴器
    sleep(0.1)              # 休息 0.1 秒

buzzer.deinit()  # 釋放 PWM 資源
