## 1. 虛擬機 (Virtual Machine) vs Docker 容器 (Docker Containers)
![upgit_20250302_1740895465.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/03/upgit_20250302_1740895465.png)

### 1.1. 虛擬機 (Virtual Machines, VMs)

-   運作方式

    -   每個應用程式運行在獨立的虛擬作業系統上 (例如 Linux)。
    -   需要完整的 OS，包含 kernel、libraries、tools。
    -   透過 Hypervisor (虛擬機管理程式) 來管理。

-   優點 (Pros)
    -   ✅ 隔離的環境：每個應用程式都有獨立的 OS，避免衝突。
    -   ✅ 可以運行不同 OS：例如 Windows 主機可以運行 Linux VM。
    -   ✅ 環境可重現：可以透過 VM 檔案直接複製到別的電腦上運行。
-   缺點 (Cons)
    -   ❌ 資源消耗大：每個 VM 都需要完整的 OS，佔用大量 CPU、RAM、磁碟空間。
    -   ❌ 啟動速度慢：VM 需要完整啟動 OS，可能需要幾分鐘時間。
    -   ❌ 複製與部署麻煩：要複製 VM 需要大量空間，可能會有相容性問題。

### 1.2. Docker 容器 (Docker Containers)

-   運作方式
    -   共享相同的 OS 核心 (Kernel)，但每個應用程式有自己的環境。
    -   不需要完整的 OS，只包含應用程式和所需的 libraries。
    -   透過 Docker Engine 來管理容器。
-   優點 (Pros)
    -   ✅ 低資源消耗：不需要完整的 OS，佔用更少的 CPU、RAM、磁碟空間。
    -   ✅ 啟動速度快：容器幾乎是即時啟動，通常只需要幾秒鐘。
    -   ✅ 容易共享與部署：可以透過 Docker Hub 或 docker save 來傳輸映像檔，甲方可以快速還原環境。
    -   ✅ 一致的環境：確保開發環境和生產環境一致，避免「我的機器可以跑但你的不行」的問題。
-   缺點 (Cons)
    -   ❌ 不能運行不同 OS：Docker 只能在相同 OS 的 kernel 上運行，不能在 Windows 上直接跑 Linux 容器 (需要 WSL2 或 Hyper-V)。
    -   ❌ 容器內部無法持久存儲資料：如果沒有設定 volume，重啟後資料會遺失。

## 2. Docker 工具與組成

### 2.1. Docker Engine

-   核心引擎，負責管理 Docker 容器
-   負責 建立、運行、管理容器。
-   主要包含 Docker Daemon（後台服務）與 CLI（命令列工具）。
-   負責處理 映像檔（Image）、容器（Container）、網路（Networking）、儲存（Storage）。
-   一般會安裝在伺服器上，如 Linux、Windows、Mac。
-   常用指令

```
docker run hello-world   # 運行一個簡單的測試容器
docker ps                # 檢視運行中的容器
docker stop <container>  # 停止容器
docker rm <container>    # 刪除容器

```

### 2.2. Docker Desktop

-   讓開發者更容易在本機開發與測試 Docker 應用程式。
-   Docker Desktop 是 Windows/Mac 平台的 GUI 版本，內含：
    -   Docker Daemon（Docker 後台服務）
    -   Docker CLI（命令列工具）
    -   Docker Compose（用來管理多個容器的工具）

### 2.3. Docker Hub

-   Docker 官方的雲端映像檔庫
-   你可以將 Docker 映像檔 (Images) 上傳到 Docker Hub，然後其他人可以下載來使用。

```
常用指令
docker pull nginx        # 下載官方的 Nginx 映像檔
docker push myrepo/myapp # 上傳自己的映像檔到 Docker Hub
```

### 2.4. Docker Compose

-   當一個應用程式包含 多個服務（例如 Web + 資料庫），可以用 Docker Compose 一次啟動所有容器。
-   透過 YAML 檔案 (docker-compose.yml) 來定義應用程式的架構。

### 2.5. 驗證安裝

```
docker run hello-world
```
![image](https://dockerbook.tw/d/qr-2-1.gif)
## 3. Docker架構
- 採主從式架構
- 操作以下介面：
	- image：read-only
	- container：基於image建立
	- registry：存放image的空間

### 3.1. Lab：練習使用image【hello-world】：使用run
```
# 確認image【hello-world】是否已存在
docker images hello-world
做了以下事情：
下載image
建立容器（Container）
容器執行完後的行為
```

- 查看所有container：docker ps -a
- 移除container：docker rm <containerID或NAMES>

### 3.2. Lab：練習使用image【busybox】：不使用run

```
# 查看PC是否安裝
docker images busybox

# 下載images
docker pull busybox

# 移除image
docker rmi busybox

# 使用image建立comtainer
docker run -it --name my_busybox busybox

# 執行container
docker start -i my_busybox

# 停止comtainer
docker stop my_busybox

# 移除container
docker rm my_busybox
```
## 4. 使用docker指令建置環境
![upgit_20250302_1740896372.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/03/upgit_20250302_1740896372.png)
- 使用image【httpd】
### 4.1. run完container後移除
```
docker run httpd (如果要自訂名稱 docker run --rm --name web httpd)
docker ps -a
docker rm httpd # 需要自行移除

# 在使用完結束後，會自動刪除container
docker run httpd --rm
```

### 4.2. 背景執行container
- 增加參數：--detach或-d
```
docker run -d httpd
docker ps # 查看container是否運行中
```
### 4.3. 強制移除container
- container要stop才可以移除
- 如果需要強制移除的話：
```
docker rm -f <CONTAINER NAME>
```
### 4.4. Lab：利用docker啟動httpd
```
docker run -d --rm httpd
docker ps
crul http://localhost/ => 會失敗，原因是每一個port都是80
```
```
# 應該要自行預設port
# 使用--publish 或 -p 設定port
docker run -d --rm -p 8080:80 httpd
# 連線到主機的8080port，對接到container的80port
crul http://localhost:8080
```
![upgit_20250302_1740898354.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/03/upgit_20250302_1740898354.png)

### 4.5. Lab：架好server後，要修改裡面檔案
```
docker run -d --rm -p 8080:80 httpd
docker ps
# 使用exec加上shell進入comtainer
docker exec -it <CONTAINER_NAME> bash
# 找出apache回crul的HTML
cat htdocs/index.html
# 使用新內容取代
echo Hello volume > htdocs/index.html
# 離開
exit
# 測試
curl http://localhost:8080
```
- 但如果我這個container刪掉後，東西就沒了
### 4.6. bind mount
- 把host某個檔案(資料夾)綁訂在container的檔案(資料夾) => 使用 -v
- 每次產生新container後，都能在host拿到當下目錄的檔案
```
# 把目前目錄綁定在Apache container的/usr/local/apache2/htdocs 目錄下
docker run -d -it -v `pwd':/usr/local/apache2/htdocs -p 8080:80 httpd

# 測試對應路徑
curl http://localhost:8080/test.html
```



























