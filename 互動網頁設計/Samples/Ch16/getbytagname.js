var foods = document.getElementsByTagName('li'); 
for (var i = 0; i < foods.length; i++)
  console.log(foods.item(i).textContent);
