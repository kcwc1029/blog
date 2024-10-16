$('#whichkey').on('mousedown', function(e) {
  $('#log').text(e.type + '：' +  e.which);
});