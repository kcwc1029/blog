## 1. disk system 組成

| 名稱             | 說明                                                        |
| ---------------- | ----------------------------------------------------------- |
| Disk             | 一片硬碟，通常有兩面（上、下）                              |
| Surface          | 每一面磁碟可儲存資料的區域                                  |
| Track（磁軌）    | 圓形同心圓，每一面有多條                                    |
| Sector（磁區）   | 每條 Track 被切分為多個 Sector（通常為 Block 單位）         |
| Cylinder（柱面） | 同一柱軸下對應多面、同編號 Track 所形成的集合               |
|                  | ➡️ 磁碟讀寫臂只要一次 Seek，就能讀完整個 Cylinder（效能佳） |

### 1.1. 容量計算範例：

假設：

-   有 10 片 Disk（共 20 面，但最上最下不存資料 ➝ 有效面數為 18）
-   每面有 2048 條 Track
-   每條 Track 有 4096 個 Sector
-   每 Sector 容量為 8 KB

```
容量 = 有效面數 × track/面 × sector/track × 每 sector 容量
     = 18 × 2048 × 4096 × 8 KB
     = 18 × 2^11 × 2^12 × 2^13 bytes
     = 18 × 2^36 bytes ≈ 1.15 TB
```

## 2. Disk Access Time（存取時間）

定義：磁碟存取資料所需時間 = Seek Time + Rotational Latency + Transfer Time

### 2.1. Seek Time（尋道時間）

定義：磁頭從目前位置移動至目標 Track 的時間
特性：通常佔整體時間最大（會動機械臂）

### 2.2. Rotational Latency（旋轉延遲）

定義：轉盤旋轉，將欲讀取的 sector 旋轉至磁頭下的時間
平均值：半圈時間（因 sector 平均會落在圓上任一點）

```
公式：
轉速 7200 rpm（每分鐘 7200 轉） → 一圈時間 = 60 / 7200 = 1/120 秒
平均 latency = 1/2 × 1/120 = 1/240 秒 ≈ 4.17ms
```

### 2.3. Transfer Time（資料傳輸時間）

定義：資料從磁碟搬到主記憶體所需的時間
取決於：轉速、每次搬資料大小、磁碟傳輸率

```
給定：
Seek Time = 3ms
轉速 6000 rpm（→ 平均 latency = 5ms）
傳輸速率 = 400 MB/sec
資料大小 = 4 MB
求：讀取時間？

Access Time = Seek + Latency + Transfer
            = 3ms + 5ms + (4MB / 400MB/s)
            = 3ms + 5ms + 0.01s = 13ms
```

Transfer Rate 計算範例

```
假設：
1 Track 有 1024 個 Sector
每 Sector 4 KB
轉速 = 6000 rpm

→ 每圈資料量 = 1024 × 4KB = 4MB
→ 每秒轉速 = 100 圈
→ Transfer Rate = 100 × 4MB = 400 MB/sec
```

## 3. Disk Free Space Management（磁碟空間管理）

目的：管理「哪些 block 是空的」，供檔案系統分配使用。

### 3.1. Bit Vector（BitMap）法

**定義**：每個 Block 對應一個 bit

-   `0` 表示 free
-   `1` 表示 allocated
    範例：`00110000100101`

優點：

-   結構簡單，易於實作
-   容易找連續空 block  
    缺點：
-   適用於小磁碟系統
-   大型磁碟會導致 bitmap 太大，佔用主記憶體，甚至需儲存在磁碟 ➝ 額外 I/O 成本

### 3.2. Link List 法

定義：每個 free block 存放一個 pointer，指向下一個 free block
適用情境：大型磁碟
優點：不需記憶體保存表格
缺點：

-   難以找「連續的」空間
-   每次尋找 free block 需大量磁碟讀取（traverse）

![upgit_20250412_1744440768.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744440768.png)

### 3.3. Grouping 法

![upgit_20250412_1744441069.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744441069.png)

定義：每個 free block 的 pointer 指向下一組 free blocks，同時存一部分 free block 編號
優點：快速找到大量 free blocks，降低 I/O 次數
應用：FAT 分群或 clustering 時常見

---

### 3.4. Counting 法

![upgit_20250412_1744441238.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744441238.png)

定義：在 free block 記錄「從這裡開始，有幾個連續的 free blocks」
優點：

-   適用於 free block 連續的情況
-   結構簡單、搜尋快速

| 方法       | 優點                   | 缺點                   | 適用情況     |
| ---------- | ---------------------- | ---------------------- | ------------ |
| Bit Vector | 容易實作、找連續空間快 | bitmap 可能很大        | 小磁碟       |
| Link List  | 節省主記憶體空間       | 遍歷耗時、難找連續區塊 | 大磁碟       |
| Grouping   | 找大量空間快           | 複雜度稍高             | FAT 系統     |
| Counting   | 找連續空間快、結構簡單 | 無法處理零散空間       | 空間連續情況 |

## 4. File Allocation Methods（檔案配置方法）

目標：如何配置檔案在磁碟中的實體 block，影響效能與管理效率。

### 4.1. Contiguous Allocation（連續配置）

![upgit_20250412_1744441716.png|745x318](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744441716.png)
定義：檔案必須儲存在連續的 blocks 中
目錄記錄：記錄起始位置與長度（start, size）

-   優點：
-   `seek time` 最短（位於同一 Track）
-   支援 `Sequential` 與 `Random Access`  
    缺點：
-   無法動態擴充（須事先知道檔案大小）
-   有 `External Fragmentation` 問題
-   須定期重排磁碟（Compaction）

### 4.2. Linked Allocation（連結配置）

定義：檔案由一串非連續的 blocks 組成，每個 block 含有指向下一個的指標
目錄記錄：記錄起始與結尾 block
優點：

-   無 external fragmentation
-   檔案可彈性擴充（只要還有空 block）
    缺點：
-   無法隨機存取（需逐一走訪）
-   儲存指標空間額外開銷大
-   每次讀取下一塊需磁碟存取指標 ➝ 時間成本高

![upgit_20250412_1744441920.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744441920.png)

### 4.3. FAT Method（File Allocation Table）

![upgit_20250412_1744442161.png|613x261](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744442161.png)

FAT 表存於記憶體，類似 linked allocation，但把鏈結資訊集中儲存在 FAT 表中，而非分散在各 block。
優點：

-   存取較快（表在記憶體中）
-   查詢任一 block 快速（循表查詢）
    缺點：
-   FAT 表太大 ➝ 占記憶體空間
-   非常大的檔案會導致 FAT 鍊很長

### 4.4. Indexed Allocation（索引配置）

定義：每個檔案對應一個 index block，儲存所有使用的 block 編號
目錄記錄：記錄 index block 的 block 編號
優點：

-   支援 `random` 與 `sequential access`
-   無 external fragmentation
-   可延伸檔案大小（只要有 block）
    缺點：
-   index block 額外占空間
-   若檔案太大 ➝ 單一 index block 無法容納

| 方法       | 說明                                    | 優點                                  | 缺點                               |
| ---------- | --------------------------------------- | ------------------------------------- | ---------------------------------- |
| Contiguous | 連續配置：所有 block 必須連在一起       | 快速 seek time，支援順序與隨機存取    | 易產生 external fragmentation      |
| Linked     | 鏈結配置：每個 block 儲存下一個位置指標 | 無 external fragmentation，可彈性延伸 | 存取慢、隨機存取困難、多次 seek    |
| Indexed    | 將所有 block 編號記在 index block       | 支援隨機與順序存取、無碎裂            | index block 佔空間，小檔案浪費嚴重 |

## 5. Index 擴展技術：單一 index block 無法容納所有 block？

解法 01：使用多個 index block，並用 Linking 串接

-   每個 index block 記錄部分 block
-   若空間不夠，再配置新 index block
    解法 02：使用 Multi-level Index Structure（多層次索引）
-   例：Two-level Index
    -   第一層 ➝ 指向第二層索引
    -   第二層 ➝ 指向資料 block
-   可大幅提升可支持檔案大小
    ![upgit_20250412_1744442722.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744442722.png)

## 6. 磁碟排程演算法（Disk Scheduling Algorithms）

### 6.1. FCFS：First-Come, First-Served

定義：依照請求抵達的順序處理磁軌（track）請求。
優點：

-   實作簡單
-   無 starvation（飢餓）問題
    缺點：
-   排程效率差
-   磁頭 seek distance 大，平均 seek time 較長

```
範例：
磁碟有 200 tracks（編號 0-199），磁頭目前在 track 50。
請求序列：`98, 183, 37, 122, 14, 124, 65, 67`
總移動距離：`640` tracks
計算公式：|98-50| + |183-98| + |37-183| + ...
```

### 6.2. SSTF：Shortest Seek Time First

定義：依優先處理離磁頭最近的請求（最短 seek time）。
優點：平均 seek time 較短，效率較高
缺點：可能造成 starvation：遠端請求長時間無法處理

```
範例：
磁碟有 200 tracks（編號 0-199），磁頭目前在 track 50。
請求序列：`98, 183, 37, 122, 14, 124, 65, 67`
執行順序按最近距離排：`50 -> 65 -> 67 -> 37 -> 14 -> 98 -> 122 -> 124 -> 183`
總移動距離：`236` tracks
```

### 6.3. SCAN：Elevator Algorithm

定義：磁頭向某方向移動時，服務該方向所有請求，抵達端點後反轉方向。
優點：

-   整體公平、飢餓風險低
-   排程效率穩定
    缺點：端點無請求也需抵達（造成多餘移動）

```
範例：
磁碟有 200 tracks（編號 0-199），磁頭目前在 track 50。
初始位置 50，往右服務至最右端（199）再折返
總移動距離：`199 - 50 + 199 - 14 = 334 tracks`
```

### 6.4. C-SCAN：Circular SCAN

定義：只在一個方向服務請求，到達尾端後磁頭回到開頭，但不處理回程請求。
優點：

-   平均等待時間穩定、較公平
-   有助於避免 starvation
    缺點：回程未處理請求，略有資源浪費

```
範例：
磁碟有 200 tracks（編號 0-199），磁頭目前在 track 50。
總移動距離略大於 SCAN，但等待時間更均勻
```

### 6.5. OOK / C-LOOK

#### 6.5.1. LOOK：

定義：類似 SCAN，但磁頭只移動到最後一個請求位置，不必到磁碟端點。
優點：節省不必要移動，效率高

#### 6.5.2. C-LOOK：

定義：類似 C-SCAN，但只服務到最後一筆請求後回開頭，無需抵達尾端。
範例：與 LOOK 類似，會在完成後直接跳轉回開頭開始新一輪

| 類型   | 名稱全稱                 | 核心概念與特色                                        |
| ------ | ------------------------ | ----------------------------------------------------- |
| FCFS   | First-Come, First-Served | 依照請求順序處理，簡單但效率低，seek time 不穩定      |
| SSTF   | Shortest Seek Time First | 優先處理距離最近的請求，效率較高但可能造成 starvation |
| SCAN   | Elevator Algorithm       | 磁頭像電梯般來回移動，處理兩側請求，公平性好          |
| C-SCAN | Circular SCAN            | 僅單方向服務請求，回程不服務，平均等待時間穩定        |
| LOOK   | LOOK Algorithm           | 類似 SCAN，但只到最後一個請求後折返                   |
| C-LOOK | Circular LOOK            | 類似 C-SCAN，但只服務至最後請求位置                   |

## 7. RAID (高等節資碼元組碼)

RAID = Redundant Array of Independent Disks
定義：

-   採用多片硬碟組成的數據存取技術
-   提供優化效能、高可靠性與效能層級存取

### 7.1. RAID-0

-   功能：提供 block-level striping
-   無 mirror 與 parity check (無備份與效驗檢查)
-   效能最高，但一片磚損壞即全部損失
-   適用場景：VOD (Video on Demand)、播映類 DB

### 7.2. RAID-1

-   功能：提供 mirror 鏈結
-   元數據是本元數據的複製
-   優點：可靠性高，回復速度快
-   缺點：成本高 (價格加倍)

### 7.3. RAID-2

-   採用 ECC 技術，有 parity check （如 Hamming 碼）
-   每個 bit 分割到不同 disk
-   成本較高，實作不多，很少應用

### 7.4. RAID-3

-   功能：Block-level striping + Dedicated parity disk
-   每次 I/O 必須同時 access all disks
-   適用場景：需要大量連續讀取、傳輸大文件的場景

### 7.5. RAID-4

-   功能：Block-level striping + Parity check
-   與 RAID-3 相似，但各 disk 可獨立操作
-   缺點：獨立 parity disk 成為環境瓜瓶

### 7.6. RAID-5

-   功能：Block-level striping + Distributed parity
-   各 disk 分操不同分區的 parity check
-   常用的一種組態，同時具備效能與可靠性

### 7.7. RAID-6

-   採用顏示 Reed-Solomon 碼 (如 P+Q)
-   可同時 tolerate 2 片 disk 損壞
-   優點：可靠性高
-   缺點：成本高，運算複雜

| RAID 類型 | 備份 | 效能 | 可靠性 | 適用場景           |
| --------- | ---- | ---- | ------ | ------------------ |
| RAID 0    | 無   | 最高 | 最弱   | 流映、體感玩法     |
| RAID 1    | 有   | 中   | 最高   | 關鍵性優先         |
| RAID 5    | 有   | 高   | 高     | 經濟中底           |
| RAID 6    | 有   | 中   | 超高   | 最高安全性         |
| RAID 1+0  | 有   | 高   | 高     | DB、讀寫常勤的系統 |

## 8. Disk Formatting（格式化）

Physical Formatting（低階格式化）

-   將磁碟劃分為磁道與區塊，建立物理結構。
    Logical Formatting（邏輯格式化）
-   建立檔案系統的資料結構，如 FAT、I-Node、空的目錄等。
-   包含：
    -   Partition（分割區）：分出不同用途區段（如：系統分割區、資料分割區），每個分割區可獨立格式化與掛載
    -   Logical format（邏輯結構建立）

## 9. Raw I/O（原始磁碟存取）

將 Disk 當作大型 Array（sector 組成）
不經過檔案系統，就像你直接操作原始資料一樣。
類比：

-   你平常存資料都會經過一個「書櫃系統」（也就是檔案系統），檔案被整理成檔案夾（File）放在書櫃中（Disk）。
-   但 Raw I/O 就像是你不透過書櫃，直接從紙箱裡抓文件——速度快，但你要自己記得文件的位置，沒有分類也沒有檔名。
    優點：
-   很快！沒有檔案系統中繼結構（像 FAT 或 I-Node）干擾。
-   資料寫入直接命中磁碟區塊（Sector）
    缺點：
-   你要自己記得位置與結構（例如第幾個 Sector 是什麼）
-   沒有 File、沒有路徑、沒有檔名 → 很難管理
-   程式需要自己設計邏輯來管理空間（→ 高難度）
    使用情境
-   高效能資料庫（像 Oracle、SQL Server）會選擇使用 Raw I/O 來提升吞吐量。
-   嵌入式系統或儲存裝置測試。

## 10. Bootstrap Loader（開機載入器）

電腦剛開機的時候，什麼都還沒跑，作業系統（OS）也還不在記憶體中。
所以系統會先執行一段特別的程式：Bootstrap Loader，它的任務是：把 OS 的核心（Kernel）從磁碟載入到 RAM 裡，並開始執行 OS。

### 10.1. 傳統做法

Bootstrap 程式直接寫死在 **ROM** 裡面（Read-Only Memory）
缺點：

-   ❌ 不能修改（要改只能換晶片）
-   ❌ 大小有限，功能簡單（只能做很基本的事）

![upgit_20250412_1744446209.png|436x254](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744446209.png)

### 10.2. 現代設計（常見於 BIOS / UEFI）：

| 階段                         | 存放位置               | 內容                          | 備註                                      |
| ---------------------------- | ---------------------- | ----------------------------- | ----------------------------------------- |
| 開機剛開始（BIOS/UEFI 階段） | ROM（主機板上）        | **簡化版 Bootstrap** 程式     | 通常只能做「從磁碟載入東西」的簡單功能    |
| 第二階段                     | Disk（磁碟）Boot Block | **完整版本 Bootstrap Loader** | 包含更多邏輯，如載入 kernel、跳轉控制權等 |
| 真正開始運作時               | RAM（記憶體）          | 從 Disk 載入後放進來執行      | 這時才會啟動 OS 核心（kernel）            |

![upgit_20250412_1744446461.png|529x331](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250412_1744446461.png)
