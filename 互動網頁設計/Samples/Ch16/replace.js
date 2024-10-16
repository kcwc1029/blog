// 建立一個新節點，此例為 <li> 元素
var newElm = document.createElement('li');
// 建立一個文字節點，此例的文字內容為 '祥雲龍吟'
var newText = document.createTextNode('祥雲龍吟');
// 將文字節點加入到新節點的子節點
newElm.appendChild(newText);
// 取得新節點要取代的舊節點，此例為第四個 <li> 元素
var replacedElm = document.getElementsByTagName('li')[3];
// 取得要取代之舊節點的父節點，即 <ul> 元素
var parentElm = replacedElm.parentNode;
// 以新節點取代舊節點
parentElm.replaceChild(newElm, replacedElm);