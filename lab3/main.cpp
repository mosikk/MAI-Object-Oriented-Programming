/* Моисеенков Илья М8О-208Б-19
 *
 * github: mosikk
 *
 * Создать классы для геометрических фигур - Ромба, Пятиугольника и Шестиугольника. Все классы должны быть
 * наследниками класса Figure. В классах реализованы методы определения геометрического центра фигуры и
 * вычисления площадей. Переопределены функции для ввода и вывода фигур.
 *
 * В функции main создаётся вектор фигур. Пользователь может ввести любое количество разных фигур. Затем
 * для каждой фигуры из вектора выводятся ее координаты, площадь и геометрический центр. Вычисляется суммарная
 * площадь всех введенных фигур.
 *
 * Пользователь может удалить любое количество фигур из массива.
 *
 */

#include <iostream>
#include <vector>
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"

int main() {
    unsigned int amount;
    std::cout << "Enter the amount of figures you want to enter: " << std::endl;
    std::cin >> amount;

    std::vector<Figure *> figures;
    for (int i = 0; i < amount; ++i) {
        char type;
        do {
            std::cout << "Enter the type of figure (r - rhombus, p - pentagon, h - hexagon)" << std::endl;
            std::cin >> type;
            if (type != 'r' && type != 'R' && type != 'p' && type != 'P' && type != 'h' && type != 'H') {
                std::cout << "Incorrect type. Try again." << std::endl;
            }
        } while (type != 'r' && type != 'R' && type != 'p' && type != 'P' && type != 'h' && type != 'H');

        if (type == 'R' || type == 'r') {
            auto *R = new Rhombus;
            std::cout << "Enter vertices of this figure" << std::endl;
            std::cin >> *R;
            figures.push_back(R);
        } else if (type == 'P' || type == 'p') {
            auto *P = new Pentagon;
            std::cout << "Enter vertices of this figure" << std::endl;
            std::cin >> *P;
            figures.push_back(P);
        } else if (type == 'H' || type == 'h') {
            auto *H = new Hexagon;
            std::cout << "Enter vertices of this figure" << std::endl;
            std::cin >> *H;
            figures.push_back(H);
        }
    }
    std::cout << std::endl;

    double total_square = 0;
    std::cout << "List of figures:" << std::endl;
    for (auto &figure : figures) {
        std::cout << *figure << std::endl;
        double cur_square = figure->square();
        total_square += cur_square;
        std::cout << "Square: " << cur_square << std::endl;
        std::cout << "Center: " << figure->center() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Total square of figures is " << total_square << std::endl;
    std::cout << std::endl;

    unsigned int amount_delete;
    do {
        std::cout << "Enter the amount of figures you want to delete: " << std::endl;
        std::cin >> amount_delete;
        if (amount_delete > figures.size()) {
            std::cout << "Size of vector is less than your number. Try again" << std::endl;
        }
    } while (amount_delete > figures.size());
    std::cout << std::endl;

    for (int i = 0; i < amount_delete; ++i) {
        int id;
        do {
            std::cout << "Enter the id of figure you want to delete "
                         "(from " << 0 << " to " << figures.size() - 1 << "): " << std::endl;
            std::cin >> id;
            if (id < 0 || id >= figures.size()) {
                std::cout << "Wrong id. Try again" << std::endl;
            }
        } while (id < 0 || id >= figures.size());
        delete figures[id];
        figures.erase(figures.begin() + id);
    }
    std::cout << std::endl;

    std::cout << "List of remaining figures:" << std::endl;
    for (auto &figure : figures) {
        std::cout << *figure << std::endl;
        double cur_square = figure->square();
        total_square += cur_square;
        std::cout << "Square: " << cur_square << std::endl;
        std::cout << "Center: " << figure->center() << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    if (!figures.empty()) {
        std::cout << "Deleting remained figures:" << std::endl;
        for (auto &figure : figures) {
            delete figure;
        }
    }

}
