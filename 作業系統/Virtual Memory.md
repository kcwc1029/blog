定義：讓 process 的大小**可以超過實體記憶體**的剩餘空間。
目的：允許大型程序在記憶體不足的情況下，仍然可以執行。

## 1. 運作原理：

### 1.1. 早期方法

使用 overlay 技術（一種 Dynamic Loading）
程序中需要的模組才會被「Load-on-call」
缺點：需程式設計師自行負責管理載入與釋出，OS 不處理。

### 1.2. 現代作法

作業系統提供 Virtual Memory 功能
優點：

-   程式設計師不需使用 overlay 技術，交由 OS 管理
-   提升 memory utilization（記憶體利用率）
-   提升 Multiprogramming Degree，增加 CPU 使用效率

> [!NOTE] 補充
> Utilization：允許同時存在更多 process，進而增加效率
> Thrashing（顫動現象）：I/O transfer time 變長，process 一直在換頁 → 效能反而變差

## 2. 實現 Virtual Memory 技術：Demand Paging（需求分頁）

是架在【page memory management】的基礎上
定義：類似 Lazy Swapper：初始不載入任何 page，等到程序執行到某個 page 時，才觸發 page fault 再載入

運作機制

1. 每當~一個 process 執行，只有部分 page 會載入 memory
2. 若要執行的 page 尚未載入 → 發生 page fault
3. OS 會：
    - 從 secondary storage 把缺失的 page 載入 free frame
    - 更新 page table

### 2.1. Page Table 與 Valid/Invalid Bit

每個 process 都有一張 page table，紀錄 page 對應的 frame  
Valid Bit：代表 page 在 memory 中
Invalid Bit：代表 page 不在 memory 中（還在 disk）

> OS 負責設定 Valid / Invalid Bit
> MMU（記憶體管理單元）\*\*只負責參考，不修改

### 2.2. Page Fault 處理流程

定義：當程式嘗試存取尚未載入至主記憶體的 page 時，就會觸發一個 中斷（trap）。

-   若該記憶體位址非法，則為「非法錯誤（invalid access）」，OS 將終止該 process。
-   若是合法的 page fault，則執行以下步驟。

1. MMU 偵測錯誤：偵測到「**address error**」，產生中斷（trap），並通知 OS。
2. OS 處理中斷：OS 暫停當前 process，儲存其狀態資訊（如 general-purpose registers、PC、page table register 等）。
3. OS 驗證記憶體位址是否合法：
    - 若不合法：OS 終止該 process
    - 若合法：確認為 page fault，繼續處理
4. 檢查是否有可用的 free frame
    - 有 free frame：直接使用
    - 若沒有：執行 page replacement，騰出一個 free frame
5. 從磁碟中載入缺失的 page：啟動 Disk I/O，把缺失的 page 載入剛剛取得的 free frame
6. 更新 Page Table
    - 將 page table 中的該項目更新為：
    - 對應到新 frame 號碼
    - 將 Invalid Bit → Valid Bit
7. 恢復執行
    - 回復原本中斷前的 process 狀態
    - 或將該 process 狀態設為 `ready`，等候 CPU Scheduler 決定何時重新執行

## 3. Page Fault Ratio 的影響因素

Page Replacement Algorithm 的選擇：如 FIFO、LRU、Optimal 等策略會直接影響 page fault 數量。
Frame 數量的分配多寡：Frame 越多，page fault ratio 通常會降低。
Page Size（頁面大小）

-   頁面太大：可能增加內部碎裂，降低使用效率
-   頁面太小：管理成本高，TLB miss 增加
    Program Structure（程式結構）：若程式使用區域性差，或頻繁跳躍位置，也會影響 page fault ratio

## 4. Page Replacement（頁面替換）

![upgit_20250412_1744437560.png|854x303](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744437560.png)
條件：當 page fault 發生且記憶體已無 free frame 時
作法：

-   選出一個 victim page（被替換頁）
-   SWAP OUT 到 backing store（如 disk）
-   將失敗的 page 載入 free frame
    不良影響
-   每一次 SWAP 都是一次 I/O ⇒ 耗時
-   victim page 若需寫回 disk（非乾淨頁），I/O 成本更高
-   多次 page fault ⇒ 增加系統的整體記憶體管理延遲

如何降低 swap out 次數？

-   在 page table 中新增「Modification Bit（或 Dirty Bit）」：表示該 page 是否有被修改 - `0`：未改動（可不需寫回 disk） - `1`：有改動（需 SWAP OUT）
    OS 會檢查該 bit：
-   若為 `0` ⇒ 可以直接釋出，不需寫回 disk
-   若為 `1` ⇒ 必須寫回，增加 I/O 次數
    這個 bit：
-   是由 MMU 設定（0 → 1）
-   並由 OS 重設（1 → 0）

## 5. Page Replacement Algorithm

### 5.1. FIFO（First-In First-Out）

定義：替換「最早載入」的頁面為 victim page
優點：簡單、好實作
缺點：

-   Page fault ratio 通常偏高
-   會發生 Belady’s Anomaly（frame 增加時，page fault 卻可能增加）

### 5.2. 補充：Stack Property（堆疊性質）

定義： 若某演算法在 n 個 frame 下的 page set 一定是 (n+1) 個 frame 下的子集合，則具有堆疊性質。
重要性：擁有 stack property 的演算法不會發生 Belady’s Anomaly。
擁有此性質的演算法： OPT（Optimal）、LRU（Least Recently Used）

### 5.3. OPT（Optimal）

定義：替換「未來最久都不會使用的頁面」
優點：

-   最低 page fault ratio，理論最優
-   不會有 Belady’s Anomaly
    缺點：無法實作，只能當作比較基準

### 5.4. LRU（Least Recently Used）

定義：替換最近最久未使用的頁面
優點：

-   效果好，接近 OPT
-   無 Belady’s Anomaly
    缺點：實作成本高，需追蹤歷史資料存取順序
    實作方式：
-   Counter 法
    -   每次 memory access，更新一個 counter（代表 logical time）
    -   替換時選擇最久未被訪問的頁面（counter 最小）
-   Stack 法
    -   每次被存取的頁面移到 stack 頂端
    -   Bottom 為 LRU page（最久未被使用）

### 5.5. Second Chance（二次機會法）

定義：在 FIFO 基礎上增加 Ref. Bit
流程：

1. 從 FIFO 順序選出候選頁
2. 若 Ref. Bit = 1：清除並放回尾端，重新排序
3. 若 Ref. Bit = 0：被替換

### 5.6. Enhanced Second Chance（加強版）

定義：在 Second Chance 基礎上加入 Dirty Bit（M Bit）
優點：可避免不必要的寫回磁碟，提升效能
範例：以 R/M 比對為依據，挑出最適合 victim
選擇優先順序：

| R Bit | M Bit | 優先順序               |
| ----- | ----- | ---------------------- |
| 0     | 0     | ✅ 最佳候選            |
| 0     | 1     | 次佳                   |
| 1     | 0     | 再次                   |
| 1     | 1     | 最差（最近有用又被改） |

### 5.7. LFU / MFU（Least/Most Frequently Used）

LFU 定義：替換被參考最少次數的頁面
MFU 定義：替換參考最多次數的頁面
特性：

-   根據統計次數（Counter）
-   會有 Belady’s Anomaly
-   須額外硬體或軟體支援計數器

### 5.8. Page Buffering Algorithm（頁面緩衝法）

定義：系統保留額外 free frame pool 來減少 page fault 的處理時間
優點：

-   victim page 可先換出，missed page 再補回
-   提升 page fault 後的 process restart 執行速度
    補充機制：
-   加入 page 鏈結追蹤 modified pages
-   儲存寫回的 page，以便將來重用

| 演算法       | 是否會 Belady’s Anomaly | 頁錯率 | 複雜度   | 適合用途     |
| ------------ | ----------------------- | ------ | -------- | ------------ |
| FIFO         | ✅                      | 高     | 低       | 簡單系統     |
| OPT          | ❌                      | 最低   | 無法實作 | 評估用       |
| LRU          | ❌                      | 中     | 高       | 效能需求高   |
| 2nd Chance   | ❌                      | 中     | 中       | 平衡法則     |
| Enhanced 2nd | ❌                      | 中     | 中偏高   | 寫入敏感系統 |
| LFU          | ✅                      | 可變   | 高       | 統計系統     |
| Buffering    | ❌                      | 較低   | 較高     | 頁面頻繁替換 |

## 6. Thrashing 現象（換頁震盪）

定義：當 process 被分配的 frame 數不足，導致它頻繁發生 page fault 並持續觸發 page replacement，而這些替換還會影響其他 process 的 page 被換出，進而形成惡性循環 ⇒ 整體系統效能急遽下降。

發生條件：

-   使用 global page replacement policy
-   所有 process 都在持續發生 page fault
-   Process 不斷互相替換彼此的 page
-   Ready queue 滿載，process 都在等待 I/O

現象結果：

-   CPU utilization **急速下降**
-   I/O 裝置過度忙碌（持續執行 swap I/O）
-   Process 幾乎花全部時間在處理 page fault，無法執行實際運算

![upgit_20250412_1744438734.png|626x172](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744438734.png)

CPU utilization 對 multiprogramming degree 的關係如下：

-   初期增加 degree → CPU utilization 增加
-   超過臨界點後 → 開始 thrashing，utilization 反而降低

### 6.1. Thrashing 的解決 / 預防方法：

#### 6.1.1. 方法一：減少 Multiprogramming Degree

發生 thrashing 時，減少同時執行的 process 數量
釋出 frame，讓剩下的 process 有足夠的記憶體使用
可讓 CPU utilization 回升

#### 6.1.2. 方法二：使用 Page Fault Frequency (PFF) 控制法

為每個 process 設定合理的 **page fault ratio 上限與下限**
OS 動態調整 frame 分配數量
分析：

-   若某 process 的 fault ratio **大於上限** ➝ 給它更多 frames
-   若某 process 的 fault ratio **小於下限** ➝ 收回其多餘 frames 給其他 process

> 讓所有 process 的 page fault ratio 落在合理範圍，就能避免 thrashing

#### 6.1.3. 方法三：使用 Working Set Model

-   根據 process 在一定時間內參考的記憶體範圍（working set）估算其實際需要的 frame 數量
-   動態分配足夠 frames 給每個 process
-   可預測性地控制每個 process 的 memory footprint，有效防止 thrashing

形式定義：

> **WS(t, Δ)**：process 在時間 t 之前 Δ 單位時間內曾經參考過的 pages 集合

-   `t`：目前時間點
-   `Δ`：視窗大小（window size），用來決定參考的時間長度
-   `WS(t, Δ)`：這段期間曾經被使用的所有 page，即 working set

步驟：

-   OS 追蹤每個 page 最近的使用時間
-   定期掃描 page table，找出 Δ 時間內被使用的 pages
-   計算 working set size
-   為該 process 分配等量的 frames（或略多）
-   若全部 process 所需總和 > 總 frame 數 ⇒ 停掉一些 process（降低 multiprogramming degree）

優點

-   考慮 locality（區域性原則）
-   動態調整，避免靜態分配浪費
-   可搭配其他策略（如 page fault frequency）
    注意
-   OS 需記錄每個 page 的最後使用時間（開銷不小）
-   Δ 選太大：包含不必要的 pages → 浪費
-   Δ 選太小：不足以反映真實使用 → 頻繁換頁

以下是你提供的手寫筆記整理重點，內容涵蓋 Page Size、Program Structure、Copy-on-Write、TLB Reach 等作業系統記憶體管理主題：

---

## 7. Page Size 的影響

Page size 過小：

-   Page fault ratio ↓（較佳 locality）
-   Page table size ↑（更多 entries）
-   I/O 次數 ↑（分頁更多，I/O loading 更頻繁）

Page size 過大：

-   I/O transfer time ↓（一次搬大塊）
-   Locality ↓（浪費空間與資料）

趨勢：傾向使用較大的 page size，但要兼顧 fragmentation。

---

## 8. Program Structure 的影響

Locality Model 依賴程式存取模式：

-   良好的結構 ➝ Good Locality
-   差的結構 ➝ Bad Locality ➝ 多次 page fault

2D 陣列掃描方式差異

```c
int A[128][128]; // 每個 int 4 byte，page size = 128 byte
```

-   **Row-major（行優先）**：連續掃描記憶體，每列最多觸發一次 page fault（page 使用效率高）
-   **Column-major（列優先）**：每存取一欄就跳頁 ➝ page fault 次數極高

## 9. Copy-on-Write 技術

目的：提升 fork() 效率、避免不必要的記憶體複製

### 9.1. 三種 fork：

傳統 fork (no COW)

-   父子 process 各有獨立記憶體副本（全部複製）
-   ❌ 成本高、效能差
    fork + Copy-On-Write（COW）
-   初期共享父記憶體，設為唯讀
-   若子 process 寫入 ➝ page 被複製到新 frame
-   ✅ 減少不必要的複製
    vfork（虛擬 fork）
-   父子共用記憶體，直到 exec() 前
-   🚨 父 process 被暫停，需立刻 exec()
-   用於 shell 與 CLI 類系統

| fork 類型     | 說明                                       | 優點               | 缺點                            |
| ------------- | ------------------------------------------ | ------------------ | ------------------------------- |
| 傳統 fork     | 直接複製 parent 的整個記憶體               | 🛠 無需特殊硬體     | ❌ 複製慢、佔空間               |
| fork + COW    | 開始時共享記憶體、唯讀保護，寫時再複製     | ✅ 節省資源        | 實作較複雜                      |
| vfork（虛擬） | child 直接用 parent 空間，禁止 parent 執行 | ✅ 超快、適合 exec | 🚨 危險，parent 被凍結直到 exec |
