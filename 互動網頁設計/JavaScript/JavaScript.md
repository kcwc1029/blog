- JavaScript是一種應用廣泛的瀏覽器端Script，瀏覽器大多內建JavaScript直譯器。
- JavaScript和HTML、CSS都是網頁設計的核心技術，其中JavaScript用來定義網頁的行為，例如即時更新地圖、輪播圖片等。

## 在HTML中寫js
- 寫在script裡面。
- 一般會建議寫在最後面，尤其是當有大的JavaScript程式時，先讓渲染引擎將網頁顯示出來再載入JavaScript程式，比較不會有畫面延遲的情況。
![upgit_20241024_1729754092.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729754092.png)

## data type
- JavaScript的型別分為基本型別(primitive type)與物件型別(object type)兩種類型。
- 基本型別指的是單純的值(例如數值、字串、布林等)。
- 而物件型別會參照某個資料結構，裡面包含資料和用來操作資料的方法。
- 基本型別：
	- number：採用IEEE754 Double形式，其中包含NaN(非數值)、Infinity、-Infinity。
	- string
	- boolen
	- undefined
	- null
- 物件型別：
	- funtion
	- array
	- object：是一種關聯陣列(associative array)，比較像是python的字典。
## var, let, const
- [JavaScript var let const的区别 - Web前端工程师面试题讲解 (youtube.com)](https://www.youtube.com/watch?v=aqZuCthC5BY)

## 函數
- 使用者自訂函數
```js
// 使用者自訂函數
function showMsg() {
    let userName = prompt("請書入名稱");
    alert(userName + "你好");
}

// 匿名函數
let sum = function (a, b) {
    return a + b;
};

// arrow funtion
let sum = (a, b) => {
    return a + b;
};
```

## 物件導向基本概念：
- 物件 (Object)：可以代表生活中任何物品，包含屬性與方法。例如，汽車是物件，包含品牌與速度等屬性。
- 屬性 (Property)：物件的特徵，例如汽車的顏色、大小。
- 方法 (Method)：物件可以執行的動作，例如發動汽車 (startCar)。
- 事件 (Event)：特定情況下的反應，例如加速事件 (accelerate)。
- 類別 (Class)：定義物件的模板，例如 `Car` 類別下有不同品牌的汽車物件。
![upgit_20241024_1729761090.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729761090.png)

### JavaScript中的三種物件模型：
- ECMAScript物件模型：基本語法與資料型別。
- DOM物件模型：針對 HTML 元素的操作。
- BOM物件模型：瀏覽器相關的物件，例如 `Window`、`Location`。

### 使用實體方式建立物件
```js
// 建立物件
let user = {
    name: "TA",
    age: 24,
    showMsg: () => {
        window.alert("Hi, 我是" + this.name + "!");
    },
};

// 更改物件
user.age = 18;

// 刪除物件
delete user.age;
```
### 使用建構子建立物件
```js
let user = new Object();
user.name = "TA";
user.age = 23;
user.showMsg = () => {
    window.alert("Hi, 我是" + this.name + "!");
};
```

## 內建物件
### number物件
![upgit_20241024_1729768059.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768059.png)

![upgit_20241024_1729768068.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768068.png)

```js
document.write(Number.MAX_VALUE);
document.write("<br>");
document.write(Number.MIN_VALUE);
document.write("<br>");
document.write(Number.NaN);
document.write("<br>");
document.write(Number.NaN);
document.write("<br>");
document.write(Number.isNaN(100));
document.write("<br>");
document.write(Number.isFinite(100));
document.write("<br>");
document.write(Number.isInteger(100));
document.write("<br>");
document.write(Number.parseFloat("1.8x"));
document.write("<br>");
document.write(Number.parseInt("1.8x"));
document.write("<br>");
let x = 123.456;
document.write(x.toExponential());
document.write("<br>");
document.write(x.toFixed(2));
document.write("<br>");
document.write(x.toString());
document.write("<br>");
document.write(x.toPrecision(8));
document.write("<br>");
```
### string物件
![upgit_20241024_1729768723.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768723.png)

### Math物件
![upgit_20241024_1729768754.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768754.png)

![upgit_20241024_1729768766.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768766.png)

![upgit_20241024_1729768776.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768776.png)

![upgit_20241024_1729768783.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768783.png)

![upgit_20241024_1729768794.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768794.png)

### Date物件
![upgit_20241024_1729768822.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768822.png)


### Array物件
![upgit_20241024_1729768863.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768863.png)

![upgit_20241024_1729768872.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768872.png)

![upgit_20241024_1729768879.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768879.png)

![upgit_20241024_1729768890.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729768890.png)

### Error物件
```js
try{
	可能發生例外之敘述
}catch(exceptionVar){
	發生例外要執行的敘述
}finally{
	無論有無發生例外都會執行的敘述
}
```

## 文件物件模型(Document Object Model、DOM)
- DOM 是一種由 W3C 制定的應用程式介面，提供操作 HTML、XML 文件結構的方式。
- DOM 將 HTML 結構轉換為樹狀結構 (DOM 樹)，讓程式可以使用 JavaScript 存取與操作文件中的物件 (如元素、屬性)。
- 每個 HTML 標籤代表一個物件，物件具有屬性、方法和事件，可以用 JavaScript 進行操作與變更。

![upgit_20241024_1729769603.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729769603.png)

![upgit_20241024_1729769629.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729769629.png)

## 取得元素節點
### getElementByld()
- 根據id屬性值取得元素
![upgit_20241024_1729770517.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729770517.png)

![upgit_20241024_1729770540.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729770540.png)

### getElementsByName() 
- 根據name屬性值取得元素：
	- 通常用來取得input、select等表單元素，選擇鈕(radio)、核取方塊(checkbox)或下拉式清單都是有數個選項，而且每個選項的name屬性值均相同，此時取得的就是一群元素，而不是單一元素。
	- NodeList集合常用的成員如下:
		- length:這個屬性表示NodeList集合的元素個數。
		- item(i):這個方法用來取得第i+1個元素，i的值為0~length-1。
![upgit_20241024_1729772057.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729772057.png)

### getElementsByTagName()
- 根據標籤名稱取得元素：
	- length:這個屬性表示NodeList集合的元素個數。
	- item(i):這個方法用來取得第i+1個元素，i的值為0~length-1。
![upgit_20241024_1729772437.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729772437.png)


### getElementsByClassName()
- 根據類別名稱取得元素
![upgit_20241024_1729772559.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241024_1729772559.png)

### querySelector()/querySelectorAll()
- 根據CSS選擇器取得元素/所有元素。
- 較為推薦使用。
![upgit_20241026_1729946978.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241026_1729946978.png)

## 走訪節點
- 也可以先取得DOM樹中的某個節點，然後再透過該節點和下列幾個屬性去走訪其它節點。
- 這些屬性是唯讀的,只能用來取得節點,不能用來變更節點。
- parentNode：目前節點的父節點
- previousSibling：目前節點的前一個兄弟節點。
- nextSibling:：目前節點的後一個兄弟節點。
- childNodes：目前節點的子節點(可能有零個、一個或多個)。
- firstChild：目前節點的第一個子節點。
- lastChild：目前節點的最後一個子節點。
![upgit_20241026_1729947729.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241026_1729947729.png)

## 取得/設定元素的屬性值與文字內容

### 取得屬性值
- hasAttribute()：會檢查參數指定的屬性是否存在。
- getAttribute()：根據參數指定的屬性名稱去取得屬性值。
- setAttribute()：根據參數指定的屬性名稱與屬性根據參數指定的屬性名稱與屬性。如果重複就取代掉。
- removeAttribute()：會移除參數指定的屬性。
### 取得文字內容
- textContent()：用於只需要純文字、不關心樣式的情境。
	- 返回或設置元素內所有的純文字內容，不包含任何 HTML 標籤。
	- 不會顯示被 CSS 樣式設置為 `display: none;` 的隱藏元素內容。
	- 執行效率高於 `innerText`（因為它直接操作 DOM 節點，忽略樣式和渲染）。
```js
let element = document.querySelector(".example");
console.log(element.textContent); // 取得所有純文字
element.textContent = "新文字"; // 設置新的純文字內容
```
- innerText()：用於獲取可見文字，且內容受樣式影響的情境。
	- 返回或設置元素內的純文字內容，但它會受 CSS 樣式影響。
	- 會解析樣式，僅返回可見的文字內容（不包含 `display: none;` 的元素）。
	- 執行效率較低，因為它需要重新渲染和解析樣式。
```js
let element = document.querySelector(".example");
console.log(element.innerText); // 取得可見文字
element.innerText = "新文字"; // 設置新的可見文字
```
- innerHTML()：用於操作帶有 HTML 結構的內容，但要確保內容的安全性。
	- 會解析並返回 HTML 標籤，因此適合操作包含 HTML 的內容。
```js
let element = document.querySelector(".example");
console.log(element.innerHTML); // 取得 HTML 結構和內容
element.innerHTML = "<strong>新內容</strong>"; // 設置新的 HTML 結構
```
## 新增節點
![upgit_20241030_1730276902.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241030_1730276902.png)

## 更新節點
![upgit_20241030_1730277473.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241030_1730277473.png)


## 移除節點
![upgit_20241030_1730277312.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241030_1730277312.png)


## 存取表單內容
### 取得文字欄
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />

        <title>互動網頁設計</title>
    </head>
    <style>
        * {
            box-sizing: border-box;
            padding: 0;
            margin: 0;
        }
    </style>
    <body>
        <form>
            <label for="name">姓名</label>
            <input type="text" id="name" size="20" />
            <br />
            <label for="password">密碼</label>
            <input type="password" id="password" size="20" />
            <br />
            <button type="submit" onclick="showResult()">提交</button>
        </form>
    </body>
    <script>
        function showResult() {
            let name = document.querySelector("#name").value;
            let password = document.querySelector("#password").value;
            document.write(`name: ${name}`);
            document.write(`<br>`);
            document.write(`password: ${password}`);
        }
    </script>
</html>
```

### 取得radiobox的值
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />

        <title>互動網頁設計</title>
    </head>
    <style>
        * {
            box-sizing: border-box;
            padding: 0;
            margin: 0;
        }
    </style>
    <body>
        <form>
            <p>喜歡的甜點</p>
            <input type="radio" name="desert" value="馬卡龍" />馬卡龍
            <input type="radio" name="desert" value="舒芙雷" />舒芙雷
            <input type="radio" name="desert" value="蘋果派" />蘋果派
            <input type="radio" name="desert" value="水果塔" />水果塔
            <button type="submit" onclick="showResult()">submit</button>
        </form>
    </body>
    <script>
        function showResult() {
            event.preventDefault(); // 防止表單提交刷新頁面
            let desert = document.getElementsByName("desert");
            for (let i = 0; i < desert.length; i++) {
                if (desert[i].checked) {
                    console.log(desert[i].value);
                }
            }
        }
    </script>
</html>
```
### 取得checkbox的值
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />

        <title>互動網頁設計</title>
    </head>
    <style>
        * {
            box-sizing: border-box;
            padding: 0;
            margin: 0;
        }
    </style>
    <body>
        <form>
            <p>喜歡的甜點</p>
            <input type="checkbox" name="desert" value="馬卡龍" />馬卡龍
            <input type="checkbox" name="desert" value="舒芙雷" />舒芙雷
            <input type="checkbox" name="desert" value="蘋果派" />蘋果派
            <input type="checkbox" name="desert" value="水果塔" />水果塔
            <button type="submit" onclick="showResult()">submit</button>
        </form>
    </body>
    <script>
        function showResult() {
            event.preventDefault(); // 防止表單提交刷新頁面
            let desert = document.getElementsByName("desert");
            for (let i = 0; i < desert.length; i++) {
                if (desert[i].checked) {
                    console.log(desert[i].value);
                }
            }
        }
    </script>
</html>
```

### 取得selected的值
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />

        <title>互動網頁設計</title>
    </head>
    <style>
        * {
            box-sizing: border-box;
            padding: 0;
            margin: 0;
        }
    </style>
    <body>
        <form>
            <label for="desert">喜歡的甜點(可複選)</label>
            <select name="desert" id="desert" multiple>
                <option value=""></option>
                <option value="馬卡龍">馬卡龍</option>
                <option value="舒芙雷">舒芙雷</option>
                <option value="蘋果派">蘋果派</option>
                <option value="水果塔">水果塔</option>
            </select>

            <button type="submit" onclick="showResult()">submit</button>
        </form>
    </body>
    <script>
        function showResult() {
            event.preventDefault(); // 防止表單提交刷新頁面
            let desert = document.querySelector("#desert");
            for (let i = 0; i < desert.length; i++) {
                if (desert[i].selected) {
                    console.log(desert[i].value);
                }
            }
        }
    </script>
</html>

```
## 操作CSS
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />

        <title>互動網頁設計</title>
    </head>
    <style>
        * {
            box-sizing: border-box;
            padding: 0;
            margin: 0;
        }
    </style>
    <body>
        <h1 id="msg" onmouseover="f1()" onmouseout="f2()">我的夢想就是不上班</h1>
    </body>
    <script>
        function f1() {
            let msg = document.querySelector("#msg");
            msg.style.color = "white";
            msg.style.backgroundColor = "red";
        }

        function f2() {
            let msg = document.querySelector("#msg");
            msg.style.color = "";
            msg.style.backgroundColor = "";
        }
    </script>
</html>
```

## 瀏覽器物件模型(BOM)
![upgit_20241030_1730300810.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241030_1730300810.png)

## window物件
- 代表瀏覽器視窗或標籤頁。
![upgit_20241030_1730300885.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241030_1730300885.png)

![upgit_20241030_1730300907.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241030_1730300907.png)

### 對話確認方塊window.confirm()
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />

        <title>互動網頁設計</title>
    </head>
    <body>
        <form action="#" id="myform">
            <label for="name">姓名：</label>
            <input type="text" id="name" />
            <button type="submit">提交</button>
        </form>
    </body>
    <script>
        let myform = document.querySelector("#myform");
        myform.addEventListener("submit", (e) => {
            if (window.confirm("確定提交表單?")) {
                // 回傳boolean
                e.preventDefault();
            }
        });
    </script>
</html>
```
### 開啟/關閉視窗window.open
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />

        <title>互動網頁設計</title>
    </head>
    <body>
        <a href="javascript: openNewWindow()">開啟新視窗</a>
        <a href="javascript: closeNewWindow()">關閉新視窗</a>
    </body>
    <script>
        function openNewWindow() {
            // 要先建立好，要open的html
            myWin = window.open("index2.html", "myWin", "height=200", "width=400");
        }
        function closeNewWindow() {
            if (myWin) {
                myWin.close();
            }
        }
    </script>
</html>

```

### 使用計時器
#### 週期計算機
- window.setInterval(要值行的函數名稱, 時間)：會回傳計時器的ID。
- window.clearInterval(計時器ID)：用來停止計時器。
#### 單次計算機
- window.setTimeout(要值行的函數名稱, 時間)：會回傳計時器的ID。
- window.clearTimeout(計時器ID)：用來停止計時器。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />

        <title>互動網頁設計</title>
    </head>
    <body>
        <div id="clock"></div>
        <button id="btn">停止線上時鐘</button>
    </body>
    <script>
        let timer = window.setInterval(() => {
            let clock = document.querySelector("#clock");
            clock.textContent = new Date().toLocaleString();
        }, 1000);

        let btn = document.querySelector("#btn");
        btn.addEventListener("click", () => {
            window.clearInterval(timer);
        });
    </script>
</html>

```
## Location物件
- 包含目前開啟網頁的URL相關資訊。
![upgit_20241031_1730367689.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730367689.png)

![upgit_20241031_1730367699.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730367699.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body>
        <a href="javascript: location.reload();">重新載入</a>
        <a href="javascript: location.replace('https://scholar.google.com.tw/');">導向google scholar</a>
        <br />
    </body>
    <script>
        for (let i in window.location) {
            document.write(i + "：" + window.location[i] + "<br>");
        }
    </script>
</html>

```

## Navigator物件
- 包含瀏覽器相關描述與系統資訊。
![upgit_20241031_1730368618.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730368618.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body>
        <a href="javascript: location.reload();">重新載入</a>
        <a href="javascript: location.replace('https://scholar.google.com.tw/');">導向google scholar</a>
        <br />
    </body>
    <script>
        for (let i in window.navigator) {
            document.write(i + "：" + window.navigator[i] + "<br>");
        }
    </script>
</html>
```

## History物件
- 包含瀏覽器的瀏覽歷程紀錄。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body>
        <a href="javascript: history.back();">上一頁</a>
        <a href="javascript: history.forward();">下一頁</a>
        <br />
    </body>
    <script>
        document.write("瀏覽歷程記錄：" + history.length);
    </script>
</html>

```
## Screen物件
- 取得螢幕資訊，並調整網頁內容
![upgit_20241031_1730369514.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730369514.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body></body>
    <script>
        document.write("height 屬性的值為 " + screen.height + "<br>");
        document.write("width 屬性的值為 " + screen.width + "<br>");
        document.write("availHeight 屬性的值為 " + screen.availHeight + "<br>");
        document.write("availWidth 屬性的值為 " + screen.availWidth + "<br>");
        document.write("colorDepth 屬性的值為 " + screen.colorDepth + "<br>");
    </script>
</html>

```
## Document物件
![upgit_20241031_1730369690.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730369690.png)

![upgit_20241031_1730369702.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730369702.png)

![upgit_20241031_1730369747.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730369747.png)

- Document物件集合
![upgit_20241031_1730369962.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730369962.png)


## 事件處理
### 事件驅動(Event Driven)
- Windows 作業系統中的視窗會持續監控使用者的各種事件，如視窗打開、關閉、調整大小、移動、輸入等。系統會根據接收到的事件訊息，將其傳遞給對應的視窗處理。
- 事件觸發：JavaScript 等瀏覽器端 Script 採用事件驅動模式，監控 HTML 文件或 HTML 元素發生的事件，如：
	- load事件：網頁內容載入完成。
	- unload事件：網頁內容卸載。
	- 點擊事件：當使用者在 HTML 元素上點擊時觸發。
- 事件觸發後，事件驅動模式會依次執行事件，讓程式等待執行完成後再處理後續事件。

### 事件類型
#### 使用者介面(UI)事件
- 與使用者界面變動有關的事件。
- `load`：當瀏覽器載入網頁內容完成時觸發。
- `unload`：當瀏覽器卸載網頁內容時觸發。
- `error`：當載入錯誤時觸發。
- `resize`：當視窗大小調整時觸發。
- `scroll`：當視窗或元素被拖動時觸發。
- `DOMContentLoaded`：HTML 文件載入完成時觸發，不包括樣式表或圖片。
- `hashchange`：當 URL 的 hash 值改變時觸發。
- `beforeunload`：當網頁即將卸載時觸發。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body>
        <p>進入網頁時間：<span id="entrytime"></span></p>
    </body>
    <script>
        entrytime = document.querySelector("#entrytime");
        entrytime.textContent = new Date().toLocaleString();
    </script>
</html>
```
#### 鍵盤事件
- 與使用者鍵盤操作有關的事件。
- `keydown`：當按下某個鍵時觸發。
- `keyup`：當釋放某個鍵時觸發。
- `keypress`：當按下或按住鍵時觸發。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body>
        <form action="">
            <label for="achar">請輸入字元</label>
            <input type="text" id="achar" size="10" />
            <br />
            <p id="msg"></p>
        </form>
    </body>
    <script>
        achar = document.querySelector("#achar");
        achar.addEventListener("keydown", (e) => {
            msg = document.querySelector("#msg");
            msg.textContent = "按鍵：" + e.key;
        });
    </script>
</html>
```
#### 滑鼠事件
- 與使用者滑鼠操作有關的事件。
- `click`：當按下滑鼠按鍵並釋放時觸發。
- `dblclick`：當按下兩次滑鼠按鍵時觸發。
- `mousedown`、`mouseup`：當按下或釋放滑鼠按鍵時觸發。
- `mousemove`、`mouseover`、`mouseout`：當滑鼠移動或進出元素時觸發。
- `mousewheel`：當使用者滾動滑鼠滾輪時觸發。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body>
        <img src="./img/角色-吉伊卡哇.png" alt="" id="fig" />
    </body>
    <script>
        fig = document.querySelector("#fig");
        fig.addEventListener("mouseover", (e) => {
            fig.src = "./img/角色-兔兔.png";
        });
        fig.addEventListener("mouseout", (e) => {
            fig.src = "./img/角色-吉伊卡哇.png";
        });
    </script>
</html>
```

#### 表單事件：
- 與表單操作有關的事件。
- `input`：當使用者在 `<input>`、`<select>` 等表單元素中輸入時觸發。
- `change`：當表單元素值變更時觸發。
- `submit`：當提交表單時觸發。
- `reset`：當重設表單時觸發。
- `focus`、`blur`：當元素獲得或失去焦點時觸發。
- `cut`、`copy`、`paste`：當剪切、複製或粘貼內容時觸發。

#### 焦點事件
- 與元素焦點有關的事件。
- `focus`、`focusin`：元素獲取焦點時觸發。
- `blur`、`focusout`：元素失去焦點時觸發。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body>
        <form action="">
            <label for="num">會員編號</label>
            <input type="text" size="20" id="num" />
            <br />
            <p id="msg"></p>
            <button type="submit">提交</button>
        </form>
    </body>
    <script>
        num = document.querySelector("#num");
        msg = document.querySelector("#msg");
        num.addEventListener("focus", () => {
            msg.textContent = "要記得輸入8位";
        });

        num.addEventListener("blur", function () {
            if (this.value.length === 8) {
                msg.textContent = "";
            } else {
                msg.textContent = "我跟你說要輸入8個字";
            }
        });
    </script>
</html>
```

### 定義事件處理/監聽
- 要先確認
	- 由哪個元件觸發
	- 要觸發哪個事件
	- 觸發的事件要繫結哪個處理/監聽事件
#### 第一種方式：利用HTML元素的事件屬性設定
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body>
        <button onclick="f()">顯示訊息</button>
    </body>
    <script>
        function f() {
            window.alert("hello world");
        }
    </script>
</html>
```
#### 第二種方式：DOM Level2事件監聽程式
- 主要就是使用addEventListener()
- 優點是，可以針對同一個物件去設定多個處理程式。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>互動網頁設計</title>
    </head>
    <body>
        <button id="btn">顯示訊息</button>
    </body>
    <script>
        let btn = document.querySelector("#btn");
        btn.addEventListener("click", () => {
            window.alert("hello world01");
        });

        btn.addEventListener("click", () => {
            window.alert("hello world02");
        });

        // 移除監聽
        btn.removeEventListener("click", () => {
            window.alert("hello world02");
        });
    </script>
</html>

```
### Event物件
![upgit_20241031_1730379747.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730379747.png)

![upgit_20241031_1730379759.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241031_1730379759.png)

## 製作javascript lab01












