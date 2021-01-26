#pragma once

#include "figure.h"

class rhombus : public figure {
public:
    rhombus() = default;

    rhombus(std::pair<double, double>& center, double d1, double d2) : figure(center), diag1(d1), diag2(d2) {}

    double square() override {
        return diag1 * diag2 * 0.5;
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

    friend std::ostream& operator<<(std::ostream& out, rhombus& r);

private:
    double diag1 = 0;
    double diag2 = 0;
};

std::ostream& operator<<(std::ostream& out, rhombus& r) {
    out << "Rhombus {(" << r.center.first - r.diag1 * 0.5 << "; " << r.center.second << "), (";
    out << r.center.first << "; " << r.center.second + r.diag2 * 0.5 << "), (";
    out << r.center.first + r.diag1 * 0.5 << "; " << r.center.second << "), (";
    out << r.center.first << "; " << r.center.second - r.diag2 * 0.5 << ")}";
    return out;
}