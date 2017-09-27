#include <Wire.h>
#include <Adafruit_ADS1015.h>

//addr ==gnd
//sda = 4 = D2 //leonardo 2
//scl = 5 = D1 //leonardo 3

float Voltage = 0.0;
int16_t adc0;
int runpin=8;
Adafruit_ADS1115 ads(0x48);

void setup() {  
  pinMode(runpin,INPUT_PULLUP);
  //make 9 a 'ground'
  pinMode(9,OUTPUT);
  digitalWrite(9,LOW);
  Serial.begin(9600);  
  ads.begin();

}

void loop() {
  
  if (digitalRead(runpin)==LOW){
           Serial.println("running");
       adc0 = ads.readADC_SingleEnded(0);
       Voltage = (adc0 * 0.1875)/1000;
      //Serial.println(adc0);
       Serial.println(Voltage);
    }
  delay(1000);
}
