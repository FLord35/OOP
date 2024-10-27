#pragma once
#include "CBody.h"

class CParallelepiped : public CBody
{
	public:
		CParallelepiped(double inputDensity, double inputWidth, double inputHeight, double inputDepth);

		double GetWidth();
		double GetHeight();
		double GetDepth();

		std::string ToString() override;

	private:
		double width = 0.0;
		double height = 0.0;
		double depth = 0.0;

		double CalculateVolume();
		double CalculateMass();
};

