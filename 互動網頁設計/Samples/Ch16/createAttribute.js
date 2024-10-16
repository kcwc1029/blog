// 建立一個屬性節點，此例為type屬性
var type = document.createAttribute('type');
// 將屬性節點的值設定為 'circle'，即空心圓點
type.value = 'circle';
// 取得屬性節點要加入的元素節點，此例為 <ul> 元素
var list = document.getElementsByTagName('ul')[0];
// 將屬性節點加入指定的元素節點
list.setAttributeNode(type);


