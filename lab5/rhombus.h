#ifndef OOP_LAB5_RHOMBUS_H
#define OOP_LAB5_RHOMBUS_H

#include <iostream>

template<class T>
class rhombus {
private:
    std::pair<T, T> center;
    double diagonal1;
    double diagonal2;
public:
    rhombus() : diagonal1(0), diagonal2(0) {
        center = std::make_pair(0, 0);
    }

    rhombus(T x_center, T y_center, double diag1, double diag2) : diagonal1(diag1), diagonal2(diag2) {
        center = std::make_pair(x_center, y_center);
    }

    double square() {
        return diagonal1 * diagonal2 * 0.5;
    }

    bool operator==(rhombus<T> &other) {
        if (center != other.center) {
            return false;
        }
        if (diagonal1 != other.diagonal1) {
            return false;
        }
        if (diagonal2 != other.diagonal2) {
            return false;
        }
        return true;
    }

    bool operator!=(rhombus<T> &other) {
        return !(*this == other);
    }

    template<class T1>
    friend std::ostream &operator<<(std::ostream &out, rhombus<T1> &r);

    template<class T1>
    friend std::istream &operator>>(std::istream &in, rhombus<T1> &r);


};

template<class T>
std::istream &operator>>(std::istream &in, rhombus<T> &r) {
    in >> r.center.first >> r.center.second >> r.diagonal1 >> r.diagonal2;
}

template<class T>
std::ostream &operator<<(std::ostream &out, rhombus<T> &r) {
    out << "Rhombus {(" << r.center.first - r.diagonal1 * 0.5 << "; " << r.center.second << "), (";
    out << r.center.first << "; " << r.center.second + r.diagonal2 * 0.5 << "), (";
    out << r.center.first + r.diagonal1 * 0.5 << "; " << r.center.second << "), (";
    out << r.center.first << "; " << r.center.second - r.diagonal2 * 0.5 << ")}";
}


#endif //OOP_LAB5_RHOMBUS_H
