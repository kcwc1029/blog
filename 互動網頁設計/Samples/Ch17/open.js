var myWin = null; 
//開啟新視窗
function openNewWindow() {
  myWin = window.open('new.html', 'myWin', 'height=200, width=400');
}

//關閉新視窗
function closeNewWindow() {
  if (myWin) myWin.close();
}
