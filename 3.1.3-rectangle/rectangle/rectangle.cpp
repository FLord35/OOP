#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "consts.h"
#include "CRectangle.h"
#include "InputHandler.h"

struct Args
{
    std::string firstFileName;
    std::string secondFileName;
};

void OutputRectangleProperties(const CRectangle& rectangle, const std::string& rectangleName)
{
    std::cout << rectangleName << std::endl;

    std::cout << "  " << rct::OUTPUT_LEFT_TOP_STRING << "(" << rectangle.GetLeft() << ";" << rectangle.GetTop() << ")" << std::endl;
    std::cout << "  " << rct::OUTPUT_SIZE_STRING <<  rectangle.GetWidth() << "*" << rectangle.GetHeight() << std::endl;
    std::cout << "  " << rct::OUTPUT_RIGHT_BOTTOM_STRING << "(" << rectangle.GetRight() << ";" << rectangle.GetBottom() << ")" << std::endl;
    std::cout << "  " << rct::OUTPUT_AREA_STRING << rectangle.GetArea() << std::endl;
    std::cout << "  " << rct::OUTPUT_PERIMETER_STRING << rectangle.GetPerimeter() << std::endl;
}

Args ParseArgs(int argc, char* argv[])
{
    if (argc != 3) //Проверяем верное кол-во аргументов командной строки
    {
        throw std::string{ rct::INVALID_ARGUMENTS_MESSAGE + "\n" + rct::USAGE_MESSAGE + "\n"};
    }

    Args args;
    args.firstFileName = argv[1];
    args.secondFileName = argv[2];

    return args;
}

int main(int argc, char* argv[])
{
    try
    {
        auto args = ParseArgs(argc, argv);

        InputHandler firstInputHandler(args.firstFileName);
        CRectangle firstRectangle = firstInputHandler.ParseCommands();
        OutputRectangleProperties(firstRectangle, "Rectangle 1");

        InputHandler secondInputHandler(args.secondFileName);
        CRectangle secondRectangle = secondInputHandler.ParseCommands();
        OutputRectangleProperties(secondRectangle, "Rectangle 2");

        firstRectangle.Intersect(secondRectangle);
        OutputRectangleProperties(firstRectangle, "Intersection rectangle");
    }
    catch (std::string& errorMessage)
    {
        std::cout << errorMessage << std::endl;
        return 1;
    }

    return 0;
}
