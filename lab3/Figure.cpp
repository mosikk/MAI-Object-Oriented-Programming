#include "Figure.h"


Figure::Figure() {
    std::cout << "Creating figure..." << std::endl;
    name = "Unknown";
}

Figure::~Figure() {
    std::cout << "Figure was successfully deleted!" << std::endl;
}

Point Figure::center() {
    double x_mid = 0, y_mid = 0;
    for (Point &point : vertices) {
        x_mid += point.x;
        y_mid += point.y;
    }
    return Point(x_mid / vertices.size(), y_mid / vertices.size());
}

bool Figure::check_vertices() {
    double figure_length = vertices[0].length(vertices[vertices.size() - 1]);
    for (int i = 0; i < vertices.size() - 1; ++i) {
        double cur_length = vertices[i].length(vertices[i + 1]);
        if (std::abs(cur_length - figure_length) >= 1e-2) {
            std::cout << "Figure must have equal sides. Try again!" << std::endl;
            return false;
        }
        if (figure_length == 0) {
            std::cout << "Points should be different. Try again!" << std::endl;
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, Figure &figure) {
    out << figure.name << " { ";
    for (Point &point : figure.vertices) {
        out << point << " ";
    }
    out << "}";
    return out;
}

std::istream &operator>>(std::istream &in, Figure &figure) {
    do {
        for (auto &vertex : figure.vertices) {
            in >> vertex;
        }
    } while (!figure.check_vertices());
    return in;
}

