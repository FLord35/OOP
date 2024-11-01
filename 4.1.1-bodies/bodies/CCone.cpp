#include "CCone.h"

CCone::CCone(double inputDensity, double inputBaseRadius, double inputHeight) :
	CBody()
{
	density = inputDensity;
	baseRadius = inputBaseRadius;
	height = inputHeight;

	if (density < 0)
	{
		throw std::string(bd::DENSITY_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
	if (baseRadius < 0)
	{
		throw std::string(bd::BASE_RADIUS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
	if (height < 0)
	{
		throw std::string(bd::HEIGHT_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	if (baseRadius > (DBL_MAX / height / M_PI / baseRadius) * 3)
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
