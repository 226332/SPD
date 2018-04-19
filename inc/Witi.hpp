#include "StandardIncludes.hpp"
#include "Task.hpp"
#include <cmath>
inline long witiSum(TasksWiti tasks) {
    long sum = 0;
    long C = 0;
    for(auto& t : tasks) {
        C += t.p;
        sum += t.w * std::max(C - t.d, 0l);
    }
    return sum;
}

inline long calculateWiti(int i, const TasksWiti& tasks) {
    static std::map<int, int> knownValues;
    std::map<int, TaskWiti> permutation;
    std::list<long> witiParts;
    long pSum = 0;

    if(knownValues.count(i)) return knownValues[i];

    int mask = 1;
    for(size_t j = 0; j < tasks.size(); j++) {
        if(mask & i) {
            permutation[j] = tasks[j];
            pSum += tasks[j].p;
        }
        mask = mask << 1;
    }
    for(auto& p : permutation) {
        long witiPart = std::max(pSum - p.second.d, 0l) * p.second.w;
        int elemWiti = (i & (~(1 << p.first)));
        if(permutation.size() > 1) {
            std::cout << "elemWiti " << elemWiti << " i " << i << std::endl;
            witiPart += calculateWiti(elemWiti, tasks);
        }
        witiParts.push_back(witiPart);
    }
    long witi = *std::min_element(witiParts.begin(), witiParts.end());

    knownValues[i] = witi;
    return witi;
}
