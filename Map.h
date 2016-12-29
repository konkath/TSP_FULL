#pragma once

#include "rapidXml\rapidxml.hpp"
#include "rapidXml\rapidxml_utils.hpp"

#include <iostream>  
#include <vector>

enum MapTypes
{
	None = 0,
	TSP_LIB,
	Symetric,
	Asymetric
};

template<typename T>
class Map
{
public:
	Map<T>();
	Map<T>(const MapTypes type, const unsigned size);
	
	void generateMap(const MapTypes mapType, const unsigned size);
	bool loadXml(const std::string fileName);
	void saveXml();

	template<typename T> friend std::ostream& operator<<(std::ostream& os, const Map<T>& map);
	std::vector<T>& operator[](const int index);

private:
	void generateSymetricMap();
	void generateAsymetricMap();

	std::vector<std::vector<T>> map;
	MapTypes mapType;
};
