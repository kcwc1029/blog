## EECharts.js 套件引入
- [jsDelivr](https://www.jsdelivr.com/package/npm/echarts)

## 製作第一個eChart
```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>ECharts</title>
        <!-- ECharts CDN -->
        <script src="https://cdn.jsdelivr.net/npm/echarts@5.5.1/dist/echarts.min.js"></script>
    </head>
    <body>
        <div id="main"></div>
        <script type="text/javascript">
            let myChart = echarts.init(document.getElementById("main"), null, {
                // 初始化大小
                width: 1000,
                height: 400,
            });

            // 數據內容
            var option = {
                title: {
                    text: "感知學習與人機合作實驗室 -- ECharts 示範",
                    left: "center", // 將標題置中
                },
                tooltip: {},
                xAxis: {
                    data: ["01月", "02月", "03月", "04月", "05月", "06月", "07月", "08月", "09月", "10月", "11月", "12月"],
                },
                yAxis: {},
                series: [
                    {
                        name: "每月聚餐次數",
                        type: "bar",
                        data: [5, 20, 36, 10, 10, 20, 15, 25, 30, 18, 28, 33], // 補充完整的數據
                    },
                ],
            };

            // 顯示圖表
            myChart.setOption(option);
        </script>
    </body>
</html>
```

![upgit_20241104_1730704847.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241104_1730704847.png)


- 稍微修正，分成html跟JS
```html
<!DOCTYPE html>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>ECharts</title>
        <!-- ECharts CDN -->
        <script src="https://cdn.jsdelivr.net/npm/echarts@5.5.1/dist/echarts.min.js"></script>
    </head>
    <body>
        <div id="chart"></div>
    </body>
    <script src="./js/index.js"></script>
</html>
```
```js
let chart = document.getElementById("chart");
// 設定CSS大小
chart.setAttribute("style", "height: 30rem; width: 100%;");

// 初始化圖表
let myChart = echarts.init(chart, null);


// 數據內容
var option = {
    title: {
        text: "感知學習與人機合作實驗室 -- ECharts 示範",
        left: "center", // 將標題置中
    },
    tooltip: {},
    xAxis: {
        data: ["01月", "02月", "03月", "04月", "05月", "06月", "07月", "08月", "09月", "10月", "11月", "12月"],
    },
    yAxis: {},
    series: [
        {
            name: "每月聚餐次數",
            type: "bar",
            data: [5, 20, 36, 10, 10, 20, 15, 25, 30, 18, 28, 33], // 補充完整的數據
        },
    ],
};

// 顯示圖表
myChart.setOption(option);
```

## 初始化
- 需要在 HTML 中先定義一個節點，並且通過 CSS 使得該節點具有寬度和高度。
- 初始化的時候，傳入該節點，圖表的大小預設即為該節點的大小。
```js
let chart = document.getElementById("chart");
// 設定CSS大小
chart.setAttribute("style", "height: 30rem; width: 100%;");

// 初始化圖表
let myChart = echarts.init(chart, null);
window.addEventListener("resize", function () {
    myChart.resize();
});

// 數據內容
var option = {
    title: {
        text: "感知學習與人機合作實驗室 -- ECharts 示範",
        left: "center", 
    },
    tooltip: {},
    xAxis: {
        data: ["01月", "02月", "03月", "04月", "05月", "06月", "07月", "08月", "09月", "10月", "11月", "12月"],
    },
    yAxis: {},
    series: [
        {
            name: "每月聚餐次數",
            type: "bar",
            data: [5, 20, 36, 10, 10, 20, 15, 25, 30, 18, 28, 33], 
        },
    ],
};

myChart.setOption(option); // 顯示圖表
```

## 設定樣式

### 更改主題顏色(theme)
- 深色模式：dark

```js
let chart = document.getElementById("chart");
chart.setAttribute("style", "height: 30rem; width: 100%;"); // 設定CSS大小

// 初始化圖表
let myChart = echarts.init(chart, "dark"); // 設定theme
window.addEventListener("resize", function () {
    myChart.resize();
});

// 數據內容
var option = {
    title: {
        text: "感知學習與人機合作實驗室 -- ECharts 示範",
        left: "center",
    },
    tooltip: {},
    xAxis: {
        data: ["01月", "02月", "03月", "04月", "05月", "06月", "07月", "08月", "09月", "10月", "11月", "12月"],
    },
    yAxis: {},
    series: [
        {
            name: "每月聚餐次數",
            type: "bar",
            data: [5, 20, 36, 10, 10, 20, 15, 25, 30, 18, 28, 33],
        },
    ],
};

myChart.setOption(option); // 顯示圖表
```

- 如果要使用其他主題
	- 先查看[主题编辑器 - Apache ECharts](https://echarts.apache.org/zh/theme-builder.html)
	- ![upgit_20241104_1730706273.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241104_1730706273.png)
	- ![upgit_20241104_1730706396.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241104_1730706396.png)


## 數據集(dataSet)
- 有2種設定方式
- 方式1：在series設定
```js
option = {
    title: {
        text: "感知學習與人機合作實驗室 -- ECharts 示範",
        left: "center",
    },
    xAxis: {
        type: "category",
        data: ["Matcha Latte", "Milk Tea", "Cheese Cocoa", "Walnut Brownie"],
    },
    yAxis: {},
    series: [
        {
            type: "bar",
            name: "2015",
            data: [89.3, 92.1, 94.4, 85.4],
        },
        {
            type: "bar",
            name: "2016",
            data: [95.8, 89.4, 91.2, 76.9],
        },
        {
            type: "bar",
            name: "2017",
            data: [97.7, 83.1, 92.5, 78.1],
        },
    ],
};
```

- 方式2：在datasts設定(較推薦)
```js
option = {
    title: {
        text: "感知學習與人機合作實驗室 -- ECharts 示範",
        left: "center",
    },
    dataset: {
        // 提供一份数据。
        source: [
            ["product", "2015", "2016", "2017"],
            ["Matcha Latte", 43.3, 85.8, 93.7],
            ["Milk Tea", 83.1, 73.4, 55.1],
            ["Cheese Cocoa", 86.4, 65.2, 82.5],
            ["Walnut Brownie", 72.4, 53.9, 39.1],
        ],
    },
    // 在去設定他的series
    series: [{ type: "bar" }, { type: "bar" }, { type: "bar" }],
    xAxis: { type: "category" },
    yAxis: {},
};
```

## 其餘部分
- 他其實就是option這個東西在改而以。
- [Examples - Apache ECharts](https://echarts.apache.org/examples/zh/index.html)








