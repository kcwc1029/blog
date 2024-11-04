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
