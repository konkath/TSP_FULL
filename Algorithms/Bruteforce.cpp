#include "stdafx.h"
#include "Bruteforce.h"

#include <algorithm>
#include <numeric>
#include <future>

template<typename T>
Bruteforce<T>::Bruteforce(const std::shared_ptr<Map<T>> map, unsigned nofThreads) :
	Algorithm(map), nofThreads(nofThreads)
{

}

template<typename T>
std::vector<unsigned> Bruteforce<T>::generateSolution()
{
	std::vector<std::future<std::vector<unsigned>>> threads(nofThreads - 1);

	auto maxPerm = factorial(map->getMapSize());
	auto currentPerm = 0;
	auto permSize = maxPerm / nofThreads;

	for (auto& t : threads)
	{
		t = std::async(&Bruteforce<T>::evaluatePermutations, this, currentPerm, permSize);
		currentPerm += permSize;
	}

	auto bestPath = evaluatePermutations(currentPerm, permSize);
	auto bestPathCost = getPathCost(bestPath);

	for (auto& t : threads)
	{
		auto path = t.get();
		auto cost = getPathCost(path);

		if (cost < bestPathCost)
		{
			bestPathCost = cost;
			bestPath = path;
		}
	}

	return bestPath;
}

template<typename T>
std::vector<unsigned> Bruteforce<T>::evaluatePermutations(unsigned firstPerm, unsigned lastPerm)
{
	auto path = nthPermutation(firstPerm);
	auto bestPath = path;
	auto bestPathCost = getPathCost(path);

	for (auto counter = 1u; counter < lastPerm; ++counter)
	{
		std::next_permutation(path.begin(), path.end());

		auto cost = getPathCost(path);
		if (cost < bestPathCost)
		{
			bestPath = path;
			bestPathCost = cost;
		}
	}
	return bestPath;
}

template<typename T>
std::vector<unsigned> Bruteforce<T>::nthPermutation(unsigned index)
{
	std::vector<unsigned> path;
	std::vector<unsigned> availablePerms(map->getMapSize());
	std::iota(availablePerms.begin(), availablePerms.end(), 0);
	
	while (availablePerms.size() > 0)
	{
		auto permSize = factorial(availablePerms.size() - 1);
		auto counter = index / permSize;

		path.push_back(availablePerms[counter]);
		availablePerms.erase(availablePerms.begin() + counter);
		index %= permSize;
	}

	return path;
}

template<typename T>
unsigned Bruteforce<T>::factorial(unsigned perm)
{
	return (perm < 2) ? 1 : factorial(perm - 1) * perm;
}

template class Bruteforce<int>;
template std::vector<unsigned> Bruteforce<int>::generateSolution();
template std::vector<unsigned> Bruteforce<int>::evaluatePermutations(unsigned firstPerm, unsigned lastPerm);
template std::vector<unsigned> Bruteforce<int>::nthPermutation(unsigned index);
unsigned Bruteforce<int>::factorial(unsigned perm);

template class Bruteforce<double>;
template std::vector<unsigned> Bruteforce<double>::generateSolution();
template std::vector<unsigned> Bruteforce<double>::evaluatePermutations(unsigned firstPerm, unsigned lastPerm);
template std::vector<unsigned> Bruteforce<double>::nthPermutation(unsigned index);
template unsigned Bruteforce<double>::factorial(unsigned perm);
