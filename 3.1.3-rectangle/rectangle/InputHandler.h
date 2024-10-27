#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "consts.h"
#include "CRectangle.h"
class InputHandler
{
	public:
		InputHandler(const std::string& inputFileName);

		CRectangle ParseCommands();

	private:
		std::ifstream inputStream;
};

