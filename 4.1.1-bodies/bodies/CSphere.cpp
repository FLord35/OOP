#include "CSphere.h"

CSphere::CSphere(double inputDensity, double inputRadius) :
	CBody()
{
	density = inputDensity;
	radius = inputRadius;

	if (density < 0)
	{
		throw std::string(bd::DENSITY_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
	if (radius < 0)
	{
		throw std::string(bd::RADIUS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	if ((radius > (DBL_MAX / 4 / M_PI / pow(radius, 2)) * 3))
	{
		throw std::string(bd::VOLUME_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
	else
	{
		volume = CalculateVolume();
	}

	if (density > DBL_MAX / volume)
	{
		throw std::string(bd::MASS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
	else
	{
		mass = CalculateMass();
	}
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
