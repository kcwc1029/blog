var btn = document.getElementById('btn');
btn.addEventListener('click', function() {
  showMsg('Hello, world!');
}, false);

function showMsg(msg) {
  window.alert(msg);
}
