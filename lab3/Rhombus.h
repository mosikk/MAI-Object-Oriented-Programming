#ifndef OOP_LAB3_RHOMBUS_H
#define OOP_LAB3_RHOMBUS_H


#include <vector>
#include "Figure.h"

class Rhombus : public Figure {
public:
    Rhombus();

    ~Rhombus() override;

    double square() override;
};


#endif //OOP_LAB3_RHOMBUS_H
