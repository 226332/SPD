#include "../inc/Cmax.hpp"

unsigned int calculateCmax(const Tasks & tasks) {
    std::vector<size_t> S(tasks.size());
    std::vector<size_t> C(tasks.size());
    S[0] = tasks[0].r;
    C[0] = S[0] + tasks[0].p;
    size_t Cmax = C[0]+ tasks[0].q;
    for (size_t i = 1; i < tasks.size(); i++) {
        S[i] = std::max(tasks[i].r, C[i - 1]);
        C[i] = S[i] + tasks[i].p;
        Cmax = std::max(Cmax, C[i] + tasks[i].q);
    }
    return Cmax;
}
