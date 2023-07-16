enum buttonsNumbers
{
    buttonFirst,

    buttonLeft = buttonFirst,
    buttonCenter,
    buttonRight,

    buttonLast = buttonRight,
    buttonMax
};

class ButtonSets
{
    public:
        uint8_t pin;
        uint16_t counter;
        uint8_t pressCode;

        ButtonSets(uint8_t pin){this->pin = pin;}
};


ButtonSets ButtonsProps[buttonMax] =
{
    [buttonLeft] = ButtonSets(2),
    [buttonCenter] = ButtonSets(3),
    [buttonRight] = ButtonSets(4)
};

uint8_t lastFunc=0;
void buttonsScan()
{
    for(uint8_t i=buttonFirst; i<=buttonLast; i++)
    {
        if(digitalRead(ButtonsProps[i].pin) == 0){ButtonsProps[i].counter++;}
        else if(digitalRead(ButtonsProps[i].pin) == 1)
        {
            //Короткое нажатие
            if(ButtonsProps[i].counter >= 5 && ButtonsProps[i].counter <= 50){ButtonsProps[i].pressCode = 1;}
            //Длинное нажатие
            if(ButtonsProps[i].counter > 50){ButtonsProps[i].pressCode = 2;}
            //Насчитался
            ButtonsProps[i].counter = 0;
        } 

        if(ButtonsProps[i].pressCode != 0)
        {
            lastFunc = ButtonsProps[i].pin * 10 + ButtonsProps[i].pressCode;
            ButtonsProps[i].pressCode=0;
        }
    }
}

void buttonsActions()
{
    buttonsScan();

    switch(lastFunc)
    {
        case 31:
            Players[currentPlayer].isFinished = true;

            lastFunc = 0;
            break;
    
        default:
            break;
    }
}