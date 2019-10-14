#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("hello, world!");
}

void loop()
{
    // Turn off the display:
    // lcd.noDisplay();
    // delay(500);
    // // Turn on the display:
    // lcd.display();
    // delay(500);
}
