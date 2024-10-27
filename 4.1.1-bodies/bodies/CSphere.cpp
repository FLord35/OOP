#include "CSphere.h"

CSphere::CSphere(double inputDensity, double inputRadius):
	CBody()
{
	density = inputDensity;
	radius = inputRadius;

	volume = CalculateVolume();
	mass = CalculateMass();
}

double CSphere::GetRadius()
{
	return radius;
}

std::string CSphere::ToString()
{
	return std::string{
		bd::OUTPUT_SPHERE_NAME + 
		"r: " + 
		std::to_string(radius) + 
		"; d.v.m.: " + 
		std::to_string(density) +
		", " +
		std::to_string(volume) +
		", " +
		std::to_string(mass)
	};
}

double CSphere::CalculateVolume()
{
	return (4 * M_PI * pow(radius, 3)) / 3;
}

double CSphere::CalculateMass()
{
	return density * volume;
}
