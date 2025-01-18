## 程式語言分類
- procedural programming: 
    - It is a list of instruction in a single block.
    - suitable for small program
- Modular Programming :
    - In this procedural program is divided into functions & each function has a clear purpose.

## OOP example
```cpp
//class
class house{
private :
    //member variables
	int length = 0, breadth = 0;
public :
	//member functions
	void setData(int x, int y){
		length = x;
		breadth = y;
	}

	void area(){
		cout << "Area of house " << length * breadth;
	}
};

int main(){
	house gini;
	gini.setData(300, 500);
	gini.area();
	return 0;
}
```

## access specifiers

|           | Class1 | Class2(繼承Class1) | other class  |
| --------- | ------ | ---------------- | ------------ |
| private   | int x  | can't access     | can't access |
| protected | int y  | y = 10;          | can't access |
| public    | int z  | z = 20;          | z = 20;      |

## OOP's Characteristicts
- **Abstraction** - 抽象
- **Encapsulation** - 封裝
	- wrapping up variables and methods in class.
	- It help in data hiding.
- **Polymorphism** - 多型
	- Polymorphism means having many forms.
    - In class method may behave differently, depending on the inputs. function overloading.
- **Inheritance** - 繼承
	- **Inheritance** means property of a child class to inherit characteristic of parent class.
    - like: Dog, Cat, Cow Class inherit from

## 以ATM為例
- Check Balance
- Cash WithDraw
- User Details
- Update Mobile No.
```cpp
#include <iostream>
#include <string>
#include <conio.h>  // 引入 _getch() 函數使用

using namespace std;

class ATM {
private:
    string account_no;  // 帳號 
    string name;        // 使用者姓名 
    string PIN;         // 使用者的帳戶 PIN 碼 (無法更改)
    double balance;     // 使用者帳戶餘額 
    string mobile_no;   // 使用者的手機號碼 

public:
    // 初始化設定使用者資料
    void setData(string account_No_a, string name_a, string PIN_a, double balance_a, string mobile_No_a) {
        account_no = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_No_a;
    }

    // 取得帳號資料
    string getAccountNo() { return account_no; }

    // 取得姓名
    string getName() { return name; }

    // 取得PIN
    string getPIN() { return PIN; }

    // 取得電話號碼
    string getMobileNo() { return mobile_no; }

    // 取得存款餘額
    double getBalance() { return balance; }

    // 修改手機號碼 (驗證舊手機號碼)
    void setMobile(string old_mobile_no, string new_mobile_no) {
        if (old_mobile_no == mobile_no) {
            mobile_no = new_mobile_no; // 更新手機號碼
            cout << "Successfully Updated Mobile No.\n";
        } else {
            cout << "Incorrect! Old Mobile No.\n";
        }
        _getch();  // 等待用戶按下任意鍵繼續（不顯示按下的字符）
    }

    // 提款功能
    void cashWithDraw(int money) {
        if (money > 0 && money <= balance) {
            balance -= money; // 扣除提款金額
            cout << "Please Collect Your Cash\n";
            cout << "Available Balance: " << balance << "\n";
        } else {
            cout << "Invalid Input or Insufficient Balance\n";
        }
        _getch();  // 等待用戶按下任意鍵繼續（不顯示按下的字符）
    }
};

//////////////////////////////////////////////////////////////////////////////////
// 主程式入口
int main() {
    int order = 0; 
    string enterAccountNo;
    string enterPIN;

    ATM user1;
    user1.setData("001", "TA1", "1111", 45000.90, "0978123123");

    while (true) {
        system("cls");  // 清空螢幕
        cout << "\n**** Welcome to ATM *****\n";
        cout << "Enter Your Account No: ";
        cin >> enterAccountNo;
        cout << "Enter PIN: ";
        cin >> enterPIN;

        if (enterAccountNo == user1.getAccountNo() && enterPIN == user1.getPIN()) {
            while (true) {
                int money = 0;
                string oldMobileNo, newMobileNo;

                system("cls");  // 清空螢幕

                // User Interface
                cout << "\n**** Welcome to ATM *****\n";
                cout << "Select Options\n";
                cout << "1. Check Balance\n";
                cout << "2. Cash Withdraw\n";
                cout << "3. Show User Details\n";
                cout << "4. Update Mobile No.\n";
                cout << "5. Exit\n";
                cout << "Enter Option: ";
                cin >> order;

                switch (order) {
                    case 1:
                        cout << "Your Bank Balance is: " << user1.getBalance() << "\n";
                        _getch();  // 等待用戶按下任意鍵繼續
                        break;
                    case 2:
                        cout << "Enter the Amount: ";
                        cin >> money;
                        user1.cashWithDraw(money);
                        break;
                    case 3:
                        cout << "*** User Details ***\n";
                        cout << "Account No: " << user1.getAccountNo() << "\n";
                        cout << "Name: " << user1.getName() << "\n";
                        cout << "Balance: $" << user1.getBalance() << "\n";
                        cout << "Mobile No: " << user1.getMobileNo() << "\n";
                        _getch();  // 等待用戶按下任意鍵繼續
                        break;
                    case 4:
                        cout << "Enter Old Mobile No: ";
                        cin >> oldMobileNo;
                        cout << "Enter New Mobile No: ";
                        cin >> newMobileNo;
                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;
                    case 5:
                        exit(0);  // 結束程式
                    default:
                        cout << "Enter Valid Option!\n";
                        _getch();  // 等待用戶按下任意鍵繼續
                        break;
                }
            }
        } else {
            cout << "Invalid Account No or PIN. Please Try Again.\n";
            _getch();  // 等待用戶按下任意鍵繼續
        }
    }
    return 0;
}
```


## OOP相關面試題
1. C 和 C++ 之間的差異是什麼？
- C 是程序式(procedural)編程語言，而 C++ 是程序式和面向對象(object-oriented)的編程語言。
- C++ 比 C 更加安全，因為它有數據隱藏(data hiding)的機制 - 我們有訪問控制符(access specifiers)(私有(private)、受保護(protected)、公共(public))。
- C++ 還提供了繼承(inheritance)、多態(polymorphism)、封裝(encapsulation)、抽象(abstraction)、運算符重載(operator overloading)、構造函數(constructors)等功能。

2. 什麼是 C++ 中的 `using namespace std`？
- `using namespace std;` 是一個指令，告訴編譯器我們將使用命名空間 `std` 中的所有成員。`std` 是 C++ 標準庫的命名空間，裡面包含了許多常用的函數、類別和對象，例如 `cout`、`cin`、`vector` 等。
- 通常在使用標準輸出流時，例如 `cout`，如果不使用 `using namespace std;`，需要寫成 `std::cout`。而加了 `using namespace std;` 之後，你就可以直接寫 `cout` 來輸出，不用每次都加上 `std::`。
![upgit_20241006_1728195794.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241006_1728195794.png)

3. 什麼是 C++ 中的 `iostream`？
-  `iostream` 是 C++ 中的一個標頭檔（header file），它包含了一些用於輸入和輸出的對象，例如 `cin` 和 `cout`。
	- **`cin`**：這是用來從輸入流中獲取數據的對象，通常用來從鍵盤讀取用戶輸入。
	- **`cout`**：這是用來將數據輸出到輸出流中的對象，通常用來在控制台上顯示訊息。

4. C++ 程式中最少需要多少個函數？
- C++ 中，一個最小的有效程式至少需要 **一個函數**，就是 `main()` 函數。

5. C++ 是面向對象的編程語言嗎？為什麼？
- 是的，C++ 是一種面向對象（Object-Oriented）的編程語言，因為它支持面向對象編程的四個主要特徵：**封裝（Encapsulation）**、**繼承（Inheritance）**、**多態（Polymorphism）** 和 **抽象（Abstraction）**。C++ 可以用類和對象來組織和管理代碼，這樣可以更好地模擬現實世界的事物，增強程序的重用性和可擴展性。

6. 什麼是類（Class）？
- **類（Class）** 是一種用戶自定義的數據類型，它包含了成員變數（Member Variables）和成員函數（Member Functions）。類實際上是對象的藍圖，描述了對象的屬性和行為。類本身並不佔用存儲空間，只有當我們使用類創建對象時，才會分配內存。

7. 什麼是對象（Object）？
- **對象（Object）** 是類的實例。對象是從類創建出來的，並且可以使用類的成員變數和函數。可以把類比作建築的藍圖，而對象就是根據這個藍圖建造出來的實際房子。因此，對象會佔用內存。

8. 從一個類可以創建多少個對象？
- 從一個類可以創建**無限多個對象**。只要有需要，你可以使用相同的類來創建多個對象，每個對象都是類的一個實例，並且擁有獨立的內存。

9. 面向對象編程（OOP）的特徵是什麼？
- **類（Class）**：類是對象的藍圖，它描述了一組具有相似屬性和行為的對象。
- **對象（Object）**：對象是類的實例，具有類的屬性和方法。
- **封裝（Encapsulation）**：將數據和方法綁定在一起，隱藏內部實現細節。
- **數據隱藏（Data Hiding）**：通過訪問控制符來控制對類中成員的訪問。
- **抽象（Abstraction）**：隱藏對象的複雜實現，僅對外暴露必要的部分。
- **繼承（Inheritance）**：一個類可以繼承另一個類的屬性和方法。
- **多態（Polymorphism）**：允許對象以多種形態出現，例如函數重載和重寫。

10. 什麼是封裝（Encapsulation）？
- 封裝是將變數和函數綁定在一起的過程，用於將數據保護起來，防止外部直接訪問。這樣可以確保數據安全，只允許特定的方法來訪問和修改數據。

11. 什麼是抽象（Abstraction）？
- 抽象是在不顯示對象的內部實現的情況下，僅顯示對象的必要部分。這有助於簡化複雜系統。例如，ATM 機可以讓用戶取款，而不需要知道機器內部的實現細節。

12. 什麼是繼承（Inheritance）？
- 繼承是類之間的一種關係，一個類可以繼承另一個類的屬性和行為。被繼承的類稱為父類（Parent Class），繼承的類稱為子類（Child Class）。這使得子類可以重用父類的代碼，並添加自己特有的功能。

13. 繼承有哪幾種類型？
- **單繼承（Simple Inheritance）**：一個子類繼承一個父類。
- **多級繼承（Multilevel Inheritance）**：一個子類繼承自一個父類，該父類又繼承自另一個類。
- **層次繼承（Hierarchical Inheritance）**：多個子類繼承自同一個父類。
- **多重繼承（Multiple Inheritance）**：一個子類繼承多個父類。
- **多路徑繼承（Multipath Inheritance）**：多重繼承的變種，可能會導致重複繼承同一個基類的問題。

14. 什麼是 C++ 中的菱形問題（Diamond Problem）？
- 菱形問題出現在多重繼承中，當一個類同時繼承兩個來自相同父類的子類時，會導致繼承鏈重複。為了解決這個問題，我們可以使用 `virtual` 關鍵字來使基類成為虛擬基類，這樣可以防止多次繼承同一基類的屬性。
```cpp
void test(int x) {
    cout << "Integer: " << x << endl;
}

void test(float x) {
    cout << "Float: " << x << endl;
}
```

15. 什麼是函數重載（Function Overloading）？
- 函數重載是指在同一個作用域內可以有多個名稱相同但參數不同的函數。這些參數可以是類型不同或者數量不同。編譯器通過函數的參數來區分它們。
```cpp
class Base {
public:
    virtual void display() {
        cout << "Base class display" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived class display" << endl;
    }
};
```
16. 什麼是多態性（Polymorphism）？
- 多態性（Polymorphism）是指同一個函數名稱可以具有多種不同的功能，根據不同的上下文表現出不同的行為。這使得我們可以用同樣的接口來實現不同的功能。
- C++ 中的多態性有兩種主要形式：
	- **函數重載（Function Overloading）**：多個函數具有相同名稱但參數不同，可以根據參數來區分。
	- **函數重寫（Function Overriding）**：子類重新定義父類中的方法，使得通過父類引用調用時會執行子類中的實現。

17. 多態性有哪幾種類型？
- 多態性可以分為兩種類型：
	1. **運行時多態性（Runtime Polymorphism）**：
	    - 又稱為動態多態性，是在運行時決定要調用哪個函數。主要通過虛函數（virtual function）和函數重寫來實現。
	    - 例如：函數重寫（Function Overriding）。
	2. **編譯時多態性（Compile Time Polymorphism）**：
	    - 又稱為靜態多態性，是在編譯時就決定了要調用哪個函數。主要通過函數重載和運算符重載來實現。
	    - 例如：函數重載（Function Overloading）或運算符重載（Operator Overloading）。

18. 什麼是內聯函數（Inline Function）？
- C++ 提供內聯函數（inline function）來減少函數調用的開銷。當我們將一個函數定義為內聯函數時，編譯器會在編譯時用函數體代替函數調用，從而省去調用的開銷。
- 這樣做的好處是減少了函數調用的成本，但如果函數體過大，內聯反而可能導致代碼膨脹。
```cpp
inline void function(int x) {
    cout << x;
}
```
19. 什麼是訪問控制符（Access Specifiers）及其特性？
- 訪問控制符在 C++ 中用來控制類成員的訪問權限。主要有三種訪問控制符：
	1. **Public**：公共成員可以從類的外部訪問。
	2. **Protected**：保護成員不能從類外部訪問，但可以在子類中訪問。
	3. **Private**：私有成員不能從類的外部訪問，僅能被類內部的方法訪問。

20. 什麼是靜態成員變數（Static Member Variable）？
- 靜態成員變數屬於整個類，而不是某個對象。靜態成員變數只在內存中分配一次，並且所有對象共享這塊內存。
```cpp
// `stat` 是靜態變數，所有 `Alpha` 類的對象共享該變數。
class Alpha {
    static int stat;
};
```
21. 什麼是構造函數（Constructor），為什麼使用它？
- 構造函數是一種特殊的方法，在創建對象時自動調用，用於初始化對象。構造函數的名稱與類名相同，且沒有返回類型。它可以用來設置對象的初始值。

22. 什麼是複製構造函數（Copy Constructor）？
- 複製構造函數用於通過已有的對象來初始化新的對象。這種操作通常用於對象複製。
```cpp
Obj_2(Obj_1); // 使用 Obj_1 來初始化 Obj_2
```
23. `delete` 和 `delete[]` 的區別是什麼？
- **`delete`**：釋放單個動態分配的對象的內存。
- **`delete[]`**：釋放動態分配的數組的內存。

24. 什麼是虛函數（Virtual Function）？
- 虛函數是基類中用 `virtual` 關鍵字聲明的成員函數，可以在派生類中被重寫（override）。使用虛函數可以實現多態性，通過基類指針調用子類的實現。
```cpp
class Base {
public:
    virtual void show() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class" << endl;
    }
};
```
25. 什麼是泛型編程語言(generic programming language)？
- Generic programming是一種泛型編程技術，使用者可以使用同一組代碼處理不同的數據類型。C++支持泛型編程，因為它有模板（templates）和標準模板庫（STL）。模板函數與模板類允許開發者寫出對任意數據類型都能工作的代碼。

26. 什麼是STL，你可以列舉一些 STL 中的容器嗎？
- STL（Standard Template Library，標準模板庫）是C++中泛型編程的一部分，它包含了一些已經實現的資料結構和演算法的集合。STL由三個主要組件構成：
	1. **Container（容器）**：儲存數據。
	2. **Algorithm（算法）**：對儲存在容器中的數據進行操作。
	3. **Iterator（迭代器）**：類似指標，用於遍歷容器中的元素。
- STL 中包含以下容器：
	1. **陣列（Array）**
	2. **向量（Vector）**
	3. **鏈表（List）**
	4. **堆疊（Stack）**
	5. **佇列（Queue）**
	6. **優先佇列（Priority Queue）**
	7. **映射（Map）**
	8. **集合（Set）**
27. `array`和`vector`有什麼區別？
- **array**：具有固定大小，運行時無法擴展。
- **vector**：動態數組，大小可以在運行時自動擴展。

28. 什麼是模板？為什麼要使用模板？
- 模板是一個泛型的代碼塊，可以幫助我們減少函數重載。使用模板可以用相同的代碼處理不同類型的變數，例如模板函數可以同時處理整數和浮點數的比較。