#include <iostream>
#include <sstream>
#include "CTime.h"

int main()
{
    try
    {
        CTime time(74730);
    }
    catch (std::string& errorMessage)
    {
        std::cout << errorMessage << std::endl;
        return 1;
    }

    return 0;
}
