#include "stdafx.h"
#include "Random.h"

#include <numeric>
#include <algorithm>

template<typename T>
Random<T>::Random(const std::shared_ptr<Map<T>> map) : Algorithm(map)
{
	solution = std::vector<unsigned>(map->getMapSize());
}

template<typename T>
void Random<T>::generateSolution()
{
	std::iota(solution.begin(), solution.end(), 0);
	std::random_shuffle(solution.begin(), solution.end());
}

template<typename T>
std::vector<unsigned> Random<T>::getSolution()
{
	generateSolution();
	evaluateSolution(solution);
	return solution;
}

template class Random<int>;
template void Random<int>::generateSolution();
template std::vector<unsigned> Random<int>::getSolution();

template class Random<double>;
template void Random<double>::generateSolution();
template std::vector<unsigned> Random<double>::getSolution();
