- JavaScript是一種應用廣泛的瀏覽器端Script，瀏覽器大多內建JavaScript直譯器。
- JavaScript和HTML、CSS都是網頁設計的核心技術，其中JavaScript用來定義網頁的行為，例如即時更新地圖、輪播圖片等。
## 基本運作流程
1. 瀏覽器透過作業系統,將網址發送給DNS Server3
2. DNS Server解析網址,將處理的結果組成完整的IP位址並回傳。
3. 瀏覽器知道IP位址後發出網路請求,透過TCP/IP4的通訊協定對 Target Server,也就是網頁所在的伺服器來建立連線。
4. Target Server收到請求後,把所需的資源以封包的形式回應。
5. 解析完封包後,瀏覽器會收到相關的檔案和狀態資訊。
6. 以網頁最常見的資源-HTML和CSS來說,會分別透過各自的Parser建立樹狀結構的資料模型-DOM Tree和CSSOM Tree。
7. 瀏覽器把DOM Tree整理出可見的節點5,並套用對應的CSSOM規則,形成Render Tree的資料結構。
8. 瀏覽器透過Render Tree,計算出每個節點對應到頁面上的實際位置、形狀與大小等資訊,最後輸出一個Layout的資料模型。
9. 瀏覽器透過這個Layout進行最後的繪製動作,渲染在頁面上。
![upgit_20241103_1730615963.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241103_1730615963.png)


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
## 變數與常數
- [JavaScript var let const的区别 - Web前端工程师面试题讲解 (youtube.com)](https://www.youtube.com/watch?v=aqZuCthC5BY)
1. JavaScript引擎解析到等號右邊的資料,也就是test,轉為二進位後新增進記憶體中。
2. JavaScript引擎解析到等號左邊的變數var1,把var1宣告(declare)在記憶體中。
3. 把變數var1指派(assign)到資料test,作為初始值。
![upgit_20241103_1730618059.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241103_1730618059.png)

### 作用域(Scope)
- 全域作用域(Global Scope)：程式碼的任何地方都可以存取跟操作該變數。
- 函式作用域(Function Scope)：
- 區塊作用域(Block Scope)：像是for/while迴圈範圍、if...else條件句範圍。
![upgit_20241103_1730618375.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241103_1730618375.png)

## 函數
![upgit_20241103_1730618563.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241103_1730618563.png)

- 輸入的對應叫做參數(Arguments/Parameters),用途是傳入程序所對應到的「函式」,讓函式對參數進行處理。
- 輸出的對應叫做返回(return),並且有兩種狀態：
	- 有回傳值,表示函式執行完後,會取得結果
	- 另一種則是undefined,簡單來說就是事情做完就結束了。
- 函式就是包覆程序中一連串的動作,可重複性地呼叫(call/invoke)來執行動作內容,來取得輸出或完成目的。
```js
// 函式表達式(Function Expression)
const showMsg = function() {
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

### 閉包(Closure) 和柯里化(Currying)
- 在 JavaScript 中，函式是一級函式，也就是說，函式可以像變數一樣傳遞。由於這個特性，我們可以在函式內部返回另一個函式，並利用閉包保存某些變數的值。
- 假設有一個函式需要多個參數，但其中一些參數經常是固定的（例如 API 的基礎 URL），那麼我們可以將這些固定的參數抽出來，讓整體函式使用上更方便。
```js
let configURL;
configURL = getAPIURL01("https://myapp.com", "user/config");
// 一般函數
function getAPIURL01(base, url) {
	return base + "/" + url;
}


// closure
function getAPIURL02(base) {
	return function (url) {
		return base + "/" + url;
	};
}
let getRemoteAPI = getAPIURL02("https://myapp.com");
configURL = getRemoteAPI("user/config");
```
### 立即執行函式(Immediately Invoked Function,IIFE)
- 定義完立即函式後不用再呼叫,就能馬上執行函式內的運算,有回傳值的話也會立即賦值給指定變數。
- 立即函式的優點：
	- 裡面的變數不會被提升,造成汙染全域的問題。
	- 程式碼只須執行一次來求值的話,也很適合使用。
```js
var myArray = ["Yuri", "Zoe"];
const getResult = (function () {
	var myArray = [1, 2, 3, 4, 5, 6, 7];
	return myArray.join("");
})();

console.log(getResult, myArray); // 1234567 ['Yuri', 'Zoe']
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


## 原型(Prototype)
- 在 JavaScript 中，所有物件都有一個隱藏屬性叫做 `[[Prototype]]`，這個屬性指向另一個物件，我們稱之為「原型」。通過這個機制，一個物件可以「繼承」其原型上的屬性和方法。
### 建構函式
- 在 JavaScript 中，如果你想要創建多個類似的物件，通常會使用「建構函式」(constructor function)。
```js
function Person(attributes) {
    this.name = attributes.name;
    this.age = attributes.age;
}
```
- 當你想要創建一個新物件時，可以使用 `new` 關鍵字，並且呼叫建構函式。
```js
const ta = new Person({
    name: "TA",
    age: 23,
});
console.log(ta); // 輸出 { name: "TA", age: 23 }
```

### `prototype` 屬性
- 如果我們想要讓所有 `Person` 建構函式創建的物件共享一些方法或屬性，可以使用 `prototype` 屬性。所有由 `Person` 創建的物件都會共享這些方法。
```js
Person.prototype.introduce = function() {
    console.log(`Hi, I'm ${this.name} and I'm ${this.age} years old.`);
};

// 所有由 `Person` 建構函式創建的物件都可以使用 `introduce` 方法：
ta.introduce(); // 輸出 "Hi, I'm TA and I'm 23 years old."
```

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
    </head>
    <body></body>
    <script>
        // 建立一個prototype
        function Person(attributes) {
            this.name = attributes.name;
            this.age = attributes.age;
        }

        // 使用 new 關鍵字創建物件
        const Yuri = new Person({
            name: "Yuri",
            age: 23,
        });

        // 擴充 prototype 的屬性
        Person.prototype.legalAge = 18;
        Person.prototype.commuteWay = function () {
            return this.age > this.legalAge ? "開車" : "走路";
        };

        // 確認是否為同一個 prototype
        console.log(Object.getPrototypeOf(Yuri) === Person.prototype); // 應該輸出 true
        console.log(Yuri.commuteWay()); // 應該輸出 "開車" 或 "走路"
    </script>
</html>
```


## 原型鏈 (Prototype Chain)
- 使用 `Object.create()`
```js
// 立一個基礎的物件作為最上層的原型
const baseProto = {
	species: "Human",
	sayHello: function () {
		console.log(`Hello, I'm a ${this.species}`);
	},
};

// 使用 Object.create() 繼承 baseProto
const personProto = Object.create(baseProto);
personProto.name = "Alice";
personProto.introduce = function () {
	console.log(`Hi, my name is ${this.name}`);
};

// 進一步創建新的物件，並讓它繼承 personProto，形成一條更長的原型鏈。
const student = Object.create(personProto);
student.grade = "A";
student.study = function () {
	console.log(`${this.name} is studying.`);
};

// 用 student 來呼叫原型鏈中各層的屬性和方法：
student.name = "Bob"; // 設定 student 的 name 屬性
student.introduce(); // 輸出: Hi, my name is Bob
student.sayHello(); // 輸出: Hello, I'm a Human
student.study(); // 輸出: Bob is studying.
console.log(student.grade); // 輸出: A
```

## this
### 執行環境的生命週期
- 創造階段 (Creation Phase)：
    - 分配記憶體空間給變數和函式。
    - 進行變數提升 (Hoisting)。
    - 建立執行環境所需的資料結構。
    - 將函式放入呼叫堆疊 (Call Stack)，等待執行。
- 執行階段 (Execution Phase)：
    - 逐行執行程式碼。
    - 透過 `this` 和作用域鏈，存取所需的變數和函式。
    - 當函式執行完成或遇到 `return`，從堆疊中移除執行環境。

### 執行環境的分類
1. 全域執行環境 (Global Execution Context)：
    - 在程式啟動時首先建立的執行環境。
    - 負責管理全域變數和函式，並將 `this` 綁定到全域物件（瀏覽器中是 `window`，Node.js 中是 `global`）。
    - 當程式中呼叫函式時，會建立新的執行環境並放入呼叫堆疊中。
2. 函式/局部執行環境 (Function/Local Execution Context)：
    - 每當呼叫一個函式時，會為該函式建立一個新的執行環境。
    - `this` 的指向會根據呼叫方式而定，不像全域環境中那樣固定。
```js
const callJoe = () => {
	console.log("hello, i am joe");
};

const callDava = () => {
	callJoe();
	console.log("hello, i am Dave");
};
console.log("hello global");
callDava();
console.log("godbye scope");

// hello global
// hello, i am joe
// hello, i am Dave
// godbye scope
```

- this是透過物建中的建構子產生，this會指向建構子。
- 當要存取或執行自己的成員時,就可以透過this來進行。
```js
class Book {
	constructor(name) {
		// 建構子
		this.name = name;
	}
	getName() {
		return "書名" + this.name;
	}
}

let mtBook = new Book("小王子");
console.log(mtBook.getName()); // 書名小王子
```

- 不過在JavaScript中,this關鍵字會隨著執行環境、特殊的語法、函式呼叫的方式等會有變動。
- 這種動態決定函式執行環境中this對象,我們通常叫做「綁定」(binding)。

### 預設綁定(Default binding)
- 在全域宣告的函式,this會預設指向全域物件(可能是瀏覽器中的window,或是Node.js中的global)。
```js
function getThis1() {
	console.log("[全域] 函式陳述式 this 指向:", this);
}

const getThis2 = function () {
	console.log("[全域] 函式表達式 this 指向:", this);
};

const getThis3 = () => console.log("[全域] 箭頭函式 this 指向:", this);

getThis1(); // [全域] 函式陳述式 this 指向: Window
getThis2(); // [全域] 函式表達式 this 指向: Window
getThis3(); // [全域] 箭頭函式 this 指向: Window
```

### 隱式綁定(Implicit binding)
- 物件中如果有方法實作，當呼叫方法時,this會指向物件本身。
- 箭頭函式有自己一套的綁定規則,並不符合隱式綁定。
- 箭頭函式的this對象，主要是看上一層的作用域指向的this對象。
```js
function getThis1() {
	console.log("[全域] 函式陳述式 this 指向:", this);
}

const getThis2 = function () {
	console.log("[全域] 函式表達式 this 指向:", this);
};

const getThis3 = () => console.log("[全域] 箭頭函式 this 指向:", this);

getThis1(); // [全域] 函式陳述式 this 指向: Window
getThis2(); // [全域] 函式表達式 this 指向: Window
getThis3(); // [全域] 箭頭函式 this 指向: Window
```
### 隱式綁定(Implicit binding)
```js
const book = {
	name: "小王子",
	getThis1: function () {
		console.log("[物件] inline函式 this:", this);
	},
};

book.getThis1(); // [物件] inline函式 this: {name: '小王子' ...}
```

### 顯式綁定(Explicit binding)

#### 綁定函數(bind function)
- 在 JavaScript 中，當我們希望函式的 `this` 值被綁定到特定對象，或者想在呼叫函式時自動傳入一些固定的參數。
- `bind` 可以讓你創建一個新的函式，這個函式的 `this` 值被綁定到特定對象，並且可以預設某些參數。
- `function.bind(thisValue, arg1, arg2, ..., argN);` 
	- thisValue：要綁定的 `this` 對象，必須指定。
	- arg1, arg2, ..., argN：可選的參數列表
```js
const my0bject = {
	x: 10,
	addX: function (valuel, value2) {
		return value1 + value2 + this.x;
	},
};

//透過 bind 建立新的函式
const addXFunction = my0bject.addX.bind({ x: 3 }, 1, 2);

console.log(myObject.addX(1, 2)); // 13 ( this fld my0bject )
console.log(addXFunction()); // 6 ( this #/ { x: 3} )
```

#### 呼叫函數(call function)
- `call` 是 JavaScript 中的一個函式方法，用於改變函式內部的 `this` 指向，並立即執行該函式。
- 與 `bind` 不同的是，`call` 不會返回一個新的函式，而是直接執行。
```js
const myObject = {
	x: 10,
	addX: function (value1, value2) {
		return value1 + value2 + this.x;
	},
};

// 使用原始函式
const result01 = myObject.addX(1, 2);
console.log(result01); // 應輸出：13 (1 + 2 + 10)

// 透過 call 修改 this 指向並執行函式
const result02 = myObject.addX.call({ x: 3 }, 1, 2);
console.log(result02); // 應輸出：6 (1 + 2 + 3)
```

#### 呼叫函數(apply function)
- 跟call依樣，差別是後面的參數要放到陣列裡。
```js
const myObject = {
	x: 10,
	addX: function (value1, value2) {
		return value1 + value2 + this.x;
	},
};

// 使用原始函式
const result01 = myObject.addX(1, 2);
console.log(result01); // 應輸出：13 (1 + 2 + 10)

// 透過 call 修改 this 指向並執行函式
const result02 = myObject.addX.apply({ x: 3 }, [1, 2]);
console.log(result02); // 應輸出：6 (1 + 2 + 3)
```

## 模組(module) -- ES Module(MSM)
![upgit_20241103_1730625196.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241103_1730625196.png)

### 匯出
```js
let maginNum = 1000;
const printMsg = function (msg) {
    console.log("ESM example", msg);
};

class Robot {}

// ESM匯出
export { maginNum, printMsg, Robot };

// 也可以使用as
// export { maginNum as mg, printMsg, Robot };
```

### 匯入
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
    </head>
    <body></body>
    <script type="module">
        import { maginNum, printMsg, Robot } from "./js/index.js";
        // import * as Mymodule from "./js/index.js"; // 為模組命名
        console.log(printMsg(maginNum));
    </script>
</html>
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



## 陣列(array)
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- <link rel="stylesheet" href="style.css" /> -->
    </head>
    <body></body>
    <script>
        let arr = ["A", "B", "C", "D", "E", "F"];
        let temp = ["G", "H", "I", "J", "K", "L"];
        console.log(arr.slice(2));
        console.log(arr.slice(2, 4));
        console.log(arr.slice(-1));
        console.log(...arr); // 解包

        // TODO: reverse
        console.log(arr.reverse()); // 解包

        // TODO: concat
        console.log(arr.concat(temp));
        console.log([...arr, ...temp]);

        // TODO: join
        console.log(arr.join("-"));
    </script>
</html>
```

- 基本操作
```js
// 宣告陣列
let arr1 = [1, 2, 3];
console.log(arr1);

// 取值
let temp = arr1[0];
console.log(temp);

// 查詢
let man = { name: "joe" };
let arr2 = ["yuri", man, 23];
console.log(arr2.indexOf(23));

// 是否含有該元素
// includes(target, position)
console.log(arr2.includes("yuri"));
console.log(arr2.includes("yuri", 2));

// 檢查每個元素(條件為AND)
// every(executor, thisValue)
let arr3 = [3, 12, 24, 72];
console.log(
    "every(executor, thisValue)",
    arr3.every((value) => {
        return value % 2 === 0; // 加上 return
    })
);

// 檢查每個元素(條件為OR)
// some(executor, thisValue)
console.log(
    "some(executor, thisValue)",
    arr3.some((value) => {
        return value % 2 === 0; // 加上 return
    })
);

// find：尋找第一個符合元素(沒有回傳undefined)
const inventories = [
    { name: "apples", quantity: 2 },
    { name: "bananas", quantity: 3 },
    { name: "cherries", quantity: 5 },
    { name: "tomatoes", quantity: 3 },
];

console.log(
    inventories.find((inventories) => {
        return (inventories.quantity = 3);
    })
);

// findIndex：跟find依樣，但是回傳index
console.log(
    inventories.findIndex((inventories) => {
        return (inventories.quantity = 3);
    })
);

// filter：尋找所有符合元素(沒有回傳undefined)
console.log(
    inventories.filter((inventories) => {
        return (inventories.quantity = 3);
    })
);

// 移除最後一個元素
let arr4 = [1, 2, 3];
console.log(arr4.pop(), arr4);
arr4.push(4);
console.log(arr4);

// 切片
console.log(arr4.slice(1, 3));

// 取代
console.log(arr4.length);
arr4.fill("AAA", 0, 2); // 取代index=0, 1
console.log(arr4);

// 反轉
console.log(arr4.reverse());

// 合併
console.log(arr4.concat(arr1));

// 元素合併
console.log(arr4.join(""));

// 遍歷
const candidates = [
    { name: "Ann", seniority: 8, englishNative: false },
    { name: "Bob", seniority: 5, englishNative: false },
    { name: "Joe", seniority: 7, englishNative: true },
];

let score = candidates.map((value, index) => {
    let temp = value.englishNative ? -10 : 10;
    return value.seniority * 10 + temp;
});
console.log(score);

// reduce 方法是 JavaScript 中用來對陣列的每一個元素進行累加或聚合操作的一種方法。
// 通常用於將陣列縮減為單一的值，像是計算總和、統計數據等。
const numbers = [1, 2, 3, 4];

const sum = numbers.reduce((accumulator, currentValue) => {
    return accumulator + currentValue;
}, 0);

console.log(sum); // 輸出: 10

// keys()、values()、entries() ->返回是一個跌帶物件
let arr5 = ["a", "b", "c"];
const keyIterator = arr5.keys();
const valIterator = arr5.values();
const entIterator = arr5.entries();
for (i of keyIterator) {
    console.log(i);
}
```

- 陣列的解構賦值
```js
// 陣列的解構賦值
let [name1, name2, name3] = ["Yuri", "Zoe", "Bob"];
console.log(name1, name2, name3); // Yuri Zoe Bob

[name1, name2, ...otherNames] = ["Yuri", "Zoe", "Bob", "Sam", "Ann", "Joe"];
console.log(name1, name2, otherNames); // Yuri Zoe ['Bob', 'Sam', 'Ann', 'Joe']
```

## set跟weakset
- 建立物件型別的變數時,記憶體會先配置空間給這份資料，變數本身則是以「參考」的形式指到資料。
- 強參考(Strong Reference)：因此只要這份資料有被一個以上的變數參考,就會留存在記憶體中。
- 弱參考(Weak Reference)：就算這份資料有被參考到,但是在程式操作後仍然可以被清理,釋放出記憶體空間
- weakset：
	- 只接受物件型別的資料型態作為元素值
	- 元素會以弱參考的方式參考到資料本身。因此當資料在記憶體中被回收時，對應的元素參考也會跟著被移除。
	- 對於要存取DOM元素，使用weakSet，在記憶體上會比較理想。
```js
// 建立容器
let set01 = new Set([1, 2, 3]);
// WeakSet 只能儲存物件，不能儲存基本資料類型（如 number、string 等）
let weakset01 = new WeakSet([{ id: 1 }, { id: 2 }, { id: 3 }]);

// 查看元素個數
console.log(set01.size);

set01.add(4); // 增加
set01.delete(4); // 刪除
console.log(set01.has(2)); // 檢查

const entries = set01.entries(); // 使用正確的變數名稱 set01
for (let [key, value] of entries) {
    console.log(key, value); // 因為在 Set 中，key 和 value 是相同的
}
// 清空
set01.clear();
```
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
- [blog/互動網頁設計/JavaScript/javascript_demo_guess_number at main · kcwc1029/blog (github.com)](https://github.com/kcwc1029/blog/tree/main/%E4%BA%92%E5%8B%95%E7%B6%B2%E9%A0%81%E8%A8%AD%E8%A8%88/JavaScript/javascript_demo_guess_number)
## 製作javascript lab02
- [blog/互動網頁設計/JavaScript/javascript_demo_pig_game at main · kcwc1029/blog (github.com)](https://github.com/kcwc1029/blog/tree/main/%E4%BA%92%E5%8B%95%E7%B6%B2%E9%A0%81%E8%A8%AD%E8%A8%88/JavaScript/javascript_demo_pig_game)


## 類別(class)
- `class` 是 ES6 (ECMAScript 2015) 引入的語法糖，主要用來讓 JavaScript 的物件導向寫法更接近其他傳統 OOP 語言 (例如 Java、C++)
- `class` 背後其實還是基於 prototype-based inheritance (原型繼承) 的機制。所以在底層上，`class` 實際上是透過 prototype 的方式來實現物件導向。
```js
class Product {
    constructor(name, price, PIN) {
        this.name = name;
        this.price = price;
        this.__PIN = PIN; // 私有屬性
    }

    displayProduct() {
        console.log(`name: ${this.name}`);
        console.log(`price: ${this.price}`);
    }

    // 靜態方法
    static printInfo() {
        console.log("把你阿罵賣掉");
    }

    // 透過method取出私有屬性
    
}

Product.printInfo(); // 靜態方法

const product01 = new Product("TA01", 78);
const product02 = new Product("TA02", 87);
product02.displayProduct();
```

## 回調函數(callback)
- 中心思想：一個很大的Process，他會需要一段時間。
- 因為所有的網路請求都可能會造成阻塞JS執行，導致後續任務無法被快速處裡。
- 同步執行(Synchronous execution)：
- 異步執行(Asynchronous execution)：
```js
// 一開始先輸出1，延遲3秒在打印2，然後駔後打印3
console.log(1);

// setTimeout就是一個callback function
setTimeout(() => {
    console.log(2);
}, 3000);

console.log(3);
```

## Promise
- 為了處理caallback hell
```js
// 先準備食材，花費 2 秒。
// 加熱鍋具，花費 1 秒。
// 加入食材並開始烹煮，花費 3 秒。
// 最後調味，花費 1 秒。
console.log("開始準備流程...");

// 模擬第一步驟：先準備食材（2秒）
setTimeout(() => {
    console.log("步驟 1：準備食材完成");

    // 模擬第二步驟：加熱鍋具（1秒）
    setTimeout(() => {
        console.log("步驟 2：加熱鍋具完成");

        // 模擬第三步驟：加入食材並開始烹煮（3秒）
        setTimeout(() => {
            console.log("步驟 3：加入食材並烹煮完成");

            // 模擬第四步驟：進行最後調味（1秒）
            setTimeout(() => {
                console.log("步驟 4：調味完成，準備上菜");

                // 最後步驟：上菜完成
                console.log("所有步驟完成，上菜！");
            }, 1000);
        }, 3000);
    }, 1000);
}, 2000);
```
- promise(承諾)：就像我們在現實中承諾對方做一件事
	- 待定(pending)
	- 履行(resolve)
	- 不履行(reject)

![upgit_20241104_1730691126.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241104_1730691126.png)

```js
// 將callback hell改成promise
function prepareIngredients() {
    return new Promise((resolve) => {
        setTimeout(() => {
            console.log("步驟 1：準備食材完成");
            resolve();
        }, 2000);
    });
}

function heatPan() {
    return new Promise((resolve) => {
        setTimeout(() => {
            console.log("步驟 2：加熱鍋具完成");
            resolve();
        }, 1000);
    });
}

function cookIngredients() {
    return new Promise((resolve) => {
        setTimeout(() => {
            console.log("步驟 3：加入食材並烹煮完成");
            resolve();
        }, 3000);
    });
}

function addSeasoning() {
    return new Promise((resolve) => {
        setTimeout(() => {
            console.log("步驟 4：調味完成，準備上菜");
            resolve();
        }, 1000);
    });
}

// 執行流程
console.log("開始準備流程...");

prepareIngredients()
    .then(() => heatPan())
    .then(() => cookIngredients())
    .then(() => addSeasoning())
    .then(() => {
        console.log("所有步驟完成，上菜！");
    })
    .catch((error) => console.error("發生錯誤:", error));
```

```js
// 展示resolve、reject跟finally的用法
function getEven() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            const n = Math.floor(Math.random() * 100);
            console.log("生成的數字:", n);
            if (n % 2 === 0) {
                console.log("resolve:", n);
                resolve(n); // 偶數時 resolve
            } else {
                console.log("reject:", n);
                reject("生成的數字不是偶數"); // 奇數時 reject
            }
        }, 1000);
    });
}
getEven()
    .then((result) => {
        result = result + 10; // 計算並返回新結果
        console.log("then 第一環節", result);
        return result; // 返回新的結果，讓下一個 .then 繼續接收
    })
    .then((result) => {
        result = result / 2; // 計算並返回新結果
        console.log("then 第二環節", result);
        return result; // 返回新的結果
    })
    .then((result) => console.log("then:", result))
    .catch((error) => console.error("error:", error))
    .finally(() => console.log("執行結束~~"));
```

## 非同步：async與await
- 將Promise納入標準後,解決了以往寫非同步時容易產生的回呼地獄。
- 不過如果有多個非同步,或是有複雜的判斷邏輯時,Promise的寫法還是會讓程式產生巢狀結構,語意上也不好解讀。
- 所以async與await主要是用來簡化 `.then` 的語法，使非同步程式碼更易讀，更接近同步風格(可以避免過多的 `.then` 嵌套)。
```js
// 基本格式

// 模擬一個返回 Promise 的非同步函數
function fetchData() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve("資料獲取成功");
        }, 1000);
    });
}

// 使用 async/await
async function getData() {
    try {
        const result = await fetchData(); // 等待 Promise 完成
        console.log(result); // 輸出: 資料獲取成功
    } catch (error) {
        console.error("發生錯誤:", error);
    }
}

getData();
```

```js
function prepareIngredients() {
    return new Promise((resolve) => {
        setTimeout(() => {
            console.log("步驟 1：準備食材完成");
            resolve();
        }, 2000);
    });
}

function heatPan() {
    return new Promise((resolve) => {
        setTimeout(() => {
            console.log("步驟 2：加熱鍋具完成");
            resolve();
        }, 1000);
    });
}

function cookIngredients() {
    return new Promise((resolve) => {
        setTimeout(() => {
            console.log("步驟 3：加入食材並烹煮完成");
            resolve();
        }, 3000);
    });
}

function addSeasoning() {
    return new Promise((resolve) => {
        setTimeout(() => {
            console.log("步驟 4：調味完成，準備上菜");
            resolve();
        }, 1000);
    });
}

// 使用 async/await 實現執行流程
async function cookProcess() {
    console.log("開始準備流程...");

    try {
        await prepareIngredients();
        await heatPan();
        await cookIngredients();
        await addSeasoning();
        console.log("所有步驟完成，上菜！");
    } catch (error) {
        console.error("發生錯誤:", error);
    }
}

// 執行流程
cookProcess();
```

## 產生器
產生器是一種特殊的函數，可以暫停其執行並在需要時恢復。產生器函數會返回一個**迭代器物件**，每次執行產生器函數的 `next()` 方法時，就會暫停在 `yield` 關鍵字上，並返回 `yield` 後的值。

## 高階知識點

產生器 (Generator)
Symbol 與符號 (Symbol)
Proxy
Reflect
WeakRef 與 FinalizationRegistry
Intl (國際化)

## JS建議的學習順序總結：
- **Three.js** - 入門 3D 圖形概念。
- **Babylon.js** - 進階 3D 開發和遊戲應用。
- **D3.js** - 資料視覺化，學會展示數據。
- **TensorFlow.js** - 機器學習應用，增強智能。
- **PixiJS** - 專注於高效的 2D 圖形渲染和動畫。




![upgit_20241102_1730513872.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241102_1730513872.png)




