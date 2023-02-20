#include "bot.hpp"

#include <iostream>

Bot::Bot() : Cell(Cell::Type::BOT), mCode(60)
{
    mLife      = 90;
    mIterator  = 0;
    mDirection = Direction(rand() % 8);
    for (int i = 0; i < 60; i++)
    {
        mCode[i] = rand() % 10;
    }
}
