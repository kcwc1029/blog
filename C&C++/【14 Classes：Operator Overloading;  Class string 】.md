##  Fundamentals of Operator Overloading
### 運算符重載的基礎（Fundamentals of Operator Overloading）
- 運算符重載（Operator Overloading）允許重新定義 C++ 中的運算符，使其能對用戶自定義的類型（如類別或列舉類型）進行操作。
- 運算符重載的意義：
    - 為用戶定義類型（如 `string` 或其他類別）提供直觀且簡潔的操作方式，與內建類型的操作一致。
    - 無法創建新的運算符，只能重載現有運算符。
- 平常的 + 是拿來做數字相加的：3 + 5 = 8。
- 用運算符重載後，`+` 也可以用來相加我們自己定義的類別，例如 `時間物件` 或 `字串物件`。
	- 例子：`時間物件1 + 時間物件2` 會返回一個「相加後的新時間」。
### 為什麼需要運算符重載？
- 因為物件之間的操作不像基本數據類型（例如整數、浮點數）那麼簡單，重載運算符可以讓程式碼更直觀、更易讀。
```c
// 沒重載前
時間 t3 = t1.add(t2);  // 必須使用函數呼叫

// 重載後
時間 t3 = t1 + t2;  // 更直觀，像數字操作一樣
```
### 重載運算符的方式
- 運算符重載並非自動進行，必須通過編寫 運算符重載函數 實現。
```c
class 類別名 {
public:
    // 函數名用 operator+ 表示我們在重載加法運算符
    類別名 operator+(const 類別名& 另一個物件) const {
        // 定義加法邏輯
        類別名 結果;
        結果.數據 = this->數據 + 另一個物件.數據;
        return 結果;
    }
};

// 範例
class MyClass {
public:
	MyClass operator+(const MyClass& rhs); // 重載加法運算符
};
```
### 範例程式
- 加法運算符重載
```cpp
class MyClass {
    int value;

public:
    MyClass(int v) : value(v) {}

    // 重載加法運算符
    MyClass operator+(const MyClass &rhs) const {
        return MyClass(this->value + rhs.value);
    }

    void print() const { cout << value << endl; }
};

int main() {
    MyClass a(10), b(20);
    MyClass c = a + b;  // 使用重載的加法運算符
    c.print();          // 輸出：30
}
```
## Overloading Binary Operators
- 二元運算符可以通過以下兩種方式進行重載
	- 成員函數（Non-static member function）
	- 非成員函數（Non-member function）
### 成員函數
- 成員函數方式的重載函數僅需要一個參數，因為另一個參數是隱式的（`this` 指針表示該類物件）。
```c
// 語法格式
class 類名 {
public:
    類名 operator+(const 類名& 右操作數) const {
        // 自定義加法邏輯
        return 類名(this->數據 + 右操作數.數據);
    }
};
```
- 範例：重載加法運算符（`+`）
```c
class MyNumber {
private:
    int value;
public:
    MyNumber(int v) : value(v) {}

    // 成員函數重載 +
    MyNumber operator+(const MyNumber& rhs) const {
        return MyNumber(this->value + rhs.value);
    }
    void print() const { cout << value << endl; }
};

int main() {
    MyNumber num1(10), num2(20);
    MyNumber result = num1 + num2;  // 使用重載的加法運算符
    result.print();                // 輸出：30
}
```
### 非成員函數
- 非成員函數需要兩個參數，分別表示左操作數和右操作數。
- 至少有一個參數必須是類型物件（或類型物件的引用），以便支持運算符重載。
```c
// 語法格式
類名 operator+(const 類名& 左操作數, const 類名& 右操作數) {
    // 自定義加法邏輯
    return 類名(左操作數.數據 + 右操作數.數據);
}
```
- 範例：重載比較運算符（<）
```c
class MyNumber {
private:
    int value;
public:
    MyNumber(int v) : value(v) {}

    // 提供 getter，用於非成員函數訪問數據
    int getValue() const { return value; }
};

// 非成員函數重載 <
bool operator<(const MyNumber& lhs, const MyNumber& rhs) {
    return lhs.getValue() < rhs.getValue();
}

int main() {
    MyNumber num1(10), num2(20);
    cout << (num1 < num2 ? "True" : "False") << endl;  // 輸出：True
}
```
## Overloading the Binary Stream Insertion and Stream Extraction Operators
- C++ 支援透過重載 輸出運算符（<<） 和 輸入運算符（>>） 來對用戶自定義類別進行格式化的輸出和輸入操作，例如處理類似 (800) 555-1212 格式的電話號碼。
- 輸出運算符 <<：
	- 將自定義類別物件的內容以格式化方式輸出到控制台（`std::cout`）或其他輸出流。
	- 例如：`cout << phone;` 將物件 `phone` 的內容以指定格式顯示。
- 輸入運算符 >>：
	- 從輸入流（`std::cin`）讀取數據，並存儲到自定義類別物件中。
	- 例如：`cin >> phone;` 從鍵盤輸入數據並存儲到 `phone`。
### 重載輸出運算符（<<）
- 實現步驟：
	- 定義一個非成員函數，函數名稱為 operator<<。
	- 將 std::ostream 引用作為函數的第一個參數。
	- 返回 std::ostream 引用以支持串接操作（如 cout << obj1 << obj2）。
```c
#include <iostream>
#include <string>
using namespace std;

// 定義 PhoneNumber 類別
class PhoneNumber {
    // 友元函式宣告，允許非成員函式 operator<< 存取 private 成員
    friend ostream &operator<<(ostream &output, const PhoneNumber &number);

private:
    string areaCode;  // 區號，例如：台灣是 "02" 或其他國家的格式
    string exchange;  // 中間三位數，例如：固定電話的分區號
    string line;      // 後四位數，例如：用戶的唯一標識碼

public:
    // 建構函式，提供預設值 "000"、"000" 和 "0000" 以避免未初始化
    PhoneNumber(string area = "000", string exchange = "000", string line = "0000")
        : areaCode(area), exchange(exchange), line(line) {} // 成員初始化列表
};

// 重載輸出運算符 <<，格式化 PhoneNumber 的輸出樣式
ostream &operator<<(ostream &output, const PhoneNumber &number) {
    // 格式化輸出為 (區號) 中間三位數-後四位數
    output << "(" << number.areaCode << ") " << number.exchange << "-" << number.line;
    return output; // 回傳 ostream 以支援連續的輸出操作
}


// 應用
PhoneNumber phone("800", "555", "1212");
cout << phone << endl;  // 輸出格式： (800) 555-1212
```
- 為什麼需要friend：
	- 輸出運算符（<<）和輸入運算符（>>）的左操作數是 ostream 或 istream，這些類型無法成為用戶類別的成員函數。
	- 為了訪問類別的私有數據（如電話號碼的區號等），需要將這些非成員函數定義為友元函數。
### 重載輸入運算符（>>）
- 實現步驟：
	- 定義一個非成員函數，函數名稱為 operator>>。
	- 將 std::istream 引用作為函數的第一個參數。
	- 使用 std::istream::ignore() 跳過不需要的符號（如括號和連字號）。
	- 返回 std::istream 引用以支持串接操作（如 cin >> obj1 >> obj2）。
```c
// 重載輸入運算符
istream &operator>>(istream &input, PhoneNumber &number) {
    input.ignore();  // 跳過 (
    input >> setw(3) >> number.areaCode;  // 讀取區號
    input.ignore(2);  // 跳過 ) 和空格
    input >> setw(3) >> number.exchange;  // 讀取中間三位數
    input.ignore();  // 跳過 -
    input >> setw(4) >> number.line;  // 讀取最後四位數
    return input;
}

// 應用：
PhoneNumber phone;
cout << "Enter phone number in the form (800) 555-1212: ";
cin >> phone;  // 輸入格式：(800) 555-1212
cout << "You entered: " << phone << endl;
```
## Overloading the Unary Prefix and Postfix ++ and --  Operators
- 單目運算符（Unary Operators）：只需要一個操作數，例如 ++ 和 --。
- 重載目的：允許我們在自定義類別中使用前置和後置的遞增（++）和遞減（--）操作。
### 前置（Prefix）與後置（Postfix）的區別
![upgit_20241201_1733040123.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241201_1733040123.png)

#### 前置運算符（++obj 或 --obj）
- `類型 &operator++();  // 前置 ++`
```c
// 程式碼實現（成員函數）
class Date {
public:
    // 重載前置 ++
    Date &operator++() {
        ++day;  // 遞增邏輯，例如增加一天
        return *this;  // 返回遞增後的自身
    }
};
```
#### 後置運算符（obj++ 或 obj--）
- `類型 operator++(int);  // 後置 ++  注意：int 是一個「虛擬參數」，用來區分前置與後置版本。`
- 重載邏輯：
	- 先保存當前值（通過臨時物件）。
	- 遞增物件本身的值。
	- 返回保存的臨時物件（即遞增前的原值）。
```c
// 程式碼實現（成員函數）
class Date {
public:
    // 重載後置 ++
    Date operator++(int) {
        Date temp = *this;  // 保存當前值
        ++day;              // 遞增
        return temp;        // 返回原值
    }
};
```
#### 非成員函數的重載
- 如果需要使用非成員函數，則必須將物件作為參數傳入：
```c
// 前置版本
Date &operator++(Date &obj) {
    ++obj.day;
    return obj;
}
```
```c
// 後置版本
Date operator++(Date &obj, int) {
    Date temp = obj;  // 保存當前值
    ++obj.day;        // 遞增
    return temp;      // 返回原值
}
```
### 完整範例
```c
#include <iostream>
using namespace std;

class Date {
private:
    int day;
public:
    Date(int d) : day(d) {}

    // 重載前置 ++
    Date &operator++() {
        ++day;  // 遞增
        return *this;  // 返回自身
    }

    // 重載後置 ++
    Date operator++(int) {
        Date temp = *this;  // 保存當前值
        ++day;              // 遞增
        return temp;        // 返回原值
    }

    void display() const {
        cout << "Day: " << day << endl;
    }
};

int main() {
    Date d(5);

    cout << "Initial day: ";
    d.display();

    // 前置遞增
    ++d;
    cout << "After prefix ++: ";
    d.display();

    // 後置遞增
    d++;
    cout << "After postfix ++: ";
    d.display();
    return 0;
}
```

## Dynamic Memory Management
- 動態記憶體管理允許程式在執行時為物件或陣列分配和釋放記憶體。
- 透過 **`new`** 和 **`delete`** 運算符，可以靈活地控制記憶體分配和釋放。
- 動態分配的記憶體位於 自由存儲區（heap），程式透過指標存取該記憶體。
- 記憶體分配與釋放需成對使用：
	- 每次使用 `new` 分配記憶體時，務必用 `delete` 釋放記憶體。
	- 每次使用 `new []` 分配陣列時，務必用 `delete []` 釋放陣列。
- 例外處理：如果 `new` 運算符分配失敗，會丟出例外，應做好例外處理。
### 動態記憶體分配與釋放
- 使用 `new` 分配記憶體
- 如果記憶體不足：`new` 運算符會丟出例外（exception），提示分配失敗。
```cpp
ClassName *ptr = new ClassName;
// 為 `ClassName` 分配記憶體並呼叫其建構函式。
// 返回指向該物件的指標。

// 範例：
int *num = new int(42);  // 分配整數並初始化為 42
```
- 使用 `delete` 釋放記憶體
- 呼叫指標所指物件的解構函式。
- 將記憶體釋放回自由存儲區。
```c
delete ptr;

// 範例
delete num;  // 釋放記憶體
```
### 動態陣列的分配與釋放
- 使用 `new []` 分配陣列
```cpp
int *arr = new int[10];  // 分配包含 10 個整數的陣列

// 若使用括號初始化，基本型別元素設為 0：
int *arr = new int[10]();  // 初始化所有元素為 0
```
- 使用 `delete []` 釋放陣列
```cpp
delete [] arr;  // 釋放陣列記憶體
// 如果指標是 `nullptr`，使用 `delete` 或 `delete []` 不會產生錯誤。
```
### C++11 新功能：智慧指標（`unique_ptr`）
- **`unique_ptr` 是一種智慧指標**，用來管理動態分配的記憶體。
- 當 `unique_ptr` 超出作用域時，其解構函式會自動釋放管理的記憶體。
- 範例：
```cpp
#include <memory>
std::unique_ptr<int> ptr(new int(10));  // 自動管理記憶體
```
### 程式碼範例
- 動態物件分配與釋放：
```cpp
#include <iostream>
using namespace std;

class Time {
public:
    Time(int h, int m) : hour(h), minute(m) {}
    void display() const { cout << hour << ":" << minute << endl; }
    ~Time() { cout << "Time object destroyed!" << endl; }

private:
    int hour, minute;
};

int main() {
    Time *timePtr = new Time(10, 30);  // 動態分配 Time 物件
    timePtr->display();  // 輸出時間
    delete timePtr;      // 釋放記憶體
    return 0;
}
```
- 動態陣列分配與釋放：
```cpp
#include <iostream>
using namespace std;

int main() {
    int *gradesArray = new int[5] {90, 85, 78, 92, 88};  // 分配陣列並初始化
    for (int i = 0; i < 5; ++i) {
        cout << "Grade " << i + 1 << ": " << gradesArray[i] << endl;
    }
    delete [] gradesArray;  // 釋放記憶體
    return 0;
}
```
- 使用 `unique_ptr` 管理記憶體：
```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr = make_unique<int>(42);  // 使用 unique_ptr
    cout << "Value: " << *ptr << endl;
    // 不需要手動釋放記憶體，unique_ptr 會自動管理
    return 0;
}
```
## Converting Between Types
- 類型轉換的需求：
	- 某些運算僅限於相同類型，例如整數加法（`int + int = int`）。
	- 需要將一種數據類型轉換為另一種類型，例如將 `int` 轉換為 `double`。
- 基本類型的轉換：
    - 編譯器可以自動完成基本類型（如 `int` 和 `double`）之間的轉換。
    - 可以使用 強制轉換（cast operators） 來進行顯式類型轉換。
- 自定義類型的轉換：
    - 編譯器無法預先知道如何轉換自定義類型，因此需要手動指定轉換邏輯。
### 轉換構造函數（Conversion Constructors）
- **轉換構造函數** 是一種特殊的構造函數，它接受單一參數，並允許自動將基本類型轉換為自定義類型。
- 範例
```c
#include <iostream>
using namespace std;

class MyClass {
private:
    int data;

public:
    // 轉換構造函數
    MyClass(int value) : data(value) {
        cout << "轉換構造函數被呼叫，value = " << value << endl;
    }

    void display() const {
        cout << "Data: " << data << endl;
    }
};

int main() {
    MyClass obj1(42);     // 明確初始化，呼叫構造函數
    MyClass obj2 = 42;    // 使用轉換構造函數，隱式轉換 int -> MyClass

    obj1.display();
    obj2.display();
    return 0;
}
```
- 一般構造函數(不使用轉換構造)
```c
#include <iostream>
using namespace std;

class MyClass {
private:
    int data;

public:
    // 一般構造函數
    MyClass(int value) {
        data = value;  // 初始化數據
        cout << "一般構造函數被呼叫，value = " << value << endl;
    }
    void display() const {
        cout << "Data: " << data << endl;
    }
};

int main() {
    MyClass obj(42); // 正常呼叫構造函數，初始化 MyClass
    // MyClass obj2 = 42; // 這裡會編譯錯誤，因為沒有隱式轉換

    obj.display();
    return 0;
}
```
### 轉換運算符
- 轉換運算符 是一種函數，允許將自定義類型（如 MyClass）轉換為基本類型（如 int），或者轉換為另一個自定義類型。
```cpp
class MyClass {
private:
    int data;

public:
    MyClass(int value) : data(value) {}

    // 轉換運算符：將 MyClass 轉換為 int
    operator int() const {
        return data;
    }
};

int main() {
    MyClass obj(42);
    int value = obj;  // 隱式將 MyClass 轉換為 int
    cout << "Converted value: " << value << endl;
    return 0;
}
```
### 範例
- 範例：自定義類型到基本類型的轉換
```cpp
class MyClass {
private:
	int data;
public:
	MyClass(int value) : data(value) {}
	// 將 MyClass 轉換為 int
	operator int() const {
		return data;
	}
};

MyClass obj(42);
int value = static_cast<int>(obj);  // 自動轉換為 int
```
- 範例：自定義類型之間的轉換
```cpp
class ClassA {
private:
	int value;
public:
	ClassA(int v) : value(v) {}
	operator ClassB() const;  // 定義到 ClassB 的轉換
};

class ClassB {
private:
	int data;
public:
	ClassB(int d) : data(d) {}
};

// ClassA 到 ClassB 的轉換
ClassA::operator ClassB() const {
	return ClassB(value);
}

ClassA a(10);
ClassB b = static_cast<ClassB>(a);  // 將 ClassA 轉換為 ClassB
```
## 隱式與顯式轉換的區別
- 顯式轉換：需要程式員明確指定。
```c
MyClass obj(42);
int value = static_cast<int>(obj);  // 顯式將 MyClass 轉換為 int
```
- 隱式轉換：編譯器自動執行，程式員不需要明確指定。
```c
MyClass obj = 42;  // 使用轉換構造函數，隱式轉換 int -> MyClass
int value = obj;   // 使用轉換運算符，隱式轉換 MyClass -> int
```
- 隱式轉換可能導致意外行為
```c
// 單一參數的構造函數如果被用於隱式轉換，可能會在不經意間觸發。
MyClass obj = 3.14;  // 如果允許隱式轉換，可能導致編譯器自動轉換

// 解決方法：在構造函數前加上 `explicit` 關鍵字：
explicit MyClass(int value);
```
### 範例
- 隱式調用轉換構造函數
```cpp
class MyClass {
public:
	MyClass(int value) : data(value) {}
private:
	int data;
};

MyClass obj = 42;  // 自動調用 MyClass(int)
```
- 隱式調用轉換運算符
```cpp
class MyClass {
private:
	int data;
public:
	MyClass(int value) : data(value) {}
	operator int() const {
		return data;
	}
};

MyClass obj(42);
int value = obj;  // 編譯器隱式調用 operator int()
```