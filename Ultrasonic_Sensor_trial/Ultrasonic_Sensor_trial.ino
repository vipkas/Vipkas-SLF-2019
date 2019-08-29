#define trigPin 13                 
#define echoPin 12                
#define BUZZER 6

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup()
{
  Serial.begin (9600);       
     
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);   

  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  //LED color
  setColor(255, 0, 0);
  delay(1000);
  setColor(255, 140, 0);
  delay(1000);
  setColor(255, 255, 80);
  delay(1000);
  setColor(127, 255, 0);
  delay(1000);
  setColor(0, 0, 205);
  delay(1000);
  setColor(111, 0, 0);
  delay(1000);
  setColor(138, 43, 226);
  delay(1000);

  //Distance
  long duration, distance;                   
  digitalWrite(trigPin, LOW);                
  delayMicroseconds(2);                
  digitalWrite(trigPin, HIGH);            
  delayMicroseconds(10);               


  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);   

  distance = duration * 17 / 1000;
  
  if (distance >= 200 || distance <= 0)       
  {
    Serial.println("Unable to measure distance");
  }
  else                                           
  {
    Serial.print(distance);                      
    Serial.println(" cm");    

    if(distance <= 30)
    {
      setColor(255, 0, 0);
      delay(distance * 10);
      setColor(255, 140, 0);
      delay(distance * 10);
      setColor(255, 255, 80);
      delay(distance * 10);
      setColor(127, 255, 0);
      delay(distance * 10);
      setColor(0, 0, 205);
      delay(distance * 10);
      setColor(111, 0, 0);
      delay(distance * 10);
      setColor(138, 43, 226);
      delay(distance * 10);

    }
    else
    {
      
      delay(500);
    }
  }
  
}

void setColor(int red, int green, int blue){
      analogWrite(redPin, red);
      //delay(distance * 10);
      analogWrite(greenPin, green);
      //delay(distance * 10);
      analogWrite(bluePin, blue);
      //delay(distance * 10);
      }
