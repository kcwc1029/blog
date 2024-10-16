window.addEventListener('load', showEntrytime, false);

function showEntrytime() {
  var entrytime = document.getElementById('entrytime');
  entrytime.textContent = (new Date()).toLocaleString();
};