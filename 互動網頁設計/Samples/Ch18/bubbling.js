var a1 = document.getElementById('a1');
var item1 = document.getElementById('item1');
var foods = document.getElementById('foods');

a1.addEventListener('click', function() {
  window.alert('<a> 元素的事件監聽程式1');
}, false);

a1.addEventListener('click', function() {
  window.alert('<a> 元素的事件監聽程式2');
}, false);

item1.addEventListener('click', function() {
  window.alert('<li> 元素的事件監聽程式');
}, false);

foods.addEventListener('click', function() {
  window.alert('<ul> 元素的事件監聽程式');
}, false);