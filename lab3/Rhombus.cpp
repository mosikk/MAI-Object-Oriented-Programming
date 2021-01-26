#include "Rhombus.h"

Rhombus::Rhombus() {
    vertices.resize(4);
    name = "Rhombus";
    std::cout << "Created Rhombus!" << std::endl;
}

Rhombus::~Rhombus() {
    std::cout << "Deleting Rhombus..." << std::endl;
}

double Rhombus::square() {
    return (vertices[0].length(vertices[2]) * vertices[1].length(vertices[3])) / 2;
}

