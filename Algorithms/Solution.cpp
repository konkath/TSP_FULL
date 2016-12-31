#include "stdafx.h"

#include "Solution.h"

template<typename T>
Solution<T>::Solution(std::vector<unsigned> path, T cost) : path(path), cost(cost)
{
	
}

template<typename T>
T Solution<T>::getCost()
{
	return cost;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, const Solution<T>& solution)
{
	os << "Path: ";
	for (auto& it = solution.path.begin(); it != solution.path.end() - 1; ++it)
	{
		os << *it << " -> ";
	}
	os << *(solution.path.end() - 1) << std::endl;
	os << "Cost: " << solution.cost << std::endl;

	return os;
}

template class Solution<int>;
template int Solution<int>::getCost();
template std::ostream& operator<<(std::ostream& os, const Solution<int>& solution);

template class Solution<double>;
template double Solution<double>::getCost();
template std::ostream& operator<<(std::ostream& os, const Solution<double>& solution);
