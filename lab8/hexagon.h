#pragma once

#include "figure.h"

class hexagon : public figure {
public:
    hexagon() = default;

    hexagon(std::pair<double, double>& center, double rad) : figure(center), radius(rad) {}

    double square() override {
        return pow(radius, 2) * 3 * sqrt(3) * 0.5;
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

    friend std::ostream& operator<<(std::ostream& out, hexagon& h);

private:
    double radius = 0;
};

std::ostream& operator<<(std::ostream& out, hexagon& h) {
    out << "Hexagon {";
    double pi = acos(-1);
    for (int i = 0; i < 6; ++i) {
        double angle = pi * i / 3;
        out.precision(2);
        out << "(" << h.center.first + h.radius * cos(angle) << "; "
            << h.center.second + h.radius * sin(angle) << ")";
        if (i != 5) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}