int led=13; 
int bz=8;                                                                
int trs=33;                                                                
                                                                           
// new Sensor DHT11                                                        
#include "SevenSegmentTM1637.h"                                            
int PIN_CLK = 4;   // define CLK pin (any digital pin)                     
int PIN_DIO = 5;   // define DIO pin (any digital pin)                     
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);                           
                                                                           
#include <DHT11.h>                                                         
DHT11 dht(11);                                                             
float humi,temp;                                                           
int h,t;                                                                   
int ERR;                                                                   
                                                                          
char mess[]="1234";                                                      
                                                                          
void setup()                                                               
{                                                                          
 Serial.begin(9600);                                                       
 Serial.print("DHT11 test:");                                            
 display.begin();                                                          
 display.setBacklight(100);                                                
 display.print(mess);                                                      
 delay(1000); display.clear();                                             
                                                                           
 mess[0]='5'; mess[1]='6';mess[2]='7';mess[3]='8';                         
 display.print(mess);                                                      
 delay(1000); display.clear();                                             
                                                                           
 pinMode(led, OUTPUT);                                                     
 pinMode(bz, OUTPUT);   
 be(); 
}                                                                          
//------------                                                             
void led_bl()                                                              
{                                                                          
int i;                                                                     
 for(i=0; i<2; i++)                                                        
  {                                                                        
   digitalWrite(led, HIGH); delay(50);                                     
   digitalWrite(led, LOW);  delay(50);                                     
  }                                                                        
}                                                                          
//-----------------------------                                            
void be()                                                                  
{                                                                          
int i;                                                                     
 for(i=0; i<100; i++)                                                      
  {                                                                        
   digitalWrite(bz, 1); delay(1);                                          
   digitalWrite(bz, 0); delay(1);                                          
  }                                                                        
}                                                                          
//-------------------------------                                          
void loop()                                                                
{                                                                          
int d, i;                                                                     
char c;
  if((ERR=dht.read(humi, temp))==0)                                        
     {                                                                     
      t=int(temp);                                                         
      h=int(humi);       
//    test only !!! arduino self test run                                                        
//    Serial.print("temp oC:"); Serial.print(t);                                                     
//    Serial.print(" hum %:");  Serial.println(h);     
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              
      d=t/10; mess[0]=d+0x30;                                              
      d=t%10; mess[1]=d+0x30;                                              
      d=h/10; mess[2]=d+0x30;                                              
      d=h%10; mess[3]=d+0x30;                                              
      display.print(mess);                                                 
     }                                                                     
   else                                                                    
     {                                                                     
      Serial.print("Error no:  ");                                         
      Serial.println(ERR);                                                 
     }    
//tx op to xio ....................     
   if (Serial.available() > 0)             
    {                                     
     c=Serial.read();                     
     if(c=='1')   
      {
     Serial.print('1');  //Serial.write(48); show'0'
     Serial.write(t);//binary
     Serial.write(h);//binary    
      }  
    }
   delay(2000);//500  
   led_bl();
//trs trig                                                                          
   if(t>trs) be();                                                                             
}                                                                          
//--------------------------------------------                                                                           
                                                                           
