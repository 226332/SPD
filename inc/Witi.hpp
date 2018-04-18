#pragma once 
#include "StandardIncludes.hpp"
#include "Task.hpp"
inline long witiSum(TasksWiti tasks){
    long sum=0;
    long C=0;
    for (auto& t : tasks){
        C+=t.p;
        sum+=t.w*std::max(C-t.d,0l);
    }
    return sum;
}

