// 取得要移除的節點，此例為第四個 <li> 元素
var removeElm = document.getElementsByTagName('li')[3];
// 取得該節點的父節點，即 <ul> 元素
var parentElm = removeElm.parentNode;
// 從父節點移除指定的子節點
parentElm.removeChild(removeElm);