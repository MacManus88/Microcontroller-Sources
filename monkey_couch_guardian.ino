/*
  Monkey Couch Guardian
  Turns on cymbal-banging toy monkey when PIR motion sensor detects motion.
  More Information: 
 */
 
 // pin 13 activates the relay which switches on monkey
 const int monkeySwitch = 13;
 // pin 12 is input for PIR sensor
 const int pirInput = 12;

 const int led = 11;

void setup() {                
  // initialize monkeySwitch as an output.
  pinMode(monkeySwitch, OUTPUT);     
  // initialize pirInput 12 as an input.
  pinMode(pirInput, INPUT);
  
  pinMode(led, OUTPUT);
  // waits for 5 seconds to allow PIR sensor to settle down
  delay(5000);
  digitalWrite(led, HIGH);
}

void loop() {
  //read PIR value
int pirState = digitalRead(pirInput); 
  //check to see if PIR senses motion
if (pirState == HIGH)
{
  digitalWrite(led, LOW);
//turn on monkey
digitalWrite(monkeySwitch, HIGH);
//monkey runs for 5 seconds
delay(5000);
//turn off monkey for 5 seconds so it doesn't activite itself
digitalWrite(monkeySwitch, LOW);
 delay(5000);
 digitalWrite(led, HIGH);
}
}
