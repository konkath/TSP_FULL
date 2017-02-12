#pragma once

#include "Algorithm.h"

template<typename T>
class Greedy : public Algorithm<T>
{
public:
	Greedy(const std::shared_ptr<Map<T>> map);

protected:
	std::vector<unsigned> generateSolution() override;

};
#pragma once
