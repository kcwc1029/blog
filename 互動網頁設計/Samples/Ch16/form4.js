function showResult() {
  // 宣告一個空陣列用來存放使用者所選取的甜點	
  var result = [];
  var dessert = document.getElementById('dessert');   
  // 逐一檢查下拉式清單的項目是否有被選取  
  for (var i = 0; i < dessert.length; i++) {	
    // 若項目有被選取，就取得其值並加入陣列 
    if (dessert[i].selected) {
      result.push(dessert[i].value);      
    }
  }    
  window.alert(result);
}