#pragma once
#include "CBody.h"
#define _USE_MATH_DEFINES
#include <math.h>

class CCone : public CBody
{
	public:
		CCone(double inputDensity, double inputBaseRadius, double inputHeight);

		double GetBaseRadius();
		double GetHeight();

		std::string ToString() override;

	private:
		double baseRadius = 0.0;
		double height = 0.0;
	
		double CalculateVolume();
		double CalculateMass();
};

