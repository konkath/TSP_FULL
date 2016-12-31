#include "stdafx.h"
#include "Algorithm.h"


template<typename T>
Algorithm<T>::Algorithm(const std::shared_ptr<Map<T>> map) : map(map), bestCost(INT_MAX)
{
	bestSolution = std::vector<unsigned>();
}

template<typename T>
T Algorithm<T>::getSolutionCost(const std::vector<unsigned>& solution)
{
	auto cost = static_cast<T>(0);

	for (auto& it = solution.begin(); it != solution.end() - 1; ++it)
	{
		cost += (*map)[*it][*(it + 1)];
	}
	cost += (*map)[*(solution.end() - 1)][*solution.begin()];

	return cost;
}

template<typename T>
void Algorithm<T>::evaluateSolution(const std::vector<unsigned> solution)
{
	auto solutionCost = getSolutionCost(solution);
	if (solutionCost < bestCost)
	{
		bestCost = solutionCost;
		bestSolution = solution;
	}
}

template class Algorithm<int>;
template int Algorithm<int>::getSolutionCost(const std::vector<unsigned>& solution);
template void Algorithm<int>::evaluateSolution(const std::vector<unsigned> solution);

template class Algorithm<double>;
template double Algorithm<double>::getSolutionCost(const std::vector<unsigned>& solution);
template void Algorithm<double>::evaluateSolution(const std::vector<unsigned> solution);
