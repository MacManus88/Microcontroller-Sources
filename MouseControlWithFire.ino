//More Infos: 

#include <Wire.h>
#include <PVision.h>

#define SERIAL_BAUD_RATE 38400

PVision ircam;
byte result;

void setup()
{
  Serial.begin(SERIAL_BAUD_RATE);
  ircam.init();
}

void loop()
{    
  result = ircam.read();
  
  if (result & BLOB1)
  {
    Serial.print("BLOB1 detected. X:");
    Serial.print(ircam.Blob1.X);
    Serial.print(" Y:");
    Serial.print(ircam.Blob1.Y);
    Serial.print(" Size:");
    Serial.println(ircam.Blob1.Size);
    
    Mouse.move(ircam.Blob1.X/5, ircam.Blob1.Y/5);
  }
}
