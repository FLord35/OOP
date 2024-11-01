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

	const std::string UNKNOWN_BODY_TYPE_EXCEPTION_MESSAGE = "exception: unknown body type: ";

	const std::string RADIUS_OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: radius is out of range";

	const std::string WIDTH_OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: width is out of range";
	const std::string HEIGHT_OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: height is out of range";
	const std::string DEPTH_OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: depth is out of range";

	const std::string BASE_RADIUS_OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: base radius is out of range";

	const std::string DENSITY_OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: density is out of range";
	const std::string VOLUME_OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: volume is out of range";
	const std::string MASS_OUT_OF_RANGE_EXCEPTION_MESSAGE = "exception: mass is out of range";
}
