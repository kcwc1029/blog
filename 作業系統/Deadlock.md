定義：系統中存在一組 processes，形成 circular waiting（循環等待），無法再執行。

## 1. Deadlock 發生的四個必要條件

只要 任一不成立，就不會發生 deadlock：

-   互斥（Mutual exclusion）
    -   資源一次只能給一個 process 使用（不可共用）
    -   例：CPU、I/O 裝置；反例：read-only file（可共享）
-   持有並等待（Hold and wait）：Process 持有部分資源，並等待其他資源
-   不可搶奪（No preemption）：已分配資源無法強制搶回，只能等釋放
-   循環等待（Circular wait）：一組 process 間形成循環等待，像是

```
P0 等 P1，P1 等 P2，...，Pn 等 P0
```

## 2. Resource Allocation Graph（資源分配圖，RAG）

定義：有向圖 G=(V,E)G=(V,E)，用來表示資源與 process 之間的關係
頂點（Vertex）

-   Process：以圓形表示
-   Resource：以方框表示，內部小圓代表資源單位（instance）
    邊（Edge）類型：
-   申請邊：P → R（process 向資源申請）
-   分配邊：R → P（資源分配給 process）
    判斷 Deadlock 的圖形特徵(三點總結)：
-   No cycle → 一定無 deadlock
-   有 cycle → 不一定有 deadlock
-   若所有資源皆為單一數量（single-instance）→ 有 cycle ⇔ 有 deadlock
    (反例補充)有 cycle，但不一定死鎖（例如資源會釋放）

## 3. Deadlock 的處理策略（Handling Methods）

### 3.1. 策略 01：Deadlock Prevention（預防）

理念：破壞 四個必要條件中的任一個，讓 deadlock 永遠不會發生。
優點：確保 system never enters deadlock state
缺點：可能造成資源利用率（utilization）與系統吞吐量（throughput）降低

四個條件的預防方式：

-   破壞 Mutual Exclusion：幾乎不可能（大多資源天生互斥）
-   破壞 Hold and Wait：要求 process 一開始就申請所有資源
    -   缺點：資源浪費、utilization 低
    -   容易發生 starvation（資源久等不到）
-   破壞 No Preemption：

    -   作法：強制回收資源（如 based on priority）
    -   缺點：可能造成 starvation

-   破壞 Circular Waiting：使用 Resource Ordering 資源排序法

#### 3.1.1. Resource Ordering 資源排序法

作法：

-   給每種資源一個唯一的 ID
-   規定 process 只能依 ID 遞增順序 請求資源（ascending）
    例子：
-   已持有 R1，要請求 R3 → OK（R1 < R3）
-   已持有 R3，要請求 R1 → 不行，需先釋放 R3
    結論：若所有 process 遵守資源遞增請求規則，則不會形成 circular waiting

### 3.2. 策略 02：Deadlock Avoidance（避免）

系統在 process 提出資源申請後，會執行一個 安全性演算法（Safety Algo） 來判斷是否會導致 unsafe state（不安全狀態）
使用 Banker's Algorithm（銀行家演算法）

-   若為 safe → 允許資源申請
-   若為 unsafe → 不允許，需稍後重申請

#### 3.2.1. Banker's Algorithm（銀行家演算法）

#### 3.2.2. Safety Algorithm（安全性演算法）

### 3.3. 策略 03：Deadlock Detection & Recovery（偵測與恢復）

目標：系統允許 deadlock 發生，但需有方法可以偵測並恢復

#### 3.3.1. Deadlock Detection Algorithm（死鎖偵測演算法）

#### 3.3.2. Deadlock Recovery 方法 01：Kill Processes（終止程序）

作法 1：Kill 掉 deadlock 中的 一個一個 process

-   通常挑選 低優先權（low priority）的
-   優點：影響較小
-   缺點：仍可能造成任務失敗、需重試
    作法 2：直接 kill 所有 deadlock 中的 processes
-   缺點：cost 非常高（所有 job 重來）

#### 3.3.3. Deadlock Recovery 方法 02：資源搶佔（Resource Preemption）

步驟：

-   選定要搶回資源的 victim process
-   暫時回收該 process 的資源
-   將 victim 的狀態儲存（如 context, program counter）
-   重新啟動其執行時需重新配置資源
    -   可能多次重複、造成高成本
