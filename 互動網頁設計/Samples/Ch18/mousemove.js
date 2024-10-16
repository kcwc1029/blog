var region = document.getElementById('region');

region.addEventListener('mousemove', function(e) {
  region.innerHTML = 'screenX/screenY:' + e.screenX + '/' + e.screenY + '<br>'
                   + 'pageX/pageY:' + e.pageX + '/' + e.pageY + '<br>'
				   + 'clientX/clientY:' + e.clientX + '/' + e.clientY + '<br>'
				   + 'offsetX/offsetY:' + e.offsetX + '/' + e.offsetY;
}, false);



