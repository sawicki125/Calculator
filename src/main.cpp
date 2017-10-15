#include "iostream"
#include "Calculator.hpp"


int main()
{
    Calculator cal;
    std::string input;
    std::getline(std::cin, input);
    while(input!="stop") {
        std::cout<< cal.count(input) << std::endl;
        std::getline(std::cin, input);
    }
    return 0;
}