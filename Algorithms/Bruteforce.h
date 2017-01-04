#pragma once

#include "Algorithm.h"

template<typename T>
class Bruteforce : public Algorithm<T>
{
public:
	Bruteforce(const std::shared_ptr<Map<T>> map, unsigned nofThreads);

protected:
	std::vector<unsigned> generateSolution() override;

private:
	std::vector<unsigned> evaluatePermutations(unsigned firstPerm, unsigned lastPerm);
	std::vector<unsigned> nthPermutation(unsigned index);
	unsigned factorial(unsigned perm);

	unsigned nofThreads;
};
