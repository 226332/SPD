//#include "../inc/Task.hpp"
#include "../inc/Scheduler.hpp"
#include "../inc/Cmax.hpp"

int main() {
    SortR scheduler;
    Tasks tasks = readTaskFile(std::string("pliki/in10.txt"));
    std::cout << "SortR: " << calculateCmax(scheduler.schedule(tasks)) << std::endl;
    std::cout << "Unscheduled: : " << calculateCmax(tasks) << std::endl;
}
