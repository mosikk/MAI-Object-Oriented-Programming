#include <iostream>
#include <tuple>
#include <cmath>

#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"


// prints a tuple
template<class T, int index>
typename std::enable_if<index >= std::tuple_size<T>::value, void>::type print_tuple(T &tuple) {
    std::cout << std::endl;
}

template<class T, int index>
typename std::enable_if<index < std::tuple_size<T>::value, void>::type print_tuple(T &tuple) {
    auto figure = std::get<index>(tuple);
    print(figure);
    print_tuple<T, index + 1>(tuple);
}


// prints a rhombus
template<class T>
typename std::enable_if<(sizeof(T::diag1) > 0), void>::type print(T &r) {
    std::cout.precision(2);
    std::cout << "Rhombus {(" << r.center.first + r.diag1 * 0.5 << "; " << r.center.second << "), (";
    std::cout << r.center.first << "; " << r.center.second + r.diag2 * 0.5 << "), (";
    std::cout << r.center.first - r.diag1 * 0.5 << "; " << r.center.second << "), (";
    std::cout << r.center.first << "; " << r.center.second - r.diag2 * 0.5 << ")}";
    std::cout << std::endl;
}

// prints a pentagon
template<class T>
typename std::enable_if<(sizeof(T::radius) > 0), void>::type print(T &p) {
    std::cout << "Pentagon {";
    double pi = acos(-1);
    for (int i = 0; i < 5; ++i) {
        double angle = 2 * pi * i / 5;
        std::cout.precision(2);
        std::cout << "(" << p.center.first + p.radius * cos(angle + pi / 10) << "; "
                  << p.center.second + p.radius * sin(angle + pi / 10) << ")";
        if (i != 4) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}

// prints a hexagon
template<class T>
typename std::enable_if<(sizeof(T::side) > 0), void>::type print(T &h) {
    std::cout << "Hexagon {";
    double pi = acos(-1);
    for (int i = 0; i < 6; ++i) {
        double angle = pi * i / 3;
        std::cout.precision(2);
        std::cout << "(" << h.center.first + h.side * cos(angle) << "; "
                  << h.center.second + h.side * sin(angle) << ")";
        if (i != 5) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}


// counts total square of figures in tuple
template<class T, int index>
typename std::enable_if<index >= std::tuple_size<T>::value, double>::type total_square(T &tuple) {
    return 0;
}

template<class T, int index>
typename std::enable_if<index < std::tuple_size<T>::value, double>::type total_square(T &tuple) {
    auto figure = std::get<index>(tuple);
    double cur_square = square(figure);
    return cur_square + total_square<T, index + 1>(tuple);
}

// counts a square of rhombus
template<class T>
typename std::enable_if<(sizeof(T::diag1) > 0), double>::type square(T &r) {
    return (r.diag1 + r.diag2) * 0.5;
}

// counts a square of pentagon
template<class T>
typename std::enable_if<(sizeof(T::radius) > 0), double>::type square(T &p) {
    double pi = acos(-1);
    double side = p.radius * cos(13 * pi / 10) - p.radius * cos(17 * pi / 10);
    return sqrt(25 + 10 * sqrt(5)) * pow(side, 2) * 0.25;
}

// counts a square of hexagon
template<class T>
typename std::enable_if<(sizeof(T::side) > 0), double>::type square(T &h) {
    return pow(h.side, 2) * 3 * sqrt(3) * 0.5;
}

int main() {
    // creating objects with figures
    Rhombus<int> r1;
    r1.center = {3, 5};
    r1.diag1 = 100;
    r1.diag2 = 1;

    Rhombus<double> r2;
    r2.center = {13.37, -36.2};
    r2.diag1 = 10;
    r2.diag2 = 2.74;

    Pentagon<int> p1;
    p1.center = {9, -9};
    p1.radius = 9;

    Pentagon<double> p2;
    p2.center = {0.01, 0.01};
    p2.radius = 0.25;

    Hexagon<int> h1;
    h1.center = {-5, -10};
    h1.side = 7.5;

    Hexagon<double> h2;
    h2.center = {12.34, -5.3};
    h2.side = 0.01;


    // creating tuple
    std::tuple<decltype(r1), decltype(p1), decltype(h1), decltype(r2), decltype(p2), decltype(h2)>
            tuple{r1, p1, h1, r2, p2, h2};

    print_tuple<decltype(tuple), 0>(tuple);
    std::cout << std::fixed << "Total square: " << total_square<decltype(tuple), 0>(tuple);
}