var btn = document.getElementById('btn');
btn.addEventListener('click', showMsg, false);

btn.removeEventListener('click', showMsg, false);

function showMsg() {
  window.alert('Hello, world!');
}
