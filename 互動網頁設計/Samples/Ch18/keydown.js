var achar = document.getElementById('achar');

achar.addEventListener('keydown', function(e) {
  var msg = document.getElementById('msg');
  msg.textContent = '按鍵：' + e.key;
}, false);


