## Files and Streams
- C 將每個檔案視為連續的位元組流。
- 每個檔案以結束標記或系統記錄的位元組數作為結尾。
- 檔案開啟時，會與其關聯一個資料流 (Stream)。
- 三個預設開啟的資料流：
	- 標準輸入 (stdin)：例如鍵盤輸入。
	- 標準輸出 (stdout)：例如螢幕輸出。
	- 標準錯誤 (stderr)：例如錯誤訊息。
![upgit_20241121_1732181979.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732181979.png)
### 標準資料流的指標
- **標準輸入 (stdin)**：鍵盤資料。
- **標準輸出 (stdout)**：螢幕顯示。
- **標準錯誤 (stderr)**：錯誤輸出。

### 檔案操作結構
- 開啟檔案會返回一個指向 FILE 結構的指標（定義於 <stdio.h>）。
- FILE 結構包含處理檔案所需的資訊：
	- 在某些系統中，包含一個檔案描述符 (File Descriptor)。
	- 檔案描述符是作業系統開啟檔案表的索引。
### 作業系統檔案管理
- 每個表格元素包含一個檔案控制區塊 (File Control Block, FCB)。
- 檔案控制區塊用於記錄和管理特定檔案的資訊。

### C 語言檔案處理函數
#### 字元讀取與寫入
- fgetc：
	- 功能：從檔案讀取一個字元。
	- 使用方式：`fgetc(FILE *)`，例如 `fgetc(stdin)` 相當於 `getchar()`。
- fputc：
	- 功能：將一個字元寫入檔案。
	- 使用方式：`fputc(char, FILE *)`，例如 `fputc('a', stdout)` 相當於 `putchar('a')`。
#### 行讀取與寫入
- fgets：
	- 功能：從檔案讀取一整行字串。
	- 適合處理多字元的輸入。
- fputs：
	- 功能：將一整行字串寫入檔案。
	- 適合處理多字元的輸出。
#### 格式化輸入與輸出
- fscanf：
	- 功能：從檔案以格式化方式讀取資料（類似 `scanf`）。
	- 適用於有特定格式的資料檔案。
- fprintf：
	- 功能：將資料以格式化方式寫入檔案（類似 `printf`）。
	- 適用於產生格式化的檔案輸出。

### 實例：應用於應收帳款系統的順序存取檔案
- 目標：建立順序存取檔案，追蹤公司信用客戶的欠款資訊。
- 每筆資料包含：
	- 帳戶號碼（作為記錄的關鍵字）。
	- 客戶名稱。
	- 客戶餘額（欠款金額）。
![upgit_20241121_1732182335.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732182335.png)

![upgit_20241121_1732182346.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732182346.png)

- 檔案指標 (FILE Pointer)：
	- 每個開啟的檔案需要一個 **FILE 指標**來管理。
	- 使用 `fopen` 開啟檔案會返回一個指向 **FILE 結構**的指標。
	- 檔案名稱（如 `clients.dat`）與檔案指標建立**溝通通道**。
- FILE 結構與檔案控制區塊 (FCB)：
	- 每個檔案的 FCB 會複製到記憶體中。
	- FCB 是作業系統管理檔案的核心資料。
![upgit_20241121_1732182618.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732182618.png)


#### 檔案開啟模式
- 基本模式：
	- **"r"**：開啟現有檔案供讀取。
	- **"w"**：開啟檔案供寫入，若檔案已存在，內容將被清除。
	- **"a"**：開啟檔案供附加，新增資料將寫入檔案尾端。
- 更新模式：
	- "r+"：開啟現有檔案供讀寫。
	- "w+"：建立檔案供讀寫，若檔案已存在，其內容將被清除。
	- "a+"：開啟或建立檔案供讀寫，新增資料寫入尾端。
- 二進位模式：
	- 各模式加 `b` 表示操作二進位檔案（如 `wb`、`rb`）。
- 獨占寫入模式 (Exclusive Write)：
	- 使用 `x`（如 `wx`、`w+x`）表示獨占模式，檔案已存在時，開啟將失敗。
#### 檔案操作流程
- 檔案開啟與錯誤檢查
	- 使用 `fopen` 開啟檔案並指定模式。
	- 若開啟失敗（`fopen` 返回 `NULL`），需進行錯誤處理。
- 資料寫入與結束條件：
	- 使用 **`fprintf`** 將格式化資料寫入檔案。
	- 當使用者輸入結束鍵（end-of-file）時，檔案輸入完成。
- 檔案結束判定：
	- 使用 **`feof(FILE *)`** 檢查是否到達檔案結尾。
- 檔案關閉：
	- 使用 **`fclose`** 明確關閉檔案。
	- 若未明確關閉，作業系統在程式結束時會自動清理。

![upgit_20241121_1732182797.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732182797.png)

![upgit_20241121_1732182808.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732182808.png)

## Reading Data from a Sequential-Access File

### 範例：Resetting the File Position Pointer
- 讀取 clients.dat 的記錄並打印其內容。
- 檔案指標 (cfPtr)：
	- 使用 fopen 開啟檔案，模式為 "r" (供讀取)。
	- 若檔案開啟失敗（fopen 返回 NULL），進行錯誤處理。
- 資料讀取：
	- 使用 fscanf（類似 scanf），依次讀取 account、name、balance。
	- 每次執行 fscanf 時，變數會獲取新記錄的值。
- 檔案結尾判定
	- 使用 `feof(FILE *)` 確認是否到達檔案結尾：
	- 當程式嘗試讀取最後一行之後的資料時，feof 返回 true。
	- 完成所有資料讀取後，關閉檔案。
- 關鍵函數
	- fopen：以指定模式開啟檔案並返回檔案指標。
	- fscanf：從檔案讀取格式化資料。
	- feof：檢查是否到達檔案末尾。
	- fclose：關閉檔案以釋放資源。
![upgit_20241121_1732183165.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732183165.png)

![upgit_20241121_1732183176.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732183176.png)


## Random-Access Files
- 固定長度記錄：
    - 隨機存取檔案的每筆記錄通常具有相同的長度。
    - 記錄位置可直接計算，無需逐一搜尋。
- 快速存取：
    - 適用於需要迅速定位特定資料的系統，例如：
        - 航空訂票系統
        - 銀行系統
        - 銷售點系統 (POS)
        - 其他交易處理系統
- 固定長度記錄的優勢
	- 直接存取：根據記錄鍵（Record Key）計算記錄的位移位置，相對於檔案開頭的位置精確定位。
	- 靈活操作：可以插入、更新或刪除資料，無需重寫整個檔案。
	- 結構類比：隨機存取檔案類似貨運列車，具有多節車廂（記錄），部分裝載資料，部分空置。
- 關鍵點
	- 實現方式：採用固定長度記錄的簡單方法建立隨機存取檔案。
	- 靈活性：支援動態操作，例如插入新資料或更新舊資料。
	- 記錄定位：透過記錄鍵的計算，快速找到記錄的位移位置。
![upgit_20241121_1732183804.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732183804.png)

## Creating a Random-Access File 
- fwrite：將記憶體中特定數量的位元組寫入檔案。
- fread：從檔案讀取特定數量的位元組到記憶體。
- fwrite 與 fread 的參數
	- 第一個參數：資料的記憶體位置（如變數或結構體的指標）。
	- 第二個參數：每個元素的大小（以位元組為單位）。
	- 第三個參數：元素的數量（如陣列中要讀寫的元素個數）。
	- 第四個參數：檔案指標。

### 寫入與讀取整數
- 使用 fwrite
```c
fwrite(&number, sizeof(int), 1, fPtr);
// 寫入固定大小的整數（4 位元組，系統依賴）。
// 不使用格式化字串，直接將原始位元組資料寫入檔案。
```
- 使用 fread
```c
fread(&number, sizeof(int), 1, fPtr);
// 檔案讀取 4 位元組整數到變數中。
```

### 結構體操作
- 一次寫入或讀取整個結構體（如客戶記錄）。
```c
// 一次寫入或讀取整個結構體（如客戶記錄）。
struct ClientData client;
fwrite(&client, sizeof(struct ClientData), 1, fPtr);
```
![upgit_20241121_1732184141.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732184141.png)

![upgit_20241121_1732184151.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732184151.png)


## Writing Data Randomly to a Random-Access File
### fseek 函數
- 檔案位置指標：指示下一個讀取或寫入操作的位元組位置。
```c
int fseek(FILE *stream, long int offset, int whence);
// stream：檔案指標。
// offset：從基準點移動的位元組數。
// whence：基準點，可選擇：
	// SEEK_SET：檔案開頭。
	// SEEK_CUR：當前位置。
	// SEEK_END：檔案結尾。
```
### fwrite
- 寫入資料
```c
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
// ptr：指向要寫入的資料位址。
// size：每個元素的大小（位元組）。
// count：寫入元素的數量。
// stream：檔案指標。
```
![upgit_20241121_1732184436.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732184436.png)

![upgit_20241121_1732184449.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732184449.png)

![upgit_20241121_1732184463.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732184463.png)

![upgit_20241121_1732184475.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732184475.png)


## Reading Data from a Random-Access File
### fread 函數
- 檔案讀取操作
```c
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
// ptr：指向存放讀取資料的記憶體位址。
// size：每個元素的大小（位元組）。
// count：要讀取的元素數量。
// stream：檔案指標。
```
### 應用範例：讀取信用記錄
![upgit_20241121_1732184901.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732184901.png)

![upgit_20241121_1732184912.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732184912.png)

![upgit_20241121_1732184924.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241121_1732184924.png)
