function showResult() {
  // 宣告一個空字串用來存放使用者所核取的甜點	
  var result = '';
  var dessert = document.getElementsByName('dessert');  
  // 逐一檢查選擇鈕是否有被核取  
  for (var i = 0; i < dessert.length; i++) {	
    // 若選擇鈕有被核取，就取得其值並跳出迴圈 
    if (dessert[i].checked) {
      result = dessert[i].value;
      break;	  
    }
  }    
  window.alert(result);
}