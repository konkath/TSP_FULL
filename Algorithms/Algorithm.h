#pragma once

#include "../Map.h"

#include <memory>

template <typename T>
class Algorithm
{
public:
	virtual std::vector<unsigned> getSolution() = 0;

	T getSolutionCost(const std::vector<unsigned>& solution);

protected:
	Algorithm(const std::shared_ptr<Map<T>> map);

	void evaluateSolution(const std::vector<unsigned> solution);

	const std::shared_ptr<Map<T>> map;

private:
	std::vector<unsigned> bestSolution;
	T bestCost;
};
