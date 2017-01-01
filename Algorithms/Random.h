#pragma once

#include "Algorithm.h"

template <typename T>
class Random : public Algorithm<T>
{
public:
	Random(const std::shared_ptr<Map<T>> map);

private:
	std::vector<unsigned> generateSolution() override;

	std::vector<unsigned> path;
};
