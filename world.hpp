#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>

#include <vector>
#include <set>

#include "objects/cell.hpp"
#include "point.hpp"

class World
{
public:
    World();
    void generate();
    void draw(sf::RenderWindow& window);
    void makeTurn();
    


private:
    int n = 30, m = 40;
    std::vector<std::vector<Cell*>> a;
    std::set<Point> coord;
};
#endif