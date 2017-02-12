#include "stdafx.h"
#include "Greedy.h"

#include "../Utils/RandomGenerator.h"

template<typename T>
Greedy<T>::Greedy(const std::shared_ptr<Map<T>> map)
	: Algorithm(map)
{

}

template<typename T>
std::vector<unsigned> Greedy<T>::generateSolution()
{
	const auto mapSize = map->getMapSize();
	const auto startingCity = RandomGenerator<int>::getGenerator().getRandom(0, mapSize - 1);
	vector<bool> visitedCities(mapSize, false);
	visitedCities[startingCity] = true;
	vector<unsigned> path(1, startingCity);

	for (auto i = 0u; i < mapSize - 1; ++i)
	{
		std::pair<T, int> closestNeighbour(INT_MAX, 0);

		for (auto j = 0u; j < mapSize; ++j)
		{
			if (i != j && !visitedCities[j] && closestNeighbour.first > (*map)[i][j])
			{
				closestNeighbour = std::make_pair((*map)[i][j], j);
			}
		}

		visitedCities[closestNeighbour.second] = true;
		path.push_back(closestNeighbour.second);
	}

	return path;
}

template class Greedy<int>;
template std::vector<unsigned> Greedy<int>::generateSolution();

template class Greedy<double>;
template std::vector<unsigned> Greedy<double>::generateSolution();
