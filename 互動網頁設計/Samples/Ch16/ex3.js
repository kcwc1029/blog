function changeColor() {
  var title = document.getElementById('title');
  var radios = document.getElementsByName('color');
  var selectedColor;
  for (var i = 0; i < radios.length; i++) {
	if (radios[i].checked) {
	  selectedColor = radios[i].value;
	  break;
	}
  } 
  title.style.color = selectedColor;
}