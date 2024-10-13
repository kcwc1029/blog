#include <rc95a.h>                       
//--------------------------------------------------
int cir =10;
int led = 13;
void setup()
{                
  pinMode(led, OUTPUT); 
  pinMode(cir, INPUT);
  Serial.begin(9600);
}

void led_bl()                                
{                                       
int i;                                  
 for(i=0; i<2; i++)                     
  {                                     
   digitalWrite(led, HIGH); delay(150);
   digitalWrite(led, LOW); delay(150);
  }                                     
}                                                                 
/*-----------------------------------------------------------*/                  
void loop()
{
int c, i;
 while(1) /* loop */                                                            
  {                                                                             
loop:                                                                           
// can do anything...............                                               
                                                                                
// scan IR RC .............                                                     
   no_ir=1; ir_ins(cir); if(no_ir==1) goto loop;                                   
                                                                                
// found IR.............................................................        
   led_bl(); rev();                                                                       
// for(i=0; i<4; i++)    
//   {c=(int)com[i];  Serial.print(c); Serial.print(' '); }  
//  Serial.println();
   delay(300); 
//比對遙控器按鍵碼，數字 1~4，執行動作              
//rx d0~9 ---uart rtx d
   if(com[2]==0) Serial.print('0');
   if(com[2]==1) Serial.print('1'); 
   if(com[2]==2) Serial.print('2'); 
   if(com[2]==3) Serial.print('3'); 
   if(com[2]==4) Serial.print('4');       
   
   if(com[2]==5) Serial.print('5');
   if(com[2]==6) Serial.print('6'); 
   if(com[2]==7) Serial.print('7'); 
   if(com[2]==8) Serial.print('8'); 
   if(com[2]==9) Serial.print('9');        
  } 
}
//----------------------------------------------------
