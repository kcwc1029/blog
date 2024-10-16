var miliseconds = 0, seconds = 0;
var stay = document.getElementById('stay');
stay.value = '0';

window.addEventListener('load', showStayTime, false);

function showStayTime() {
  if (miliseconds >= 9) {
    miliseconds = 0;
    seconds += 1;
  }
  else miliseconds += 1;
  stay.value = seconds + '.' + miliseconds;
  setTimeout('showStayTime()', 100);
}



