#pragma once
#include "StandardIncludes.hpp"
#include "Task.hpp"

class IScheduler {
public:
    virtual ~IScheduler() = default;
    virtual Tasks schedule(Tasks tasks) = 0;
};

class SortR: IScheduler {
public:
    Tasks schedule(Tasks tasks) override;
};

class Opt2: IScheduler {
public:
    Tasks schedule(Tasks tasks) override;
};

