#include "LogicCoordinator.h"

LogicCoordinator::LogicCoordinator()
{
}

void LogicCoordinator::InputBodies(std::istream& inputStream)
{
	std::string bodyType;
	double density;

	inputStream >> bodyType;

	while (bodyType != bd::INPUT_EXIT_COMMAND)
	{
		if (bodyType == bd::INPUT_SPHERE_NAME)
		{
			double radius;

			inputStream >> density >> radius;

			CSphere sphere(density, radius);
			vectorOfBodies.push_back(std::make_shared<CSphere>(sphere));
		}
		else if (bodyType == bd::INPUT_PARALLELEPIPED_NAME)
		{
			double width;
			double height;
			double depth;

			inputStream >> density >> width >> height >> depth;

			CParallelepiped parallelepiped(density, width, height, depth);
			vectorOfBodies.push_back(std::make_shared<CParallelepiped>(parallelepiped));
		}
		else if (bodyType == bd::INPUT_CONE_NAME)
		{
			double baseRadius;
			double height;

			inputStream >> density >> baseRadius >> height;

			CCone cone(density, baseRadius, height);
			vectorOfBodies.push_back(std::make_shared<CCone>(cone));
		}
		else if (bodyType == bd::INPUT_CYLINDER_NAME)
		{
			double baseRadius;
			double height;

			inputStream >> density >> baseRadius >> height;

			CCylinder cylinder(density, baseRadius, height);
			vectorOfBodies.push_back(std::make_shared<CCylinder>(cylinder));
		}
		else
		{
			throw std::string{bd::UNKNOWN_BODY_TYPE_EXCEPTION_MESSAGE + bodyType + "\n"};
		}

		inputStream >> bodyType;
	}

	CalculateExtraProperties();
}

void LogicCoordinator::OutputBodies(std::ostream& outputStream)
{
	outputStream << "OUTPUT:" << std::endl;

	for (auto& body : vectorOfBodies)
	{
		outputStream << body->ToString() << std::endl;
	}
}

void LogicCoordinator::OutputExtraProperties(std::ostream& outputStream)
{
	outputStream << "EXTRA OUTPUT:" << std::endl;

	outputStream << highestMassBodyIndex->ToString() << std::endl;
	outputStream << lightestInWaterBodyIndex->ToString() << std::endl;
}

void LogicCoordinator::CalculateExtraProperties()
{
	double currentMaxMass = -1.0;
	double currentMinWeight = std::numeric_limits<double>().max();

	using ptr = std::shared_ptr<CBody>;

	auto massCompareFunction = [](ptr left, ptr right) 
	{
		return left->GetMass() < right->GetMass(); 
	};

	highestMassBodyIndex = *std::max_element(vectorOfBodies.begin(), vectorOfBodies.end(), massCompareFunction);

	auto weightCompareFunction = [](ptr left, ptr right) 
	{
		return left->GetWeightInWater() < right->GetWeightInWater();
	};

	lightestInWaterBodyIndex = *std::min_element(vectorOfBodies.begin(), vectorOfBodies.end(), weightCompareFunction);

	/*for (auto& body : vectorOfBodies)
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
	}*/
}
