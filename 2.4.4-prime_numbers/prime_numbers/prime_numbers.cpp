//Источники:
//1)https://youtube.com/watch?v=rq3u1vIDasc

#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <cstdint>
#include <set>
#include <vector>

const std::string INVALID_ARGUMENTS_MESSAGE("Invalid arguments count");
const std::string USAGE_MESSAGE("Usage: prime_numbers.exe <upper bound>");

const int MAX_UPPER_BOUND = 100000000;

const std::string NUMBER_TOO_LOW_MESSAGE("Your upper boundary is too low, it should be greater than 1");
const std::string NUMBER_TOO_LARGE_MESSAGE("Your upper boundary is too large, it should be lower or equal to " + std::to_string(MAX_UPPER_BOUND));

const std::string QUANTITY_MESSAGE("Quantity: ");

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

void CheckUpperBound(int upperBound)
{
    if (upperBound <= 1)
    {
        throw std::string(NUMBER_TOO_LOW_MESSAGE);
    }
    if (upperBound > MAX_UPPER_BOUND)
    {
        throw std::string(NUMBER_TOO_LARGE_MESSAGE);
    }
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
    std::set<int> setOfPrimeNumbers;
    std::vector<bool> vectorOfPrimeEntries(upperBound + 1, true);

    vectorOfPrimeEntries[0] = false;
    vectorOfPrimeEntries[1] = false;

    int i = 2;

    for (i; pow(i, 2) <= upperBound; i++)
    {
        if (vectorOfPrimeEntries[i])
        {
            setOfPrimeNumbers.insert(i);

            for (int j = pow(i, 2); j <= upperBound; j = j + i)
            {
                vectorOfPrimeEntries[j] = false;
            }
        }
    }

    for (i; i <= upperBound; i++)
    {
        if (vectorOfPrimeEntries[i])
        {
            setOfPrimeNumbers.insert(i);
        }
    }

    return setOfPrimeNumbers;
}

void OutputSet(std::set<int> set)
{
    for (int const& number : set)
    {
        std::cout << number << "\n";
    }

    std::cout << "\n" << QUANTITY_MESSAGE << set.size() << "\n";
}

int main(int argc, char* argv[])
{
    try
    {
        auto args = ParseArgs(argc, argv);
        CheckUpperBound(args.upperBound);
        OutputSet(GeneratePrimeNumbersSet(args.upperBound));
    }
    catch (std::string& errorMessage)
    {
        std::cout << errorMessage << std::endl;
        return 1;
    }

    return 0;
}
