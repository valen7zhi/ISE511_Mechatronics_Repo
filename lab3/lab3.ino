/** lab3 Zhibo Wang
 *  Motor Control with tachometer
 */
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

const int motorpin = 3;
int speed; // range 0 ~ 255
// int passFlag = 0;

const int irLED = 1;
volatile byte breakNum;
unsigned int rpm;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);

    pinMode(motorpin, OUTPUT);

    attachInterrupt(0, breakCount, FALLING);
    pinMode(irLED, OUTPUT);
    digitalWrite(irLED, HIGH);

    rpm = 0;
    breakNum = 0;

    delay(1000);

    tableRotate();
    // analogWrite(motorpin, speed);
    // delay(3000);
    // digitalWrite(motorpin, LOW);
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

void tableRotate()
{

    speed = 255;
    analogWrite(motorpin, speed);
    lcddp("Max Speed");
    delay(4000);
    lcd.clear();

    speed = 0;
    analogWrite(motorpin, speed);
    lcddp("0");
    delay(2000);
    lcd.clear();

    speed = 80;
    analogWrite(motorpin, speed);
    lcddp("Half Speed");
    delay(5000);
    lcd.clear();

    speed = 0;
    analogWrite(motorpin, speed);
    lcddp("0");
    delay(2000);
    lcd.clear();

    speed = 200;
    analogWrite(motorpin, speed);
    lcddp("0.75 Speed");
    delay(3000);
    lcd.clear();

    speed = 0;
    lcddp("0");
    analogWrite(motorpin, speed);
    lcd.clear();
}

void lcddp(String spd)
{
    delay(1000);

    detachInterrupt(0);
    rpm = 60 * breakNum;

    if (spd == "0")
    {
        rpm = 0;
    }
    // breakNum = 0;

    lcd.print("RPM = ");
    // lcd.print(spd);

    lcd.setCursor(0, 2);
    lcd.print(rpm);

    Serial.print("rpm = ");
    Serial.println(rpm);

    attachInterrupt(0, breakCount, FALLING);
    rpm = 0;
    breakNum = 0;
}

void breakCount()
{
    breakNum++;
}