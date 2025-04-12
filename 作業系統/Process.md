## 1. Process

定義：

-   A program in execution（執行中的程式）
-   是 OS 分配資源（resources）之對象單位
    -   例如：CPU time、memory、I/O device…

Process vs Program 比較

| 項目 | Process                 | Program                              |
| ---- | ----------------------- | ------------------------------------ |
| 定義 | A program in execution  | Just a file stored in storage device |
| 狀態 | Active entity（活動中） | Passive entity（被動存在）           |

一個 Process 建立後的主要組成包含：

-   Process ID：程序識別碼
-   Program Counter：指向下一個要執行的指令
-   CPU Registers（value）：暫存器內容（執行狀態）
-   Stack：暫時性儲存(local variables、return address、function parameters)
-   Code Section：程式碼段
-   Data Section：資料段，例如：global variables（靜態，全域變數）
-   Heap 動態配置記憶體區塊（ex: malloc 的區域）

## 2. Process Control Block (PCB)

定義：

-   PCB 是 OS 為了管理 processes 而建立的資料結構
-   屬於 kernel memory area 的一部分
-   每個 process 都對應一個 PCB，用來記錄其所有相關資訊

PCB 所包含的資訊如下：

-   Process Number (或 ID)
-   Process State：`ready`、`running`、`blocked (waiting)` 等
-   Program Counter
-   CPU Registers (暫存器數值)
-   CPU Scheduling Information：優先權（priority）、抵達時間等資訊
-   Memory Management Information：包含 Base/limit registers、Page table 等
-   Accounting Information：紀錄：使用多少 CPU 時間、使用哪些資源（resource）、許可等級（for performance tuning / statistics）
-   I/O Status Information：包含已發出的 I/O request、所使用的 I/O 裝置（Device）編號、Process 的 I/O 狀態

## 3. Process 的 State Transition Diagram (STD) 狀態轉換圖

-   恐龍版 5 個
-   優化版 7 個

![upgit_20250403_1743659757.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250403_1743659757.png)

![upgit_20250403_1743662198.png|1084x352](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250403_1743662198.png)

## 4. OS 中三種 Scheduler（排程器）

補充：

-   CPU-bound Job：主要做大量 CPU 計算
-   I/O-bound Job：頻繁 I/O 操作、等待時間多

### 4.1. Long-term Scheduler（長期排程器）

又稱 Job Scheduler
特性：執行頻率最低
定義：

-   從 Job Queue 中挑選部分 job，載入到記憶體成為 Ready 的 process
-   控制 Multiprogramming Degree（同時在記憶體內的 process 數量）
-   混合使用 CPU-bound 和 I/O-bound process，維持平衡
    適用：Batch system
    不適用：Real-time、Time-sharing system（不需 job 控制）

### 4.2. Short-term Scheduler（短期排程器）

又稱 CPU Scheduler
特性：執行頻率最高
定義：

-   從 Ready Queue 中選出 最高優先權的 process，分派給 CPU 執行
-   決定 process 何時執行（Ready → Running）
-   存在於所有 OS 系統中（Real-time、Batch、Time-sharing）

### 4.3. Medium-term Scheduler（中期排程器）

常見於 Time-sharing system
特性：執行頻率中等(提升 multiprogramming 效率)
定義

-   當記憶體不足時，將某些 process Swap Out 到磁碟
-   當記憶體夠用，再 Swap In 回來
    執行條件：通常挑選 Blocked 狀態或低優先權的 process，將其暫時從記憶體中移除以釋放空間，等有空間後再放回來執行
    適用：Time-sharing（使用 virtual memory）
    不適用：Real-time、Batch

## 5. Process Control Operations（系統呼叫 syscalls）

聚焦在 parent/child process 的建立與管理
常見操作包括：

-   建立、結束、暫停、恢復程序（process）
-   設定 / 修改 / 讀取 process 的屬性（attributes）
    理論基礎
-   任一 process 可建立自己的 child process（子程序）

1. 建立建立 child process 的目的
    - 與 parent 相同工作（例如：`vi` 編輯器）
    - 不同工作（例如：`server` / `ftp`）
2. 建立 child process 後，所需資源由誰提供
    - OS 提供：由作業系統直接分配資源
    - parent process 提供：由父程序分享給子程序
3. parent 建立出 child 後，兩者互動形式
    - Concurrent execution（並行）：parent 與 child 同時執行
    - 順序執行：parent 等待 child 執行完畢才繼續（`wait()` 系統呼叫）
4. parent 終止時對 child 的影響：
    - 一併終止 → Ascending Termination：parent 死，child 也會跟著被終
    - Child 存活，但資源繼承者為？
        - OS 回收
        - grandparent 或其他 process 繼承（通常為 init process）

## 6. UNIX 常見 Process 系統呼叫整理

### 6.1. 子程序與父程序溝通的正確方法：

方法一：透過檔案（file）

-   child 寫入檔案 → parent 再讀取結果
    方法二：使用 pipe（管道）
-   建立 pipe → fork → 子寫入、父讀取（須處理 file descriptor）

### 6.2. `fork()` — 建立新 Process

功能：複製目前的 process，產生一個 child process
回傳值：

-   `0`：回傳給 child process
-   `>0`：回傳給 parent，值為 child 的 PID
-   `<0`：建立失敗
    `fork()` 前後記憶體結構

| 時機        | 描述                                                                    |
| ----------- | ----------------------------------------------------------------------- |
| Before fork | 一個 PCB 指向父程序的 code/data                                         |
| After fork  | 建立 child process，**複製**父的 code/data，新的 PCB 指向這份複製的空間 |

### 6.3. `wait()` — 等待子程序結束

功能：parent process 等待 child 結束再繼續執行  
常用於 同步控制 parent 與 child 執行順序

### 6.4. 6.3.`exit()` — 結束目前的 process

`exit(0)`：正常結束  
`exit(1)`：異常結束

### 6.5. 4️⃣ `exec()` 家族 — 執行新程式

如 `execlp(path, arg1, arg2, ..., NULL)`
功能：載入特定的 binary 程式到 memory 中執行之用=>取代原有程式內容
如果 child 呼叫 `exec()`：code section 將被新程式取代
常與 fork() 搭配使用：child 建立後用 exec 執行新工作

### 6.6. 範例：基本 fork + exec + wait 範例

```c
int pid = fork();
if (pid == 0) {
    execl("/bin/ls", "ls", NULL); // child 執行 ls
} else {
    wait(NULL); // parent 等 child 結束
    printf("child completes\n");
}
```

### 6.7. 範例：變數不共享（fork 複製記憶體空間）

📌 Child 與 Parent 各自有自己的 `sum`，互不影響。

```c
int sum = 0;
pid_t pid = fork();
if (pid == 0) sum += 10;
else wait(NULL);
printf("sum = %d\n", sum);
```

### 6.8. 範例：fork 產生多少個 process？

```c
fork();
fork();
fork();
```

每次 fork() 是 2 倍增長 → 總共產生 8 個 process（包含 main）
通則：若有 `n` 個 `fork()`，最多可產生 `2^n` 個 process

## 7. Context Switching（內容切換）

定義：當 CPU 要從一個正在執行的 **process** 切換到另一個 process 時，kernel 必須儲存目前 process 的執行狀態(包括 PC、CPU Registers、Stack、Process 狀態資訊（存在 PCB），並載入目標 process 的狀態(即從目標 process 的 PCB 中還原)

這整個動作就是 **Context Switching**（上下文切換）
Context Switching 的負擔（overhead）：切換時，kernel 必須不斷儲存/還原大量狀態資訊，效率開銷高
降低負擔的方法：

-   方法一：多組 Registers（成本較高）
    -   每個 process 擁有一組獨立的 register set
    -   CPU 在不同 process 間切換時，只需要切換「register set pointer」
    -   不需 memory 的 store/restore 操作
    -   切換快但成本高需要額外儲存空間
-   方法二：使用 Multithreading 技術
    -   系統進程（system process）與使用者進程（user process）分別擁有獨立 register set
    -   切換時只換 pointer，實作方式類似於虛擬記憶體的獨立空間概念

![upgit_20250403_1743664847.png|513x323](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250403_1743664847.png)

## 8. Dispatcher（分派器）

定義：Dispatcher 是一個模組，負責在 CPU scheduler 挑出 process 後，實際將 CPU 指派給該 process。
分派任務作所耗的時間稱為： Dispatch Latency（分派延遲）
主要任務（三大項）：

1. Context Switching（切換執行中 process）
2. Mode 切換（從 kernel mode → user mode）
3. 跳轉至 user process 的 entry point 開始執行

評估 Scheduling 效能的 5 項標準

| 項目                        | 定義                                         | 目標趨勢 |
| --------------------------- | -------------------------------------------- | -------- |
| CPU Utilization（利用率）   | CPU 執行工作的百分比                         | 越高越好 |
| Throughput（吞吐量）        | 單位時間完成的 jobs 數量                     | 越多越好 |
| Waiting Time（等待時間）    | Process 在 Ready Queue 中等待 CPU 的總時間   | 越少越好 |
| Turnaround Time（週轉時間） | Process 從進入系統到完成工作的整段時間       | 越短越好 |
| Response Time（回應時間）   | 從 user 發出指令到系統產生**第一反應**的時間 | 越快越好 |

### 8.1. aiting Time 範例：

-   3 個 process，執行順序為 P1→P2→P3
-   起始時間分別為 0、10、23，完成時間為 30
-   計算：

```text
P1: 0 等待 0
P2: 等待 = (30 - 10) - 10 = 10
P3: 等待 = (30 - 23) - 7 = 0
總等待時間 = 10 + 8 = 18
```

### 8.2. Turnaround Time 範例：

```text
Start = 0, End = 30 → Turnaround = 30 - 0 = 30
```

### 8.3. Response Time 說明：

-   從 user 發出指令 到系統第一次產生回應的時間
-   在 Time-sharing 系統中特別重要（user-interactive）

## 9. CPU 排班演算法

常見演算法：

-   FIFO / FCFS（先來先服務）
-   SJF（Shortest Job First）
-   SRTF / SRJF / SRTN（Shortest Remaining Time First）
-   Priority（優先權）
-   RR（Round Robin）
-   Multilevel Queues
-   Multilevel Feedback Queues

### 9.1. Preemptive vs Non-Preemptive 排程比較

| 特性         | Preemptive                      | Non-Preemptive              |
| ------------ | ------------------------------- | --------------------------- |
| 切換時機     | 高優先 process 到達就中斷       | 當前 process 完成前不會中斷 |
| 損耗（開銷） | Context switching 高            | Context switching 低        |
| Starvation   | 容易發生                        | 不太會發生                  |
| 適用場景     | Time-sharing, Real-time systems | 批次處理 Batch              |

### 9.2. Starvation（飢餓現象）

定義：Process 長時間無法取得 CPU 資源 → 遲遲無法執行
可能原因：優先權過低、永遠等不到排程
解法：Aging => 隨著等待時間增加，自動提升 process 優先權

### 9.3. FIFO（First In First Out）

定義：先到者先執行
類型：非搶佔式
優點：簡單、無 starvation
缺點：平均等待時間長、有 Convoy Effect（護航效應）

### 9.4. SJF（Shortest Job First）

定義：選擇最短 CPU burst 的 process 執行
類型：非搶佔式
優點：平均等待時間最低
缺點：易飢餓、難以預測 burst time

### 9.5. SRTF（Shortest Remaining Time First）

定義：每次都選擇剩餘時間最短的 process 執行
類型：搶佔式 SJF
優點：比 SJF 還短的等待時間
缺點：Context switching 多、易飢餓

### 9.6. RR（Round Robin）

定義：Time-sharing 系統常用，每個 process 有固定時間片（Quantum）
類型：搶佔式
優點：公平、無 starvation
缺點：Context switching 多，效率視 Quantum 而定

### 9.7. Priority Scheduling

定義：優先順序數字越小者越先執行
類型：可為搶佔或非搶佔
優點：可設定重要性
缺點：會 starvation（解法：aging）

### 9.8. Multilevel Queues（多層隊列）

定義：根據 process 類型分到不同隊列（如：foreground, background）
每個 queue 有自己排程方式
不同 queue 間採 preemptive 優先權排程

### 9.9. Multilevel Feedback Queue（可遷移）

定義：與 Multilevel Queue 類似，但允許 process 根據行為升降 queue
使用 aging 技術，防止 starvation
非常彈性，高真實性
規則：若在 Q1 未完成，降到 Q2...
低優先 queue 使用時間片越大（處理大型任務）

## 10. 多核心排程設計考量（Multiprocessor Scheduling）

架構：

-   ASMP：Master-slave 架構（類似單核心無甚協調）
-   SMP： - 共用 common ready queue - 各 CPU 有自己的 private ready queue - 當 CPU 完成自己的 process 後，就會取 common ready queue 的 process
    設計考量：
-   必須確保 queue 操作互斥，避免 race condition
-   需考慮 load balancing 問題
-   若未提供上述機制，則會發生【process 重複執行】或【process 被忽略】

### 10.1. Race Condition（競爭狀態）

定義：當多個 CPU 或執行緒同時存取/修改共享資源（像是 ready queue）而沒有適當同步機制時，就可能發生 race condition。
問題情境：

-   假設兩個 CPU 同時要從 common ready queue 取出下一個 process：
-   CPU1 檢查 queue：發現 P1 在最前面
-   CPU2 也同時檢查 queue：也發現是 P1
-   兩個都決定執行 P1 => 結果 P1 被執行兩次（重複執行）
-   或者，某 CPU 在從 queue 移除 P1 時，還沒完成，就被打斷，另一個 CPU 又嘗試操作 queue，導致：queue 資料錯亂、遺失 => process 被忽略或永久不被執行
    解法：使用 lock/mutex/synchronization 機制 保護 queue 操作，確保一次只有一個 CPU 能讀寫 queue。

### 10.2. Load Balancing（負載平衡）

定義：多核心系統中，應該平均分配 process 給每個 CPU 處理，避免某些 CPU 忙到爆炸，而其他 CPU 閒到發呆。
問題情境：

-   以 private ready queue 為例：
-   CPU1 有 10 個工作忙翻天
-   CPU2 queue 是空的，一直 idle
-   沒有 load balancing 機制 => 整體效率低下，CPU utilization 下降
    解法：
-   解法 01：Push migration（推式）：系統定時檢查所有 CPU 的負載，把多的工作推到閒的 CPU
-   解法 02：Pull migration（拉式）：閒的 CPU 主動去其他忙碌的 CPU 拉一個 process 來跑

## 11. 五、Real-Time System 排程設計

### 11.1. Process Affinity(喜好)

定義：在 Multiprocessor 中，當 process 已經決定在某 CPU 上執行，就盡量不要將他移植到其他 CPU 上面執行。避免 CPU 內之 cach 等內容還要執行複製、刪除等操作，影響效能。
分類：

-   Hard-Affinit：規定 process 不可以轉移
-   Soft-Affinity：盡可能不轉移
    要考慮的點：
-   任務是否 schedulable？（能否準時）
-   演算法：
    -   Rate-Monotonic (RM)：靜態優先權，period 越小，優先越高
    -   EDF (Earliest Deadline First)：動態優先權，deadline 越近越優先

### 11.2. Real-Time System 的 Priority Inversion

描述：發生在高優先權任務需要等待低優先權任務釋放資源時，系統卻先讓中優先權任務執行，導致高優先權任務被延遲。
舉例說明：

-   高優先任務 P1 想使用資源 R，但 R 被低優先任務 P3 佔用
-   此時中優先任務 P2 插隊執行，導致 P3 無法釋放 R
-   結果：P1 被 block，P3 無法執行 ⇒ 整個系統卡住
    解法：Priority Inheritance（優先權繼承）
-   系統暫時提升 P3 的優先權等同於 P1，讓 P3 有機會先執行完釋放資源
-   當 P3 完成後，優先權會自動還原，P1 繼續執行

### 11.3. Real-Time System 的 Dispatch Latency

Dispatch Latency 分兩段：

-   Conflict Phase：Kernel 正執行長時間任務或資料結構
-   Dispatch Phase：切換任務所需時間（context switch, mode change 等）

![upgit_20250404_1743747253.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250404_1743747253.png)
