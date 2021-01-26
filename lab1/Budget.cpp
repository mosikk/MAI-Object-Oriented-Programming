#include <cmath>
#include "Budget.h"

Budget::Budget() : owned(0), borrowed(0) {}

Budget::Budget(double owned_, double borrowed_) : owned(owned_), borrowed(borrowed_) {
    round_data();
}

double Budget::get_owned() const {
    return owned;
}

double Budget::get_borrowed() const {
    return borrowed;
}

double Budget::get_total() const {
    return owned + borrowed;
}

Budget& Budget::operator=(Budget rhs) {
    owned = rhs.owned;
    borrowed = rhs.borrowed;
    return *this;
}

bool Budget::operator==(Budget &rhs) const {
    return owned == rhs.owned && borrowed == rhs.borrowed;
}

bool Budget::operator!=(Budget &rhs) const {
    return !(*this == rhs);
}

bool Budget::operator<(Budget &rhs) const {
    if (owned == rhs.owned) {
        return borrowed < rhs.borrowed;
    }
    return owned < rhs.owned;
}

bool Budget::operator<=(Budget &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

bool Budget::operator>(Budget &rhs) {
    return rhs < *this;
}

bool Budget::operator>=(Budget &rhs) {
    return rhs <= *this;
}

Budget Budget::operator+(Budget &rhs) const {
    return Budget(owned + rhs.owned, borrowed + rhs.borrowed);
}

Budget Budget::operator+=(Budget &rhs) {
    owned += rhs.owned;
    borrowed += rhs.borrowed;
    return *this;
}

Budget Budget::operator-(Budget &rhs) const {
    return Budget(owned - rhs.owned, borrowed - rhs.borrowed);
}

Budget Budget::operator-=(Budget &rhs) {
    owned -= rhs.owned;
    borrowed -= rhs.borrowed;
    return *this;
}

Budget Budget::operator*(Budget &rhs) const {
    return Budget(owned * rhs.owned, borrowed * rhs.borrowed);
}

Budget Budget::operator*(double rhs) const {
    return Budget(owned * rhs, borrowed * rhs);
}

Budget Budget::operator*=(Budget &rhs) {
    owned *= rhs.owned;
    borrowed *= rhs.borrowed;
    round_data();
    return *this;
}

Budget Budget::operator/(Budget &rhs) const {
    return Budget(owned / rhs.owned, borrowed / rhs.borrowed);
}

Budget Budget::operator/(double rhs) const {
    return Budget(owned / rhs, borrowed / rhs);
}

Budget Budget::operator/=(Budget &rhs) {
    owned /= rhs.owned;
    borrowed /= rhs.borrowed;
    round_data();
    return *this;
}

// round to 2 decimal places
void Budget::round_data() {
    owned = round(owned * 100) / 100;
    borrowed = round(borrowed * 100) / 100;
}
