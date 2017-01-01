// TSP_FULL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"
#include "Algorithms\Random.h"
#include "Algorithms\Bruteforce.h"

#include <memory>
#include <iostream>

int main()
{
	std::shared_ptr<Map<int>> intMap = std::make_shared<Map<int>>(Symetric, 10);
	std::shared_ptr<Map<double>> doubleMap = std::make_shared<Map<double>>(Asymetric, 10);
	
	std::unique_ptr<Algorithm<int>> intRandomAlgorithm = std::make_unique<Random<int>>(intMap);
	std::unique_ptr<Algorithm<double>> doubleRandomAlgorithm = std::make_unique<Random <double>>(doubleMap);

	for (auto i = 0; i < 100; ++i)
	{
		intRandomAlgorithm->getSolution();
		doubleRandomAlgorithm->getSolution();
	}

	std::cout << (*intRandomAlgorithm->getBestSolution()) << std::endl;
	std::cout << (*doubleRandomAlgorithm->getBestSolution()) << std::endl;

	/* */

	std::unique_ptr<Algorithm<int>> intBruteforceAlgorithm = std::make_unique<Bruteforce<int>>(intMap);
	std::unique_ptr<Algorithm<double>> doubleBruteforceAlgorithm = std::make_unique<Bruteforce <double>>(doubleMap);

	std::cout << (*intBruteforceAlgorithm->getSolution()) << std::endl;
	std::cout << (*doubleBruteforceAlgorithm->getSolution()) << std::endl;

	getchar();
    return 0;
}
