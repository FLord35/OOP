#include "CCylinder.h"

CCylinder::CCylinder(double inputDensity, double inputBaseRadius, double inputHeight) :
	CBody()
{
	density = inputDensity;
	baseRadius = inputBaseRadius;
	height = inputHeight;

	volume = CalculateVolume();
	mass = CalculateMass();
}

double CCylinder::GetBaseRadius()
{
	return baseRadius;
}

double CCylinder::GetHeight()
{
	return height;
}

std::string CCylinder::ToString()
{
	return std::string{
		bd::OUTPUT_CYLINDER_NAME +
			"bR.h.: " +
			std::to_string(baseRadius) +
			", " +
			std::to_string(height) +
			"; d.v.m.: " +
			std::to_string(density) +
			", " +
			std::to_string(volume) +
			", " +
			std::to_string(mass)
	};
}

double CCylinder::CalculateVolume()
{
	return height * M_PI * pow(baseRadius, 2);
}

double CCylinder::CalculateMass()
{
	return density * volume;
}