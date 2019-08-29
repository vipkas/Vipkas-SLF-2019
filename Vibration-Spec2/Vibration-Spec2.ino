#define sensor A1
#define touch 1

#include <IoTStarterKit_WiFi.h>
#define TAG_ID "Vibration"
#define WIFI_SSID   "ICT-LAB-2.4G"
#define WIFI_PASS   "12345678"                        

#define deviceID    "firdauD1566951696016"
#define authnRqtNo  "5x1267166"
#define extrSysID   "OPEN_TCP_001PTL001_1000007608"  

IoTMakers g_im;

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
  
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  init_iotmakers();
}

void loop() {
  
  int value = analogRead(sensor);
  
  //int digitaltouch;
  //int analogtouch;
 
  /*if (analogRead(sensor)>0)
  {
    Serial.println("TOUCH");
    Serial.print("Measured : ");
    Serial.println(analogRead(sensor));
  }
  else
  {
    Serial.println("-----");
  }*/
  
  Serial.println("TOUCH");
  Serial.print("Measured : ");
  Serial.println(analogRead(sensor));
  delay(700);
  if ( g_im.send_numdata(TAG_ID, (double)analogRead(sensor)) < 0 ) {
      Serial.println(F("fail"));  
    return -1;
  }
  return 0; 
  
}
