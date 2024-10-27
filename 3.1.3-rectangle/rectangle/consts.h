#pragma once
#include <string>

namespace rct
{
	const std::string INVALID_ARGUMENTS_MESSAGE("Invalid arguments count");
	const std::string USAGE_MESSAGE("Usage: rectangle.exe <first file> <second file>");

	const std::string FILE_OPENING_ERROR_MESSAGE("Could not open file: ");

	const std::string INPUT_RECTANGLE_INITIALIZE_COMMAND("Rectangle");
	const std::string INPUT_RECTANGLE_MOVE_COMMAND("Move");
	const std::string INPUT_RECTANGLE_SCALE_COMMAND("Scale");

	const std::string INPUT_COMMAND_UNKNOWN_MESSAGE("This command is unknown: ");

	const std::string OUTPUT_LEFT_TOP_STRING("Left top: ");
	const std::string OUTPUT_SIZE_STRING("Size: ");
	const std::string OUTPUT_RIGHT_BOTTOM_STRING("Right bottom: ");
	const std::string OUTPUT_AREA_STRING("Area: ");
	const std::string OUTPUT_PERIMETER_STRING("Perimeter: ");

	struct Coordinates
	{
		int x = 0;
		int y = 0;
	};

	struct DoubleCoordinates
	{
		double x = 0;
		double y = 0;
	};
}