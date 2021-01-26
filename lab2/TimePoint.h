/*
 * Класс TimePoint для работы с моментами времени в формате "час:минута:секунда". Реализованы операции
 * вычисления разницы между двумя моментами времени, суммы моментов времени, сложения момента времени и
 * заданного количества секунд, вычисления во сколько раз один момент больше (меньше) другого, сравнения
 * моментов времени, перевода в секунды и обратно, перевода в минуты и обратно.
 *
 * Операции сложения, вычитания и сравнения реализованы в виде перегрузки операторов. Реализован
 * пользовательский литерал для работы с константами типа TimePoint.
 */

#include <iostream>

#ifndef OOP_LAB2_TIMEPOINT_H
#define OOP_LAB2_TIMEPOINT_H


class TimePoint {
public:
    TimePoint();
    TimePoint(long long hh, long long mm, long long ss);

    long long get_hours() const;
    long long get_min() const;
    long long get_sec() const;
    void print_time() const;

    void set_hours(long long hh);
    void set_min(long long mm);
    void set_sec(long long ss);

    long long to_seconds() const; // converts the time moment to seconds
    long long to_minutes() const; // converts the time moment to minutes
    void set_by_seconds(long long seconds); // converts seconds to time moment
    void set_by_minutes(long long minutes); // converts minutes to time moment

    TimePoint& operator=(TimePoint rhs);
    bool operator==(TimePoint& rhs) const;
    bool operator!=(TimePoint& rhs) const;
    bool operator<(TimePoint& rhs) const;
    bool operator<=(TimePoint& rhs) const;
    bool operator>(TimePoint& rhs);
    bool operator>=(TimePoint& rhs);

    TimePoint operator+(TimePoint& rhs) const;
    TimePoint operator+(long long seconds) const;
    TimePoint operator-(TimePoint& rhs); // absolute difference between time points
    TimePoint operator-(long long seconds);
    double operator/(TimePoint& rhs) const;

private:
    long long hours;
    long long min;
    long long sec;

    void check_data(); // removes overflows and checks if data is positive
};


#endif //OOP_LAB2_TIMEPOINT_H
