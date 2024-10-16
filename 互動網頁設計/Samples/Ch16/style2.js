// 當指標移到標題1時，就套用hot類別樣式 (即紅底白字)
function change() {
  var msg = document.getElementById('msg');
  msg.className = 'hot';
}

//當指標離開標題1時，就移除樣式 (即恢復成預設樣式)
function restore() {
  var msg = document.getElementById('msg');
  msg.className = '';
}
