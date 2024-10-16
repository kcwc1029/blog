var btn = document.getElementById('btn');
btn.addEventListener('click', function() {
  //開啟新的HTML文件
  document.open('text/html');
  //在新文件中顯示此字串
  document.write('這是新的HTML文件');	
  //關閉新文件資料流
  document.close();
}, false);

