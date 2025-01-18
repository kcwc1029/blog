## 備註
- 這一章節我整理過後，變得有點太少，你可以再到【C程式設計>PPT>chap_04】去看原內容。
## Iteration Essentials
- 迴圈：迴圈是電腦在某個條件為真的情況下，重複執行一組指令的機制。
### while：哨兵控制迴圈 (Sentinel-controlled iteration)  
- 又稱為不定次迴圈 (Indefinite iteration)，因為事先無法確定迴圈執行次數。
   - 適用於事先無法確定執行次數的情況。
   - 迴圈內每次執行時會獲取新的資料。
   - 使用哨兵值 (Sentinel value) 作為資料結束的標誌。
-  必備條件：
	- 控制變數名稱與初始值。
	- 遞增或遞減控制變數。
	- 測試是否達到最終值的條件。
![upgit_20241114_1731553589.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731553589.png)
- 使用 `unsigned int counter = 1;` 初始化控制變數。
- `++counter;` 每次迴圈執行後增加1。
- 當 `counter > 10` 時，迴圈結束。

### for：計數器控制迴圈 (Counter-controlled iteration)  
- 又稱為定次迴圈 (Definite iteration)，因為預先知道迴圈執行次數。
- 使用控制變數 (Control variable) 計算迴圈執行次數。
- 每次執行後，控制變數遞增 (通常為1)。
- 當控制變數達到預定的次數後，迴圈結束。
-  必備條件：
![upgit_20241114_1731553786.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731553786.png)

- 初始化、條件、遞增可包含**算術運算**：
```cpp
for (j = x; j <= 4 * x * y; j += y / x)
```
- Off-by-one 錯誤：條件設置不當 (如 `<=` 與 `<` 之間的差異)，導致迴圈執行次數錯誤。

## Examples Using the for Statement
- for 迴圈控制變數範例
![upgit_20241114_1731554644.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731554644.png)

- 複利計算：假設投資 $1000，年利率 5%，計算 10 年後每年的結餘金額。
	- ==這邊你在幫我看一下有沒有對==
$$a = p(1 + r)^n$$
- p：本金
- r：年利率
- n：年數
- a：第 n 年的結餘
![upgit_20241114_1731555158.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731555158.png)

![upgit_20241114_1731555215.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731555215.png)

- 數值格式化輸出：
```cpp
%21.2f
- %f：表示輸出一個浮點數。
- 設定欄位寬度為 21
- 設定小數點後顯示 2 位數。

%-6d：
- %d：表示輸出一個整數。
- 6：設定欄位寬度為 6。
- -：表示左對齊。

%-8s：
- %s：表示輸出一個字串。
- 8：設定欄位寬度為 8。
- -：表示左對齊。
```
## Multiple-Selection Statement 
### switch
- 用於處理多重決策，根據變數的不同值執行對應的操作。
- 包含多個 `case` 標籤、可選的 `default` 案例，以及每個 `case` 的執行語句。
```cpp
#include <stdio.h>

int main() {
    int day;
    printf("請輸入 1-7 的數字：");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("星期一\n");
            break;
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;
        case 4:
            printf("星期四\n");
            break;
        default:
            printf("輸入錯誤！\n");
    }
    return 0;
}

```
### do while
```cpp
do {
    // 迴圈內執行的程式碼
} while (條件);
```

- 假設要讓使用者不斷輸入數字，直到輸入 0 才結束：
```cpp
#include <stdio.h>

int main() {
    int number;

    do {
        printf("請輸入一個數字(輸入 0 以結束)：");
        scanf("%d", &number);
        printf("你輸入的數字是：%d\n", number);
    } while (number != 0);

    printf("程式結束！\n");
    return 0;
}
```

## break and continue Statements
### break
- 立即退出 while、for、do while 或 switch 語句，繼續執行後續程式碼。
- 用途：
	- 提前結束迴圈。
	- 跳出 switch 語句，避免執行後續的 case。
```cpp
for (int i = 1; i <= 10; i++) {
    if (i == 5) break; // 當 i 為 5 時跳出迴圈
    printf("%d ", i);
}
// 輸出：1 2 3 4
```
### continue
- 跳過當前迴圈中的剩餘語句，進入下一次迭代。
- 作用：
	- while 和 do while：執行 continue 後，立即檢查條件。
	- for：執行 continue 後，先執行遞增表達式再檢查條件。
```cpp
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue; // 當 i 為 3 時跳過
    printf("%d ", i);
}
// 輸出：1 2 4 5
```




