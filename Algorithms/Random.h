#pragma once

#include "Algorithm.h"

template <typename T>
class Random : public Algorithm<T>
{
public:
	Random(const std::shared_ptr<Map<T>> map);

	std::unique_ptr<Solution<T>> getSolution();
private:
	void generateSolution();

	std::vector<unsigned> path;
};
