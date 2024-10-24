- Bootstrap原名Twitter Blueprint,由Twitter的兩位工程師所開發，目的是製作一套可以保持一致性的工具與框架(framework)，後來更名為Bootstrap,並釋出成為開放原始碼專案。
- Bootstrap是目前最受歡迎的HTML、CSS與JavaScript框架之一，用來開發響應式(responsive)、行動優先(mobile first)的網頁，使用者無須撰寫CSS或JavaScript程式碼，就可以設計出響應式網頁。
## 使用Bootstrap套件
### 第一種方式：下載Bootstrap編譯檔案進行使用。
- [Download · Bootstrap v5.3 (getbootstrap.com)](https://getbootstrap.com/docs/5.3/getting-started/download/)下載編譯好的檔案
- 在 HTML 中引入 Bootstrap
```html
<link rel="stylesheet" href="path/to/bootstrap.min.css">

<script src="path/to/bootstrap.bundle.min.js"></script>
```

### 第二種方式：透過CDN(Content Delivery Networks)
- 直接遷入官網提供的CDN
```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Bootstrap demo</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
  </head>
  <body>
    <h1>Hello, world!</h1>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
  </body>
</html>
```

## color
- 【參考】[Color · Bootstrap v5.3 (getbootstrap.com)](https://getbootstrap.com/docs/5.3/customize/color/)
- Bootstrap 提供一個擴展的顏色系統，讓開發者可以自訂樣式和元件。主要的主題顏色包括 **Primary**、**Secondary**、**Success**、**Danger**、**Warning**、**Info**、**Light**、**Dark** 等。
- Bootstrap 也提供像 `.bg-primary` 和 `.text-danger` 讓開發者快速套用背景和文字顏色。

![upgit_20241023_1729685304.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729685304.png)


![upgit_20241023_1729692029.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729692029.png)

![upgit_20241023_1729692042.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729692042.png)


## 斷點(breakpoint)
- 【參考】[Breakpoints · Bootstrap v5.3 (getbootstrap.com)](https://getbootstrap.com/docs/5.3/layout/breakpoints/)
- 斷點的目標是行動優先與響應式設計，使用最少的樣式讓最小斷點能夠運作，然後逐漸調整樣式以適用於較大的裝置。

| 斷點                | 類別前置詞 | 可視區域的寬度  |
| ----------------- | ----- | -------- |
| Extra small       |       | <576px   |
| Small             | sm    | ≥ 576px  |
| Medium            | md    | ≥ 768px  |
| Large             | lg    | ≥ 992px  |
| Extra large       | xl    | ≥ 1200px |
| Extra extra large | xxl   | ≥ 1400px |

## 容器(container)
- 【參考】[Containers · Bootstrap v5.3 (getbootstrap.com)](https://getbootstrap.com/docs/5.3/layout/containers/)
- 是Bootstrap最基本的版面配置元素，可以讓網格系統的列與欄保持適當的邊界和留白。
- `.container`, which sets a `max-width` at each responsive breakpoint
- `.container-{breakpoint}`, which is `width: 100%` until the specified breakpoint
-  `.container-fluid`, which is `width: 100%` at all breakpoints
![upgit_20241024_1729739486.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729739486.png)

## grid
- Bootstrap提供一個網格系統(gird system)，讓使用者藉此開發適應不同裝置的網頁，達到響應式網頁設計的目的。
- Bootstrap網格系統是透過橫向的row(列)和直向的column(行)來設計網頁版面。
- 它將網頁寬度平均分割為12等分，稱為12個column。
![upgit_20241023_1729675830.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729675830.png)

- 假設要使用兩個div元素製作寬度為1:1的雙欄版面，那麼這兩個div元素是位於相同的row，並分別占用6個column。
![upgit_20241023_1729675943.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729675943.png)

- 假設要使用兩個div元素製作寬度為2:1的雙欄版面，那麼這兩個div元素是位於相同的row，並分別占用8個與4個column。
![upgit_20241023_1729675948.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729675948.png)

### 使用原則
- Bootstrap支援數種響應式斷點，斷點是基於媒體查詢的最小寬度，我們可以透過斷點控制容器(container)和行(column)的大小與行為。
- 內容是放在column中，而column則是放在row中。
- 每個row最多包含12個column，超過的會顯示在下一個row。
- 為了有適當的對齊與留白，row必須放在.container、.container-fluid或.container-{breakpoint}類別的容器中。
- 使用.row、.col-* 、.col-sm-* 、.col-md-* 、.col-lg-* 、.col-xl -* 、.col-xxl -* 等預先定義的網格類別來設計版面。

| .col - | .col-sm- | .col-md- | .col-lg- | .col-xl- | .col-xxl- |
| ------ | -------- | -------- | -------- | -------- | --------- |
| 100%   | 540px    | 720px    | 960px    | 1140px   | 1320px    |
- <576px的超小螢幕裝置(例如手機)使用.col-1 ~. col-12類別。
- ≥576px的小螢幕裝置(例如手機)使用.col-sm-1 ~. col-sm-12類別。
- ≥768px的中螢幕裝置(例如平板電腦)使用.col-md-1 ~. col-md-12類別。
- ≥992px的大螢幕裝置(例如桌機)使用.col-lg-1 ~. col-lg-12類別。

- 範例
![upgit_20241023_1729681321.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729681321.png)

![upgit_20241023_1729681349.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729681349.png)
	

## columns
### 欄的水平對其方式
- 我們可以使用.justify-content -* 類別設定欄的水平對齊方式
![upgit_20241023_1729683924.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729683924.png)

![upgit_20241023_1729683938.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729683938.png)


### 列的垂直對其方式
- 我們可以使用.align-items -* 類別設定列的垂直對齊方式。
![upgit_20241023_1729684291.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729684291.png)

![upgit_20241023_1729684306.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729684306.png)


### column位移
- 有時在設計網頁版面時，可能會保留一些空白，不見得12個column都會用到，此時可以使用.offset -* 類別來調整column的位移。
![upgit_20241023_1729684604.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729684604.png)

![upgit_20241023_1729684619.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729684619.png)


### gutters、padding、margine
- Bootstrap 的 **gutters** 是欄位之間的間距，主要透過欄位的水平（`gx-*`）和垂直（`gy-*`）間距進行控制。
- 預設為 1.5rem (24px)，並可依據響應式需求調整。你可以使用 `.g-*` 同時設定水平與垂直的間距。
- 要完全移除 gutters，可以使用 `.g-0`，使欄位無縫對接。


## Image
- 【參考】[Images · Bootstrap v5.3 (getbootstrap.com)](https://getbootstrap.com/docs/5.3/content/images/)
- 響應式圖片(Responsive images)：`class="img-fluid"`，相當於`max-width: 100%; height: auto;`。
- Image thumbnails：相當於給圖片一個1px的邊框。
![upgit_20241023_1729693691.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729693691.png)
- 文繞圖效果
![upgit_20241023_1729693944.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729693944.png)

![upgit_20241023_1729693927.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241023_1729693927.png)

## table
[Tables · Bootstrap v5.3 (getbootstrap.com)](https://getbootstrap.com/docs/5.3/content/tables/)
- 處理表格顏色
```html
<!-- On tables -->
<table class="table-primary">...</table>
<table class="table-secondary">...</table>
<table class="table-success">...</table>
<table class="table-danger">...</table>
<table class="table-warning">...</table>
<table class="table-info">...</table>
<table class="table-light">...</table>
<table class="table-dark">...</table>

<!-- On rows -->
<tr class="table-primary">...</tr>
<tr class="table-secondary">...</tr>
<tr class="table-success">...</tr>
<tr class="table-danger">...</tr>
<tr class="table-warning">...</tr>
<tr class="table-info">...</tr>
<tr class="table-light">...</tr>
<tr class="table-dark">...</tr>

<!-- On cells (`td` or `th`) -->
<tr>
  <td class="table-primary">...</td>
  <td class="table-secondary">...</td>
  <td class="table-success">...</td>
  <td class="table-danger">...</td>
  <td class="table-warning">...</td>
  <td class="table-info">...</td>
  <td class="table-light">...</td>
  <td class="table-dark">...</td>
</tr>
```
- 相間顏色：`.table-striped`



























### 處理prettier
- [導入 Prettier - iT 邦幫忙::一起幫忙解決難題，拯救 IT 人的一天 (ithome.com.tw)](https://ithelp.ithome.com.tw/articles/10205684)
- [如何在 Visual Studio Code 中使用 Prettier (freecodecamp.org)](https://www.freecodecamp.org/chinese/news/how-to-use-prettier-in-visual-studio-code/)




























