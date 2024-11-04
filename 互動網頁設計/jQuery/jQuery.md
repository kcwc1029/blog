- [jQuery](https://jquery.com/)

## 使用方式
- 方式1：下載套件
![upgit_20241102_1730514005.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241102_1730514005.png)

- 方式2：使用CDN
	- [jQuery CDN](https://releases.jquery.com/)
![upgit_20241102_1730514145.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241102_1730514145.png)


## 第一個jQuery
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
    </head>
    <body></body>
    <script
        src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
        integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
        crossorigin="anonymous"
    ></script>
    <script>
        $(document).ready(function () {
            window.alert("hello jquery");
        });
    </script>
</html>

```

## jQuery核心
```
$(選擇器).method(參數)
```
### 基本選擇器
- 通配選擇器：`$("*")` – 選擇所有元素。
- 類型選擇器：`$("h1")` – 選擇 `<h1>` 元素。
- ID 選擇器：`$("#id")` – 選擇 `id` 屬性為指定值的元素。
- 類別選擇器：`$(".class")` – 選擇 `class` 屬性為指定值的元素。

### 結構選擇器
- 子選擇器：`$("ul li")` – 選擇 `<ul>` 的直接子元素 `<li>`。
- 後代選擇器：`$("p a")` – 選擇 `<p>` 元素的所有後代 `<a>`。
- 相鄰兄弟選擇器：`$("img + p")` – 選擇緊接在 `<img>` 之後的 `<p>`。
- 全部兄弟選擇器：`$("img ~ p")` – 選擇所有位於 `<img>` 後的兄弟 `<p>` 元素。

### 屬性選擇器
- 基本屬性選擇器：`$("[attr]")` – 選擇有 `attr` 屬性的元素。
- 特定值屬性選擇器：`$("[class='apple']")` – 選擇 `class` 屬性值為 `apple` 的元素。
- 部分匹配屬性選擇器：
  - 包含字串：`$("[class*='apple']")` – 選擇 `class` 屬性包含 `apple` 的元素。
  - 前綴匹配：`$("[class^='apple']")` – 選擇 `class` 屬性以 `apple` 開頭的元素。
  - 後綴匹配：`$("[class$='apple']")` – 選擇 `class` 屬性以 `apple` 結尾的元素。

### 表單選擇器
- 基本表單元素：
  - `$("input")` – 選擇所有 `<input>` 元素。
  - `$("input:radio")` – 選擇所有類型為 `radio` 的 `<input>`。
  - `$("input:checkbox")` – 選擇所有類型為 `checkbox` 的 `<input>`。
- 其他表單元素：
  - `:text` – 選擇類型為 `text` 的 `<input>`。
  - `:password` – 選擇類型為 `password` 的 `<input>`。
  - `:submit` – 選擇類型為 `submit` 的 `<input>`。
  - `:selected` – 選擇下拉清單中被選取的項目。

### 狀態選擇器
- 啟用或禁用：
  - `:enabled` – 選擇所有啟用的 `<input>`。
  - `:disabled` – 選擇所有禁用的 `<input>`。
- 選取或未選取：
  - `:checked` – 選擇所有被選取的 `<input>`（例如 `checkbox` 或 `radio`）。
  - `:not(:checked)` – 選擇所有尚未選取的 `<input>`。

### 其他虛擬選擇器
- 索引選擇器：
  - `:first` – 選擇第一個元素。
  - `:last` – 選擇最後一個元素。
  - `:eq(index)` – 選擇指定索引的元素。
  - `:gt(index)` – 選擇索引值大於 `index` 的元素。
  - `:lt(index)` – 選擇索引值小於 `index` 的元素。
- 奇偶選擇器：
  - `:odd` – 選擇索引值為奇數的元素。
  - `:even` – 選擇索引值為偶數的元素。
- 其他：
  - `:contains(text)` – 選擇包含指定文字的元素。
  - `:has(selector)` – 選擇包含指定選擇器的元素。
  - `:empty` – 選擇所有沒有子元素的元素。
  - `:parent` – 選擇所有有子元素的元素。
  - `:hidden` – 選擇所有隱藏的元素。
  - `:visible` – 選擇所有可見的元素。



### 存取元素方法
- text()：取出元素內容
![upgit_20241102_1730516201.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241102_1730516201.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <button id="btn">顯示訊息</button>
        <p id="msg"></p>
    </body>
    <script>
        // 按下後顯示訊息
        let item = $("#btn").on("click", () => {
            $("#msg").text("Hello jQuery"); // 更改標籤內容
        });
    </script>
</html>
```
- html()：取出元素內容(含標籤)
```html
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1.0" />
		<title>Document</title>
		<!-- jQuery -->
		<script
			src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
			integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
			crossorigin="anonymous"
></script>
	</head>
	<body>
		<ul>
			<li>item01</li>
			<li>item02</li>
			<li>item03</li>
		</ul>
	</body>
	<script>
		let items = $("li:first").html();
		console.log(items);
		// <li>item01</li>
		// <li>item02</li>
		// <li>item03</li>
		items = $("li:first").html("<p>使用html()修改標籤</p>");
	</script>
</html>
```
- val()：選取值
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <select name="" id="book">
            <option value="01" selected>item01</option>
            <option value="02">item02</option>
            <option value="03">item03</option>
            <option value="04">item04</option>
        </select>
    </body>
    <script>
        let items = $("#book").val();
        let name = $("#book option:selected").text();
        console.log(items);
        console.log(name);
    </script>
</html>

```
- attr()：存取屬性
- removeAttr()：刪除屬性
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <a href="https://www.youtube.com/">YT</a>
    </body>
    <script>
        let href = $("a").attr("href");
        console.log(href); // https://www.youtube.com/

        // 更改屬性
        $("a").attr("href", "https://chatgpt.com/");

        // 更改1個以上屬性
        $("a").attr({
            href: "https://chatgpt.com/",
            target: "_blank",
            title: "Visit ChatGPT's official site",
        });

        // 刪除屬性
        $("a").removeAttr("title");
    </script>
</html>
```

- addClass()
- removeClass()
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <a href="https://www.youtube.com/">YT</a>
    </body>
    <script>
        let href = $("a");
        href.addClass("c1 c2");
        href.removeClass("c1");
    </script>
</html>
```

- append()：將參數所指定的元素加到符合之元素的後面。(是加到指定區塊內)
- prepend()：將參數所指定的元素加到符合之元素的前面。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <a href="https://www.youtube.com/">YT</a>
    </body>
    <script>
        let href = $("a");
        href.append("<b>這是preend</b>");
        href.prepend("<b>這是append</b>");
        // <a href="https://www.youtube.com/"><b>這是append</b>YT<b>這是preend</b></a>
    </script>
</html>
```

- before()：來將參數所指定的元素加到符合之元素的前面。(是加到指定區塊外)
- after()：來將參數所指定的元素加到符合之元素的後面。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <a href="https://www.youtube.com/">YT</a>
    </body>
    <script>
        let href = $("a");
        href.before("<p>這是before</p>");
        href.after("<p>這是after</p>");
        // <a href="https://www.youtube.com/"><b>這是append</b>YT<b>這是preend</b></a>
    </script>
</html>
```
### 操作集合中的每個物件
- each()方法的語法如下，用來針對物件或陣列進行重複運算。
![upgit_20241102_1730519573.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241102_1730519573.png)

![upgit_20241102_1730519885.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241102_1730519885.png)


### 操作CSS設定
![upgit_20241102_1730522244.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241102_1730522244.png)


```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <h1 style="background-color: #add9f4">這是標籤H1</h1>
    </body>
    <script>
        let h1 = $("h1");
        h1.on("mouseover", function () {
            $(this).css({
                color: "red",
            });
        });
        h1.on("mouseout", function () {
            $(this).css({
                color: "white",
            });
        });
    </script>
</html>
```

### 取得元素高度寬度
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <h1 style="background-color: #add9f4">這是標籤H1</h1>
    </body>
    <script>
        let h1 = $("h1");
        console.log(h1.width());
        console.log(h1.height());
        h1.width("50rem");
    </script>
</html>
```

### 移除元素
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <h1 style="background-color: #add9f4">這是標籤H1</h1>
    </body>
    <script>
        let h1 = $("h1");
        h1.remove();
    </script>
</html>
```

## jQuery DOM 操作方法

### 選擇子元素
- `.find(selector)`：從選定元素中找到符合 `selector` 的所有後代元素。
    - 範例：`$("p").find("span").css("color", "red");` 將 `<p>` 元素中的所有 `<span>` 元素的文字設為紅色。
- `.children(selector)`：從選定元素中找到符合 `selector` 的直接子元素。
    - 範例：`$("ul.level-2").children().css("color", "red");` 將 `ul.level-2` 的直接子元素的文字設為紅色。
```html
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <p>展示.find()</p>
        <p>Hello, <span>world</span>! Today is <span>Friday</span>.</p>
        <hr />
        <p>.children()</p>
        <ul class="level-1">
            <li>Item A</li>
            <li>
                Item B
                <ul class="level-2">
                    <li>Item 1</li>
                    <li>Item 2</li>
                </ul>
            </li>
            <li>Item C</li>
        </ul>
    </body>
    <script>
        $("p").find("span").css("color", "red");
        $("ul.level-2").children().css("color", "blue");
    </script>
</html>

```
###  選擇父元素
- **`.closest(selector)`**：從選定元素開始，沿 DOM 樹向上查找，返回最接近且符合 `selector` 的祖先元素。
    - 範例：`$("li.item-1").closest("ul").css("color", "red");` 選取最近的 `<ul>` 祖先元素並設為紅色。
- **`.parent(selector)`**：找到符合 `selector` 的直接父元素。
    - 範例：`$("p").parent(".selected").css("color", "red");` 將 `<p>` 元素的直接父元素設為紅色。
- **`.parents(selector)`**：從選定元素開始，沿 DOM 樹向上查找，找到所有符合 `selector` 的祖先元素。
    - 範例：`$("p").parents(".selected").css("color", "red");` 將所有符合 `.selected` 的祖先元素設為紅色。
```html
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.slim.min.js"
            integrity="sha256-kmHvs0B+OpCW5GVHUNjv9rOmY0IvSIRcf7zGUDTDQM8="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <p>展示closest()</p>
        <ul class="level-1">
            <li class="item-1">Item A</li>
            <li class="item-2">Item B</li>
        </ul>
        <hr />
        <p>展示parent()</p>
        <div class="selected">
            <p>Hello World</p>
        </div>
        <hr />
    </body>
    <script>
        $("li.item-1").closest("ul").css("color", "green");
        $("p").parent(".selected").css("color", "red");
    </script>
</html>
```
### 選擇兄弟元素
- **`.siblings(selector)`**：找到符合 `selector` 的所有兄弟元素。
    - `$("li.active").siblings().css("color", "red");` 將 `li.active` 的所有兄弟元素設為紅色。
- **`.next(selector)`**：找到符合 `selector` 的下一個兄弟元素。
    - `$("li.active").next().css("color", "red");` 將 `li.active` 的下一個兄弟元素設為紅色。
- **`.nextAll(selector)`**：找到符合 `selector` 的所有後續兄弟元素。
    - `$("li.active").nextAll().css("color", "red");` 將 `li.active` 後的所有兄弟元素設為紅色。
- **`.prev(selector)`**：找到符合 `selector` 的前一個兄弟元素。
    - `$("li.active").prev().css("color", "red");` 將 `li.active` 的前一個兄弟元素設為紅色。
- **`.prevAll(selector)`**：找到符合 `selector` 的所有前面的兄弟元素。
    - `$("li.active").prevAll().css("color", "red");` 將 `li.active` 前的所有兄弟元素設為紅色。

## jQuery DOM 篩選方法
- .eq(index)：選擇指定索引的元素。
	- `$("li").eq(1).css("color", "red"); // 將索引為1的項目2設為紅色`
- .first()：選擇第一個元素。
	- `$("li").first().css("color", "red"); // 將第一個項目設為紅色`
- last()：選擇最後一個元素。
	- `$("li").last().css("color", "red"); // 將最後一個項目設為紅色`
- even()：選擇索引為偶數的元素（0、2、4...）。
	- `$("li").even().css("color", "red"); // 將偶數索引的項目設為紅色`
- odd()：選擇索引為奇數的元素（1、3、5...）。
	- `$("li").odd().css("color", "blue"); // 將奇數索引的項目設為藍色`
- is(selector)：檢查當前元素集合是否符合指定的選擇器條件。
```html
<input type="checkbox" id="check">
<script>
    var isFormParent = $("#check").parent().is("form");
    console.log(isFormParent); // 檢查父元素是否為 <form>
</script>
```
- not(selector)：從當前元素集合中排除指定的元素。
	- `$("li").not($("#notli")).css("color", "red"); // 排除 id="notli" 的項目，其他設為紅色`
- has(selector)：選擇包含指定子元素的元素。
	- `$("li").has("ul").css("color", "red"); // 選擇包含 <ul> 的項目並設為紅色`
- filter(selector)：從當前元素集合中篩選出符合指定條件的元素。
```html
<ul>
    <li>項目 1</li>
    <li>項目 2</li>
    <li>項目 3</li>
    <li>項目 4</li>
    <li>項目 5</li>
</ul>
<script>
    $("li").filter(":odd").css("color", "red"); // 選擇奇數索引項目並設為紅色
</script>
```
## Query 事件處理
- on()：用於為元素綁定事件處理程序。你可以為同一元素綁定多個事件。
```js
// 語法
// $(selector).on(events, [selector], [data], handler);
// events：事件名稱（例如 `click` 或 `dblclick`）
// selector：選擇器
// data：要傳遞給事件處理程序的數據
// handler：當事件觸發時執行的函式

// 範例
$("button").on("click dblclick", function () {
    $("p").text("段行文字已被按下！");
});
```

- off()：用於移除指定的事件處理程序。如果未指定參數，則移除所有綁定的事件。
```js
// 語法
// $(selector).off(events, [selector], [handler]);

// 範例
$("button").off("click");
```

- ready()：是在 DOM 加載完成後執行指定的函式，通常用於初始化。
```js
$(document).ready(function () {
    $("p").text("DOM 已經載入完畢！");
});

// 或簡寫
$(function () {
    $("p").text("DOM 已經載入完畢！");
});
```

### event物件
![upgit_20241102_1730525209.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241102_1730525209.png)
- 當我們要在事件處理程式中存取Event物件時，可以透過名稱為e的參數來加以傳遞。
- 且e必須是第一個參數。

```js
// 取得事件目標元素與事件類型
$("input").on("click", function (e) {
    $(this).after("<p>目標元素：" + e.target + "</p>")
           .after("<p>事件類型：" + e.type + "</p>");
});
```

## Query 動畫與特效
### 基本特效
- hide()：隱藏符合的元素
	- `$('#element').hide(600); // 600 毫秒內隱藏`
- show()：顯示符合的元素
	- `$('#element').show(600); // 600 毫秒內顯示`
-  toggle()：切換顯示/隱藏元素
	- `$('#element').toggle(); // 無參數切換顯示狀態`
	- `$('#element').toggle(600); // 600 毫秒內切換`

### 淡入/淡出特效
- fadeIn()/fadeOut()：淡入/淡出特效顯示元素
	- `$('#element').fadeIn(400); // 400 毫秒內淡入顯示`
	- `$('#element').fadeOut(400); // 400 毫秒內淡出隱藏`
- fadeTo()：調整透明度
	- `$('#element').fadeTo(400, 0.5); // 400 毫秒內調整透明度到 50%`
- fadeToggle()：切換淡入/淡出特效
	- `$('#element').fadeToggle(400); // 400 毫秒內切換淡入/淡出`

### 滑動特效
- slideDown()/slideUp()：滑動顯示/隱藏元素
	- `$('#element').slideDown(600); // 600 毫秒內由上往下滑動顯示`
	- `$('#element').slideUp(600); // 600 毫秒內由下往上滑動隱藏`
- slideToggle()：切換滑動顯示/隱藏
	- `$('#element').slideToggle(600); // 600 毫秒內切換滑動顯示/隱藏`
```html
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
        <!-- jQuery -->
        <script
            src="https://code.jquery.com/jquery-3.7.1.js"
            integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4="
            crossorigin="anonymous"
        ></script>
    </head>
    <body>
        <button id="hideBtn">隱藏</button>
        <button id="showBtn">顯示</button>
        <button id="toggleBtn">切換顯示</button>
        <button id="fadeInBtn">淡入顯示</button>
        <button id="fadeOutBtn">淡出隱藏</button>
        <button id="slideDownBtn">滑動顯示</button>
        <button id="slideUpBtn">滑動隱藏</button>
        <h1 id="element">Hello, jQuery!</h1>
    </body>
    <script>
        // 隱藏
        $("#hideBtn").on("click", function () {
            $("#element").hide(600);
        });

        // 顯示
        $("#showBtn").on("click", function () {
            $("#element").show(600);
        });

        // 切換顯示/隱藏
        $("#toggleBtn").on("click", function () {
            $("#element").toggle(600);
        });

        // 淡入顯示
        $("#fadeInBtn").on("click", function () {
            $("#element").fadeIn(600);
        });

        // 淡出隱藏
        $("#fadeOutBtn").on("click", function () {
            $("#element").fadeOut(600);
        });

        // 滑動顯示
        $("#slideDownBtn").on("click", function () {
            $("#element").slideDown(600);
        });

        // 滑動隱藏
        $("#slideUpBtn").on("click", function () {
            $("#element").slideUp(600);
        });
    </script>
</html>

```