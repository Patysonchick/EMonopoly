void displayGameInfo()
{
    lcd.setCursor(0, 0);
    lcd.print("Pos");
    lcd.setCursor(4, 0);
    lcd.print(Players[currentPlayer].currentPos);

    lcd.setCursor(7, 0);
    lcd.print("Plr");
    lcd.setCursor(11, 0);
    lcd.print(currentPlayer);    

    lcd.setCursor(0, 1);
    lcd.print("Mny");
    lcd.setCursor(4, 1);
    lcd.print(Players[currentPlayer].money);    
}