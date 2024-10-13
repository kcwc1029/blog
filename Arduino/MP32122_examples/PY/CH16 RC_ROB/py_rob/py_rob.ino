#define  khelp  0x11
#define  kdemo  0x0f
#define  kvc    0x0c
//引用紅外線遙控器解碼程式庫
#include <rc95a.h>                                                              
#define de   200    
#define de2  200                        
int out1=4, out2=5; 
int out3=6, out4=7;   

int cir =10 ; //設定信號腳位
int led = 13; //設定LED腳位
int k1 =12;    //設定按鍵腳位  
int bz=8;     //設定喇叭腳位
unsigned long ti=0;
//--------------------------------------
void setup()//初始化設定
{
  pinMode(out1, OUTPUT);  
  pinMode(out2, OUTPUT);  
  pinMode(out3, OUTPUT);  
  pinMode(out4, OUTPUT);  
  digitalWrite(out1, 0);  
  digitalWrite(out2, 0);  
  digitalWrite(out3, 0);  
  digitalWrite(out4, 0);  
  pinMode(led, OUTPUT);  
  pinMode(k1, INPUT);
  digitalWrite(k1, HIGH);
  
  pinMode(cir, INPUT);
  pinMode(bz, OUTPUT);                                 
  digitalWrite(bz, LOW);  
  Serial.begin(9600);  
}
//-----------------------------------
void led_bl()//LED 閃動                                
{                                       
int i;                                  
 for(i=0; i<2; i++)                     
  {                                     
   digitalWrite(led, HIGH); delay(50);
   digitalWrite(led, LOW); delay(50);
  }                                     
}
//--------------------------  
void be()  //發出嗶聲                                                                    
{                                                                              
int i;                                                                         
 for(i=0; i<100; i++)                                                          
  {                                                                            
   digitalWrite(bz, HIGH); delay(1);                                           
   digitalWrite(bz, LOW); delay(1);                                            
  }                                                                            
delay(100);                                                                    
}        
//---------------------
void stop()//停止                                  
{                                            
  digitalWrite(out1,0);                      
  digitalWrite(out2,0);                      
  digitalWrite(out3,0);                      
  digitalWrite(out4,0);
  led_bl();                      
}      
//-------------------
void go()//前進                                                                     
{                                                                              
digitalWrite(out1,1);                       
 digitalWrite(out2,0);                       
 digitalWrite(out3,0);                       
 digitalWrite(out4,1);                       
 delay(de);                                  
 stop();                                 
}                                                                              
//------------------------------------------                                   
void back()//後退                                                                    
{                                                                          
digitalWrite(out1,0);                       
 digitalWrite(out2,1);                       
 digitalWrite(out3,1);                       
 digitalWrite(out4,0);                       
 delay(de);                                  
 stop();  
}                                                                              
//------------------------------------------                                   
void right()//右轉                                                                  
{                                                                              
  digitalWrite(out1,0);                      
  digitalWrite(out2,1);                      
  digitalWrite(out3,0);                      
  digitalWrite(out4,1);                      
  delay(de2);                                
  stop();                               
}                                                                              
//------------------------------------------                                   
void left()//左轉                                                                    
{                                                                              
  digitalWrite(out1,1);                      
  digitalWrite(out2,0);                      
  digitalWrite(out3,1);                      
  digitalWrite(out4,0);                      
  delay(de2);                                
  stop();                            
}                                                                              
//------------------------------------------                                   
void demo()//展示                                                                    
{                                                                              
 go();    delay(500);                                                          
 back();  delay(500);                                                          
 left();  delay(500);                                                          
 right(); delay(500);                                                          
}
//------------------------
void loop()//主程式迴圈  
{
char k1c;  
int c,i;
 led_bl(); be(); 
 while(1) //無窮迴圈
  { 
loop:     
     k1c=digitalRead(k1); //偵測按鍵
     if(k1c==0) { led_bl(); demo();   led_bl(); }
       
  if (Serial.available() > 0) //偵測串口有信號傳入
    {  c= Serial.read(); //讀取資料                        
     if(c=='1') {  led_bl(); go();   }   
     if(c=='2') {  led_bl(); demo(); } 
     if(c=='f') go();                                                          
     if(c=='b') back();                                                       
     if(c=='l') left();                                                       
     if(c=='r') right();
     if(c=='d') demo();      
   }     
                                                                       
//迴圈掃描是否有遙控器按鍵信號？            
   no_ir=1; ir_ins(cir); if(no_ir==1) goto loop;                                
// 發現遙控器信號，進行轉換
   led_bl(); rev();   
//串列介面顯示解碼結果                                                        
   for(i=0; i<4; i++)    
   {c=(int)com[i]; Serial.print(c); 
    Serial.print(' '); }  
    Serial.println();
    delay(100); 
// action: key0~9  go &  say   
//0~9 RC95 test ............
  if(com[2]==0x12) { Serial.print('f'); go();  } //前進                                                       
  if(com[2]==0x10) { Serial.print('b'); back();} //後退                                                       
  if(com[2]==0x1c) { Serial.print('l'); left();} //左轉                                                      
  if(com[2]==0x15) { Serial.print('r'); right();}//右轉                                                     
  if(com[2]==kdemo){ Serial.print('d'); demo(); }//展示
  
  if(com[2]==khelp){ Serial.print('h'); }
  if(com[2]==kvc)  { Serial.print('v'); act();}
//10 fn  
  if(com[2]==0)  Serial.print('A');     
  if(com[2]==1)  Serial.print('B');                                                         
  if(com[2]==2)  Serial.print('C');                                                         
  if(com[2]==3)  Serial.print('D');                                                         
  if(com[2]==4)  Serial.print('E');                                                       
  if(com[2]==5)  Serial.print('F');    
  if(com[2]==6)  Serial.print('G'); 
  if(com[2]==7)  Serial.print('H');                                                    
  if(com[2]==8)  Serial.print('I'); 
  if(com[2]==9)  Serial.print('J');
 }//loop 
}
//---------------------
void act()
{
char c;  
//wait command ....
 while(1)
  {
   if (Serial.available() > 0) //偵測串口有信號傳入，則語音合成輸出
   c=Serial.read();  break;
  } 
 if(c=='f') go();                                                          
 if(c=='b') back();                                                       
 if(c=='l') left();                                                       
 if(c=='r') right();
 if(c=='d') demo();
}
//---------------------
