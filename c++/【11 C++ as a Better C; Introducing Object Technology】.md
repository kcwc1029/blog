## C++
### C++的起源與命名
- C++由 Bjarne Stroustrup 於 Bell實驗室 開發，最初稱為「C with classes」。
- 名稱中的「C++」取自C語言的遞增運算符「++」，表示C++是C語言的增強版。
### C++的改進與優勢
- 改進C語言功能：增強了許多C語言的特性。
- 物件導向程式設計(OOP)：提供物件導向功能，大幅提高軟體的生產力、品質與可重用性。
- 滿足新需求：C語言作為廣泛使用的編程語言，因需求變化而持續進化，而非被取代。

## A Simple Program: Adding Two Integers
### C++ 和 C 的差異
- **檔案副檔名**：
    - C 使用 **.c** 作為副檔名。
    - C++ 支援多種副檔名，如 **.cpp**、**.cxx**、**.C** 等，常用 **.cpp**。
- **注釋方式**：
    - C++ 新增單行注釋 **//**，僅適用於當行文字。
    - 同時支援多行注釋 **/_..._/**（與 C 相同）。
### 程式結構與核心語法
![upgit_20241127_1732681483.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241127_1732681483.png)

#### 程式入口點：
- 每~個 C++ 程式的執行從 **main()** 函數開始。
- **int~ main()** 表示主函數會回傳整數值；C++ 強制要求所有函數必須指定回傳類型 (如 **void** 表示無回傳值)。
#### 變數宣告位置：
- 變數必須先宣告才能使用。
- 宣告可以位於程式的任意位置，但需在變數第一次使用之前出現。
#### 標頭檔引用：
- 標頭檔使用 `<iostream>` 來處理輸入與輸出。
- **#include** 是必須的，否則無法使用 `std::cout` 和 `std::cin`。
#### 命名空間 (namespace)：
- C++ 使用命名空間 **std** 管理標準庫功能。
- 使用時需在關鍵字前加上 **std::**，如 **std::cout**、**std::cin**、**std::endl**。
- 可以使用 **using namespace std** 簡化寫法 (後續介紹)。
### C++ 的輸入與輸出
- 輸出 (Output)：使用 **std::cout** 與運算符 **<<**，例如：
```cpp
std::cout << "Enter first integer: ";
// 可透過串接方式同時輸出多個內容：
std::cout << "Sum is " << sum << std::endl;
```
- 輸入 (Input)：使用 **std::cin** 與運算符 **>>**，例如：
```cpp
std::cin >> number1;
// 系統會等待使用者輸入數值並按下 Enter，再將值賦予指定變數。
```
- 換行與緩衝：**std::endl** 用於輸出換行並強制清空緩衝區，確保即時顯示內容。
## Header Files
### 標頭檔的功能與重要性
- C++ 標準庫分為多個部分，每部分都有專屬的標頭檔。
- 標頭檔內包含：
	- 函數原型 (Function Prototypes)：定義相關函數的介面。
	- 類別型別與函數的定義。
	- 常數：供函數使用的必要數值。
- 標頭檔負責指導編譯器如何與函數庫和自定義組件互動。
- 標頭檔的命名：
- 現代標頭檔：C++ 標準庫的標頭檔不帶副檔名，如 `<iostream>`。
- 舊式標頭檔：副檔名為 .h，如 `<iostream.h>`，已被現代標準取代。
![upgit_20241127_1732682989.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241127_1732682989.png)

![upgit_20241127_1732683003.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241127_1732683003.png)

![upgit_20241127_1732683017.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241127_1732683017.png)

![upgit_20241127_1732683034.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241127_1732683034.png)

## Inline Functions
- 在函數定義前加上 **inline** 關鍵字，建議編譯器將函數直接展開到呼叫處，減少函數呼叫的執行時間開銷。
- 通常用於小型函數，以避免函數呼叫的額外開銷。
- 注意：編譯器對於大型函數可能忽略 inline 關鍵字。
- 基本上，是否使用 **inline** 關鍵字在現代 C++ 中影響不大，因為編譯器已經非常智能，會自動決定是否將函數展開（這被稱為 編譯器內聯優化）。
### Inline 函數的使用規範
- 完整定義必須出現在函數使用前，否則編譯器無法展開程式碼。
- 重用性：建議將 inline 函數放入標頭檔，方便多個檔案引用。
#### 範例：
- 計算立方體體積的 inline 函數：
```cpp
inline double cube(const double side) {
	return side * side * side;
}
// const 關鍵字：確保參數 `side` 在函數內不被修改。
```
### 命名空間 (Namespace) 簡化
- std:: 前綴簡化：
- 使用 using namespace std 可省略每次使用標準庫時加上 std::。
- 範例：
```cpp
using namespace std;
cout << "Hello, World!" << endl; // 不需要 std:: 前綴
```
## C++ Keywords
![upgit_20241127_1732686334.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241127_1732686334.png)

![upgit_20241127_1732686350.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241127_1732686350.png)

## References and Reference Parameters
### 參數傳遞的兩種方式
#### 值傳遞 (Pass-by-Value)：
- 定義：函數接收到變數值的複製品，**在函數內操作的是複製品，不會影響原變數**。
- 優點：避免原變數被意外修改，提升程式安全性。
- 缺點：當參數是大型物件時，複製操作會**消耗額外的記憶體與執行時間**。
- 範例：
```cpp
void changeValue(int num) {
	num = num * 2; // 只修改了 num 的副本，原變數不受影響
}
```  
#### 引用傳遞 (Pass-by-Reference)：
- 定義：函數接收到變數的 引用 (alias)，可直接訪問並修改原變數的值。
- 優點：提升性能，省去複製的成本，直接操作原變數。
- 缺點：若不小心修改了原變數，可能造成不可預期的副作用。
- 範例：
```cpp
void changeValue(int &num) {
	num = num * 2; // 修改了原變數的值
}
```
### 引用參數的語法與使用
- 在參數類型後加上 **&** 表示參數是引用傳遞。
- 函數原型與定義：
```cpp
void modifyValue(int &num); // 函數原型
void modifyValue(int &num) { // 函數定義
	num = num + 10;
}
```
- 使用引用傳遞：在函數呼叫時直接傳遞變數名稱，無需特別標註：
```cpp
int a = 5;
modifyValue(a); // a 的值會被修改
```
- const 引用：使用 **const** 修飾引用參數，防止函數修改變數的值，保護原變數的安全性。
```cpp
void displayValue(const int &num) {
	std::cout << num; // 僅能讀取，不能修改 num
}
```
### 值傳遞與引用傳遞的比較
- 基本差異：
	- Pass-by-Value：函數內部的操作僅影響副本，安全但耗資源。
	- Pass-by-Reference：直接操作原變數，效能高但需謹慎。
- 語法一致性：在呼叫函數時，兩種傳遞方式的語法相同，差異在於函數定義。
```cpp
// Pass-by-Value
void squareByValue(int num);
// Pass-by-Reference
void squareByReference(int &num);
```
### Reference的其他應用
- 引用作為別名 (Alias)：引用可作為變數的別名，操作引用即操作原變數。    
- 一旦初始化，不能更改為其他變數的別名。
```cpp
int count = 10;
int &cRef = count; // cRef 是 count 的別名
cRef++; // 等效於 count++
std::cout << count; // 輸出 11
```
- 返回引用
	- 函數可以返回一個變數的引用，允許呼叫者直接操作該變數。
	- 不要返回函數內的局部變數的引用，會產生 懸空引用 (dangling reference)。
	- 若返回函數內變數的引用，需將該變數宣告為 static。
```cpp
#include <iostream>

// 返回靜態變數的引用
int& getStaticValue() {
    static int value = 42; // 靜態變數，在函數結束後仍然存在
    return value;
}

int main() {
    int &ref = getStaticValue(); // 獲取靜態變數的引用
    std::cout << "Initial value: " << ref << std::endl;
    ref = 100; // 修改靜態變數的值
    std::cout << "Modified value: " << getStaticValue() << std::endl;

    return 0;
}
```
### 完整範例程式碼
```cpp
#include <iostream>

// 值傳遞
void squareByValue(int num) {
    num = num * num;
}

// 引用傳遞
void squareByReference(int &num) {
    num = num * num;
}

int main() {
    int a = 3, b = 4;

    squareByValue(a);
    std::cout << "Value after squareByValue: " << a << std::endl; // a 未改變

    squareByReference(b);
    std::cout << "Value after squareByReference: " << b << std::endl; // b 被修改

    return 0;
}
```
## Default Arguments
- 函數可以為參數指定**預設值**，在函數呼叫時，如果某些參數未提供實際值，會使用該參數的預設值。
- 適用情境：當函數多次使用相同的參數值時，可以減少重複編寫相同的值。
- 預設參數值通常定義在**函數原型**中，或直接定義在函數標頭內：
```cpp
int boxVolume(int length = 1, int width = 1, int height = 1);
```
- 預設參數必須放在參數列表的最右邊：
```cpp
void example(int a, int b = 5); // 正確
void example(int a = 5, int b); // 錯誤

// 如果呼叫函數時省略某些參數，必須從右到左依序省略：
boxVolume(5); // 視為 length = 5, width = 1, height = 1
```
## Unary Scope Resolution Operator C++ 單一作用域解析運算符 (::) 
- 定義：`::` 是 C++ 提供的一元作用域解析運算符，用於在局部作用域中訪問全域變數，當局部變數與全域變數同名時尤為有用。
- 語法：
```cpp
::global_variable_name
// ::：強制解析為全域變數的作用域。
// `global_variable_name`：全域變數的名稱。
```
- 範例程式碼：區分局部與全域變數
```cpp
#include <iostream>

double number = 3.14159; // 全域變數

int main() {
	int number = 42; // 局部變數，遮蔽全域變數
	std::cout << "Local variable: " << number << std::endl;
	std::cout << "Global variable: " << ::number << std::endl; // 使用 :: 訪問全域變數
	return 0;
}
/*
輸出結果
Local variable: 42
Global variable: 3.14159
*/
```
- 範例程式碼：不同類型的全域與局部變數
```cpp
#include <iostream>

int number = 100; // 全域變數

int main() {
	double number = 5.5; // 局部變數 (不同型別)
	std::cout << "Local variable (double): " << number << std::endl;
	std::cout << "Global variable (int): " << ::number << std::endl; // 訪問全域變數
	return 0;
}
/*
輸出結果
Local variable (double): 5.5
Global variable (int): 100
*/
```

## Function Overloading(函數多載)
### 什麼是函數多載？
- C++ 允許多個名稱相同但參數列表不同的函數存在，稱為**函數多載**。
- 適用於功能相似但處理不同數據類型的情境，例如數學函數（`sqrt`、`abs`）。
### 函數多載的語法
- 多載函數的定義：
```cpp
// 函數名稱相同，但參數列表不同：
int square(int x);        // 處理整數
double square(double x);  // 處理浮點數
```
- 多載函數的呼叫：
```cpp
// 編譯器根據傳入的參數類型自動選擇適合的函數：
std::cout << square(7);    // 呼叫 int 版本
std::cout << square(7.5);  // 呼叫 double 版本
```
### 多載函數的特性與限制
- 函數簽名 (Signature)：
	- 函數名稱 + 參數列表 (類型與順序) ：共同構成函數簽名，用於區分多載函數。
	- 返回值類型不影響函數簽名：
```cpp
int square(int x);    // 正確
double square(int x); // 錯誤，與上方簽名重複
```
- 參數列表中的默認值：避免產生模糊不清的呼叫情境
```cpp
void example(int x, int y = 10);  // 有默認值
void example(int x);             // 可能與上方函數衝突
```
### 多載函數範例
- 範例：計算平方
```cpp
#include <iostream>
// 定義多載函數
int square(int x) {
   return x * x;
}

double square(double x) {
   return x * x;
}

int main() {
   std::cout << "Square of 7: " << square(7) << std::endl;     // 呼叫 int 版本
   std::cout << "Square of 7.5: " << square(7.5) << std::endl; // 呼叫 double 版本
   return 0;
}
/*
輸出結果
Square of 7: 49
Square of 7.5: 56.25
*/
```
- 範例：多載函數參數數量不同
```cpp
#include <iostream>
// 多載函數
void display(int x) {
   std::cout << "Integer: " << x << std::endl;
}

void display(int x, double y) {
   std::cout << "Integer and double: " << x << ", " << y << std::endl;
}

int main() {
   display(5);         // 呼叫單參數版本
   display(5, 3.14);   // 呼叫雙參數版本
   return 0;
}
/*
輸出結果
Integer: 5
Integer and double: 5, 3.14
*/
```

## Introduction to C++ Standard Library Class Template vector 
### 什麼是 vector？
- 定義：`vector` 是 C++ 標準庫中的模板類，用於替代 C 樣式的指標陣列，提供更安全且強大的功能。
- 優勢：
    - 避免陣列越界錯誤（提供邊界檢查）。
    - 支援陣列的比較操作（`==`, `!=` 等）。
    - 支援陣列的賦值操作（`=`）。
    - 提供動態大小調整功能，無需顯式管理記憶體。
### 基本語法與功能
- 宣告與初始化：
```cpp
#include <vector>

// std::vector<資料型別> 名稱(大小, 預設值);
std::vector<int> vec1(7);        // 7 個元素，初始值為 0
std::vector<int> vec2(10, 5);   // 10 個元素，初始值為 5
```
- 訪問元素：
```cpp
// 使用方括號或成員函數 at
vec1[0] = 10;            // 設置第 1 個元素
int value = vec1.at(1);  // 取得第 2 個元素，若越界則丟出例外
```
- 動態大小調整：
	- 增加元素：`push_back(value)`。
	- 移除元素：`pop_back()`。
	- 取得大小：`size()`。
```cpp
vec1.push_back(42);  // 新增元素
vec1.pop_back();     // 移除最後一個元素
std::cout << vec1.size();  // 輸出大小
```
- 比較操作：支援比較運算符：`==`, `!=`。
```cpp
if (vec1 != vec2) {
	std::cout << "Vectors are different.";
}
```
- 邊界檢查與例外處理：
	- 成員函數 `at` 提供邊界檢查，若越界會丟出 `std::out_of_range` 例外。
	- 使用 `try-catch` 處理例外：
```cpp
try {
	int value = vec1.at(15);  // 超出範圍
} catch (std::out_of_range &ex) {
	std::cout << "Error: " << ex.what();
}
```
- 完整範例：基本操作與例外處理
```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

void outputVector(const std::vector<int> &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 宣告與初始化
    std::vector<int> integers1(7);       // 7 個元素，預設值為 0
    std::vector<int> integers2(10, 1);  // 10 個元素，預設值為 1

    // 訪問與修改元素
    integers1[0] = 42;
    integers2.at(2) = 99;

    // 輸出內容
    std::cout << "integers1: ";
    outputVector(integers1);
    std::cout << "integers2: ";
    outputVector(integers2);

    // 比較操作
    if (integers1 != integers2) {
        std::cout << "Vectors are different." << std::endl;
    }

    // 使用 at 函數進行邊界檢查
    try {
        std::cout << integers1.at(15);  // 超出範圍
    } catch (std::out_of_range &ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}
/*
輸出結果：
integers1: 42 0 0 0 0 0 0 
integers2: 1 1 99 1 1 1 1 1 1 1 
Vectors are different.
Exception: vector::_M_range_check: __n (which is 15) >= this->size() (which is 7)
*/
```