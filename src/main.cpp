#include "../inc/Cmax.hpp"
#include "../inc/CommandLineHandler.hpp"
#include "../inc/Scheduler.hpp"
#include "../inc/Witi.hpp"
#include <bitset>
int main(int argc, char* argv[]) {
    // CommandLineHandler::handleCommandLine(argc, argv);

    TasksWiti tasks = readTaskFile<TaskWiti>("pliki/data10.txt");
    int a = (1 << tasks.size()) - 1;
    std::cout << calculateWiti(a, tasks) << std::endl;
}
