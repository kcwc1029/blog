定義：限制所有指令執行時，要在single-cycle內完成
- clock cycle決定在machine內最長執行時間的指令
- 效率不佳(每一個cycle time變很長)
抽象化設計：在設計複雜系統時，先將較低層的細節暫時隱藏，來簡化設計時候的複雜程度
指令集(ISA)
- IS=>9種
	- lw、sw
	- add、sub、and、or、slt
	- beq、jump
- 根據IS的硬體資訊
	- register=>特殊目的(PC)、32一般目的佔存器GPR
	- memory：32bit
	- R/I/J-format
## 1. 基本元件

### 1.1. 暫存器檔案（Register File）
![upgit_20250405_1743837682.png|493x308](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743837682.png)

### 1.2. 算術邏輯單元（ALU）
![upgit_20250405_1743838622.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743838622.png)

### 1.3. 指令記憶體（Instruction Memory）&資料記憶體（Data Memory）

![upgit_20250405_1743839324.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743839324.png)


### 1.4. 加法器（Adder）
常用來：
- PC+4：取得下一個指令位址
- PC + offset：計算跳躍目標

![upgit_20250405_1743839288.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743839288.png)

### 1.5. 有號延伸單元（Sign Extension Unit）

將 16-bit 的立即值延伸為 32-bit。
用於 addi、lw 等指令的立即數。
會根據最高位元做符號延伸（正數補0，負數補1）

![upgit_20250405_1743839371.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743839371.png)

### 1.6. 程式計數器（Program Counter, PC）
儲存目前指令的記憶體位址。
每次指令執行後會遞增（通常為 +4）。
輸出：下一條要取出的指令位址。
![upgit_20250405_1743839394.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743839394.png)

## 2. single cycle 的datapath建構

### 2.1. 指令擷取資料路徑（Instruction Fetch）
指令擷取階段 是處理器執行任何指令的第一個步驟。
執行一條指令前，必須先從記憶體中讀取（fetch）該指令。
擷取的來源是 指令記憶體（Instruction Memory）。
指令記憶體的讀取位置由 程式計數器（Program Counter, PC） 提供。

![upgit_20250405_1743840205.png|651x305](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743840205.png)

### 2.2. R-type 指令資料路徑
R-type 是 MIPS 指令中 最常見的計算型指令。
特性：
-  需要從暫存器中讀取 2 個操作元（source）
- 將 ALU 的運算結果寫回第 3 個暫存器（destination）
```
R[rd] ← R[rs] op R[rt]
```
![upgit_20250405_1743840408.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743840408.png)

### 2.3. Load Word 載入指令資料路徑（lw）
`lw` 是用來從記憶體載入資料到暫存器。
```
R[rt] ← Mem[ R[rs] + SignExt(imm16) ]
```
![upgit_20250405_1743840609.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743840609.png)

### 2.4. Store Word 儲存指令資料路徑（sw）
sw 是用來把暫存器內的資料寫入記憶體。
計算記憶體目的位址，再把資料寫進去。
```
Mem[ R[rs] + SignExt(imm16) ] ← R[rt]
```
![upgit_20250405_1743840961.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743840961.png)


### 2.5. 相等分支指令資料路徑（beq）
beq 指令用來比較兩個暫存器的內容是否「相等」。
若相等，則跳躍（branch）到指定的分支目標位址，否則繼續執行下一條指令。
```
if (R[rs] == R[rt]) → PC ← PC + 4 + SignExt(imm16) << 2
```
![upgit_20250405_1743841378.png|763x530](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743841378.png)

### 2.6. 合併記憶體與 R-type 指令的資料路徑
雖然 R-type 與 記憶體類（load/store）指令 使用不同的操作，但他們使用的硬體單元大致相同。
為了簡化硬體（共用一組 ALU、Register File 等），將兩種資料路徑整合成一個通用資料路徑。

![upgit_20250405_1743841872.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743841872.png)

### 2.7. 合併記憶體指令、R-type 指令、及指令擷取的資料路徑

![upgit_20250405_1743842144.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743842144.png)

## 3. 含控制單元的簡單資料路徑（Single-Cycle Datapath with Control Unit）
![upgit_20250405_1743842388.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743842388.png)


控制單元（Control Unit） 是根據指令的 操作碼（op code），決定整個資料路徑中各個元件的行為。
控制單元會產生多組控制訊號，控制：
- ALU 要做什麼運算？
- 要不要寫暫存器？讀寫記憶體？
- 哪個資料要經由 MUX 輸入？
ALU Control：會根據 ALUOp 和指令的 funct 欄位，決定 ALU 的實際運算
分支（Branch）控制邏輯
- 當遇到 beq 時：
	- ALU 會比較兩個暫存器的值是否相等 → Zero = 1
	- Branch 控制訊號會與 Zero 做 AND
	- 若為 1，就跳到分支目標位址：PC ← PC + 4 + (SignExt(offset) << 2)

### 3.1. MIPS 跳躍指令（Jump）資料路徑
```
JumpAddr = { PC+4[31:28], Instruction[25:0], 00 }
```
組合起來形成最終的 32-bit 跳躍目標地址
- 使用 PC + 4 的高 4 位元（位址區段） 保持目標區塊不變。
- 使用 26-bit 指令欄位 提供較低位址資訊。
- 尾端自動補 00 → 代表位址是「以 4 為單位」（word-aligned）

![upgit_20250405_1743842462.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743842462.png)

## 4. multi cycle
單一時脈（Single-Cycle）問題：
- 每條指令都要在一個 clock cycle 內完成，導致整個時脈週期長度受限於**最慢的指令**。
- 快速指令浪費時間，效率不高。

多重時脈（Multi-Cycle）解法：
- 將指令分成多個步驟（cycle），每一個步驟只執行單一功能。
- 同一組硬體（如 ALU、記憶體）可以被不同指令在不同時段共用。
- 用較短的時脈週期組合完成整體指令，提高整體效率與資源利用率。
定義：每個步驟在執行時，會花掉一個clock cycle=>一個指令花費不同的clock **cycle**

### 4.1. 每個步驟用一個時脈週期（Cycle）

| 步驟  | 功能                                          |     |
| --- | ------------------------------------------- | --- |
| IF  | Instruction Fetch：擷取指令                      |     |
| ID  | Instruction Decode & Register Fetch：解碼+讀暫存器 |     |
| EX  | Execute / Address Calc：執行 ALU 運算、地址計算或分支判斷  |     |
| MEM | Memory Access：存取記憶體（只給 lw / sw 使用）          |     |
| WB  | 將資料寫回暫存器（如 lw 或 R-type）                     |     |

### 4.2. 不同指令類型的執行步驟與 CPI（週期數）
CPI 越小 → 執行越快。跳躍和分支最短，lw 最長。

|Instr.|步驟（五階段）|CPI|
|---|---|---|
|R-type|IF → ID → EX → WB|4|
|lw|IF → ID → EX → MEM → WB|5|
|sw|IF → ID → EX → MEM|4|
|beq|IF → ID → EX|3|
|j|IF → ID|2|



### 4.3. 功能單元使用狀況

|功能單元|使用階段|
|---|---|
|Instruction Memory|IF|
|Register File|ID + WB|
|ALU|EX|
|Data Memory|MEM (lw/sw)|

### 4.4. 資料路徑圖解說明（從圖中理解）
![upgit_20250405_1743843059.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/04/upgit_20250405_1743843059.png)

料路徑與單一時脈基本相同，不同之處在於：
- 加入控制暫存器（如 IF/ID, ID/EX, EX/MEM, MEM/WB）
- 指令分段運行，結果透過 pipeline 暫存器保留到下一周期使用。











