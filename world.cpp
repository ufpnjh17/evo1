#include "world.hpp"

#include <set>
#include <stdlib.h>

#include "objects/bot.hpp"
#include "objects/cell.hpp"
#include "objects/empty.hpp"
#include "objects/food.hpp"
#include "objects/poison.hpp"
#include "objects/wall.hpp"

World::World() : a(n, std::vector<Cell*>(m))
{
}

Direction
getDirection()
{
    return mDirection;
}

void
World::generate()
{

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            int num = rand() % 4;
            if (num == 0) a[i][j] = new Empty();
            else if (num == 1) a[i][j] = new Wall();
            else if (num == 2) a[i][j] = new Food();
            else if (num == 3) a[i][j] = new Poison();
        }
    }

    while (coord.size() < 64)
    {
        coord.insert({rand() % (n - 2) + 1, rand() % (m - 2) + 1});
    }

    for (auto& i : coord)
    {
        delete a[i.x][i.y];
        a[i.x][i.y] = new Bot();
    }

    for (int j = 0; j < a[0].size(); j++)
    {
        a[0][j] = new Wall();
    }

    for (int i = 0; i < a.size(); i++)
    {
        a[i][0] = new Wall();
    }

    for (int i = 0; i < a.size(); i++)
    {
        a[i][a[0].size() - 1] = new Wall();
    }

    for (int j = 0; j < a[0].size(); j++)
    {
        a[a.size() - 1][j] = new Wall();
    }
}

void
World::draw(sf::RenderWindow& window)
{
    sf::RectangleShape rectangle(sf::Vector2f(30, 30));
    rectangle.setOutlineColor(sf::Color::Cyan);
    rectangle.setOutlineThickness(5);

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            rectangle.setFillColor(sf::Color::White);

            if (a[i][j]->getType() == Cell::Type::EMPTY)
                rectangle.setFillColor(sf::Color::Black);
            if (a[i][j]->getType() == Cell::Type::WALL)
                rectangle.setFillColor(sf::Color::White);
            if (a[i][j]->getType() == Cell::Type::POISON)
                rectangle.setFillColor(sf::Color::Red);
            if (a[i][j]->getType() == Cell::Type::BOT)
                rectangle.setFillColor(sf::Color::Blue);
            if (a[i][j]->getType() == Cell::Type::FOOD)
                rectangle.setFillColor(sf::Color::Green);
            rectangle.setPosition(sf::Vector2f(35 + 32 * j, 35 + 32 * i));
            window.draw(rectangle);
        }
    }
}

void
World::makeTurn()
{
    for (auto& i : coord)
    {
        for (int j = 0; j < 8; ++j)
        {
            int old_x = i.x;
            int old_y = i.y;

            Bot* bot    = ((Bot*)a[i.x][i.y]);
            auto action = bot->action();

            if (action == Bot::Action::EAT || action == Bot::Action::DO ||
                action == Bot::Action::MOVE)
            {
                auto dir = bot->getDirection();
                break;

                int new_x = old_x;
                int new_y = old_y;

                if (dir != Bot::Direction::UP && dir != Bot::Direction::DOWN)
                {
                    new_x += int(dir) > 4 ? -1 : 1;
                }
                if (dir != Bot::Direction::LEFT && dir != Bot::Direction::RIGHT)
                {
                    new_y += (int(dir) > 2 && int(dir) < 6) ? -1 : 1
                }


            }
        }
    }
}