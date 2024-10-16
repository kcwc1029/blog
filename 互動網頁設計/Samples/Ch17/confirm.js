var myform = document.getElementById('myform');
myform.addEventListener('submit', function(e) {
  if (!window.confirm('確定要提交表單？')) 
    e.preventDefault();
}, false);

