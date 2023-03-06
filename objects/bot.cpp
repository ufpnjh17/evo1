#include "bot.hpp"

#include <iostream>

Bot::Bot() : Cell(Cell::Type::BOT), mCode(60)
{
    mLife      = 90;
    mIterator  = 0;
    mDirection = Direction(rand() % 8);

    for (int i = 0; i < 60; i++)
    {
        mCode[i] = rand() % 4;
    }
}

Bot::Action
Bot::action(Cell::Type aType)
{
    int num;

    num = mCode[mIterator];
    if (mIterator++ >= mCode.size()) mIterator = 0;
    if (num == 0) return Action::LOOK;
    else if (num == 1) return Action::EAT;
    else if (num == 2) return Action::DO;
    else if (num == 3) return Action::MOVE;
    else return Action::NUN;
}