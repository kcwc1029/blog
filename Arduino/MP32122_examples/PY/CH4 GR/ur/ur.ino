//ur                                                                                                     
int led = 13;                                                               
int k1 =7;                                                                                                                                   
//--------------------------------------                                    
void setup() {                                                  
  Serial.begin(9600);                                                       
  pinMode(led, OUTPUT);                                                                                
  pinMode(k1, INPUT); digitalWrite(k1, HIGH);                                
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
void loop()                                                                 
{                                                       
char c;                                                                     
 led_bl();                                                                  
 Serial.print("uart test : ");                                        
 while(1)                                                                   
  {                                                                         
  if (Serial.available() > 0)                                               
    {                                                                       
     c= Serial.read();                                                      
     if(c=='1')   {Serial.print('1');led_bl();}                            
     if(c=='2')   {Serial.print('2');led_bl();led_bl(); }                  
     if(c=='3')   {Serial.print('3');led_bl();led_bl(); led_bl();}         
    }
     if(digitalRead(k1)==0) {Serial.print('1');led_bl(); delay(300);}                                                               
     
 }                                                                          
}          
