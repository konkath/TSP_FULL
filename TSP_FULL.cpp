// TSP_FULL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"
#include "Algorithms\Random.h"

#include <memory>
#include <iostream>

int main()
{
	std::shared_ptr<Map<int>> intMap = std::make_shared<Map<int>>(Symetric, 10);
	std::shared_ptr<Map<double>> doubleMap = std::make_shared<Map<double>>(Asymetric, 10);
	
	std::unique_ptr<Algorithm<int>> intAlgorithm = std::make_unique<Random<int>>(intMap);
	std::unique_ptr<Algorithm<double>> doubleAlgorithm = std::make_unique<Random <double>>(doubleMap);

	for (auto i = 0; i < 10; ++i)
	{
		auto intSolution = intAlgorithm->getSolution();
		std::cout << (*intSolution);

		auto doubleSolution = doubleAlgorithm->getSolution();
		std::cout << (*doubleSolution);
	}

	std::cout << std::endl << std::endl;
	auto bestIntSolution = intAlgorithm->getBestSolution();
	std::cout << (*bestIntSolution);

	auto bestDoubleSolution = doubleAlgorithm->getBestSolution();
	std::cout << (*bestDoubleSolution);

	getchar();
    return 0;
}
