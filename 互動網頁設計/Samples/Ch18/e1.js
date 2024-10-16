var btn = document.getElementById('btn');
btn.addEventListener('click', showMsg, false);

function showMsg(e) {
  window.alert(e.target.nodeName);
  window.alert(e.type);
}
