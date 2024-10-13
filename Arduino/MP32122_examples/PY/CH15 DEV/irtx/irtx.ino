//irtx        
#include <IRremote.h>
int led = 13;                                                               
int k1 =12;  
//irtx=D3
IRsend irsend;
//--------------------------------------                                    
void setup() {                                                  
  Serial.begin(9600);                                                       
  pinMode(led, OUTPUT);                                                                                
  pinMode(k1, INPUT); 
  digitalWrite(k1, HIGH);                                
}                                                                           
//-----------------------------------                                       
void led_bl()                                                               
{                                                                           
int i;                                                                      
 for(i=0; i<2; i++)                                                         
  {                                                                         
   digitalWrite(led, HIGH); delay(150);                                     
   digitalWrite(led, LOW);  delay(150);                                     
  }                                                                         
}                            
//-----------------------------------
void ir_tx(int d)
{ 
 led_bl(); 
 if(d==1) irsend.sendNEC(0x02FD807F,32);
 if(d==2) irsend.sendNEC(0x02FD40BF,32);
 if(d==3) irsend.sendNEC(0x02FDC03F,32);
 if(d==4) irsend.sendNEC(0x02FD20DF,32);
 if(d==5) irsend.sendNEC(0x02FDA05F,32);
}
//-------------------------------
void loop()                                                                 
{                                                       
char c;                                                                     
 led_bl(); ir_tx(1);                                                                 
// Serial.print("uart irtx test--RC95:1~5 IR code");                                        
 while(1)                                                                   
  {                                                                         
  if (Serial.available() > 0)                                               
    {                                                                       
     c= Serial.read();              
     if(c=='1') 
      {led_bl(); Serial.print('1'); ir_tx(1);}                            
     if(c=='2')   
      {led_bl(); Serial.print('2'); ir_tx(2);}                  
     if(c=='3')   
      {led_bl(); Serial.print('3'); ir_tx(3);}         
     if(c=='4')   
      {led_bl(); Serial.print('4'); ir_tx(4);}                            
     if(c=='5')   
      {led_bl(); Serial.print('5'); ir_tx(5);}                           
    }
     if(digitalRead(k1)==0) 
      {led_bl(); ir_tx(1); delay(300);}    
 }                                                                          
}          
