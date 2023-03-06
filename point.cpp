#include "point.hpp"

bool
Point::operator<(const Point& other) const
{
    if (x == other.x) return y < other.y;
    return x < other.x;
}
