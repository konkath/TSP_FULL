#pragma once

#include "../Map.h"
#include "Solution.h"

#include <memory>

template <typename T>
class Algorithm
{
public:
	virtual std::unique_ptr<Solution<T>> getSolution() = 0;
	std::unique_ptr<Solution<T>> getBestSolution();

protected:
	Algorithm(const std::shared_ptr<Map<T>> map);

	T getPathCost(const std::vector<unsigned>& path);
	void evaluateSolution(Solution<T>& solution);

	const std::shared_ptr<Map<T>> map;

private:
	std::unique_ptr<Solution<T>> bestSolution;

};
