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