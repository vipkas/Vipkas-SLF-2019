#include <IoTStarterKit_WiFi.h>
#define LIGHT A3
#define TAG_ID "Light"
#define WIFI_SSID   "ICT-LAB-2.4G"
#define WIFI_PASS   "12345678"                        

#define deviceID    "firdauD1566870700803"
#define authnRqtNo  "0o9wjvub5"
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

void setup() 
{
	Serial.begin(9600);
  
  pinMode(LIGHT, INPUT);

	init_iotmakers();
}


void loop()
{
	static unsigned long tick = millis();

  if(g_im.isServerDisconnected() == 1) 
  {
    init_iotmakers();
  }

	if ( ( millis() - tick) > 1000 )
	{
		send_light();
		tick = millis();
 	}

  g_im.loop();
}


int send_light()
{
  int value = analogRead(LIGHT);
  int data = map(value, 0, 1023, 1023, 0);
  
  Serial.print(F("Light : ")); 
  Serial.println(data);
  
	if ( g_im.send_numdata(TAG_ID, (double)data) < 0 ) {
  		Serial.println(F("fail"));  
		return -1;
	}
	return 0;   
}
