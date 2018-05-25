#pragma once
#include "../inc/StandardIncludes.hpp"
#include <cstring>
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
    long machineEndTime[tasks.size()][tasks[0].machines.size()];
    machineEndTime[0][0] = tasks[0].machines[0];

    for(size_t j = 1; j < tasks.size(); j++) {
        machineEndTime[j][0] = tasks[j].machines[0] + machineEndTime[j - 1][0];
    }

    for(size_t i = 1; i < tasks[0].machines.size(); i++) {
        machineEndTime[0][i] = tasks[0].machines[i] + machineEndTime[0][i - 1];
    }

    for(size_t j = 1; j < tasks.size(); j++) {
        for(size_t i = 1; i < tasks[0].machines.size(); i++) {
            machineEndTime[j][i] = std::max(machineEndTime[j][i - 1], machineEndTime[j - 1][i])
                + tasks[j].machines[i];
        }
    }
    return machineEndTime[tasks.size() - 1][tasks[0].machines.size() - 1];
}

inline TaskNeh getShortestTask(std::list<TaskNeh>& tasks) {
    auto task = tasks.front();
    tasks.pop_front();
    return task;
}

inline void insertTaskToBestPosition(TasksNeh& permutation, const TaskNeh& task) {
    long bestPosition = 0;
    long bestCMax = std::numeric_limits<decltype(bestCMax)>::max();
    for(size_t i = 0; i < permutation.size() + 1; i++) {
        TasksNeh tentativePermutation(permutation);
        tentativePermutation.insert(tentativePermutation.begin() + i, task);
        long cMax = nehCMax(tentativePermutation);
        if(cMax < bestCMax) {
            bestCMax = cMax;
            bestPosition = i;
        }
    }
    permutation.insert(permutation.begin() + bestPosition, task);
}

inline TaskNeh pickTaskWithHighestCMax(TasksNeh& permutation, const TaskNeh& task) {
    long bestPosition = 0;
    long bestCMax = std::numeric_limits<decltype(bestCMax)>::max();
    for(size_t i = 0; i < permutation.size(); i++) {
        TasksNeh tentativePermutation(permutation);
        tentativePermutation.erase(tentativePermutation.begin() + i);
        long cMax = nehCMax(tentativePermutation);
        if((cMax < bestCMax) && (task.machines != permutation[i].machines)) {
            bestCMax = cMax;
            bestPosition = i;
        }
    }
    TaskNeh result = permutation[bestPosition];
    permutation.erase(permutation.begin() + bestPosition);
    return result;
}

inline long nehBasic(TasksNeh tasks) {
    TasksNeh permutation;
    permutation.reserve(tasks.size());
    // Step 1: Sort the n jobs in non-increasing order of their total processing times

    std::sort(tasks.begin(), tasks.end(), [](TaskNeh& a, TaskNeh& b) {
        long aSum = std::accumulate(a.machines.begin(), a.machines.end(), 0);
        long bSum = std::accumulate(b.machines.begin(), b.machines.end(), 0);
        return aSum > bSum;
    });
    permutation.push_back(tasks[0]);

    // Step 2: For k = 2 to n do Step 4
    // Step 3: Insert the kth job at the place, which minimises the
    // partial makespan among the k possible ones.

    std::list<TaskNeh> remainingTasks(tasks.begin() + 1, tasks.end());
    while(!remainingTasks.empty()) {
        TaskNeh task = getShortestTask(remainingTasks);
        insertTaskToBestPosition(permutation, task);
    }
    return nehCMax(permutation);
}

inline long nehMod(TasksNeh tasks) {
    TasksNeh permutation;
    permutation.reserve(tasks.size());

    // Step 1: Sort the n jobs in non-increasing order of their total processing times

    std::sort(tasks.begin(), tasks.end(), [](TaskNeh& a, TaskNeh& b) {
        long aSum = std::accumulate(a.machines.begin(), a.machines.end(), 0);
        long bSum = std::accumulate(b.machines.begin(), b.machines.end(), 0);
        return aSum > bSum;
    });
    permutation.push_back(tasks[0]);

    // Step 2: For k = 3 to n do Step 4
    // Step 3: Insert the kth job at the place, which minimises the
    // partial makespan among the k possible ones.

    std::list<TaskNeh> remainingTasks(tasks.begin() + 1, tasks.end());
    while(!remainingTasks.empty()) {
        TaskNeh task = getShortestTask(remainingTasks);
        insertTaskToBestPosition(permutation, task);
        // krok 5: wybierz zadanie x i wstaw zadanie x na x pozycjach i wybierz to o
        // najmniejszej wartości Cmax, następnie wróć do kroku 3
        // 4. Zadanie, którego usunięcie spowoduję najwieksze zmniejszenie wartości Cmax.
        task = pickTaskWithHighestCMax(permutation, task);
        insertTaskToBestPosition(permutation, task);
    }

    return nehCMax(permutation);
}
