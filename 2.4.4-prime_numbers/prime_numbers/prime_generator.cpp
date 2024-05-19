#include "prime_generator.h"

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
    CheckUpperBound(upperBound);

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
    std::cout << QUANTITY_MESSAGE << set.size() << "\n";

    for (int const& number : set)
    {
        std::cout << number << "\n";
    }
}