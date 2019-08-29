#include <Servo.h>
Servo myServo;
int angle = 0;
static unsigned long tit;
void setup() {
  Serial.begin(9600);
  myServo.attach(3);
}

void loop() {
  // scan from 0 to 180 degrees
  tit = millis();
  //static unsigned long tit2;
  for(int i=0;i<10;i++)
  {
    for(angle = 0; angle < 180; angle++) 
  { 
    myServo.write(angle); 
    delay(15); 
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--) 
  { 
    myServo.write(angle); 
    delay(10);
  } 
  }
  Serial.println(millis()-tit);
  

}
