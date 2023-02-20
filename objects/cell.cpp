#include "cell.hpp"

#include <iostream>

Cell::Cell(Type aType)
{
    mType = aType;
}

Cell::Type
Cell::getType(){
    return mType;
}