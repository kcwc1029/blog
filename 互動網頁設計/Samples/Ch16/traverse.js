var foods = document.getElementById('foods');
var foodsChild = foods.childNodes;
for (var i = 0; i < foodsChild.length; i++)	
  if (foodsChild.item(i).nodeType === 1)
    console.log(foodsChild.item(i).textContent);