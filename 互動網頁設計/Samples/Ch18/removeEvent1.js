var btn = document.getElementById('btn'); 
btn.onclick = showMsg;

btn.onclick = null;

function showMsg() {
  window.alert('Hello, world!');
}
