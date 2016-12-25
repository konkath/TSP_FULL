#include "stdafx.h"
#include "Map.h"
#include "rapidXml\rapidxml.hpp"
#include "rapidXml\rapidxml_utils.hpp"

template<class T>
Map<T>::Map(unsigned size)
{
	map = std::vector<std::vector<T>>(size, std::vector<T>(size, 10));
}

template<class T>
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

template<class T>
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

template<class T>
std::vector<T>& Map<T>::operator[](const int index)
{
	return map[index];
}
