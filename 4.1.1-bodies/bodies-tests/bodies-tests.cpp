#include <iostream>
#include <string>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch.hpp"
#include "..\bodies\CBody.h"
#include "..\bodies\CCylinder.h"
#include "..\bodies\CCone.h"
#include "..\bodies\CParallelepiped.h"
#include "..\bodies\CSphere.h"
#include "..\bodies\LogicCoordinator.h"

//TODO: Протестировать LogicCoordinator

SCENARIO("Creating invalid shapes")
{
	//SPHERE
	WHEN("Creating an sphere with invalid parameters is attempted (density is negative)")
	{
		CHECK_THROWS_WITH(CSphere(-3800.0, 5.0), bd::DENSITY_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	WHEN("Creating an sphere with invalid parameters is attempted (radius is negative)")
	{
		CHECK_THROWS_WITH(CSphere(3800.0, -5.0), bd::RADIUS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	//PARALLELEPIPED
	WHEN("Creating a parallelepiped with invalid parameters is attempted (density is negative)")
	{
		CHECK_THROWS_WITH(CParallelepiped(-3800.0, 5.0, 6.0, 7.0), bd::DENSITY_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	WHEN("Creating an parallelepiped with invalid parameters is attempted (width is negative)")
	{
		CHECK_THROWS_WITH(CParallelepiped(3800.0, -5.0, 6.0, 7.0), bd::WIDTH_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	WHEN("Creating an parallelepiped with invalid parameters is attempted (height is negative)")
	{
		CHECK_THROWS_WITH(CParallelepiped(3800.0, 5.0, -6.0, 7.0), bd::HEIGHT_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	WHEN("Creating an parallelepiped with invalid parameters is attempted (depth is negative)")
	{
		CHECK_THROWS_WITH(CParallelepiped(3800.0, 5.0, 6.0, -7.0), bd::DEPTH_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	//CYLINDER
	WHEN("Creating a cylinder with invalid parameters is attempted (density is negative)")
	{
		CHECK_THROWS_WITH(CCylinder(-3800.0, 5.0, 6.0), bd::DENSITY_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	WHEN("Creating a cylinder with invalid parameters is attempted (base radius is negative)")
	{
		CHECK_THROWS_WITH(CCylinder(3800.0, -5.0, 6.0), bd::BASE_RADIUS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	WHEN("Creating a cylinder with invalid parameters is attempted (height is negative)")
	{
		CHECK_THROWS_WITH(CCylinder(3800.0, 5.0, -6.0), bd::HEIGHT_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	//CYLINDER
	WHEN("Creating a cone with invalid parameters is attempted (density is negative)")
	{
		CHECK_THROWS_WITH(CCone(-3800.0, 5.0, 6.0), bd::DENSITY_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	WHEN("Creating a cone with invalid parameters is attempted (base radius is negative)")
	{
		CHECK_THROWS_WITH(CCone(3800.0, -5.0, 6.0), bd::BASE_RADIUS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	WHEN("Creating a cone with invalid parameters is attempted (height is negative)")
	{
		CHECK_THROWS_WITH(CCone(3800.0, 5.0, -6.0), bd::HEIGHT_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
}

SCENARIO("Creating shapes and testing their functions")
{
	//SPHERE
	WHEN("Sphere is created and initialised")
	{
		THEN("We can get its parameters")
		{
			double density = 3800.0;
			double radius = 5.0;

			CSphere sphere(density, radius);

			CHECK(sphere.GetDensity() == density);
			CHECK(sphere.GetRadius() == radius);
			CHECK(sphere.GetVolume() == (4 * M_PI * pow(sphere.GetRadius(), 3)) / 3);
			CHECK(sphere.GetMass() == density * sphere.GetVolume());
			CHECK(sphere.ToString() == std::string{
				bd::OUTPUT_SPHERE_NAME +
				"r: " +
				std::to_string(sphere.GetRadius()) +
				"; d.v.m.: " +
				std::to_string(sphere.GetDensity()) +
				", " +
				std::to_string(sphere.GetVolume()) +
				", " +
				std::to_string(sphere.GetMass())
			});
		}
	}

	WHEN("Sphere is created and initialised (with volume exceeding)")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CSphere(3800.0, DBL_MAX), bd::VOLUME_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("Sphere is created and initialised (with mass exceeding)")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CSphere(DBL_MAX, 5.0), bd::MASS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	//PARALLELEPIPED
	WHEN("Parallelepiped is created and initialised")
	{
		THEN("We can get its parameters")
		{
			double density = 3800.0;
			double width = 5.0;
			double height = 6.0;
			double depth = 7.0;

			CParallelepiped parallelepiped(density, width, height, depth);

			CHECK(parallelepiped.GetDensity() == density);
			CHECK(parallelepiped.GetWidth() == width);
			CHECK(parallelepiped.GetHeight() == height);
			CHECK(parallelepiped.GetDepth() == depth);
			CHECK(parallelepiped.GetVolume() == parallelepiped.GetWidth() * parallelepiped.GetHeight() * parallelepiped.GetDepth());
			CHECK(parallelepiped.GetMass() == density * parallelepiped.GetVolume());
			CHECK(parallelepiped.ToString() == std::string{
				bd::OUTPUT_PARALLELEPIPED_NAME +
				"w.h.d.: " +
				std::to_string(parallelepiped.GetWidth()) +
				", " +
				std::to_string(parallelepiped.GetHeight()) +
				", " +
				std::to_string(parallelepiped.GetDepth()) +
				"; d.v.m.: " +
				std::to_string(parallelepiped.GetDensity()) +
				", " +
				std::to_string(parallelepiped.GetVolume()) +
				", " +
				std::to_string(parallelepiped.GetMass())
			});
		}
	}

	WHEN("Parallelepiped is created and initialised (with volume exceeding)")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CParallelepiped(3800.0, DBL_MAX, 6.0, 7.0), bd::VOLUME_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("Parallelepiped is created and initialised (with mass exceeding)")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CParallelepiped(DBL_MAX, 5.0, 6.0, 7.0), bd::MASS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	//CYLINDER
	WHEN("Cylinder is created and initialised")
	{
		THEN("We can get its parameters")
		{
			double density = 3800.0;
			double baseRadius = 5.0;
			double height = 7.0;

			CCylinder cylinder(density, baseRadius, height);

			CHECK(cylinder.GetDensity() == density);
			CHECK(cylinder.GetBaseRadius() == baseRadius);
			CHECK(cylinder.GetHeight() == height);
			CHECK(cylinder.GetVolume() == height * M_PI * pow(baseRadius, 2));
			CHECK(cylinder.GetMass() == density * cylinder.GetVolume());
			CHECK(cylinder.ToString() == std::string{
				bd::OUTPUT_CYLINDER_NAME +
				"bR.h.: " +
				std::to_string(cylinder.GetBaseRadius()) +
				", " +
				std::to_string(cylinder.GetHeight()) +
				"; d.v.m.: " +
				std::to_string(cylinder.GetDensity()) +
				", " +
				std::to_string(cylinder.GetVolume()) +
				", " +
				std::to_string(cylinder.GetMass())
			});
		}
	}

	WHEN("Cylinder is created and initialised (with volume exceeding)")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CCylinder(3800.0, DBL_MAX, 6.0), bd::VOLUME_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("Cylinder is created and initialised (with mass exceeding)")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CCylinder(DBL_MAX, 5.0, 6.0), bd::MASS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	//CONE
	WHEN("Cylinder is created and initialised")
	{
		THEN("We can get its parameters")
		{
			double density = 3800.0;
			double baseRadius = 5.0;
			double height = 7.0;

			CCone cone(density, baseRadius, height);

			CHECK(cone.GetDensity() == density);
			CHECK(cone.GetBaseRadius() == baseRadius);
			CHECK(cone.GetHeight() == height);
			CHECK(cone.GetVolume() == (height * M_PI * pow(baseRadius, 2)) / 3);
			CHECK(cone.GetMass() == density * cone.GetVolume());
			CHECK(cone.ToString() == std::string{
				bd::OUTPUT_CONE_NAME +
					"bR.h.: " +
					std::to_string(cone.GetBaseRadius()) +
					", " +
					std::to_string(cone.GetHeight()) +
					"; d.v.m.: " +
					std::to_string(cone.GetDensity()) +
					", " +
					std::to_string(cone.GetVolume()) +
					", " +
					std::to_string(cone.GetMass())
			});
		}
	}

	WHEN("Cone is created and initialised (with volume exceeding)")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CCone(3800.0, DBL_MAX, 6.0), bd::VOLUME_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("Cone is created and initialised (with mass exceeding)")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CCone(DBL_MAX, 5.0, 6.0), bd::MASS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}
}

SCENARIO("Testing LogicCoordinator's work")
{
	WHEN("Multiple shapes are created")
	{
		THEN("We can get the full list of objects in the output stream including their mass and volume")
		{
			LogicCoordinator logicCoordinator;
			std::stringstream inStream("SPHERE 3800 5 \n PARALLELEPIPED 6000 5 6 8 \n CYLINDER 2000 5 14 \n CONE 13800 6 8 \n EXIT");
			std::stringstream outStream;
			std::string outputString = "OUTPUT:\n";
			outputString += "SPHERE: r: 5.000000; d.v.m.: 3800.000000, 523.598776, 1989675.347274\n";
			outputString += "PARALLELEPIPED: w.h.d.: 5.000000, 6.000000, 8.000000; d.v.m.: 6000.000000, 240.000000, 1440000.000000\n";
			outputString += "CYLINDER: bR.h.: 5.000000, 14.000000; d.v.m.: 2000.000000, 1099.557429, 2199114.857513\n";
			outputString += "CONE: bR.h.: 6.000000, 8.000000; d.v.m.: 13800.000000, 301.592895, 4161981.947476\n";

			logicCoordinator.InputBodies(inStream);
			logicCoordinator.OutputBodies(outStream);

			CHECK(outStream.str() == outputString);
		}
	}

	WHEN("Multiple shapes are created. Cylinder goes overboard with its parameters (volume will be out of range)")
	{
		THEN("We should get an exception")
		{
			LogicCoordinator logicCoordinator;
			std::string inputString = "SPHERE 3800 5 \n PARALLELEPIPED 6000 5 6 8 \n CYLINDER 2000 ";
			inputString += std::to_string(DBL_MAX);
			inputString += " 14 \n CONE 13800 6 8 \n EXIT";

			std::stringstream inStream(inputString);
			std::stringstream outStream;

			CHECK_THROWS_WITH(logicCoordinator.InputBodies(inStream), bd::VOLUME_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("Multiple shapes are created. Cylinder goes overboard with its parameters (mass will be out of range)")
	{
		THEN("We should get an exception")
		{
			LogicCoordinator logicCoordinator;
			std::string inputString = "SPHERE 3800 5 \n PARALLELEPIPED 6000 5 6 8 \n CYLINDER ";
			inputString += std::to_string(DBL_MAX);
			inputString += " 5 14 \n CONE 13800 6 8 \n EXIT";

			std::stringstream inStream(inputString);
			std::stringstream outStream;

			CHECK_THROWS_WITH(logicCoordinator.InputBodies(inStream), bd::MASS_OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("Multiple shapes are created")
	{
		THEN("We can get the extra list of two objects with the highest mass and the lowest weight")
		{
			LogicCoordinator logicCoordinator;
			std::stringstream inStream("SPHERE 3800 5 \n PARALLELEPIPED 6000 5 6 8 \n CYLINDER 2000 5 14 \n CONE 13800 6 8 \n EXIT");
			std::stringstream outStream;
			std::string outputString = "EXTRA OUTPUT:\n";
			outputString += "CONE: bR.h.: 6.000000, 8.000000; d.v.m.: 13800.000000, 301.592895, 4161981.947476\n";
			outputString += "CYLINDER: bR.h.: 5.000000, 14.000000; d.v.m.: 2000.000000, 1099.557429, 2199114.857513\n";

			logicCoordinator.InputBodies(inStream);
			logicCoordinator.OutputExtraProperties(outStream);

			CHECK(outStream.str() == outputString);
		}
	}

	WHEN("Multiple shapes are created")
	{
		THEN("We can get the full list of objects in the output stream including their mass and volume plus extra list")
		{
			LogicCoordinator logicCoordinator;
			std::stringstream inStream("SPHERE 3800 5 \n PARALLELEPIPED 6000 5 6 8 \n CYLINDER 2000 5 14 \n CONE 13800 6 8 \n EXIT");
			std::stringstream outStream;
			std::string outputString = "OUTPUT:\n";
			outputString += "SPHERE: r: 5.000000; d.v.m.: 3800.000000, 523.598776, 1989675.347274\n";
			outputString += "PARALLELEPIPED: w.h.d.: 5.000000, 6.000000, 8.000000; d.v.m.: 6000.000000, 240.000000, 1440000.000000\n";
			outputString += "CYLINDER: bR.h.: 5.000000, 14.000000; d.v.m.: 2000.000000, 1099.557429, 2199114.857513\n";
			outputString += "CONE: bR.h.: 6.000000, 8.000000; d.v.m.: 13800.000000, 301.592895, 4161981.947476\n";
			outputString += "EXTRA OUTPUT:\n";
			outputString += "CONE: bR.h.: 6.000000, 8.000000; d.v.m.: 13800.000000, 301.592895, 4161981.947476\n";
			outputString += "CYLINDER: bR.h.: 5.000000, 14.000000; d.v.m.: 2000.000000, 1099.557429, 2199114.857513\n";

			logicCoordinator.InputBodies(inStream);
			logicCoordinator.OutputBodies(outStream);
			logicCoordinator.OutputExtraProperties(outStream);

			CHECK(outStream.str() == outputString);
		}
	}
}
