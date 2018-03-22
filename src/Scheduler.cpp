#include "../inc/Scheduler.hpp"
#include "../inc/Cmax.hpp"
Tasks SortR::schedule(Tasks tasks) {
    std::sort(tasks.begin(), tasks.end(), [](Task & task1, Task & task2)->bool {return task1.r<task2.r;});
    //for_each(tasks.begin(), tasks.end(), [](Task & task) {std::cout << task.r <<" ";}); //debug print
    return tasks;
}

Tasks Opt2::schedule(Tasks tasks) {
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
    } else if (schedulerName == "shrage") {
        return std::unique_ptr < IScheduler > (new Shrage());
    }
    throw std::runtime_error("Unknown scheduler: " + schedulerName);
}

Tasks Shrage::schedule(Tasks tasks) {
    size_t t = 0; //t
    // tasks is N here
    Tasks permutation; //pi*
    std::sort(tasks.begin(), tasks.end(), [](Task & task1, Task & task2)->bool {return task1.r>task2.r;}); //N = reverse sortR

    t = tasks.back().r + tasks.back().q;
    std::list<Task> taskList(tasks.begin(), tasks.end());

    permutation.push_back(taskList.back());
    taskList.pop_back();

    while (permutation.size() != tasks.size()) {
        permutation.push_back(takeLongestReadyTask(taskList, t));
    }
    return permutation;
}

Task Shrage::takeLongestReadyTask(std::list<Task>& tasks, size_t& t) {
    auto compareQ = [](const Task& task1, const Task& task2) {return task1.q>task2.q;};
    static std::priority_queue<Task, Tasks, decltype(compareQ)> readyTasks(compareQ);
    for (auto i = tasks.begin(); i != tasks.end(); i++) {
        if (i->r <= t) {
            readyTasks.push(*i);
        }
    }
    tasks.remove_if([&t](Task& task)->bool {return (task.r <= t);});

    Task longestTask;
    if (readyTasks.empty() && !tasks.empty()) {
        t = tasks.front().r;
        longestTask = takeLongestReadyTask(tasks, t);
    } else {
        longestTask = readyTasks.top();
        readyTasks.pop();
    }

    return longestTask;
}
