#include "LedControl.h"
#include <Keyboard.h>
int runpin=8;
int timer=0;
/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 

 */

LedControl lc=LedControl(12,11,10,1);
unsigned long delaytime=5;

void setup() {
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,1);
  /* and clear the display */
  lc.clearDisplay(0);
  pinMode(runpin,INPUT_PULLUP);
  pinMode(9,OUTPUT);
  
  Keyboard.begin();
  
}



void loop() { 

  if (digitalRead(runpin)==LOW){

    /*
int i=1;
    lc.setDigit(0,3,i,false);
    lc.setDigit(0,2,i+1,false);
    lc.setDigit(0,1,i+2,false);
    lc.setDigit(0,0,i+3,false);
     lc.setDigit(0,5,i+4,false);
    lc.setDigit(0,4,i+5,false);
    lc.setDigit(0,1,i+2,false);
    lc.setDigit(0,0,i+3,false);
    delay(delaytime);
  
  lc.clearDisplay(0);
  delay(delaytime);


*/





timer += 1;
int num5 = (timer / 1) % 10;
int num4 = (timer / 10) % 10;
int num3 = (timer / 100) % 10;
int num2 = (timer / 1000) % 10;
int num1 = (timer / 10000) % 10;


  lc.clearDisplay(0);
  delay(delaytime);
    lc.setDigit(0,4,num1,false);
    lc.setDigit(0,3,num2,false);
    lc.setDigit(0,2,num3,false);
    lc.setDigit(0,1,num4,false);
    lc.setDigit(0,0,num5,false);

  delay((1000-delaytime));


if (timer % 300 == 0) {dim();dim();dim(); } 


  }
}


//Hide and Minimize All Mac Windows with Command + Option + H + M

void dim()
{ 
  int j = 60 ;
  while (j>0){
  Keyboard.press(KEY_F1);
  
int n1 = (j / 1) % 10;
int n2 = (j / 10) % 10;


  lc.clearDisplay(0);
  delay(delaytime);
    lc.setDigit(0,6,n1,false);
    lc.setDigit(0,7,n2,false);
  delay((1000-delaytime));
  Keyboard.release(KEY_F1);
  j-=1;
  }

while (j<10){
  
  Keyboard.press(KEY_F2);
  delay(10);
  Keyboard.release(KEY_F2);
  delay(50);
  j+=1;
}

timer += 70;
  
}
