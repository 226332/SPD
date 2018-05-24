#pragma once
#include "../inc/StandardIncludes.hpp"
#include <numeric>
struct TaskNeh {
    std::vector<long> machines;
};

using TasksNeh = std::vector<TaskNeh>;

inline TasksNeh readNehFile(const std::string& fileName) {
    long n, m;
    std::string infilename;
    std::string ignore;
    std::ifstream taskFile("pliki/neh.txt");
    if(taskFile.fail()) throw std::runtime_error("File: pliki/neh.txt doesn't exist!");

    while(infilename != fileName) taskFile >> infilename;

    taskFile >> n >> m;

    TasksNeh tasks = std::vector<TaskNeh>(n);
    for(auto& i : tasks) {
        i = TaskNeh{ std::vector<long>(m) };
        for(auto& j : i.machines) { taskFile >> ignore >> j; }
    }
    return tasks;
}

inline long nehCMax(const TasksNeh& tasks) {
    int numOfMachines = tasks[0].machines.size();
    int numOfTasks = tasks.size();
    std::vector<long> times(numOfMachines);

    times[0] = tasks[0].machines[0];
    for(int i = 1; i < numOfMachines; i++) { times[i] = tasks[0].machines[i] + times[i - 1]; }

    for(int i = 1; i < numOfTasks; i++) {
        times[0] = tasks[i].machines[0];
        for(int j = 1; j < numOfMachines; j++) {
            if(times[j - 1] > times[j]) {
                times[j] = times[j - 1] + tasks[i].machines[j];
            } else {
                times[j] = times[j] + tasks[i].machines[j];
            }
        }
    }
    return times.back();
}

inline TaskNeh getLongestTask(std::list<TaskNeh>& tasks) {
    auto task = tasks.front();
    tasks.pop_front();
    return task;
}

inline void insertTaskToBestPosition(TasksNeh& permutation, const TaskNeh& task) {
    long tentativePosition = 0;
    long bestCMax = std::numeric_limits<decltype(bestCMax)>::max();
    for(size_t i = 0; i != permutation.size(); i++) {
        TasksNeh tentativePermutation(permutation);
        tentativePermutation.insert(tentativePermutation.begin() + 1, task);
        long cMax = nehCMax(permutation);
        if(cMax <= bestCMax) {
            bestCMax = cMax;
            tentativePosition = i;
        }
    }
    permutation.insert(permutation.begin() + tentativePosition, task);
}

inline long nehBasic(TasksNeh tasks) {
    TasksNeh permutation;
    permutation.reserve(tasks.size());

    // Step 1: Sort the n jobs in non-increasing order of their total processing times

    std::sort(tasks.begin(), tasks.end(), [](TaskNeh& a, TaskNeh& b) {
        long aSum = std::accumulate(a.machines.begin(), a.machines.end(), 0);
        long bSum = std::accumulate(b.machines.begin(), b.machines.end(), 0);
        return aSum < bSum;
    });

    // Step 2: Take the first two jobs and schedule them in order to minimise the
    // partial makespan as if there were only these two jobs

    TasksNeh permutation1 = { tasks[0], tasks[1] };
    TasksNeh permutation2 = { tasks[1], tasks[0] };
    long cMax1 = nehCMax(permutation1);
    long cMax2 = nehCMax(permutation2);

    if(cMax1 < cMax2)
        permutation = permutation1;
    else
        permutation = permutation2;

    // Step 3: For k = 3 to n do Step 4
    // Step 4: Insert the kth job at the place, which minimises the
    // partial makespan among the k possible ones.

    std::list<TaskNeh> remainingTasks(tasks.begin() + 2, tasks.end());
    while(!remainingTasks.empty()) {
        TaskNeh task = getLongestTask(remainingTasks);
        insertTaskToBestPosition(permutation, task);
    }

    return nehCMax(tasks);
}
