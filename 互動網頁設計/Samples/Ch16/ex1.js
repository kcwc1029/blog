function toggleElementVisibility(elementId, buttonId) {
  const element = document.getElementById(elementId);
  const button = document.getElementById(buttonId);

  if (element.style.display === 'none') {
    element.style.display = 'block';
    button.textContent = '隱藏元素';
  } 
  else {
    element.style.display = 'none';
    button.textContent = '顯示元素';
  }
}