#include "InputHandler.h"

InputHandler::InputHandler(const std::string& inputFileName)
{
	inputStream.open(inputFileName);
	if (!inputStream.is_open())
	{
		throw std::string{ rct::FILE_OPENING_ERROR_MESSAGE + inputFileName + "\n" };
	}
}

CRectangle InputHandler::ParseCommands()
{
	CRectangle rectangle(0, 0, 0, 0);
	std::string line;
	std::stringstream streamLine;
	std::string command;

	while (!inputStream.eof())
	{
		std::getline(inputStream, line);
		command = line.substr(0, line.find(' '));
		line = line.substr(line.find(' ') + 1, line.length());
		streamLine.clear();

		streamLine.str(line);

		if (command == rct::INPUT_RECTANGLE_INITIALIZE_COMMAND)
		{
			int left;
			int top;
			int width;
			int height;

			streamLine >> left >> top >> width >> height;

			rectangle.SetLeft(left);
			rectangle.SetTop(top);
			rectangle.SetWidth(width);
			rectangle.SetHeight(height);
		}
		else if (command == rct::INPUT_RECTANGLE_MOVE_COMMAND)
		{
			int dx;
			int dy;

			streamLine >> dx >> dy;

			rectangle.Move(dx, dy);
		}
		else if (command == rct::INPUT_RECTANGLE_SCALE_COMMAND)
		{
			int sx;
			int sy;

			streamLine >> sx >> sy;

			rectangle.Scale(sx, sy);
		}
		else
		{
			throw std::string{ rct::INPUT_COMMAND_UNKNOWN_MESSAGE + command + "\n" };
		}
	}

	return rectangle;
}
