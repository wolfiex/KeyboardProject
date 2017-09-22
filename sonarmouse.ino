#include <Keyboard.h>
#include <Mouse.h>
const int analogPin = A0;
int buttons = 0;
const int clickbtn = 7;
const int runhid = 2;
int buttonState = 0;


int range = 12;               // output range of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2; 
const int mouseButton = 3;    // input pin for the mouse pushButton
const int xmouse = A2;         // joystick X axis
const int ymouse = A1; 
const int yscroll = A3; 
const int xscroll = A0; 


// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
// defines variables
long duration;
int distance;



void setup()
{
  pinMode(clickbtn, INPUT_PULLUP);
  pinMode(runhid,INPUT_PULLUP);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Mouse.begin();
}



void loop()

{
  
  if ( digitalRead(runhid) == LOW) {
    
          //Serial.println("run");
      if ( digitalRead(clickbtn) == LOW) {
          Mouse.click();
          delay(1000);
  }

      int xReading = readAxis(xmouse);
      int yReading = readAxis(ymouse);
      long ysReading = readAxisScroll(yscroll);

      

      Mouse.move(- xReading, yReading, 0);
      delay(responseDelay);

      
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      // Calculating the distance
      distance= duration*0.034/2;
      // Prints the distance on the Serial Monitor
      sonar(distance);

      
  }
  
switch (analogRead(xscroll)) {
    case 0:
         Keyboard.press(KEY_LEFT_CTRL);
         Keyboard.press(KEY_RIGHT_ARROW);
         delay(100);
          Keyboard.releaseAll();
          delay(1000);
      break;
    case 1023:
      Keyboard.press(KEY_LEFT_CTRL);
         Keyboard.press(KEY_LEFT_ARROW);
         delay(100);
          Keyboard.releaseAll();
          delay(1000);
      break;
    //default: 
      // if nothing else matches, do the default
      // default is optional
    //break;
  }


}

//function wheel mouse joystick
int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the rest position threshold, use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}



//function wheel mouse joystick
int readAxisScroll(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, 8);
  long distance=reading-4;
  // return the distance for this axis:

   if (abs(distance) < threshold) {
    distance = 0;
  }
  
Mouse.move(0, 0, -distance);
if (distance < 0 ){
      delay(20*responseDelay);
}

}



//function wheel mouse joystick
int sonar(int distance) {

  if (distance < 40){

    if (distance<12){
      Mouse.move(0, 0, 6*(-13+distance));

  }

  else{
    Mouse.move(0, 0, 1.2*distance-10);
    }

      delay(30*responseDelay);
}
}
