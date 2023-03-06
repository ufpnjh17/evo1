#include <SFML/Graphics.hpp>

#include <set>
#include <stdlib.h>

#include "objects/bot.hpp"
#include "objects/cell.hpp"
#include "objects/empty.hpp"
#include "objects/food.hpp"
#include "objects/poison.hpp"
#include "objects/wall.hpp"
#include "world.hpp"

int
main()
{
    int n = 10;
    std::vector<std::vector<Cell*>> a(n, std::vector<Cell*>(n));

    World w;
    w.generate();

    sf::RenderWindow window(sf::VideoMode(1400, 950), "SFML works!");

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        w.draw(window);

        w.makeTurn();

        window.display();
    }
    return 0;
}