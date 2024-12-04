// 載入
window.addEventListener("load", () => {
    console.log("頁面已載入完成！");
});

document.addEventListener("DOMContentLoaded", () => {
    console.log("DOM 已完全載入！");
});

// 卸載
window.addEventListener("beforeunload", (event) => {
    event.preventDefault();
    event.returnValue = ""; // 必須設置，否則某些瀏覽器不會提示
});

window.addEventListener("unload", () => {
    console.log("頁面即將卸載！");
});
