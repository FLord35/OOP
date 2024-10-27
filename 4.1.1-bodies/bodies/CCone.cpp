#include "CCone.h"

CCone::CCone(double inputDensity, double inputBaseRadius, double inputHeight) :
	CBody()
{
	density = inputDensity;
	baseRadius = inputBaseRadius;
	height = inputHeight;

	volume = CalculateVolume();
	mass = CalculateMass();
}

double CCone::GetBaseRadius()
{
	return baseRadius;
}

double CCone::GetHeight()
{
	return height;
}

std::string CCone::ToString()
{
	return std::string{
		bd::OUTPUT_CONE_NAME +
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

double CCone::CalculateVolume()
{
	return (height * M_PI * pow(baseRadius, 2)) / 3;
}

double CCone::CalculateMass()
{
	return density * volume;
}
