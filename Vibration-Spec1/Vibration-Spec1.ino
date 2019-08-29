#define sensor A1
#define touch 1

void setup() {
  
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int digitaltouch;
  int analogtouch;
 
  if (analogRead(sensor)>0)
  {
    Serial.println("TOUCH");
    Serial.print("Measured : ");
    Serial.println(analogRead(sensor));
  }
  else
  {
    Serial.println("-----");
  }
  delay(700);
  
}
