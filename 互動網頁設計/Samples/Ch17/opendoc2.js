var btn = document.getElementById('btn');
btn.addEventListener('click', function() {
  //開啟新的標籤頁
  var newWin = window.open('', 'newWin');
  //在新的標籤頁開啟新文件
  newWin.document.open('text/html');
  //在新文件中顯示此字串
  newWin.document.write('這是新的HTML文件');
  //關閉新文件資料流
  newWin.document.close();
}, false);