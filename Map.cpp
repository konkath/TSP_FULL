#include "stdafx.h"
#include "Map.h"
#include "rapidXml\rapidxml.hpp"
#include "rapidXml\rapidxml_utils.hpp"
#include "rapidXml\rapidxml_print.hpp"
#include "Utils\RandomGenerator.h"

#include <fstream>
#include <iostream>
#include <sstream>

template<typename T>
Map<T>::Map() : mapType(None)
{
	
}

template<typename T>
Map<T>::Map(const MapTypes type, const unsigned size)
{
	generateMap(type, size);
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
std::string Map<T>::getScientificString(const double number)
{
	std::stringstream convert; 
	convert.precision(this->precision);
	convert << std::scientific << number;
	return convert.str();
}

template<typename T>
std::string Map<T>::generateDescription()
{
	std::string dupaName = typeid(T).name();
	return "Map type " + to_string(mapType) + " with costs of type " + dupaName;
}

template<typename T>
void Map<T>::generateMap(const MapTypes mapType, const unsigned size)
{
	this->mapType = mapType;
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
				= static_cast<T>(std::stod(leaf->first_attribute()->value()));
		}
	}

	doc.clear();
	mapType = TSP_LIB;
	return true;
}

template<typename T>
void Map<T>::saveXml()
{
	rapidxml::xml_document<> doc;
	auto declaration = doc.allocate_node(rapidxml::node_declaration);
	declaration->append_attribute(doc.allocate_attribute("version", "1.0"));
	declaration->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
	declaration->append_attribute(doc.allocate_attribute("standalone", "no"));
	doc.append_node(declaration);
	
	auto tsp = doc.allocate_node(rapidxml::node_element, "travellingSalesmanProblemInstance");
	auto fileName = "TSP_" + std::to_string(map.size());
	tsp->append_node(doc.allocate_node(rapidxml::node_element, 
		"name", fileName.c_str()));
	tsp->append_node(doc.allocate_node(rapidxml::node_element, 
		"source", "https://github.com/konkath/TSP_FULL"));
	tsp->append_node(doc.allocate_node(rapidxml::node_element, 
		"description", doc.allocate_string(generateDescription().c_str())));
	tsp->append_node(doc.allocate_node(rapidxml::node_element, 
		"doublePrecision", doc.allocate_string(std::to_string(precision).c_str())));
	tsp->append_node(doc.allocate_node(rapidxml::node_element, 
		"ignoredDigits", doc.allocate_string(std::to_string(ignoredDigits).c_str())));

	auto graph = doc.allocate_node(rapidxml::node_element, "graph");
	for (auto& row : map)
	{
		auto vertex = doc.allocate_node(rapidxml::node_element, "vertex");
		auto counter = 0;
		for (auto& column : row)
		{
			auto edge = doc.allocate_node(rapidxml::node_element, 
				"edge", doc.allocate_string(std::to_string(counter).c_str()));
			edge->append_attribute(doc.allocate_attribute(
				"cost", doc.allocate_string(getScientificString(column).c_str())));
			vertex->append_node(edge);
			counter++;
		}
		graph->append_node(vertex);
	}

	tsp->append_node(graph);
	doc.append_node(tsp);

	std::ofstream file;
	file.open(fileName + ".xml", std::fstream::in | std::fstream::trunc);
	file << doc;

	file.close();
	doc.clear();
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
template std::string Map<int>::getScientificString(const double number);
template std::string Map<int>::generateDescription(void);
template void Map<int>::generateMap(const MapTypes mapType, const unsigned size);
template bool Map<int>::loadXml(const std::string fileName);
template void Map<int>::saveXml();
template std::ostream& operator<<(std::ostream& os, const Map<int>& map);
template std::vector<int>& Map<int>::operator[](const int index);

template class Map<double>;
template void Map<double>::generateSymetricMap(void);
template void Map<double>::generateAsymetricMap(void);
template std::string Map<double>::getScientificString(const double number);
template std::string Map<double>::generateDescription(void);
template void Map<double>::generateMap(const MapTypes mapType, const unsigned size);
template bool Map<double>::loadXml(const std::string fileName);
template void Map<double>::saveXml();
template std::ostream& operator<<(std::ostream& os, const Map<double>& map);
template std::vector<double>& Map<double>::operator[](const int index);
