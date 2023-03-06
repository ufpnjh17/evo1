#ifndef POINT_HPP
#define POINT_HPP

struct Point
{
    int x, y;

    bool operator<(const Point& other) const;
};

#endif