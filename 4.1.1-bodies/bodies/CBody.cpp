#include "CBody.h"

CBody::CBody()
{
}

double CBody::GetDensity()
{
	return density;
}

double CBody::GetVolume()
{
	return volume;
}

double CBody::GetMass()
{
	return mass;
}

double CBody::GetWeightInWater()
{
	return (density - bd::waterDensity) * bd::g * volume;
}
