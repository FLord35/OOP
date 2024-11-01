#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "CBody.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "CSphere.h"
#include "Constants.h"
#include <string>

class LogicCoordinator
{
	public:
		LogicCoordinator();

		void InputBodies(std::istream& inputStream);
		void OutputBodies(std::ostream& outputStream);

		void OutputExtraProperties(std::ostream& outputStream);

	private:
		std::vector<std::shared_ptr<CBody>> vectorOfBodies;
		std::shared_ptr<CBody> highestMassBodyIndex;
		std::shared_ptr<CBody> lightestInWaterBodyIndex = 0;

		void CalculateExtraProperties();
};

