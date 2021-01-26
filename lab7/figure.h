#ifndef OOP_LAB7_FIGURE_H
#define OOP_LAB7_FIGURE_H

#include <cmath>

class figure {
public:
    figure() = default;

    figure(std::pair<double, double> &center_) : center(center_) {}

    virtual double square() = 0;

    virtual void print() = 0;

    virtual void write_to_file(std::ofstream &out) = 0;

    std::pair<double, double> get_center() {
        return center;
    }

protected:
    std::pair<double, double> center;
};


#endif //OOP_LAB7_FIGURE_H
