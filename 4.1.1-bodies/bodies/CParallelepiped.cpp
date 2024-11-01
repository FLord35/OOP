#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double inputDensity, double inputWidth, double inputHeight, double inputDepth) :
	CBody()
{
	density = inputDensity;
	width = inputWidth;
	height = inputHeight;
	depth = inputDepth;

	if (density < 0)
	{
		throw std::string(bd::DENSITY_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
	if (width < 0)
	{
		throw std::string(bd::WIDTH_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
	if (height < 0)
	{
		throw std::string(bd::HEIGHT_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
	if (depth < 0)
	{
		throw std::string(bd::DEPTH_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	if (width > DBL_MAX / height / depth)
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

double CParallelepiped::GetWidth()
{
	return width;
}

double CParallelepiped::GetHeight()
{
	return height;
}

double CParallelepiped::GetDepth()
{
	return depth;
}

std::string CParallelepiped::ToString()
{
	return std::string{
		bd::OUTPUT_PARALLELEPIPED_NAME +
		"w.h.d.: " +
		std::to_string(width) +
		", " +
		std::to_string(height) +
		", " +
		std::to_string(depth) +
		"; d.v.m.: " +
		std::to_string(density) +
		", " +
		std::to_string(volume) +
		", " +
		std::to_string(mass)
	};
}

double CParallelepiped::CalculateVolume()
{
	return width * height * depth;
}

double CParallelepiped::CalculateMass()
{
	return density * volume;
}
