#pragma once
#include "CBody.h"
#define _USE_MATH_DEFINES
#include <math.h>

class CSphere : public CBody
{
	public:
		CSphere(double inputDensity, double inputRadius);

		double GetRadius();

		std::string ToString() override;

	private:
		double radius = 0.0;

		double CalculateVolume();
		double CalculateMass();
};

