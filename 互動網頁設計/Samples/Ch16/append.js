// 建立一個新節點，此例為 <li> 元素
var newElm = document.createElement('li');
// 建立一個文字節點，此例的文字內容為 '祥雲龍吟'
var newText = document.createTextNode('祥雲龍吟');
// 將文字節點加入到新節點的子節點
newElm.appendChild(newText);
// 取得要加入新節點的位置，此例為 <ul> 元素
var position = document.getElementsByTagName('ul')[0];
// 將新元素加入到 <ul> 元素的最後一個子節點
position.appendChild(newElm);