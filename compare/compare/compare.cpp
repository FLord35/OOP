//Источники:
//1)https://www.youtube.com/watch?v=9oaWRls-d0I
//2)https://metanit.com/cpp/tutorial/6.1.php

#include <iostream>
#include <fstream>
#include <optional>
#include <string>

struct Args
{
    std::string firstFileName;
    std::string secondFileName;
};

Args ParseArgs(int argc, char* argv[])
{
    if (argc != 3) //Проверяем верное кол-во аргументов командной строки
    {
        throw std::string{"Invalid arguments count\nUsage: compare.exe <file 1 name> <file 2 name>"};
    }

    Args args;
    args.firstFileName = argv[1];
    args.secondFileName = argv[2];

    return args;
}

bool CompareStrings(std::ifstream& firstFile, std::ifstream& secondFile, int& line)
{

    std::string firstFileLine;
    std::string secondFileLine;
    while (std::getline(firstFile, firstFileLine) && std::getline(secondFile, secondFileLine))
    {
        if (firstFile.bad())
        {
            line = -1;
            return false;
        }

        if (secondFile.bad())
        {
            line = -2;
            return false;
        }

        line++;

        if (firstFileLine.compare(secondFileLine) != 0)
        {
            return false;
        }
    }

    return true;
}

void CompareFiles(Args& args)
{
    //Открываем первый файл
    std::ifstream firstFile;
    firstFile.open(args.firstFileName);
    if (!firstFile.is_open())
    {
        throw std::string{"Failed to open " + args.firstFileName + " for reading"};
    }

    //Открываем второй файл
    std::ifstream secondFile;
    secondFile.open(args.secondFileName);
    if (!firstFile.is_open())
    {
        throw std::string{"Failed to open " + args.secondFileName + " for reading"};
    }

    int lineCounter = 0;

    if (!CompareStrings(firstFile, secondFile, lineCounter))
    {
        if (lineCounter == -1)
        {
            throw std::string("Failed to read data from " + args.firstFileName + "\n");
        }
        if (lineCounter == -2)
        {
            throw std::string("Failed to read data from " + args.secondFileName + "\n");
        }
        throw lineCounter;
    }
}

int main(int argc, char* argv[])
{
    try
    {
        auto args = ParseArgs(argc, argv);
        CompareFiles(args);
    }
    catch (int mismatchLine)
    {
        std::cout << "Files are different. Line number is " << mismatchLine << std::endl;
        return 1;
    }
    catch(std::string& errorMessage)
    {
        std::cout << errorMessage << std::endl;
        return 2;
    }
    
    std::cout << "Files are equal";
    return 0;
}
