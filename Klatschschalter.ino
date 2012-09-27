//Library RCSwitch von folgender Seite: http://code.google.com/p/rc-switch/
#include <RCSwitch.h>

int soundSensor = 2;
int transmitter = 3;

int switchState = 0;

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(3);
  pinMode(soundSensor, INPUT);
}

void loop() {
  int soundSensorState = digitalRead(soundSensor);
  
  if(soundSensorState == 1)
  {
    if (switchState == 0)
    {
      switchState = 1;
      Serial.println("Steckdose an");
    }
    else
    {
      switchState = 0;
      Serial.println("Steckdose aus");
    }
    Serial.println("KLATSCH");
    
    switch(switchState)
    {
      case 0: mySwitch.switchOff("00001", 1); break;
      case 1: mySwitch.switchOn("00001", 1); break;
      default: Serial.println("default Wert");
    }
    delay(1000);
  }
  delay(1);
}



