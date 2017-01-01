#include "stdafx.h"
#include "Bruteforce.h"

#include <algorithm>
#include <numeric>

template<typename T>
Bruteforce<T>::Bruteforce(const std::shared_ptr<Map<T>> map) : Algorithm(map), bestPathCost(INT_MAX)
{

}

template<typename T>
std::unique_ptr<Solution<T>> Bruteforce<T>::getSolution()
{
	timer->startTimer();
	generateSolution();
	timer->endTimer();

	Solution<T> solution(bestPath, bestPathCost, timer->getTime());
	evaluateSolution(solution);
	return std::make_unique<Solution<T>>(solution);
}

template<typename T>
void Bruteforce<T>::generateSolution()
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
}

template class Bruteforce<int>;
template void Bruteforce<int>::generateSolution();
template std::unique_ptr<Solution<int>> Bruteforce<int>::getSolution();

template class Bruteforce<double>;
template void Bruteforce<double>::generateSolution();
template std::unique_ptr<Solution<double>> Bruteforce<double>::getSolution();
