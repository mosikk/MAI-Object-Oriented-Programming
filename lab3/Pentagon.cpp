#include "Pentagon.h"

Pentagon::Pentagon() {
    vertices.resize(5);
    name = "Pentagon";
    std::cout << "Created Pentagon!" << std::endl;
}

Pentagon::~Pentagon() {
    std::cout << "Deleting Pentagon..." << std::endl;
}

double Pentagon::square() {
    double side = vertices[0].length(vertices[1]);
    return sqrt(25 + 10 * sqrt(5)) * pow(side, 2) / 4;
}

