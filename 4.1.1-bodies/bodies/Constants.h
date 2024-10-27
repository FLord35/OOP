#pragma once
namespace bd
{
	const double g = 9.81;
	const double waterDensity = 1000.0;

	//enum BodyType
	//{
	//	SPHERE,
	//	PARALLELEPIPED,
	//	CONE,
	//	CYLINDER
	//};

	const std::string INPUT_CONE_NAME = "CONE";
	const std::string INPUT_CYLINDER_NAME = "CYLINDER";
	const std::string INPUT_PARALLELEPIPED_NAME = "PARALLELEPIPED";
	const std::string INPUT_SPHERE_NAME = "SPHERE";

	const std::string OUTPUT_CONE_NAME = "CONE: ";
	const std::string OUTPUT_CYLINDER_NAME = "CYLINDER: ";
	const std::string OUTPUT_PARALLELEPIPED_NAME = "PARALLELEPIPED: ";
	const std::string OUTPUT_SPHERE_NAME = "SPHERE: ";

	const std::string INPUT_EXIT_COMMAND = "EXIT";

	const std::string ERROR_UNKNOWN_BODY_TYPE = "Unknown body type: ";
}
