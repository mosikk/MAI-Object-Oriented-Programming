#ifndef OOP_LAB3_PENTAGON_H
#define OOP_LAB3_PENTAGON_H


#include "Figure.h"

class Pentagon : public Figure {
public:
    Pentagon();

    ~Pentagon() override;

    double square() override;
};


#endif //OOP_LAB3_PENTAGON_H
