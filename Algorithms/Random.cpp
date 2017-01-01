#include "stdafx.h"
#include "Random.h"

#include <numeric>
#include <algorithm>

template<typename T>
Random<T>::Random(const std::shared_ptr<Map<T>> map) : Algorithm(map)
{
	path = std::vector<unsigned>(map->getMapSize());
}

template<typename T>
std::vector<unsigned> Random<T>::generateSolution()
{
	std::iota(path.begin(), path.end(), 0);
	std::random_shuffle(path.begin(), path.end());
	return path;
}

template class Random<int>;
template std::vector<unsigned> Random<int>::generateSolution();

template class Random<double>;
template std::vector<unsigned> Random<double>::generateSolution();
