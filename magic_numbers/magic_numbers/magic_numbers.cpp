//Источники:
//1)https://www.youtube.com/watch?v=9oaWRls-d0I
//2)https://metanit.com/cpp/tutorial/6.1.php
//3)https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c

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
    if (argc != 1 && argc != 3) //Проверяем верное кол-во аргументов командной строки
    {
        throw std::string{"Invalid arguments count\n" + USAGE_MESSAGE};
    }

    if (argc == 3) //Смотрим, есть ли у нас аргументы
    {
        if (argv[1] != FIND_COMMAND)
        {
            throw std::string{"Invalid command\n" + USAGE_MESSAGE};
        }
        std::optional<Args> args;
        args = { "temp" , 0 };
        args->command = argv[1];
        args->numberArgument = _strtoui64(argv[2], NULL, 10);
        return args;
    }
    else
    {
        return std::nullopt;
    }
}

bool IsNumberMagic(uint64_t& number) //Проверяем число на 'магические' свойства
{
    uint64_t numberRemnant = number;
    int sumOfDigits = 0;
    while (numberRemnant != 0)
    {
        sumOfDigits = sumOfDigits + (numberRemnant % 10);
        numberRemnant = numberRemnant / 10;
    }

    if ((number - sumOfDigits) % 9 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CheckMagicNumbers()
{
    std::string line;
    std::getline(std::cin, line);

    char* p;
    uint64_t convertedNumber = _strtoui64(line.c_str(), &p, 10);

    if (*p) //Число не соответствует типу uint64_t или вообще не является числом
    {
        throw std::string{"Error"};
    }
    else //Число соответствует типу uint64_t
    {
        if (IsNumberMagic(convertedNumber))
        {
            std::cout << "Magic" << std::endl;
        }
        else
        {
            std::cout << "Non-magic" << std::endl;
        }
    }
}

void FindMagicNumbers(uint64_t& maxNumber)
{
    for (uint64_t i = 1; i <= maxNumber; i++)
    {
        if (IsNumberMagic(i))
        {
            std::cout << i << std::endl;
        }
    }
}

int main(int argc, char* argv[])
{
    try
    {
        auto args = ParseArgs(argc, argv);
        if (!args)
        {
            CheckMagicNumbers();
        }
        else
        {
            FindMagicNumbers(args->numberArgument);
        }
    }
    catch (std::string& errorMessage)
    {
        std::cout << errorMessage << std::endl;
        return 1;
    }

    return 0;
}