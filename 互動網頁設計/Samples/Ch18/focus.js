var num = document.getElementById('num');
var msg = document.getElementById('msg');
msg.style.color = 'red';  

num.addEventListener('focus', function() {
  msg.textContent = '會員編號是8個字元';
}, false);

num.addEventListener('blur', function() {  
  if (this.value.length === 8)	
    msg.textContent = '';
  else
    msg.textContent = '注意！會員編號必須是8個字元';
}, false);

