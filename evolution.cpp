#include <SFML/Graphics.hpp>

#include <stdlib.h>

#include "objects/cell.hpp"
#include "objects/bot.hpp"
#include "objects/empty.hpp"
#include "objects/food.hpp"
#include "objects/poison.hpp"
#include "objects/wall.hpp"

int
main()
{

        int n = 10;
    std::vector<std::vector<Cell*>> a(n, std::vector<Cell*>(n));

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    // sf::RectangleShape shape( sf::Vector2f(10, 10));
    // sf::TriangleFan
    sf::RectangleShape rectangle(sf::Vector2f(30, 30));
    // rectangle.setSize(sf::Vector2f(200, 200));
    rectangle.setOutlineColor(sf::Color::Cyan);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(300, 300);

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            int num = rand() % 5;
            if (num == 0) a[i][j] = new Empty();
            else if (num == 1) a[i][j] = new Wall();
            else if (num == 2) a[i][j] = new Food();
            else if (num == 3) a[i][j] = new Poison();
            else if (num == 4) a[i][j] = new Bot();
        }
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

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        for (int i = 0; i < a.size(); ++i)
        {
            for (int j = 0; j < a[i].size(); ++j)
            {
                rectangle.setFillColor(sf::Color::White);

                if (a[i][j]->getType() == Cell::Type::EMPTY) rectangle.setFillColor(sf::Color::Black);
                if (a[i][j]->getType() == Cell::Type::WALL) rectangle.setFillColor(sf::Color::White);
                if (a[i][j]->getType() == Cell::Type::POISON) rectangle.setFillColor(sf::Color::Red);
                if (a[i][j]->getType() == Cell::Type::BOT) rectangle.setFillColor(sf::Color::Blue);
                if (a[i][j]->getType() == Cell::Type::FOOD) rectangle.setFillColor(sf::Color::Green);
                rectangle.setPosition(sf::Vector2f(100 + 32 * j, 100 + 32 * i));
                window.draw(rectangle);
            }
        }

        window.display();
    }
    return 0;
}