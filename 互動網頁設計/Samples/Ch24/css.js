/* 繫結 <h1> 元素的mouseover事件與事件處理程式 */
$('h1').on('mouseover', function(){
  $(this).css({'color' : 'red', 'text-shadow' : 'gray 3px 3px'});
});

/* 繫結 <h1> 元素的mouseout事件與事件處理程式 */
$('h1').on('mouseout', function(){
  $(this).css({'color' : 'black', 'text-shadow' : 'none'});
});
