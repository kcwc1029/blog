var source = document.getElementById('source');
var textContentOutput = document.getElementById('textContentOutput');
var innerTextOutput = document.getElementById('innerTextOutput');
textContentOutput.value = source.textContent;
innerTextOutput.value = source.innerText;