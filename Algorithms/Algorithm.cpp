#include "stdafx.h"
#include "Algorithm.h"


template<typename T>
Algorithm<T>::Algorithm(const std::shared_ptr<Map<T>> map) 
	: map(map), bestSolution(nullptr), timer(std::make_unique<Timer>())
{

}

template<typename T>
std::unique_ptr<Solution<T>> Algorithm<T>::getSolution()
{
	timer->startTimer();
	auto path = generateSolution();
	timer->endTimer();

	Solution<T> solution(path, getPathCost(path), timer->getTime());
	evaluateSolution(solution);
	return std::make_unique<Solution<T>>(solution);
}

template<typename T>
std::unique_ptr<Solution<T>> Algorithm<T>::getBestSolution()
{
	return std::make_unique<Solution<T>>(*bestSolution);
}

template<typename T>
T Algorithm<T>::getPathCost(const std::vector<unsigned>& path)
{
	auto cost = static_cast<T>(0);

	auto endItr = path.end() - 1;
	for (auto& it = path.begin(); it != endItr;)
	{
		cost += (*map)[*(++it)][*it]; // Optimalization hack equal with (*map)[*it][*(it++)] but much faster
	}
	cost += (*map)[*endItr][*path.begin()];
	return cost;
}

template<typename T>
void Algorithm<T>::evaluateSolution(Solution<T>& solution)
{
	if (!bestSolution || solution.getCost() < bestSolution->getCost())
	{
		bestSolution = std::make_unique<Solution<T>>(solution);
	}
}

template class Algorithm<int>;
template std::unique_ptr<Solution<int>> Algorithm<int>::getSolution();
template std::unique_ptr<Solution<int>> Algorithm<int>::getBestSolution();
template int Algorithm<int>::getPathCost(const std::vector<unsigned>& solution);
template void Algorithm<int>::evaluateSolution(Solution<int>& solution);

template class Algorithm<double>;
template std::unique_ptr<Solution<double>> Algorithm<double>::getSolution();
template std::unique_ptr<Solution<double>> Algorithm<double>::getBestSolution();
template double Algorithm<double>::getPathCost(const std::vector<unsigned>& solution);
template void Algorithm<double>::evaluateSolution(Solution<double>& solution);
