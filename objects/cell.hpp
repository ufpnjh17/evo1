#ifndef CELL_HPP
#define CELL_HPP

#include <vector>

class Cell
{
public:
    enum class Type
    {
        EMPTY,
        WALL,
        FOOD,
        POISON,
        BOT
    };

    Cell(Type aType);
    virtual ~Cell() = default;

    Type getType();

private:
    Type mType;
};

#endif // !VIRTUALBOT_HPP