#include "stdafx.h"
#include "MapTypes.h"

std::string to_string(const MapTypes mapType)
{
	switch (mapType)
	{
	case None: return "None";
	case TSP_LIB: return "TSP_LIB";
	case Symetric: return "Symetric";
	case Asymetric: return "Asymetric";
	}
	return "Unknown";
}