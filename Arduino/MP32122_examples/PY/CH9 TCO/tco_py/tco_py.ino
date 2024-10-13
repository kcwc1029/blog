//tco_py.ino  ur op
#include "SevenSegmentTM1637.h"
int PIN_CLK = 4;   // define CLK pin (any digital pin)
int PIN_DIO = 5;   // define DIO pin (any digital pin)
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);
int tr  =9;
int led =13;
int k1 =12;
int bz =8;
int co=0;
//-----------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  display.begin();
  display.setBacklight(100);
  pinMode(led, OUTPUT);
  pinMode(bz, OUTPUT);
  digitalWrite(bz, LOW);
  pinMode(k1, INPUT);
  digitalWrite(k1, HIGH);
  pinMode(tr, INPUT);
  digitalWrite(tr, HIGH);
  Serial.print('c');
}
//-----------------------------------------------------------
void led_bl()
{
int i;
 for(i=0; i<2; i++)
  {
   digitalWrite(led, HIGH); delay(50);
   digitalWrite(led, LOW); delay(50);
  }
}
//-----------------------------------------------------------
void be()
{
int i;
 for(i=0; i<100; i++)
  {
   digitalWrite(bz, HIGH); delay(1);
   digitalWrite(bz, LOW); delay(1);
  }
 delay(100);
}
//----------------------------------------
void loop()
{
 display.print(co); delay(1000);
 display.clear();   delay(1000);
 co=0; display.print(co);
 led_bl(); be();  be();
 while(1)
  {
   if(digitalRead(tr)==0)
      { be();  led_bl();
        co++;  Serial.print('i');
        display.clear();  display.print(co);
        if(co==9999)
          { be(); be(); be(); co=0; }
        delay(300);
      }
   if(digitalRead(k1)==0)
     { be(); be(); be(); co=0;
       Serial.print('c');
       display.clear();  display.print(co);
     }
  }
}
