function showResult() {
  // 宣告一個空陣列用來存放使用者所核取的甜點	
  var result = [];
  var dessert = document.getElementsByName('dessert');  
  // 逐一檢查核取方塊是否有被核取  
  for (var i = 0; i < dessert.length; i++) {	
    // 若核取方塊有被核取，就取得其值並加入陣列 
    if (dessert[i].checked) {
      result.push(dessert[i].value);      
    }
  }    
  window.alert(result);
}