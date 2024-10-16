function addListItem(listId) {
  let newItemText = prompt('輸入新項目文字');  
  // 找到指定的清單
  const list = document.getElementById(listId);  
  // 建立一個新的清單項目
  const newItem = document.createElement('li');
  newItem.textContent = newItemText;  
  // 將新項目添加到清單中
  list.appendChild(newItem);
}