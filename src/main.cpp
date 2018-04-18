#include "../inc/Scheduler.hpp"
#include "../inc/Cmax.hpp"
#include "../inc/CommandLineHandler.hpp"
#include "../inc/Witi.hpp"

int main(int argc, char* argv[]) {
    //CommandLineHandler::handleCommandLine(argc, argv);
    std::cout<<witiSum(readTaskFile<TaskWiti>("pliki/data10.txt"))<<std::endl;
}

