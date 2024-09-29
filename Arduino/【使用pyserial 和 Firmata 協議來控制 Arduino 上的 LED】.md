## Firmata
- **Firmata** 是一個通訊協議，用於通過串行連接(例如 USB)來與微控制器板(如 Arduino)進行通訊。它的主要作用是使得微控制器與計算機或其他主機系統之間進行互動，無需在微控制器上撰寫複雜的控制代碼。
- **預載於 Arduino**：Arduino IDE 中包含一個名為 `StandardFirmata` 的示例，這個固件可以被上傳到 Arduino 板上。這樣，你就可以通過電腦端的軟件來控制 Arduino，而不需要每次都寫新的控制代碼。
- **跨平台通訊**：Firmata 是通過串行連接 (例如 USB 或藍牙) 實現的，因此它可以用來與多種主機設備通訊，比如 Raspberry Pi、PC、手機等。

## pyserial 和 Firmata 協議來控制 Arduino 上的 LED
- 安裝 PyFirmata：需要安裝 PyFirmata 來進行 Arduino 和 Python 的通信
```python
pip install pyfirmata
```
- 在 Arduino 上上傳 StandardFirmata
	- 打開 **Arduino IDE**，進入 **文件 > 範例 > Firmata > StandardFirmata**。
	- 選擇你的 Arduino 開發板和串口，然後將 **StandardFirmata** 上傳到 Arduino。

- 在Python 代碼控制 Arduino 板上的 LED
```python
import pyfirmata
import time

# 設置 Arduino 的串口端口 (根據你的情況修改端口)
board = pyfirmata.Arduino('COM8')  # 將 'COM3' 改為你的 Arduino 的串口名稱 (在 Linux 上通常是 '/dev/ttyUSB0')

# 初始化 PyFirmata 的 LED 控制，13 引腳通常是內建 LED
led_pin = board.get_pin('d:13:o')  # 'd' 表示數字引腳, 13 表示引腳號, 'o' 表示輸出模式

# 控制 LED 閃爍
while True:
    led_pin.write(1)  # 設置引腳為高電平（LED 開）
    time.sleep(1)     # 保持 1 秒鐘
    led_pin.write(0)  # 設置引腳為低電平（LED 關）
    time.sleep(1)     # 保持 1 秒鐘
```
### 如果預報報錯
【AttributeError: module 'inspect' has no attribute 'getargspec'. Did you mean: 'getargs'?】
- 是因為 Python 3.11 及以上版本中，`inspect` 模塊已經移除了 `getargspec()` 方法，並且推薦使用 `getfullargspec()` 或 `getargs()` 來代替。PyFirmata 的一些版本可能還依賴於舊的 `getargspec()`，這導致了兼容性問題。
#### 法1：修改 PyFirmata 源碼
- 找到有關 `inspect.getargspec()` 的代碼行，將 `inspect.getargspec(func)` 修改為 `inspect.getfullargspec(func)`
#### 法2：使用 pyfirmata2 庫
```python
pip install pyfirmata2
```

```python
import pyfirmata2
import time

# 設置 Arduino 的串口端口
board = pyfirmata2.Arduino('COM3')

# 控制 LED 閃爍 (引腳 13)
while True:
    board.digital[13].write(1)  # LED 開
    time.sleep(1)
    board.digital[13].write(0)  # LED 關
    time.sleep(1)
```

## 免費下載fritzing
- [[Fritzing]Fritzing軟體免費下載－sky的異想世界｜痞客邦 (pixnet.net)](https://mjjoe1017.pixnet.net/blog/post/217770873)


## 設定腳位的方式
```python
from pyfirmata import Arduino
from pyfirmata import INPUT, OUTPUT, PWM
import time

board = Arduino('COM8') 

# 寫法1：可以對多個引腳進行設置並進行不同的控制。如果你需要頻繁變更引腳模式，這種方式可能更加合適。
board.digital[13].mode = OUTPUT
board.analog[0].mode = INPUT
board.digital[3].mode = PWM

# 寫法2：使用 get_pin() 獲取引腳 -> 是一個更高層次的封裝，讓你能夠更輕鬆地操作引腳。
led_pin = board.get_pin('d:13:o') 
```