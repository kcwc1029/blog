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





































