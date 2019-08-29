
//#define sensor A1
//#define touch 1

#include <IoTStarterKit_WiFi.h>
#include <Wire.h>
#define TAG_ID "Gyro"
#define WIFI_SSID   "ICT-LAB-2.4G"
#define WIFI_PASS   "12345678"                        

#define deviceID    "firdauD1566951696016"
#define authnRqtNo  "5x1267166"
#define extrSysID   "OPEN_TCP_001PTL001_1000007608"  

IoTMakers g_im;

const int MPU = 0x68;
int16_t tmp;

void init_iotmakers()
{  
  while(1)
  {
    Serial.print(F("Connect to AP..."));
    while(g_im.begin(WIFI_SSID, WIFI_PASS)<0) { 
      Serial.println(F("retrying."));
      delay(1000);
    }
    Serial.println(F("success"));
    
    g_im.init(deviceID, authnRqtNo, extrSysID); 
    
    Serial.print(F("Connect to platform... "));
    while ( g_im.connect() < 0 ){
      Serial.println(F("retrying."));
      delay(1000);
    }
    Serial.println(F("success"));
   
    Serial.print(F("Auth... "));
    if(g_im.auth_device() >= 0) {
      Serial.println(F("success "));
      return;
    }
    Serial.println(F("fail"));
  }
}

void setup() {
  init_iotmakers();
  Serial.begin(9600);
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU);
  Wire.write(0x1B);
  Wire.write(0xF8);
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU);
  Wire.write(0x1C);
  Wire.write(0xF8);
  Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);

  tmp = Wire.read() << 8 | Wire.read();
  

  
  

  Serial.print("temp : ");
  Serial.print(tmp);
  Serial.println();
  Serial.println();
  delay(1000);
  if ( g_im.send_numdata(TAG_ID, (double)tmp) < 0 ) {
      Serial.println(F("fail"));  
    return -1;
  }
  return 0; 
}
