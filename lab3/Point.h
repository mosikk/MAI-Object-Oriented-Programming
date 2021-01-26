#ifndef OOP_LAB3_POINT_H
#define OOP_LAB3_POINT_H

#include <iostream>
#include <cmath>

class Point {
public:
    Point(double x1 = 0.0, double y1 = 0.0);

    double length(Point &p) const;

    double x;
    double y;
};

std::ostream &operator<<(std::ostream &out, Point point);

std::istream &operator>>(std::istream &in, Point &point);


#endif //OOP_LAB3_POINT_H
