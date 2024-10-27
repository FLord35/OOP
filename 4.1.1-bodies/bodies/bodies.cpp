#include <iostream>
#include "LogicCoordinator.h"

int main()
{
    try
    {
        LogicCoordinator logicCoordinator;

        logicCoordinator.InputBodies();
        logicCoordinator.OutputBodies();
        logicCoordinator.OutputExtraProperties();
    }
    catch (std::string& errorMessage)
    {
        std::cout << errorMessage << std::endl;
        return 1;
    }

    return 0;
}
