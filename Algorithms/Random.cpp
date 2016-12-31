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
void Random<T>::generateSolution()
{
	std::iota(path.begin(), path.end(), 0);
	std::random_shuffle(path.begin(), path.end());
}

template<typename T>
std::unique_ptr<Solution<T>> Random<T>::getSolution()
{
	timer->startTimer();
	generateSolution();
	timer->endTimer();

	Solution<T> solution(path, getPathCost(path), timer->getTime());
	evaluateSolution(solution);
	return std::make_unique<Solution<T>>(solution);
}

template class Random<int>;
template void Random<int>::generateSolution();
template std::unique_ptr<Solution<int>> Random<int>::getSolution();

template class Random<double>;
template void Random<double>::generateSolution();
template std::unique_ptr<Solution<double>> Random<double>::getSolution();
