#include <iostream>
#include <sstream>
#include "LogicCoordinator.h"

int main()
{
    try
    {
        LogicCoordinator logicCoordinator;

        logicCoordinator.InputBodies(std::cin);
        logicCoordinator.OutputBodies(std::cout);
        logicCoordinator.OutputExtraProperties(std::cout);
    }
    catch (std::string& errorMessage)
    {
        std::cout << errorMessage << std::endl;
        return 1;
    }

    return 0;
}
