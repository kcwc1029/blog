## Structure Definitions
- 結構提供一種方法將相關聯的數據聚合在一起，適合用於管理複雜數據。
- 結構的靈活性支持多型別成員與遞歸指標，成為構建高效資料結構 (如鏈結串列、樹等) 的基礎。
### 結構 (Structures) 的基本概念
- Structures是一種衍生資料型別，由多個其他型別的物件組成，能夠將多個相關的資料打包成一個單元。
```c
struct card {
	char *face;
	char *suit;
};
// `struct` 是關鍵字，用於宣告結構型別。
// `card` 是結構的標籤名稱 (Tag)，用於標識該結構型別。
// 成員變數 `face` 和 `suit` 是指標類型，分別代表撲克牌的點數與花色。
```
### 結構的成員 (Members)
- 定義在結構的 `{}` 大括號內。  
- 同一結構內的成員名稱必須唯一，但不同結構可以有相同名稱，且互不衝突。  
- 成員可以是基礎型別 (如 int, float)、陣列、其他結構，甚至是指向其他結構的指標。
```c
struct employee {
	char firstName[20];  // 姓名
	unsigned int age;   // 年齡
	double hourlySalary;// 時薪
};
```
#### 範例：struct結構定義與使用
```c
#include <stdio.h>

// 定義結構
struct point {
    int x;
    int y;
};

int main() {
    struct point p1;       // 宣告結構變數
    p1.x = 10;             // 設定成員值
    p1.y = 20;

    printf("Point: (%d, %d)\n", p1.x, p1.y); // 輸出結構成員
    return 0;
}
```
### 結構定義與變數宣告
- 結構定義不會分配記憶體空間，只是建立一個新型別。
- 可以在結構定義外部或內部進行。
- 單獨宣告：  
```c
struct card aCard; // 單一變數
struct card deck[52]; // 陣列
struct card *cardPtr; // 指標
```
- 結合宣告：  
```c
struct card {
	char *face;
	char *suit;
} aCard, deck[52], *cardPtr; // 直接在定義中聲明變數
```
### 結構的操作
- 賦值：結構變數之間可以直接賦值，但需為相同型別。
- 取地址：使用 `&` 取結構變數的地址。
- 存取成員：透過 `.` 存取普通結構成員，或透過 `->` 存取指標結構成員。
- sizeof 操作：計算結構變數的大小。
- 不允許操作：不能直接使用 `==` 或 `!=` 比較結構，因為結構內成員可能存放於非連續的記憶體中，且可能含有未定義的記憶體「洞」。
## Initializing Structures
- 結構可以像陣列一樣使用初始化器列表進行初始化。
```c
struct card aCard = {"Three", "Hearts"};
// 初始化 aCard 的 face 成員為 "Three"，suit 成員為 "Hearts"
```
- 如果初始化列表中的項目數少於結構成員數，剩餘成員會被自動初始化：
	- 數值型成員：初始化為 0。
	- 指標型成員：初始化為 NULL。

### 賦值方式
- 直接賦值整個結構變數：可將一個結構變數賦值給同型別的另一個結構變數。
```c
struct card anotherCard = aCard;
```
- 逐一賦值給結構成員：可分別對結構的各個成員進行賦值。
```c
aCard.face = "Four";
aCard.suit = "Spades";
```

## Accessing Structure Members
- 結構成員運算子 (.)：
	- 用於透過結構變數名稱存取成員。
	- 適用於直接操作結構變數。
- 結構指標運算子 (->)：
	- 用於透過指向結構的指標存取成員。
	- 適用於操作指向結構的指標。
```c
printf("%s", aCard.suit); // 顯示 "Hearts"
printf("%s", cardPtr->suit); // 顯示 "Hearts"
```
- 綜合範例：
```c
struct card aCard;
aCard.face = "Ace";         // 使用結構成員運算子
aCard.suit = "Spades";

struct card *cardPtr = &aCard; // 指標指向 aCard
printf("%s", cardPtr->face);   // 使用結構指標運算子
printf("%s", (*cardPtr).suit); // 解參考後使用結構成員運算子
```
## Using Structures with Functions
### 傳遞方式的特性
- Pass by Value：
	- 傳遞單一成員或整個結構時，皆以值的形式傳遞。
	- 被調用的函數無法修改原結構變數或其成員。
- Pass by Address：
	- 若需修改原結構變數或成員，應傳遞結構的地址。
```c
void modifyStruct(struct card *ptr) {
    ptr->face = "King"; // 修改原結構的成員
}

int main() {
    struct card aCard = {"Queen", "Hearts"};
    modifyStruct(&aCard); // 傳遞結構的地址
}
```
### 範例：結構與函數搭配
```c
#include <stdio.h>

// 定義結構
typedef struct {
    int x;
    int y;
} Point;

// 定義函數：修改結構成員
void updatePoint(Point *p, int newX, int newY) {
    p->x = newX;
    p->y = newY;
}

int main() {
    Point p = {5, 10}; // 初始化結構變數
    printf("Before Update: (%d, %d)\n", p.x, p.y);

    updatePoint(&p, 20, 30); // 傳址修改結構內容
    printf("After Update: (%d, %d)\n", p.x, p.y);
    return 0;
}
```
### 範例：結構陣列的應用
```c
#include <stdio.h>

// 定義結構
typedef struct {
    char name[20];
    int age;
} Student;

int main() {
    Student students[3] = { // 初始化結構陣列
        {"Alice", 20},
        {"Bob", 22},
        {"Charlie", 19}
    };

    for (int i = 0; i < 3; i++) {
        printf("Student %d: %s, Age: %d\n", i + 1, students[i].name, students[i].age);
    }
    return 0;
}
```


### 自參考結構 (Self-Referential Structures)
- 自參考結構是構建鏈結資料結構 (如鏈結串列) 的基礎。
- 結構中不能包含自己的實例，但可以包含指向自己型別的指標。  
```c
struct employee2 {
	char firstName[20];
	struct employee2 person;   // 錯誤：不能包含自己的實例
	struct employee2 *ePtr;    // 合法：指向自己的指標
};
```
#### 範例：自參考結構的應用
```c
// 學習如何使用自參考結構來構建鏈結串列。
#include <stdio.h>
#include <stdlib.h>

// 定義結構：鏈結串列節點
typedef struct node {
    int data;
    struct node *next; // 指向下一個節點的指標
} Node;

// 函數：建立新節點
Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 函數：列印鏈結串列
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = createNode(10); // 建立頭節點
    head->next = createNode(20); // 第二個節點
    head->next->next = createNode(30); // 第三個節點

    printList(head); // 列印鏈結串列

    return 0;
}
```
## typedef
- typedef 提供為現有資料型別創建別名 (alias) 的機制。
- 優點：
	- 簡化型別名稱，使程式更具可讀性。
	- 提高程式可攜性。
- 定義結構型別別名：
```c
typedef struct card Card; // 定義 Card 作為 struct card 的別名。

// 定義後，可直接使用 Card 宣告變數
Card deck[52]; // 定義包含 52 個 Card 結構的陣列
```
- 使用 typedef 可省略結構標籤
```c
typedef struct {
    char *face;
    char *suit;
} Card;
```
- 用於基本資料型別的 typedef：
	- 例如，不同系統可能對 4 位元組整數使用 int 或 long。使用 typedef 可統一型別名稱。
```c
typedef int Integer; // 在某系統使用 int 作為 4 位元組整數
typedef long Integer; // 在另一系統使用 long
```
### 使用 typedef 簡化結構名稱
- 不使用typedef
```c
#include <stdio.h>

// 定義結構型別
struct Rectangle {
    int width;
    int height;
};

int main() {
    struct Rectangle rect = {10, 5}; // 初始化結構變數

    printf("Rectangle Width: %d, Height: %d\n", rect.width, rect.height);
    return 0;
}
```
- 使用typedef
```c
#include <stdio.h>

// 使用 typedef 定義結構型別別名
typedef struct {
    int width;
    int height;
} Rectangle;

int main() {
    Rectangle rect = {10, 5}; // 初始化結構變數

    printf("Rectangle Width: %d, Height: %d\n", rect.width, rect.height);
    return 0;
}
```

## Unions
- Union是一種衍生資料型別，與結構類似，但其所有成員共享相同的儲存空間。
- 特點：
	- 每次只能存取聯合中的一個成員。
	- 聯合的大小由其最大成員的大小決定，節省不必要的存儲浪費。
	- 用戶需確保以正確的資料型別存取聯合中的資料。
- 聯合適合用於以下場景：
	- 節省存儲空間：僅需存儲多種型別中的一個值。
	- 資料表示的轉換或內部檢查，如數值與位元的轉換。
- 語法格式：
```c
union number {
    int x;
    double y;
};
```
### 聯合變數的宣告與初始化
- 聯合變數可以用第一個成員的型別進行初始化
```c
union number value = {10}; // 初始化為 int 型別
```
- 若初始化值不匹配第一個成員型別，編譯器可能會警告或出現截斷。
```c
union number value = {1.43}; // 編譯器可能警告
```
### 聯合與資料型別的存取
- 聯合中的資料表示取決於使用的資料型別。
```c
union number value;
value.x = 10;
printf("As int: %d\n", value.x);

value.y = 3.14;
printf("As double: %f\n", value.y);
```
### 聯合的程式範例
```c
#include <stdio.h>

// 聯合定義
union number {
    int x;
    double y;
};

int main() {
    union number value;

    value.x = 42; // 初始化為 int 型別
    printf("As int: %d\n", value.x);

    value.y = 3.14159; // 改變為 double 型別
    printf("As double: %f\n", value.y);
    return 0;
}
```
### Unions 與 Struct 的差異
![upgit_20241120_1732087756.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241120_1732087756.png)

## Bitwise Operators 
### 位元基礎概念
- 電腦內部以 位元 (bit) 表示資料，每個位元為 0 或 1。
- 一組 8 個位元為 位元組 (byte)，如 char 型別通常佔 1 個位元組。
- 整數型別 通常用於位元運算，包括 有號整數 (signed) 和 無號整數 (unsigned)。
### 位元運算子概述
![upgit_20241120_1732089746.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241120_1732089746.png)

- 位元 AND (&)：
```c
int a = 5;   // 二進位: 0101
int b = 3;   // 二進位: 0011
int result = a & b; // 結果: 0001 (十進位: 1)
```
- 位元 OR (|)：
```c
int a = 5;   // 二進位: 0101
int b = 3;   // 二進位: 0011
int result = a | b; // 結果: 0111 (十進位: 7)
```
- 位元 XOR (^)：
```c
int a = 5;   // 二進位: 0101
int b = 3;   // 二進位: 0011
int result = a ^ b; // 結果: 0110 (十進位: 6)
```
- 位元補數 (~)：
```c
int a = 5;   // 二進位: 00000000 00000000 00000000 00000101
int result = ~a; // 結果: 11111111 11111111 11111111 11111010
```
- 左移 (<<) 和右移 (>>)：
```c
int a = 5;   // 二進位: 00000000 00000000 00000000 00000101
int result = a << 1; // 結果: 00000000 00000000 00000000 00001010 (十進位: 10)
result = a >> 1;     // 結果: 00000000 00000000 00000000 00000010 (十進位: 2)
```
### 使用 Mask 操作特定位元
- Mask 是一個整數，用於選擇或隱藏某些位元。
- 常用於檢查、設置或清除特定位元。
```c
int value = 5;        // 二進位: 0101
int mask = 1 << 2;    // Mask: 0100
int result = value & mask; // 結果: 0100 (非零表示位元開啟)
```
## Bit Fields 
- 位元欄位概念：
	- 結構中的成員可以定義所佔的位元數，稱為位元欄位。
	- 用於精簡記憶體使用，例如撲克牌資料表示。
```c
struct bitCard {
    unsigned int face : 4;  // 點數 (4 位元，範圍 0–15)
    unsigned int suit : 2;  // 花色 (2 位元，範圍 0–3)
    unsigned int color : 1; // 顏色 (1 位元，0: 紅色, 1: 黑色)
};

// 操作Bit Fields 
struct bitCard card;
card.face = 12;  // 國王 (King)
card.suit = 3;   // 黑桃 (Spades)
card.color = 1;  // 黑色
```
- 記憶體對齊與填充
```c
struct example {
    unsigned int a : 13;
    unsigned int   : 19;  // 填充 19 位元
    unsigned int b : 4;   // 另外存放
};
```
## Enumeration Constants
- 列舉 (Enumeration) 是一組以識別符表示的整數常量，透過關鍵字 enum 定義。
- 列舉值預設從 0 開始，依次遞增 1，但可自定義起始值及其他值。
- 列舉的優勢在於提高程式的可讀性，並限制變數的取值範圍。
- 識別符需唯一：同一列舉中的成員名稱不能重複。
- 值的範圍：列舉成員的值可任意指定，但需避免衝突或邏輯錯誤。
### 基本語法
```c
enum enumeration_name { constant1, constant2, ... };

// 月份列舉
enum months {
    JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};
```
- 自定義起始值：
```c
enum months {
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};
```
### 列舉與陣列的結合
```c
#include <stdio.h>

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

const char *monthName[] = {
    "", "January", "February", "March", "April",
    "May", "June", "July", "August", "September",
    "October", "November", "December"
};

int main() {
    for (enum months month = JAN; month <= DEC; month++) {
        printf("%s\n", monthName[month]);
    }
    return 0;
}
```
## Anonymous Structures and Union(匿名結構與聯合)
- C11 支援匿名結構 (struct) 與 聯合 (union)，它們可以嵌套於已命名的結構或聯合中。
- 匿名結構與聯合的成員被視為外層型別的成員，可直接透過外層型別的物件存取。
- 使用匿名結構與聯合的優勢
	- 簡化代碼：無需為嵌套的結構或聯合命名，減少額外名稱的定義。
	- 增強可讀性：直接存取內部成員，程式更直觀。
	- 節省存儲空間：匿名聯合的成員共享同一塊存儲空間。
### 基本語法
```c
struct MyStruct {
    int member1;
    int member2;

    struct { // 匿名結構
        int nestedMember1;
        int nestedMember2;
    };
};
// nestedMember1 和 nestedMember2 是匿名結構的成員。
```
### 存取方式
```c
// 假設宣告變數如下
struct MyStruct myStruct;

// 存取成員的方式
myStruct.member1;       // 外層成員
myStruct.member2;       // 外層成員
myStruct.nestedMember1; // 匿名結構成員
myStruct.nestedMember2; // 匿名結構成員
```
## 匿名union的應用
- 匿名聯合的成員同樣可直接存取，並且共享相同的存儲空間。
```c
struct Data {
    int id;
    union { // 匿名聯合
        float value;
        int count;
    };
};

// 存取方式
struct Data data;
data.id = 1;
data.value = 3.14;  // 使用匿名聯合的成員
data.count = 42;    // 改變聯合的成員
```



