#include <OneWire.h>  
int period = 2000;
unsigned long time = 0;

OneWire ds(2); // Create OneWire Object Connected to Pin 2
void setup() {
  Serial.begin(9600);
}

void loop() {
  byte i;
  byte present = 0;

  byte data[12];
  byte addr[8];
  float Temp;

  if (!ds.search(addr)) { // check we are really using a DS18B20
    ds.reset_search();
    return;
  }
  
  ds.reset(); //reset value to 85 derajat C
  ds.select(addr); // select DS18B20
  ds.write(0x44,1); // start conversion, with parasite power on at the end
  time = millis();
  while(millis() < time + period){
    
  present = ds.reset();
  ds.select(addr); //
  ds.write(0xBE); // Read Scratchpad
  }
  for (i = 0; i < 9; i++) { // Clean up the values ​​from the sensors and place them in the array in order
    data[i] = ds.read();
  }

  Temp=(data[1]<<8)+data[0];// geser sebanyak 16(2 pangkat 8)
  Temp=Temp/16;
  
  // Celsius
  Serial.print("C=");
  Serial.print(Temp);
  Serial.print(", ");
  // 섭씨 출력

  // Convert "Celsius" to "Fahrenheit"
  Temp=Temp*1.8+32;

  // Celsius
  Serial.print("F=");
  Serial.print(Temp);
  Serial.println(" ");  
}
