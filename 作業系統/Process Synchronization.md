Synchronization：process 因為某件事而被迫等待，直到其他 process 做某件事，原先的 process 才能繼續做

## 1. Process Communication 兩大方式：

### 1.1. 方式 01：Shared Memory（共享記憶體，速度快）

定義：

-   Process 之間透過對共享變數的存取來達成彼此溝通的目的。
-   像「朋友面對面聊天」→ 直接接觸，快，但要自己管理互動。
    責任分配：
-   OS 不負責：OS 僅提供 shared memory space。
-   Programmer 自行負責：須設計共享變數的互斥存取控制（避免 race condition）。

### 1.2. 方式 02：Message Passing（訊息傳遞，速度慢）

定義：

-   Process 依下列步驟通訊：
    -   建立 Communication link
    -   message 相互傳輸
    -   釋放（release）link
-   像「打電話」→ 要先建立連線，慢一點，但由電信公司管理。
    責任分配：
-   OS 負責：負責 Communication link 管理、Exception handling。
-   Programmer 無需負責：僅需呼叫 `send()`、`receive()` 指令即可。
    特點：傳遞資料量較小

## 2. Race Condition（競爭條件）

定義：當使用 Shared Memory Communication，若共享變數的存取**缺乏互斥控制（mutual exclusive access）**，則：

-   最終結果值可能會因為 Process 執行順序不同而有所不同
-   造成資料不一致（Inconsistency） 的問題

### 2.1. 範例說明 01

假設共享變數 `C` 初始值為 5

-   Process P₁：`C = C + 1`
-   Process P₂：`C = C - 1`
    當 P₁、P₂ 各執行一次後，C 最終值可能為 **4、5 或 6**，這就是 **Race Condition**

#### 2.1.1. Case 1（互不干擾）：

```
T1: P1 執行 C = C + 1 → 得到 C = 6
T2: P2 執行 C = C - 1 → 得到 C = 5
```

#### 2.1.2. Case 2（彼此覆蓋）：

```
T1: P1 計算 C + 1 得到 6，但尚未 assign 回 C
T2: P2 計算 C - 1 得到 4，但尚未 assign 回 C
T3: P2 assign C = 4
T4: P1 assign C = 6（被覆蓋）
→ 此時 C = 6 或 C = 4（看誰後執行）
```

#### 2.1.3. Case 3（T3, T4 對調）：

```
T3: P1 assign C = 6
T4: P2 assign C = 4
→ 最終 C = 4
```

### 2.2. 範例說明 02

假設 `x = 1`, `y = 0`，共享變數：

-   P₁: `x = x + y`，接著 `y = x * z`
-   P₂: `y = x + z`，接著 `x = x + y`
    當兩者都執行一次後，(x, y) 的值可能有多種可能：

執行結果範例：

| 執行順序                         | 結果         |
| -------------------------------- | ------------ |
| P1: x = x + y = 1, P2: y = x + z | x = 1, y = 2 |
| P2: y = x + z = 3, P1: x = x + y | x = 3, y = 2 |

當 T₁ 計算 `x + y = 1` 但尚未 assign 回 x，T₂ 使用舊值進行計算，會導致：

-   最終值錯誤
-   出現競爭狀況

## 3. 解決 Race Condition 的兩大策略：

### 3.1. 策略 01：Disable Interrupt（適用於單核心 CPU）

定義： 當 Process 執行共享變數存取時，先 `Disable interrupt`，結束後再 `Enable interrupt`，確保該段程式能在不被中斷情況下完成。
目的： 保證程式在 CPU 中「原子性（atomically executed）」地執行，不會被其他 Process 打斷。
範例：

```
P1                         P2
Disable interrupt          Disable interrupt
C = C + 1                  C = C - 1
Enable interrupt           Enable interrupt
```

缺點：

-   僅適用於單處理器（uniprocessor）架構
-   不適用於多核心（multiprocessor），因為 disable interrupt 僅針對當前 CPU，不影響其他 CPU
-   增加 overhead，影響效能與系統反應能力

> 該方法是去【鎖住 CPU】，但鎖住這棵，還有別顆會去搶=>應該是要去【鎖住資料】=>Critical Section Design

### 3.2. 策略 02：Critical Section Design（臨界區設計）

定義：

-   Critical Section（C.S.）：每個 Process 中對共享變數進行存取的區域
-   Remainder Section（R.S.）：非臨界區部分

![upgit_20250407_1744007567.png|352x288](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250407_1744007567.png)

#### 3.2.1. Process 結構：

每個 C.S.前後，programer 需要加入額外的控制碼

-   Entry Section
-   Exit Section
    C.S.是在設計 Entry Section 與 Exit Section 的 code。

```text
repeat
  Entry Section   ← 進入 C.S. 前
  Critical Section (C.S.)
  Exit Section    ← 離開 C.S. 時
  Remainder Section (R.S.)
until False
```

#### 3.2.2. 範例流程（互斥保護 C 的操作）：

```
P1                         P2
Entry Sec.                 Entry Sec.
C = C + 1                  C = C - 1
Exit Sec.                  Exit Sec.
R.S.                       R.S.
```

#### 3.2.3. Critical Section Design 的 3 大必要條件（Criteria）：

條件 01：Mutual Exclusion（互斥）：同一時間只能有一個 Process 在執行 C.S.，避免資料不一致。
條件 02：Progress（進度性）：在有限時間內，能決定讓哪一個想進入 C.S. 的 Process 進入（No Deadlock）。
條件 03：Bounded Waiting（有限等待）：任一個 Process 想進入 C.S. 後，最多等待 N-1 次後就可進入（No Starvation）。

![upgit_20250407_1744008419.png|919x381](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250407_1744008419.png)

### 3.3. software solution

前提：要以兩個 process 的角度去看

|                                         |                                    |
| --------------------------------------- | ---------------------------------- |
| 適用於 2 個 Process 的解法（如 P₀, P₁） | Algo 1(不 OK)，即 Turn-based       |
|                                         | Algo2(不 OK)，即 Flag-based        |
|                                         | Algo 3，即 Peterson’s Solution     |
| 適用於 n 個 Process 的解法（n > 2）     | Peterson’s Solution(糟糕+不用學)   |
|                                         | Bakery’s Algorithm（麵包店演算法） |

#### 3.3.1. 適用於 2 個 Process 的解法--Algo01：Turn-based

以一支【權杖】在做輪替
基本概念：

-   共享變數：`turn`（int）代表哪個 Process 有「進入 C.S. 的權杖」
-   可以想像成【權杖】
-   若 turn == i → i 拿到權杖 → Pi 有權限進入 C.S.

```c
///// Turn-based程式碼： /////
repeat
  while (turn ≠ i) do no-op; // 權杖輪到我，才可以進去CS
  C.S.
  turn = j; // 將權杖給對方
  R.S.
until False
```

優點：適合 spinlock 的環境（ex: SMP 系統），context switching 時間短
缺點：

-   無法真正讓 process 等待，只是不斷執行迴圈浪費 CPU
-   若條件為 true，process 雖等待卻仍持續佔用 CPU 資源
    回顧 3 個 Criteria：
-   ✅Mutual Exclusion：turn 只能是 i 或 j 其中一個
-   ❌Progress：若 turn = i，但 i 不想進入 C.S.，j 也不能進入
-   ✅Bounded Waiting：最多等一次輪替即可

#### 3.3.2. 適用於 2 個 Process 的解法--Algo02：Flag-based

考量每一個 process 的意願
共享變數 `flag[i]` 為布林值，代表 Process i 是否有意願進入 C.S.

-   初始值為 `False`

```c
///// Flag-based程式碼： /////
repeat
  flag[i] = True; // 表示想進入CS
  while (flag[j]) do no-op; // 看對方是否有意願進入CS
  // 如果對方有意願進入，那對方就在CS，自己就在外面等
  C.S.
  flag[i] = False; // 表達自己沒有意願(做完了)
  R.S.
until False
```

缺點：❌Progress 不通過，可能會雙方同時等待而進入 deadlock(若`flag[i]`、`flag[j]`同時都是 true)
回顧 3 個 Criteria：

-   ✅Mutual Exclusion：turn 只能是 i 或 j 其中一個
-   ❌Progress：若 turn = i，但 i 不想進入 C.S.，j 也不能進入
-   ✅Bounded Waiting：最多等一次輪替即可

#### 3.3.3. 適用於 2 個 Process 的解法--Algo03：Peterson’s Solution（最佳）

既要考量，也要考量權杖
有 flag 也有 turn

-   `flag[i]`：是否想進入 C.S.
-   `turn`：給予對方機會的讓步機制

```c
///// Peterson’s Solution程式碼： /////
repeat
	// 我想進去，把權杖給對方
	flag[i] = True; // 表達有意願進入CS
	turn = j; // 將權杖給對方
	// 當對方有意願，且權杖在對方身上 => 等待
	// 反之，若對方無意願，或權杖在我身上 => 滿足1即可進入
	while (flag[j] && turn == j) do no-op;
	C.S.
	flag[i] = False; // 表達自己沒有意願(做完了)
	R.S.
until False
```

回顧 3 個 Criteria：

-   ✅Mutual Exclusion：turn 只能是 i 或 j 其中一個
-   ✅Progress：若只有一方有意願，會成功進入
-   ✅Bounded Waiting：若 Pi 一直等，最多等一次 Pj 進入即可

#### 3.3.4. 適用於 n 個 Process 的解法：Bakery’s Algorithm

類似在麵包店排隊買麵包：

-   先抽號碼牌，號碼小者優先
-   若號碼相同則依據 **Process ID** 比大小

使用的共享變數：

-   `choosing[0...n-1]` → `Boolean`（預設值 False）
    -   `True`：表示該 Process 正在抽號碼牌
-   `number[0...n-1]` → `int`（預設值 0）
    -   表示該 Process 抽到的號碼
    -   0 表示不想進入 C.S.
-   `MAX(A)`：取得陣列中最大值
-   序對比較：若 `a < c(先比號碼牌)` 或 `a == c 且 b < d(號碼牌相同，在比身分ID)`，則 `(a,b) < (c,d)`

```c
///// Bakery’s Algorithm程式碼： /////
repeat
	choosing[i] = True;                      // 開始抽號碼
	number[i] = 1 + MAX(number[0...n-1]);    // 決定你號碼牌的值
	choosing[i] = False;                     // 抽完了

	// 檢查所有process
	for (j = 0; j < n; j++) {
		// 等待，直到所有process都抽完號碼牌
		while (choosing[j]);
		// number[j] ≠ 0 => 有意願
		// 比號碼牌，在比身分ID
		while (number[j] ≠ 0 && (number[j], j) < (number[i], i)) do no-op;
	}

	  C.S. // 進入臨界區

	  number[i] = 0; // 離開時歸零
	  R.S.           // 非臨界區
until False
```

回顧 3 個 Criteria：

-   ✅Mutual Exclusion：不可能有兩個 process 同時在 C.S.(因為兩人號碼若一樣，會以 ID 比大小，形成總順序)
-   ✅Progress：若只有一方有意願，會成功進入
    -   如果某個 Process 不想進入 C.S.，它的號碼就是 0
    -   其他 Process 不會被它阻擋，仍可進入 C.S.
-   ✅Bounded Waiting：
    -   若 Pi 想進入 C.S.，最多等待 (n-1) 個 Process 完成後可進入
    -   不會永久被卡住 → No Starvation

### 3.4. hardware solution

若 CPU 有提供【test-and-set】/【swap】之一指令，則 programmer 可以運用在 CS design

#### 3.4.1. Test-and-Set

定義：

-   `Test-and-Set` 是一種 原子操作指令（atomic instruction），常用來實作低階的鎖（lock）機制。
-   傳出 lock 參數，並將 lock 參數設定為 1

```c
///// 以C語言模擬Test-and-Set /////
int Test-and-Set(int *lock){
	int temp = *lock;
	*lock = 1;
	return temp;
}
```

#### 3.4.2. Test-and-Set 應用在 CS design 版本 01：

```c
///// 共享變數 /////
Lock = False  # 初始狀態，未鎖定
```

```c
///// Test-and-Set版本01程式碼 /////
repeat
	// 快的人：並將lock設定為true，並回傳false
	// 慢的人：因為lock=true，被鎖在外面
    while Test-and-set(Lock): do no-loop
	    C.S.
	    Lock = False
	    R.S.
until False
```

回顧 3 個 Criteria：

-   ✅Mutual Exclusion：若 Pi 和 Pj 同時嘗試進入 C.S.，只有第一個成功執行 test-and-set 的 process 會得到 Lock，其餘會被卡住（busy wait）。
-   ✅Progress：若沒有人在 C.S.，且某 process 想進入 C.S.，最終會成功進入（no deadlock）。
-   ❌Bounded Waiting：因為 Test-and-Set 是競爭機制，可能某些 process 永遠搶不到 Lock，有機會發生飢餓（Starvation）。

#### 3.4.3. Test-and-Set 應用在 CS design 版本 02：（改善 Bounded Waiting 的版本）

```c
///// 共享變數 /////
Lock = False
waiting[0..n-1] = [False] * n  // 每個 process 是否正在等待
waiting[false] // 不用等了，可以進去
waiting[true] // process有意願進入CS，且正在等待中
```

```c
///// Test-and-Set版本02程式碼 /////
repeat
    waiting[i] = True // Step 1：Pi 說「我要排隊」
    key = True // Step 2：key 是 Pi 自己的旗子
    while waiting[i] and key:
	    // 快的人：成功設定 Lock = true，並得到 key = false ⇒ 成功進入 C.S.
		// 慢的人：因為 Lock = true，所以 key 會一直是 true ⇒ 卡在 while 裡面，等待輪到自己
        key = Test-and-set(Lock)


    waiting[i] = False // 搶到 Lock 的人清除「我在等」這個標記 => 其他人會知道「我不用再管他，因為他正在執行 C.S.」
    C.S.

    # 嘗試讓下一位進入 C.S.(環狀掃描)
    j = (i + 1) % n
    while j != i and not waiting[j]:
        j = (j + 1) % n

	// 如果掃完整圈都沒有人在等，就把 Lock 設回 false（代表空閒）
	// 否則，將下一位 waiting[j] 設為 False，代表你可以進入 C.S. 囉！
    if j == i:
        Lock = False  # 沒人等了，釋放 Lock
    else:
        waiting[j] = False  # 喚醒下一位
    R.S.
until False
```

回顧 3 個 Criteria：

-   ✅Mutual Exclusion：Lock 仍確保每次只有一人進入 C.S.
-   ✅Progress：若有 process 想進入 C.S.，則一定有一人會成功，避免 deadlock
-   ✅Bounded Waiting：實作了 FIFO（先到先服務）的排隊機制，避免 process 永遠卡在等待

#### 3.4.4. swap

前提：SWAP 指令本身需為 atomic（不可中斷）操作
定義：將記憶體中的 `*a` 與 `*b` 的值交換

```c
void SWAP(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

#### 3.4.5. swap 應用在 CS design：

```c
///// 共享變數 /////
Lock = False  // 表示目前未鎖定
```

```c
repeat
    key = True // 每個process都有意願
    repeat
	    // 原先預設：Lock = False（目前沒人進 C.S.）、key = True（我想進去）
	    // 快的人SWAP後：lock=true(表示鎖定)、key=false(成功進去了)
        SWAP(Lock, key)
    until key == False
    C.S.
    Lock = False // 執行完 C.S. 後，把門打開
until False
```

回顧 3 個 Criteria：

-   ✅Mutual Exclusion：同一時間最多只有一個 process 的 `key` 能設成 False ⇒ 保證一次只有一人進入 C.S.
-   ✅Progress：若有 process 想進入 C.S.，則一定有一人成功搶到 Lock 並進入
-   ❌Bounded Waiting：沒有保證先等的人先進入 ⇒ 有機會出現 飢餓現象

### 3.5. Semaphore（信號量）

定義：Semaphore 是一種 資料型別（data type），可用於解決：

-   Critical Section（C.S.）設計問題
-   Process Synchronization（同步）問題
-   通常以整數 `S` 表示 semaphore 的值，搭配兩個原子操作：

```c
///// 兩種操作 /////
wait(S):  // 又叫 P(S)
    while (S <= 0) do no-op
    S = S - 1

signal(S):  // 又叫 V(S)
    S = S + 1

// wait：(進入)表示請求資源 → 嘗試「減1」
// signal：(離開)表示釋放資源 → 「加1」
// 保證兩者為 atomic（不可被中斷）
```

#### 3.5.1. emaphore 用於 C.S.（互斥鎖）

```c
///// 範例：使用 semaphore 實作互斥 /////

// 共享變數
semaphore mutex = 1;  // 初值為 1，代表未鎖定

// 每個 process：
repeat
    wait(mutex);   // 詢問是否可進入臨界區
    C.S.           // Critical Section
    signal(mutex); // 離開後釋放資源
    R.S.           // Remainder Section
until False
```

回顧 3 個 Criteria：

-   ✅Mutual Exclusion：`S <= 0` 時不能再進入 C.S.
-   ✅Progress：若有人離開，必有一人可進入
-   ❌Bounded Waiting：沒有明確排隊機制 ⇒ 可能會餓死（Starvation）

#### 3.5.2. Semaphore 常見錯誤與死結（Deadlock）範例 01：誤用順序，違反互斥

問題：S 會變成大於 1，導致多人同時進入 C.S.

```c
repeat
    signal(S);   // 提早釋放（錯誤！）
    C.S.
    wait(S);     // 進來太晚，其他人可能也進來了
until False
```

#### 3.5.3. Semaphore 常見錯誤與死結（Deadlock）範例 02：兩人互相等待（死結）

```c
P1:
    wait(S);   // S=1 變 0
    ...
P2:
    wait(S);   // S=0 卡住（P1 沒有 signal）
```

#### 3.5.4. Semaphore 常見錯誤與死結（Deadlock）範例 03：互相鎖錯資源

問題：兩人互相等待彼此釋放 ⇒ 死結！

```c
// S1 = 1, S2 = 1

P1: wait(S1); wait(S2); ...
P2: wait(S2); wait(S1); ...
```

#### 3.5.5. Semaphore 的分類

| 類型                       | 說明                                               |
| -------------------------- | -------------------------------------------------- |
| 依數值型態分類             |                                                    |
| Binary Semaphore           | 只有 0 / 1 兩個值，用來實作互斥鎖 (Mutex)          |
| Counting Semaphore         | 可大於 1 的整數，適用於計數資源                    |
|                            |                                                    |
| 依是否 Busy-Waiting 分類   |                                                    |
| Spinlock Semaphore         | 使用 busy-waiting 技術（CPU 空轉等待）             |
| Non-Busy-Waiting Semaphore | 使用 block/wakeup 機制（讓程式睡覺，避免浪費資源） |

##### 3.5.5.1. Binary Semaphore

特點：

-   僅有 0 或 1
-   適用於臨界區 (Critical Section) 的互斥設計
-   無法得知 有多少 process 正在等待

```c
wait(S): while(S <= 0) do no-op; S--;
signal(S): S++;
```

##### 3.5.5.2. Counting Semaphore

特點：

-   value 可以大於 1
-   若 value < 0，代表有 |value| 個 process 卡在 wait()

##### 3.5.5.3. Spinlock

特性：當 S <= 0 時，while(S <= 0) do nothing，也就是說它會讓程式不斷重複檢查 S 的值，直到 S 的值大於 0。
程式範例：CPU 空轉等待，這就是所謂的 busy-waiting（忙碌等待），因為程式會持續檢查條件，但不會去做其他有意義的工作。

##### 3.5.5.4. Non-Busy-Waiting Semaphore

特性：當 S <= 0 時，將 process 放入 queue，並將其阻塞（block），直到有空餘資源。當資源可用時，再用 wakeup 喚醒該 process。
程式範例：這種方式不會讓 CPU 空轉等待，取而代之的是使用排隊機制，讓正在等待的進程暫時停止執行，直到被唤醒。

| 類型                 | 特性                                | 程式範例              | 優缺點               |
| -------------------- | ----------------------------------- | --------------------- | -------------------- |
| **Spinlock**         | `while(S<=0) do nothing`            | CPU 空轉等待          | 資源浪費但實作簡單   |
| **Non-Busy-Waiting** | 將 process 放入 queue，block/wakeup | 使用 queue 控管等待者 | 效率高，適用多工系統 |

### 3.6. Producer-Consumer Problem（生產者與消費者問題）

Producer：負責「生產」資料（item）並放進 Buffer
Consumer：負責「消費」資料，從 Buffer 取出 item
Buffer 類型：

-   Bounded Buffer（有限緩衝區）
    -   Buffer 滿：Producer 必須等待
    -   Buffer 空：Consumer 必須等待
-   Unbounded Buffer（理論無限容量）：Producer 幾乎不需要等待

#### 3.6.1. 簡單實作（尚未使用 Semaphore）

```c
///// 共用變數 /////
Buffer[n];      // 緩衝區
in = out = 0;   // 指向放入與取出的 index
```

-   Producer：

```c
repeat
    produce item into nextp; // 生產一個資料放入
    while ((in + 1) % n == out) do no-op;  // 如果Buffer滿，卡住
    Buffer[in] = nextp;
    in = (in + 1) % n;
until False
```

-   Consumer：

```c
repeat
    while (in == out) do no-op;  // 如果Buffer空，卡住
    nextc = Buffer[out]; // 取出資料
    out = (out + 1) % n;
    consume item from nextc; // 消耗一個資料
until False
```

分析：

-   只能使用 n - 1 格空間，避免混淆滿/空狀態(in 本身那一個是空的)。
-   若引入 `count` 作為 item 數量指標，則需同步保護該變數，否則會出現 race condition（資料競爭問題）。

#### 3.6.2. 使用 Semaphore 改善同步問題

目的：

-   確保互斥、避免 race condition
-   控制 Buffer 滿與空的情況

```c
///// 共用變數 /////
mutex = 1;     // 保護共享區，確保一次只有一人動手(互斥所)
empty = n;     // 表示 Buffer 有 n 個空格（Producer 使用）
full = 0;      // 表示 Buffer 有 0 個 item（Consumer 使用）
```

-   Producer：

```c
repeat
    produce item into nextp; // 生產一個資料
    wait(empty);     // 等待有空格可放入
    wait(mutex);     // 進入臨界區（寫入 Buffer）
    Buffer[in] = nextp; // 資料放入
    in = (in + 1) % n; // 資料往前
    signal(mutex);   // 離開臨界區
    signal(full);    // 通知有 item 可取用
until False
```

-   Consumer：

```c
repeat
    wait(full);      // 等待有 item 可取
    wait(mutex);     // 進入臨界區（讀取 Buffer）
    nextc = Buffer[out]; // 取資料
    out = (out + 1) % n;
    signal(mutex);   // 離開臨界區
    signal(empty);   // 通知有空格可使用
    consume item from nextc;
until False
```

#### 3.6.3. 常見錯誤與死結（Deadlock）

錯誤的順序：若 Producer 卡住不釋放 mutex，Consumer 也進不來，會導致 **Deadlock**

```c
wait(mutex)
wait(empty)  // 若 Buffer 已滿且先鎖 mutex，Consumer 無法取得

//  解法：要先 `wait(empty)`（確認有空格）再進入 `wait(mutex)`（才鎖）
```

回顧 3 個 Criteria：

-   ✅Mutual Exclusion：`使用 `mutex` 確保同一時間只有一人操作 buffer
-   ✅Synchronization：`empty` & `full` 控制 producer 與 consumer 的等待與通知
-   ✅Bounded Waiting：Semaphore 本身有 FIFO 機制
-   ❌Deadlock 防止：若 wait 順序不當，仍可能造成死結

### 3.7. Reader-Writer Problem 簡介

Reader-Writer 問題是一個經典的同步問題，目標是在多個 Reader 和 Writer 存取共用資料時(Producer-Consumer Problem 是各一，Reader-Writer Problem 各 n)，確保：

-   允許多個 Reader 同時讀資料（若無 Writer 在寫）
-   只有一個 Writer 可以寫（寫時不能有其他 Reader 或 Writer）
-   考慮公平性問題（如：避免 Writer 或 Reader 永遠等不到進入，即 Starvation）

#### 3.7.1. 第一種版本：對 Reader 有利，對 Write 不利

![upgit_20250408_1744087477.png|610x241](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250408_1744087477.png)

特點

-   Reader 可不斷進入，只要沒有 Writer 寫入中
-   如果很多很多 reader 一直來，那 Writer 會一直等不到機會寫，就會產生 Writer Starvation（飢餓）

```c
///// 共享變數 /////
// 想像一個圖書室裡

// wrt 是門鎖：只要有人在寫，門就上鎖，別人不能進來
semaphore wrt=1 // 控制 Writer 的進出（1 代表可以寫，0 代表不能）

// readcnt 是圖書室內正在讀書的人數
int readcnt=0 // 記錄 reader 數量(有幾個 reader 正在讀（需要保護）)

// mutex 是一位管理員：專門負責記錄「現在有幾位人進入讀書」
semaphore mutex=1 // 保護 readcnt，不讓多個人同時改它
```

```c
///// Reader-Writer Problem 版本01  /////
int readcnt = 0;         // 有幾個 reader 正在讀（需要保護）
Semaphore mutex = 1;     // 保護 readcnt，不讓多個人同時改它
Semaphore wrt = 1;       // 控制 Writer 的進出（1 代表可以寫，0 代表不能）


// Writer
wait(wrt);           // 嘗試鎖上門，進去寫
// writing
signal(wrt);         // 寫完了，把門打開


// Reader
wait(mutex);          // 1. 跟管理員說我要進來，讓我改 readcnt
readcnt++;            // 2. 記錄多了一個 reader
if (readcnt == 1)     // 3. 如果我是第一個 reader
    wait(wrt);        //    就去把門鎖起來，不讓 writer 進來
signal(mutex);        // 4. 跟管理員說改好了
  // reading 現在可以讀書（reading）
wait(mutex);           // 5. 讀完書，跟管理員說我要離開
readcnt--;             // 6. 人數減 1
if (readcnt == 0)      // 7. 如果我是最後一個離開的人
    signal(wrt);       //    就幫忙把門打開，讓 writer 有機會進來
signal(mutex);         // 8. 跟管理員說改好了
```

#### 3.7.2. 第二種版本：對 Writer 有利，對 Reader 不利

在第一種版本中，Reader 一直來一直來，Writer 永遠等不到進入（飢餓），所以這個版本改進成：如果 Writer 有等，就不讓 Reader 進來！

特點：

-   若 Writer 有等待，則優先讓 Writer 進入
-   避免 Reader 一直佔據，導致 Writer 無法寫入

```c
///// 共享變數 /////
// 圖書室升級版

int readcnt = 0;        // readcnt 是裡面正在讀書的人
int writecnt = 0;       // writecnt 是正在等著寫的人數

semaphore x = 1;        // 保護 readcnt
semaphore y = 1;        // 保護 writecnt

// wsem 是「寫作室的門鎖」：只准一個人進來寫
semaphore wsem = 1;     // 控制誰可以寫（writer 專用鎖）

// rsem 是「大門口警衛」：如果 Writer 要寫了，就會把門擋住，不讓 Reader 進入
semaphore rsem = 1;     // 控制 reader 是否可以進入（新 reader 要問過它）
semaphore z = 1;        // 「控制 reader 依序排隊」：避免大家擠門口
```

```c
///// Reader-Writer Problem 版本02  /////

// Reader
wait(z);  // 確保 Reader 是依序進場，不讓其他reader擠進來造成混亂
  wait(rsem); // 問問大門警衛：現在能不能進來(writer就不能進來了)
    wait(x); // 🔐 保護 readcnt：我要進來了，幫我記錄一下
      readcnt++;
      if (readcnt == 1)
          wait(wsem);  // 如果我是第一個讀書人，就鎖住寫作室（不讓老師寫）
    signal(x); // 解鎖 x，讓別人也能更新 readcnt
  signal(rsem); // 放行給下一個 Reader（如果沒被鎖）
signal(z); // 下一個人也能排隊進來
// reading
wait(x);           // 我要離開了，先鎖住 readcnt
  readcnt--;       // 讀書人 -1
  if (readcnt == 0)
      signal(wsem); // 如果我是最後一個，幫大家開門（給 Writer 用）
signal(x);         // 解鎖 x



// Writer
wait(y);           // 我要來寫作，先登記一下
  writecnt++;      // 想寫的老師數量 +1
  if (writecnt == 1)
      wait(rsem);  // 如果我是第一個老師，鎖住警衛，不讓新 Reader 進來
signal(y);         // 登記完畢


wait(wsem); // 嘗試進入寫作室（只能一人寫）

wait(y);           // 我要離開了，先更新資料
  writecnt--;      // 想寫的老師數量 -1
  if (writecnt == 0)
      signal(rsem); // 如果我是最後一位老師，就讓 Reader 可以重新進來了
signal(y);         // 解鎖
```

### 3.8. Sleeping Barber Problem 簡介

問題描述

-   如果沒客人 → 理髮師睡覺 😴
-   如果有客人：
    -   如果有空位（椅子） → 坐下等候
    -   如果沒椅子可坐 → 客人直接走人

```c
///// 共享變數 /////
semaphore Customers=0 // 控制「叫醒理髮師」用：客人進來就 +1
semaphore Barbers=0 // 控制「讓客人進去理髮」：理髮師空了就 +1
int waiting=0 // 正在等候室裡的客人數量
semaphore mutex=1 // 保護 waiting 的更新（防 race condition）
int x // 等待椅子的數量上限
```

```c
///// Barber 的行為流程  /////
repeat {
    wait(Customers);   // 如果沒有客人，這裡就會阻塞 → Barber 就睡了
    wait(mutex);       // 保護 waiting
      waiting--;       // 有人被叫進來了，等待中的人 -1
      signal(Barbers); // 叫一位客人過來（之前在等待）
    signal(mutex);
    cut_hair();        // 開始理髮
}
```

```c
///// Customer 的行為流程  /////
wait(mutex);                       // 我要進店，先鎖 waiting
if (waiting < n) {                // 如果有椅子，我就坐下排隊
    waiting++;                    // 坐下等候
    signal(Customers);           // 通知理髮師我來了
    signal(mutex);               // 放開鎖
    wait(Barbers);               // 我等理髮師叫我進來（理髮椅只有一張）
    get_haircut();               // 理髮
}
else {
    signal(mutex);               // 沒位子，直接離開
}
```

### 3.9. Dining Philosophers Problem（哲學家用餐問題）

問題背景：

-   有 5 位哲學家 坐在圓桌吃飯
-   每位哲學家左右兩邊各有一根筷子（共 5 根）
-   哲學家有三種狀態：thinking（思考）、hungry（飢餓）、eating（吃飯）
    規則：
-   想吃飯時，哲學家必須同時拿到左、右兩根筷子
-   吃完飯後，放下筷子，繼續思考
-   筷子一次只能被一位哲學家拿著（不能共用）
    死結（Deadlock）：
-   如果每位哲學家都同時拿起「左邊」的筷子，然後等「右邊」的筷子
-   就是經典的 Hold and Wait + Circular Waiting → Deadlock

```c
///// 資源宣告 /////
semaphore chopstick[5] = {1, 1, 1, 1, 1}; // 每根筷子是 semaphore=1
semaphore NO = 4; // 最多同時允許4人嘗試拿筷子（防止死結用）
```

```c
///// 每位哲學家（P[i]）行為 /////

repeat {
    wait(NO);                       // 最多同時允許4人進入，防止死結
    wait(chopstick[i]);            // 拿左邊筷子
    wait(chopstick[(i+1)%5]);      // 拿右邊筷子
    // 吃飯
    signal(chopstick[i]);
    signal(chopstick[(i+1)%5]);    // 放下兩支筷子
    signal(NO);                    // 釋放允許權
    // 思考
}
```

#### 3.9.1. 哲學家用餐解法 01：

限制最多同時進入的人數
只允許 n - 1 個哲學家同時嘗試進入 hungry 狀態，就永遠不會五個人都卡住

```c
semaphore NO = 4;  // 最多允許4人嘗試拿筷子（5人中最多只能有4人同時嘗試）
```

#### 3.9.2. 哲學家用餐解法 02

非同步拿筷子（非對稱解）

-   奇數編號哲學家先拿左筷再拿右筷
-   偶數編號哲學家先拿右筷再拿左筷
    原理：
-   破壞了「每人都同樣順序拿筷子」的對稱條件
-   所以就不會形成「環形等待（Circular Waiting）」

#### 3.9.3. 哲學家用餐解法 03

允許哲學家一次只能拿到一根筷子，且必須兩根都可拿時才拿

-   先檢查：左右兩根筷子都 available 才能同時拿
-   否則就什麼都不做（不會先搶一根）
    原理：
-   這樣就不會產生「先拿一根 → 卡住」的情況
-   直接破壞 Hold and Wait 條件

### 3.10. Monitor（監控器）

![upgit_20250408_1744095499.png|636x325](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250408_1744095499.png)

定義：是一種高階同步資料結構，用來解決 同步與互斥問題。
可確保【共享變數區內的共享變數不會發生 race condition】
有三個主要組成：

-   共享變數區（私有）
-   Procedure 區（公共，可呼叫）
-   初始設定區
    特性：任一時刻，最多只允許一個 process 執行 Monitor 內的某個 procedure
-   有加上 entry 的 function，就是公開可以給 process 使用得(public)

```c
///// Monitor 語法結構 //////
type monitor = MonitorName
var
  // 宣告共享變數：所有程序要一起用的資料（只能 Monitor 裡面存取）

procedure entry function1(...)
begin
  // function1 的邏輯（別人從外面會呼叫這個 function）
end;

procedure entry function2(...)
begin
  // function2 的邏輯（也是公開的）
end;

begin
  // 初始化區
end;
```

Condition 變數（條件同步）：

-   X.wait()：讓執行中的 process 進入 X 的 waiting queue，並釋放 monitor 鎖
-   X.signal()：喚醒一個在 X 的 waiting queue 中等待的 process

#### 3.10.1. 範例：用 Monitor 解決哲學家用餐問題

```c
///// 狀態 /////
state[i] = {thinking, hungry, eating} // 表示每位哲學家的狀態
self[i] = condition  // 每個哲學家對應一個 condition
```

```c
// 哲學家要開始吃飯
procedure pickup(i){
	state[i] = hungry;     // 先標記我餓了
	test(i);                // 試試看左右都沒吃 → 就能吃
	if (state[i] ≠ eating)  // 如果不能吃 → 就 wait（等別人讓位）
	    self[i].wait();
}

// 哲學家吃完放下筷子
procedure putdown(i){
	state[i] = thinking; // 放下筷子回去思考
	test(left of i);      // 檢查左邊人是否能吃
	test(right of i);     // 檢查右邊人是否能吃
}

// 決定哲學家 i 能不能吃
procedure test(i){
	if (state[i] = hungry
	    and state[left of i] ≠ eating
	    and state[right of i] ≠ eating)
	{
	    state[i] := eating;   // 開始吃！
	    self[i].signal();     // 如果有人在等，喚醒自己
	}
}
```

#### 3.10.2. 範例：資源分配 Resource Allocator

你去學校借 1 台筆電（學校只有一台筆電）

-   只有一個人可以同時借（互斥）
-   如果筆電被借走了，你就要「排隊等待」。
-   一旦有人還筆電了，就會通知下一個人「你可以來借了！」

```c
Var:
    Busy: Boolean    // 筆電目前有沒有人在用
    X: condition     // 排隊等待的人（waiting queue）

Acquire(i)           // 想要借筆電的人執行這個
    if Busy      // 如果筆電已經有人在用
	    X.wait(i)    // 那就排隊等通知
    Busy = True      // 一旦借到，設定為正在使用

Release()            // 還筆電的動作
    Busy = False     // 筆電變成「空閒」
    X.signal()       // 通知排在最前面的人來借
```

| 功能                        | 說明                                                    |
| --------------------------- | ------------------------------------------------------- |
| **互斥**                    | 一次只有一人能執行 Monitor 的方法（Acquire or Release） |
| **幫忙排隊（Condition X）** | 使用 wait() 和 signal() 排隊＋通知下一位                |

#### 3.10.3. 範例：限制同時存取的 Coordinator Monitor

你在管理一間自習室，裡面只有 N 單位的空間（比如 N = 10）。 每個人進來都會佔用 不同大小的空間，例如：

-   A：佔 3 單位
-   B：佔 4 單位
-   C：佔 6 單位
    你要確保：同時在自習室裡的所有人佔用的總空間（Sum）不能超過 N

```c
Var:
	int Sum = 0           // 目前自習室總共被佔用的空間
    condition X           // 沒空位的時候大家在這邊排隊等

Access(i)                 // 有人要進來，佔用 i 單位
    while (Sum + i ≥ N)   // 如果加上他會超過空間，就要等
        X.wait(i)
    Sum = Sum + i         // 有空間，進來佔用空間

Leave(i)                  // 有人離開
    Sum  Sum - i         // 把空間釋放
    X.signal()            // 通知等待的人有空間了

```

| 功能         | 說明                                           |
| ------------ | ---------------------------------------------- |
| **互斥**     | 一次只有一個 process 在 Access or Leave 中動作 |
| **條件等待** | 沒空間時自動進入 X.wait() 排隊                 |
| **自動喚醒** | 有空間時用 X.signal() 叫醒等待的人             |

#### 3.10.4. 範例：印表機分配 Printers Allocator

你是一位老師，教室裡有 3 台印表機（P0, P1, P2）。現在有很多學生想列印作業，但：

-   每台印表機一次只能被一個人使用
-   如果三台都在用，就只能等
-   用完後要記得「歸還」印表機，讓其他人可以用

```c
Var:
    bool P[3]           // 代表 P0, P1, P2 三台印表機是否有人在用
    X: condition        // 等印表機的排隊區（waiting queue）

Apply(i, pid)
    if 所有印表機都在用 then
        X.wait(i)       // 沒空的，乖乖排隊等通知
    // 找到第一台空的印表機
    // pid ← 那台印表機的編號
    P[pid] = True       // 標記這台正在被使用

Release(pid)
    P[pid] = False       // 歸還印表機
    X.signal()           // 叫下一個等的人來用
```

| 功能         | 說明                                                  |
| ------------ | ----------------------------------------------------- |
| **互斥**     | 同時間只能有一人執行 `Apply()` 或 `Release()`         |
| **同步**     | 沒印表機就 `wait()`，有空的就 `signal()` 喚醒等待的人 |
| **狀態紀錄** | 用 `P[]` 陣列紀錄每台印表機有沒有人在用               |

#### 3.10.5. Monitor 的種類

為何會有不同種類：

-   因為 `signal()` 呼叫之後，原本在等待的 process（Q）被換性了，但這時正在使用的 process(P)還在 Monitor 裡啊
-   為了保證 mutual exclusion，一次只能有一個 process 在 Monitor 內活動，因此呼叫 `signal()` 後會產生衝突：「現在誰該跑？」

Monitor 的三種策略

| 種類                                 | 行為                                   | 額外說明                                         |
| ------------------------------------ | -------------------------------------- | ------------------------------------------------ |
| (Type 1)Hoare Monitor                | P 讓出控制權 給 Q（Q 馬上執行）        | signal() 完，P 讓位，Q 被喚醒立刻執行完          |
| (Type 2)Signal-and-continue (Type 2) | P 繼續執行完，Q 再執行                 | signal() 完，Q 雖被喚醒但還不能執行，要等 P 結束 |
| (Type 3)Concurrent Pascal            | P 直接離開 Monitor，Q 接手執行 Monitor | 效果跟 Hoare 類似，但有 entry queue 排隊         |

## 4. Message Passing 溝通方式

### 4.1. Direct Communication（直接通訊）

#### 4.1.1. Symmetric（對稱式）

雙方需互相指定對方的 Process ID 才能建立通訊連結。
也就是說，送方（P）和收方（Q）都知道對方的 ID，才能建立有效的通訊。

```
P（送方）: send(Q, message)
Q（收方）: receive(P, message)
```

#### 4.1.2. Asymmetric（非對稱式）

只有送方需要指定收方的 Process ID。
收方（Q）不需要事先知道送方（P）的 ID，當收方收到訊息後，才會知道是誰傳來的訊息。

```
P（送方）: send(Q, message)
Q（收方）: receive(id, message)
```

### 4.2. Indirect Communication（間接通訊）

雙方透過 shared mailbox（共享信箱）建立通訊連結
通訊是透過 mailbox（又稱 port）進行，不直接指名對方

```c
// A 是 P 與 Q 共享的 mailbox
send(A, message)
receive(A, message)
```

### 4.3. 使用 message passing 解決 Producer-Consumer

```c
// Producer
repeat
  produce an item in nextp
  send(consumer, nextp)
until False


// Consumer
repeat
  receive(producer, nextp)
  consume the item in nextp
until False
```

### 4.4. 在 message passing 下如何呈現 Synchronization

有兩種方式說明

-   Link Capacity（連結容量）
-   Blocking vs. Non-Blocking（阻塞與非阻塞）

#### 4.4.1. Link Capacity（連結容量）

定義：在 Communication link 上會有一個附屬的 queue，用以保存暫留的 message

| 類型                   | 說明                                                                               |
| ---------------------- | ---------------------------------------------------------------------------------- |
| **Zero Capacity**      | 通道不能儲存任何訊息，送方與收方必須同時到場（類似面交），否則送方要等收方準備好。 |
| **Bounded Capacity**   | 通道有固定大小（例如 5 封訊息），如果滿了，送方會等。                              |
| **Unbounded Capacity** | 通道沒有大小限制，送方可以一直傳訊息，不會被擋下來。                               |

#### 4.4.2. Blocking vs. Non-Blocking（阻塞與非阻塞）

定義：送訊息的人（Send） 和 收訊息的人（Receive），傳送/接收完要不要「等一下」？

|         | Blocking                                           | Non-Blocking                                               |
| ------- | -------------------------------------------------- | ---------------------------------------------------------- |
| Send    | - 傳完要等收方收到才繼續<br>(你講完話要等對方回應) | - 傳完就繼續，不管收方有沒有收到<br>(你丟紙條就走了)       |
| Receive | - 一直等到有訊息才能動作<br>(你站在信箱前等信)     | - 沒有訊息就繼續往下做，不會卡住<br>(打開信箱看沒信就走了) |

### 4.5. Message Passing 的錯誤處理（Exception Handling）

#### 4.5.1. Message Lost（訊息遺失）怎麼辦？

由 作業系統（OS） 負責偵測訊息是否遺失。
如果偵測到遺失，OS 會通知 sender 重新傳送訊息。

#### 4.5.2. Symmetric Mode 中的問題（同步陷阱）

在對稱式訊息傳遞（Symmetric Mode，rendezvous 同步模式）下：

-   若一方結束了傳送或接收，但未通知另一方，則 另一方會永遠卡在等待狀態（waiting forever）！
    這是同步設計中常見的問題，屬於協調失敗（coordination failure）。

#### 4.5.3. 孤島問題（Orphaned Process）

在 Symmetric Mode 中，如果有 process 建立後 resume，但沒有對應的 process 跟它配對通訊。
就會發生「孤島問題」：這個 process 存在，但無法與他人互動，變成閒置孤立。
