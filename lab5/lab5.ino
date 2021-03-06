/*  lab5 Zhibo Wang
Linear Motion Control 
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

const int motorPin = 3;
const int maxPWM = 255;
const int adjPWM = 230;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    pinMode(motorPin, OUTPUT);

    delay(1000);

    motionControl();
}

void loop()
{
}

void motionControl()
{

    lcd.print("Moving 1 inch");
    // analogWrite(motorPin, maxPWM); // torque initializer
    // delay(150);
    analogWrite(motorPin, adjPWM);
    delay(1200);
    analogWrite(motorPin, 0);
    delay(3000);

    lcd.clear();
    lcd.print("Moving 3/4 inch");
    // analogWrite(motorPin, maxPWM); // torque initializer
    // delay(150);
    analogWrite(motorPin, adjPWM);
    delay(900);
    analogWrite(motorPin, 0);
    delay(3000);

    lcd.clear();
    lcd.print("Moving 1 1/4 inch");
    // analogWrite(motorPin, maxPWM); // torque initializer
    // delay(50);
    analogWrite(motorPin, adjPWM);
    delay(1300);
    analogWrite(motorPin, 0);

    lcd.clear();
    lcd.print("All Steps Done!");
}