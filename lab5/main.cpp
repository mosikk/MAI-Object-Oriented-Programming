/* Моисеенков И П М8О-208Б-19
 *
 * Реализовать шаблон класса "ромб" и шаблон динамической коллекции "стек".
 * Реализовать forward_iterator по коллекции.
 * Итератор должен быть совместим со стандартными алгоритмами
 */

#include <iostream>
#include <algorithm>

#include "rhombus.h"
#include "stack.h"

void print_menu() {
    std::cout << "1. Push rhombus to stack" << std::endl;
    std::cout << "2. Pop rhombus from the stack" << std::endl;
    std::cout << "3. Check the element on the top of the stack" << std::endl;
    std::cout << "4. Insert rhombus to the position" << std::endl;
    std::cout << "5. Erase rhombus from the position" << std::endl;
    std::cout << "6. Print all figures" << std::endl;
    std::cout << "7. Calculate the amount of figures with square less than ..." << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "(to add a rhombus type the in coords of the center and lengths of diagonals)" << std::endl;
    std::cout << std::endl;
}

int main() {
    stack<rhombus<int>> s;
    print_menu();
    char cmd;
    while (std::cin >> cmd) {
        if (cmd == '1') {
            rhombus<int> r;
            std::cin >> r;
            s.push(r);
            std::cout << "Pushed" << std::endl;

        }
        else if (cmd == '2') {
            try {
                s.pop();
                std::cout << "Popped" << std::endl;
            }
            catch (std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }
        }
        else if (cmd == '3') {
            try {
                auto t = s.top();
                std::cout << "Top: " << t << std::endl;
            }
            catch (std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }
        }
        else if (cmd == '4') {
            rhombus<int> r;
            std::cin >> r;
            unsigned int pos;
            std::cin >> pos;
            auto iter = s.begin();
            try {
                if (iter == s.end() && pos != 0) {
                    throw std::runtime_error("Invalid position");
                }
                for (unsigned int i = 0; i < pos; ++i) {
                    ++iter;
                    if (iter == s.end() && i != pos - 1) {
                        throw std::runtime_error("Invalid position");
                    }
                }
                s.insert(iter, r);
                std::cout << "Inserted" << std::endl;
            }
            catch (std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }
        }
        else if (cmd == '5') {
            unsigned int pos;
            std::cin >> pos;
            auto iter = s.begin();
            try {
                if (iter == s.end()) {
                    throw std::runtime_error("Invalid position");
                }
                for (unsigned int i = 0; i < pos; ++i) {
                    ++iter;
                    if (iter == s.end() && i != pos) {
                        throw std::runtime_error("Invalid position");
                    }
                }
                s.erase(iter);
                std::cout << "Erased" << std::endl;
            }
            catch (std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }
        }
        else if (cmd == '6') {
            std::for_each(s.begin(), s.end(), [](rhombus<int> r) {
                std::cout << r << std::endl;
            });

        }
        else if (cmd == '7') {
            double num;
            std::cin >> num;
            int count = std::count_if(s.begin(), s.end(), [num](auto &r) {
                return r.square() < num;
            });
            std::cout << "The amount of figures with square < " << num << " is " << count << std::endl;

        }
        else if (cmd == '0') {
            break;
        }
        else {
            std::cout << "Invalid cmd" << std::endl;
        }
    }
}
