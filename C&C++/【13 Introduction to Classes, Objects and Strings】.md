## Defining a Class with a Member Function
- 類別是一種藍圖，用來設計物件(Object)的結構和功能。
- 可以想像成「模型」，例如 GradeBook 是「課程成績簿」的設計藍圖。
### 類別的基本結構
- 類別名稱：
	- 使用 class 關鍵字來定義類別，後接類別名稱。
	- 類別名稱的命名建議首字母大寫，使用 Pascal 命名法 (例：GradeBook)。
- 類別的組成：
	- 成員函式：類別內的功能，例如顯示訊息。
	- 存取修飾詞：控制類別內的功能是否可以被外部呼叫，例如 public:。
```c
class 類別名稱 {
public:
    // 定義成員函式
    void 函式名稱() const {
        // 函式功能
    }
}; // 類別結尾記得加分號
```

### 如何使用類別與物件
- 建立類別物件
```c
// 類別名稱 物件名稱
GradeBook myGradeBook; // 建立一個 GradeBook 的物件
```
- 呼叫成員函式
```c
// 使用「物件名稱 + . + 函式名稱」的方式呼叫。
myGradeBook.displayMessage(); // 呼叫 displayMessage 函式
```
### 完整範例
```c
#include <iostream>
using namespace std;

class GradeBook {
public:
    // 成員函式：顯示歡迎訊息
    void displayMessage() const {
        cout << "Welcome to the Grade Book!" << endl;
    }
};

int main() {
    GradeBook myGradeBook;       // 建立物件
    myGradeBook.displayMessage(); // 呼叫函式
    return 0;
}
```
## Defining a Member Function with a Parameter
### 什麼是函式的參數？
- 參數是提供給函式的額外資訊，幫助函式完成任務。
- 當我們呼叫函式時，傳入的值稱為「引數 (argument)」。
- 舉例：你點外賣時，告訴店家「我要加起司」，這就是「參數」。
### 用參數改變函式行為
```c
// 函式沒有參數：固定輸出訊息。
void displayMessage() {
    cout << "Welcome to the Grade Book!" << endl;
}

// 函式有參數：依據參數顯示不同內容。
void displayMessage(string courseName) {
    cout << "Welcome to the grade book for " << courseName << "!" << endl;
}
```

### 實際案例：用參數自訂歡迎訊息
```c
#include <iostream>
#include <string>
using namespace std;

class GradeBook {
public:
    // 成員函式：顯示歡迎訊息
    void displayMessage(string courseName) const {
        cout << "Welcome to the grade book for " << courseName << "!" << endl;
    }
};

int main() {
    GradeBook myGradeBook;           // 建立物件
    string nameOfCourse;             // 定義課程名稱變數

    cout << "Please enter the course name: ";
    getline(cin, nameOfCourse);      // 接收使用者輸入

    myGradeBook.displayMessage(nameOfCourse); // 呼叫函式並傳入課程名稱
    return 0;
}
```
## Data Members, set Member Functions and get Member Functions
### 什麼是資料成員？
- 資料成員是類別內的變數，用來儲存物件的屬性。
- 每個物件都擁有自己的資料成員，像是一個獨立的存放區。
- 範例：  `string courseName;` 是一個資料成員，用來記錄課程名稱。
### 為什麼需要資料成員？
- 資料儲存：幫助物件記住自己的狀態。例：`courseName` 可以記住課程名稱。
- 封裝資料：透過「隱藏內部細節」提升安全性，避免資料被外部程式隨意更改。
### 封裝 (Encapsulation) 
- 封裝：資料成員通常設定為 `private`，避免外部程式直接存取。
- 如何操作資料成員？
    - 使用「`set` 成員函式」來修改值。
    - 使用「`get` 成員函式」來取得值。
### set 函式
- 負責修改資料成員的值。
- 又稱 Mutator (修改器)。
```c
void setCourseName(string name){
	courseName = name; 
}
```
### `get` 函式
- 用於取得資料成員的值 (也稱為 Accessor)。
```c
string getCourseName() const {
	return courseName; 
}
```
### 完整範例：設置與取得課程名稱
```c
// 定義類別：`GradeBook`
// 包含資料成員 `courseName`。
// 提供 `setCourseName` 和 `getCourseName` 函式。

#include <iostream>
#include <string>
using namespace std;

class GradeBook {
private:
    string courseName; // 資料成員：課程名稱
public:
    // 設定課程名稱
    void setCourseName(string name) {
        courseName = name; // 將參數存入 courseName
    }

    // 取得課程名稱
    string getCourseName() const {
        return courseName; // 回傳 courseName 的值
    }

    // 顯示歡迎訊息
    void displayMessage() const {
        cout << "Welcome to the grade book for " << getCourseName() << "!" << endl;
    }
};
```
## Class Scope and Accessing Class Members 
### 類別範疇 (Class Scope)
- 資料成員 和 成員函式 屬於類別的範疇，能直接互相存取。
- 非成員函式預設定義在全域範疇 (Global Scope)。
#### 內部存取 (Inline Access)
```c
#include <iostream>
using namespace std;

class Account {
    double balance; // 資料成員
public:
    void setBalance(double b) { balance = b; } // 在類別內部定義
    double getBalance() { return balance; }   // 在類別內部定義
};

int main() {
    Account acc;           // 創建 Account 物件
    acc.setBalance(100.0); // 呼叫內部定義的成員函式
    cout << "Balance: " << acc.getBalance() << endl;
    return 0;
}
/*
執行結果
Balance: 100
*/
```
#### 外部存取 (External Access)
- 成員函式的定義在類別外部，只在類別內提供函式的原型 (宣告)。
- 需要使用 範疇解析運算符 (::) 指定函式所屬的類別。
- 適合更複雜或較長的函式實作，讓類別定義保持簡潔。
```c
#include <iostream>
using namespace std;

class Account {
    double balance; // 資料成員
public:
    void setBalance(double b);   // 成員函式宣告
    double getBalance() const;   // 成員函式宣告
};

// 類別外部定義 setBalance
void Account::setBalance(double b) {
    balance = b; // 存取類別內部的資料成員
}

// 類別外部定義 getBalance
double Account::getBalance() const {
    return balance; // 存取類別內部的資料成員
}

int main() {
    Account acc;           // 創建 Account 物件
    acc.setBalance(200.0); // 呼叫外部定義的成員函式
    cout << "Balance: " << acc.getBalance() << endl;
    return 0;
}
/*
執行結果
Balance: 200
*/
```
## Initializing Objects with Constructors
- 建構函式是一種特殊的成員函式，用於在**物件建立時自動執行**，幫助物件初始化。
- 特點：
	- 名稱必須與類別相同。
	- 沒有回傳型別 (不能寫 void 或其他型別)。
	- 由系統自動呼叫，無需手動執行。
- 建構函式的用途
	- 物件初始化：在物件創建時自動設定屬性的初始值。
	- 簡化程式碼：避免額外的設定步驟。
### 基本結構
```c
class 類別名稱 {
public:
    類別名稱(參數列表) {
        // 初始化程式碼
    }
};


// 範例
class GradeBook {
private:
    string courseName; // 資料成員：課程名稱

public:
    // 建構函式
    GradeBook(string name) {
        courseName = name; // 初始化 courseName
    }
    // 成員函式
    void displayMessage() const {
        cout << "Welcome to the course: " << courseName << endl;
    }
};

int main() {
    // 建立物件並初始化
    GradeBook myGradeBook("CS101 Introduction to Programming");
    // 呼叫成員函式
    myGradeBook.displayMessage();
    return 0;
}
```
### 初始化列表 (Member Initializer List)
- 是一種簡化的語法，讓資料成員在建構函式執行前初始化。
- 為什麼使用初始化列表：提升執行效率，避免重複操作。
- 不使用初始化列表：
```c
GradeBook(string name) {
    courseName = name; // 用指派操作初始化
}
```
- 使用方式：
```c
GradeBook(string name) : courseName(name) {} // 初始化列表
// 在物件建立時，`courseName` 直接被初始化為 `name`。
// 不需要經過「先建構、再指派」的步驟。
```
#### 必須使用初始化列表的情況
- 常數成員 (`const`)：常數成員必須在初始化列表中設定，因為無法在建構函式內指派。
```c
class Example {
private:
    const int constantValue;

public:
    Example(int value) : constantValue(value) {} // 必須使用初始化列表
};
```
- 參考成員 (&)：引用型別的成員變數必須在初始化列表中初始化，無法透過指派操作。
```c
class Example {
private:
    int &referenceValue;

public:
    Example(int &value) : referenceValue(value) {} // 初始化參考
};
```
- 成員類別沒有預設建構函式：如果資料成員的型別 (例如另一個類別) 沒有預設建構函式，必須在初始化列表中初始化。
```c
class Example {
private:
    AnotherClass member;

public:
    Example() : member(10) {} // 初始化列表用參數建構
};
```

#### 完整範例：有與沒有初始化列表的比較
```c
#include <iostream>
#include <string>
using namespace std;

// 使用初始化列表的版本
class GradeBook {
private:
    string courseName;

public:
    GradeBook(string name) : courseName(name) {} // 初始化列表
    void displayMessage() const {
        cout << "Welcome to the course: " << courseName << endl;
    }
};

// 不使用初始化列表的版本
class GradeBookWithoutInitList {
private:
    string courseName;

public:
    GradeBookWithoutInitList(string name) {
        courseName = name; // 指派操作
    }
    void displayMessage() const {
        cout << "Welcome to the course: " << courseName << endl;
    }
};

int main() {
    // 使用初始化列表
    GradeBook gradeBook1("CS101 Introduction to C++");
    gradeBook1.displayMessage();

    // 不使用初始化列表
    GradeBookWithoutInitList gradeBook2("CS102 Data Structures");
    gradeBook2.displayMessage();
    return 0;
}
```
### 預設建構函式 (Default Constructor)
- 無參數的建構函式，用於初始化資料成員為預設值。
- 如果類別未定義任何建構函式，編譯器會自動生成一個空的預設建構函式。
```c
class GradeBook {
private:
    string courseName;

public:
    GradeBook() { // 預設建構函式
        courseName = "No course assigned";
    }

    void displayMessage() const {
        cout << "Course: " << courseName << endl;
    }
};

int main() {
    GradeBook myGradeBook; // 呼叫預設建構函式
    myGradeBook.displayMessage(); // Course: No course assigned
    return 0;
}
```
## Destructors(解構子)
- 解構函式名稱為 類別名稱前加上波浪號 (~)。
- 用於執行物件銷毀前的收尾工作 (例如釋放資源)。
- 不接收參數，不回傳任何值，也不能指定回傳型別 (連 void 都不允許)。
```c
class Example {
public:
    ~Example(); // 解構函式
};
```
### 解構函式的功能
- 內存管理：
	- 解構函式本身不釋放物件的記憶體，僅執行收尾工作。
	- 物件記憶體的真正釋放由系統完成。
- 資源釋放：
	- 用於釋放分配的動態記憶體 (如 new 配對 delete)。
	- 關閉檔案、釋放網路連線或其他外部資源。
### 解構函式範例
```c
#include <iostream>
using namespace std;

class Example {
public:
    Example() {
        cout << "Constructor called!" << endl;
    }
    ~Example() { // 解構函式
        cout << "Destructor called!" << endl;
    }
};

int main() {
    Example ex; // 創建物件
    // 當物件 ex 離開作用域時，自動呼叫解構函式
    return 0;
}
```
## When Constructors and Destructors Are Called
- 隱式呼叫：
	- 建構函式：當物件被建立時自動呼叫。
	- 解構函式：當物件超出作用域或程式終止時自動呼叫。
- 呼叫順序：
	- 建構函式按物件建立順序執行。
	- 解構函式按建構函式相反順序執行（即後建構的物件先解構）。
### 不同範圍的建構與解構行為
- 全域範圍的物件：
	- 建構函式在 main 函式執行前呼叫。
	- 解構函式在 main 結束後呼叫。
- 區域範圍的物件：
	- 建構函式在進入物件定義的作用域時呼叫。
	- 解構函式在離開作用域時呼叫。
	- 若程式直接使用 exit 或 abort 終止，則不呼叫區域物件的解構函式。
- 靜態區域的物件：
	- 建構函式僅在第一次執行到物件定義處時呼叫。
	- 解構函式在 main 結束時或程式呼叫 exit 時執行。
	- 若程式直接使用 abort 終止，則不呼叫靜態物件的解構函式。
### 程式中止的影響
- exit 函式：
	- 立即結束程式。
	- 不會呼叫區域物件的解構函式，但仍會呼叫全域與靜態物件的解構函式。
- abort 函式：
	- 強制結束程式。
	- 不呼叫任何物件的解構函式。
### 範例
- 定義類別 CreateAndDestroy結構
```c
// CreateAndDestroy.h

#ifndef CREATE_H
#define CREATE_H

#include <string>
using namespace std;

// 定義類別 CreateAndDestroy
class CreateAndDestroy {
public:
    CreateAndDestroy(int, string); // 建構函式
    ~CreateAndDestroy();           // 解構函式

private:
    int objectID;      // 物件的 ID
    string message;    // 物件描述訊息
};
#endif
```
- 定義類別 CreateAndDestroy實作內容
```c
// CreateAndDestroy.cpp

#include <iostream>
#include "CreateAndDestroy.h"
using namespace std;

// 建構函式：初始化物件的 ID 和描述訊息
CreateAndDestroy::CreateAndDestroy(int ID, string messageString)
    : objectID(ID), message(messageString) {
    cout << "Object " << objectID << "  constructor runs  " << message << endl;
}

// 解構函式：釋放物件並輸出訊息
CreateAndDestroy::~CreateAndDestroy() {
    cout << (objectID == 1 || objectID == 6 ? "\n" : ""); // 格式化輸出
    cout << "Object " << objectID << "  destructor runs  " << message << endl;
}
```
- 主要實作：fig09_09.cpp
```cpp
#include <iostream>
#include "CreateAndDestroy.h"
using namespace std;

// 函式原型
void create(void);

// 全域範圍物件
CreateAndDestroy first(1, "(global before main)");

int main() {
    cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
    // 區域物件
    CreateAndDestroy second(2, "(local automatic in main)");
    // 靜態區域物件
    static CreateAndDestroy third(3, "(local static in main)");
    // 呼叫函式 create
    create();
    cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
    // 區域物件
    CreateAndDestroy fourth(4, "(local automatic in main)");
    cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
}

void create() {
    cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
    // 區域物件
    CreateAndDestroy fifth(5, "(local automatic in create)");
    // 靜態區域物件
    static CreateAndDestroy sixth(6, "(local static in create)");
    // 區域物件
    CreateAndDestroy seventh(7, "(local automatic in create)");
    cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
}

/*
程式運行輸出
Object 1  constructor runs  (global before main)

MAIN FUNCTION: EXECUTION BEGINS
Object 2  constructor runs  (local automatic in main)
Object 3  constructor runs  (local static in main)

CREATE FUNCTION: EXECUTION BEGINS
Object 5  constructor runs  (local automatic in create)
Object 6  constructor runs  (local static in create)
Object 7  constructor runs  (local automatic in create)
CREATE FUNCTION: EXECUTION ENDS
Object 7  destructor runs  (local automatic in create)
Object 5  destructor runs  (local automatic in create)

MAIN FUNCTION: EXECUTION RESUMES
Object 4  constructor runs  (local automatic in main)

MAIN FUNCTION: EXECUTION ENDS
Object 4  destructor runs  (local automatic in main)
Object 2  destructor runs  (local automatic in main)
Object 6  destructor runs  (local static in create)
Object 3  destructor runs  (local static in main)
Object 1  destructor runs  (global before main)
*/
```
## Placing a Class in a Separate File for Reusability
### 為什麼要把類別分離至標頭檔？
- 重用性：將類別寫在標頭檔 (.h)，其他程式可以用 #include 指令快速重用。
- 清楚的結構：主程式的邏輯和類別定義分開，讓程式更容易閱讀與維護。
- 工程開發標準：大型專案中，類別通常會分為 .h（定義）和 .cpp（實作）。
### 隱式轉換是什麼
- 隱式轉換（Implicit Conversion），也稱為**型別自動轉換**，是 C++ 編譯器自動將一種資料型別轉換為另一種相容型別的過程。
- 例如：整數轉換為浮點數、較小型別轉換為較大型別。這個過程不需要程式設計師明確指定，編譯器會自動完成。
```c
// 整數轉換為浮點數
int x = 10;
double y = x; // 隱式轉換：將整數 x 轉換為浮點數 y

// 字元轉換為整數
char c = 'A';
int asciiValue = c; // 隱式轉換：將字元 'A' 轉換為其 ASCII 值 65
```
- 隱式轉換可能帶來的問題：
	- 精度損失
	- 數值溢位
	- 語意不清
#### 如何避免隱式轉換： 
- 使用 explicit 關鍵字
```c
class GradeBook {
public:
    explicit GradeBook(string name) {
        courseName = name;
    }
};

GradeBook gb1 = "CS101"; // 編譯錯誤：隱式轉換被禁止
GradeBook gb2("CS101");  // 正確：明確呼叫建構函式
```
- 明確型別轉換：使用強制型別轉換來清楚表示轉換的意圖。
```c
double result = static_cast<double>(5) / 2; // 明確地將整數轉換為浮點數
```
### 基本分離結構
#### 標頭檔 (`GradeBook.h`)
- 放類別定義和函式的宣告，不包含具體的函式內容
```c
#include <string> // 提供 std::string 類別

class GradeBook {
public:
    explicit GradeBook(std::string name); // 建構函式
    void setCourseName(std::string name); // 設定課程名稱
    std::string getCourseName() const;    // 取得課程名稱
    void displayMessage() const;         // 顯示訊息

private:
    std::string courseName;              // 資料成員: 課程名稱
};
```
#### 實作檔 (GradeBook.cpp)
```c
#include "GradeBook.h" // 導入標頭檔
#include <iostream>
using namespace std; // 使用命名空間 std

GradeBook::GradeBook(string name) : courseName(name) {} // 初始化列表

void GradeBook::setCourseName(string name) {
    courseName = name; // 設定課程名稱
}

string GradeBook::getCourseName() const {
    return courseName; // 傳回課程名稱
}

void GradeBook::displayMessage() const {
    cout << "Welcome to the course: " << getCourseName() << endl; // 顯示歡迎訊息
}
```
#### 主程式檔 (main.cpp)
```c
#include <iostream>
#include "GradeBook.h" // 導入類別定義
using namespace std;

int main() {
    GradeBook course1("CS101 Introduction to C++ Programming"); // 建立物件
    GradeBook course2("CS102 Data Structures in C++");
    cout << "Course 1: " << course1.getCourseName() << endl;
    cout << "Course 2: " << course2.getCourseName() << endl;

    return 0;
}
```
## Separating Interface from Implementation
![upgit_20241129_1732859164.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241129_1732859164.png)

### 介面與實作分離的概念
- 介面 (Interface)：
	- 定義類別的公開成員函式 (Public Member Functions)，描述可用的功能及其使用方式。
	- 位於 .h 標頭檔，僅包含函式原型 (Prototypes)。
- 實作 (Implementation)：
	- 定義類別成員函式的具體邏輯。
	- 位於 .cpp 檔案，與標頭檔分離。
- 目的：
	- 提高程式的模組化與可讀性。
	- 隱藏實作細節，減少客戶程式對類別內部的依賴。
### 分離的結構與組件
- 標頭檔 (`GradeBook.h`)
```c
// 定義類別的介面
// 包含：類別名稱、資料成員宣告、公開成員函式的原型

#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <string>
class GradeBook {
public:
    explicit GradeBook(std::string name);
    void setCourseName(std::string name);
    std::string getCourseName() const;
    void displayMessage() const;
private:
    std::string courseName; // 課程名稱
};
#endif
```
- 實作檔 (`GradeBook.cpp`)：
```c
// 包含成員函式的具體邏輯。
// 每個函式的名稱前需加上類別名稱與範圍解析運算符 (`::`)。
#include <iostream>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(string name) : courseName(name) {}

void GradeBook::setCourseName(string name) {
    courseName = name;
}

string GradeBook::getCourseName() const {
    return courseName;
}

void GradeBook::displayMessage() const {
    cout << "Welcome to the grade book for " << getCourseName() << "!" << endl;
}
```
- 主程式檔 (`main.cpp`)
```c
// 使用 `#include "GradeBook.h"` 引入類別介面。
#include <iostream>
#include "GradeBook.h"
using namespace std;

int main() {
    GradeBook gradeBook1("CS101 Introduction to C++ Programming");
    GradeBook gradeBook2("CS102 Data Structures in C++");

    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName() << endl;
    cout << "gradeBook2 created for course: " << gradeBook2.getCourseName() << endl;

    return 0;
}
```

## Time Class Case Study
### 定義class的結構：Time.h
```c
#ifndef TIME_H // Include Guard：防止重複包含 header
#define TIME_H

// Time 類別定義
class Time {
public:
    Time(); // constructor

    void setTime(int, int, int); // 設定時、分、秒
    void printUniversal() const; // 以 24 小時制格式輸出時間
    void printStandard() const;  // 以 12 小時制格式輸出時間

private:
    unsigned int hour;   // 時 (0 - 23，24 小時制)
    unsigned int minute; // 分 (0 - 59)
    unsigned int second; // 秒 (0 - 59)
}; // end class Time

#endif
```
### 負責class的實作 (implementation)：Time.cpp
```c
#include <iostream>
#include <iomanip>      // for std::setw and std::setfill(填充寬度與填充字元)
#include <stdexcept>    // for std::invalid_argument(處裡異常)
#include "Time.h"       // include definition of class Time from Time.h

using namespace std;

// 建構函式 (`Time::Time`)，初始化成員變數 `hour`, `minute`, 和 `second` 為 0
Time::Time()
    : hour(0), minute(0), second(0) {
} 

// 設定時間
void Time::setTime(int h, int m, int s) {
    // 驗證 hour、minute 和 second 是否在合法範圍
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
        hour = h;
        minute = m;
        second = s;
    } else {
        throw invalid_argument("hour, minute and/or second was out of range");
    }
} // end function setTime

// 以 24 小時制格式輸出時間 (HH:MM:SS)
void Time::printUniversal() const {
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second;
} // end function printUniversal

// 以 12 小時制格式輸出時間 (HH:MM:SS AM or PM)
void Time::printStandard() const {
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setw(2) << second << (hour < 12 ? " AM" : " PM");
} // end function printStandard
```
### 實例化class
```c
#include <iostream>
#include <stdexcept>    // 用於處理 invalid_argument 例外
#include "Time.h"       // 引入 Time 類別的定義

using namespace std;

int main() {
    Time t; // 實例化 Time 類別的物件 t

    // 輸出物件 t 的初始值
    cout << "The initial universal time is ";
    t.printUniversal(); // 預期輸出: 00:00:00
    cout << "\nThe initial standard time is ";
    t.printStandard();  // 預期輸出: 12:00:00 AM

    // 設定新的時間
    t.setTime(13, 27, 6); // 設定時間為 13:27:06

    // 輸出更新後的時間
    cout << "\n\nUniversal time after setTime is ";
    t.printUniversal(); // 預期輸出: 13:27:06
    cout << "\nStandard time after setTime is ";
    t.printStandard();  // 預期輸出: 1:27:06 PM

    // 嘗試設定無效的時間
    try {
        t.setTime(99, 99, 99); // 無效輸入，超出範圍
    } catch (invalid_argument &e) {
        // 捕獲例外，輸出錯誤訊息
        cout << "\n\nException: " << e.what() << endl;
    }

    // 輸出物件 t 在設定無效時間後的值
    cout << "\nAfter attempting invalid settings:" << "\nUniversal time: ";
    t.printUniversal(); // 預期仍輸出之前的有效時間: 13:27:06
    cout << "\nStandard time: ";
    t.printStandard();  // 預期仍輸出之前的有效時間: 1:27:06 PM
    cout << endl;
    return 0;
}

/*
輸出結果
The initial universal time is 00:00:00
The initial standard time is 12:00:00 AM

Universal time after setTime is 13:27:06
Standard time after setTime is 1:27:06 PM

Exception: hour, minute and/or second was out of range

After attempting invalid settings:
Universal time: 13:27:06
Standard time: 1:27:06 PM
*/
```
## friend Functions and friend Classes
### friend 函數
- 是一個非成員函數，但有權限訪問類別的公有與非公有成員。
- 可以是獨立函數，也可以是其他類別的成員函數。
- 限制與特性
	- 授予友元權限：友元關係需要被授權，無法自行取得。
	- 非對稱性：若類別 A 是類別 B 的 friend，B 不會自動成為 A 的 friend。
	- 非傳遞性：若 A 是 B 的 friend，B 是 C 的 friend，則 A 不會自動成為 C 的 friend。
#### friend 宣告
- 函數宣告
```c
// 使用關鍵字 friend 修飾函數原型。
class ClassOne {
    friend void someFunction(ClassOne &obj);
};
```
- 類別宣告
```c
// 在類別定義中，使用 friend class 宣告另一個類別為友元。
class ClassOne {
    friend class ClassTwo;
};
```
### 範例：使用 friend 函數修改私有成員
```c
class Count {
    // 宣告並實作 friend 函數
    friend void setX(Count &obj, int value) {
        obj.x = value; // 直接修改私有成員 x
    }
public:
    Count() : x(0) {} // 初始化 x 為 0
    void print() const { cout << x << endl; } // 顯示 x 的值
private:
    int x; // 私有資料成員
};

int main() {
    Count counter;
    counter.print();      // 初始值 0
    setX(counter, 8);     // 呼叫 friend 函數修改 x
    counter.print();      // 修改後的值 8
    return 0;
}
```
## Using the this Pointer
- this 是一個指向物件自身的隱含指標。
- 非靜態成員函數中，this 被編譯器作為隱式參數傳遞。
- 不佔用物件本身的內存空間 (sizeof 不包含 this)。
- 用途：避免命名衝突
```c
// 使用 this 指標可區分類別成員與函數參數
void setHour(int hour) {
    this->hour = hour;
}
```

## static Class Members
- 用於共享類別中所有物件的單一變數，不屬於特定物件。
- 表示全類別共用的資訊，而非每個物件特有的資料。
- 不需物件即可呼叫，為類別提供服務，而非物件。
- 透過類別名稱和範圍解析運算符 :: 存取。
- 初始化靜態成員：
```c
unsigned int Employee::count = 0;
```
### 範例
```c
#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    // 建構子: 初始化名字與姓氏，並增加物件計數
    Employee(const string &first, const string &last)
        : firstName(first), lastName(last) {
        ++count; // 每創建一個物件，計數器加 1
        cout << "Employee constructor for " << firstName << " " << lastName << " called." << endl;
    }

    // 解構子: 減少物件計數
    ~Employee() {
        --count; // 每刪除一個物件，計數器減 1
        cout << "Employee destructor for " << firstName << " " << lastName << " called." << endl;
    }

    // Getter: 回傳名字
    string getFirstName() const {
        return firstName;
    }

    // Getter: 回傳姓氏
    string getLastName() const {
        return lastName;
    }

    // 靜態函數: 回傳目前物件的數量
    static unsigned int getCount() {
        return count;
    }

private:
    string firstName; // 每個物件的名字
    string lastName;  // 每個物件的姓氏

    // 靜態資料成員: 記錄物件數量 (所有物件共用)
    static unsigned int count;
};

// 初始化靜態資料成員
unsigned int Employee::count = 0;
int main() {
    // 使用類別名直接呼叫靜態函數，顯示初始物件數量
    cout << "Number of employees before instantiation: " << Employee::getCount() << endl;

    // 創建 Employee 物件的作用域 (區塊)
    {
        // 建立兩個 Employee 物件
        Employee e1("Susan", "Baker");
        Employee e2("Robert", "Jones");
        // 顯示物件數量
        cout << "\nNumber of employees after instantiation: " << Employee::getCount() << endl;
        // 顯示兩個物件的詳細資訊
        cout << "\nEmployee 1: " << e1.getFirstName() << " " << e1.getLastName() << endl;
        cout << "Employee 2: " << e2.getFirstName() << " " << e2.getLastName() << endl;
    } // 離開作用域，e1 和 e2 被解構

    // 再次顯示物件數量，確保靜態資料成員正確更新
    cout << "\nNumber of employees after destruction: " << Employee::getCount() << endl;
    return 0;
}
```