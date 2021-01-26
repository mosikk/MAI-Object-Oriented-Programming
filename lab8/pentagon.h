#pragma once

#include "figure.h"

class pentagon : public figure {
public:
    pentagon() = default;

    pentagon(std::pair<double, double>& center, double rad) : figure(center), radius(rad) {}

    double square() override {
        double pi = acos(-1);
        double side = radius * cos(13 * pi / 10) - radius * cos(17 * pi / 10);
        return sqrt(25 + 10 * sqrt(5)) * pow(side, 2) * 0.25;
    }

    void print() override {
        std::cout << *this << std::endl;
        std::cout << "Square: " << square() << std::endl;
        auto center = get_center();
        std::cout << "Center: (" << center.first << "; " << center.second << ")" << std::endl << std::endl;
    }

    void print_to_file(std::ofstream& out) override {
        out << *this << std::endl;
        out << "Square: " << square() << std::endl;
        auto center = get_center();
        out << "Center: (" << center.first << "; " << center.second << ")" << std::endl << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, pentagon& p);

private:
    double radius = 0;
};

std::ostream& operator<<(std::ostream& out, pentagon& p) {
    out << "Pentagon {";
    double pi = acos(-1);
    for (int i = 0; i < 5; ++i) {
        double angle = 2 * pi * i / 5;
        out.precision(2);
        out << "(" << p.center.first + p.radius * cos(angle + pi / 10) << "; "
            << p.center.second + p.radius * sin(angle + pi / 10) << ")";
        if (i != 4) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}