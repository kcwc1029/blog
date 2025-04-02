## 1. Polling I/O（輪詢式 I/O）
![upgit_20250401_1743484649.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250401_1743484649.png)


又稱：Programmed I/O、Busy-waiting I/O
流程步驟：
1. Process 發出 I/O 請求  → 如：Disk Read
2. Process 被 Blocked  → 等待 I/O 完成（此時不能做其他事）
3. OS 接管 CPU 執行 I/O system call  → 進行裝置控制指令（透過 driver）
4. CPU 發送 I/O 指令給 Device Controller
5. Controller 負責裝置的實際操作  → 如磁碟旋轉、資料傳輸等
6. CPU 持續「輪詢」（Polling）
   → 檢查裝置是否完成任務，是否出錯  
   → 完成後才繼續處理下一個工作
特性與問題
- CPU Utilization（使用率）：低(因為 CPU 被綁在等 I/O 上)
- Process Throughput低：多數時間都浪費在 I/O 等待
- 需要反覆查詢裝置是否完成
- 浪費 CPU 資源？=> Busy waiting
- 適用情況：簡單裝置、少量 I/O（不建議用於高效能系統）

【比較】Polling I/O、Interrupt I/O

| 模式       | Polling I/O  | Interrupt I/O |
| -------- | ------------ | ------------- |
| 調查裝置完成狀態 | CPU 主動查詢（持續） | 裝置完成後主動通知 CPU |
| 效率       | ❌ 差          | ✅ 高           |
| 適合場合     | 簡單系統         | 多工、多裝置系統      |

## 2. Interrupt I/O（中斷式 I/O）
![upgit_20250401_1743485362.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250401_1743485362.png)


定義：I/O 裝置在完成任務後，主動發送中斷訊號通知 CPU，不需要 CPU 一直輪詢（Polling）
流程步驟：
1. CPU 執行某個 Process，I/O 裝置獨立執行
2. I/O 操作完成，Device Controller 發出中斷 (Interrupt)
3. OS 收到 Interrupt，暫停當前 process，將其儲存至 Ready Queue
4. 根據 Interrupt Vector 查找對應的 ISR（Interrupt Service Routine） 位置
5. 跳轉到 ISR 執行裝置相關後續處理
6. ISR 結束後，控制權交還給 kernel
7. kernel 根據排程決定繼續哪個 process（可能是原本那個）

優點：
- CPU 不用浪費時間 polling
	- 可將時間集中在 process 執行上
	-  效率更高、CPU utilization 提升
- 提升整體效能（throughput）
- 提升多工能力，系統可同時做更多事（例如邊傳輸邊運算）
缺點：
- 處理 Interrupt 仍會消耗 CPU Time
	- 如 ISR 執行、上下文切換、回復等開銷
	- 若 I/O 操作時間很短，反而用 polling 更划算 => 適合長時間 I/O，如磁碟寫入、大檔案處理
- 高頻率 Interrupt 會拖慢系統效能：若頻率太高會導致 CPU 忙於處理中斷 → utilization 下降
- CPU 還是會耗費時間等待資料傳輸：雖然中斷提醒處理完成，但資料傳送過程仍消耗 CPU time（若沒用 DMA）

【比較】

|技術|說明|
|---|---|
|ISR|Interrupt Service Routine，中斷服務程式|
|Interrupt Vector|儲存中斷類型與 ISR 的對應表|
|DMA（延伸）|Direct Memory Access，可直接讓 I/O 將資料傳到 memory，完全不經 CPU（下一步進化）|
## 3. DMA（Direct Memory Access）

定義：一種資料傳輸機制，由 DMA controller 負責 I/O 裝置與記憶體之間的資料搬移，CPU 不需介入搬運過程。
- 與 CPU 的協作：==DMA controller 使用 interleaving（交錯） 或 cycle stealing（偷取時脈） 技術==
* 在 CPU 不使用 Bus 時插入使用
避免與 CPU 產生總線衝突（Bus Conflict）
DMA 資料搬移流程
1. Device Driver 告知 disk controller 要傳送的資料數量、目標記憶體位置（如 addr X）
2. Device Driver 通知 disk controller 開始傳送資料
3. Disk controller 啟動 DMA 傳輸
4. Disk controller 將資料送至 DMA controller
5. DMA controller 將資料寫入記憶體指定位置
6. 傳輸完成，DMA controller 發出中斷通知 CPU 
優點
- CPU 不需參與資料搬運 → 更多時間執行其他工作
- CPU utilization 更高，系統效能提升
- 適用於：
	- 高速、大量資料的 Block 傳輸
	- 例如：Disk、音訊、影像等大量 I/O
缺點
- DMA Controller 硬體電路設計較複雜
- DMA 仍需使用 memory 與 bus，可能與 CPU 爭用 → Bus 競爭問題
- 若系統中 DMA 發生頻率太高，也可能影響效能（例如多裝置同時 DMA）

### 3.1. 機器指令週期（五階段）

| Stage | 全名                | 說明               | CPU 是否會存取記憶體？ | DMA 是否可用 Memory？ |
| ----- | ----------------- | ---------------- | ------------- | ---------------- |
| IF    | Instruction Fetch | 擷取指令             | ✅ 必須要         | ❌ 衝突 (Conflict)  |
| DE    | Decode            | 解碼，了解指令意義        | ❌ 不用          | ✅ OK             |
| EX    | ALU Execution     | 執行運算             | ❌ 不用          | ✅ OK             |
| FO    | Fetch Operand     | 取資料（可能從記憶體或暫存器）  | ⚠️ 可能會用       | ⚠️ 小心衝突          |
| WM    | Write-back Memory | 將結果寫入記憶體（不一定每次有） | ⚠️ 可能會寫       | ⚠️ 小心衝突          |

結論：  DMA 最好在 CPU 非存取記憶體的階段 動作，否則會發生 Bus 衝突！

### 3.2. CPU與DMA 同時存取memory的優先權調度策略

若 CPU 與 DMA 同時存取 memory，通常採：
- DMA 擁有優先權（preempt CPU）
- 或使用 交錯技術（interleaving） / Cycle Stealing

### 3.3. 一般資源調度原則
重點：資源的使用時間越短、使用頻率越低者優先  
原因：能提升整體排程效率（例：印表機、I/O 裝置）
好處：
- 降低 average waiting time
- 提升 throughput（單位時間完成的工作數）
例如：作業系統的 **SJF（Shortest Job First）** 排程策略

![upgit_20250401_1743487076.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250401_1743487076.png)

## 4. blocking IO vs non-blocking IO

### 4.1. blocking IO
當 process發出請求後，processs就suspended，直到IO動作完成
優點：易用易了解，適合 I/O 操作時間短的應用（如鍵盤輸入）
缺點：效率較低，CPU 被閒置在等待 I/O，不適合高效能需求場景

### 4.2. non-blocking IO
Process 發出 I/O 請求後不會等待，而是繼續執行其他任務。
I/O 操作由系統背景進行，完成後再用中斷（interrupt）或回呼（callback）通知該 process。
優點：系統效率高、CPU 不被浪費，更適合需要同時處理多項任務的應用（如網路伺服器）
缺點：邏輯較複雜，程式碼實作與錯誤處理較難。需要額外設計狀態管理機制。


![upgit_20250401_1743495841.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250401_1743495841.png)

## 5. interrupt

中斷（Interrupt）是一種 CPU 的控制流程中斷與轉移機制，當裝置或系統發生事件時，通知作業系統去處理。

![upgit_20250401_1743495982.png|574x249](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250401_1743495982.png)

每個 Interrupt ID 對應到一個 ISR（Interrupt Service Routine）中斷服務程式的記憶體位置。
Interrupt 有 優先階層（Priority Hierarchy），高優先權會先被處理。
中斷發生後，OS 處理步驟：
- OS 接收到中斷，暫停當前 process 並儲存狀態
- 根據 interrupt ID 查找對應的 ISR 位址（由 interrupt vector 決定）
- 跳轉至 ISR 執行中斷服務程式
- ISR 完成後，return control to kernel
- OS 恢復原本的 process 繼續執行（或 CPU scheduler 換新 process）

### 5.1. 中斷的三大類別

|分類|說明|範例|
|---|---|---|
|**1. External Interrupt**（外部中斷）|來自 CPU 外部，如裝置完成 I/O 時通知 CPU|`I/O complete`、`I/O error`、`machine check`|
|**2. Internal Interrupt（Trap）**|CPU 本身執行指令時發生錯誤|除以 0、非法指令（user 執行特權指令）|
|**3. Software Interrupt**|由 user process 觸發要求 OS 提供服務|系統呼叫如 `I/O request`, `fork`, `exec`|
### 5.2. Interrupt vs Trap 差異比較

|特徵|Interrupt|Trap|
|---|---|---|
|來源|硬體產生（hardware）|軟體產生（software）|
|用途|外部事件通知（如裝置完成）|捕捉錯誤 or 使用者請求系統服務|
|範例|I/O complete, I/O error, timer|divide by zero, system call (如 `fork()`)|

## 6. hardware resources protection

### 6.1. 基礎建設
- Dual Mode Operation（雙模式運作）
- Privileged Instruction（特權指令）

#### 6.1.1. Dual Mode Operation（雙模式運作）

作業系統至少區分兩種運作模式
模式轉換（Mode Switching）：系統會使用一個額外的硬體位元（mode bit）表示目前處於哪一種模式：
- 0：kernel mode
- 1 ：user mode

| 模式                | 說明                                                                                   |
| ----------------- | ------------------------------------------------------------------------------------ |
| Kernel Mode（核心模式） | 代表 OS 或核心層級操作，可執行特權指令、I/O 操作、處理中斷等                                                   |
| User Mode（使用者模式）  | 一般 user process 執行的狀態，不能執行特權指令。  <br>若違規執行 → 發生錯誤、產生 Trap，由 OS 接手處理該 Process（可能強制結束） |

#### 6.1.2. Privileged Instruction（特權指令）

任何可能引發系統重大危害的指令，皆被視為 Privileged Instruction。
只能在 kernel mode 下執行，user mode 下不可執行，否則會產生 Trap，由 OS 處理。

常見的特權指令
- Modify / set the timer 值：CPU 保護，限制執行時間
 - I/O 指令：控制或操作 I/O 裝置（避免 user 任意操作硬體）
- Modify / set Base / Limit register：用於記憶體保護
- Clear Memor：避免任意清除系統資料
- Turn off / disable interrupt：避免中斷被關閉，影響系統回應性
- Change mode → kernel mode：限制進入特權模式

### 6.2. I/O protection
目的：防止 user process 直接執行 I/O 操作
- 避免使用者程式直接操作 I/O devices，導致安全問題或資源混亂
- 降低 user process 控制硬體的複雜度與風險
作法：禁止 user mode 下執行任何 I/O 指令
- 所有 I/O 指令皆被視為特權指令（Privileged Instruction）
- 必須透過 系統呼叫（system call） → 進入 kernel mode → 由 OS 代為操作

![upgit_20250401_1743511583.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250401_1743511583.png)

### 6.3. memory protection
目的：防止 user process 存取非自己範圍的記憶體，例如其他 process 的資料或 kernel 區段，保障作業系統與其他程式的安全性。
作法：Base / Limit 檢查機制：
- 系統會替每個 process 建立一組：
	- Base Register：記錄可用記憶體的起始位置
	- Limit Register：記錄 process 可存取的最大長度
- CPU 每次執行記憶體指令時，都會先比對是否在合法範圍內

![upgit_20250401_1743512893.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250401_1743512893.png)



### 6.4. CPU protection
目的：防止某個 user process 長時間獨占 CPU，導致其他程序無法執行或系統資源被壟斷。
作法：使用 Timer + Time Quantum（時間配額）
- OS 為每個 process 規定一個「最大可使用時間」 ➜ Max Time Quantum
- 當 process 取得 CPU 開始執行時，OS 會設定 timer 初始值為該配額
- 隨著 process 執行，timer 值會遞減
- 若 timer 減至 0：觸發中斷（Timeout Interrupt）=> 通知 OS 由 OS 強制收回 CPU，並切換至下一個排程的 process




