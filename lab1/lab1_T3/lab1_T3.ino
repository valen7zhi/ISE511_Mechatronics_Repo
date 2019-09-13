
void loop() {
  // put your main code here, to run repeatedly:

  
  
  unsigned long currentmillis = millis();

  if (currentmillis - previousmillis >= interval)
  {
    previousmillis = currentmillis;
    
    if (ledstate == LOW)
    {
      ledstate = HIGH;
    }
    else
    {
      ledstate = LOW;
    }

    digitalWrite(YellowPin,ledstate);

    
  }

  
  blink23(previousmillis,currentmillis);
}


void blink23(int previousmillis, int currentmillis)
{


  unsigned long thismillis = millis();

  if (thismillis - previousmillis >= 500 )
  {   
    if (ledstate2 == LOW)
    {
      ledstate2 = HIGH;
      ledstate3 = LOW;
    }
    else
    {
      ledstate2 = LOW;
      ledstate3 = HIGH;
    }

    digitalWrite(RedPin,ledstate2);
    digitalWrite(GreenPin,ledstate3);
  }
  
}
