- 備註：這個章節，我其實也不知道我在寫三小==
## Class Templates
- 類別模板是一種可以處理多種數據類型的類別設計方式。
- 就像一個「通用模具」，可以用來創建針對不同數據類型的具體類別。
### 為什麼要用類別模板?
- 減少重複代碼：不用為每種數據類型（如 `int`, `double`, `string`）分別寫一個類別。
- 提高靈活性：可以一次寫好，適用於多種情況。
- 實現代碼重用：只要用模板，就能輕鬆擴展。
### 類別模板基本語法
```cpp
template<typename T> // 定義模板，`T` 是一個占位符，表示「類別會用到的數據類型」。
class 類別名稱 {
    // 成員變量
    T 成員變量;

    // 成員函數
    T 函數名稱(T 參數) {
        // 實現
    }
};
```
- 範例 1: 簡單的模板類別：製作一個可以儲存任意類型數據的容器
```cpp
template<typename T>
class Box {
public:
    T value; // 儲存值

    void setValue(T v) { // 設定值
        value = v;
    }

    T getValue() { // 獲取值
        return value;
    }
};

int main() {
    Box<int> intBox; // 宣告一個 Box<int>
    intBox.setValue(123);
    cout << "Box 的值是: " << intBox.getValue() << endl;

    Box<string> stringBox; // 宣告一個 Box<string>
    stringBox.setValue("Hello");
    cout << "Box 的值是: " << stringBox.getValue() << endl;
    return 0;
}
/*
輸出結果：
Box 的值是: 123
Box 的值是: Hello
*/
```
- 範例 2: 實現一個簡單的 Stack (堆疊)
```cpp
#include <iostream>
#include <deque> // 使用 deque 容器

template<typename T>
class Stack {
private:
    std::deque<T> stack; // 使用 deque 作為底層容器

public:
    void push(const T& value) { // 壓入元素
        stack.push_front(value);
    }
    void pop() { // 彈出元素
        stack.pop_front();
    }
    T top() const { // 查看頂部元素
        return stack.front();
    }
    bool isEmpty() const { // 檢查是否為空
        return stack.empty();
    }
};

int main() {
    Stack<int> intStack; // 定義一個 int 堆疊
    intStack.push(10);
    intStack.push(20);
    cout << "頂部元素: " << intStack.top() << endl; // 輸出 20
    intStack.pop();
    cout << "頂部元素: " << intStack.top() << endl; // 輸出 10

    Stack<string> stringStack; // 定義一個 string 堆疊
    stringStack.push("Hello");
    stringStack.push("World");
    cout << "頂部元素: " << stringStack.top() << endl; // 輸出 "World"

    return 0;
}
/*
輸出結果：
頂部元素: 20
頂部元素: 10
頂部元素: World
*/
```
## Function Template to Manipulate a Class-Template Specialization Object
- 函數模板是一種用來處理多種數據類型的函數設計方法，類似於類別模板的概念。
### 函數模板如何操作類別模板?
- 我們可以將類別模板物件作為函數模板的參數，實現通用的功能操作。
- 範例：操作 Stack 類別模板：
	- 壓入一系列值到 Stack。
	- 彈出 Stack 中的所有值。
### 函數模板的語法
```c
template<typename T>
void 函數名稱(參數列表) {
    // 函數邏輯
}
```
- 範例：函數模板操作 Stack 類別模板：使用函數模板 `testStack`，統一處理 `Stack<int>` 和 `Stack<double>`。
```c
#include <iostream>
#include <string>
#include "Stack.h" // 包含 Stack 類別模板的定義

using namespace std;

// 函數模板定義
template<typename T>
void testStack(
    Stack<T> &theStack,  // 引用類別模板物件
    const T &value,      // 初始化壓入的值
    const T &increment,  // 每次壓入的值增量
    size_t size,         // 壓入的元素數量
    const string &stackName // Stack 名稱，用於輸出
) {
    cout << "\n將元素壓入 " << stackName << ":\n";

    T pushValue = value;
    for (size_t i = 0; i < size; ++i) {
        theStack.push(pushValue); // 壓入元素
        cout << pushValue << ' ';
        pushValue += increment;
    }

    cout << "\n\n從 " << stackName << " 彈出元素:\n";
    while (!theStack.isEmpty()) {
        cout << theStack.top() << ' ';
        theStack.pop(); // 彈出元素
    }
    cout << "\n堆疊已空，無法彈出。\n";
}

int main() {
    Stack<double> doubleStack; // 創建 Stack<double>
    testStack(doubleStack, 1.1, 1.1, 5, "doubleStack");

    Stack<int> intStack; // 創建 Stack<int>
    testStack(intStack, 1, 1, 10, "intStack");
    return 0;
}
/*
執行結果
將元素壓入 doubleStack:
1.1 2.2 3.3 4.4 5.5

從 doubleStack 彈出元素:
5.5 4.4 3.3 2.2 1.1
堆疊已空，無法彈出。

將元素壓入 intStack:
1 2 3 4 5 6 7 8 9 10

從 intStack 彈出元素:
10 9 8 7 6 5 4 3 2 1
堆疊已空，無法彈出。
*/
```
## Nontype Parameters
- 非類型參數是一種可以傳遞「常量」給模板的參數，與類型參數 (Type Parameters) 不同。
- 特點：
	- 非類型參數在模板聲明中是常量。
	- 可以設定預設值。
	- 常見用途：設定固定大小或數值。
### 非類型參數的語法
```cpp
template <typename T, size_t N>
class 類別名稱 {
    T data[N]; // 固定大小的內建數組
};
// T：類型參數，決定數據的類型。
// N：非類型參數，指定固定大小或其他常量。
```
### 範例：C++ 標準模板庫 (STL) 的 array 類
- 模板聲明
```cpp
template <class T, size_t N>
class array {
    T elements[N]; // 內建數組作為數據成員
};
```
- 使用方式
```cpp
#include <array>
using namespace std;

int main() {
    array<int, 5> intArray;     // 5 個整數元素的陣列
    array<double, 10> dblArray; // 10 個雙精度浮點數元素的陣列
    intArray.fill(42); // 初始化所有元素為 42
    for (size_t i = 0; i < intArray.size(); ++i) {
        cout << intArray[i] << ' '; // 輸出每個元素
    }

    return 0;
}
/*
輸出結果：
42 42 42 42 42
*/
```
### 自定義非類型參數模板
- 任務：自定義一個固定大小的 Stack
```cpp
#include <iostream>
using namespace std;

template <typename T, size_t N>
class FixedStack {
private:
    T data[N];
    size_t topIndex;

public:
    FixedStack() : topIndex(0) {}

    void push(const T& value) {
        if (topIndex < N) {
            data[topIndex++] = value;
        } else {
            cout << "Stack is full!\n";
        }
    }

    void pop() {
        if (topIndex > 0) {
            --topIndex;
        } else {
            cout << "Stack is empty!\n";
        }
    }

    T top() const {
        if (topIndex > 0) {
            return data[topIndex - 1];
        } else {
            throw runtime_error("Stack is empty!");
        }
    }

    bool isEmpty() const {
        return topIndex == 0;
    }

    bool isFull() const {
        return topIndex == N;
    }
};

int main() {
    FixedStack<int, 5> stack; // 創建大小為 5 的整數堆疊

    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (!stack.isEmpty()) {
        cout << stack.top() << ' ';
        stack.pop();
    }

    return 0;
}
/*
輸出結果：
30 20 10
*/
```
## Default Arguments for Template Type Parameters
- 在模板中，類型參數可以設定一個預設值，當使用模板時，未明確指定參數時會自動採用這個預設值。
### 語法與規則
```c
template <typename T, typename Container = deque<T>>
class 類別名稱 {
    // 類別實現
};
// 預設參數必須放在模板參數列表的最右側。
// 如果省略一個參數，所有右邊的參數也必須省略。
```
### 範例：C++ STL 的 stack 類
```c
template <class T, class Container = deque<T>>
class stack {
    // 堆疊的實現
};
```
#### 如何使用？
- 不提供第二個參數，使用預設值
```c
stack<int> values; // 使用預設的 deque<int> 作為底層容器
```
- 自定義第二個參數
```c
stack<int, vector<int>> customStack; // 改用 vector<int> 作為底層容器
```
### 範例：預設值與自定義容器
```c
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    // 默認情況：使用 deque 作為底層容器
    stack<int> defaultStack;
    defaultStack.push(10);
    defaultStack.push(20);
    cout << "默認堆疊頂部元素: " << defaultStack.top() << endl; // 輸出 20
    defaultStack.pop();
    cout << "默認堆疊頂部元素: " << defaultStack.top() << endl; // 輸出 10

    // 自定義情況：使用 vector 作為底層容器
    stack<int, vector<int>> customStack;
    customStack.push(100);
    customStack.push(200);
    cout << "自定義堆疊頂部元素: " << customStack.top() << endl; // 輸出 200
    customStack.pop();
    cout << "自定義堆疊頂部元素: " << customStack.top() << endl; // 輸出 100
    return 0;
}
/*
執行結果
默認堆疊頂部元素: 20
默認堆疊頂部元素: 10
自定義堆疊頂部元素: 200
自定義堆疊頂部元素: 100
*/
```
### C++11 新特性：函數模板的預設值
- 在 C++11 中，函數模板的類型參數也可以有預設值。
```c
#include <iostream>
using namespace std;

template <typename T = int>
void printValue(T value) {
    cout << "Value: " << value << endl;
}

int main() {
    printValue(42);         // 使用預設類型 int
    printValue<double>(3.14); // 顯式指定類型 double
    return 0;
}
/*
執行結果
Value: 42
Value: 3.14
*/
```
## Overloading Function Templates
- 函數模板重載是指可以定義多個模板或非模板函數，它們具有相同的函數名稱，但參數列表不同。
- 當調用函數時，編譯器根據參數的類型和數量來選擇最匹配的函數或模板函數。
- 為什麼要使用函數模板重載？
	- 提供多種版本的函數以處理不同類型或數量的參數。
	- 使代碼更加靈活且易於擴展。
### 語法與特點
- 使用相同的函數名稱，但具有不同的模板參數或參數列表。
```c
template <typename T>
void print(T value);

template <typename T, typename U>
void print(T value1, U value2);
```
- 模板與非模板函數重載：可以為模板函數定義非模板版本，處理特殊類型的參數。
```c
template <typename T>
void print(T value); // 泛型版本

void print(int value); // 非模板版本，專門處理 int
```
### 範例：函數模板重載
```cpp
#include <iostream>
using namespace std;

template <typename T>
void print(T value) {
    cout << "模板函數： " << value << endl;
}

template <typename T, typename U>
void print(T value1, U value2) {
    cout << "模板函數 (兩個參數)： " << value1 << " 和 " << value2 << endl;
}

int main() {
    print(10);             // 調用單參數模板函數
    print(10, 3.14);       // 調用雙參數模板函數
    return 0;
}
/*
輸出結果
模板函數： 10
模板函數 (兩個參數)： 10 和 3.14
*/
```
### 範例：模板與非模板函數重載
```c
#include <iostream>
using namespace std;

// 泛型模板函數
template <typename T>
void print(T value) {
    cout << "模板函數： " << value << endl;
}

// 非模板函數
void print(int value) {
    cout << "非模板函數： " << value << endl;
}

int main() {
    print(10);         // 調用非模板函數 (更具體)
    print(3.14);       // 調用模板函數
    return 0;
}
/*
輸出結果
非模板函數： 10
模板函數： 3.14
*/
```
