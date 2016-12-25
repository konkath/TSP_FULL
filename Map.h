#pragma once

#include <iostream>  
#include <vector>

template<class T>
class Map
{
private:
	std::vector<std::vector<T>> map;
public:
	Map<T>(unsigned size);
	
	template<typename T> friend std::ostream& operator<<(std::ostream& os, const Map<T>& map);
	std::vector<T>& operator[](const int index);
};

template class Map<int>;
template std::ostream& operator<<(std::ostream& os, const Map<int>& map);
template std::vector<int>& Map<int>::operator[](const int index);

template class Map<double>;
template std::ostream& operator<<(std::ostream& os, const Map<double>& map);
template std::vector<double>& Map<double>::operator[](const int index);
