#pragma once

#include "../Map.h"
#include "../Utils/Timer.h"
#include "Solution.h"

#include <memory>

template <typename T>
class Algorithm
{
public:
	std::unique_ptr<Solution<T>> getSolution();
	std::unique_ptr<Solution<T>> getBestSolution();

protected:
	Algorithm(const std::shared_ptr<Map<T>> map);

	virtual std::vector<unsigned> generateSolution() = 0;
	T getPathCost(const std::vector<unsigned>& path);

	const std::shared_ptr<Map<T>> map;
	std::unique_ptr<Timer> timer;

private:
	void evaluateSolution(Solution<T>& solution);

	std::unique_ptr<Solution<T>> bestSolution;
};
