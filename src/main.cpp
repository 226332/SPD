//#include "../inc/Task.hpp"
#include "../inc/Scheduler.hpp"
#include "../inc/Cmax.hpp"

int main() {
    SortR scheduler;
	Opt2 scheduler2;
    Tasks tasks = readTaskFile(std::string("pliki/in100_3.txt"));
    std::cout << "SortR: " << calculateCmax(scheduler.schedule(tasks)) << std::endl;
    std::cout << "Unscheduled: : " << calculateCmax(tasks) << std::endl;
	std::cout << "Opt2: " << calculateCmax(scheduler2.schedule(tasks)) << std::endl;
	std::cout << "SortR+Opt2: " << calculateCmax(scheduler2.schedule(scheduler.schedule(tasks))) << std::endl;
}
