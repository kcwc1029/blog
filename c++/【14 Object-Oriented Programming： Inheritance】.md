## Base Classes and Derived Classes

- 繼承是一種軟體重用的形式，通過創建新類別（衍生類別），吸收現有類別（基礎類別）的數據和行為，並添加新功能。
	- 基礎類別（Base Class）：提供基本數據和行為的類別。
	- 衍生類別（Derived Class）：從基礎類別繼承，並進一步擴展其功能。
- 繼承關係形成「類別階層（Class Hierarchy）」。
- 基礎類別位於階層的頂部，衍生類別位於底部，並可以建立多層級結構。
### 繼承的關係
- 「is-a」關係：
    - 表示繼承關係。
    - 衍生類別的物件同時可以被視為其基礎類別的物件。
    - 例：「一位研究生（GraduateStudent）**是**一名學生（Student）」。
- 「has-a」關係：
    - 表示組合關係（composition），非繼承。
    - 例：「一個車輛擁有引擎」而不是「車輛是引擎」。
### 繼承的類型
- 單一繼承（Single Inheritance）：衍生類別只能從一個基礎類別繼承。
- 多重繼承（Multiple Inheritance）：
    - 衍生類別可以同時繼承多個基礎類別的特性（例如 AdministratorTeacher 同時是 Administrator 和 Teacher）。
    - 需要處理潛在的衝突。

### 案例分析
#### 通用類別與專業化類別
![upgit_20241203_1733191121.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241203_1733191121.png)

- 基礎類別： Student、Shape、Loan、Employee、Account。
- 衍生類別：
    - GraduateStudent 是 Student 的衍生類別。
    - Circle 是 Shape 的衍生類別。

#### 大學社群成員（CommunityMember）階層
![upgit_20241203_1733191198.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241203_1733191198.png)

- 五層結構：
    - CommunityMember（頂層基礎類別）。
    - 員工（Employee）、學生（Student）、校友（Alumnus）。
    - 員工進一步分為教職員（Faculty）和職員（Staff）。
    - 教職員分為管理員（Administrator）和教師（Teacher）。
    - 部分管理員兼任教師，形成多重繼承類別 AdministratorTeacher。
- 範例關係：
    - 「一名 Teacher 是 Faculty，是 Employee，也是 CommunityMember」。
#### 幾何形狀（Shape）階層
![upgit_20241203_1733191229.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241203_1733191229.png)
- 基礎類別：Shape。
- 第二層：TwoDimensionalShape 和 ThreeDimensionalShape。
- 第三層：
    - TwoDimensionalShape 衍生出 Circle、Square、Triangle。
    - ThreeDimensionalShape 衍生出 Sphere、Cube、Tetrahedron。
- 範例關係：
    - 「一個 Cube 是 ThreeDimensionalShape，也是 Shape」。
## Relationship between Base and Derived Classes
- 繼承是一種軟體重用形式，允許衍生類別吸收基類的資料與行為，並擴展新功能。
- 基類 (Base Class)：提供共用功能的類別。
- 衍生類別 (Derived Class)：基於基類創建，更專門化的類別。
- 單一繼承與多重繼承：
    - 單一繼承：從一個基類繼承。
    - 多重繼承：同時繼承多個基類。

### 繼承中的訪問控制
- **`private`**：
    - 僅基類內部可訪問，衍生類無法直接使用。
    - 需透過 `get`/`set` 函數操作。
- **`protected`**：
    - 衍生類可直接訪問基類的受保護成員。
    - 優點：提高性能，減少函數調用開銷。
    - 缺點：基類變更時，可能導致衍生類失效。
- **`public`**：
    - 繼承後，基類的公有成員仍保持公有。

#### 基類成員的可見性規則
![upgit_20241203_1733193058.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241203_1733193058.png)

### 範例 1：Public 繼承
```c
#include <iostream>
using namespace std;

class Base {
public:
    void show() { cout << "Base class: public member" << endl; }
protected:
    void protectedFunc() { cout << "Base class: protected member" << endl; }
};

class Derived : public Base {
public:
    void display() {
        show();            // 繼承的 public 成員，保持 public
        protectedFunc();   // 繼承的 protected 成員，保持 protected
    }
};

int main() {
    Derived obj;
    obj.show();           // 可存取
    // obj.protectedFunc(); // 無法直接存取
    obj.display();
    return 0;
}
```

### 範例 2：
```c
#include <iostream>
using namespace std;

class Base {
public:
    void show() { cout << "Base class: public member" << endl; }
protected:
    void protectedFunc() { cout << "Base class: protected member" << endl; }
};

class Derived : private Base {
public:
    void display() {
        show();            // 繼承的 public 成員，變為 private
        protectedFunc();   // 繼承的 protected 成員，變為 private
    }
};

int main() {
    Derived obj;
    // obj.show();           // 無法存取
    obj.display();
    return 0;
}
```

### 範例 3：基類與衍生類的簡單應用
- 動物類別的繼承層次
```c
#include <iostream>
#include <string>
using namespace std;

// 基類：Animal
class Animal {
public:
    Animal(const string &name, int age) : name(name), age(age) {}
    void speak() const { cout << name << " 發出了聲音！" << endl; }
    void displayInfo() const {
        cout << "名稱: " << name << ", 年齡: " << age << " 歲" << endl;
    }
protected:
    string name;
    int age;
};

// 衍生類：Dog
class Dog : public Animal {
public:
    Dog(const string &name, int age, const string &breed)
        : Animal(name, age), breed(breed) {}
    void speak() const { cout << name << " 汪汪叫！" << endl; }
    void fetch() const { cout << name << " 正在撿球！" << endl; }
    void displayInfo() const {
        Animal::displayInfo(); // 呼叫基類方法
        cout << "品種: " << breed << endl;
    }
private:
    string breed;
};

// 衍生類：Cat
class Cat : public Animal {
public:
    Cat(const string &name, int age, const string &color)
        : Animal(name, age), color(color) {}
    void speak() const { cout << name << " 喵喵叫！" << endl; }
    void climb() const { cout << name << " 正在爬樹！" << endl; }
    void displayInfo() const {
        Animal::displayInfo(); // 呼叫基類方法
        cout << "毛色: " << color << endl;
    }
private:
    string color;
};

// 測試代碼
int main() {
    Dog dog("小黑", 3, "黃金獵犬");
    Cat cat("小花", 2, "白色");

    cout << "狗的資訊:" << endl;
    dog.displayInfo();
    dog.speak();
    dog.fetch();

    cout << "\n貓的資訊:" << endl;
    cat.displayInfo();
    cat.speak();
    cat.climb();
    return 0;
}
/*
輸出結果
狗的資訊:
名稱: 小黑, 年齡: 3 歲
品種: 黃金獵犬
小黑 汪汪叫！
小黑 正在撿球！

貓的資訊:
名稱: 小花, 年齡: 2 歲
毛色: 白色
小花 喵喵叫！
小花 正在爬樹！
*/
```
### 範例 4：使用 protected 的衍生類
- 圖形類別的繼承層次
```c
#include <iostream>
#include <cmath>
using namespace std;

// 基類：Shape
class Shape {
public:
    Shape(double dimension1, double dimension2) 
        : dimension1(dimension1), dimension2(dimension2) {}
    virtual double area() const = 0; // 純虛函數
    virtual void display() const = 0; // 純虛函數
protected:
    double dimension1, dimension2; // 受保護數據
};

// 衍生類：Rectangle
class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : Shape(width, height) {}
    double area() const override {
        return dimension1 * dimension2; // 寬 × 高
    }
    void display() const override {
        cout << "矩形，寬: " << dimension1 << ", 高: " << dimension2
             << ", 面積: " << area() << endl;
    }
};

// 衍生類：Circle
class Circle : public Shape {
public:
    Circle(double radius) : Shape(radius, 0) {}
    double area() const override {
        return M_PI * dimension1 * dimension1; // π × 半徑²
    }
    void display() const override {
        cout << "圓形，半徑: " << dimension1 
             << ", 面積: " << area() << endl;
    }
};

// 測試代碼
int main() {
    Rectangle rect(5, 3);
    Circle circ(4);
    rect.display();
    circ.display();
    return 0;
}
/*
輸出結果
矩形，寬: 5, 高: 3, 面積: 15
圓形，半徑: 4, 面積: 50.2655
*/
```
### 範例 5：多重繼承的應用
- 主題：多重角色的繼承
```c
#include <iostream>
using namespace std;

// 基類：Teacher
class Teacher {
public:
    Teacher(const string &name) : name(name) {}
    void teach() const { cout << name << " 正在教課！" << endl; }
protected:
    string name;
};

// 基類：Administrator
class Administrator {
public:
    Administrator(const string &department) : department(department) {}
    void manage() const { cout << "管理部門: " << department << endl; }
protected:
    string department;
};

// 衍生類：AdministratorTeacher
class AdministratorTeacher : public Teacher, public Administrator {
public:
    AdministratorTeacher(const string &name, const string &department)
        : Teacher(name), Administrator(department) {}
    void displayRoles() const {
        cout << "名字: " << name << endl;
        manage();
        teach();
    }
};

// 測試代碼
int main() {
    AdministratorTeacher person("王老師", "教務處");
    person.displayRoles();
    return 0;
}
/*
輸出結果
名字: 王老師
管理部門: 教務處
王老師 正在教課！
*/
```
## Constructors and Destructors in Derived Classes
### 建構函數的執行順序
- 當衍生類別物件被實例化時：
    1. 先執行基類的建構函數，再執行衍生類的建構函數。
    2. 若基類本身也是從其他類別繼承，基類的建構函數需呼叫其上層類別的建構函數，以此類推。
    3. 最底層的基類建構函數最早執行，衍生類建構函數最後執行。
### 解構函數的執行順序
- 當衍生類別物件被銷毀時：
    1. 先執行衍生類的解構函數，接著執行基類的解構函數，以此類推。
    2. 解構函數的執行順序與建構函數相反，最底層的基類解構函數最後執行。
    3. 最後物件會從記憶體中移除。
### 基類建構函數與解構函數的特性
- 基類的建構函數、解構函數與重載的賦值運算子不會被繼承。
- 衍生類別可以呼叫基類的建構函數或解構函數。

### 範例 1：建構函數與解構函數執行順序

```cpp
#include <iostream>
using namespace std;

// 基類
class Base {
public:
    Base() { cout << "執行基類建構函數" << endl; }
    ~Base() { cout << "執行基類解構函數" << endl; }
};

// 衍生類
class Derived : public Base {
public:
    Derived() { cout << "執行衍生類建構函數" << endl; }
    ~Derived() { cout << "執行衍生類解構函數" << endl; }
};

int main() {
    cout << "創建衍生類物件:" << endl;
    Derived obj;
    cout << "銷毀衍生類物件:" << endl;
    return 0;
}
/*
執行結果
創建衍生類物件:
執行基類建構函數
執行衍生類建構函數
銷毀衍生類物件:
執行衍生類解構函數
執行基類解構函數
*/
```
### 範例 2：C++11 繼承基類建構函數
```c
#include <iostream>
using namespace std;

// 基類
class Base {
public:
    Base(int x) { cout << "基類建構函數被呼叫，x = " << x << endl; }
};

// 衍生類
class Derived : public Base {
public:
    using Base::Base;  // 繼承基類建構函數
};

int main() {
    Derived obj(42);  // 呼叫基類的建構函數
    return 0;
}
/*
執行結果
基類建構函數被呼叫，x = 42
*/
```