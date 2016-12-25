#include "stdafx.h"
#include "Map.h"
#include "rapidXml\rapidxml.hpp"
#include "rapidXml\rapidxml_utils.hpp"
#include "Utils\RandomGenerator.h"

template<typename T>
Map<T>::Map(unsigned size)
{
	map = std::vector<std::vector<T>>(size, std::vector<T>(size, 10));
}

template<typename T>
void Map<T>::generateSymetricMap()
{
	for (auto i = 0u; i < map.size(); ++i)
	{
		for (auto j = 0u; j < map[i].size(); ++j)
		{
			i >= j ? map[i][j] = map[j][i] : map[i][j] 
				= RandomGenerator<T>::getGenerator().getRandom(0, 1000);
		}
	}
}

template<typename T>
void Map<T>::generateAsymetricMap()
{
	auto i = 0;
	for (auto &row = map.begin(); row != map.end(); ++row, ++i)
	{
		auto j = 0;
		for (auto &column = (*row).begin(); column != (*row).end(); ++column, ++j)
		{
			if (i != j)
			{
				(*column) = RandomGenerator<T>::getGenerator().getRandom(0, 1000);
			}
		}
	}
}

template<typename T>
void Map<T>::generateMap(const MapTypes mapType, const unsigned size)
{
	map = std::vector<std::vector<T>>(size, std::vector<T>(size, -1));

	switch (mapType)
	{
	case Symetric:
		generateSymetricMap();
		break;
	case Asymetric:
		generateAsymetricMap();
		break;
	}
}

template<typename T>
bool Map<T>::loadXml(const std::string fileName)
{
	rapidxml::file<> xmlFile(fileName.c_str());
	rapidxml::xml_document<> doc;

	try 
	{
		doc.parse<0>(xmlFile.data());
	}
	catch (rapidxml::parse_error p)
	{
		return false;
	}

	if (map.size() > 0) 
	{
		map.erase(map.begin(), map.end());
	}

	auto root = doc.first_node()->last_node();
	auto length = std::stoi(root->first_node()->last_node()->value()) + 1;
	for (auto node = root->first_node(); node; node = node->next_sibling())
	{
		map.push_back(std::vector<T>(length, -1));
		for (auto leaf = node->first_node(); leaf; leaf = leaf->next_sibling())
		{
			map[map.size() - 1][std::stoi(leaf->value())] 
				= (T)std::stod(leaf->first_attribute()->value());
		}
	}

	doc.clear();
	return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Map<T>& map)
{
	for (const auto &v1 : map.map)
	{
		for (const auto &v2 : v1)
		{
			os << v2 << " ";
		}
		os << std::endl;
	}

	return os;
}

template<typename T>
std::vector<T>& Map<T>::operator[](const int index)
{
	return map[index];
}

template class Map<int>;
template void Map<int>::generateSymetricMap(void);
template void Map<int>::generateAsymetricMap(void);
template void Map<int>::generateMap(const MapTypes mapType, const unsigned size);
template bool Map<int>::loadXml(const std::string fileName);
template std::ostream& operator<<(std::ostream& os, const Map<int>& map);
template std::vector<int>& Map<int>::operator[](const int index);

template class Map<double>;
template void Map<double>::generateSymetricMap(void);
template void Map<double>::generateAsymetricMap(void);
template void Map<double>::generateMap(const MapTypes mapType, const unsigned size);
template bool Map<double>::loadXml(const std::string fileName);
template std::ostream& operator<<(std::ostream& os, const Map<double>& map);
template std::vector<double>& Map<double>::operator[](const int index);
