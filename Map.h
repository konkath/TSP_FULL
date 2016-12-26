#pragma once

#include "rapidXml\rapidxml.hpp"
#include "rapidXml\rapidxml_utils.hpp"

#include <iostream>  
#include <vector>

enum MapTypes
{
	Symetric = 0,
	Asymetric = 1
};

template<typename T>
class Map
{
public:
	Map<T>();
	Map<T>(MapTypes type, const unsigned size);
	
	void generateMap(const MapTypes mapType, const unsigned size);
	bool loadXml(const std::string fileName);

	template<typename T> friend std::ostream& operator<<(std::ostream& os, const Map<T>& map);
	std::vector<T>& operator[](const int index);

private:
	void generateSymetricMap();
	void generateAsymetricMap();

	std::vector<std::vector<T>> map;
};
