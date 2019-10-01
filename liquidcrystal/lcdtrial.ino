#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup()
{
    lcd.begin(16, 2);
}

void loop()
{
    lcd.print("Arduino");
    delay(1000);

    lcd.setCursor(0, 2);
    lcd.print("LCD");
    delay(1000);

    lcd.clear();

    lcd.blink();
    delay(3000);
    lcd.setCursor(16, 2);
    delay(3000);
    lcd.noBlink();

    lcd.cursor();
    delay(3000);
    lcd.noCursor();

    lcd.clear();
}