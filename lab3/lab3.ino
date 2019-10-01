/** lab3 Zhibo Wang
 *  Motor Control with tachometer
 */
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

const int motorpin = 3;
int speed; // range 0 ~ 255
// int passFlag = 0;

const int irLED = 7;
volatile byte breakNum;
unsigned int rpm;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);

    pinMode(motorpin, OUTPUT);

    pinMode(irLED, OUTPUT);
    digitalWrite(irLED, HIGH);
    attachInterrupt(0, breakCount, FALLING);

    // analogWrite(motorpin, speed);
    // delay(3000);
    // digitalWrite(motorpin, LOW);

    // rpm = 0;
    // breakNum = 0;

    tableRotate();
}

void loop()
{
    // if (passFlag == 0)
    // {
    //     tableRotate();
    //     passFlag++;
    // }

    // delay(1000);

    // detachInterrupt(0);

    // rpm = 60 * breakNum;

    // breakNum = 0;
    // motorswitch();

    // attachInterrupt(0, breakCount, FALLING);
}

// void motorswitch()
// {
//     analogWrite(motorpin, speed); // run fan for seven seconds and then turn it off as required
// }

void breakCount()
{
    breakNum++;
}

void tableRotate()
{
    lcddp("Max Speed");
    speed = 255;
    analogWrite(motorpin, speed);
    delay(4000);

    lcddp("0");
    speed = 0;
    analogWrite(motorpin, speed);
    delay(2000);

    lcddp("Half Speed");
    speed = 60;
    analogWrite(motorpin, speed);
    delay(5000);

    lcddp("0");
    speed = 0;
    analogWrite(motorpin, speed);
    delay(2000);

    lcddp("0.75 Speed");
    speed = 180;
    analogWrite(motorpin, speed);
    delay(3000);

    lcddp("0");
    speed = 0;
    analogWrite(motorpin, speed);
}

void lcddp(String spd)
{
    lcd.clear();
    lcd.print("RPM = ");
    lcd.print(spd);

    Serial.print("rpm = ");
    Serial.println(spd);
}