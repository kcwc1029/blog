#include <SevSeg.h>

SevSeg sevseg; // 建立 SevSeg 物件

void setup() {
  byte numDigits = 4;  // 設定為 4 位顯示器
  byte digitPins[] = {2, 3, 4, 5};  // 位選擇腳
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};  // 連接到顯示器的段選擇腳
  bool resistorsOnSegments = true;  // 設定為 true，表示電阻連接在段上

  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);  // 設定顯示亮度
  Serial.begin(9600);  // 初始化序列通信
}

void loop() {
  if (Serial.available() > 0) {
    // String data = Serial.readString();  // 從 Python 接收字串
    String data = "45";
    int number = data.toInt();  // 將接收到的字串轉換為整數

    // 顯示有效數字，範圍：0 到 9999
    if (number >= 0 && number <= 9999) {
      sevseg.setNumber(45, 0);  // 顯示數字，最後的 0 表示不顯示小數點
      delay(5000);
    } else {
      sevseg.blank();  // 若輸入超出範圍則清除顯示
    }

    sevseg.refreshDisplay();  // 刷新顯示器以更新顯示內容
  }
}
