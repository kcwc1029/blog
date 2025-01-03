## 很好的網頁開發 arduino

-   https://wokwi.com/
-   https://www.tinkercad.com/dashboard

## 具備特殊工程的開具備特殊功能的開發版

![upgit_20241223_1734940314.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241223_1734940314.png)

![upgit_20241223_1734940344.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241223_1734940344.png)

## 更高等的開發版

![upgit_20241223_1734940401.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241223_1734940401.png)

## 第一個程式碼 閃爍 LED

![upgit_20241225_1735102719.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735102719.png)

```cpp
#define LED_PIN 11

void setup(){
    pinMode(LED_PIN, OUTPUT);
}

void loop(){
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
}
```

## 彈跳開關控制 LED

### 接法

![upgit_20241225_1735103699.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735103699.png)

### Project：按下才開

![upgit_20241225_1735104166.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735104166.png)

```cpp
#define LED_PIN 11
#define BUTTON_PIN 2
void setup(){
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop(){
    // 讀取開關狀態
    boolean LED_status = digitalRead(BUTTON_PIN);
    digitalWrite(LED_PIN, LED_status);
}
```

### Project：開關切控

![upgit_20241225_1735104166.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735104166.png)

```cpp
#define LED_PIN 11
#define BUTTON_PIN 2

boolean LED_status;
boolean BUTTON_status;
void setup(){
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    // 一開始先設定燈泡關燈
    digitalWrite(LED_PIN, false);
}

int count=0; // 計算跳開關次數
void loop(){
    // 讀取開關狀態
    BUTTON_status = digitalRead(BUTTON_PIN);
    if(BUTTON_status==true){
        Serial.print("press buttin");
        Serial.print(count);
        Serial.print("\n");
        count++;
        LED_status = !LED_status;
        digitalWrite(LED_PIN, LED_status);
    }
}
```

-   這邊可以觀察到，其實 button 他開開關關了很多次

![upgit_20241225_1735105176.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735105176.png)

## 處裡開關彈跳問題

### 使用 bounce 庫

-   [WOKWI](https://wokwi.com/projects/418222744014292993)

![upgit_20241225_1735107382.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735107382.png)

![upgit_20241225_1735107333.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735107333.png)

```cpp
#include <Bounce2.h>
Bounce2::Button button = Bounce2::Button(); // 初始化Button OBJECT
#define LED_PIN 7
#define BUTTON_PIN 2

boolean LED_status;
void setup() {
  Serial.begin(115200);
  // 初始化開關
  button.attach(BUTTON_PIN, INPUT);
  button.interval(5);
  button.setPressedState(LOW);

  // 初始化LED
  pinMode(LED_PIN, OUTPUT);
  LED_status = HIGH;
  digitalWrite(LED_PIN, LED_status);
}

void loop() {
  button.update();
  if(button.pressed()){
    LED_status = !LED_status;
    digitalWrite(LED_PIN,LED_status);
  }
}

```

## 結合 enum 有限狀態機

-   狀態機
    -   燈暗後，按按鈕是無效的，只有在【不碰開關 5 秒】才會亮燈
    -   亮燈後，要【按按鈕長達 5 秒】才會暗燈

![upgit_20241225_1735109393.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735109393.png)

```cpp
#include <Bounce2.h>

// 初始化 Bounce2 按鈕物件
Bounce2::Button button = Bounce2::Button();

// 定義LED和按鈕的引腳
#define LED_PIN 7       // LED連接在腳位7
#define BUTTON_PIN 2    // 按鈕連接在腳位2

// 定義狀態機的狀態
typedef enum {
  S_OFF,           // LED關閉狀態
  S_OFF_NO_PRESS,  // LED關閉且按鈕未按的狀態
  S_ON,            // LED開啟狀態
  S_ON_PRESS       // LED開啟且按鈕被按住的狀態
} State;

State state = S_OFF; // 初始化狀態為 S_OFF (LED關閉)

// 更新LED狀態
void updateLED() {
  // 根據狀態機的當前狀態開啟或關閉LED
  if (state == S_OFF || state == S_OFF_NO_PRESS) {
    digitalWrite(LED_PIN, LOW);  // 關閉LED
  } else if (state == S_ON || state == S_ON_PRESS) {
    digitalWrite(LED_PIN, HIGH); // 開啟LED
  } else {
    Serial.println("ERROR state"); // 如果進入未知狀態，輸出錯誤
  }
}

void setup() {
  // 初始化序列監視器
  Serial.begin(115200);

  // 設置LED為輸出模式
  pinMode(LED_PIN, OUTPUT);

  // 初始化按鈕
  button.attach(BUTTON_PIN, INPUT);        // 將按鈕引腳設置為輸入模式
  button.interval(5);                      // 設定去彈性時間為5毫秒
  button.setPressedState(LOW);             // 定義按下按鈕時為低電平 (LOW)
}

unsigned long time_prev; // 用於記錄時間的變數

void loop() {
  // 更新按鈕的狀態
  button.update();

  // 獲取按鈕的當前狀態，按下為 true，未按下為 false
  boolean switch_state = button.pressed();

  // 調試輸出：顯示按鈕和當前狀態
  Serial.print("按鈕狀態: ");
  Serial.println(switch_state);  // 輸出按鈕是否按下
  Serial.print("當前狀態: ");
  Serial.println(state);         // 輸出狀態機的當前狀態

  // 狀態機邏輯
  switch (state) {
    case S_OFF: // 當LED為關閉狀態
      if (!switch_state) {  // 如果按鈕未被按下
        time_prev = millis();   // 記錄當前時間
        state = S_OFF_NO_PRESS; // 進入 S_OFF_NO_PRESS 狀態
      }
      break;

    case S_OFF_NO_PRESS: // LED關閉且按鈕未按的狀態
      if (!switch_state) {  // 確保按鈕未按下
        unsigned long time_curr = millis(); // 獲取當前時間
        if (time_curr - time_prev >= 5000) { // 若按鈕未按下超過5秒
          state = S_ON; // 切換到 S_ON 狀態
        }
      }
      break;

    case S_ON: // 當LED為開啟狀態
      if (switch_state) {  // 如果按下按鈕
        time_prev = millis();  // 記錄按下的開始時間
        state = S_ON_PRESS;    // 進入 S_ON_PRESS 狀態
      }
      break;

    case S_ON_PRESS: // LED開啟且按鈕被按住的狀態
      if (switch_state) {  // 如果按鈕仍然按住
        unsigned long time_curr = millis(); // 獲取當前時間
        if (time_curr - time_prev >= 5000) { // 如果按鈕按住超過5秒
          state = S_OFF; // 切換到 S_OFF 狀態
        }
      }
      break;
  }

  // 更新LED狀態
  updateLED();

  // 加入延遲以避免過於頻繁的輸出
  delay(100);
}
```

## 呼吸燈(PWM)

-   Potentiometer：常用於調節電壓，例如音量控制旋鈕。
-   雖然數位腳位只能輸出 0V 或 5V 兩種準位而已，但 Arduino 可以根據設定的工作週期(duty cycle),不斷地切換電壓準位。

![upgit_20241225_1735110032.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735110032.png)

-   接法：

    -   左端：5v
    -   中間：A0
    -   右端：GND

-   使用 analogWrite+for 迴圈控制 LED 亮度

```cpp
#define LED_PIN 11

void loop() {
  for(int i=0;i<255;i++){
    analogWrite(LED_PIN, i);
    delay(10);
  }
  for(int i=255;i>0;i--){
    analogWrite(LED_PIN, i);
    delay(10);
  }
}
```

-   Potentiometer：控制 LED(不太明顯，可以搭配 Serial.print)

![upgit_20241225_1735111379.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735111379.png)

```cpp
#define LED_PIN 11
#define POT_PIN A0

int brightness = 0; // 亮度

void setup() {
  Serial.begin(112500);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int v = analogRead(POT_PIN);
  Serial.print(v);
  Serial.print("\n");
  brightness = map(v, 0, 1023, 0, 255);
  analogWrite(LED_PIN, brightness);
  delay(50);
}
```

## 光敏電阻器(photoresistor)

-   當照射光強度不同時,它的電阻也會隨之改變;當有光線照射時,就會激發裡頭原本穩定的電子,所以光越強產生越多的自由電子,電阻就越小;光線越暗則電阻越大。
-   值介於 0(0V)-1023(5V)之間
-   若要轉換為實際電壓

![upgit_20241225_1735111909.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735111909.png)

```cpp
float voltage = r * (5.0 / 1023.0); // 5.0 是默認的參考電壓
Serial.print("Voltage: ");
Serial.println(voltage);
```

-   透過光敏電阻讀取

```cpp
#define PR_PIN A0

void setup(){
    Serial.begin(115200);
}


void loop(){
    int r = analogRead(PR_PIN);
    Serial.print(r);
    Serial.print("\n");
}
```

## 矩陣鍵盤(keypaf)

-   每一種鍵盤接法都會不同
-   https://docs.wokwi.com/parts/wokwi-membrane-keypad

![upgit_20241225_1735112943.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241225_1735112943.png)

```cpp
#include <Keypad.h>

const int ROWS = 4;
const int COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

int colPins[COLS] = { 5, 4, 3, 2 }; // Pins connected to C1, C2, C3, C4
int rowPins[ROWS] = { 9, 8, 7, 6 }; // Pins connected to R1, R2, R3, R4

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    Serial.println(key);
  }
}
```

## RGB LED

-   https://wokwi.com/projects/306455554559050306
