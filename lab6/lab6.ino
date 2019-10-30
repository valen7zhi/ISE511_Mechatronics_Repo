/*  lab6 Zhibo Wang
Control based on Sensor Feedbacks
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    delay(1000);
}

void loop()
{
  
}
