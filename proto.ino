#include <Keyboard.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>

int runpin=8;
int thresh =60;
//addr ==gnd
//sda = 4 = D2 //leonardo 2
//scl = 5 = D1 //leonardo 3
Adafruit_ADS1115 ads(0x48);
float Voltage = 0.0;

void setup(void) 
{
  Keyboard.begin();
  pinMode(runpin,INPUT_PULLUP);
  pinMode(9,OUTPUT);
  Serial.begin(9600);  
  ads.begin();
}

void loop(void) 
{
  if (digitalRead(runpin)==LOW){
  int16_t adc0;  // we read from the ADC, we have a sixteen bit integer as a result
  adc0 = ads.readADC_SingleEnded(0);
  adc0=adc0/250;

  if (adc0 > thresh){
  Serial.println(adc0);
  
    if (adc0 > 99){release();Keyboard.press('h');Keyboard.release('h');}
    else if (adc0 < 89) {release();Keyboard.press('.');Keyboard.release('.');}
    else if (adc0 < 92){release();Keyboard.press('e');Keyboard.release('e');}
    else if (adc0 < 95 ){release();Keyboard.press('o');Keyboard.release('o');}
    else if (adc0 < 99){release();Keyboard.press('l');Keyboard.release('l');}  

  //delayMicroseconds(1500);
  delay(200);
  }


  
  }
}



void release()
{
   while (ads.readADC_SingleEnded(0) > thresh*250){
    delayMicroseconds(500);
     
   }
   return false;
}
