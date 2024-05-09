//Источники:
//1)https://www.youtube.com/watch?v=9oaWRls-d0I
//2)https://metanit.com/cpp/tutorial/6.1.php

#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <cstdint>

const std::string FIND_COMMAND = "-find";
const std::string USAGE_MESSAGE = "Usage:\n1)magic_numbers.exe\nOr\n2)magic_numbers.exe -find <number>";

struct Args
{
    std::string command;
    std::uint64_t numberArgument;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 1 || argc != 3) //Проверяем верное кол-во аргументов командной строки
    {
        throw std::string{"Invalid arguments count\n"};
    }

    if (argc == 3) //Смотрим, есть ли у нас аргументы
    {
        if (argv[1] != FIND_COMMAND)
        {
            throw std::string{"Invalid command\n"};
        }
        Args args;
        args.command = argv[1];
        args.numberArgument = (uint64_t)argv[2];
        return args;
    }
    else
    {
        return std::nullopt;
    }
}

void CheckMagicNumbers()
{
    
}

void FindMagicNumbers(std::optional<Args>& args)
{

}

int main(int argc, char* argv[])
{
    try
    {
        auto args = ParseArgs(argc, argv);
        if (args = std::nullopt)
        {
            CheckMagicNumbers();
        }
        else
        {
            FindMagicNumbers(args);
        }
    }
    catch (std::string& errorMessage)
    {
        std::cout << errorMessage << USAGE_MESSAGE << std::endl;
        return 1;
    }

    std::cout << std::endl;
    return 0;
}

