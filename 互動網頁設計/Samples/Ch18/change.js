var URL = document.getElementById('URL');

URL.addEventListener('change', function() {
  newWin = open();
  newWin.location.href = URL.value;
}, false);

