#include "../inc/Scheduler.hpp"
#include "../inc/Cmax.hpp"
Tasks SortR::schedule(std::vector<Task> tasks) {
    std::sort(tasks.begin(), tasks.end(), [](Task & task1, Task & task2)->bool {return task1.r<task2.r;});
    //for_each(tasks.begin(), tasks.end(), [](Task & task) {std::cout << task.r <<" ";}); //debug print
    return tasks;
}

Tasks Opt2::schedule(std::vector<Task> tasks) {
    unsigned int best;
    best = calculateCmax(tasks);
    unsigned int k, i;
    k = 0;
    i = 1;
    while (k < (tasks.size() - 1)) {
        std::iter_swap(tasks.begin() + k, tasks.begin() + i);
        if (calculateCmax(tasks) >= best) {
            std::iter_swap(tasks.begin() + k, tasks.begin() + i);
            if (i == (tasks.size() - 1)) {
                k++;
                i = k + 1;
            } else
                i++;
        } else {
            best = calculateCmax(tasks);
            k = 0;
            i = 1;
        }
    }
    return tasks;
}

std::unique_ptr<IScheduler> SchedulerFactory::createScheduler(std::string schedulerName) {
    if (schedulerName.empty()) {
        throw std::runtime_error("no scheduler given!");
    } else if (schedulerName == "opt2") {
        return std::unique_ptr < IScheduler > (new Opt2());
    } else if (schedulerName == "sortR") {
        return std::unique_ptr < IScheduler > (new SortR());
    }
    throw std::runtime_error("Unknown scheduler: " + schedulerName);
}
