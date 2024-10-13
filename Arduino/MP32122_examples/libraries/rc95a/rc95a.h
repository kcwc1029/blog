#include <Arduino.h>  
#define RLEN  32                         
unsigned hid[RLEN];
unsigned char  fa[]={1,2,4,8,16,32,64,128};
unsigned char  com[4];
char no_ir=1;

void deli() { delayMicroseconds(100); }

void rev()                                                                  
{
char   d,i, j;
  for(i=0;i<32;i++)                                                    
   {                                                                  
    if(hid[i]<10) hid[i]=0; else hid[i]=1;
   }                                                                   
                                                                       
 for(j=0; j<4; j++)                                                    
  {                                                                    
   d=0;                                                                
   for(i=0; i<8; i++)                                                  
     d+=fa[i]*hid[8*j+i];                                              
   com[j]=d;                                                           
  }                                                                    
}  
//------------------------------------------------------------------
void ir_ins(int ir)                                                           
{                                                                       
byte c, i,in;                                                           
   no_ir=1;   in=digitalRead(ir);                                       
   if (in==1) return;                                                   
/* HI--> LO ...start.......*/                                           
   while(1)                                                             
    {                                                                   
     deli();                                                            
     in=digitalRead(ir);                                                
     if (in==0)                                                         
      {                                                                 
       for(i=0; i<80; i++) deli();                                      
       while(1) { deli();                                               
                  in=digitalRead(ir);                                   
                  if (in==0) goto go; // found IR                       
                   else  return;                                        
                }                                                       
      }                                                                 
    }                                                                   
//............................................                          
go:                                                                 
                                          
c=0; while(1) { deli(); c++; in=digitalRead(ir);                        
if (in==1) break;  if (c>=100)  return;}                                
                                                                        
c=0; while(1) { deli(); c++; in=digitalRead(ir);                        
if (in==0) break;  if (c>=100)  return;}                                
                                                                        
/* test bit start.............*/                                        
  for(i=0;i<32;i++) /* 8 bit */                                         
   {                                                                    
c=0; while(1)  { deli(); c++; in=digitalRead(ir);                       
if (in==1) break; if (c>=30) return;}                                   
                                                                        
c=0; while(1)  { deli(); c++; in=digitalRead(ir);                       
if (in==0) break; if (c>=30) return;}                                   
    hid[i]=c;                                                           
   }                                                                              
                                            
  no_ir=0;                                                              
}                                                                       
/*-----------------------------------------------------------*/         
