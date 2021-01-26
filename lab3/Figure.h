#ifndef OOP_LAB3_FIGURE_H
#define OOP_LAB3_FIGURE_H

#include <iostream>
#include <vector>
#include "Point.h"

class Figure {
public:
    Figure();

    virtual ~Figure();

    Point center();

    virtual double square() = 0;

    friend std::ostream &operator<<(std::ostream &out, Figure &figure);

    friend std::istream &operator>>(std::istream &in, Figure &figure);

protected:
    std::vector<Point> vertices;
    std::string name;

    bool check_vertices();
};


#endif //OOP_LAB3_FIGURE_H
