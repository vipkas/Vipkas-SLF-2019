#define BUZZER        6
#define SIGNAL_PIN    A0

int distance = 0; 

void setup() {
  Serial.begin(9600);

  pinMode(BUZZER, OUTPUT);
  pinMode(SIGNAL_PIN, INPUT);
}

void loop() {
  int volt = map(analogRead(SIGNAL_PIN), 0, 1023, 0, 5000); 
  
  distance = 0.0001936428309 * volt *volt + 0.06987226424 * volt - 14.32575223;
   
  
  /*if(distance <= 20)
  {
    tone(BUZZER, 100);
    delay(distance * 5);
    noTone(BUZZER);
    delay(distance * 5);
  }
  else
  {
    delay(500);
  }*/
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
