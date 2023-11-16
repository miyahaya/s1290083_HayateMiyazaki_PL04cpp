#ifndef K_CLOSESTH
#define K_CLOSEST_H

#include <iostream>
#include<vector>

struct Point
{
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};

class Compare
{
public:
    bool operator()(const Point& p1, const Point& p2);
};

std::vector<Point> find_k_closest(const std::vector<Point>& points, int k);

#endif