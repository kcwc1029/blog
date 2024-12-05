- 執行時機：預處理器在程式編譯之前執行。
- 主要功能：
	- 包含檔案：將其他檔案內容插入正在編譯的檔案中。
	- 符號常數與巨集定義：使用 #define 定義符號常數與巨集。
	- 條件編譯：根據條件選擇性編譯程式碼。
	- 條件執行指令：執行特定的預處理指令。
## `#include` Preprocessor Directive
- 功能：將指定檔案的內容插入到指令所在的位置。
- 標準庫標頭檔案：如 stdio.h、stdlib.h。
- 多檔案程式：可建立包含結構、聯合、列舉與函式原型等共用宣告的標頭檔案，供各個源檔案引入。
- `#include <filename>`：
	- 用於標準庫標頭檔案。
	- 預處理器從目前檔案所在目錄開始搜尋檔案，接著搜尋其他指定路徑。
- `#include "filename"`：
	- 用於程式設計者自訂的標頭檔案。
	- 用於標準庫標頭檔案，預處理器根據實作依賴性，搜尋系統或編譯器指定的路徑。

## `#define` Preprocessor Directive: Symbolic Constants
- 功能：
	- 定義符號常數：用符號表示常數值。
	- 定義巨集：用符號表示操作或替換內容。
- 語法：
```c
#define 標識符 替換文字 // 出現在檔案中的 標識符將被預處理器替換為 替換文字。
#define PI 3.14159 // 會將所有 `PI` 替換為 `3.14159`
```
- 優點：
	- 提高程式的可讀性和可維護性。
	- 若需修改常數值，只需在 `#define` 中修改一次即可。
- 潛在問題：
    - 語法錯誤：例如 `#define PI = 3.14159`，會導致每次出現 `PI` 時被替換為 `= 3.14159`，造成邏輯或語法錯誤。
    - 重新定義：重複定義符號常數會導致編譯錯誤。
	- 建議：優先使用 `const` 宣告變數取代 `#define`，以避免潛在錯誤。
```c
const double PI = 3.14159;
```
## `#define` Preprocessor Directive: Macros

### 巨集 (Macros)
- 定義方式：`#define 標識符(參數) 替換文字`
- 巨集是由 `#define` 預處理指令 定義的識別符號，會在編譯前將巨集名稱替換為替換文字。
- 可分為：
	- 無參數巨集：類似符號常數。
	- 有參數巨集：允許將傳入的參數替換到巨集的替換文字中。
#### 有參數巨集範例
- 計算圓的面積：
```c
#define CIRCLE_AREA(x) ((PI) * (x) * (x))

// 使用
area = CIRCLE_AREA(4); // 若巨集未加括號，運算順序可能錯誤。
```
- 計算矩形面積：
```c
#define RECTANGLE_AREA(x, y) ((x) * (y))

// 使用
rectArea = RECTANGLE_AREA(a + 4, b + 7);
```
#### 巨集的優缺點
- 優點：
  - 提升程式碼重用性。
  - 定義後可全局使用，修改方便。
- 缺點：
  - 重複計算：巨集參數可能被多次評估，導致副作用。
  - 調試困難：展開後的巨集內容可能難以排查錯誤。
### 巨集 vs 函式
- 巨集可以替代簡單的函式，但容易出現副作用（如參數多次評估）。
- 建議在複雜計算中使用函式，例如：
```c
double circleArea(double x) {
  return 3.14159 * x * x;
}
```
-  刪除巨集或符號常數：使用 `#undef` 指令。
```c
#undef CIRCLE_AREA
```
- 標準庫中的巨集：標準庫函式常以巨集形式定義。
```c
#define getchar() getc(stdin)
// 此巨集使用 `getc` 從標準輸入流讀取字符。
```
- 多行巨集：若替換文字超過一行，需在行末使用反斜線 `\`：
```c
#define MULTI_LINE_MACRO(x, y) \
	((x) + (y)) * 2
```
## Conditional Compilation(條件編譯)
- 功能：
	- 控制程式碼是否被編譯。
	- 控制預處理指令的執行。
- 運作原理：
	- 透過條件表達式決定程式碼是否被編譯。
	- 僅能評估整數常數表達式，無法處理 cast、sizeof 或列舉常數。
- `#if 和 #endif`
```c
#if 條件表達式
    // 要編譯的程式碼
#endif
```
- `#ifdef 和 #ifndef`：簡化形式，用於檢查符號常數是否已定義
```c
#ifndef 符號常數
    // 符號常數未定義時執行
#endif
```
- `#define 和 #undef`：定義或取消符號常數
```c
#define MY_CONSTANT 1
#undef MY_CONSTANT
```
- `#elif 和 #else`：支援多條件判斷（類似於 `else if` 和 `else`）
```c
#if 條件1
    // 條件1成立
#elif 條件2
    // 條件2成立
#else
    // 其他情況
#endif
```
### 範例：
- 根據條件表達式判斷是否編譯程式碼。
```c
#include <stdio.h>
#define ENABLE_FEATURE 1  // 定義一個常數，表示功能是否啟用

int main() {
#if ENABLE_FEATURE
    printf("功能已啟用。\n");
#else
    printf("功能未啟用。\n");
#endif
    return 0;
}
```
- 定義或取消符號常數。
```c
#include <stdio.h>

#define VERSION 2  // 定義程式版本

int main() {
#if VERSION == 1
    printf("這是版本 1。\n");
#elif VERSION == 2
    printf("這是版本 2。\n");
#else
    printf("未知版本。\n");
#endif

#undef VERSION  // 取消定義符號
// #ifdef VERSION 會檢查是否還存在定義
#ifdef VERSION
    printf("版本已定義。\n");
#else
    printf("版本已取消定義。\n");
#endif

    return 0;
}
```
- 檢查符號常數是否已定義。
```c
#include <stdio.h>

//#define DEBUG  // 如果取消註解，DEBUG 模式會啟用

int main() {
#ifdef DEBUG
    printf("這是調試模式。\n");
#else
    printf("這是正常模式。\n");
#endif
    return 0;
}
```
- 用於多條件判斷，類似 else if 和 else。
```c
#include <stdio.h>

#define PLATFORM 3  // 定義平台標識：1=Windows, 2=Linux, 3=MacOS

int main() {
#if PLATFORM == 1
    printf("執行於 Windows 平台。\n");
#elif PLATFORM == 2
    printf("執行於 Linux 平台。\n");
#elif PLATFORM == 3
    printf("執行於 MacOS 平台。\n");
#else
    printf("未知平台。\n");
#endif
    return 0;
}
```

## `#error and #pragma` Preprocessor Directives
### `#error`指令
- 用於顯示錯誤訊息並終止編譯。
- 常用於在編譯時檢查不符合條件的情況。
- 使用格式：
```c
#error tokens

#error 1 - Out of range error
// 此錯誤訊息包含 6 個字元組，並在某些系統上直接顯示訊息後停止編譯。
```
### `#pragma` 指令
- 用於執行實作定義的動作（與編譯器相關）。
- 非標準化指令，若編譯器不認識該指令，則會自動忽略。
- 使用格式：
```c
#pragma tokens // tokens 是由空格分隔的字符序列，具體行為由編譯器決定。
#pragma once // 指示編譯器僅包含該標頭檔一次（防止多次包含重複內容）。
```
## # and ## Operators
### `#` 運算符
- 將巨集參數轉換為字串，並加上雙引號。
- 只能用於帶參數的巨集，`#` 的操作對象是巨集的參數。
```c
#define HELLO(x) printf("Hello, " #x "\n");

// 當程式中出現 HELLO(John) 時，展開為：
printf("Hello, " "John" "\n");

// 等效於
printf("Hello, John\n");
```
### `##` 運算符
- 將兩個巨集參數進行連接，生成新的標識符。
- 必須有兩個操作數。
```c
#define TOKENCONCAT(x, y) x ## y

// 當程式中出現 TOKENCONCAT(O, K) 時，展開為：
OK

// 若搭配變數使用：
#define VARCONCAT(x, y) x ## y
int VARCONCAT(my, Variable) = 42;

// 展開為：
int myVariable = 42;
```

## Line Numbers
- 用於重新編號後續程式碼行號。
- 可選擇指定檔案名稱，方便調試或查看編譯器訊息。
- 基本格式
```c
#line 整數 // 指定後續程式碼的行號從該整數開始。

// 包含檔案名稱的格式
#line 整數 "檔案名稱" // 除了重新編號行號，還指定檔案名稱，用於顯示編譯錯誤或警告訊息。
```
### 範例
- 重新編號行號
```c
#line 100
int main() {
    return 0; // 這一行的行號為 100
}
```
- 指定檔案名稱
```c
#line 50 "custom_file.c"
int func() {
    return 42; // 這一行的行號為 50，檔案名稱顯示為 "custom_file.c"
}
```

## Predefined Symbolic Constants
- C 語言標準中提供了一些預定義的符號常數。
- 這些符號常數的識別符以 __ 開頭和結尾。
- 例如：__FILE__, __LINE__, __DATE__, __TIME__, __STDC__。
```c
#include <stdio.h>

int main() {
    printf("檔案名稱: %s\n", __FILE__); // 表示當前檔案名稱（字串形式）。
    printf("行號: %d\n", __LINE__); // 表示程式中當前行號（整數）。
    printf("編譯日期: %s\n", __DATE__);// 表示程式編譯的日期（字串形式，格式：MMM DD YYYY）。
    printf("編譯時間: %s\n", __TIME__);// 式編譯的時間（字串形式，格式：HH:MM:SS）。
    printf("是否符合標準 C: %d\n", __STDC__);// 表示是否符合標準 C（值為 1 時代表符合標準 C）。
    return 0;
}
```
### 應用場景
- 除錯與日誌記錄：
```c
printf("錯誤發生於檔案: %s, 行號: %d\n", __FILE__, __LINE__);
```
- 版本控制與時間標記：：
```c
printf("程式編譯於 %s %s\n", __DATE__, __TIME__);
```

## Assertions
- assert 巨集 定義於 `<assert.h>` 標頭檔，用於執行期檢查表達式的值。
- 主要用途：
	- 當表達式結果為 false (0) 時：
		- 顯示錯誤訊息（包含檔案名稱與行號）。
		- 呼叫 <stdlib.h> 中的 abort() 函數終止程式執行。
	- 常用於除錯，用來檢查變數的值是否正確。
	- 快速定位錯誤：
		- 當條件失敗時，錯誤訊息會指向具體的檔案和行號。
		- 有助於專注在問題區域進行調試。
### 基本範例
```c
assert(x <= 10); // 假設程式中的變數 x 不應大於 10
```
```c
#define NDEBUG // 定義後，assert 語句將被編譯器忽略。
```