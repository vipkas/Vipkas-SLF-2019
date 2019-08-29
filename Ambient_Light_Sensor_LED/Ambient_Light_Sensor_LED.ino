#define LIGHT A3
#define LED A0

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(LIGHT, INPUT);
}

void loop() {

  int value = analogRead(LIGHT);

  int data = map(value, 0, 1023, 1023, 0);

  Serial.print("LIGHT : ");
  Serial.println(data);
  analogWrite(LED, value);
  delay(1000);
}
