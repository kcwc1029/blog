try {
    let arr = null;
    arr.push(1); // 會拋出錯誤
} catch (error) {
    console.log("錯誤名稱：" + error.name); // 錯誤名稱：TypeError
    console.log("錯誤訊息：" + error.message); // 錯誤訊息：Cannot read properties of null (reading 'push')
    console.log("錯誤堆疊：" + error.stack); // 詳細錯誤堆疊資訊
}
