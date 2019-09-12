//lab1 Zhibo Wang

int YellowPin = 13; //Yellow LED
int RedPin = 12; //Red LED
int GreenPin = 11; //Green LED

int blinkTime = 500 / 5; // .5 second

int blinkcounter = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(YellowPin, OUTPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);

  blinkThree(10 * 3, blinkTime); //blink 10 times, on and off for .5 second

  blinkAll(blinkTime); //blink all for 10 timesdi

}

void loop() {
  // put your main code here, to run repeatedly:
  
    if (blinkcounter < 60)
    {
      digitalWrite(YellowPin,HIGH);
      blinkcounter++;
      delay(250);
      digitalWrite(YellowPin,LOW);
      delay(250);
      
      blink23();
      blinkcounter++;

      
      digitalWrite(YellowPin,HIGH);
      blinkcounter++;
      delay(250);
      digitalWrite(GreenPin,LOW);
      digitalWrite(YellowPin,LOW);
      delay(250);
      
    }
    else if (blinkcounter > 60 && blinkcounter < 100)
    {
      digitalWrite(YellowPin,HIGH);
      blinkcounter++;
      delay(250);
      digitalWrite(YellowPin,LOW);
      delay(250);
    }
    else
    {
      digitalWrite(YellowPin,LOW);
      digitalWrite(GreenPin,LOW);
      digitalWrite(RedPin,LOW);
    }
  

}

void blink23()
{
  digitalWrite(YellowPin,HIGH);
  digitalWrite(RedPin,HIGH);
  digitalWrite(GreenPin,LOW);
  delay(250);
  digitalWrite(YellowPin,LOW);
  digitalWrite(RedPin,LOW);
  digitalWrite(GreenPin,HIGH);
  
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
