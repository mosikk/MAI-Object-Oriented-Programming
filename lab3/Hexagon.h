#ifndef OOP_LAB3_HEXAGON_H
#define OOP_LAB3_HEXAGON_H


#include "Figure.h"

class Hexagon : public Figure {
public:
    Hexagon();

    ~Hexagon() override;

    double square() override;
};


#endif //OOP_LAB3_HEXAGON_H
