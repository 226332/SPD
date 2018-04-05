#include "../inc/Shrage.hpp"

Tasks Shrage::schedule(Tasks tasks) {
    std::sort(tasks.begin(), tasks.end(), [](Task & task1, Task & task2)->bool {return task1.r>task2.r;}); //N = reverse sortR
    std::list<Task> taskList(tasks.begin(), tasks.end()); //N

    while (!(taskList.empty() && readyTasks.empty())) {
        Task best = takeLongestReadyTask(taskList);
        permutation.push_back(best);
        t += best.p;
    }
    return permutation;
}

Tasks ShrageSplit::schedule(Tasks tasks) {
    std::sort(tasks.begin(), tasks.end(), [](Task & task1, Task & task2)->bool {return task1.r>task2.r;}); //N = reverse sortR
    std::list<Task> taskList(tasks.begin(), tasks.end()); //N

    while (!(taskList.empty() && readyTasks.empty())) {
        Task best = takeLongestReadyTask(taskList);

        if ((taskList.back().r < t + best.p) && (taskList.back().q > best.q) && !taskList.empty())
            best = splitTask(best, taskList);

        permutation.push_back(best);
        t += best.p;

    }
    return permutation;
}

Task Shrage::takeLongestReadyTask(std::list<Task>& taskList) {
    for (auto i = taskList.rbegin(); i != taskList.rend(); i++)
        if (i->r <= t) readyTasks.push(*i);

    taskList.remove_if([this](Task& task)->bool {return (task.r <= t);});
    Task longestTask;

    if (readyTasks.empty() && !taskList.empty()) {
        t = taskList.back().r;
        longestTask = takeLongestReadyTask(taskList);
    } else {
        longestTask = readyTasks.top();
        readyTasks.pop();
    }

    return longestTask;
}

Task ShrageSplit::splitTask(Task& task, std::list<Task>& taskList) {
    taskList.push_back(Task { task.r, t + task.p - taskList.back().r, task.q });
    return Task { task.r, task.r - t, task.q };
}
