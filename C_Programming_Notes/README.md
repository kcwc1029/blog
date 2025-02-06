## 基本安裝

gcc gdb g++ binutils

## 1. 程式語言基本區分

-   程式語言基本可以分為高階語言(high-level languages)與低階語言(low-level languages)
-   高階語言
    -   貼近人類的表達方式，易學易懂
    -   缺點是無法有效控制低階的硬體，執行效率也相對較差。
-   低階語言
    -   擁有良好的執行效率，並提供強大的硬體控制
    -   很難學習和理解。編寫、讀取、除錯和維護相對較具挑戰性。

### 1.1. 程式語言開發過程

-   C 語言從設計、到最後執行會依據下列步驟進行：

1. Create a source file.
2. Use an editor to write the original source code.
3. Compile and link the program. At this stage, the system will generate an executable module.
4. Execute the program.

### 1.2. Linker 與 Executables

-   Linker  負責在連結階段找到函式庫，並將正確的函式呼叫插入到目標程式中。

## 2. 第一支程式

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int no;
    no = 2;
    printf("Hello World!!\n");
    printf("there are %d pandas in Taipei", no);

    system("PAUSE");
    return 0;
}
```

## 3. 編譯&執行方式

```shell
gcc test.c -o test // 將.C檔編譯成執行檔
.\test // 執行
```

## 4. 標頭擋

```c
#include <內建標題檔.h>
#include "自訂標題檔.h"
```

## 7. bit/bytes

### 7.1. 位元 (bit)

-   位元 (bit) 是電腦中最小的數據單位。
-   它可以表示 0 或 1 兩種狀態（像開或關，對應於電路中的電流有或沒有）。

### 7.2. 位元組 (byte)

-   位元組 (byte) 是由 8 個位元 (bits) 組成的數據單位。
-   每個位元都有兩種可能性（0 或 1），所以 8 個位元可以有 256 種組合。

## 5. 變數的基本概念

-   變數的宣告告訴電腦要為變數分配多少記憶體空間。
-   變數是強型別(strongly typed)語言的一部分，這意味著在宣告變數時，必須明確指定其資料型態。
-   變數命名規則：https://reurl.cc/A2zqNQ

```c
int sum = 0;
```

### 5.1. 變數的宣告

-   變數宣告就是在程式碼中指定變數名稱和其資料型態

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    // 宣告
    int num1, num2;

    // 初始化
    int num1 = 30;  // 初始化 num1
    int num2 = 77;  // 初始化 num2
    return 0;
}
```

### 5.2. 基本資料型態

![image](https://cdn.discordapp.com/attachments/1286741860538122281/1332376413675851796/image.jpg?ex=679507bb&is=6793b63b&hm=eadd7c4ce076d52d8b93f8cf136e9b124e25f5d371e048fd476335155b9f06fe&)

-   可以用 sizeof()查詢資料長度。

#### 5.2.1. 整數型

-   int：4byte

```c
int a = 80; // 十進位
int a = 0120 // 八進位(前面+個0)
int a = 0x50 // 十六進位

// 修飾詞
int a = 58; // 占 4byte(32bits)
short int a = 58; // 占 2byte(16bits)
long int a = 58; // 占 8byte(64bits)
```

#### 5.2.2. 浮點數

-   float：4byte
-   double：8byte

##### 資料宣告

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f1 = 123.4563357109375f; // 宣告單精度浮點數
    double d1 = 123456789.123456789123; // 宣告雙精度浮點數
    printf("f1=%f\n", f1); // f1=123.456337
    printf("d1=%f\n", d1); // d1=123456789.123457
    return 0;
}
```

##### 輸入輸出

```c
#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 5
int main() {
    float f;  double df;
    scanf("%f", &f);
    scanf("%lf", &df);
    printf("%f\n", f);
    printf("%f\n", df);
    return 0;
}

// 輸入
// 3.14 3.15
// 輸出
// 3.140000
// 3.150000
```

##### 類別轉換

-   double => float => int

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int j;
    double d;
    scanf("%d%d%lf", &i, &j, &d);
    printf("%d\n", i / j); // int除int
    printf("%f\n", i / d); // int除double
    return 0;
}

// 輸入
// 100 4 4.0
// 輸出
// 25
// 25.000000
```

-   計算泰勒展開式

![image](https://cdn.discordapp.com/attachments/1286741860538122281/1332676020389548142/image.jpg?ex=67961ec3&is=6794cd43&hm=88bed968ad8e77384ac88bcdb2c4f79b740f86247efa56ea41c41cc5e15ef720&)

-   可以嘗試將 xpower 的資料型態更改看看(double、float)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    float x;
    scanf("%f", &x);
    float e = 1.0;
    int n = 10;
    int factorial = 1; // 分母部分
    float xpower = 1.0; // 分子
    for (int i = 1; i <= n; i++){
        factorial *= i;
        xpower *= x;
        e += xpower / factorial; // float除int 資料型別轉換
    }
    printf("%f\n", e);
    return 0;
}

// 輸入
// 1.5
// 輸出
// 4.48186
```

#### 5.2.3. 字元 char

-   字元型用於存儲單個字符，使用 ASCII 編碼來表示字符的數值
-   佔用 1 個位元組。
-   範圍：-128 到 127 或 0 到 255（取決於是否使用 signed 或 unsigned）。
-   跳脫字符：在 C 語言中，字串其實是一個字符陣列，以空字元 '\0' 作為結束標誌

```c
char str[] = "Hello, World!";
// `\n`：換行
// `\t`：水平製表符
// `\\`：反斜線字符
```

### 5.3. 資料型態轉換

-   C 編譯器會自動將「範圍小的型態」轉換為「範圍大的型態」，以避免資料丟失

```c
int i = 3;
float f = 5.2;
double d;

d = i + f;  // i 會被轉換成 float，然後結果再轉換為 double
```

### 5.4. 強制型態轉換

-   如果需要將某個資料強制轉換為另一種型態，可以使用強制轉換運算符

```c
double x = 5.7;
int y;

y = (int) x;  // 將 double 型態的 x 強制轉換為 int，結果為 5
```

## 6. 定義常數的方式

### 6.1. 方式 1：使用#define

-   `#define` 是一個預處理指令
-   在編譯期間，所有使用到這個名稱的地方，預處理器會用對應的值來替換
-   在編譯前就完成了代換
-   優點：高效：由於在編譯時直接替換，需要額外的記憶體空間來存儲常數值
-   缺點：沒有類型檢查，因此不受任何編譯期的類型檢查，這可能導致一些潛在的錯誤

```c
#define PI 3.14159
#define SQUARE(x) (x * x)

// 如果使用SQUARE(3 + 1)，就會變成(3 + 1 * 3 + 1)，就不是預期答案
```

### 6.2. 方式 2：使用 const

-   const 定義的常數有類型，並且會在記憶體中分配空間。
-   優點：因為有資料型態，因此可以接受編譯器的類型檢查，從而避免因類型錯誤導致的問題
-   缺點：佔用記憶體

```c
#include <stdio.h>
#define PI_1 3.14159

int main() {
    const float PI_2 = 3.14159;  // 定義一個常數
    float radius = 5.0;
    float area1 = radius * radius * PI_1;
    float area2 = radius * radius * PI_2;
    printf("aera of circle %.2f\n", area1);
    printf("aera of circle %.2f\n", area2);
    return 0;
}
```

## 運算

### 交換兩個變數的值

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j;
    scanf("%d%d", &i, &j);
    int temp = i;
    i = j;
    j = temp;
    printf("%d\n", i);
    printf("%d\n", j);
}
```

### 計算零錢

-   輸入金額，計算 50、10、5、1 硬幣數量

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int change;
    scanf("%d", &change);
    int fifty = change / 50;
    change = change - fifty * 50;
    int ten = change / 10;
    change = change - ten * 10;
    int five = change / 5;
    change = change - five * 5;
    int one = change;

    printf("%d\n", fifty);
    printf("%d\n", ten);
    printf("%d\n", five);
    printf("%d\n", one);
}
```

## 輸入輸出

### scanf

-   輸入的格式必須和指定的格式化字串一致（如 %d 表示整數，%f 表示浮點數等）

### fgets

-   從標準輸入或文件中讀取一行字串
-   比 gets 更安全，因為可以指定最大讀取長度

```c
char str[100];
fgets(str, sizeof(str), stdin);
```

### printf

-   格式化輸出到標準輸出（通常是屏幕）

### puts

-   比 printf 簡單，適合輸出純文本
-   輸出字串並自動換行

```c
puts("Hello, World!");
```

## 8. ASCII

-   ASCII（American Standard Code for Information Interchange）是早期設計的一種字符編碼方式，用來將字母、數字和符號對應到二進制數字。

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = 'a';
    printf("character: %c\n", c);
    printf("decimal ASCII code: %d\n", c);
    printf("hex ASCII code: %x\n", c);
    return 0;
}
// character: a
// decimal ASCII code: 97
// hex ASCII code: 61
```

## 9. flow control

### 判斷式

-   選擇結構(Selection Statements)
    -   if
    -   switch 多重選擇敘述：根據表達式的值執行多種操作之一。
-   迴圈結構(Iteration Statements)
    -   while 迴圈：當條件為真時重複執行。
    -   do…while 迴圈：至少執行一次，然後根據條件決定是否繼續。
    -   for 迴圈：根據條件設定重複次數。

#### 實作 abs

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, k, max;
    scanf("%d%d%d", &i, &j, &k);
    if (i > 0){
        k = i;
    }else{
        k = -i;
    }
    printf("%d\n", k);
}
```

#### 實作三者最大值

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, k, max;
    scanf("%d%d%d", &i, &j, &k);
    if (i > j){
        max = i;
    }else{
        max = j;
    }
    if (k > max){
        max = k;
    }
    printf("%d\n", max);
}
```

#### 閏年判斷

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // bool

int main(){
    int year;
    printf("請輸入年分");
    scanf("%d", &year);
    bool leapYear;
    if (year % 400 == 0){
        leapYear = true;
    }else if ((year % 4 == 0) && (year % 100 != 0)){
        leapYear = true;
    }else{
        leapYear = false;
    }
    printf("%d\n", leapYear);
}
```

#### 四則運算

-   輸入三個參數：被加數、加數、規則
    -   0：加法
    -   1：減法
    -   2：乘法
    -   3：除法

```c
#include <stdio.h>
#include <stdlib.h>

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3
#define MOD 4

int main() {
    int a, b, c, d; // a 和 b 是操作數，c 是運算符，d 是結果
    printf("請輸入兩個整數和運算符（0:加法, 1:減法, 2:乘法, 3:除法, 4:取餘數）：\n");
    scanf("%d%d%d", &a, &b, &c);

    switch (c) {
        case ADD:
            d = a + b;
            printf("結果: %d\n", d);
            break;
        case SUB:
            d = a - b;
            printf("結果: %d\n", d);
            break;
        case MUL:
            d = a * b;
            printf("結果: %d\n", d);
            break;
        case DIV:
            if (b == 0) {
                printf("錯誤: 除數不能為零\n");
            } else {
                d = a / b;
                printf("結果: %d\n", d);
            }
            break;
        case MOD: // 取餘數
            if (b == 0) { // 處理除以零的情況
                printf("錯誤: 除數不能為零\n");
            } else {
                d = a % b;
                printf("結果: %d\n", d);
            }
            break;
        default: // 無效的運算符
            printf("錯誤: 無效的運算符\n");
            break;
    }

    return 0;
}

```

### 迴圈

#### 最大公因數(GCD)

![image](https://cdn.discordapp.com/attachments/1286741860538122281/1332351648785240145/image.jpg?ex=6794f0aa&is=67939f2a&hm=e7fe7b2d31924bfa30811e0988710f4e35005915844b008f15b32a061fb88a19&)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k;
    scanf("%d%d", &i, &j);
    while (i % j != 0) {
        k = i % j;
        i = j;
        j = k;
    }
    printf("%d\n", j);
}

```

#### 質數判斷

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // 使用 bool 類型

// 判斷質數的函數
bool isPrime(int n) {
    if (n <= 1) {
        return false; // 1 和以下的數字不是質數
    }
    if (n == 2) {
        return true; // 2 是質數
    }
    if (n % 2 == 0) {
        return false; // 偶數（除了 2）不是質數
    }

    // 檢查從 3 到 sqrt(n) 的奇數
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false; // 如果有因數，則不是質數
        }
    }
    return true; // 否則，是質數
}

int main() {
    int num;
    printf("請輸入一個整數：");
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("%d 是質數。\n", num);
    } else {
        printf("%d 不是質數。\n", num);
    }
    return 0;
}

```

#### 模擬長除法

```
模擬126/3
輸入
3
1 2 6

輸出
4
2
```

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int k;
    scanf("%d", &k); // 讀取除數 k
    int count = 0, prev = 0; // count 用於計數輸入的數字，prev 保存上一步的餘數
    int toPrint; // 用於保存部分商
    int digit; // 用於保存當前輸入的數字
    while (scanf("%d", &digit) != EOF) { // 逐個讀取數字，直到輸入結束
        int value = 10 * prev + digit; // 將上一步的餘數與當前數字結合，形成新的被除數
        toPrint = value / k; // 計算部分商
        if (!(count == 0 && toPrint == 0)){ // 如果不是前導零，則輸出
            printf("%d\n", toPrint);
        }
        prev = value % k; // 更新餘數
        count++; // 計數輸入的數字
    }

    // 處理特殊情況：只有一個數字且結果為 0
    if (count == 1 && toPrint == 0){
        printf("0\n");
    }
    return 0;
}

```

#### 檢查 11 的倍數

```
判斷2728是否為11的倍數
輸入
2 7 2 8
^Z

輸出
1
```

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int digit;
    int count = 0;
    int evenSum = 0, oddSum = 0; // 紀錄奇數位跟偶數位
    while (scanf("%d", &digit) != EOF){
        if (count % 2 == 0){
            evenSum += digit;
        }else{
            oddSum += digit;
        }
        count++;
    }
    // 檢查正負
    int diff = evenSum - oddSum;
    if (diff < 0){
        diff = -diff;
    }
    printf("%d\n", diff % 11 == 0);
    return 0;
}
```

### 9.1. break

-   立即退出 while、for、do while 或 switch 語句，繼續執行後續程式碼。
-   跳出 switch 語句，避免執行後續的 case。

```cpp
for (int i = 1; i <= 10; i++) {
    if (i == 5) break; // 當 i 為 5 時跳出迴圈
    printf("%d ", i);
}
// 輸出：1 2 3 4
```

### 9.2. continue

-   跳過當前迴圈中的剩餘語句，進入下一次迭代。

```cpp
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue; // 當 i 為 3 時跳過
    printf("%d ", i);
}
// 輸出：1 2 4 5
```

## array

-   占有一塊連續的記憶體空間。

### initialization

```c
// 宣告空間
int score[5];

// 在宣告空間的時候，同時需要宣告值
int arr[3] = {5,7,10}; // array of int
float arr[3] = {5.1,7.1,10.1}; // array of float
char arr[3] = {'a', 'b', 'c'}; // array of charts

int arr[5] = {0}; //相當於{0,0,0,0,0}
int arr[5] = {1,2}; //相當於{1,2,0,0,0}
```

```c
// TODO: 分別輸出 5 個值，並且輸出平均

#include <stdio.h>
#include <stdlib.h>

int main(){
    int Score[5] = {87, 66, 90, 65, 70};
    int i = 0;
    float Total = 0;

    for (i = 0; i < 5; i++) {
        printf("The score of student %d is: %d\n", i + 1, Score[i]);
        Total += Score[i]; // Calculate total score
    }

    printf("Total: %.1f   Average: %.1f\n", Total, Total / 5); // Output total and average score
    return 0;
}
```

### Element Accessing

```c
// TODO: 輸入5個數值，最後輸出最小的數值

#include <stdio.h>
#include <stdlib.h>

int main(){
    int grades[5];
    int low_grage;
    for(int i=0;i<5;i++){
        printf("enter grade no.%d\t", i);
        scanf("%d", &grades[i]);
    }

    low_grage = grades[0];
    for(int i=0;i<5;i++){
        if(grades[i]<low_grage)
            low_grage = grades[i];
    }
    printf("low grade: %d", low_grage);
    return 0;
}
```

### 超出邊界

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[3] = {1,2,3,};
    for (int i = 0; i < 5; i++){
        printf("arr num: %d\n", arr[i]);
    }
    return 0;
}
// arr num: 1
// arr num: 2
// arr num: 3
// arr num: 3
// arr num: 4194432
```

### 查看 arr 的記憶體空間與長度

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr1[1];
    float arr2[1];
    char arr3[1];
    printf("%d\n", sizeof(arr1));
    printf("%d\n", sizeof(arr2));
    printf("%d\n", sizeof(arr3));
    return 0;
}
// 4
// 4
// 1
```

### 記憶體位置

-   印出記憶體位置：要使用%p

```c
#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 5

int main() {
    int a[ARRAYSIZE];
    printf("%ld\n", sizeof(a[0]));
    printf("%ld\n", sizeof(a));
    for (int i = 0; i < ARRAYSIZE; i++){
        printf("%p\n", &(a[i]));
    }
    return 0;
}

// 輸出
// 4
// 20
// 0061FF08
// 0061FF0C
// 0061FF10
// 0061FF14
// 0061FF18
```

### 費博納數列

-   assert：
    -   確保輸入 n 不會超過 FIBARRAYSIZE
    -   引入：`<assert.h>`

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define FIBARRAYSIZE 100

int main() {
    int n;
    scanf("%d", &n);
    assert(n >= 2 && n < FIBARRAYSIZE);
    int fab[FIBARRAYSIZE];
    fab[0] = 0, fab[1] = 1;
    for (int i = 2; i < n; i++){
        fab[i] = fab[i - 1] + fab[i - 2];
    }
    for (int i = 0; i < n; i++){
        printf("%d\t", fab[i]);
    }
    return 0;
}
```

### 泡沫排序法

-   核心：反覆比較相鄰的元素，並將較大的元素逐步「冒泡」到數列的末尾
-   會有雙重迴圈
    -   外部：回和數
    -   內部：

```
未排序
64, 34, 25, 12, 22, 11, 90

第一輪： 最大值 90 冒泡到最後一位
64, 34, 25, 12, 22, 11, 90

第二輪： 次大值 64 冒泡到倒數第二位
34, 25, 12, 22, 11, 64, 90

第三輪： 次次大值 34 冒泡到倒數第三位
25, 12, 22, 11, 34, 64, 90
...
```

-   [bubble_sort01.c](./bubble%20sort/bubble_sort01.c)
-   優化：在最佳情況下，如果數列已經有序，我們可以提早停止排序。
-   [bubble_sort02.c](./bubble%20sort/bubble_sort02.c)

### 九宮格遊戲

-   [nine_grid_game.c](./Nine%20Grid%20Game/nine_grid_game.c)

### 10. BUG：明明已經安裝好 gcc 或 gdb，可是 vscode 的 terminal 卻無法 work

-   手動設置 VS Code 的環境變數
-   點擊右下角齒輪圖標，選擇 Settings。
-   點擊右上角的 Open Settings (JSON)，打開 `settings.json` 配置文件。
-   添加以下設置(要確認好你安裝 MinGW 的路徑)

```json
"terminal.integrated.env.windows": {
	"PATH": "C:\\MinGW\\bin;${env:PATH}"
}
```

## 函數

-   包含五個部分：函式庫、標頭檔(header file)、函數名稱、參數、回傳

### 參數傳遞

-   分為：
    -   形式參數(formal parameter)
    -   實際參數(actual parameter)

#### 主程式與函數內的地址不同

```c
// 變數i為實際參數(actual parameter)
// 變數j為實際參數(formal parameter)
#include <stdio.h>
#include <stdlib.h>

void test(int j){
    printf("變數j的值 = %d\n",j);
    printf("變數j的地址 = %p\n", &j);
    j++;
    return;
}
int main(void){
    int i;
    scanf("%d", &i);
    printf("變數i的值 = %d\n",i);
    printf("變數i的地址 = %p\n", &i);
    test(i);
    printf("變數i的值 = %d\n",i);
    printf("變數i的地址 = %p\n", &i);
    return 0;
}

// 輸入
// 25
// 輸出
// 變數i的值 = 25
// 變數i的地址 = 0061FF1C
// 變數j的值 = 25
// 變數j的地址 = 0061FF00
// 變數i的值 = 25
// 變數i的地址 = 0061FF1C
```

### 陣列參數傳遞

-   陣列是以實際參數(actual parameter)的方式傳值

```c
#include <stdio.h>
#include <stdlib.h>
#define ASIZE 3
#define BSIZE 5

void printArray(int array[], int n){
    printf("array is at %p\n", array);
    for (int i = 0; i < n; i++){
        printf("array[%d] = %d\n", i, array[i]);
    }
    return;
}


int main(void){
    int a[ASIZE] = {3,5,7};
    int b[BSIZE] = {2,4,6,8,10};
    printf("印出a陣列 = %p\n", a); // 相當於印出a[0]的地址
    printf("印出b陣列 = %p\n", b);

    printArray(a, ASIZE);
    printArray(b, BSIZE);
    return 0;
}

// 輸出
// 印出a陣列 = 0061FF14
// 印出b陣列 = 0061FF00
// array is at 0061FF14
// array[0] = 3
// array[1] = 5
// array[2] = 7
// array is at 0061FF00
// array[0] = 2
// array[1] = 4
// array[2] = 6
// array[3] = 8
// array[4] = 10
```

### 使用函數對陣列操作

-   因為陣列是實際參數，所以可以用函數的方式去對陣列操作

```c
// TODO: 將陣列各數值+1
#include <stdio.h>
#include <stdlib.h>
#define ASIZE 5

void printArray(int array[], int n){
    printf("array is at %p\n", array);
    for (int i = 0; i < n; i++){
        printf("array[%d] = %d ", i, array[i]);
    }
    printf("\n");
    return;
}

void addArray(int array[], int n){
    printf("array is at %p\n", array);
    for (int i = 0; i < n; i++){
        array[i]++;
    }
}

int main(void){
    int a[ASIZE] = {2,4,6,8,10};
    printf("印出a陣列 = %p\n", a); // 相當於印出a[0]的地址
    printArray(a, ASIZE);
    addArray(a, ASIZE);
    printArray(a, ASIZE);
    return 0;
}

// 輸出
// 印出a陣列 = 0061FF0C
// array is at 0061FF0C
// array[0] = 2 array[1] = 4 array[2] = 6 array[3] = 8 array[4] = 10
// array is at 0061FF0C
// array is at 0061FF0C
// array[0] = 3 array[1] = 5 array[2] = 7 array[3] = 9 array[4] = 11
```

### 陣列中找特定值

-   定義一個函數 match(要找的值, 陣列本身, 陣列長度)
    -   如果找到，返回位置
    -   找不到，返回-1

```c
int match(int key, int keys[], int n){
    for (int i = 0; i < n; i++){
        if (key == keys[i]){
            return i;
        }
    }
    return -1;
}

int main(void){
    int key = 2;// 要找的值
    int keys[] = {3, 4, 6, 2, 8, 10};
    int size = sizeof(keys) / sizeof(int);
    printf("%d\n", match(key, keys, size));
    return 0;
}
```

## 指標

-   %p：用於輸出記憶體地址

### 變數地址存取

```c
// TODO: 分別取址跟取值
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 110;
    char ch = 'A';
    printf("nun\t %d\t %p\n", num, &num);
    printf("ch\t %d\t %c\t %p\n", ch, ch, &ch);
    return 0;
}
```

### 陣列地址存取

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num[5] = {1,2,3,4,5};
    size_t length = sizeof(num) / sizeof(num[0]);
    puts("長度   元素    地址");
    for(int i=0;i<length;i++){
        printf("%d\t %d\t %p\n", i, num[i], &num[i]);
    }
    return 0;
}
```

### 宣告指標變數

-   無法變更指標所指向的 data type

```c
// TODO: 宣告方式
int *x;
int *x, *y;
int *y=NULL;
float *fptr;
double *dptr;
```

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a1=40, a2=50, a3=60;
    int *p1 = &a1;
    int *p2 = &a2;
    int *p3 = &a3;
    printf("%p\t %d\n", p1, *p1);
    printf("%p\t %d\n", p2, *p2);
    printf("%p\t %d\n", p3, *p3);
    return 0;
}
```

### 查看指標大小

```c
#include <stdio.h>
#include <stdlib.h>


int main(void){
    int *iptr;
    float *fptr;
    double *dptr;
    printf("sizeof(iptr) = %d\n", sizeof(iptr));
    printf("sizeof(fptr) = %d\n", sizeof(fptr));
    printf("sizeof(dptr) = %d\n", sizeof(dptr));
    return 0;
}
```

### 指標交換變數值

```c
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int i=1;
    int j=2;
    swap(&i, &j);
    printf("i = %d, j = %d\n", i, j);
    return 0;
}
```

### 利用指標處理陣列

-   將陣列元素+3

```c
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a[] = {1,2,3,4,5};
    // 建立指標
    int *ptr = a;
    for (int i = 0; i < 5; i++){
        printf("%p\n", ptr); // 印出元素地址
        *ptr +=3; // 透過指標取值的方式+3
        ptr++; // 指標往下一個邁進
    }

    for (int i = 0; i < 5; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}

// 輸出
// 0061FF00
// 0061FF04
// 0061FF08
// 0061FF0C
// 0061FF10
// a[0] = 4
// a[1] = 5
// a[2] = 6
// a[3] = 7
// a[4] = 8
```

### 指標變數當陣列使用

```
*(ptr + i)：取的陣列內容的值
    ptr 是指向陣列第一個元素的指標
    ptr + i 會移動到第 i 個元素的記憶體位置。
    *(ptr + i) 會解引用該位置，取得該元素的值。

ptr[i]：取的陣列內容的值
    是*(ptr + i) 的語法糖，
    編譯器會自動將 ptr[i] 轉換為 *(ptr + i)

ptr + i：取的陣列內容的地址
&ptr[i]：取的陣列內容的地址
```

```c
#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 5

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = %d (Address: %p)\n", i, a[i], (void*)&a[i]);
    }
    printf("\n");
}

int main(void){
    int a[ARRAYSIZE]={1,2,3,4,5};
    int *ptr = a;
    // TODO: 利用ptr[i] 修改值
    for (int i = 0; i < 5; i++){
        ptr[i] += 3;
    }
    printArray(a, ARRAYSIZE);

    // TODO: 利用ptr[i] 修改值
    ptr = &(a[0]);
    for (int i = 0; i < 5; i++){
        ptr[i] += 3;
    }
    printArray(a, ARRAYSIZE);
    return 0;
}
```

### 將指標作為回傳值

```c
#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 10

int *firstPositive(int *ptr){
    while (*ptr == 0){
        ptr++; // 如果是0的話就往後
    }
    return ptr;
}

int main(void){
    int array[ARRAYSIZE]={0,0,0,5,9,0,0,6,0,2};
    int *iptr = firstPositive(array);
    printf("*iptr = %d\n", *iptr);
    printf("iptr - array = %ld\n", iptr - array);
    iptr = firstPositive(&(array[5]));
    printf("*iptr = %d\n", *iptr);
    printf("iptr - array = %ld\n", iptr - array);
    return 0;
}

// 輸出
// *iptr = 5
// iptr - array = 3
// *iptr = 6
// iptr - array = 7
```

### 雙重指標

-   指標是指向資料型態
-   雙重指標是指向目標的指標

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    // a1 <- p1 <- p2
    int a1 = 10;       // 定義整數變數 a1
    int *p1 = &a1;     // 定義指向 a1 的指標 p1
    int **p2 = &p1;    // 定義指向 p1 的指標 p2

    puts("元素\t地址\t\t值");
    printf("a1:\t %p\t %d\n", &a1, a1);
    printf("p1:\t %p\t %p\t %d\n", &p1, p1, *p1);
    printf("p2:\t %p\t %p\t %p\n", &p2, p2, *p2);

    // 解釋 p2 解引用兩次的值（即 a1 的值）
    printf("**p2: %d\n", **p2);
    return 0;
}

```

### 指標運算

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int no;
    int *int_ptr = &no;

    printf("int_ptr = %p\n", int_ptr);
    int_ptr++;
    printf("int_ptr = %p\n", int_ptr);
    int_ptr--;
    printf("int_ptr = %p\n", int_ptr);
    int_ptr += 2;
    printf("int_ptr = %p\n", int_ptr);
    int_ptr -= 2;
    printf("int_ptr = %p\n", int_ptr);
    return 0;
}
```

### 指標常數與陣列

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int no [4] = {10, 12, 14, 16};
    printf("%p\n", no); // 陣列本身地址 = 陣列第一個元素的地址
    printf("%d\n", *(no)); // 取值


    int num[2][4]= {
        312, 16, 35, 65,
        52, 111, 77, 80
    };
    // 計算行數與列數
    size_t m = sizeof(num) / sizeof(num[0]);
    size_t n = sizeof(num[0]) / sizeof(num[0][0]);


    printf("%p\n", *(num+1)); //
    printf("%p\n", *(num+1)+1); //
    printf("%d\n", *(*(num+1)+1)); //

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t", *(*(num+i)+j));
        }
    }
    return 0;
}

```

## 字元

### 計算字元大小

```c
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char c = 'c';
    printf("%ld\n", sizeof(c));
    printf("%c\n", c);
    return 0;

}

// 輸出
// 1
```

### 常用函數<ctype.h>

-   isalnum(int c) 檢查字符是否為字母或數字（a-z、A-Z、0-9）。
-   isalpha(int c) 檢查字符是否為字母（a-z、A-Z）。
-   isdigit(int c) 檢查字符是否為數字（0-9）
-   islower(int c) 檢查字符是否為小寫字母（a-z）。
-   isupper(int c) 檢查字符是否為大寫字母（A-Z）。
-   isspace(int c) 檢查字符是否為空白字符（空格、換行 \n、回車 \r、製表符 \t 等
-   ispunct(int c) 檢查字符是否為標點符號（非字母、數字、空白字符的可打印字符）
-   iscntrl(int c) 檢查字符是否為控制字符（ASCII 0-31 和 127）
-   tolower(int c) 將大寫字母轉換為小寫字母。
-   toupper(int c) 將小寫字母轉換為大寫字母。

## 字串

-   字串就是字元陣列

```c
// TODO: 一個字元占1個位元，80個字元占80個位元
#include <stdio.h>
#include <stdlib.h>

#define STRINGLEN 80
int main(void)
{

    char s[STRINGLEN];
    printf("%ld\n", sizeof(s));
    return 0;
}
```

```c
// TODO: 使用字元陣列模擬字元
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char string[STRINGLEN];
    char *ptr = string;;
    return 0;
}
```

### 字元指標

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGLEN 80

int main(void){
    char string[STRINGLEN];
    char *ptr = string;
    scanf("%s", ptr); // 字元指標直接把整串字串輸出
    printf("%s\n", ptr);
    // 用陣列的方式輸出
    for (int i = 0; i < strlen(ptr); i++){
        printf("%c ", ptr[i]);
    }
    return 0;
}

// 輸出
// asdfg
// a s d f g
```

### 不同字串格式各有不同的記憶體空間

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGLEN 80

int main(void){
    char str1[STRINGLEN] = "programming"; // 本身宣告空間80byte
    char str2[] = "programming"; // 給內容，讓編譯器自己算(後面加\0)
    char *str3 = "programming"; // 指針
    printf("sizeof(str1) = %ld\n", sizeof(str1));
    printf("sizeof(str2) = %ld\n", sizeof(str2));
    printf("sizeof(str3) = %ld\n", sizeof(str3));
    return 0;
}

// 輸出
// sizeof(str1) = 80
// sizeof(str2) = 12
// sizeof(str3) = 4
```

### 字串函數

#### strlen：計算字串長度

```c
// TODO: 計算字串長度，並倒者印出字串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGLEN 80

int main(void){
    char string[] = "abcdefg";

    int length = strlen(string);
    printf("%d\n", length);
    // 將字串左右顛倒
    for (int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length -i - 1];
        string[length - i - 1] = temp;
    }
    printf("%s\n", string);
    return 0;
}

// 輸出
// 7
// gfedcba
```

```c
// TODO: 手刻strlen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char *string){
    int i = 0;
    while(string[i]!='\0'){
        i++;
    }
    return i;
}

int main(void){
    char string[] = "abcdefg";
    int length = mystrlen(string);
    printf("%d\n", length);
    return 0;
}
```

#### strcpy、strcat：複製字串

-   會發生緩衝區覆蓋(buffer overrun)

```
char *strcpy(char *destination, *source)
- 將source字串複製到destination字串，並回傳destination位址。
- source字串的結尾'\0'，也會依同複製
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGLEN  10

int main(void){
    char source[] = "abcdefg";
    char destination[STRINGLEN];
    strcpy(destination, source);
    printf("%s\n", destination);
    return 0;
}
```

```
char *strcat(char *destination, *source)
- 將source字串複製並接到destination字串後面
- source字串的結尾'\0'，也會依同複製
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGLEN  10

int main(void){
    char source[] = "abcdefg";
    char destination[] = "123";
    strcat(destination, source);
    printf("%s\n", destination);
    return 0;
}
```

#### 比較 3 種字串在 strcpy 處理(重要)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char string1[80] = "programming";
    char string2[] = "programming";
    char *string3 = "programming";
    strcpy(string1, "more programming");
    strcpy(string2, "more programming");
    strcpy(string3, "more programming"); // error，因為字串常量放在.rodata，不能錯修改
    return 0;
}
```

#### strncpy、strncat 第三個參數(處理緩衝區覆蓋，但要手動'\0')

```
char *strncpy(char *destination, *source, int i)
- 將source字串複製到destination字串，並回傳destination位址，限制複製i個字元
- 如果 source 的長度小於 n，strncpy 會用空字元 \0 填充到 n 的長度。
- 如果 source 的長度大於或等於 n，則 strncpy 不會自動在 destination 的結尾添加 \0。
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char source[] = "This is a string.";
    char destination[4];
    strncpy(destination, source, 3);
    destination[3] = '\0';
    printf("source <%s>\n", source);
    printf("strlen(source) = %d\n",strlen(source)); // 17
    printf("sizeof(source) = %zu\n", sizeof(source)); // 18
    printf("destination <%s>\n",destination);
    return 0;
}

// 輸出
// source <This is a string.>
// strlen(source) = 17
// sizeof(source) = 18
// destination <Thi>
```

#### strcmp、strncmp 字串比較

```
int strcmp(char *string1, *string2);
int strncmp(char *string1, *string2, int n);
```

-   範例：12 生肖排序
    -   [12 生肖陣列排序](./Zodiac%20Sort/ZodiacSort01.c)
    -   [12 生肖指標排序](./Zodiac%20Sort/ZodiacSort02.c)

#### strchr、strrchrr、strstr

```
char *strchr(char *string, char c); // 前往後找c，返回找到目標的地址
char *strrchr(char *string, char c); // 後往前找c，返回找到目標的地址
```

-   [strchr 將路徑中的每個子資料夾名稱抽出](./strchr/strchr.c)

```
char *strstr(char *string1, char *string2); 在string1中找string2，找到返回string2出現第址
```

-   [在 12 生肖中找有 er 字串的](./strchr/strstr.c)

#### 切割字串

```
char *strtok(char *string, delimeters);
```

-   [切割字串](./strchr/strtok.c)

## 宣告修飾

### 輸出各整數類別位元小

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    printf("sizeof(short int) = %ld\n",sizeof(short int));
    printf("sizeof(int) = %ld\n",	 sizeof(int));
    printf("sizeof(long) = %ld\n",	 sizeof(long));
    printf("sizeof(long int) = %ld\n",	 sizeof(long int));
    printf("sizeof(long long int) = %ld\n", 	 sizeof(long long int));
    return 0;
}

// 輸出
// sizeof(short int) = 2
// sizeof(int) = 4
// sizeof(long) = 4
// sizeof(long int) = 4
// sizeof(long long int) = 8
```

### C99 有號數

-   解決了不同平台上整數大小不一致的問題

```c
#include <stdint.h>


int main(void){
    printf("sizeof(uint8_t) = %ld\n",	 sizeof(uint8_t));
    printf("sizeof(uint16_t) = %ld\n",	 sizeof(uint16_t));
    printf("sizeof(uint32_t) = %ld\n",	 sizeof(uint32_t));
    printf("sizeof(uint64_t) = %ld\n", 	 sizeof(uint64_t));
    printf("UINT8_MAX = %u\n", UINT8_MAX);
    printf("UINT16_MAX = %u\n", UINT16_MAX);
    printf("UINT32_MAX = %u\n", UINT32_MAX);
    printf("UINT64_MAX = %lu\n", UINT64_MAX);
    return 0;
}

// 輸出
// sizeof(short int) = 2
// sizeof(int) = 4
// sizeof(long) = 4
// sizeof(long int) = 4
// sizeof(long long int) = 8
// INT8_MIN = -128 INT8_MAX = 127
// INT16_MIN = -32768 INT16_MAX = 32767
// INT32_MIN = -2147483648 INT32_MAX = 2147483647
// INT64_MIN = 0
// INT64_MAX = -2147483648
```

### C99 無號數

```c
#include <stdint.h>


int main(void){
    printf("sizeof(uint8_t) = %ld\n",	 sizeof(uint8_t));
    printf("sizeof(uint16_t) = %ld\n",	 sizeof(uint16_t));
    printf("sizeof(uint32_t) = %ld\n",	 sizeof(uint32_t));
    printf("sizeof(uint64_t) = %ld\n", 	 sizeof(uint64_t));
    printf("UINT8_MAX = %u\n", UINT8_MAX);
    printf("UINT16_MAX = %u\n", UINT16_MAX);
    printf("UINT32_MAX = %u\n", UINT32_MAX);
    printf("UINT64_MAX = %lu\n", UINT64_MAX);
    return 0;
}

// 輸出
// //sizeof(uint8_t) = 1
// sizeof(uint16_t) = 2
// sizeof(uint32_t) = 4
// sizeof(uint64_t) = 8
// UINT8_MAX = 255
// UINT16_MAX = 65535
// UINT32_MAX = 4294967295
// UINT64_MAX = 4294967295t) = 8
```

### const 指標

```
int *ptrToInt = &i; ptrToInt 一個指向 int 型別變數的指標
const int *ptrToConstInt = &i; 一個指向 const int 型別變數 的指標(可以用*區分) => 不能透過指標修改目標變數的值，但可以改變指標的指向
int * const constPtrToInt = &i; 一個指向 int 的 常量指標 => 只能指向初始化時的地址，但可以透過指標修改目標變數的值
```

### static

-   更改生命週期：從程式開始執行時初始化，一直存在於程式運行期間，直到程式結束才會被銷毀。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void foo(void){
    int i = 0;
    i++;
    printf("foo: i = %d ", i);
}
void bar(void){
    static int i = 0;
    i++;
    printf("bar: i = %d ", i);
}


int main(void){
    for (int j = 0; j < 5; j++){
        foo();
    }
    printf("\n");
    for (int j = 0; j < 5; j++){
        bar();
    }
    return 0;
}

// 輸出
// foo: i = 1 foo: i = 1 foo: i = 1 foo: i = 1 foo: i = 1
// bar: i = 1 bar: i = 2 bar: i = 3 bar: i = 4 bar: i = 5
```

## 結構(structuure)

-   一名學生有以下資料：
    -   name：string
    -   student ID：string
    -   phone：string
    -   各學期平均成績：float[]
    -   birth：3 個 int

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct student {
    char name[10];
    char id[20];
    char phone[20];
    float grade[4]; // 16
    int birthYear, birthMonth, birthDay; // 12
};

int main(void){
    struct student john;
    printf("sizeof(john) = %ld\n", sizeof(john));
    return 0;
}
```

### 結構初始化

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct student {
    char name[10];
    char id[20];
    char phone[20];
    float grade[4]; // 16
    int birthYear, birthMonth, birthDay; // 12
};

int main(void){
    struct student john = {
        "John Smith",
        "12345",
        "1234567",
        {4.0, 3.9, 3.8, 3.6},
        2000, 1, 1
    };
    printf("name is %s\n", john.name);
    printf("id is %d\n", john.id);
    printf("phone is %s\n", john.phone);
    printf("john.grade[0] is %f\n", john.grade[0]);
    return 0;
}
```

### 結構指標

-   按照正常想法，如果要在結構指標取值，需要先使用星號取整個結構的值，在用結構的語法 => \*(ptr).id
-   可以直接寫成 ptr->id

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct student {
    char name[10];
    char id[20];
    char phone[20];
    float grade[4]; // 16
    int birthYear, birthMonth, birthDay; // 12
};

int main(void){
    struct student john = {
        "John",
        "12345",
        "1234567",
        {4.0, 3.9, 3.8, 3.6},
        2000, 1, 1
    };
    struct student *ptr = &john;
    strcpy(ptr->phone, "00000"); // 使用 strncpy 複製字符串，避免超出邊界
    printf("name is %s\n", ptr->name);
    printf("phone is %s\n", ptr->phone);
    return 0;
}

// 輸出
// name is John
// phone is 00000
```

-   [使用結構處理負數](./complex/complex01.c)
-   [結構傳遞](./complex/complex02.c)

### typedef

-   結構在初是化實，要寫兩個英文字母，typedef 可以把它節和在一起
-   [在結構中使用 typedef](./complex/complex03.c)

### 結構標題檔

-   [可以把結構用標題檔儲存](./complex/complex04.c)

### 在結構中使用結構

-   [在結構中使用結構](./complex/student01.c)

## 程式記憶體分段

-   程式在執行時，會將記憶體劃分為不同的區域（分段）
-   每個區域用於存儲不同類型的數據
-   安全性：將程式碼與數據分離，防止數據被意外修改。
-   效率：根據數據的特性（例如是否可修改、是否初始化）進行分類存儲，提高記憶體使用效率。
-   管理方便：分段後，作業系統可以更輕鬆地管理記憶體，例如設置唯讀保護或動態分配記憶體。

## recusion

-   [遞迴費博那係數](./recusion/fib.c)
-   [實作最大公因數](./recusion/gcd.c)
-   [實作和內塔](./recusion/hanio.c)

### 常見的分段（Sections）

#### .text 段：存儲程式的機器指令（即編譯後的程式碼）

-   通常是唯讀的，防止程式碼被意外修改。
-   包含函數的實現（例如 main 函數）。

#### .data 段：已初始化的全局變數和靜態變數

-   變數的值在編譯時就已經確定。
-   通常是可讀寫的。

#### .bss 段：存儲未初始化的全局變數和靜態變數。

-   變數的值在程式啟動時會被初始化為零。
-   不佔用可執行文件的大小，因為只記錄變數的大小。

#### .rodata 段：存儲唯讀數據，例如字串常量和全局 const 變數。

-   通常是唯讀的，防止數據被修改。
-   可以節省記憶體，因為相同的常量可能會被共享。
-   `const char *str = "Hello, World!";  // 字串常量存儲在 .rodata 段`

## 檔案處理

-   開啟檔案方式

```c
#include <stdio.h>
FILE *fp;
fp = open(filename, option)

fclose(fp); //關閉檔案

// 開啟模式
// r
// w：
// a：append
```

### 以字元處理檔案

```c
int fget(FILE *p) // 讀取字元並回傳
int fput(int c, FILE *p) // 寫入(成功寫入的話也會回傳)
```

### 重複讀取字元到 EOF

```c
while((c=fget(fp))!=EOF){

}
```

-   [文字覆蓋範例](./file/file01.c)
-   [文字添加範例](./file/file02.c)
-   [文字讀寫範例](./file/file03.c)

### 以行處理檔案

```c
int fgets(char *string, int num, FILE *p) // 讀取一行並回傳
int fputs(const char *string, FILE *p) // 寫入(成功寫入的話也會回傳)

// 使用fgets讀檔
#define STRINGLEN 128
char string[STRINGLEN];

while(fgets(string, STRINGLEN, fp)!=NULL){
    // ...
}
```

-   [以 fput 逐行寫入，在逐行讀取](./file/file04.c)

### 以格式處理檔案

```c
int fprintf(FILE *fp, const char *format, ...);
int fscanf(FILE *fp, const char *format, ...);
```

-   [使用 fprintf，fscanf 讀寫檔案](./file/file05.c)

### 二進制檔案處理

-   [文字與二進制差別](./file/file06.c)

### 緩衝區為主的輸出入

-   緩衝區(buffer)是一塊記憶體，用來暫存數據，避免每次寫入或讀取文件時都直接操作磁碟，提升效率。

```c
int fread(void *buffer, int size, int n, FILE *fp);
// fread以二進制的方式，由fp連結的檔案中讀取n筆資料，每筆資料大小為size
// 這些資料由檔案讀到buffer

int fwrite(const void *buffer, int size, int n, FILE *fp);
// fwrite以二進制的方式將n筆資料大小為size的資料從buffer寫到檔案
```

-   [使用 fread，fwrite](./file/file07.c)
-   [將 struct 取操作](./file/file08.c)

### fseek 移動讀寫位置

```c
int fseek(FILE *fp, long int offset, int base);
// 將讀寫位置跳到offset及base所指示的位置
// offset 是以byte為單位
// base可分為3種：
//  SEEK_SET：從檔案開頭開始計算位移量 offset
//  SEEK_CUR：從目前檔案指標位置開始計算位移量 offset
//  SEEK_END：從檔案結尾開始計算位移量 offset
```

-   [使用 fseek 操作檔案](./file/file09.c)

### EOF 測試

-   前面都是使用 fget 去檢查回傳質是否為 EOF，其實 stdio.h 也有專門測試 EOF 的函數
-   EOF 是一種狀態，而非一種字元

```c
int feof(FILE *fp)

// 讀取檢查
int c = fget(fp);
while(!feof(fp)){
    // ...
    c = fget(fp);
}
```

## 動態記憶體配置

-   malloc：跟系統要記憶體
-   free：還系統記憶體

```c
#include <stdlib>
void *malloc(int size);
void free(void *ptr);
```

-   [跟系統要求一個 int 的記憶體空間](./dynamic%20memory/malloc01.c)
-   [跟系統要求一個結構的記憶體空間](./dynamic%20memory/malloc02.c)

## LinkList(可以用力扣去說明)

-   節點概念

```c
typedef struct listNode{
    int data;
    struct listNode *next;
}ListNode;
```

-   [建立 listNode](./LinkList/create_node.c)
-   [遍歷 listNode](./LinkList/traverse_node.c)

## 前置處理

### #include

### #define

### 條件編譯(#if)

```c
#define DEBUG_LEVEL 4

#if DEBUG_LEVEL==3
執行...
#endif

#if DEBUG_LEVEL==4
執行...
#endif
```

-   有時候我們需要修改 DEBUG_LEVEL 的值，但又不想到檔案內修改，可以使用命令行去修改

```
gcc -DEBUG_LEVEL=8 program.c
```

-   但這樣會有重複定義的問題，因此程式碼可以修改成

```c
#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 4
執行...
#endif
```

### `__LINE__ __FILE__`

-   取得當前程式碼的行號和檔案名

```
__LINE__	取得當前行號（整數）
__FILE__	取得當前檔案名稱（字串）
```

```c
#include <stdio.h>

int main() {
    printf("這行是第 %d 行，檔案名稱是 %s\n", __LINE__, __FILE__);
    return 0;
}
// 輸出
// 這行是第 4 行，檔案名稱是 .\test.c
```

## C standard library (stdlib)

### 排序：qsort

```c
void qsort(void *base, int num, int size, int(*compare)(const void*, const void*))
```

-   [qsort](./Stdlib/qsort.c)
-   [qsort 排序日期](./Stdlib/qsort_date.c)
-   [qsort 排序字串陣列](./Stdlib/qsort_string.c)
-   [以 1 的個數做排序](./Stdlib/qsort_1bit.c)

### 字串轉換函數：

```
atoi(const char *str)：string to int
atol(const char *str)：string to long
atof(const char *str)：string to float
strtol(const char *str, char **ptr, int base)：字串依照基底轉換為長整數
```

-   [字串轉數值](./Stdlib/stdlib_conversion.c)

### 產生隨機數：

```c
#include <time.h>

void srand(unsigned int seed); // 設定隨機數產生器的種子
int rand(void); // 產生一個範圍在 0 到 RAND_MAX 之間的隨機整數
```

-   [隨機數](./Stdlib/rand.c)

## 分段在記憶體中的佈局(從低地址到高地址)

-   .text 段：存儲程式碼。
-   .rodata 段：存儲唯讀數據。
-   .data 段：存儲已初始化的全局變數。
-   .bss 段：存儲未初始化的全局變數。
-   Heap（堆）：用於動態記憶體分配（例如 malloc）。
-   Stack（堆疊）：用於存儲區域變數和函數調用信息。

## C 語言的命令列參數（Command Line Arguments）

```
int main(int argc, char *argv[])
// argc：參數的個數（包含程式本身）
// *argv[]：參數的陣列
```

-   [列出命令列參數](./Command_Line_Arguments/print_command_line.c)
-   [轉換數值](./Command_Line_Arguments/command_line_change.c)
-   [使用 strtol() 處理進階數字轉換](./Command_Line_Arguments/command_line_strtol.c)

## 5. GPT 給的學習關鍵字

### 系統核心功能

-   檔案操作：`fopen()`、`fwrite()`、`fread()`、`fseek()`、`fprintf()`
-   記憶體管理：`malloc()`、`calloc()`、`realloc()`、`free()`
-   指標進階：雙重指標、函式指標、結構指標。

### 多執行緒與並行程式設計

-   Pthreads：`pthread_create()`、`pthread_join()`、多執行緒應用，如處理器密集型任務。
-   同步機制：互斥鎖 (`pthread_mutex`)、條件變數 (`pthread_cond`)、信號量。
-   網路程式設計：`socket()`、`bind()`、`listen()`、`connect()`、`send()`、`recv()`。

### 嵌入式系統基礎

-   硬體控制：GPIO、I2C、SPI、UART。
-   FreeRTOS。

### C++ 進階學習關鍵

-   物件導向 (OOP)
-   模板 (Template)
-   錯誤處理機制
-   標準模板庫 (STL)
-   多執行緒與並行程式設計：`std::thread`、`std::mutex`、`std::future`。
-   Lambda 表達式
-   智能指標：`std::shared_ptr`、`std::unique_ptr`。

## 還沒處理的

-   C 語言式如何處理不定個數參數的問題
-   分段在記憶體中的佈局(從低地址到高地址)
    -   .text 段：存儲程式碼。
    -   .rodata 段：存儲唯讀數據。
    -   .data 段：存儲已初始化的全局變數。
    -   .bss 段：存儲未初始化的全局變數。
    -   Heap（堆）：用於動態記憶體分配（例如 malloc）。
    -   Stack（堆疊）：用於存儲區域變數和函數調用信息。
