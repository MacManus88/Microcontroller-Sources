//Mehr Infos auf: http://www.pascals-koenigreich.de/2013/04/led-kerze-mit-unterschiedlichen.html

#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 15

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int ledPin = 9;
int last_value = pow(MAX_DISTANCE, 2)-50;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop()
{  
  unsigned int uS = sonar.ping();
  int cm = uS / US_ROUNDTRIP_CM;
  Serial.print("Ping: ");
  Serial.print(cm);
  Serial.println("cm");
  
  int i;
  if (cm == 0)
  {
    i = last_value;
  }
  else if (cm <= 8)
  {
    i = pow(cm, 2);
    last_value=i;
  }
  else if (cm <= MAX_DISTANCE)
  {
    i = pow(cm, 2)-50;
    last_value=i;
  }
  
  Serial.print("LED-Value: ");
  Serial.println(i);
  
  analogWrite(ledPin, random(50)+i);
  
  delay(random(50,100));
}
