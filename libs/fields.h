enum fieldsName
{
    start,
    tax,
    chest,
    chance,
    goToJail,
    jail,
    parking,
    own,
    railroad
};

class Field
{
    public:
        uint8_t type;
        uint8_t price;
        uint8_t prize;
        uint8_t owner; //4-ничейная(монополии)
        uint8_t rent;

        Field(uint8_t type, uint8_t price, uint8_t prize, uint8_t owner, uint8_t rent)
        {
            this->type = type;
            this->price = price;
            this->prize = prize;
            this->owner = owner;
            this->rent = rent;
        }
};

#define MAX_FIELDS 40
Field Fields[MAX_FIELDS] =
{
    [0] = Field(start, 0, 200, 4, 0),
    [1] = Field(own, 60, 0, 4, 0),
    [2] = Field(chest, 0, 0, 4, 0),
    [4] = Field(tax, 0, 0, 4, 200),
    [10] = Field(goToJail, 0, 0, 4, 0),

    [30] = Field(jail, 0, 0, 4, 0),
};