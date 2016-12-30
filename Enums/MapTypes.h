#pragma once

#include <string>

enum MapTypes
{
	None = 0,
	TSP_LIB,
	Symetric,
	Asymetric
};

std::string to_string(const MapTypes mapType);
