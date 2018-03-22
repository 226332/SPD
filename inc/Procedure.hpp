#pragma once
#include "StandardIncludes.hpp"
#include "Scheduler.hpp"

class Procedure {
public:
    Procedure(const std::string& fileName, std::unique_ptr<IScheduler> scheduler) :
            scheduler(std::move(scheduler)), fileName(fileName) {
    }
    Procedure() = delete;

    void prepare() {
        tasks = readTaskFile(fileName);
    }

    void execute() {
        std::cout<<"shrage: "<<calculateCmax(scheduler->schedule(tasks))<<std::endl;
    }

private:
    std::unique_ptr<IScheduler> scheduler;
    std::string fileName;
    Tasks tasks;
};
