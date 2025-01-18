-   Processor（處理器）：
    -   處理器是整個中央處理單元（Central Processing Unit, CPU）的總體設備，負責執行計算機的主要計算任務。它是計算機系統的核心硬體組件
    -   可能包含多個核心（Cores）
    -   其他部件，如快取記憶體、控制單元（CU）、寄存器組等
-   Processor Core（處理器核心）： - 處理器核心是處理器中的一個運算單元，能夠獨立執行指令和處理數據。核心是現代多核心處理器的一個組成部分。

![upgit_20250118_1737198053.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250118_1737198053.png)

## BUG：

-   warning: #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use.
-   FPU 是浮點運算單元，用於加速浮點數的計算。如果 MCU (如 STM32F4) 包含 FPU 並且啟用了支持，則需要在系統啟動時進行初始化。
-   您的編譯器在編譯時啟用了對 FPU 的支持（例如在選項中啟用了 -mfpu=fpv4-sp-d16 和 -mfloat-abi=hard），但是代碼中沒有對 FPU 進行初始化。

![upgit_20250118_1737201619.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250118_1737201619.png)
