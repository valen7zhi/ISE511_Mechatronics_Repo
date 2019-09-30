/** lab3 Zhibo Wang
 *  Motor Control
 */

const int motorpin = 3;
const int speed = 70;

const int Vin = 5;
const float R1 = 10000;
const int sensor = A0;

int raw = 0;
float Vout = 0;
float R2 = 0;
float buffer = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(motorpin, OUTPUT);

    // digitalWrite(greenled_pin, LOW);
    // digitalWrite(blueled_pin, LOW);
    // delay(1000);
}

void loop()
{
    // Serial.print("Humidity = ");
    // Serial.println(realt_humidity);

    motorswitch();
    raw = analogRead(sensor);

    if (raw)
    {
        buffer = raw * Vin;
        Vout = buffer / 1024.0;
        buffer = Vin / Vout - 1;
        R2 = R1 * buffer;
        Serial.print("Vout: ");
        Serial.println(Vout);
        Serial.println(R2);
        delay(1000);
    }
    // ledblinker();
}

void motorswitch()
{
    analogWrite(motorpin, speed);
    delay(7000); // run fan for seven seconds and then turn it off as required
    analogWrite(motorpin, 0);
}

// void ledblinker()
// {
//     for (int i = 0; i < 3; i++)
//     {
//         digitalWrite(greenled_pin, HIGH);
//         digitalWrite(blueled_pin, LOW);
//         delay(blinkinterval);

//         digitalWrite(greenled_pin, LOW);
//         digitalWrite(blueled_pin, HIGH);
//         delay(blinkinterval);
//     }

//     digitalWrite(greenled_pin, LOW);
//     digitalWrite(blueled_pin, LOW);
// }