enum playersColours
{
    playerBlue,
    playerRed,
    playerGreen,
    playerPurple
};

class Player
{
    public:
        uint16_t money;
        uint8_t currentPos;
        uint8_t firstDice;
        uint8_t secondDice;
        bool doubleDice;
        bool isFinished;
        bool isConnected;

        Player(uint16_t money){this->money = money;}
        
        void throwDice()
        {
            firstDice=0;
            secondDice=0;

            firstDice = random(1, 7);
            secondDice = random(1, 7);

            Serial.print(firstDice);
            Serial.print(" ");
            Serial.println(secondDice);

            if(firstDice == secondDice){doubleDice = true;}
            
            currentPos += firstDice + secondDice;

            //Проход клетки старт
            if(currentPos > 39)
            {
                currentPos -= 40;
                money += Fields[0].prize;
            }
        }

        void fieldsAction()
        {
            switch(Fields[currentPos].type)
            {
                case tax:
                    money -= Fields[currentPos].rent;
                    break;
                
                case chest:
                    break;
                
                case chance:
                    break;

                case goToJail:
                    currentPos = 30;
                    break;
            }
        }
};

#define MAX_PLAYERS 4
#define START_MONEY 1500
Player Players[4] = 
{
    [0] = Player(START_MONEY),
    [1] = Player(START_MONEY),
    [2] = Player(START_MONEY),
    [3] = Player(START_MONEY)
};

uint8_t currentPlayer=0;
void changePlayer()
{
    Players[currentPlayer].isFinished = false;
    Players[currentPlayer].doubleDice = false;

    if(currentPlayer+1 <= 3){currentPlayer++;}
    else if(currentPlayer+1 > 3)
    {
        currentPlayer++;
        currentPlayer-=4;
    }
    Players[currentPlayer].throwDice();
}

void gameEngine()
{	
  	if(Players[currentPlayer].isFinished == true && Players[currentPlayer].doubleDice == true)
    {
        Players[currentPlayer].isFinished = false;
        Players[currentPlayer].doubleDice = false;

        if(Fields[Players[currentPlayer].currentPos].type != jail){Players[currentPlayer].throwDice();}
    }
    else if(Players[currentPlayer].isFinished == true && Players[currentPlayer].doubleDice == false){changePlayer();}
}