又稱「輕量級程序（Lightweight process）
定義：是 OS 分配 CPU 時間的最小單位。

-   Thread 是 CPU 利用的基本單元。
    多執行緒的優點（Multithreading 的好處）
-   Responsiveness：若主 thread 被 block，其他 thread 仍能回應使用者，提高互動性
-   Resource Sharing：多個 threads 可共享 process 的 code 和資源，節省記憶體
-   Economy：thread 建立與切換比 process 更快 → context switch 成本低、更有效率
-   Scalability：可在多 CPU 上同時執行同一個 process 的不同 threads → 增強 concurrency 與效能

## 1. Thread 與 Process 的關係

一個 Process 可包含多個 Threads，
這些 threads 共享：

-   Code section（程式碼區）
-   Data section（資料區）
-   OS resources（例如：open files, signal, heap memory）
    不共享（Private）
-   程式計數器 PC（Program Counter）
-   CPU Registers（暫存器值）
-   Stack（堆疊空間）
-   Thread 狀態（State）、Thread ID 等

| 項目                        | **Process**                                       | **Thread**                                                       |
| --------------------------- | ------------------------------------------------- | ---------------------------------------------------------------- |
| **定義**                    | Heavyweight process（重量級程序）                 | Lightweight process（輕量級程序）                                |
| **OS 資源配置單位**         | OS 分配資源的單位（Memory、IO、File）             | OS 分配 CPU time 的基本單位                                      |
| **資源共享情況**            | Process 之間無共享資源（除非透過 shared memory）  | 同一 process 內的 threads 可彼此共享：memory、code、resources 等 |
| **記憶體使用**              | 有各自的記憶體空間                                | 共用 process 的 memory 空間                                      |
| **建立與切換成本**          | 建立與 context switching 成本高（複雜）           | 建立、切換成本低                                                 |
| **執行阻塞影響**            | 一個 thread blocked，整個 process 會被 block      | 若還有可運行 thread，整個 process 不會被 blocked                 |
| **Multiprocessor 架構支援** | 支援（透過 shared memory 溝通）                   | 更佳支援，threads 可分散執行於不同 CPU 上                        |
| **資料互存與同步**          | 須使用 IPC（Inter-process Communication）         | 共享資源，必須小心同步與競爭問題                                 |
| **適用場景**                | 每個 task 獨立處理，如 shell、command interpreter | 同時執行多個小任務，例如：server 同時處理多用戶                  |

## 2. User-level vs Kernel-level Threads

### 2.1. User-Level Threads（使用者層級執行緒）

定義

-   Thread 的管理（建立、刪除、排程、切換）由 user space 的 thread library 負責。
-   Kernel 不感知 這些 threads 的存在（無需介入）。
    優點
-   Fast：thread 建立與切換速度快。
-   管理成本低，實作簡單（不需系統呼叫）。
    缺點
-   若 thread 發出 blocking 系統呼叫（例如 I/O），整個 process 都會被 block。
-   Kernel 是 single-threaded view（不知道內部有多個 threads）→ 不能有效利用 CPU。

在 Multiprocessor 架構下的劣勢：Kernel 無法將不同 threads 分派到多個 CPU 上 → 無法充分並行。

### 2.2. Kernel-Level Threads（核心層級執行緒）

定義： Thread 的管理由 Kernel 負責，每個 thread 都是 kernel 可見單位。
優點

-   Thread 被 block 時，kernel 可以讓其他 threads 先執行（更佳 responsiveness）。
-   支援真正的並行（threads 可被分配至不同 CPU）。
    缺點
-   建立、切換 thread 成本高，需要系統呼叫。
-   涉及 kernel 資源管理，相對複雜。
    實例：現代作業系統幾乎皆支援（e.g., Linux、Windows）

### 2.3. CPU 配額分配差異（重點範例）

假設有兩個 process：Pa 有 3 個 user threads、Pb 有 2 個
對於 User-level threads：

-   Kernel 不知道 threads 存在，只分配 50% 給 Pa，50% 給 Pb。
-   Pa：3 threads 分 50% → 每個分 16.7%；Pb：2 threads 分 50% → 每個分 25%
    對於 Kernel-level threads：
-   Kernel 知道總共 5 個 threads，平均分配 CPU 時間 → 每個 thread 得 20%
-   Pa 得 3×20% = 60%；Pb 得 2×20% = 40%

| 項目               | User Thread                | Kernel Thread            |
| ------------------ | -------------------------- | ------------------------ |
| 管理者             | User library               | Kernel                   |
| 是否被 Kernel 感知 | ❌ 不被感知                | ✅ 被感知                |
| 建立與切換效率     | ✅ 快                      | ❌ 慢                    |
| 若有 blocking 呼叫 | 整個 process 被 block      | 其他 thread 可繼續執行   |
| 適用場景           | 小系統、無 multiprocessing | 現代作業系統、大型伺服器 |
| 多核心利用         | ❌ 無法並行                | ✅ 真正多核支援          |

## 3. Multithreading 模型比較

![upgit_20250405_1743844886.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743844886.png)

### 3.1. 傳統 Single-threaded Model(其實就是 process)

-   每個 process 只能有一個 thread。
-   一旦 thread blocked（如 I/O 等待），整個 process 無法執行 → CPU 浪費。

### 3.2. Multithreaded Model（多執行緒）

同一 process 中有多個 threads，能共享記憶體、code、資源。
每個 thread 有自己的私有執行狀態與堆疊。

| 模型名稱        | 對應說明                                      | 優點 / 缺點                               |
| --------------- | --------------------------------------------- | ----------------------------------------- |
| Many-to-One     | 多個 user thread 映射到一個 kernel thread     | 快，但無法真正並行；一個 block 全部 block |
| One-to-One      | 每個 user thread 對應一個 kernel thread       | 真正並行；但開銷大、限制 thread 數量      |
| Many-to-Many    | 多個 user thread 對應數個 kernel thread       | 彈性最高、支援並行；複雜度較高            |
| Two-Level Model | Many-to-Many 的一種實作方式，支援 thread 綁定 | Solaris 2 以上支援                        |

### 3.3. Multithreading 問題（Issues）

#### 3.3.1. 問題 01：fork() 的問題是什麼？

`fork()` 是 Unix/Linux 裡一個系統呼叫，用來 **複製出一個新的 process**，通常發生在父程式想產生子程式的時候。
在 單執行緒（single-threaded） 中，`fork()` 很單純：複製整個 process 的程式碼和資料。
但在 多執行緒（multithreaded） 的情況下就麻煩了：如果我在一個擁有很多 thread 的 process 中呼叫 `fork()`，到底要不要「也把那些 thread 一起複製過去」？
有兩種實作方式：

| 實作方式                   | 描述                                                                                               |
| -------------------------- | -------------------------------------------------------------------------------------------------- |
| ✅ **只複製呼叫者 thread** | 較常見、安全。fork 出來的 child process 只有當下那個呼叫 fork() 的 thread。                        |
| ⚠️ **複製所有 thread**     | 比較危險，因為原本其他 thread 可能正好在執行敏感操作（像 mutex、socket），一複製過去容易造成錯亂。 |

#### 3.3.2. 問題 02：signal 是什麼？

Signal 是作業系統傳給 process 的一種「訊息」或「中斷」，例如：

-   division by zero
-   segmentation fault（非法記憶體存取）
-   ctrl + C
-   timeout
    問題：一個 process 裡如果有很多個 threads，那 signal 到底該傳給誰？
    常見的 4 種 signal 傳遞策略：

| 策略                   | 解釋與例子                                                     |
| ---------------------- | -------------------------------------------------------------- |
| 傳給「特定 thread」    | 用於 **同步訊號**，像是除以零。只該通知發生問題的那個 thread。 |
| 傳給「所有 threads」   | 通常是非同步訊號，像 `Ctrl+C`。所有 threads 都知道被通知。     |
| 傳給「部分 threads」   | 作業系統自行決定傳給哪幾個（例：Unix）。                       |
| 指定某 thread 接收訊號 | 程式明確設定一個 thread 處理所有訊號（例：Solaris 2）。        |

## 4. Thread Pool

原因：在 client-server model 中，如果 server 在收到 client 的 request 才臨時建立 thread：

-   儘管 Thread 建立很快，但仍需耗費一些時間。
-   若有大量 clients，同時請求會造成 延遲（latency），影響回應速度。
    解法：Thread Pool
-   Server 一開始就 預先建立一組 threads 放入「thread pool」中。
-   當有 client 的 request 到達時：
    1.  Server 直接從 thread pool 中 派出一個可用的 thread 處理任務。
    2.  任務完成後，thread 回到 pool standby。
    3.  若 pool 中無空閒 thread，client request 就得等 → 延遲仍可能發生，但可控。
-   此方法大幅減少了「client 請求 ↔ thread 處理」之間的反應時間。

優點：

-   提高系統反應速度（responsiveness），減少 request 等待時間。
-   避免每次都重新建立 thread 的 overhead。
    缺點：
-   若建立過多 threads（比實際需要多），會造成：
    -   系統資源（memory、CPU）浪費。
    -   效能下降。
-   通常會有上限 → 限制 thread pool 的大小（size）。
