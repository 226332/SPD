/*
 * CommandLineHandler.hpp
 *
 *  Created on: 15 mar 2018
 *      Author: arek
 */

#pragma once
#include "StandardIncludes.hpp"
#include <unistd.h>
#include "Scheduler.hpp"
#include "Procedure.hpp"
#include "Clock.hpp"

class CommandLineHandler {
    inline static std::string fileName;
    inline static std::string schedulerName;

    inline static void readCommandLine(const int &argc, char* argv[]) {
        int opt = 0;

        while ((opt = getopt(argc, argv, "f:s:")) != -1) {
            switch (opt) {

            case 'f':
                fileName = optarg;
                break;

            case 's': //scheduler
                schedulerName = optarg;
                break;

            case '?':
                std::cerr << "Unknown FLAG! : " << opt << std::endl;
                break;
            }
        }
    }

    inline static void executeCommandLine() {
        SchedulerFactory factory;
        Procedure procedure(fileName, factory.createScheduler(schedulerName));
        Clock::measureTime(procedure);
    }
public:

    inline static void handleCommandLine(const int &argc, char* argv[]) {
        readCommandLine(argc, argv);
        executeCommandLine();
    }

};

