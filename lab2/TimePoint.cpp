/*
 * Класс TimePoint для работы с моментами времени в формате "час:минута:секунда". Реализованы операции
 * вычисления разницы между двумя моментами времени, суммы моментов времени, сложения момента времени и
 * заданного количества секунд, вычисления во сколько раз один момент больше (меньше) другого, сравнения
 * моментов времени, перевода в секунды и обратно, перевода в минуты и обратно.
 *
 * Операции сложения, вычитания и сравнения реализованы в виде перегрузки операторов. Реализован
 * пользовательский литерал для работы с константами типа TimePoint.
 */

#include "TimePoint.h"

#include <iostream>

TimePoint::TimePoint() : hours(0), min(0), sec(0) {}

TimePoint::TimePoint(long long hh, long long mm, long long ss) : hours(hh), min(mm), sec(ss) {
    check_data();
}

long long TimePoint::get_hours() const {
    return hours;
}

long long TimePoint::get_min() const {
    return min;
}

long long TimePoint::get_sec() const {
    return sec;
}

void TimePoint::print_time() const {
    std::cout << hours << ":";
    std::cout.fill('0');
    std::cout.width(2);
    std::cout << min << ":";
    std::cout.fill('0');
    std::cout.width(2);
    std::cout << sec << std::endl;
}

void TimePoint::set_hours(long long hh) {
    hours = hh;
    check_data();
}

void TimePoint::set_min(long long mm) {
    min = mm;
    check_data();
}

void TimePoint::set_sec(long long ss) {
    sec = ss;
    check_data();
}

// converts the time moment to seconds
long long TimePoint::to_seconds() const {
    return hours * 3600 + min * 60 + sec;
}

// converts the time moment to minutes
long long TimePoint::to_minutes() const {
    return hours * 60 + min + (sec >= 30);
}

// converts seconds to time moment
void TimePoint::set_by_seconds(long long int seconds) {
    hours = seconds / 3600;
    seconds %= 3600;
    min = seconds / 60;
    seconds %= 60;
    sec = seconds;
    check_data();
}

// converts minutes to time moment
void TimePoint::set_by_minutes(long long int minutes) {
    hours = minutes / 60;
    min = minutes % 60;
    check_data();
}

// removes overflows and checks if data is positive
void TimePoint::check_data() {
    if (sec < 0 || min < 0 || hours < 0) {
        std::cerr << "TimePoint can't be negative!" << std::endl;
        exit(1);
    }
    if (sec > 59) {
        min += sec / 60;
        sec %= 60;
    }
    if (min > 59) {
        hours += min / 60;
        min %= 60;
    }
}

TimePoint &TimePoint::operator=(TimePoint rhs) {
    hours = rhs.hours;
    min = rhs.min;
    sec = rhs.sec;
    return *this;
}

bool TimePoint::operator==(TimePoint &rhs) const {
    return hours == rhs.hours && min == rhs.min && sec == rhs.sec;
}

bool TimePoint::operator!=(TimePoint &rhs) const {
    return !(*this == rhs);
}

bool TimePoint::operator<(TimePoint &rhs) const {
    if (hours != rhs.hours) {
        return hours < rhs.hours;
    }
    if (min != rhs.min) {
        return min < rhs.min;
    }
    return sec < rhs.sec;
}

bool TimePoint::operator<=(TimePoint &rhs) const {
    return *this < rhs || *this == rhs;
}

bool TimePoint::operator>(TimePoint &rhs) {
    return rhs < *this;
}

bool TimePoint::operator>=(TimePoint &rhs) {
    return rhs <= *this;
}

TimePoint TimePoint::operator+(TimePoint &rhs) const {
    return TimePoint(hours + rhs.hours, min + rhs.min, sec + rhs.sec);
}

TimePoint TimePoint::operator+(long long int seconds) const {
    return TimePoint(hours, min, sec + seconds);
}

// absolute difference between time points
TimePoint TimePoint::operator-(TimePoint &rhs) {
    if (rhs > *this) {
        return rhs - *this;
    }
    // *this <= rhs
    long long h = hours - rhs.hours;
    long long m = min - rhs.min;
    long long s = sec - rhs.sec;
    if (s < 0) { // if seconds are negative we should convert some minutes to seconds
        m += s / 60 - 1;
        s = s % 60 + 60;
    }
    if (m < 0) { // same for minutes and hours
        h += m / 60 - 1;
        m = m % 60 + 60;
    }
    TimePoint result(h, m, s);
    result.check_data();
    return result;
}

TimePoint TimePoint::operator-(long long int seconds) {
    if (to_seconds() < seconds) { // we can't make subtraction then
        std::cerr << "Subtrahend is greater than minuend. Time moment can't be negative!" << std::endl;
        exit(2);
    }
    TimePoint tmp(0, 0, seconds);
    return *this - tmp;
}

double TimePoint::operator/(TimePoint &rhs) const {
    return (double)to_seconds() / (double)rhs.to_seconds();
}



