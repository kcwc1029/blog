//RC37 decode 
#include <rc95a.h> 
#define D0 22
#define D1 12   
#define D2 24   
#define D3 94   
#define D4 8    
#define D5 28   
#define D6 90   
#define D7 66   
#define D8 82   
#define D9 74                         
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
   if(com[2]==D0) Serial.print('0');
   if(com[2]==D1) Serial.print('1'); 
   if(com[2]==D2) Serial.print('2'); 
   if(com[2]==D3) Serial.print('3'); 
   if(com[2]==D4) Serial.print('4');       
   
   if(com[2]==D5) Serial.print('5');
   if(com[2]==D6) Serial.print('6'); 
   if(com[2]==D7) Serial.print('7'); 
   if(com[2]==D8) Serial.print('8'); 
   if(com[2]==D9) Serial.print('9');        
  } 
}
//----------------------------------------------------
