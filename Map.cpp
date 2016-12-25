#include "stdafx.h"
#include "Map.h"

template<class T>
Map<T>::Map(unsigned size)
{
	map = std::vector<std::vector<T>>(size, std::vector<T>(size, 10));
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
