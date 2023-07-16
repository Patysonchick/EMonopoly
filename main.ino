#include "libs/libs.h"

LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

void setup()
{
    Serial.begin(9600);

    for(uint8_t i=buttonFirst; i<=buttonLast; i++){pinMode(ButtonsProps[i].pin, INPUT_PULLUP);}

    lcd.begin(16, 2);

    randomSeed(analogRead(A0));

    Players[currentPlayer].throwDice();
}

void loop()
{
    gameEngine();

    buttonsActions();

    displayGameInfo();

    lcd.clear();
    delay(1);
}