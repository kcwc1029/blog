- 這一章節，我整理起來內容量比較少，學長在做PPT時可以在較GPT多生一些範例。

## Relationships Among Objects in an Inheritance Hierarchy
- 對於衍生類的物件，雖然它們的型別不同，但因為每個衍生類物件也是基類的一部分，編譯器允許這種行為。
- 基類指標可以指向基類物件，也可以指向衍生類物件。這使得我們能夠通過基類指標或引用操作衍生類的物件。
- 限制條件：
	- 基類物件無法視為衍生類物件
- 利用繼承層次結構和多型，我們可以設計具有高可擴展性的系統，允許以基類的方式統一操作不同的衍生類物件。
## Invoking Base-Class Functions from Derived-Class Objects
### 基類指標與基類物件
- 基類指標用來操作基類物件。
- 你可以用基類的指標來呼叫基類的成員函式。
```c
CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000, 0.06);
CommissionEmployee* commissionEmployeePtr = &commissionEmployee;  // 基類指標指向基類物件
commissionEmployeePtr->print();  // 呼叫基類版本的 print 函式

//  基類指標 commissionEmployeePtr 可以正常操作基類物件 commissionEmployee 並執行 CommissionEmployee 的 print 函式。
```
### 衍生類指標與衍生類物件
- 衍生類指標可以操作衍生類物件，並呼叫衍生類的函式。
```c
BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);
BasePlusCommissionEmployee* basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;  // 衍生類指標指向衍生類物件
basePlusCommissionEmployeePtr->print();  // 呼叫衍生類版本的 print 函式
```
### 基類指標操作衍生類物件
- 允許行為： 可以將衍生類物件的地址賦值給基類指標，因為衍生類物件也是基類物件的一部分（繼承的 is-a 關係）。
- 使用基類指標時，只能呼叫基類中定義的函式，無法直接使用衍生類新增的函式。
```c
CommissionEmployee* commissionEmployeePtr = &basePlusCommissionEmployee;  // 基類指標指向衍生類物件
commissionEmployeePtr->print();  // 呼叫基類版本的 print 函式
```
## Aiming Derived-Class Pointers at Base-Class Objects
- 禁止行為：嘗試將 **基類物件的地址** 賦值給 **衍生類指標** 是無效的，會導致編譯錯誤。
	- 基類物件只是基類的實例，並不包含衍生類中新增的屬性或行為。
	- 繼承的方向是單向的 (is-a)：衍生類是基類的一種，但基類不是衍生類的一種。
- 錯誤範例
```c
CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000, 0.06);
BasePlusCommissionEmployee* basePlusCommissionEmployeePtr = nullptr;

basePlusCommissionEmployeePtr = &commissionEmployee;  // 編譯錯誤

// CommissionEmployee 並不包含 BasePlusCommissionEmployee 中定義的額外成員，因此無法進行這種轉換。
```
## Derived-Class Member-Function Calls via Base-Class Pointers
- 基類指標可以操作基類成員函式，即使該指標實際指向的是衍生類物件。
```c
commissionEmployeePtr->getFirstName();
commissionEmployeePtr->getLastName();
// 這些函式在基類 CommissionEmployee 中已定義，故可以正常呼叫。
```
- 禁止操作：基類指標無法呼叫 僅在衍生類中定義的成員函式。
```c
commissionEmployeePtr->getBaseSalary();  // 錯誤：編譯器報錯
commissionEmployeePtr->setBaseSalary(500);  // 錯誤：編譯器報錯
```
## Virtual Functions and Virtual Destructors
### 靜態綁定與動態綁定
#### 靜態綁定 (Static Binding)
- 靜態綁定是在編譯時就決定了「哪個函式會被呼叫」。這種情況通常發生在：
	- 直接用物件名稱呼叫函式。
	- 編譯器可以直接確定物件的類型。
- 日常例子：假設我們有一個「形狀」類別 (Shape) 和它的子類別「圓形」(Circle)。當我們直接用物件的名稱呼叫函式時，編譯器知道這是一個 `Circle`，所以直接呼叫 `Circle` 的函式。
```c
class Shape {
public:
    void draw() const {
        cout << "畫一個形狀\n";
    }
};

class Circle : public Shape {
public:
    void draw() const {
        cout << "畫一個圓形\n";
    }
};

int main() {
    Circle circle;  // 直接創建一個圓形物件
    circle.draw();  // 編譯時已確定要呼叫 Circle 的 draw()
}
```
#### 動態綁定 (Dynamic Binding)
- 動態綁定則是在執行時才決定「哪個函式會被呼叫」。這種情況通常發生在：
	- 基類指標或基類參考指向衍生類物件時。
	- 使用了虛函式 (virtual function)。
- 日常例子：我們希望用「基類指標」來指向不同的物件，並讓程式自動決定要執行哪個版本的函式。例如，我們用一個指標處理 Shape、Circle 和 Triangle。
```c
class Shape {
public:
    virtual void draw() const {  // 基類虛函式
        cout << "畫一個形狀\n";
    }
};

class Circle : public Shape {
public:
    void draw() const override {  // 覆寫基類函式
        cout << "畫一個圓形\n";
    }
};

class Triangle : public Shape {
public:
    void draw() const override {  // 覆寫基類函式
        cout << "畫一個三角形\n";
    }
};

int main() {
    Shape* shapePtr = new Circle();  // 基類指標指向圓形物件
    shapePtr->draw();  // 執行時決定要呼叫 Circle 的 draw()
    
    shapePtr = new Triangle();  // 基類指標指向三角形物件
    shapePtr->draw();  // 執行時決定要呼叫 Triangle 的 draw()
}
/*
輸出結果
畫一個圓形
畫一個三角形
*/
```
### 虛擬函式 (virtual function)
- 虛擬函式的目的就是讓程式在「執行時」根據物件的實際類別，正確地呼叫對應的函式。
- 想像有一個「畫圖工具」，我們希望它能畫圓形 (Circle)、三角形 (Triangle) 和矩形 (Rectangle)。  
	- 每個形狀有自己的畫法，但我們只想用「基類」(Shape) 來處理，而不需要特別寫「如果是圓形就呼叫畫圓形」這種程式。
	- 解決方法：把 `draw()` 定義為基類的「虛函式」，然後在每個形狀類別中「覆寫」這個函式。程式在執行時會自動選擇正確的函式。
	- 如果沒有虛擬函式，程式只會呼叫基類的 `draw()`，不會執行到衍生類的版本。
```cpp
class Shape {  // 基類：所有形狀的父類別
public:
    virtual void draw() const {  // 虛函式
        cout << "畫一個形狀\n";
    }
};

class Circle : public Shape {  // 圓形類別
public:
    void draw() const override {  // 覆寫 draw()
        cout << "畫一個圓形\n";
    }
};

class Triangle : public Shape {  // 三角形類別
public:
    void draw() const override {  // 覆寫 draw()
        cout << "畫一個三角形\n";
    }
};
```
- 實際呼叫：
```cpp
Shape* shapePtr = new Circle();  // 基類指標指向圓形物件
shapePtr->draw();  // 執行時會呼叫 Circle 的 draw()
// 輸出結果： `畫一個圓形`
```
### 為什麼需要虛擬解構函式？
- 當使用 `delete` 釋放指向衍生類物件的基類指標時，如果基類沒有虛擬解構函式，可能只會執行基類的解構函式，導致衍生類的資源沒有正確釋放，甚至出現記憶體洩漏。
- 錯誤示例：
```cpp
class Shape {
public:
    ~Shape() {  // 非虛解構函式
        cout << "Shape 解構\n";
    }
};

class Circle : public Shape {
public:
    ~Circle() {
        cout << "Circle 解構\n";
    }
};

Shape* shapePtr = new Circle();
delete shapePtr;  // 只呼叫 Shape 的解構函式

/*
輸出`Shape 解構  
問題：Circle 的解構函式沒有被呼叫，可能導致資源未釋放。
*/
```
- 正確做法：定義虛解構函式
```cpp
class Shape {
public:
    virtual ~Shape() {  // 虛解構函式
        cout << "Shape 解構\n";
    }
};

class Circle : public Shape {
public:
    ~Circle() {
        cout << "Circle 解構\n";
    }
};

Shape* shapePtr = new Circle();
delete shapePtr;  // 呼叫 Circle 和 Shape 的解構函式
/*
輸出：  
`Circle 解構`  
`Shape 解構`
*/
```
### C++11 中的 final
- final 函式： 防止衍生類覆寫某函式。
```cpp
class Shape {
public:
    virtual void draw() const final {  // 禁止覆寫
        cout << "畫一個形狀\n";
    }
};
```
- final 類別： 防止其他類別繼承這個類別。
```cpp
class Circle final {  // Circle 無法被繼承
public:
    void draw() const {
        cout << "畫一個圓形\n";
    }
};
```
## Abstract Classes and Pure virtual Functions
### 抽象類別？
- 抽象類別是一種「概念類別」，代表一些抽象的東西，**不能直接用來創建物件**。
- 它的作用是讓其他類別繼承，並實現具體的行為。
- 舉例：
	- 假設我們要模擬「動物」(Animal)，動物可以叫聲 (makeSound)，但不同動物的叫聲不一樣。
	- 因為「動物」這個概念太抽象，我們不能直接創建一個「動物」，但我們可以定義「動物」類別，讓「狗」(Dog) 和「貓」(Cat) 繼承它，並具體實現叫聲的功能。
```cpp
class Animal {  // 抽象類別
public:
    virtual void makeSound() const = 0;  // 純虛函式
};

class Dog : public Animal {  // 衍生類別
public:
    void makeSound() const override {
        cout << "汪汪汪\n";
    }
};

class Cat : public Animal {  // 衍生類別
public:
    void makeSound() const override {
        cout << "喵喵喵\n";
    }
};

// 使用
Animal* animal = new Dog();
animal->makeSound();  // 輸出：汪汪汪

animal = new Cat();
animal->makeSound();  // 輸出：喵喵喵
```
### 純虛擬函式是什麼？

|**虛函式 (Virtual Function)**|**純虛函式 (Pure Virtual Function)**|
|---|---|
|可以有預設實作|沒有實作，子類別必須實作|
|衍生類別可選擇是否覆寫|衍生類別一定要覆寫，否則子類別仍是抽象類別|
|例子：`virtual void draw();`|例子：`virtual void draw() = 0;`|

- 純虛函式是一個沒有實作的函式，定義在抽象類別中。
- **語法：** `virtual void functionName() const = 0;`
- 子類別**必須實現純虛函式**，否則子類別本身也是抽象類別。
- 舉例：
	- 假設有一個「形狀」(Shape) 的類別，每種形狀都需要實現 `draw()`，但基類不知道具體要怎麼畫，所以把 `draw()` 定義為純虛函式。
```cpp
class Shape {  // 抽象基類
public:
    virtual void draw() const = 0;  // 純虛函式
};

class Circle : public Shape {  // 衍生類別
public:
    void draw() const override {
        cout << "畫一個圓形\n";
    }
};

class Rectangle : public Shape {  // 衍生類別
public:
    void draw() const override {
        cout << "畫一個矩形\n";
    }
};

// 使用：
Shape* shape = new Circle();
shape->draw();  // 輸出：畫一個圓形

shape = new Rectangle();
shape->draw();  // 輸出：畫一個矩形
```


幫我整理幫我整理中文重點筆記(我要放PPT)

原內容有點分散，你可以針對內容進行統整
過於重複(或是攏言贅字)可以精簡濃縮
內容不足之處可以補全，使內容更完整，讓學生可以一次學懂



















































