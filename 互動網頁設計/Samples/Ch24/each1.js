var sum = 0;
var arr = [1, 2, 3, 4, 5];

$.each(arr, function(index, value){
  sum += value;
});

window.alert(sum);
