// 當指標移到標題1時，就變成紅底白字
function change() {
  var msg = document.getElementById('msg');
  // 將前景色彩設定為白色
  msg.style.color = 'white';
  // 將背景色彩設定為紅色
  msg.style.backgroundColor = 'red';
}

//當指標離開標題1時，就恢復成預設樣式
function restore() {
  var msg = document.getElementById('msg');
  // 清除前景色彩 (即恢復成預設樣式)
  msg.style.color = '';
  // 清除背景色彩 (即恢復成預設樣式)
  msg.style.backgroundColor = '';
}
