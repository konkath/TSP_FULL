#pragma once

#include "Algorithm.h"

template<typename T>
class Bruteforce : public Algorithm<T>
{
public:
	Bruteforce(const std::shared_ptr<Map<T>> map);

	std::unique_ptr<Solution<T>> getSolution();

private:
	void generateSolution();

	std::vector<unsigned> bestPath;
	T bestPathCost;
};
