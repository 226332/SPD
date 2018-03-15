/*
 * Clock.h
 *
 *  Created on: 9 mar 2018
 *      Author: arek
 */

#pragma once
#include "StandardIncludes.hpp"
#include "Procedure.hpp"

class Clock {
public:
    Clock() = delete;
    Clock(const Clock &) = delete;
    Clock(const Clock &&) = delete;

    static void printDuration(std::chrono::duration<double> &&duration) {
        std::cout.precision(9);
        std::cout << std::fixed << duration.count() << std::endl;
    }

    static void measureTime(Procedure& procedure) {
        procedure.prepare();
        auto t2 = std::chrono::high_resolution_clock::now();
        procedure.execute();
        auto t1 = std::chrono::high_resolution_clock::now();
        t2 = std::chrono::high_resolution_clock::now();
        printDuration(std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1));
    }
};

