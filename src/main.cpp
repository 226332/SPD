#include "../inc/Cmax.hpp"
#include "../inc/CommandLineHandler.hpp"
#include "../inc/Scheduler.hpp"
#include "../inc/Witi.hpp"
#include "../neh/TaskNeh.hpp"
int main() {
    // CommandLineHandler::handleCommandLine(argc, argv);

    std::cout << "ta001: " << nehBasic(readNehFile("ta001")) << std::endl;
    std::cout << "ta005: " << nehBasic(readNehFile("ta005")) << std::endl;
    std::cout << "ta010: " << nehBasic(readNehFile("ta010")) << std::endl;
    std::cout << "ta020: " << nehBasic(readNehFile("ta020")) << std::endl;
    std::cout << "ta025: " << nehBasic(readNehFile("ta025")) << std::endl;
    std::cout << "ta030: " << nehBasic(readNehFile("ta100")) << std::endl;
    std::cout << "ta050: " << nehBasic(readNehFile("ta050")) << std::endl;
    std::cout << "ta075: " << nehBasic(readNehFile("ta075")) << std::endl;
    std::cout << "ta090: " << nehBasic(readNehFile("ta090")) << std::endl;
    std::cout << "ta100: " << nehBasic(readNehFile("ta100")) << std::endl;

    return 0;
}
