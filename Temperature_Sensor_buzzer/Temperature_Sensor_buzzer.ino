#include <OneWire.h>
int BUZZER = 6;  

OneWire ds(2); // 2번 핀에 연결된 OneWire 개체 생성

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  byte i;
  byte present = 0;

  byte data[12];
  byte addr[8];
  float Temp;

  if (!ds.search(addr)) {
    ds.reset_search();
    return;
  }
  
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); 
  delay(1000);

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); 

  for (i = 0; i < 9; i++) { 
    data[i] = ds.read();
  }

  Temp=(data[1]<<8)+data[0];
  Temp=Temp/16;
  
  // Celsius
  Serial.print("C=");
  Serial.print(Temp);
  Serial.print(", ");
 
   if (Temp>30)
{tone(BUZZER,400);}
else
{noTone (BUZZER);}

  // Convert "Celsius" to "Fahrenheit"
  Temp=Temp*1.8+32;

  // Celsius
  Serial.print("F=");
  Serial.print(Temp);
  Serial.println(" ");  

 

}
