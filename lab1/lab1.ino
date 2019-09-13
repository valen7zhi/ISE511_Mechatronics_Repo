//lab1 Zhibo Wang

const int YellowPin = 13; //Yellow LED
const int RedPin = 12; //Red LED
const int GreenPin = 11; //Green LED

const int blinkTime = 500 / 5; // .5 second

unsigned long previousmillis = 0; //Task3 Init
const long interval = 250; // blinkTime for YellowPin

int blinkcounterY = 0; //Task3 blinkcounter 
int blinkcounterRG = 0; 

//int ledstate = LOW;
//int ledstate2 = LOW;
//int ledstate3 = HIGH;

void setup() {
  // put your setup code here, to run once:

  pinMode(YellowPin, OUTPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);

  blinkThree(10 * 3, blinkTime); //Task1 blink 10 times, on and off for .5 second

  blinkAll(blinkTime); //Task2 blink all for 10 timesdi


}

void loop() {
  // put your main code here, to run repeatedly:

  if (blinkcounterY < 100)
  {
    delay(interval);
    digitalWrite(YellowPin, HIGH);
    digitalWrite(RedPin, HIGH);
    digitalWrite(GreenPin, LOW);
    blinkcounterY++;
    
  
    delay(interval);
    digitalWrite(YellowPin, LOW);
    digitalWrite(RedPin, HIGH);
    digitalWrite(GreenPin, LOW);
    blinkcounterY++;
    blinkcounterRG++;
    
    delay(interval);
    digitalWrite(YellowPin, HIGH);
    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, HIGH);
    blinkcounterY++;
  
    delay(interval);
    digitalWrite(YellowPin, LOW);
    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, HIGH);
    blinkcounterY++;
    blinkcounterRG++;

  }
  else if (blinkcounterRG < 60)
  {
    
    digitalWrite(YellowPin,LOW);
    delay(interval*2);
    digitalWrite(RedPin,HIGH);
    digitalWrite(GreenPin,LOW);
    delay(interval*2);
    digitalWrite(RedPin,LOW);
    digitalWrite(GreenPin,HIGH);

    blinkcounterRG++;
   
    
  }

  else
  {
    digitalWrite(YellowPin,LOW);
    digitalWrite(RedPin,LOW);
    digitalWrite(GreenPin,LOW);
  }
  
}






void blinkThree(int repeats, int time)
{
  int pinswitch = 0;

  for (int i = 0; i < repeats; i++)
  {

    if (i < 10)
    {
      pinswitch = YellowPin;
    }
    else if ( 10 <= i && i < 19)
    {
      pinswitch = RedPin;
    }
    else
    {
      pinswitch = GreenPin;
    }

    digitalWrite(pinswitch, HIGH);
    delay(time);
    digitalWrite(pinswitch, LOW);
    delay(time);
  }


}

void blinkAll(int time)
{

  for (int i = 0; i < 10; i++)
  {
    digitalWrite(RedPin, HIGH);
    digitalWrite(GreenPin, HIGH);
    digitalWrite(YellowPin, HIGH);
    delay(time);

    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, LOW);
    digitalWrite(YellowPin, LOW);
    delay(time);
  }

}
