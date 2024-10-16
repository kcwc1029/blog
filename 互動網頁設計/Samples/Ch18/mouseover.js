var fig = document.getElementById('fig');

fig.addEventListener('mouseover', function() {
  fig.src = 'girl2.png';
}, false);

fig.addEventListener('mouseout', function() {
  fig.src = 'girl1.png';
}, false);

