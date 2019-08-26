// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to GPIO4
//#define ONE_WIRE_BUS 4

OneWire oneWire(2);
float tempC;

// declare as sensor referenec by passing oneWire reference to Dallas Temperature. 

DallasTemperature sensors(&oneWire);

DeviceAddress tempSensor = { 0x28, 0xE4, 0x6C, 0x41, 0x0B, 0x00, 0x00, 0x75 };

void setup(void){
  Serial.begin(9600);
  
}

void loop(void){ 

  sensors.setResolution(tempSensor, 9);
  Serial.print("Sensor Resolution: ");
  Serial.println(sensors.getResolution(tempSensor), DEC); 
  Serial.println();
  
  sensors.requestTemperaturesByAddress(tempSensor); 
  tempC = sensors.getTempC(tempSensor);
  
  Serial.print("Temp C: ");
  Serial.print(tempC,5); 
  delay(1000);
  Serial.println();
  Serial.println();

  sensors.setResolution(tempSensor, 12);
  Serial.print("Sensor Resolution: ");
  Serial.println(sensors.getResolution(tempSensor), DEC); 
  Serial.println();
  
  sensors.requestTemperaturesByAddress(tempSensor); 
  tempC = sensors.getTempC(tempSensor);
  
  Serial.print("Temp C: ");
  Serial.print(tempC,5); 
  delay(1000);
  Serial.println();
  Serial.println();
}
