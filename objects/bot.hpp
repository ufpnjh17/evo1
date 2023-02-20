#ifndef BOT_HPP
#define BOT_HPP

#include <vector>

#include "cell.hpp"

class Bot : public Cell
{
public:
    enum class Direction
    {
        UP,
        UP_RIGHT,
        RIGHT,
        DOWN_RIGHT,
        DOWN,
        DOWN_LEFT,
        LEFT,
        UP_LEFT
    };

    Bot();

private:
    std::vector<int> mCode; // генетический код
    int mIterator;          //
    int mLife;              // время жизни
    Direction mDirection;
};

#endif // !BOT_HPP