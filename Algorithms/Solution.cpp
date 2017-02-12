#include "stdafx.h"

#include "Solution.h"

template<typename T>
Solution<T>::Solution(const std::vector<unsigned> path, const T cost, const double time) 
	: path(path), cost(cost), time(time)
{
	
}

template<typename T>
T Solution<T>::getCost()
{
	return cost;
}

template<typename T>
double Solution<T>::getTime()
{
	return time;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, const Solution<T>& solution)
{
	if (solution.path.size() < 12)
	{
		os << "Path: ";
		for (auto& it = solution.path.begin(); it != solution.path.end() - 1; ++it)
		{
			os << *it << " -> ";
		}
		os << *(solution.path.end() - 1) << std::endl;
	}

	os << "Cost: " << solution.cost << std::endl;
	os << "Time: " << solution.time << std::endl;

	return os;
}

template class Solution<int>;
template int Solution<int>::getCost();
template double Solution<int>::getTime();
template std::ostream& operator<<(std::ostream& os, const Solution<int>& solution);

template class Solution<double>;
template double Solution<double>::getCost();
template double Solution<double>::getTime();
template std::ostream& operator<<(std::ostream& os, const Solution<double>& solution);
