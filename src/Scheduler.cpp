#include "../inc/Scheduler.hpp"
Tasks SortR::schedule(std::vector<Task> tasks) {
    std::sort(tasks.begin(), tasks.end(), [](Task & task1, Task & task2)->bool {return task1.r<task2.r;});
    //for_each(tasks.begin(), tasks.end(), [](Task & task) {std::cout << task.r <<" ";}); //debug print
    return tasks;
}

Tasks Opt2::schedule(std::vector<Task> tasks) {
    //TODO: implement Opt2.
    return tasks;
}
