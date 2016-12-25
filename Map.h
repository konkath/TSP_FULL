#pragma once

#include "rapidXml\rapidxml.hpp"
#include "rapidXml\rapidxml_utils.hpp"

#include <iostream>  
#include <vector>

template<class T>
class Map
{
private:
	std::vector<std::vector<T>> map;
public:
	Map<T>(unsigned size);
	
	bool loadXml(const std::string fileName);

	template<typename T> friend std::ostream& operator<<(std::ostream& os, const Map<T>& map);
	std::vector<T>& operator[](const int index);
};

template class Map<int>;
template bool Map<int>::loadXml(const std::string fileName);
template std::ostream& operator<<(std::ostream& os, const Map<int>& map);
template std::vector<int>& Map<int>::operator[](const int index);

template class Map<double>;
template bool Map<double>::loadXml(const std::string fileName);
template std::ostream& operator<<(std::ostream& os, const Map<double>& map);
template std::vector<double>& Map<double>::operator[](const int index);
