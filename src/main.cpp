#include "../inc/Cmax.hpp"
#include "../inc/CommandLineHandler.hpp"
#include "../inc/Scheduler.hpp"
#include "../inc/Witi.hpp"
#include "../neh/TaskNeh.hpp"
int main() {
    // CommandLineHandler::handleCommandLine(argc, argv);

    std::cout << "nehBasic ta001: " << nehBasic(readNehFile("ta001")) << std::endl;
    std::cout << "nehBasic ta005: " << nehBasic(readNehFile("ta005")) << std::endl;
    std::cout << "nehBasic ta010: " << nehBasic(readNehFile("ta010")) << std::endl;
    std::cout << "nehBasic ta020: " << nehBasic(readNehFile("ta020")) << std::endl;
    std::cout << "nehBasic ta025: " << nehBasic(readNehFile("ta025")) << std::endl;
    std::cout << "nehBasic ta030: " << nehBasic(readNehFile("ta100")) << std::endl;
    std::cout << "nehBasic ta050: " << nehBasic(readNehFile("ta050")) << std::endl;
    std::cout << "nehBasic ta075: " << nehBasic(readNehFile("ta075")) << std::endl;
    std::cout << "nehBasic ta090: " << nehBasic(readNehFile("ta090")) << std::endl;
    std::cout << "nehBasic ta100: " << nehBasic(readNehFile("ta100")) << std::endl;

    std::cout << "nehMod ta001: " << nehMod(readNehFile("ta001")) << std::endl;
    std::cout << "nehMod ta005: " << nehMod(readNehFile("ta005")) << std::endl;
    std::cout << "nehMod ta010: " << nehMod(readNehFile("ta010")) << std::endl;
    std::cout << "nehMod ta020: " << nehMod(readNehFile("ta020")) << std::endl;
    std::cout << "nehMod ta025: " << nehMod(readNehFile("ta025")) << std::endl;
    std::cout << "nehMod ta030: " << nehMod(readNehFile("ta100")) << std::endl;
    std::cout << "nehMod ta050: " << nehMod(readNehFile("ta050")) << std::endl;
    std::cout << "nehMod ta075: " << nehMod(readNehFile("ta075")) << std::endl;
    std::cout << "nehMod ta090: " << nehMod(readNehFile("ta090")) << std::endl;
    std::cout << "nehMod ta100: " << nehMod(readNehFile("ta100")) << std::endl;

    return 0;
}
