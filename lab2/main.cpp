/* Моисеенков Илья М8О-208Б-19
 *
 * github: mosikk
 *
 * Создать класс TimePoint для работы с моментами времени в формате "час:минута:секунда". Реализовать операции
 * вычисления разницы между двумя моментами времени, суммы моментов времени, сложения момента времени и
 * заданного количества секунд, вычисления во сколько раз один момент больше (меньше) другого, сравнения
 * моментов времени, перевода в секунды и обратно, перевода в минуты и обратно.
 *
 * Операции сложения, вычитания и сравнения реализовать в виде перегрузки операторов. Реализовать
 * пользовательский литерал для работы с константами типа TimePoint.
 */

#include <iostream>
#include <fstream>

#include "TimePoint.h"

TimePoint operator"" _time(unsigned long long seconds) {
    TimePoint time;
    time.set_by_seconds((long long)seconds);
    return time;
}

int main() {
    std::string files_name;
    std::cout << "Enter the name of test file (e.g. test1.txt) or type skip to enter data yourself: ";
    std::cin >> files_name;
    std::cout << std::endl;
    int hh1, mm1, ss1, hh2, mm2, ss2;
    if (files_name != "skip") {
        std::ifstream input;
        input.open(files_name);
        input >> hh1 >> mm1 >> ss1 >> hh2 >> mm2 >> ss2;
    }
    else {
        std::cout << "Enter hours, minutes, seconds for time point 1: ";
        std::cin >> hh1 >> mm1 >> ss1;
        std::cout << std::endl;
        std::cout << "Enter hours, minutes, seconds for time point 2: ";
        std::cin >> hh2 >> mm2 >> ss2;
        std::cout << std::endl;
    }
    TimePoint time1(hh1, mm1, ss1);
    TimePoint time2;
    time2.set_hours(hh2);
    time2.set_min(mm2);
    time2.set_sec(ss2);
    std::cout << "We have time1: ";
    time1.print_time();
    std::cout << "And time2: ";
    time2.print_time();
    std::cout << std::endl;

    TimePoint sum = time1 + time2;
    std::cout << "Sum of time moments: ";
    sum.print_time();
    TimePoint diff = time1 - time2;
    std::cout << "Difference between times: ";
    diff.print_time();
    double quotient = time1 / time2;
    std::cout << "Time1 / Time2 is " << quotient << std::endl;
    std::cout << std::endl;

    long long seconds1 = time1.to_seconds();
    long long seconds2 = time2.to_seconds();
    std::cout << "Convert time1 to seconds: " << seconds1 << std::endl;
    std::cout << "Convert time2 to seconds: " << seconds2 << std::endl;

    TimePoint time1_seconds;
    TimePoint time2_seconds;
    time1_seconds.set_by_seconds(seconds1);
    time2_seconds.set_by_seconds(seconds2);
    std::cout << "If we convert seconds back to time points we'll get: " << std::endl;
    std::cout << "New time1: ";
    time1_seconds.print_time();
    std::cout << "New time2: ";
    time2_seconds.print_time();
    if (time1 == time1_seconds && time2 == time2_seconds) {
        std::cout << "We got same time points!" << std::endl;
    }
    else {
        std::cout << "The didn't get same time points. Error occurred!" << std::endl;
    }
    std::cout << std::endl;

    TimePoint time3 = time1 + seconds2;
    std::cout << "Now we'll add time2 converted to seconds to time 1" << std::endl;
    std::cout << "We got: ";
    time3.print_time();
    if (time3 == sum) {
        std::cout << "We got same time point as (time1 + time2)!" << std::endl;
    }
    else {
        std::cout << "The didn't get the same time point. Error occurred!" << std::endl;
    }
    std::cout << std::endl;

    TimePoint time4 = time3 - seconds1;
    std::cout << "Now we'll subtract time1 converted to seconds from the time point above" << std::endl;
    std::cout << "We got: ";
    time4.print_time();
    if (time4 == time2) {
        std::cout << "We got same time point as time2!" << std::endl;
    }
    else {
        std::cout << "The didn't get the same time point. Error occurred!" << std::endl;
    }
    std::cout << std::endl;

    long long minutes1 = time1.to_minutes();
    long long minutes2 = time2.to_minutes();
    std::cout << "Convert time1 to minutes: " << minutes1 << std::endl;
    std::cout << "Convert time2 to minutes: " << minutes2 << std::endl;

    TimePoint time1_minutes;
    TimePoint time2_minutes;
    time1_minutes.set_by_minutes(minutes1);
    time2_minutes.set_by_minutes(minutes2);
    std::cout << "If we convert minutes back to time points we'll get: " << std::endl;
    std::cout << "New time1: ";
    time1_minutes.print_time();
    std::cout << "New time2: ";
    time2_minutes.print_time();
    std::cout << std::endl;

    std::cout << "Finally, we'll try to create '3600_time' literal:" << std::endl;
    TimePoint time5 = 3600_time;
    time5.print_time();

}