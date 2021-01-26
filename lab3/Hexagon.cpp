#include "Hexagon.h"

Hexagon::Hexagon() {
    vertices.resize(6);
    name = "Hexagon";
    std::cout << "Created Hexagon!" << std::endl;
}

Hexagon::~Hexagon() {
    std::cout << "Deleting Hexagon..." << std::endl;
}

double Hexagon::square() {
    double side = vertices[0].length(vertices[1]);
    return pow(side, 2) * 3 * sqrt(3) / 2;
}


