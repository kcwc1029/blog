
## Vue.js 介紹
- Vue.js 是基於 Angular 和 React 的基礎上開發的框架，結合了這兩者的優勢，並保留了其獨特的特性。
- 它在前端框架中具有市場佔有率，且逐漸受到更多開發者的認可。
- 使用 Vue.js 的開發者數量逐年增長，並且在用戶滿意度上得分較高。

### Vue.js 是什麼
- Vue.js 是一款漸進式框架，主要應用於構建用戶介面的視圖層。
- 它的核心概念圍繞著響應式資料綁定和組件系統，使得開發者可以靈活地擴展應用。
- Vue.js 支持 MVVM 模式，透過資料綁定和 DOM 操作來實現動態的網頁內容。

### MVC 模式介紹
- MVC 模式包括模型(Model)、視圖(View)、控制器(Controller)三個部分。
- Model 負責資料邏輯，View 負責顯示，Controller 負責處理用戶的輸入並進行相應的資料處理。
- MVC 的優點在於將業務邏輯與介面分離，便於維護和擴展。
### MVP 模式介紹
- MVP 模式中的 Presenter 負責管理業務邏輯，而 View 只負責顯示。
- 在該模式中，View 和 Model 是完全解耦的，便於進行測試和維護。
- MVP 模式適合於更複雜的應用，特別是需要頻繁更新視圖的情況。
### MVVM 模式介紹
- MVVM 是 MVC 的進階版，分離了視圖(View)和業務邏輯(Model)。
- 引入了 ViewModel 層，用於處理業務邏輯和 UI 間的資料綁定。
- MVVM 適合於需要雙向資料綁定的應用場景，並引入了 WPF 等技術的支援。
![upgit_20241106_1730879598.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730879598.png)

### Vue.js 與 React 的比較
- 優勢
	1. 使用虛擬 DOM。
	2. 提供響應式和元件化的視圖。
	3. 核心簡單，便於快速上手。
- 缺點
	1. Vue.js 的社區生態系統相較 React 較小。
	2. 在 HTML 和 CSS 上的支援方式不同，Vue.js 使用範本語法，而 React 使用 JSX 語法。
-  區別
	- React 注重於單一方向的資料流，而 Vue.js 支持雙向資料綁定。
	- React 更傾向於使用外部工具，Vue.js 則具有內建 CLI 支援。

## 建立一個沒有vue的網頁
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>A First App</title>
        <style>
            * {
                box-sizing: border-box;
            }
            body {
                margin: 0;
            }
            #app {
                margin: 3rem auto;
                max-width: 40rem;
                padding: 1rem;
                box-shadow: 0 2px 8px rgba(0, 0, 0, 0.26);
            }
            label,
            input {
                margin-bottom: 0.5rem;
                display: block;
                width: 100%;
            }
            label {
                font-weight: bold;
            }
            ul {
                list-style: none;
                margin: 1rem 0;
                padding: 0;
            }
            li {
                margin: 1rem 0;
                padding: 1rem;
                border: 1px solid #ccc;
            }
        </style>
    </head>
    <body>
        <div id="app">
            <div>
                <label for="goal">吵架清單</label>
                <input type="text" id="goal" />
                <button>增加項目</button>
            </div>
            <ul>
                <li>尿尿不洗手</li>
                <li>抽菸bad</li>
            </ul>
        </div>
        <script>
            let buttonEl = document.querySelector("button");
            let inputEl = document.querySelector("input");
            let ulEl = document.querySelector("ul");

            // 排查元素選取問題
            console.log(buttonEl, inputEl, ulEl);

            buttonEl.addEventListener("click", () => {
                let enteredValue = inputEl.value;

                // 檢查是否有輸入值
                if (enteredValue.trim() !== "") {
                    // 建立新的li元素
                    let newLi = document.createElement("li");
                    newLi.textContent = enteredValue;

                    // 將新的li元素添加到ul中
                    ulEl.appendChild(newLi);

                    // 清空輸入欄
                    inputEl.value = "";
                }
            });
        </script>
    </body>
</html>
```

- 更改為vue後
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>A First App</title>
        <style>
            * {
                box-sizing: border-box;
            }
            body {
                margin: 0;
            }
            #app {
                margin: 3rem auto;
                max-width: 40rem;
                padding: 1rem;
                box-shadow: 0 2px 8px rgba(0, 0, 0, 0.26);
            }
            label,
            input {
                margin-bottom: 0.5rem;
                display: block;
                width: 100%;
            }
            label {
                font-weight: bold;
            }
            ul {
                list-style: none;
                margin: 1rem 0;
                padding: 0;
            }
            li {
                margin: 1rem 0;
                padding: 1rem;
                border: 1px solid #ccc;
            }
        </style>
        <!-- VUE -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <div>
                <label for="goal">吵架清單</label>
                <input type="text" id="goal" v-model="enteredValue" />
                <button v-on:click="addGoal">增加項目</button>
            </div>
            <ul>
                <li>尿尿不洗手</li>
                <li>抽菸bad</li>
                <li v-for="goal in goals">{{ goal }}</li>
            </ul>
        </div>
        <script>
            Vue.createApp({
                data() {
                    return {
                        goals: [],
                        enteredValue: "",
                    };
                },
                methods: {
                    addGoal() {
                        if (this.enteredValue.trim() !== "") {
                            this.goals.push(this.enteredValue);
                            this.enteredValue = ""; // 清空輸入框
                        }
                    },
                },
            }).mount("#app");
        </script>
    </body>
</html>
```
![upgit_20241105_1730778585.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241105_1730778585.png)



## 起手式
- 這邊引入vue跟bootstrap5的CDN
- mount：將實體掛載到HTML的物件當中。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">{{message}}</div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    message: "hello vue",
                };
            },
        });
        app.mount("#app");
    </script>
</html>
```

## 文字綁定(單向)
### 使用mustache標籤
- 是一種樣板與法。
![upgit_20241106_1730880069.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730880069.png)

### v-text
![upgit_20241106_1730880329.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730880329.png)

### v-html
![upgit_20241106_1730880830.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730880830.png)

## 屬性綁定(單向)
### v-bind
- v-bind可以改成「:」
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <p v-html="message"></p>
            <!-- TODO: 綁訂單個屬性 -->
            <img v-bind:src="img" alt="" srcset="" />
            <!-- TODO: 綁訂多個屬性：用一個物件包起來 -->
            <img v-bind="objectImg" />
            <!-- TODO: 綁訂布林值-->
            <button :disabled="isDisable">這是button</button>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    message: "<h1>hello vue</h1>",
                    img: "./img/image01.jpg",
                    objectImg: {
                        src: "./img/image01.jpg",
                        width: "500",
                    },
                    isDisable: true,
                };
            },
        });
        app.mount("#app");
    </script>
</html>
```

- 另一個範例
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <header class="container my-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-4">Vue Course Goals</h1>
        </header>
        <section id="user-goal" class="container my-4 p-4 border rounded text-center shadow">
            <h2 class="h2 text-success border-bottom pb-2 mb-4">My Course Goal</h2>
            <!-- 綁定屬性 -->
            <a v-bind:href="vuelink">官網查詢</a>
            <!-- 偛值 -->
            <p class="fs-5 fw-bold bg-success text-white py-2 px-3 rounded-pill">{{ courseGoal }}</p>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    courseGoal: "努力畢業", // data裡面返還資料到{{courseGoal}}
                    vuelink: "https://www.es.ncku.edu.tw/esncku/zh/page.home.action",
                };
            },
        });
        app.mount("#user-goal");
    </script>
</html>
```

## mathods、computed、watch屬性
### mathods屬性
- 可以在這個屬性內定義方法。
- 用來定義方法，適合處理觸發性或事件驅動的操作，例如按鈕點擊事件或表單提交。
- `methods` 中的方法每次呼叫都會重新執行，不會自動快取結果。
![upgit_20241106_1730882597.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730882597.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <p>身高(cm):{{ height }}</p>
            <p>體重(kg):{{ weight}}</p>
            <p>BMI: {{BMI()}}</p>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    height: 176,
                    weight: 62,
                };
            },
            methods: {
                BMI() {
                    return (this.weight / (this.height / 100) ** 2).toFixed(2);
                },
            },
        });
        app.mount("#app");
    </script>
</html>
```
### computed屬性
- 適合計算屬性，當依賴的資料改變時才會重新計算，並且結果會自動快取。
- 宣告：要括弧(放參數)
- 函數內要有return
- 呼叫：以屬性進行呼叫
![upgit_20241106_1730883199.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730883199.png)

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Vue Basics</title>
    <!-- Bootstrap -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
    <!-- Vue -->
    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
</head>
<body>
    <div id="app">
        <p>身高(cm): {{ height }}</p>
        <p>體重(kg): {{ weight }}</p>
        <p>BMI: {{ BMI }}</p>
    </div>
</body>
<script>
    const app = Vue.createApp({
        data() {
            return {
                height: 176,
                weight: 62,
            };
        },
        computed: {
            BMI() {
                return (this.weight / (this.height / 100) ** 2).toFixed(2);
            },
        },
    });
    app.mount("#app");
</script>
</html>
```


### watch屬性
- 適合監聽指定資料的變化，當指定的資料改變時執行相應的回調函數。
- `watch` 屬性通常用於執行非同步操作（例如 API 請求），或在資料改變時進行複雜的邏輯處理。
- 會有兩個參數(新值, 舊值)
![upgit_20241106_1730883762.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730883762.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <p>身高(cm): {{ height }}</p>
            <p>體重(kg): {{ weight }}</p>
            <input type="number" v-model="weight" placeholder="修改體重" />
            <p>BMI: {{ bmi }}</p>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    height: 176,
                    weight: 62,
                    bmi: null,
                };
            },
            methods: {
                updateBMI() {
                    this.bmi = (this.weight / (this.height / 100) ** 2).toFixed(2);
                },
            },
            watch: {
                // TODO: 監測數值修改 -> 有修改就去執行methods的updateBMI()
                weight(newWeight, oldWeight) {
                    this.updateBMI();
                },
            },
        });
        app.mount("#app");
    </script>
</html>
```

## v-on 事件處理
- 可以減寫為「@」
![upgit_20241106_1730884093.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730884093.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <button @click="countPlus()">點讚次數：{{count}}</button>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    count: 0,
                };
            },
            methods: {
                countPlus() {
                    this.count++;
                },
            },
        });
        app.mount("#app");
    </script>
</html>
```

- 另一個例子
![upgit_20241105_1730785366.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241105_1730785366.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body class="bg-light">
        <header class="container my-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-5">Vue Events</h1>
        </header>

        <section id="events" class="container my-4 p-4 text-center border rounded shadow bg-white">
            <h2 class="text-success border-bottom pb-2 mb-4">Events in Action</h2>
            <!-- TODO: button 綁定監聽 -->
            <button class="btn btn-danger me-2" v-on:click="increaseCounter(1)">Add 1</button>
            <button class="btn btn-danger" v-on:click="decreaseCounter(1)">Remove 1</button>
            <hr />
            <button class="btn btn-danger me-2" v-on:click="increaseCounter(5)">Add 5</button>
            <button class="btn btn-danger" v-on:click="decreaseCounter(5)">Remove 5</button>

            <!-- Result區塊 -->
            <p class="fs-5 fw-bold mt-4 bg-success text-white rounded-pill">Result: {{counter}}</p>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    counter: 0,
                };
            },
            methods: {
                increaseCounter(num) {
                    this.counter += num;
                },
                decreaseCounter(num) {
                    this.counter -= num;
                },
            },
        });
        app.mount("#events");
    </script>
</html>
```
- 另一個例子：如果要做出【鍵盤輸入，同時顯示】之效果。
![upgit_20241105_1730785901.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241105_1730785901.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body class="bg-light">
        <header class="container my-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-5">Vue Events</h1>
        </header>

        <section id="events" class="container my-4 p-4 text-center border rounded shadow bg-white">
            <h2 class="text-success border-bottom pb-2 mb-4">Events in Action</h2>
            <input type="text" placeholder="請隨意姓名" v-on:input="setName" />
            <!-- 在 v-on:input="setName()" 中使用了括弧 ()，這會直接調用 setName() 方法，而不是將事件作為參數傳入。 -->
            <hr />

            <!-- Result區塊 -->
            <p class="fs-5 fw-bold mt-4 bg-success text-white rounded-pill">姓名: {{name}}</p>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    name: "",
                };
            },
            methods: {
                setName(event) {
                    this.name = event.target.value;
                },
            },
        });
        app.mount("#events");
    </script>
</html>
```


## v-model 雙向綁定(表單)
- 時線文字輸入同步顯示
![upgit_20241106_1730884392.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730884392.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <input type="text" name="" id="" v-model="message" />
            <p>輸入訊息如下：{{message}}</p>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    message: "",
                };
            },
            methods: {},
        });
        app.mount("#app");
    </script>
</html>
```

- radio搭配v-model
![upgit_20241107_1730955196.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730955196.png)
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <!-- TODO: radio 搭配v-model -->
            <p>確認哥布林 {{Goblin}}</p>
            <input type="radio" name="" id="yes" value="是" v-model="Goblin" />
            <label for="yes">是</label>
            <input type="radio" name="" id="no" value="否" v-model="Goblin" />
            <label for="no">否</label>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    Goblin: "是", // 使用小寫的 true
                };
            },
            methods: {},
        });
        app.mount("#app");
    </script>
</html>
```
- checkbox搭配v-model
![upgit_20241107_1730955335.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730955335.png)
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <!-- TODO: checkbox 搭配v-model -->
            <p>興趣(可複選):{{interest}}</p>
            <input type="checkbox" id="item1" value="閱讀" v-model="interest" />
            <label for="item1">閱讀</label>
            <input type="checkbox" id="item2" value="運動" v-model="interest" />
            <label for="item2">運動</label>
            <input type="checkbox" id="item3" value="園藝" v-model="interest" />
            <label for="item3">園藝</label>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    interest: [], // 使用陣列裝有選的
                };
            },
            methods: {},
        });
        app.mount("#app");
    </script>
</html>
```
- textarea搭配v-model
![upgit_20241107_1730955486.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730955486.png)
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <!-- TODO: textarea 搭配v-model -->
            <textarea rows="5" v-model="message"></textarea>
            <p style="white-space: pre-line">輸入訊息如下: <br />{{ message }}</p>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    message: "", // 使用陣列裝有選的
                };
            },
            methods: {},
        });
        app.mount("#app");
    </script>
</html>
```
- selected搭配v-model
![upgit_20241107_1730955669.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730955669.png)
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <!-- TODO: select 搭配v-model -->
            <p>最高學歷:{{education}}</p>
            <select v-model="education">
                <option disabled value="">請選擇一個</option>
                <option value="碩士或以上">碩士或以上</option>
                <option value="大專">大專</option>
                <option value="高中或以下">高中或以下</option>
            </select>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    education: "", // 使用陣列裝有選的
                };
            },
            methods: {},
        });
        app.mount("#app");
    </script>
</html>
```

### V-model & 修飾字(modifier)
- lazy：
	- v-model指令預設會監聽文字方塊的input事件，只要使用者一敲擊鍵盤就會觸發input事件。
	- 加上lazy後，改成使用者按下【enter】才會顯示。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <!-- TODO:  -->
            <input type="text" v-model.lazy="message" />
            <p>輸入訊息如下 :<br />{{message }}</p>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    message: "", // 使用陣列裝有選的
                };
            },
            methods: {},
        });
        app.mount("#app");
    </script>
</html>
```

- trim：去除前後空白字元。
- number：將輸入資料視為數值。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <!-- TODO:  -->
            <p>1 : <input type="text" v-model.number="num1" /></p>
            <p>2 : <input type="text" v-model.number="num2" /></p>
            <p>數字1+數字2:{{num1 +num2}}</p>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    num1: 0,
                    num2: 0,
                };
            },
            methods: {},
        });
        app.mount("#app");
    </script>
</html>
```

##  Event Modifier
![upgit_20241105_1730787041.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241105_1730787041.png)

- 點下button後，瀏覽器會發送request並reload網頁(預設)
- 但有時候你並不希望他去做這件，你希望你手動設定。
- 方法1：
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body class="bg-light">
        <header class="container my-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-5">Vue Events</h1>
        </header>

        <section id="events" class="container my-4 p-4 text-center border rounded shadow bg-white">
            <h2 class="text-success border-bottom pb-2 mb-4">Events in Action</h2>
            <!-- TODO:  阻止form跳轉 方法1 -->
            <form action="" v-on:submit="submitForm">
                <p class="fs-5 fw-bold mt-4 bg-success text-white rounded-pill">傳送表單</p>
                <input type="text" />
                <button class="btn btn-danger me-2">sign in</button>
            </form>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {};
            },
            methods: {
                submitForm(event) {
                    event.preventDefault();
                    alert("提交表單");
                },
            },
        });
        app.mount("#events");
    </script>
</html>
```
- 方法2：使用Event Modifier
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body class="bg-light">
        <header class="container my-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-5">Vue Events</h1>
        </header>

        <section id="events" class="container my-4 p-4 text-center border rounded shadow bg-white">
            <h2 class="text-success border-bottom pb-2 mb-4">Events in Action</h2>
            <!-- TODO:  阻止form跳轉 方法2 透過事件修飾符  -->
            <form action="" v-on:submit.prevent="submitForm">
                <p class="fs-5 fw-bold mt-4 bg-success text-white rounded-pill">傳送表單</p>
                <input type="text" />
                <button class="btn btn-danger me-2">sign in</button>
            </form>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {};
            },
            methods: {
                submitForm() {
                    alert("提交表單");
                },
            },
        });
        app.mount("#events");
    </script>
</html>
```

- 再來看一個使用Event Modifier的例子
	- 原本是監聽打字(打一個輸出一個)，在原基礎上改成【按下enter才會顯示】
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body class="bg-light">
        <header class="container my-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-5">Vue Events</h1>
        </header>

        <section id="events" class="container my-4 p-4 text-center border rounded shadow bg-white">
            <h2 class="text-success border-bottom pb-2 mb-4">Events in Action</h2>
            <!-- TODO: 使用Event Modifier -->
            <input type="text" placeholder="請隨意姓名" v-on:input="setName" v-on:keyup.enter="confirmInput" />
            <hr />
            <p class="fs-5 fw-bold mt-4 bg-success text-white rounded-pill">姓名: {{confirmName}}</p>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    name: "",
                    confirmName: "",
                };
            },
            methods: {
                // 監聽打字
                setName(event) {
                    this.name = event.target.value;
                },
                confirmInput() {
                    this.confirmName = this.name;
                },
            },
        });
        app.mount("#events");
    </script>
</html>
```

## v-once：鎖定內容
![upgit_20241105_1730788141.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241105_1730788141.png)

- 用於 **一次性渲染元素**。
- 當使用 `v-once` 指令時，Vue 會在初次渲染時將元素或組件的內容緩存下來，不會隨著後續數據的變化而重新渲染該元素或組件。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body class="bg-light">
        <header class="container my-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-5">Vue Events</h1>
        </header>

        <section id="events" class="container my-4 p-4 text-center border rounded shadow bg-white">
            <h2 class="text-success border-bottom pb-2 mb-4">Events in Action</h2>
            <button class="btn btn-danger me-2" v-on:click="increaseCounter(1)">Add 1</button>
            <button class="btn btn-danger" v-on:click="decreaseCounter(1)">Remove 1</button>
            <!-- TODO: 使用v-once -->
            <p class="fs-5 fw-bold mt-4 bg-success text-white rounded-pill">沒有使用 v-once Result: {{counter}}</p>
            <p v-once class="fs-5 fw-bold mt-4 bg-success text-white rounded-pill">有使用 v-once Result: {{counter}}</p>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    counter: 0,
                };
            },
            methods: {
                increaseCounter(num) {
                    this.counter += num;
                },
                decreaseCounter(num) {
                    this.counter -= num;
                },
            },
        });
        app.mount("#events");
    </script>
</html>
```

## CSS綁定
- 綁定class：`:class={"class名稱", "vue屬性"}`
- 綁定style：`:syle={"css屬性", "vue屬性"}`
![upgit_20241107_1730958088.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730958088.png)

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <style>
        .class1 {
            background-color: aquamarine;
        }
        .class2 {
            background-color: cornflowerblue;
        }
    </style>
    <body>
        <div id="app">
            <!-- 切換 class 基於 isHovered 的值 -->
            <h1 :class="isHovered ? 'class1' : 'class2'" @mouseover="over()" @mouseout="out()">姊姊你會唱哈基米嗎</h1>
            <h1 :style="{'background-color': bgColor}" @mouseover="over()" @mouseout="out()">姊姊你會唱哈基米嗎</h1>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    isHovered: false,
                    bgColor: "cornflowerblue",
                };
            },
            methods: {
                over() {
                    this.isHovered = true;
                    this.bgColor = "aquamarine";
                },
                out() {
                    this.isHovered = false;
                    this.bgColor = "cornflowerblue";
                },
            },
        });
        app.mount("#app");
    </script>
</html>
```


### 另一個例子：動態添加CSS
```html
	<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Dynamic Styling</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
        <style>
            .active {
                border-color: red;
                background-color: salmon;
            }
        </style>
    </head>
    <body class="bg-light">
        <header class="container my-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-5">Vue Dynamic Styling</h1>
        </header>

        <section id="styling" class="container p-4 rounded shadow bg-white text-center">
            <!-- 綁定 :class 動態切換 active 類別 -->
            <div class="demo border border-2 border-dashed border-secondary p-4 mb-3" :class="{ active: boxASelected }" @click="toggleBox('A')"></div>
            <div class="demo border border-2 border-dashed border-secondary p-4 mb-3" :class="{ active: boxBSelected }" @click="toggleBox('B')"></div>
            <div class="demo border border-2 border-dashed border-secondary p-4 mb-3" :class="{ active: boxCSelected }" @click="toggleBox('C')"></div>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    boxASelected: false,
                    boxBSelected: false,
                    boxCSelected: false,
                };
            },
            methods: {
                toggleBox(box) {
                    if (box === "A") this.boxASelected = true;
                    else if (box === "B") this.boxBSelected = true;
                    else if (box === "C") this.boxCSelected = true;
                },
            },
        });
        app.mount("#styling");
    </script>
</html>
```

- 也可以進一步，把切換CSS的環節放到compute
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Dynamic Styling</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
            crossorigin="anonymous"
        ></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
        <style>
            .active {
                border-color: red;
                background-color: salmon;
            }
        </style>
    </head>
    <body class="bg-light">
        <header class="container my-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-5">Vue Dynamic Styling</h1>
        </header>

        <section id="styling" class="container p-4 rounded shadow bg-white text-center">
            <!-- boxA的切換改成用computed去做 -->
            <div class="demo border border-2 border-dashed border-secondary p-4 mb-3" :class="boxAClass" @click="toggleBox('A')"></div>
            <div class="demo border border-2 border-dashed border-secondary p-4 mb-3" :class="{ active: boxBSelected }" @click="toggleBox('B')"></div>
            <div class="demo border border-2 border-dashed border-secondary p-4 mb-3" :class="{ active: boxCSelected }" @click="toggleBox('C')"></div>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    boxASelected: false,
                    boxBSelected: false,
                    boxCSelected: false,
                };
            },
            // 把CSS切換的步驟切到computed這邊去做
            computed: {
                boxAClass() {
                    return { active: this.boxASelected };
                },
            },
            methods: {
                toggleBox(box) {
                    if (box === "A") this.boxASelected = true;
                    else if (box === "B") this.boxBSelected = true;
                    else if (box === "C") this.boxCSelected = true;
                },
            },
        });
        app.mount("#styling");
    </script>
</html>
```

## v-if、v-else、v-else條件式渲染
![upgit_20241107_1730960487.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730960487.png)
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <div v-if="type === 'X'">X</div>
            <div v-else-if="type === 'Y'">Y</div>
            <div v-else-if="type === 'Z'">Z</div>
            <div v-else>Not X/Y/Z</div>
            <button @click="change()">切換不同div</button>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    arr: ["X", "Y", "Z"],
                    type: "X",
                };
            },
            methods: {
                change() {
                    this.type = this.arr[Math.floor(Math.random() * this.arr.length)];
                },
            },
        });
        app.mount("#app");
    </script>
</html>
```

### v-show
- 他是將元素增加sttle="display:none"，仍有出現在html，但並不會顯示出來。
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <button @click="toggle = !toggle">切換</button>
            <h1 v-show="toggle">Hello, Vue.js !</h1>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    toggle: true,
                };
            },
            methods: {},
        });
        app.mount("#app");
    </script>
</html>
```

## v-for清單渲染
![upgit_20241107_1730960976.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730960976.png)
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Basics</title>
        <!-- Bootstrap -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <ul>
                <li v-for="(item, index) in arr" :key="index">{{item}}-{{index}}</li>
            </ul>
        </div>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    arr: ["dog", "cat", "bird"],
                };
            },
            methods: {},
        });
        app.mount("#app");
    </script>
</html>
```
## ref 
- `ref` 是 Vue 中用來創建響應式數據或 DOM 元素的引用
- 允許我們追蹤和更新變數或直接操作 DOM 元素，使用 `.value` 來訪問和修改它的內容。
- 我們來探討，把輸入內容顯示出來，有幾種方式。
- 第一種
![upgit_20241107_1730967671.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730967671.png)


- 第二種：利用按鈕的方式去顯示值
![upgit_20241107_1730968090.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730968090.png)

- 第二種：利用ref
![upgit_20241107_1730969074.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730969074.png)

## 虛擬DOM
![upgit_20241107_1730969230.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730969230.png)

![upgit_20241107_1730969270.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730969270.png)

### 簡單介紹 Vue 的虛擬 DOM

1. **什麼是虛擬 DOM**：虛擬 DOM 是一種 JavaScript 表示法，它創建了一棵與真實 DOM 相似的樹狀結構，用來模擬頁面 UI 的狀態。當數據發生變化時，Vue 會先更新虛擬 DOM 樹，然後將其與上一版本的虛擬 DOM 進行比較，找出變更之處。
2. **如何工作**：
    - **數據更新**：當 Vue 中的數據發生變化時，Vue 會自動更新對應的虛擬 DOM 樹。
    - **差異比較**：Vue 將新舊虛擬 DOM 樹進行比較，識別出需要改變的節點和屬性。
    - **精準更新**：Vue 只將改變的部分同步到真實 DOM 中，避免不必要的重排和重繪，從而提升渲染效能。
3. **為什麼使用虛擬 DOM**：
    - **性能優化**：直接操作真實 DOM 是耗時的，虛擬 DOM 可以減少直接操作真實 DOM 的次數。
    - **響應式渲染**：Vue 將數據和視圖分離，通過虛擬 DOM 來自動處理數據與視圖的同步。
    - **跨瀏覽器一致性**：虛擬 DOM 幫助 Vue 跨瀏覽器進行一致的渲染。

### 簡單類比

可以把虛擬 DOM 想像成頁面的「快照」。每次數據變化時，Vue 會生成新的快照（虛擬 DOM），並與之前的快照進行對比，這樣 Vue 就能知道需要更新哪些部分，而不必重新渲染整個頁面。

### 總結

虛擬 DOM 是 Vue 用來提升渲染性能的核心技術，通過構建、比較和更新虛擬 DOM，Vue 能夠快速、精準地將變化同步到真實 DOM 中，從而提升整體的渲染效率。

## vue的生命週期
![upgit_20241107_1730969426.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241107_1730969426.png)

在 Vue 中，**生命週期（Lifecycle）** 是指 Vue 元件從創建到銷毀過程中的一系列階段。Vue 提供了生命週期鉤子函數（hook functions），允許我們在元件的不同階段執行特定的代碼。了解生命週期可以幫助我們更好地控制元件的行為，尤其是在異步操作或 DOM 操作中。

### Vue 生命週期的主要階段

Vue 的生命週期可以分為以下四個主要階段：

1. **創建階段（Creation）**
2. **掛載階段（Mounting）**
3. **更新階段（Updating）**
4. **銷毀階段（Destruction）**

以下是各階段的詳細說明：

---

### 1. 創建階段（Creation）

在這個階段，Vue 會初始化元件的數據、事件和觀察等，但此時尚未將元件掛載到 DOM 上，頁面上看不到元件的內容。

- **`beforeCreate`**：元件實例剛剛創建，數據和事件還未初始化，無法使用 `data` 和 `methods`。通常不常使用。
  
  ```javascript
  beforeCreate() {
    console.log("元件正在創建（beforeCreate）");
  }
  ```

- **`created`**：元件實例已創建，`data`、`methods` 都已初始化，可以進行初始數據的設置或執行異步操作（如 AJAX 請求）。
  
  ```javascript
  created() {
    console.log("元件已創建（created）");
  }
  ```

---

### 2. 掛載階段（Mounting）

在這個階段，Vue 會將模板渲染為虛擬 DOM，然後將虛擬 DOM 挂載到真實 DOM 上，讓頁面顯示元件的內容。

- **`beforeMount`**：在掛載到 DOM 之前調用，虛擬 DOM 已經創建，尚未插入到頁面中。此階段可以用來查看虛擬 DOM。
  
  ```javascript
  beforeMount() {
    console.log("元件即將掛載到 DOM（beforeMount）");
  }
  ```

- **`mounted`**：元件已掛載到 DOM，真實 DOM 已渲染完成。可以在此階段進行 DOM 操作，比如獲取元素尺寸、設置監聽器等。
  
  ```javascript
  mounted() {
    console.log("元件已掛載到 DOM（mounted）");
  }
  ```

---

### 3. 更新階段（Updating）

當元件的 `data` 或 `props` 發生變化時，Vue 會進行重新渲染，此時元件會進入更新階段。

- **`beforeUpdate`**：當數據發生變化，重新渲染之前調用。此時虛擬 DOM 已更新，但尚未同步到真實 DOM。
  
  ```javascript
  beforeUpdate() {
    console.log("元件數據更新前（beforeUpdate）");
  }
  ```

- **`updated`**：重新渲染後調用，虛擬 DOM 已與真實 DOM 同步。通常用於執行 DOM 操作或依賴最新數據的操作。
  
  ```javascript
  updated() {
    console.log("元件數據更新後（updated）");
  }
  ```

---

### 4. 銷毀階段（Destruction）

當元件從 DOM 中移除或其生命周期結束時，它會進入銷毀階段。

- **`beforeUnmount`**：元件銷毀之前調用。可以用來清除定時器或事件監聽器等資源，避免內存洩漏。
  
  ```javascript
  beforeUnmount() {
    console.log("元件即將被銷毀（beforeUnmount）");
  }
  ```

- **`unmounted`**：元件已完全銷毀，與 DOM 的關聯已斷開。此時所有事件監聽器和數據綁定已解除。
  
  ```javascript
  unmounted() {
    console.log("元件已銷毀（unmounted）");
  }
  ```

---

### 生命週期鉤子總結

以下是 Vue 生命週期的執行順序：

1. **beforeCreate** → **created**
2. **beforeMount** → **mounted**
3. **beforeUpdate** → **updated**
4. **beforeUnmount** → **unmounted**

---

### 什麼時候使用各個鉤子？

- **created**：用於進行初始數據加載、異步請求等操作。
- **mounted**：用於操作已掛載的 DOM 元素，如第三方庫的初始化。
- **beforeUpdate** 和 **updated**：用於監測數據變化後的動態操作。
- **beforeUnmount** 和 **unmounted**：用於清理資源（如事件監聽器或定時器）避免內存洩漏。

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Lifecycle Demo</title>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body>
        <div id="app">
            <h1>Vue 生命週期示範</h1>
            <!-- 按鈕用來切換元件顯示與否 -->
            <button @click="toggleComponent">切換元件顯示</button>
            <!-- 使用 v-if 控制元件的顯示與隱藏 -->
            <my-component v-if="showComponent"></my-component>
        </div>

        <script>
            // 定義一個子元件 MyComponent，用於演示 Vue 的生命週期
            const MyComponent = {
                template: `<div><p>這是一個元件</p></div>`,
                
                // 生命週期鉤子：元件實例被創建之前
                beforeCreate() {
                    console.log("beforeCreate：元件實例正在創建中");
                },
                
                // 生命週期鉤子：元件實例創建完成，數據和方法已初始化
                created() {
                    console.log("created：元件實例已創建完成");
                },
                
                // 生命週期鉤子：元件準備掛載到 DOM，但尚未完成
                beforeMount() {
                    console.log("beforeMount：元件即將掛載到 DOM");
                },
                
                // 生命週期鉤子：元件已經掛載到 DOM，可以操作真實的 DOM 元素
                mounted() {
                    console.log("mounted：元件已掛載到 DOM");
                },
                
                // 生命週期鉤子：在數據變更、重新渲染之前調用
                beforeUpdate() {
                    console.log("beforeUpdate：元件數據即將變更，準備重新渲染");
                },
                
                // 生命週期鉤子：數據更新完成，DOM 已同步更新
                updated() {
                    console.log("updated：元件已重新渲染並更新 DOM");
                },
                
                // 生命週期鉤子：元件即將從 DOM 中移除，適合在此進行清理操作
                beforeUnmount() {
                    console.log("beforeUnmount：元件即將從 DOM 中移除");
                },
                
                // 生命週期鉤子：元件已經從 DOM 中完全移除
                unmounted() {
                    console.log("unmounted：元件已從 DOM 中移除");
                },
            };

            // 創建 Vue 應用程式
            const app = Vue.createApp({
                components: {
                    MyComponent, // 註冊 MyComponent 供父元件使用
                },
                data() {
                    return {
                        showComponent: true, // 控制 MyComponent 的顯示與隱藏
                    };
                },
                methods: {
                    // 切換顯示或隱藏元件
                    toggleComponent() {
                        this.showComponent = !this.showComponent;
                    },
                },
            });

            app.mount("#app");
        </script>
    </body>
</html>
```

## component
- 沒有component的問題
```html
<!-- NOTE: 所有的li都是吃同一個methode跟同一個data，所以會一起展開/關閉 -->
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Friend List</title>
        <!-- Bootstrap 5 -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body class="bg-light">
        <header class="container text-center my-5">
            <h1 class="display-5 text-white bg-primary p-3 rounded shadow">Friend List</h1>
        </header>
        <section id="app" class="container">
            <ul class="list-unstyled">
                <li v-for="(item, index) in friends" :key="item.id" class="card mb-3 shadow border-0">
                    <div class="card-body text-center">
                        <h2 class="card-title h4 text-primary">{{item.name}}</h2>
                        <button @click="toggleDetails()" class="btn btn-danger mb-2">Show Details</button>
                        <ul v-if="datailAreVisible" class="list-group list-group-flush">
                            <li class="list-group-item border border-2 shadow"><strong>Phone:</strong> {{item.phone}}</li>
                            <li class="list-group-item border border-2 shadow"><strong>Email:</strong> {{item.email}}</li>
                        </ul>
                    </div>
                </li>
                <!-- 靜態框架 -->
                <!-- <li class="card mb-3 shadow border-0">
                    <div class="card-body text-center">
                        <h2 class="card-title h4 text-primary">Julie Jones</h2>
                        <button class="btn btn-danger mb-2">Show Details</button>
                        <ul class="list-group list-group-flush">
                            <li class="list-group-item border border-2 shadow"><strong>Phone:</strong> 09876 543 221</li>
                            <li class="list-group-item border border-2 shadow"><strong>Email:</strong> julie@localhost.com</li>
                        </ul>
                    </div>
                </li> -->
            </ul>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    datailAreVisible: false,
                    friends: [
                        {
                            id: "001",
                            name: "吉伊卡哇",
                            phone: "77777777",
                            email: "77777777@gmail.com",
                        },
                        {
                            id: "002",
                            name: "小八貓",
                            phone: "88888888",
                            email: "88888888@gmail.com",
                        },
                        {
                            id: "003",
                            name: "兔兔",
                            phone: "88888888",
                            email: "88888888@gmail.com",
                        },
                        {
                            id: "004",
                            name: "小桃鼠   ",
                            phone: "88888888",
                            email: "88888888@gmail.com",
                        },
                    ],
                };
            },
            methods: {
                toggleDetails() {
                    this.datailAreVisible = !this.datailAreVisible;
                },
            },
        });
        app.mount("#app");
    </script>
</html>
```

- 時做component：
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Friend List</title>
        <!-- Bootstrap 5 -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
        <!-- Vue -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    </head>
    <body class="bg-light">
        <header class="container text-center my-5">
            <h1 class="display-5 text-white bg-primary p-3 rounded shadow">Friend List</h1>
        </header>
        <section id="app" class="container">
            <ul class="list-unstyled">
                <!-- 使用 v-for 迴圈來生成每個 friend-contact 元件 -->
                <!-- :key="friend.id"：用來追蹤每個元件的唯一 -->
                <!-- :friend="friend"：這個語法將父層的 friend 資料作為 props 傳遞到每個 friend-contact 元件中。 -->
                <friend-contact v-for="friend in friends" :key="friend.id" :friend="friend"></friend-contact>
            </ul>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    friends: [
                        {
                            id: "001",
                            name: "吉伊卡哇",
                            phone: "77777777",
                            email: "77777777@gmail.com",
                        },
                        {
                            id: "002",
                            name: "小八貓",
                            phone: "88888888",
                            email: "88888888@gmail.com",
                        },
                        {
                            id: "003",
                            name: "兔兔",
                            phone: "99999999",
                            email: "99999999@gmail.com",
                        },
                        {
                            id: "004",
                            name: "小桃鼠",
                            phone: "66666666",
                            email: "66666666@gmail.com",
                        },
                    ],
                };
            },
        });

        // TODO: 定義 friend-contact 元件
        app.component("friend-contact", {
            props: ["friend"], // 接收 `friend` 資料
            template: `
            <li class="card mb-3 shadow border-0">
                <div class="card-body text-center">
                    <h2 class="card-title h4 text-primary">{{ friend.name }}</h2>
                    <button @click="toggleDetails()" class="btn btn-danger mb-2">
                        {{ datailAreVisible ? 'Hide Details' : 'Show Details' }}
                    </button>
                    <ul v-if="datailAreVisible" class="list-group list-group-flush">
                        <li class="list-group-item border border-2 shadow">
                            <strong>Phone:</strong> {{ friend.phone }}
                        </li>
                        <li class="list-group-item border border-2 shadow">
                            <strong>Email:</strong> {{ friend.email }}
                        </li>
                    </ul>
                </div>
            </li>
        `,
            data() {
                return {
                    datailAreVisible: false,
                };
            },
            methods: {
                toggleDetails() {
                    this.datailAreVisible = !this.datailAreVisible;
                },
            },
        });

        app.mount("#app");
    </script>
</html>
```

## vue CLI
- 安裝nodejs
	- 可以透過檢查
```
node -v
npm -v
```
- 全域安裝 Vue CLI
```
npm install -g @vue/cli
vue --version
```
- 常見問題
```
// vue : 因為這個系統上已停用指令碼執行，所以無法載入 C:\Users\33313\AppData\Roaming\npm\vue.ps1 檔案。

# 解決方法
以管理員身份執行PowerShell，輸入以下指令檢查目前的執行政策：
Get-ExecutionPolicy
// 通常會顯示 `Restricted`，表示不允許執行任何腳本。

# 更改執行政策
// 輸入以下指令，將執行政策更改為 `RemoteSigned`（允許本地腳本執行，但遠端下載的腳本需要簽署）
Set-ExecutionPolicy RemoteSigned
```
- 創建新 Vue 專案
```
vue create my-vue-project
cd my-vue-project // 切換到專案目錄
```
- 運行開發伺服器
```
npm run serve
// 這會啟動開發伺服器，通常會在 `http://localhost:8080` 上運行。
```
![upgit_20241108_1731044252.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731044252.png)

### vscode可以安裝的套件

![upgit_20241108_1731044557.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731044557.png)
![upgit_20241108_1731044582.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731044582.png)

### 專案架構
![upgit_20241108_1731054583.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731054583.png)

### 在vue引入bootstrap
- npm安裝：`npm install bootstrap`
- 在main.js引入
```js
// TODO: bootstrap
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.min.js";
```
![upgit_20241108_1731056383.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731056383.png)

![upgit_20241108_1731056404.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731056404.png)


## 增加元件(component)
![upgit_20241108_1731057088.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731057088.png)

![upgit_20241108_1731057655.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731057655.png)

![upgit_20241108_1731057696.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731057696.png)

![upgit_20241108_1731057708.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731057708.png)


## component 通訊
- **不加括號**：僅在事件觸發時執行方法（推薦用法）。
- **加上括號**：在綁定時就立即執行方法（通常不是你想要的行為）。

### props (property的縮寫)
- 他是單向數據流(父元件=>子元件)
- 支援的 prop 值：String、Number、Boolean、Array、Object、Date、Function、Symbol
![upgit_20241111_1731303575.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241111_1731303575.png)

![upgit_20241111_1731307509.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241111_1731307509.png)

![upgit_20241111_1731307551.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241111_1731307551.png)



### $emit 
- 他是單向數據流(子元件=>父元件)
![upgit_20241111_1731310224.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241111_1731310224.png)

![upgit_20241111_1731310543.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241111_1731310543.png)

![upgit_20241111_1731310677.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241111_1731310677.png)

### `provide` 和 `inject`(雙向傳遞)
- 這是vue3 Composition API 的核心，讓你在setup中直接去定義所有的屬性(ref)跟方法。
- 假設你有一個父元件和多個深層嵌套的子元件。你希望所有的子元件都可以存取父元件的資料，但又不想在每一層中都使用 `props` 傳遞，那麼 `provide` 和 `inject` 就非常適合這種情境。
- 要在 Vue 3 中實現雙向資料傳遞，我們可以利用 `provide` 和 `inject`，結合 `ref` 或 `reactive`，使資料在父元件和子元件之間雙向同步更新。
![upgit_20241111_1731315028.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241111_1731315028.png)

- 這邊提供gpt給的範例：
![upgit_20241111_1731315283.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241111_1731315283.png)


## Global vs Local Components
 - 全局
![upgit_20241112_1731390517.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241112_1731390517.png)
- 也可以把它放到local => 把TheHeader.vue放到App.vue

![upgit_20241112_1731390936.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241112_1731390936.png)




## scoped style
- 在 Vue 中，彼此的`<style>`標籤的屬性是會互相影響的。
- `scoped` 是一個用於 `<style>` 標籤的屬性，可以讓樣式**只應用於當前組件**，而不會影響到其他組件的樣式。這有助於防止樣式衝突，保持專案的模組化和可維護性。
![upgit_20241112_1731391986.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241112_1731391986.png)

##   `<component>` 動態元件
- `<component>` 是 Vue 提供的特殊元件，用於根據變數動態渲染不同的子元件。這在需要動態切換不同視圖或元件的情況下特別有用，例如標籤頁、步驟表單、多步驟向導等。
- 建立動態元件
```js
// ActiveGoals.vue
<template>
  <div>
    <h2>Active Goals</h2>
    <p>這裡是 Active Goals 的內容。</p>
  </div>
</template>
```
```js
// ManageGoals.vue
<template>
  <div>
    <h2>Manage Goals</h2>
    <p>這裡是 Manage Goals 的內容。</p>
  </div>
</template>
```
- 在app.vue中使用
![upgit_20241112_1731394081.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241112_1731394081.png)

### Keeping Dynamic Components Alive
- `keep-alive` 是 **Vue** 提供的一個內建元件，用於**緩存動態元件**。
- 當你在應用中使用動態元件（例如透過 `<component>` 標籤來切換不同的子元件）時，使用 `keep-alive` 可以防止元件在切換時被銷毀，而是將其緩存起來，這樣切換回來時就能保留元件的狀態。

## Teleport (Vue3)
- 在某些情況下，你可能需要將元件的內容顯示在應用程式的根級別（或其他特定的 DOM 節點）中，而不被限制在父組件的作用範圍內。常見的應用場景包括：
	- 彈出視窗 (Modal)、通知 (Notification)、提示框 (Tooltip) 等，這些元素通常需要顯示在視窗的最上層，而不應受限於嵌套的父元素的 z-index 或 CSS 影響。
	- 全螢幕覆蓋層，例如遮罩背景層（Backdrop）。

![upgit_20241112_1731397278.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241112_1731397278.png)


## 表單
![upgit_20241113_1731479306.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731479306.png)

### 驗證欄位 
![upgit_20241113_1731479493.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731479493.png)

### 下拉式清單selected
![upgit_20241113_1731480358.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731480358.png)


### checkbox
![upgit_20241113_1731480921.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731480921.png)


### radio
![upgit_20241113_1731480852.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731480852.png)

### 提交
![upgit_20241113_1731481020.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731481020.png)


## 發送HTTP請求
- 建立firebase的realtime database
![upgit_20241113_1731482476.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731482476.png)
- 有兩種方式：
	- axiox
	- fetch
### POST 發送表單
![upgit_20241113_1731483162.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731483162.png)

### GET(通過button觸發)
![upgit_20241113_1731484506.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731484506.png)

```html
<template>
    <div class="container mt-5">
        <form @submit.prevent="saveData" class="p-4 border rounded shadow">
            <!-- Name Input -->
            <div class="mb-3">
                <label for="name" class="form-label">Your Name</label>
                <input type="text" id="name" v-model="formData.name" @blur="validInput" class="form-control" />
                <div v-if="formData.namevalid === 'invalid'" class="text-danger mt-1">請輸入有效username</div>
            </div>

            <!-- Age Input -->
            <div class="mb-3">
                <label for="age" class="form-label">Your Age (Years)</label>
                <input type="number" id="age" v-model.number="formData.age" class="form-control" />
            </div>

            <!-- Dropdown: How did you hear about us? -->
            <div class="mb-3">
                <label for="source" class="form-label">How did you hear about us?</label>
                <select id="source" v-model="formData.source" class="form-select">
                    <option value="Google">Google</option>
                    <option value="Friend">Friend</option>
                    <option value="Advertisement">Advertisement</option>
                </select>
            </div>

            <!-- Checkbox Group: Interests -->
            <div class="mb-3">
                <label class="form-label">What are you interested in?</label>
                <div class="form-check">
                    <input type="checkbox" id="news" value="News" v-model="formData.interests" class="form-check-input" />
                    <label for="news" class="form-check-label">News</label>
                </div>
                <div class="form-check">
                    <input type="checkbox" id="tutorials" value="Tutorials" v-model="formData.interests" class="form-check-input" />
                    <label for="tutorials" class="form-check-label">Tutorials</label>
                </div>
                <div class="form-check">
                    <input type="checkbox" id="nothing" value="Nothing" v-model="formData.interests" class="form-check-input" />
                    <label for="nothing" class="form-check-label">Nothing</label>
                </div>
            </div>

            <!-- Radio Buttons: How do you learn? -->
            <div class="mb-3">
                <label class="form-label">How do you learn?</label>
                <div class="form-check">
                    <input type="radio" id="video" value="Video Courses" v-model="formData.learningMethod" class="form-check-input" />
                    <label for="video" class="form-check-label">Video Courses</label>
                </div>
                <div class="form-check">
                    <input type="radio" id="blogs" value="Blogs" v-model="formData.learningMethod" class="form-check-input" />
                    <label for="blogs" class="form-check-label">Blogs</label>
                </div>
                <div class="form-check">
                    <input type="radio" id="other" value="Other" v-model="formData.learningMethod" class="form-check-input" />
                    <label for="other" class="form-check-label">Other</label>
                </div>
            </div>

            <!-- Submit Button -->
            <button type="submit" class="btn btn-primary w-100">Save Data</button>
        </form>
        <button @click="loadData" type="submit" class="btn btn-success w-100">load Data</button>
    </div>
</template>

<script setup>
import { reactive, ref } from "vue";
const loadedData = ref([]);
const formData = reactive({
    name: "",
    age: 0,
    source: "Google",
    interests: [],
    learningMethod: "Video Courses",
    namevalid: "",
});

const validInput = () => {
    if (formData.name === "") formData.namevalid = "invalid";
    else formData.namevalid = "valid";
    console.log(formData.namevalid);
};

fetch("https://vue-http-demo-f3460-default-rtdb.firebaseio.com/" + "surveys.json", {
    method: "POST",
});

// TODO: 發送表單資料到 Firebase 的函數
const saveData = async () => {
    // 檢查表單是否已填寫
    if (formData.name === "" || formData.age === 0) {
        alert("請填寫所有必填欄位");
        return;
    }
    try {
        const response = await fetch("https://vue-http-demo-f3460-default-rtdb.firebaseio.com/surveys.json", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify(formData),
        });
        if (!response.ok) throw new Error("發送資料失敗！");

        const data = await response.json();
        console.log("表單資料已成功送出", data);
    } catch (e) {
        console.log("錯誤", e);
        alert("發送資料失敗，請稍後再試。");
    }
};

// 從 Firebase 讀取資料
const loadData = async () => {
    try {
        const response = await fetch("https://vue-http-demo-f3460-default-rtdb.firebaseio.com/surveys.json", {
            method: "GET",
            headers: { "Content-Type": "application/json" },
        });
        if (!response.ok) throw new Error("讀取資料失敗！");

        const data = await response.json();
        if (data) {
            // 確保使用 .value 來更新 ref
            loadedData.value = Object.values(data);
            console.log("已載入資料", loadedData.value);
        } else console.log("無資料可載入");
    } catch (error) {
        console.error("錯誤", error);
        alert("讀取資料失敗，請稍後再試。");
    }
};
</script>

<style scoped></style>
```


### 掛載元件時載入數據
- 先查看vue元件的生命週期
![upgit_20241113_1731484737.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731484737.png)

![upgit_20241113_1731485307.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731485307.png)

### loading動畫
- 其實就是設定一個boolen，在適當時間跳true/false。在搭配`<p v-if="...">`
![upgit_20241113_1731486131.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241113_1731486131.png)

## vue router
- 安裝：`npm install vue-router@4`
### 實現nav之間切換
![upgit_20241115_1731659663.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731659663.png)

- main.js
	- 這邊createMemoryHistory要改成createWebHistory
![upgit_20241115_1731659851.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731659851.png)

- App.vue
![upgit_20241115_1731659871.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731659871.png)

- TheNavigation.vue
![upgit_20241115_1731659904.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731659904.png)

### 實現button做頁面切換
![upgit_20241115_1731660052.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731660052.png)

### 設定linkActiveClass
![upgit_20241115_1731660568.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731660568.png)


## Vue Router 中資料如何傳遞
### 動態路由參數 (params)
- main.js
	- 動態路由參數通常用於需要在 URL 中嵌入動態資料的情境，例如 `/users/:userId`。
![upgit_20241115_1731666206.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731666206.png)

![upgit_20241115_1731666271.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731666271.png)

### 使用 查詢參數 (query)
- 查詢參數通常用於傳遞可選的、非必需的資料，格式為 /search?keyword=vue。
![upgit_20241115_1731666562.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731666562.png)

![upgit_20241115_1731666674.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731666674.png)

### 獲補所有路徑
- main.js
![upgit_20241115_1731667018.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731667018.png)

### 使用命名視圖 (Named Views) 渲染多個路由
![upgit_20241115_1731668387.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731668387.png)
- App.vue
![upgit_20241115_1731668442.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731668442.png)


## Pinia
- **Pinia** 是一個輕量級且現代的狀態管理庫
- Pinia 是 Vue 團隊推薦的替代方案，因其擁有更簡單的 API、更好的開發體驗以及與 Vue 3 的更緊密整合。
```
app.use(pinia)
```

### 建立pinia
![upgit_20241115_1731670961.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731670961.png)

### Store
- Store 用於集中管理 Vue.js 應用的全域狀態，適合需要在多個組件間共享的資料。
	- 全域共享資料(例如：使用者登入資訊、權限角色、偏好設定)
	- 跨組件共享狀態(例如：導航欄和設定頁面需要共用的用戶名稱)
	- 跨頁面保存狀態(例如：多步驟表單資料需要在頁面切換間保持)
- 何時不需要 Store？
	- 組件本地狀態(按鈕顯示/隱藏、彈出視窗開關)
	- 短暫存在的資料(通知提示、表單驗證訊息)


## 要學的東西
- Pinia / Vuex（狀態管理）=> pinia
- Vite