var myform = document.getElementById('myform');
var agree = document.getElementById('agree');
var msg = document.getElementById('msg');
myform.addEventListener('submit', function(e) {	
  if (!agree.checked) {
	msg.style.color = 'red';  
    msg.textContent = '你必須核取「我同意合約」';
	e.preventDefault();
  }
}, false);

