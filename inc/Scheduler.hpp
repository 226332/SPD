#pragma once
#include "StandardIncludes.hpp"
#include "Task.hpp"

class IScheduler {
public:
    virtual ~IScheduler() = default;
    virtual Tasks schedule(Tasks tasks) = 0;
};
class SchedulerFactory {
public:
    std::unique_ptr<IScheduler> createScheduler(std::string schedulerName);
};

class SortR: public IScheduler {
public:
    Tasks schedule(Tasks tasks) override;
};

class Opt2: public IScheduler {
public:
    Tasks schedule(Tasks tasks) override;
};

