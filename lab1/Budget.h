#ifndef OOP_LAB1_BUDGET_H
#define OOP_LAB1_BUDGET_H


class Budget {
public:
    Budget();
    Budget(double, double);

    double get_owned() const;

    double get_borrowed() const;

    double get_total() const;

    Budget& operator=(Budget rhs);

    bool operator==(Budget& rhs) const;

    bool operator!=(Budget& rhs) const;

    bool operator<(Budget& rhs) const;

    bool operator<=(Budget& rhs) const;

    bool operator>(Budget& rhs);

    bool operator>=(Budget& rhs);

    Budget operator+(Budget& rhs) const;

    Budget operator+=(Budget& rhs);

    Budget operator-(Budget& rhs) const;

    Budget operator-=(Budget& rhs);

    Budget operator*(Budget& rhs) const;

    Budget operator*(double rhs) const;

    Budget operator*=(Budget& rhs);

    Budget operator/(Budget& rhs) const;

    Budget operator/(double rhs) const;

    Budget operator/=(Budget& rhs);

private:
    double owned; // owned part of budget
    double borrowed; // borrowed part of budget

    // rounds to 2 decimal places
    void round_data();
};


#endif //OOP_LAB1_BUDGET_H
