

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

## v-bind：插值&綁定屬性(單向綁定)
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

## methods：在Vue中處理數據
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

            <p class="fs-5 fw-bold bg-success text-white py-2 px-3 rounded-pill">{{ outputGoal() }}</p>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    goalA: "this is goal A",
                    goalB: "this is goal B",
                };
            },
            methods: {
                outputGoal() {
                    const randomNum = Math.random();
                    if (randomNum < 0.5) return this.goalA;
                    else return this.goalB;
                },
            },
        });
        app.mount("#user-goal");
    </script>
</html>
```

## v-html：放有包含標籤的內容
- {{物件}}：適用於只單純文字。
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
            <!-- 如果是要給整個html -> v-html -->
            <div class="" v-html="outputHTML()"></div>
        </section>
    </body>
    <script>
        const app = Vue.createApp({
            data() {
                return {
                    goalA: "this is goal A",
                    goalB: "this is goal B",
                };
            },
            methods: {
                outputHTML() {
                    const randomNum = Math.random();
                    if (randomNum < 0.5) return "<p>randomNum < 0.5</p>";
                    else return "<p>randomNum > 0.5</p>";
                },
            },
        });
        app.mount("#user-goal");
    </script>
</html>
```


## v-on：事件監聽
- v-on可以改成@
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

- 如果要做出【鍵盤輸入，同時顯示】之效果。
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

## v-model：雙向綁定指令
![upgit_20241105_1730788434.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241105_1730788434.png)

- `v-model` 本質上是 **將數據綁定到表單元素的值**（即 `v-bind:value`），並且在用戶輸入或選擇表單元素時，自動 **監聽 input 或 change 事件**（相當於 `v-on:input`），將表單元素的值同步回 Vue 的數據中。
- 實作：
	- 輸入框輸入，同時顯示
	- 【reset】按鈕，把資料清除
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

            <!-- TODO: 使用v-model -->
            <input type="text" placeholder="請隨意姓名" v-model="name" />
            <button class="btn btn-danger" v-on:click="reset()">情除</button>

            <hr />
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
                reset() {
                    this.name = "";
                },
            },
        });
        app.mount("#events");
    </script>
</html>
```

## 引入計算屬性(Computed Properties)
- **自動依賴追蹤**：計算屬性會自動追蹤它所依賴的數據，一旦依賴的數據發生變化，計算屬性會自動重新計算。
- **緩存功能**：計算屬性具有緩存機制，只有當依賴的數據改變時，計算屬性才會重新計算。這與方法不同，方法每次調用時都會執行，而計算屬性只在需要時才執行計算。
- **讀取與寫入**：計算屬性可以具有 getter 和 setter。這允許我們在需要時定義計算屬性的寫入操作，使計算屬性不僅可以計算值，還可以設置值。
## 計算屬性 (`computed`) vs 方法 (`methods`)
- **計算屬性 (`computed`)** 更適合於需要多次使用且不頻繁變動的計算場景，具有緩存機制和自動更新優勢。
- **方法 (`methods`)** 更靈活，適合於單次操作或不需要緩存的情境，每次調用會執行完整的計算邏輯。

| 特性        | 計算屬性 (`computed`)           | 方法 (`methods`)         |
| --------- | --------------------------- | ---------------------- |
| **緩存機制**  | 有緩存功能，依賴的數據未改變時返回緩存的結果      | 沒有緩存功能，每次調用都會重新執行      |
| **使用場景**  | 適合需要多次使用的計算結果，並且不頻繁變動的數據    | 適合執行一次性操作或不需要重複計算的情況   |
| **自動更新**  | 當依賴的數據改變時，自動重新計算並更新結果       | 不會自動更新，每次需要調用時重新執行     |
| **性能**    | 性能更佳，當依賴數據未改變時，重複使用計算結果無需重算 | 每次調用都會執行完整的計算邏輯，性能相對較低 |
| **代碼可讀性** | 更簡潔，適合重複引用的計算邏輯             | 適合僅在特定情境下執行的操作         |
| **響應式特性** | 具有響應式追蹤能力，自動追蹤依賴數據          | 無響應式追蹤能力，不會自動隨依賴數據更新   |

## method、compute、watch (這個我做不出範例)
###  `methods`：用於定義函數和事件處理
- `methods` 是用來定義可以被調用的函數，通常用於事件處理或需要手動觸發的操作。
	- 主要用途：響應事件、手動調用的操作、不需要緩存的計算
	- 特點：每次調用 `method`，Vue 都會執行其中的邏輯，沒有緩存。

```javascript
const app = Vue.createApp({
  data() {
    return {
      name: "",
    };
  },
  methods: {
    greet() {
      alert(`Hello, ${this.name}!`);
    },
    getNameLength() {
      return this.name.length;
    }
  }
});
```

在模板中：
```html
<input v-model="name" placeholder="Enter your name">
<button @click="greet">Greet</button>
<p>Name Length (method): {{ getNameLength() }}</p>
```

**說明**：
- 當按下「Greet」按鈕時，`greet` 方法被觸發。
- `getNameLength` 方法可以顯示 `name` 的長度，但每次調用都會重新計算。

---

### `computed`：計算屬性，帶有緩存功能
- `computed` 是一種屬性，但它本質上是一個有緩存的函數，用來處理依賴於其他數據的計算。
- 主要用途：依賴於數據的計算且需要重複使用的場景
- 特點：緩存結果，當依賴的數據未變化時，不會重新計算，提高性能
```javascript
const app = Vue.createApp({
  data() {
    return {
      name: "",
    };
  },
  computed: {
    nameWithLength() {
      return `${this.name} (${this.name.length} characters)`;
    }
  }
});
// 當 `name` 改變時，`nameWithLength` 會重新計算，並返回 `name` 和它的字數。
// 若 `name` 沒有改變，重複訪問 `nameWithLength` 不會重新計算，因為計算結果已被緩存。
```

在模板中：
```html
<input v-model="name" placeholder="Enter your name">
<p>Name with Length (computed): {{ nameWithLength }}</p>
```



### `watch`：監聽數據變化並執行副作用操作
- `watch` 是用來監聽數據變化並在變化時執行回調函數，適合異步操作、處理副作用、或監聽多層數據。
- 主要用途：在數據變化時執行某些操作，例如異步請求或複雜的邏輯
- 特點：監聽指定的數據變化，執行特定的邏輯，不適合處理直接顯示的計算結果
```javascript
const app = Vue.createApp({
  data() {
    return {
      age: 25,
    };
  },
  watch: {
    age(newAge, oldAge) {
      console.log(`Age changed from ${oldAge} to ${newAge}`);
      if (newAge >= 30) {
        alert("You're getting older!");
      }
    }
  }
});
// 當 `age` 改變時，`watch` 會監聽到變化，並打印出 `oldAge` 和 `newAge`。//
// 若 `age` 大於等於 30，會彈出一個警告訊息。
// `watch` 常用於異步操作或複雜邏輯，例如監聽數據變化後發起 API 請求。
```

在模板中：
```html
<input type="number" v-model="age" placeholder="Enter your age">
<p>Your age: {{ age }}</p>
```
## 動態添加CSS
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


## v-if、v-for、v-show
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Vue Course Goals</title>
        <!-- Bootstrap -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH"
            crossorigin="anonymous"
        />
        <!-- VUE -->
        <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
        <style>
            body {
                font-family: "Jost", sans-serif;
            }
            .goal-list {
                background-color: #8ddba4;
                color: #1f1f1f;
                font-weight: bold;
                border-radius: 25px;
            }
        </style>
    </head>
    <body>
        <header class="container mt-4 p-4 bg-success text-white text-center rounded shadow">
            <h1 class="display-5">Vue Course Goals</h1>
        </header>

        <section id="app" class="container mt-5 p-4 bg-light rounded shadow">
            <h2 class="text-success border-bottom pb-2 mb-4">My Course Goals</h2>

            <!-- Input and Button -->
            <div class="input-group mb-3">
                <input type="text" class="form-control" placeholder="Enter a new goal" v-model="enterGoalValue" />
                <button class="btn btn-danger" @click="addGoal()">Add Goal</button>
            </div>

            <!-- TODO: 如果使用v-show，他是【沒達成條件->隱藏】，但還是有出現 -->
            <p class="text-muted" v-show="goals.length===0">v-show --> No goals have been added yet - please start adding some!</p>

            <!-- TODO: v-if 有條件的渲染，未達成條件則不渲染 -->
            <p class="text-muted" v-if="goals.length===0">v-if --> No goals have been added yet - please start adding some!</p>

            <!-- TODO: v-else -->
            <ul class="list-group" v-else>
                <!-- TODO: v-for -->
                <li v-for="(item, index) in goals" class="list-group-item goal-list my-2 text-center">{{item}}-{{index}}</li>
            </ul>
        </section>

        <script>
            Vue.createApp({
                data() {
                    return {
                        enterGoalValue: "",
                        goals: [],
                    };
                },
                methods: {
                    addGoal() {
                        this.goals.push(this.enterGoalValue);
                    },
                },
            }).mount("#app");
        </script>
    </body>
</html>

```