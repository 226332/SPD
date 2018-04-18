#pragma once
#include "StandardIncludes.hpp"

struct Task {
    long r;
    long p;
    long q;
};

struct TaskWiti{
    long p;
    long w;
    long d;
};

using Tasks = std::vector<Task>;
using TasksWiti = std::vector<TaskWiti>;

template <typename T>
inline std::vector<T> readTaskFile(const std::string & fileName){
    long n;
    std::ifstream taskFile(fileName);

    if (taskFile.fail()) throw std::runtime_error("File: " + fileName + " doesn't exist!");

    taskFile >> n;
    std::vector<T> tasks(n);
    long  fields[3];
    
    for (auto & i : tasks) {
        taskFile >> fields[0] >> fields[1] >> fields[2];
        i = {fields[0], fields[1], fields[2]};
        //std::cout<<"i.r: "<< i.r<<" i.p:  "<< i.p<< " i.q: "<<i.q<<std::endl; //Debug only
    }
    return tasks;
}

