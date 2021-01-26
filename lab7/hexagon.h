
#ifndef OOP_LAB7_HEXAGON_H
#define OOP_LAB7_HEXAGON_H

#include "figure.h"

class hexagon : public figure {
public:
    hexagon() = default;

    hexagon(std::pair<double, double> &center, double rad) : figure(center), radius(rad) {}

    double square() override {
        return pow(radius, 2) * 3 * sqrt(3) * 0.5;
    }

    void print() override {
        std::cout << *this;
    }

    void write_to_file(std::ofstream &out) override {
        int id = 3;
        out.write((char *) &id, sizeof(int));
        out.write((char *) &center.first, sizeof(double));
        out.write((char *) &center.second, sizeof(double));
        out.write((char *) &radius, sizeof(double));
    }

    friend std::ostream &operator<<(std::ostream &out, hexagon &h);

private:
    double radius = 0;
};

std::ostream &operator<<(std::ostream &out, hexagon &h) {
    std::cout << "Hexagon {";
    double pi = acos(-1);
    for (int i = 0; i < 6; ++i) {
        double angle = pi * i / 3;
        std::cout.precision(2);
        std::cout << "(" << h.center.first + h.radius * cos(angle) << "; "
                  << h.center.second + h.radius * sin(angle) << ")";
        if (i != 5) {
            std::cout << ", ";
        }
    }
    std::cout << "}";
    return out;
}


#endif //OOP_LAB7_HEXAGON_H
