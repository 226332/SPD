#pragma once
#include "StandardIncludes.hpp"
#include "Scheduler.hpp"

class Shrage: public IScheduler {
public:
    Shrage(): readyTasks(compareQ) {}
    Tasks schedule(Tasks tasks) override;
protected:
    Task takeLongestReadyTask(std::list<Task>& tasks);
    constexpr static const auto compareQ = [](const Task& task1, const Task& task2) {return task1.q < task2.q;};
    std::priority_queue<Task, Tasks, decltype(compareQ)> readyTasks;

    long t = 0; //t
    Tasks permutation; //pi*
};

class ShrageSplit: public Shrage {
public:
    Tasks schedule(Tasks tasks) override;
protected:
    Task splitTask(Task& task, std::list<Task>& taskList);
};
