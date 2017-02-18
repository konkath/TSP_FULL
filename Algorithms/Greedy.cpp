#include "stdafx.h"
#include "Greedy.h"

#include "../Utils/RandomGenerator.h"

#include <numeric>
#include <algorithm>

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
	vector<unsigned> path(1, startingCity);

	std::vector<unsigned> availableCities = std::vector<unsigned>(mapSize);
	std::iota(availableCities.begin(), availableCities.end(), 0);
	availableCities.erase(availableCities.begin() + startingCity);

	for (auto i = 0u; i < mapSize - 1; ++i)
	{
		std::pair<T, int> closestNeighbour(INT_MAX, 0);

		for (auto j = 0u; j < availableCities.size(); ++j)
		{
			const auto destination = availableCities[j];
			if (closestNeighbour.first > (*map)[i][destination] && i != destination)
			{
				closestNeighbour = std::make_pair((*map)[i][destination], j);
			}
		}

		availableCities.erase(availableCities.begin() + closestNeighbour.second);
		path.push_back(closestNeighbour.second);
	}

	return path;
}

template class Greedy<int>;
template std::vector<unsigned> Greedy<int>::generateSolution();

template class Greedy<double>;
template std::vector<unsigned> Greedy<double>::generateSolution();
