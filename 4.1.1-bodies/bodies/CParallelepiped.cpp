#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double inputDensity, double inputWidth, double inputHeight, double inputDepth) :
	CBody()
{
	density = inputDensity;
	width = inputWidth;
	height = inputHeight;
	depth = inputDepth;

	volume = CalculateVolume();
	mass = CalculateMass();
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
