/*  lab6 Zhibo Wang
Control based on Sensor Feedbacks
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

const int echo = 18;
const int trigger = 19;
float time = 0;
float distance = 0;

const int enable2 = 3;
const int in3 = 5;
const int in4 = 6;

float targetDistance;

void setup()
{
    // opens serial port, sets data rate to 9600 bps
    Serial.begin(9600);

    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    pinMode(enable2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.print("Ultrasonic");
    // set the cursor to (column 0, line 1)
    // line 1 is the second row, since counting begins with 0
    lcd.setCursor(0, 1);
    lcd.print("Distance Control");
    lcd.clear();
    lcd.print("System Initializing");
    delay(2000);

    targetDistance = 15;
}

void loop()
{
    lcd.clear();
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    time = pulseIn(echo, HIGH);
    distance = time * 330 / 20000;
    lcd.clear();
    lcd.print("Distance: ");
    lcd.setCursor(0, 1);

    if (distance < 11)
    {
        lcd.print("Reached cl. end");
    }
    else if (distance > 20)
    {
        lcd.print("Reached far end");
    }
    else if (16 < distance && distance < 17)
    {
        lcd.print("Reached Midpoint");
    }
    else if (distance > 11 && distance < 21)
    {
        lcd.print(distance, 1);
        lcd.print(" cm");
    }

    delay(1500);
    // // -> 20cm (CW)
    // analogWrite(enable2, 255);
    // digitalWrite(in3, HIGH);
    // digitalWrite(in4, LOW);
    // delay(3000);

    // // 10cm <- (CCW)
    // analogWrite(enable2, 255);
    // digitalWrite(in3, LOW);
    // digitalWrite(in4, HIGH);
    // delay(3000);

    targetDistance = distanceControl(targetDistance, distance);
}

float distanceControl(int targetDistance, float distance)
{
    if (targetDistance > distance)
    {
        analogWrite(enable2, 255);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }
    else if (targetDistance < distance)
    {
        analogWrite(enable2, 255);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    }

    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    time = pulseIn(echo, HIGH);
    distance = time * 330 / 20000;

    if (targetDistance - 0.5 < distance || distance < targetDistance + 0.5)
    {
        targetDistance = distance;
    }
    return targetDistance;
}