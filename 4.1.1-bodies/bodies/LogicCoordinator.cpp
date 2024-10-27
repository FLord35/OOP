#include "LogicCoordinator.h"

LogicCoordinator::LogicCoordinator()
{
}

void LogicCoordinator::InputBodies()
{
	std::string bodyType;
	double density;

	std::cin >> bodyType;

	while (bodyType != bd::INPUT_EXIT_COMMAND)
	{
		if (bodyType == bd::INPUT_SPHERE_NAME)
		{
			double radius;

			std::cin >> density >> radius;

			CSphere sphere(density, radius);
			vectorOfBodies.push_back(std::make_shared<CSphere>(sphere));
		}
		else if (bodyType == bd::INPUT_PARALLELEPIPED_NAME)
		{
			double width;
			double height;
			double depth;

			std::cin >> density >> width >> height >> depth;

			CParallelepiped parallelepiped(density, width, height, depth);
			vectorOfBodies.push_back(std::make_shared<CParallelepiped>(parallelepiped));
		}
		else if (bodyType == bd::INPUT_CONE_NAME)
		{
			double baseRadius;
			double height;

			std::cin >> density >> baseRadius >> height;

			CCone cone(density, baseRadius, height);
			vectorOfBodies.push_back(std::make_shared<CCone>(cone));
		}
		else if (bodyType == bd::INPUT_CYLINDER_NAME)
		{
			double baseRadius;
			double height;

			std::cin >> density >> baseRadius >> height;

			CCylinder cylinder(density, baseRadius, height);
			vectorOfBodies.push_back(std::make_shared<CCylinder>(cylinder));
		}
		else
		{
			throw std::string{bd::ERROR_UNKNOWN_BODY_TYPE + bodyType + "\n"};
		}

		std::cin >> bodyType;
	}

	CalculateExtraProperties();
}

void LogicCoordinator::OutputBodies()
{
	std::cout << "OUTPUT: " << std::endl;

	for (auto& body : vectorOfBodies)
	{
		std::cout << body->ToString() << std::endl;
	}
}

void LogicCoordinator::OutputExtraProperties()
{
	std::cout << std::endl << "EXTRA OUTPUT: " << std::endl;

	std::cout << highestMassBodyIndex->ToString() << std::endl;
	std::cout << lightestInWaterBodyIndex->ToString() << std::endl;
}

void LogicCoordinator::CalculateExtraProperties()
{
	double currentMaxMass = -1.0;
	double currentMinWeight = std::numeric_limits<double>().max();

	for (auto& body : vectorOfBodies)
	{
		double mass = body->GetMass();
		double weight = (body->GetDensity() - bd::waterDensity) * bd::g * body->GetVolume();

		if (currentMaxMass < mass)
		{
			currentMaxMass = mass;
			highestMassBodyIndex = body;
		}

		if (currentMinWeight > weight)
		{
			currentMinWeight = weight;
			lightestInWaterBodyIndex = body;
		}
	}
}
