// 取得事件目標元素與事件類型
$("input").on("click", function (e) {
    $(this)
        .after("<p>目標元素：" + e.target + "</p>")
        .after("<p>事件類型：" + e.type + "</p>");
});
