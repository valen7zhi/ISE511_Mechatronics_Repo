/** lab2 Zhibo Wang
 *  Paper towel humidity sensor
 */

#include <dht.h>
dht DHT;
#define DHT11_PIN 4

const int motor_pin = 3;
const int greenled_pin = 7;
const int blueled_pin = 8;

const int blinkinterval = 500; // .5 second
const int blinkperiod = 3000;  // for 3 seconds

const int speed = 255;

int init_humidity; // record normal room temperature and humidity into the system

void setup()
{
    Serial.begin(9600);
    pinMode(motor_pin, OUTPUT);
    pinMode(greenled_pin, OUTPUT);
    pinMode(blueled_pin, OUTPUT);

    digitalWrite(greenled_pin, HIGH); // initial system check blink both LEDs for 1 second and then turn them off
    digitalWrite(blueled_pin, HIGH);
    delay(1000);

    digitalWrite(greenled_pin, LOW);
    digitalWrite(blueled_pin, LOW);
    delay(1000);
}

void loop()
{
    int chk = DHT.read11(DHT11_PIN);
    delay(2000); // time buffer
    int realt_humidity = DHT.humidity;
    int realt_temperature = DHT.temperature;

    // Serial.print("Temperature = ");
    // Serial.println(init_temperature);
    // Serial.print("Initial Humidity = ");
    // Serial.println(init_humidity);
    Serial.print("Humidity = ");
    Serial.println(realt_humidity);
    if (realt_humidity > 75) // rule-of-thumb wet value set for 60. more robust design needed for better algorithm
    {
        ledblinker();
        motorswitch();
    }

    // if (Serial.available())
    // {
    //     int speed = Serial.parseInt();
    //     if (speed >= 0 && speed <= 255)
    //     {
    //         analogWrite(motor_pin, speed);
    //         delay(5000);
    //     }
    // }
}

// int humiditychecker()
// {
//     int chk = DHT.read11(DHT11_PIN);
//     delay(2000);
//     int init_humidity = DHT.humidity; // record normal room temperature and humidity into the system
//     delay(2000);
//     init_humidity = DHT.humidity;
// }

void ledblinker()
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(greenled_pin, HIGH);
        digitalWrite(blueled_pin, LOW);
        delay(blinkinterval);

        digitalWrite(greenled_pin, LOW);
        digitalWrite(blueled_pin, HIGH);
        delay(blinkinterval);
    }

    digitalWrite(greenled_pin, LOW);
    digitalWrite(blueled_pin, LOW);
}

void motorswitch()
{
    analogWrite(motor_pin, speed);
    delay(7000); // run fan for seven seconds and then turn it off as required
    analogWrite(motor_pin, 0);
}