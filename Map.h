#pragma once

#include "rapidXml\rapidxml.hpp"
#include "rapidXml\rapidxml_utils.hpp"
#include "Enums\MapTypes.h"

#include <iostream>  
#include <vector>

template<typename T>
class Map
{
public:
	Map<T>();
	Map<T>(const MapTypes type, const unsigned size);
	
	void generateMap(const MapTypes mapType, const unsigned size);
	bool loadXml(const std::string fileName);
	void saveXml();

	unsigned getMapSize();
	template<typename T> friend std::ostream& operator<<(std::ostream& os, const Map<T>& map);
	std::vector<T>& operator[](const int index);

private:
	void generateSymetricMap();
	void generateAsymetricMap();

	std::string getScientificString(const double number);
	std::string generateDescription();

	std::vector<std::vector<T>> map;
	MapTypes mapType;

	const unsigned precision = 15;
	const unsigned ignoredDigits = 0;
};
