#include "Point.h"


Point::Point(double x1, double y1) : x(x1), y(y1) {}

double Point::length(Point &p) const {
    return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}

std::ostream &operator<<(std::ostream &out, Point point) {
    std::cout.precision(3);
    out << "(" << point.x << ";" << point.y << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Point &point) {
    in >> point.x >> point.y;
    return in;
}
