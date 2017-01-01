#include "stdafx.h"
#include "Bruteforce.h"

#include <algorithm>
#include <numeric>

template<typename T>
Bruteforce<T>::Bruteforce(const std::shared_ptr<Map<T>> map) : Algorithm(map), bestPathCost(INT_MAX)
{

}

template<typename T>
std::vector<unsigned> Bruteforce<T>::generateSolution()
{
	std::vector<unsigned> path(map->getMapSize());
	std::iota(path.begin(), path.end(), 0);

	while (std::next_permutation(path.begin(), path.end()))
	{
		auto cost = getPathCost(path);
		if (cost < bestPathCost)
		{
			bestPath = path;
			bestPathCost = cost;
		}
	}

	return bestPath;
}

template class Bruteforce<int>;
template std::vector<unsigned> Bruteforce<int>::generateSolution();

template class Bruteforce<double>;
template std::vector<unsigned> Bruteforce<double>::generateSolution();
