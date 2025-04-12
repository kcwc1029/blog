## 1. binding

定義：Binding 是指決定程式執行時的起始位址的動作。

Binding 的三個時機：

| 時機點         | 由誰決定       | 說明                                       |
| -------------- | -------------- | ------------------------------------------ |
| Compiling Time | Compiler       | 在編譯階段直接決定絕對記憶體位置，無法搬動 |
| Loading Time   | Linking Loader | 程式載入到記憶體時再決定位置（常見）       |
| Execution Time | 作業系統（OS） | 執行過程中才決定起始位置（最有彈性）       |

![upgit_20250409_1744207428.png|870x341](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250409_1744207428.png)

### 1.1. Compiling Time 做 binding

由 Compiler 決定，在 compile time 直接決定絕對記憶體位置，Linking Loader 就負責 allocate(資源分配)與 loafing。
所產生的 object code 稱為 absolute object code
通常用於命令檔(.com)
缺點：proces 若要改變起始位置，則必須 re-compiling，不便

### 1.2. Loading Time 做 binding

> 補充
> relocation：把「寫死」的位址改掉
> linking：把「還不知道的」外部東西補上

compile 所產出的 object code 為 "relocatble object code(可重定位之目的碼)"
relocatble object code 除了地址，還會包含：

-   Relocation info：將程式從磁碟搬到記憶體不同位置時，需要修改原本硬編的位址。
-   Linking info：處理「使用外部函式或變數」的位址填入問題
    優點：程式起始位置若要改變，只需要重新 relocation、linking 即可，不用 re-compiling
    缺點：
-   因為程式執行要 linking，所以只要 processs 重新執行，就要在 re-linking => 若 module 數多就很花時間
-   processs 在執行期間，不可更改起始位址

> [!NOTE] 凡是【static binding】接無法更改

### 1.3. Dynamic Binding / Loading / Linking

#### 1.3.1. Dynamic Binding（動態綁定）

定義：程式的起始位址到 執行時（Execution time） 才決定。
需要硬體支援（MMU - 記憶體管理單元）：利用 Base Register 基底暫存器 + offset 來轉換位址。
優點：位置彈性大。
缺點：效能較差。

#### 1.3.2. Dynamic Loading（動態載入）

定義：「Load-on-call」，某些 module 不先載入，等執行時才載入到記憶體。
目的：節省記憶體空間、提升記憶體利用率。
需要：程式設計師自行管理（早期 overlay 技術）
缺點：執行效率差。

#### 1.3.3. Dynamic Linking（動態連結）

定義：module 間不預先連結，而是等 module 被呼叫時才載入 並進行連結。
常見應用：Library Linking，例如動態連結函式庫（DLL）。
優點：

-   可以共享函式庫內容。
-   Library 更新後程式自動使用新版本。
    需要 OS 支援。

## 2. Contiguous Memory Management（連續性配置）

定義：要求 OS 幫 process 找到一塊足夠大的連續性空間（Contiguous memory block）使用。
process 所占用的空間稱為 Partition，Partition 數目不固定，各 Partition 大小也不一定相同。
OS 利用 linked-list 的方式來管理 free memory block，稱為 Available list (AV-list)

配置方法 01：First-Fit

-   從頭開始找第一個符合大小的區塊
-   時間效率最佳，但空間利用差
-   是實作常用的方案。
    配置方法 02：Best-Fit
-   找剛好夠大的那塊
-   空間利用最佳，容易產生碎片
-   最適合節省記憶體，但效率較差。
    配置方法 02：Worst-Fit
-   找最大的空間來放
-   希望保留大空間，空間利用差
    配置方法 04：Next-Fit（First-Fit 改良）
-   從上次配置成功的位置開始往後找（避免一直掃描頭部）
-   AV-list 變成 circular（循環）

| 方法      | 配置效率 | 空間利用率 |
| --------- | -------- | ---------- |
| First-Fit | ⭐ 最快  | 中等       |
| Best-Fit  | 慢       | ⭐ 最佳    |
| Worst-Fit | 慢       | 差         |

## 3. External Fragmentation（外部碎裂）

定義：使用連續性配置策略時，即使有足夠總空間，但被切成多個小塊且不連續，導致無法配置給一個需要大空間的 process。
範例：

-   Process 需要 480K
-   零碎空間總共：300K + 200K + 100K = 600K ✅
-   但因不連續 ❌ → 無法配置

## 4. Internal Fragmentation（內部碎裂）

定義：實際分配的空間比 process 真正需要的還要多，多出來的空間無法使用造成浪費。
範例：分配 400K 空間給 process，但實際只用了 320K → 有 80K 的內部碎裂

| 問題類型               | 成因             | 解法               | 難處           |
| ---------------------- | ---------------- | ------------------ | -------------- |
| External Fragmentation | 記憶體空間分散   | Compaction、Paging | 搬移成本高     |
| Internal Fragmentation | 空間分配大於需求 | 改精細分配策略     | 空間使用效率差 |

### 4.1. 解決 External Fragmentation 的方法 01：Compaction（壓縮）

定義：「將正在執行的 process 搬移，使原本的非連續空間轉為連續」

-   移動 process 位置，把原本分散的 Free Memory Block 合併成一塊大區塊
    困難點：
-   不容易找出最佳搬法（Optimal Policy）
-   需要支援 Dynamic Binding → 因為搬移過程會改變記憶體位址，程式需支援執行期間位址轉換

### 4.2. 解決 External Fragmentation 的方法 02：page memory management(分頁式記憶體管理)

![upgit_20250410_1744260433.png|1078x331](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250410_1744260433.png)

基本概念

-   Physical Memory：被劃分為固定大小的區塊，稱為 Frame（頁框）
-   Logical Memory：被劃分為固定大小的區塊，稱為 Page（頁面）
-   Page Size = Frame Size：頁面大小與頁框相同，才能對應配置
    Page Table（頁表）
-   OS 會替每個 process 建立一個 page table，紀錄 process 之各 page 所在的 frame no
-   由 MMU（Memory Management Unit） 自動處理轉換邏輯位址 ➜ 實體位址
    解釋：Paging 允許非連續配置，只要記憶體中有足夠數量的 frame 就能配置成功。
    Page Protection（分頁保護）：
-   Page Table 加入 Protection Bit，可防止 process 誤用某些共享 page（如 library code） - R：唯讀 - W：可寫 - RW：可讀可寫
    優點
-   無 External Fragmentation：因為每個分頁可以分散配置
-   支援 Memory Sharing：不同 Process 可共享相同 page（例如共用 Library）
-   支援 Memory Protection：Page Table 可設定每頁是否為唯讀（R）或可寫（W）
-   支援 Dynamic Loading / Linking / Virtual Memory

缺點

-   有 Internal Fragmentation：若 page size > process 需求，最後一頁常會浪費空間
-   需硬體支援 MMU：頁表管理與位址轉換需額外硬體支援
-   有效存取時間變長：因為要經過頁表查詢，增加 memory access latency

### 4.3. 問題：Page Table 太大

每個 process 都需要自己的 page table。

-   假如 page size 很小、logical address 很大，會導致 page table 非常龐大。
    缺點：
-   佔用大量記憶體。
-   建立與存取效率差。

#### 4.3.1. 解決方法 01：Hierarchical Paging（階層式分頁表）

![upgit_20250410_1744263742.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250410_1744263742.png)

又稱：multilevel paging、forward-mapping paging。
概念：把 page table 再分頁（page the page table）。
優點：按需載入，只需載入使用到的部分，節省 memory space。
缺點：存取位址時需多次 memory access。

> 解決的是 **page table 太大** 的問題。

#### 4.3.2. 解決方法 02：Hashing Page Table（雜湊分頁表）

![upgit_20250410_1744263759.png|1078x345](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250410_1744263759.png)
概念：用 hashing 將 page number 對應到對應的 bucket（儲存 frame number）。
結構：每個 bucket 可以是 linked list 方式儲存多筆資料（處理碰撞）。
優點：搜尋速度快。
缺點：空間利用率低於 hierarchical paging。

> 解決的是 **page table 太大** + **位址空間稀疏** 的問題。

#### 4.3.3. 解決方法 03：Inverted Page Table（反轉分頁表）

![upgit_20250410_1744264251.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250410_1744264251.png)

問題：

-   傳統的 page table 是：每一個 process 都要有自己的 page table，記錄所有的 page 對應到哪個 frame。
-   如果有很多個 process，每個都要一份 page table → 記憶體空間爆炸。
-   每個 table 裡的 entry 也很多（因為 virtual address space 很大）。
    概念：每一個實體記憶體的 frame 對應一個 entry，記錄「==這格 memory 是哪個 process 的哪個 page==」。
    優點：整個系統只需一份 page table，記憶體需求低。
    缺點：因為要透過 (process ID、page number) 查找，要用線性搜尋或 Hash ⇒ 效率差。
    > 解決的是 page table 空間太大 的問題，但會帶來 存取速度變慢 的副作用。

### 4.4. Segment Memory Management（分段記憶體管理）

基本觀念

-   Physical memory（實體記憶體）：視為一連串的連續 memory blocks。
-   Logical memory（邏輯記憶體）：將 process 視為數個 segment，像是 Code segment、Data segment、Stack segment，每個 segment 內部要連續，但**大小不一定相同**
-   OS 幫每個 process 建立一個 Segment Table，紀錄每段的 **base（起始位址）** 與 **limit（長度）**

位址轉換（Logical ➜ Physical Address）

-   Logical address = ⟨s, d⟩，s 為 segment number，d 為 offset
-   查表取得該段的 base 與 limit，計算：
    -   若 d < limit ➜ 有效，physical address = base + d
    -   否則為非法存取

優點

-   支援：Memory sharing、Memory protection、Dynamic loading / linking
-   與 user 邏輯記憶體結構一致

缺點

-   有 external fragmentation
-   需額外 HW 支援（segment table 製作與查表邏輯）
-   effective memory access time 較長

![upgit_20250410_1744266289.png|1078x614](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250410_1744266289.png)

Segment vs. Page 的比較表（整理）

| 比較項目            | Paging                   | Segmentation             |
| ------------------- | ------------------------ | ------------------------ |
| 單位大小            | 各 page 大小相同         | 各 segment 大小不一定    |
| Fragmentation       | 無 external，有 internal | 有 external，無 internal |
| 記憶體對應          | 難以對應實體             | 容易對應實體             |
| memory sharing      | 難實現                   | 容易實現                 |
| memory protection   | 難實現                   | 容易實現                 |
| logical memory 結構 | 與 user 不一致           | 與 user 一致             |
| 位址格式            | 自動拆解成 P、d          | 顯式表示為 S、d          |
| 位址轉換時是否檢查  | 無檢查                   | 需檢查 d < limit         |

### 4.5. Paged Segment Memory Management (分項式分段)

概念：分段 + 分項 = 分段式分項
目的與動機

-   保有 segment-based memory 看起來跟 user 一致
-   同時解決外部碎裂 (external fragmentation)
    在 Logical Memory：
-   看成「網絡」 of segments
-   每個 segment 再分成 pages
    在 Physical Memory
-   看成「集合」 of frames (實際系統元組 pages)
    在 OS Management
-   為每個 process 建 segment table
    -   記錄: limit, page table 位址
-   每 segment 有自己的 page table
    -   記錄此 segment 中各 page 所在的 frame no

優點

-   無 External **Fragmentation**
-   保有 segment-based 看法 與 user 一致
-   可支援 memory sharing, protection

缺點

-   有 Internal Fragmentation
-   table 記錄量大
-   address 轉換過程複雜, access time 較低

![upgit_20250410_1744267557.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250410_1744267557.png)
