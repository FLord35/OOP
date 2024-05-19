//Источники:
//1)https://youtube.com/watch?v=rq3u1vIDasc
//2)https://youtube.com/watch?v=2bym1-QG3ZQ

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "prime_generator.h"

struct Args
{
    int upperBound;
};

Args ParseArgs(int argc, char* argv[])
{
    if (argc != 2) //Проверяем верное кол-во аргументов командной строки
    {
        throw std::string{INVALID_ARGUMENTS_MESSAGE + "\n" + USAGE_MESSAGE };
    }

    Args args;
    args.upperBound = std::stoi(argv[1]);

    return args;
}

int main(int argc, char* argv[])
{
    try
    {
        auto args = ParseArgs(argc, argv);
        OutputSet(GeneratePrimeNumbersSet(args.upperBound));
    }
    catch (std::string& errorMessage)
    {
        std::cout << errorMessage << std::endl;
        return 1;
    }

    return 0;
}
