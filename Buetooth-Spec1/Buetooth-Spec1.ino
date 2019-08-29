#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(3, 2); // RX, TX
//int LED = 13; 
int Data; 
int redPin = 11; 
int greenPin = 10; 
int bluePin = 9;

int LED_RED[3]    = {255, 0, 0};
int LED_ORANGE[3] = {255, 165, 0};
int LED_YELLOW[3] = {255, 255, 0};
int LED_GREEN[3]  = {0, 0, 255};
int LED_BLUE[3]   = {0, 255, 0};
int LED_AQUA[3]   = {0, 255, 255};
int LED_PULPLE[3] = {80, 0, 80};

void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("wait for command...");
  Bluetooth.println("Send 1 to turn on the LED. Send 0 to turn Off");
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT);

}

void setColor(int color[3])
{
  analogWrite(redPin,   color[0]); 
  analogWrite(greenPin, color[1]); 
  analogWrite(bluePin,  color[2]);
}

void loop() {
  if (Bluetooth.available()){ 
    Data=Bluetooth.read();
    if(Data=='1'){  
      setColor(LED_GREEN);
      Serial.println("LED On!");
      Bluetooth.println("LED On!");
    }
    else if(Data=='0'){
       setColor(LED_BLUE);
       Serial.println("LED Off!");
       Bluetooth.println("LED Off ! ");
    }
    else{;}
  }
delay(100);
}
