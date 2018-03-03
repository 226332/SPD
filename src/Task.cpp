#include "../inc/Task.hpp"
Tasks readTaskFile(const std::string & fileName) {
    int n, lp;
    std::ifstream taskFile(fileName);

    if (taskFile.fail()) throw std::runtime_error("File: " + fileName + " doesn't exist!");

    taskFile >> n >> lp;
    std::vector<Task> tasks(n);

    for (auto & i : tasks) {
        taskFile >> i.r >> i.p >> i.q;
        //std::cout<<"i.r: "<< i.r<<" i.p:  "<< i.p<< " i.q: "<<i.q<<std::endl; //Debug only
    }
    return tasks;
}
