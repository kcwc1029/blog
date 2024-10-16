window.addEventListener('load', function() {
  var timer = window.setInterval(function() {
    var clock = document.getElementById('clock');
	clock.textContent = (new Date()).toLocaleString();
  }, 1000);
  
  var btn = document.getElementById('btn');
  btn.addEventListener('click', function() {
    window.clearInterval(timer);
  }, false);
}, false);




