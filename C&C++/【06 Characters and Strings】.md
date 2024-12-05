## Fundamentals of Strings and Characters
### 字元 (Characters)
- 程式由一系列字元組成，電腦將這些字元解讀為指令執行。
- 字元常數 (Character Constants)：
	- 使用單引號包裹的字元，如 'z' 或 '\n'。
	- 字元常數的值是該字元在機器字元集（如 ASCII）中的整數值，例如 'z' 的值為 122，'\n' 的值為 10。
### 字串 (Strings)
- 字串是一系列字元組成的單一單位，包含字母、數字、特殊符號等。
- 字串以雙引號表示，例如 "blue"。
- 字串是以空字元 '\0' 結尾的字元陣列。
- 字串的值是其首個字元的地址，因此字串可視為指向字串首字元的指標。
### 字元陣列與指標初始化
```c
// 字元陣列初始化
char color[] = "blue"; // 自動創建 5 個元素的陣列，包含 '\0'

// 字串指標初始化
const char *colorPtr = "blue"; // colorPtr 是指向字串的指標
// 也就等於
char color[] = {'b', 'l', 'u', 'e', '\0'}; // 手動初始化字元陣列
```
-  使用 scanf 讀取字串
```c
char word[20];
scanf("%s", word); // 讀取使用者輸入的字串至陣列 word

// 注意字串長度限制：必須限制讀取的字串長度，以防止超出陣列邊界，
scanf("%19s", word); // 最多讀取 19 個字元，預留 1 位給 '\0'
```
### C 語言字元處理函數 (<ctype.h>) 
- 提供一系列函數，用於測試和操作字元數據。
- 接受一個無符號字元（unsigned char，以 int 表示）或特殊值 EOF 作為參數。
	- EOF：表示文件結尾，通常值為 -1。
```c
#include <stdio.h>

int main() {
    int c;
    printf("請輸入字元 (Ctrl+D 或 Ctrl+Z 結束):\n");
    while ((c = getchar()) != EOF) {  // 判斷是否為 EOF
        putchar(c); // 輸出讀取的字元
    }
    printf("\n已到達文件結尾 (EOF)。\n");
    return 0;
}
```
### 常用字元測試函數
![upgit_20241119_1732001252.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732001252.png)

![upgit_20241119_1732001262.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732001262.png)

- isdigit, isalpha, isalnum and isxdigit
![upgit_20241119_1732001343.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732001343.png)

![upgit_20241119_1732001378.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732001378.png)

![upgit_20241119_1732001393.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732001393.png)

- islower, isupper, tolower and toupper
![upgit_20241119_1732001475.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732001475.png)

![upgit_20241119_1732001487.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732001487.png)

![upgit_20241119_1732001504.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732001504.png)

## String-Conversion Functions
- 字串轉換函數屬於 C 語言的通用工具庫 <stdlib.h>。
- 這些函數將字串中的數字轉換為整數或浮點數值。
![upgit_20241119_1732001617.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732001617.png)
### Function strtoul
- 將字串中的浮點數字轉換為 double 型態。
- 第一個參數：字串 (`char *`)，包含要轉換的數字。
- 第二個參數：指向指標的指標 (`char **`)，用於返回轉換後剩餘字串的指標位置。
```c
char string[] = "51.2abc";
char *stringPtr;
double d = strtod(string, &stringPtr);
printf("轉換結果: %.2f\n剩餘字串: %s\n", d, stringPtr);
// 結果：d = 51.2，stringPtr = "abc"。
```
### Function strtol 
- 將字串中的整數數字轉換為 long int 型態。
- 第一個參數：字串 (`char *`)，包含要轉換的數字。
- 第二個參數：指向指標的指標 (`char **`)，用於返回轉換後剩餘字串的指標位置。
- 第三個參數：整數 (int)，指定進位基數 (2–36)，如 0 表示自動判斷（八進位、十進位或十六進位）。
```c
char string[] = "101101abc";
char *remainderPtr;
long x = strtol(string, &remainderPtr, 2); // 以二進位轉換
printf("轉換結果: %ld\n剩餘字串: %s\n", x, remainderPtr);
// 結果：x = 45，remainderPtr = "abc"。
```

## Standard Input/Output Library Functions
- 來自標準 I/O 函數庫 `<stdio.h>`，主要用於操作字元與字串數據。
![upgit_20241119_1732002043.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732002043.png)

![upgit_20241119_1732002057.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732002057.png)

### `fgets` 和 `putchar`
- `fgets`：
	- 從輸入流（如鍵盤）讀取一行字元，直到換行符、EOF 或達到最大長度。
	- 自動在讀取的字串後加上終止符 `\0`。
- `putchar`：
    - 輸出單個字元。
```c
// 將輸入的字串以遞迴方式反轉並輸出。
// 使用 `fgets` 讀取字串。
// 使用遞迴函數反向輸出字元，`putchar` 輸出每個字元。
char line[100];
fgets(line, 100, stdin);
reverse(line);

void reverse(char *sPtr) {
	if (*sPtr == '\0') return;
	reverse(sPtr + 1);
	putchar(*sPtr);
}
```
###  `getchar` 和 `puts`
- `getchar`：從標準輸入讀取一個字元，返回其 ASCII 值。
- `puts`：將字串輸出並自動加換行符。
```c
// 讀取最多 79 個字元，並輸出整行字串。
char sentence[80];
int i = 0;
char c;
while (i < 79 && (c = getchar()) != '\n') {
	sentence[i++] = c;
}
sentence[i] = '\0'; // 添加結尾符號
puts(sentence);
```
### `sprintf`
- 格式化輸出至字元陣列。
- 與 `printf` 用法類似，但輸出目標為字元陣列而非標準輸出流。
```c
// 將格式化的整數與浮點數儲存至字元陣列。
char s[100];
int i = 42;
double d = 3.14159;
sprintf(s, "整數: %d, 浮點數: %.2f", i, d);
printf("%s\n", s); // 輸出格式化字串
```
### `sscanf`
- 從字元陣列讀取格式化數據。
- 與 `scanf` 用法類似，但從字元陣列中讀取數據。
```c
// 從字元陣列讀取整數和浮點數。
char s[] = "42 3.14";
int x;
double y;
sscanf(s, "%d %lf", &x, &y);
printf("整數: %d, 浮點數: %.2f\n", x, y);
```

### strcpy 與 strncpy 函數
- strcpy：將來源字串（x）的所有內容複製到目標字串陣列（y），且自動加入終止符（\0）。
- strncpy：複製來源字串的前 N 個字元到目標字串陣列（z），但不會自動加入終止符（\0）
```c
char x[] = "Hello, world!";
char y[20];
char z[15];

strcpy(y, x);             // 完整複製字串
strncpy(z, x, 14);        // 複製前 14 個字元，需手動補上 '\0'
z[14] = '\0';             // 手動添加終止符
```
### strcat 與 strncat 函數
- strcat：
	- 將第二個字串（來源）附加到第一個字串（目標）的尾部。
	- 自動取代第一個字串的終止符（\0）。
- strncat：附加來源字串的前 N 個字元到目標字串，並加上終止符（\0）。
```c
char dest[50] = "Hello, ";
char src[] = "world!";

strcat(dest, src);       // 結果為 "Hello, world!"
strncat(dest, src, 3);   // 附加 "wor"，結果為 "Hello, world!wor"
```

## Comparison Functions of the String-Handling Library 
![upgit_20241119_1732002941.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732002941.png)

![upgit_20241119_1732003004.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732003004.png)

![upgit_20241119_1732003015.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732003015.png)

### 字串比較函數
- strcmp：逐字元比較兩個字串。
- strncmp：比較兩個字串的前 N 個字元。
```c
char str1[] = "Jones";
char str2[] = "Smith";
printf("%d\n", strcmp(str1, str2)); // 比較整個字串
printf("%d\n", strncmp(str1, str2, 2)); // 比較前 2 個字元
```
## Search Functions of the String-Handling Library
### 字串搜尋函數
- strchr：尋找字串中 第一次 出現的指定字元，返回指向該字元的指標，若未找到返回 NULL。
- strrchr：尋找字串中 最後一次 出現的指定字元，返回指向該字元的指標，若未找到返回 NULL。
```c
char str[] = "This is a test";
printf("%s\n", strchr(str, 'a'));  // 返回 "a test"
printf("%s\n", strrchr(str, 'a')); // 返回 "animals including zebras."
```
### 字串分割函數
- 將字串分割為多個子字串(Token)。
- 第一個參數：欲分割的字串。
- 第二個參數：分隔符字元組成的字串。
```c
char str[] = "This is a test";
char *token = strtok(str, " ");
while (token != NULL) {
    printf("%s\n", token); // 輸出每個子字串
    token = strtok(NULL, " ");
}
```
## Memory Functions of the String-Handling Library 
- 主要用途：
	- 操作內存塊（字元陣列或其他數據塊）。
	- 提供高效靈活的內存操作。
- 指標類型 void *：
	- 可指向任意類型的數據。
	- 無法直接解引用，需搭配 size 參數來指定處理的字節數。
![upgit_20241119_1732004612.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732004612.png)

![upgit_20241119_1732004623.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732004623.png)

### memcp
- 複製指定數量的字節，從來源指標複製到目標指標。
- 若來源與目標內存重疊，結果未定義。
- 若內存可能重疊，應使用 memmove。
```c
char s1[20], s2[] = "Hello, World!";
memcpy(s1, s2, strlen(s2) + 1); // 將 s2 複製到 s1
```
### memmove
- 安全地複製字節，即使來源與目標內存重疊。
- 先將來源內容複製到臨時區域，再移動到目標區域。
```c
char x[] = "1234567890";
memmove(x, x + 5, 5); // 將後 5 個字元移動到前 5 個位置
```
### memcmp
- 功能：比較兩個內存塊的前 n 個字節。
- 返回值：
	- 0：兩內存塊相等。
	- 正值：第一內存塊大於第二。
	- 負值：第一內存塊小於第二。
```c
char s1[] = "ABC", s2[] = "ABD";
int result = memcmp(s1, s2, 3); // 比較兩個字串
```
### memchr
- 功能：搜尋內存塊中第一個匹配的字節。
- 返回值：
	- 指向匹配字節的指標。
	- 若未找到，返回 NULL。
```c
char str[] = "This is a string";
char *ptr = memchr(str, 'r', strlen(str)); // 搜尋 'r' 的位置
```
### memset
- 功能：將指定值填充到內存塊的前 n 個字節。
- 應用場景：初始化數據塊，重置內存。
```c
char str[20];
memset(str, 'b', 7); // 將前 7 個字元設為 'b'
```
## Other Functions of the String-Handling Library

![upgit_20241119_1732004901.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241119_1732004901.png)

### strerror
- 功能：根據錯誤代碼生成錯誤訊息字串。
- 返回值：指向錯誤訊息字串的指標。
```c
#include <string.h>
#include <stdio.h>

int main() {
    int errorNum = 2;
    printf("Error: %s\n", strerror(errorNum)); // 顯示 "No such file or directory"
    return 0;
}
```

### strlen
- 功能：計算字串的長度（不包括結尾的 \0 字元）。
- 返回值：字串中的字元數。
```c
#include <string.h>
#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    printf("Length: %zu\n", strlen(str)); // 返回 13
    return 0;
}
```