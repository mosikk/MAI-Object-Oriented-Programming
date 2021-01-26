#pragma once

#include <cmath>
#include <fstream>

class figure {
public:
    figure() = default;

    figure(std::pair<double, double>& center_) : center(center_) {}

    virtual double square() = 0;

    virtual void print() = 0;

    virtual void print_to_file(std::ofstream&) = 0;

    std::pair<double, double> get_center() {
        return center;
    }

protected:
    std::pair<double, double> center;
};
