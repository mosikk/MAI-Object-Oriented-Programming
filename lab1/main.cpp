/* Моисеенков Илья М8О-208Б-19
 *
 * github: mosikk
 *
 * Создать класс Budget для работы с бюджетом. Класс состоит из двух вещественных чисел (a,b).
 * Где a – собственная часть средств бюджета в рублях, b – заемная часть средств бюджета рублях.
 * Оба числа должны округляться до второго знака после запятой.
 * Реализовать арифметические операции сложения, вычитания, умножения и деления,
 * а также операции сравнения.
 */


#include <iostream>
#include <fstream>
#include "Budget.h"

int main() {
    std::cout << "Let's create 2 objects for demonstration of class methods." << std::endl;
    std::string files_name;
    std::cout << "Type in the name of file with data you want to use ";
    std::cout << "(e.g test1.txt) or type 'skip' to enter them yourself: ";
    std::cin >> files_name;
    double own_a, borrow_a, own_b, borrow_b;
    if (files_name != "skip") {
        std::ifstream input;
        input.open(files_name);
        input >> own_a >> borrow_a >> own_b >> borrow_b;
    }
    else {
        std::cout << "Enter owned and borrowed parts for budget 'a': ";
        std::cin >> own_a >> borrow_a;
        std::cout << "Enter owned and borrowed parts for budget 'b': ";
        std::cin >> own_b >> borrow_b;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    Budget a(own_a, borrow_a);
    Budget b(own_b, borrow_b);
    std::cout << "So we have budget a: " << a.get_owned() << " & " << a.get_borrowed() << std::endl;
    std::cout << "Total budget a: " << a.get_total() << std::endl;
    std::cout << "And budget b: " << b.get_owned() << " & " << b.get_borrowed() << std::endl;
    std::cout << "Total budget b: " << b.get_total() << std::endl << std::endl;

    if (a != b) {
        std::cout << "a is not equal to b: ";
        if (a > b) {
            std::cout << "a is greater than b" << std::endl;
        }
        else {
            std::cout << "a is lower than b" << std::endl;
        }
    }
    else {
        std::cout << "a is equal to b" << std::endl;
    }
    std::cout << std::endl;

    Budget sum = a + b;
    Budget difference = a - b;
    Budget product = a * b;
    Budget quotient = a / b;
    std::cout << "Sum of budgets is " << sum.get_owned() << " & " << sum.get_borrowed() << std::endl;
    std::cout << "Difference between budgets is " << difference.get_owned() << " & ";
    std::cout << difference.get_borrowed() << std::endl;
    std::cout << "Product of budgets is " << product.get_owned() << " & " << product.get_borrowed() << std::endl;
    std::cout << "Quotient of budgets is " << quotient.get_owned() << " & " << quotient.get_borrowed();
    std::cout << std::endl << std::endl;

    std::cout << "We can multiply the initial budget a by 2" << std::endl;
    a = a * 2;
    std::cout << "We'll get " << a.get_owned() << " & " << a.get_borrowed() << std::endl;
    std::cout << "And let's divide budget b by 3" << std::endl;
    b = b / 3;
    std::cout << "We'll get " << b.get_owned() << " & " << b.get_borrowed() << std::endl << std::endl;
}
