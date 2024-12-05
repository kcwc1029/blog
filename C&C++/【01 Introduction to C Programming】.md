## 建立第一個程式
![upgit_20241113_1731468170.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731468170.png)
- `//`：單行註釋
- `/*...*/`：multi-line comments
- `#include <stdio.h>`：is a directive to the C preprocessor.
- `int main( void )`：
	- is a part of every C program.
	- The parentheses after main indicate that main is a program building block called a function.
- `printf( "Welcome to C!\n" );`：
	- instructs the computer to perform an action, namely to print on the screen the string of characters marked by the quotation marks.
	- A string is sometimes called a character string, a message or a literal.
- `\n`：逃脫序列(Escape Sequences)：
	- It indicates that printf is supposed to do something out of the ordinary.
![upgit_20241113_1731468516.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731468516.png)

## Linker 與 Executables
- **標準函式庫**（如 `printf` 和 `scanf`）**不屬於** C 語言的一部分，而是由外部函式庫提供。
- 編譯器在編譯程式時，如果 `printf` 或 `scanf` 拼錯，無法直接偵測到錯誤。
- 編譯器編譯 `printf` 時，**僅為函式呼叫預留空間**，但不會確認函式庫的實際位置。
- **Linker** 負責在**連結階段**找到函式庫，並將正確的函式呼叫插入到目標程式中。
- **連結器**執行時，會定位函式庫並插入適當的呼叫，以確保最終的執行檔可以正常運行。

## Using Multiple printfs
![upgit_20241113_1731468772.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731468772.png)

![upgit_20241113_1731468786.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731468786.png)

## Adding Two Integers
![upgit_20241113_1731468836.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731468836.png)

![upgit_20241113_1731468858.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731468858.png)


- 變數與變數定義 (Variables and Variable Definitions)
	- 所有變數在使用前都必須以名稱和資料型態定義。
```cpp
// 變數宣告
int integer1; // 使用者輸入的第一個數字
int integer2; // 使用者輸入的第二個數字
int sum; // 儲存相加後的結果

// 可以使用單行定義多個變數
int integer1, integer2, sum;
```
- 識別字與區分大小寫 (Identifiers and Case Sensitivity)
   - 在 C 語言中，變數名稱是有效的識別字。
   - 識別字可以由字母、數字及底線組成，但不能以數字開頭。
   - C 語言區分大小寫，例如 `a1` 和 `A1` 是不同的變數。

### C 語言的基本輸入與輸出
- 使用 `printf` 函數顯示提示訊息，告知使用者輸入資料。
```c
printf("Enter first integer\n"); // 顯示訊息並換行
```
- 使用 `scanf` 函數讀取使用者輸入的整數。
```cpp
scanf("%d", &integer1); // 讀取輸入並存入變數
// `scanf` 的兩個參數分別為格式控制字串 (`"%d"`) 和變數的地址 (`&integer1`)。
// `%d` 表示要讀取整數。
// `&` 用於取得變數的記憶體位置。
```
## Memory Concepts
- 變數名稱與記憶體位置:
   - 變數名稱 (如 integer1、integer2 和 sum) 對應到電腦記憶體中的位置。
   - 這些變數的位置在記憶體中並不一定是相鄰的。
   - 每個變數都有一個名稱 (name)、資料型態 (type) 和值 (value)。
- canf 函數讀取資料:
   - 當執行 `scanf("%d", &integer1)` 時，使用者輸入的數值會存入 integer1 所對應的記憶體位置。例如，若輸入 45，則電腦會將 45 儲存在 integer1 的位置。
![upgit_20241113_1731469533.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731469533.png)

- 記憶體覆寫特性:
   - 當新數值存入記憶體位置時，會取代之前的數值，這稱為「破壞性操作 (destructive)」。
   - 例如，當執行 `scanf("%d", &integer2)` 並輸入 72 時，該值會存入 integer2 的記憶體位置。
![upgit_20241113_1731469546.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731469546.png)
- 當程式取得 integer1 和 integer2 的值後，執行 `sum = integer1 + integer2`，將總和儲存到 sum 變數中。這會覆蓋 sum 之前的值。
![upgit_20241113_1731469605.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731469605.png)

- 當總和計算完成後，integer1 和 integer2 的值依然保持不變，因此讀取記憶體的操作稱為「非破壞性操作 (nondestructive)」。

## Arithmetic in C(C 語言中的運算符與運算規則)
- 乘法運算符使用 `*`，餘數運算符使用 `%`。
- C 語言中的算術運算符 (如 `+`, `-`, `*`, `/`, `%`) 都是二元運算符，表示它們需要兩個運算元。
	- 例如，`3 + 7` 包含二元運算符 `+` 和運算元 `3` 和 `7`。
  - 整數除法 (`/`) 的結果只取整數部分，例如 `7 / 4` 的結果為 `1`，`17 / 5` 的結果為 `3`。
   - 餘數運算符 `%` 用於求整數除法的餘數。且 `%` 只能用於整數運算元。：
     - `7 % 4` 結果為 `3`
     - `17 % 5` 結果為 `2`
-  運算優先順序摘要：
	- 最高優先權：括號 `()`
	- 次高優先權：乘法 (`*`)、除法 (`/`)、餘數 (`%`)
	- 再次優先：加法 (`+`)、減法 (`-`)
	- 最低優先：指派運算 (`=`)
![upgit_20241113_1731469960.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731469960.png)


![upgit_20241113_1731469980.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731469980.png)


## C 語言中的執行語句和判斷語句
- 執行語句 (Executable Statements)：
   - C 程式語句主要執行動作 (例如計算、資料輸入/輸出) 或做出決策。
   - 例如，程式可以決定如果考試成績大於或等於 60，則印出「Congratulations! You passed.」。
![upgit_20241113_1731470297.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731470297.png)

- if 判斷語句：
   - C 語言的 `if` 語句用於根據條件 (condition) 的真偽來決定是否執行某段程式碼。
   - 當條件為真 (true) 時，`if` 語句的主體 (body) 會被執行。
   - 當條件為假 (false) 時，`if` 語句的主體則不執行，但程式會繼續執行 `if` 語句之後的下一行程式碼。
- 程式可讀性：
   - 為了增強程式的可讀性，建議縮排 `if` 語句的主體，並在語句上下添加空行。
   - 使用 `{` 和 `}` 包圍 `if` 語句的主體，可以包含多行程式碼。
![upgit_20241113_1731470320.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731470320.png)

![upgit_20241113_1731470334.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731470334.png)

![upgit_20241113_1731470345.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731470345.png)



### 運算符的優先級 (Operator Precedence)：
   - 運算符的優先級由高到低排列，從左到右執行 (除了指派運算符 `=`，是從右到左)。
   - 等號 (`=`) 也是一種運算符，雖然通常用於指派 (assignment)。
![upgit_20241113_1731470493.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731470493.png)

### 關鍵字 (Keywords)：
   - C 語言中有許多**保留字** (keywords)，例如 `int` 和 `if`。
   - 這些保留字具有特殊的語法意義，不能作為變數名稱使用。
![upgit_20241113_1731470511.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731470511.png)


## 演算法 (Algorithms)
- 解決任何計算問題的過程，必須執行一系列按特定順序排列的動作。
- 演算法是一種解決問題的**程序**，包括：
 - 要執行的**動作**。
 - 這些動作執行的**順序**。
- 指定電腦程式中各語句執行的順序是至關重要的。若順序不正確，可能導致執行錯誤，結果不符合預期。
- 一個執行準則的演算法，如「社畜上班演算法」：
	 - (1) 起床
	 - (2) 刷牙
	 - (3) 洗臉
	 - (4) 通勤
	 - (5) 泡咖啡
	 - (6) 打開電腦
- 若順序變更，例如在起床前刷牙，可能會導致不理想的結果。

## Pseudocode
- Pseudocode 是一種人工設計的非正式語言，用於幫助開發演算法。
- 類似於日常英文，易於理解和操作，雖然它並非真正的程式語言。
- Pseudocode 並不會在電腦上執行，而是用來協助構思程式邏輯，在實際撰寫 C 程式前先理清思路。

## C 語言控制結構與流程圖

### 程式執行順序與控制結構
- 順序執行(Sequential Execution)：
   - 程式的敘述通常是依照撰寫順序逐一執行。
   - 若有特殊需求，可透過控制結構改變程式執行順序，這稱為控制轉移(Transfer of Control)。
- 結構化程式設計(Structured Programming)：
   - 在 1960 年代，過度使用控制轉移（如 `goto`）導致軟體開發困難。
   - 因此，結構化程式設計主張不使用 `goto`，以提升程式的可讀性與可維護性。
   - 研究證明，所有程式可以用三種基本控制結構撰寫：順序結構、選擇結構與迴圈結構。
#### 順序結構(Sequence Structure)：
   - 順序結構為預設執行順序，**無特殊指示時**，C 語言會依順序執行每一行程式碼。

#### **選擇結構(Selection Statements)**：
   - C 語言提供三種選擇結構：
     - **if 選擇敘述**：執行條件為真時的操作，否則跳過。
     - **if…else 雙重選擇敘述**：根據條件選擇執行不同操作。
     - **switch 多重選擇敘述**：根據表達式的值執行多種操作之一。
   - **單一選擇 (Single-Selection)**：`if`，**雙重選擇 (Double-Selection)**：`if…else`，**多重選擇 (Multiple-Selection)**：`switch`。
#### **迴圈結構(Iteration Statements)**：
   - C 語言提供三種迴圈結構：
     - **while 迴圈**：當條件為真時重複執行。
     - **do…while 迴圈**：至少執行一次，然後根據條件決定是否繼續。
     - **for 迴圈**：根據條件設定重複次數。
4. **控制結構的組合**：
   - C 程式僅包含七種控制敘述：**順序**、**三種選擇**、**三種迴圈**。
   - 這些控制敘述可以透過**控制結構堆疊(stacking)**或**嵌套(nesting)**進行組合。

### 流程圖(Flowchart)
- 流程圖是一種**圖形化表示演算法**的方式，使用**特殊符號**（如矩形、菱形、圓角矩形、圓形）及**流程線(flowlines)**來表示操作的順序。
- 常用於**規劃演算法**，雖然大多數程式設計師更偏好使用 pseudocode。
- **常見流程圖符號**：
	- **矩形符號**：代表動作（如計算或輸入/輸出）。
	- **菱形符號**：代表決策。
	- **圓角矩形**：標示流程開始或結束。
	- **小圓形**：用於連接流程段落。
- **控制結構的流程圖**：流程圖中每個控制敘述都有單一進入點與單一退出點，這使得程式**更清晰且易於維護**。
![upgit_20241113_1731472501.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731472501.png)


## The if Selection Statement
- **選擇敘述**用於在多種操作路徑中**進行選擇**。
	- 例如：假設考試及格分數為 60 分，若學生分數 ≥ 60 則顯示 "Passed"。
```c
if (grade >= 60) {
	printf("Passed\n");
}
```
### 流程圖(Flowchart) 的應用
- **流程圖**用於視覺化程式的邏輯：
	- **菱形符號 (Decision Symbol)**：表示**決策點**，用於條件判斷。
	- 菱形中包含的表達式可以為**真 (true)** 或 **假 (false)**，有兩條**流程線**分別指向不同的路徑。
- **單一選擇 (Single-Selection)**：
	- 使用 **if** 敘述進行單一條件選擇，符合條件時執行，否則跳過。
	- **單一進入/單一退出 (Single-Entry/Single-Exit)**：`if` 敘述具有單一進入點與單一退出點，方便控制程式的流程。
![upgit_20241113_1731472631.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731472631.png)

## The if…else Selection Statement

- 巢狀 `if...else` 用於**多條件測試**：
 ```cpp
 if (grade >= 90)
	 puts("A");
 else if (grade >= 80)
	 puts("B");
 else if (grade >= 70)
	 puts("C");
 else if (grade >= 60)
	 puts("D");
 else
	 puts("F");
```
- 若 `grade >= 90` 為真，其餘條件不再檢查，直接跳過 `else` 部分。
- 若 `if` 的區塊內只有**單一語句**，可省略 `{}`。
- 多條語句需使用 `{}` 包裹成**複合語句 (Compound Statement)**。

## The while Iteration Statement (Cont.)
- **迭代敘述**（又稱**迴圈敘述**）允許指定在某個**條件為真**的情況下重複執行某個動作。
- **while 迴圈**的**主體**可以是**單一敘述**或**複合敘述**（由 `{}` 包裹多條敘述）。
- 條件：「購物清單上還有更多項目」。
	 - 如果條件為真，則執行「購買下一個項目並劃掉」。
	 - 重複執行直到條件為假為止。
- 迴圈會**不斷重複執行**，直到條件變為假。
- 一旦條件不成立，程式控制權會**跳到迴圈結束後**的下一條敘述。
- **無限迴圈**的風險：
	- 若條件永遠不會變為假，則會進入無限迴圈。
	- 需注意設置適當的迴圈終止條件以避免無限迴圈。
- while 迴圈範例找出**第一個大於 100 的 3 的次方**。
```c
int product = 3;
while (product <= 100) {
	product = 3 * product;
} // end while
```
### while 迴圈的流程圖 (Flowchart)
- **流程圖符號**：
	- **矩形 (Rectangle)**：表示執行動作（例如計算或 I/O 操作）。
	- **菱形 (Diamond)**：表示條件判斷。
	- **箭頭 (Flowline)**：顯示程式執行的流程。
- **流程解釋**：
	- 進入 `while` 迴圈後，檢查條件是否為真。
	- 如果為真，執行迴圈主體，然後再次檢查條件。
	- 當條件為假時，跳出迴圈，繼續執行迴圈後的程式碼。
![upgit_20241113_1731473222.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731473222.png)


## Assignment Operators
- C 提供多種指派運算子，用於簡化指派運算式。
```cpp
// 傳統的運算
c = c + 3;
// 使用運算子縮寫
c += 3;
```
## Increment and Decrement Operators
- C 提供單一運算子 `++` (遞增) 和 `--` (遞減)，可用來增加或減少變數的值。
- 舉例: `c++` 等同於 `c = c + 1` 或 `c += 1`。
- 如果 `++` 或 `--` 運算子放在變數前面，稱為**前遞增**或**前遞減** (preincrement/predcrement)。
- 如果 `++` 或 `--` 運算子放在變數後面，則稱為**後遞增**或**後遞減** (postincrement/postdecrement)。
- 前遞增與後遞增的差異**
	- **前遞增**: 先遞增變數值，再使用該變數。
	- **後遞增**: 先使用變數的目前值，再進行遞增。
- 若在 `printf` 中使用：
	- `++c`：則會先增加 `c` 的值再輸出。
	- `c++`：則會先輸出 `c` 的值，之後再遞增。
- 區別使用場合
   - 只有在較大的運算式中，**前遞增**與**後遞增**才會有不同的效果。例如:
     - `result = ++c + 5` (先增加 `c` 再計算)
     - `result = c++ + 5` (先計算後再增加 `c`)





















































































