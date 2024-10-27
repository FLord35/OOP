#pragma once
#include <string>
#include "Constants.h"

class CBody
{
	public:
		CBody();

		double GetDensity();
		double GetVolume();
		double GetMass();
		virtual std::string ToString() = 0;

	protected:
		double density = 0.0;
		double volume = 0.0;
		double mass = 0.0;
};

