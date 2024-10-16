var num = document.getElementById('num');
num.addEventListener('blur', checkNum, false);

function checkNum() {
  var msg = document.getElementById('msg');
  if (this.value.length != 8)
    msg.textContent = '注意！會員編號必須是8個字元';
  else
    msg.textContent = '';
}
