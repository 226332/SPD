#include "../inc/Cmax.hpp"
#include "../inc/CommandLineHandler.hpp"
#include "../inc/Scheduler.hpp"
#include "../inc/Witi.hpp"
#include "../neh/TaskNeh.hpp"
int main() {

    std::cout << "Basic:, Modified:" << std::endl;

    std::cout << "ta001: " << nehBasic(readNehFile("ta001")) << " " << nehMod(readNehFile("ta001"))
              << std::endl;
    std::cout << "ta002: " << nehBasic(readNehFile("ta002")) << " " << nehMod(readNehFile("ta002"))
              << std::endl;
    std::cout << "ta003: " << nehBasic(readNehFile("ta003")) << " " << nehMod(readNehFile("ta003"))
              << std::endl;
    std::cout << "ta004: " << nehBasic(readNehFile("ta004")) << " " << nehMod(readNehFile("ta004"))
              << std::endl;
    std::cout << "ta005: " << nehBasic(readNehFile("ta005")) << " " << nehMod(readNehFile("ta005"))
              << std::endl;
    std::cout << "ta010: " << nehBasic(readNehFile("ta010")) << " " << nehMod(readNehFile("ta010"))
              << std::endl;
    std::cout << "ta020: " << nehBasic(readNehFile("ta020")) << " " << nehMod(readNehFile("ta020"))
              << std::endl;
    std::cout << "ta025: " << nehBasic(readNehFile("ta025")) << " " << nehMod(readNehFile("ta025"))
              << std::endl;
    std::cout << "ta030: " << nehBasic(readNehFile("ta030")) << " " << nehMod(readNehFile("ta030"))
              << std::endl;
    std::cout << "ta050: " << nehBasic(readNehFile("ta050")) << " " << nehMod(readNehFile("ta050"))
              << std::endl;
    std::cout << "ta075: " << nehBasic(readNehFile("ta075")) << " " << nehMod(readNehFile("ta075"))
              << std::endl;
    std::cout << "ta090: " << nehBasic(readNehFile("ta090")) << " " << nehMod(readNehFile("ta090"))
              << std::endl;
    std::cout << "ta100: " << nehBasic(readNehFile("ta100")) << " " << nehMod(readNehFile("ta100"))
              << std::endl;
    std::cout << "ta120: " << nehBasic(readNehFile("ta120")) << " " << nehMod(readNehFile("ta120"))
              << std::endl;

    return 0;
}
