/*
 * Funksteckdosen über eine Harmony steuern
 * Version 0.1 Dezember 2013
 * Pascal König
 * http://www.pascals-koenigreich.de/
 */

#include <IRremote.h>
#include <RCSwitch.h>

int RECV_PIN = 11;

unsigned long codeValue;

IRrecv irrecv(RECV_PIN);
RCSwitch mySwitch = RCSwitch();

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  mySwitch.enableTransmit(9);
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    codeValue = results.value;
    //Serial.println(codeValue);
    
    switch(codeValue){
      case 3778927144:
        Serial.println("Stecker 1 an");
        mySwitch.switchOn("10101", "10000");
        break;
      case 2908251746:
        Serial.println("Stecker 1 aus");
        mySwitch.switchOff("10101", "10000");
        break;
      case 657459652:
        Serial.println("Stecker 2 an");
        mySwitch.switchOn("10101", "01000");
        break;
      case 4120482440:
        Serial.println("Stecker 2 aus");
        mySwitch.switchOff("10101", "01000");
        break;
      default:
        //nichts
        break;
    }
    
    irrecv.resume(); // Receive the next value
  }
}
