// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;

void setup () {
    pinMode(14, OUTPUT);pinMode(2, OUTPUT);pinMode(3, OUTPUT);pinMode(4, OUTPUT);pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);pinMode(7, OUTPUT);pinMode(8, OUTPUT);pinMode(9, OUTPUT);pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);pinMode(12, OUTPUT);pinMode(13, OUTPUT);
    Serial.begin(57600);
    Wire.begin();
    RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop () {
    DateTime now = RTC.now();
    
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    
    int munit = now.minute()%10;
    int hunit = now.hour()%10;
    
    //now.minute()s units
	if(munit == 1 || munit == 3 || munit == 5 || munit == 7 || munit == 9) {  digitalWrite(14, HIGH);} else {  digitalWrite(14,LOW);}
	if(munit == 2 || munit == 3 || munit == 6 || munit == 7) {digitalWrite(2, HIGH);} else {digitalWrite(2,LOW);}
	if(munit == 4 || munit == 5 || munit == 6 || munit == 7) {digitalWrite(3, HIGH);} else {digitalWrite(3,LOW);}
	if(munit == 8 || munit == 9) {digitalWrite(4, HIGH);} else {digitalWrite(4,LOW);}

	//now.minute()s 
	if((now.minute() >= 10 && now.minute() < 20) || (now.minute() >= 30 && now.minute() < 40) || (now.minute() >= 50 && now.minute() < 60))  {digitalWrite(5, HIGH);} else {digitalWrite(5,LOW);}
	if(now.minute() >= 20 && now.minute() < 40)  {digitalWrite(6, HIGH);} else {digitalWrite(6,LOW);}
	if(now.minute() >= 40 && now.minute() < 60) {digitalWrite(7, HIGH);} else {digitalWrite(7,LOW);}

	//now.hour() units
	if(hunit == 1 || hunit == 3 || hunit == 5 || hunit == 7 || hunit == 9) {digitalWrite(8, HIGH);} else {digitalWrite(8,LOW);}
	if(hunit == 2 || hunit == 3 || hunit == 6 || hunit == 7) {digitalWrite(9, HIGH);} else {digitalWrite(9,LOW);}
	if(hunit == 4 || hunit == 5 || hunit == 6 || hunit == 7) {digitalWrite(10, HIGH);} else {digitalWrite(10,LOW);}
	if(hunit == 8 || hunit == 9) {digitalWrite(11, HIGH);} else {digitalWrite(11,LOW);}

	//now.hour()
	if(now.hour() >= 10 && now.hour() < 20)  {digitalWrite(12, HIGH);} else {digitalWrite(12,LOW);}
	if(now.hour() >= 20 && now.hour() < 24)  {digitalWrite(13, HIGH);} else {digitalWrite(13,LOW);}
    
    Serial.println();
    delay(3000);
}
