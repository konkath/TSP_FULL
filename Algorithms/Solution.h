#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Solution
{
public:
	Solution(const std::vector<unsigned> path, const T cost, const double time);

	T getCost();

	template<typename T> friend std::ostream& operator<<(std::ostream& os, const Solution<T>& solution);

private:
	const std::vector<unsigned> path;
	const T cost;
	const double time;
};
