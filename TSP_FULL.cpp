// TSP_FULL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"
#include "Algorithms\Random.h"
#include "Algorithms\Bruteforce.h"
#include "Algorithms\Greedy.h"

#include <memory>
#include <iostream>

int main()
{
	unsigned mapSizes[] = { 100, 500, 1000, 3000, 5000, 10000 };
	for (const auto& size : mapSizes)
	{
		std::shared_ptr<Map<int>> intMap = std::make_shared<Map<int>>(Symetric, size);
		std::shared_ptr<Map<double>> doubleMap = std::make_shared<Map<double>>(Asymetric, size);

		std::unique_ptr<Algorithm<int>> intGreedyAlgorithm = std::make_unique<Greedy<int>>(intMap);
		std::unique_ptr<Algorithm<double>> doubleGreedyAlgorithm = std::make_unique<Greedy <double>>(doubleMap);

		const int testNumber = 1000;
		for (auto i = 0; i < testNumber; ++i)
		{
			intGreedyAlgorithm->getSolution();
			doubleGreedyAlgorithm->getSolution();
		}

		std::cout << (*intGreedyAlgorithm->getBestSolution()) << std::endl;
		std::cout << (*doubleGreedyAlgorithm->getBestSolution()) << std::endl;
	}

	/*
	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Greedy done!" << std::endl;
	getchar();

	std::shared_ptr<Map<int>> intMap = std::make_shared<Map<int>>(Symetric, 10);
	std::shared_ptr<Map<double>> doubleMap = std::make_shared<Map<double>>(Asymetric, 10);
	
	std::unique_ptr<Algorithm<int>> intRandomAlgorithm = std::make_unique<Random<int>>(intMap);
	std::unique_ptr<Algorithm<double>> doubleRandomAlgorithm = std::make_unique<Random <double>>(doubleMap);
	
	const int testNumber = 1000;
	for (auto i = 0; i < testNumber; ++i)
	{
		intRandomAlgorithm->getSolution();
		doubleRandomAlgorithm->getSolution();
	}

	std::cout << (*intRandomAlgorithm->getBestSolution()) << std::endl;
	std::cout << (*doubleRandomAlgorithm->getBestSolution()) << std::endl;

	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Random done!" << std::endl;
	getchar();

	for (auto i = 1; i < 5; ++i)
	{
		std::unique_ptr<Algorithm<int>> intBruteforceAlgorithm = 
			std::make_unique<Bruteforce<int>>(intMap, i);
		std::unique_ptr<Algorithm<double>> doubleBruteforceAlgorithm = 
			std::make_unique<Bruteforce <double>>(doubleMap, i);
	
		double intTime = 0, doubleTime = 0;
		for (auto j = 0; j < testNumber; ++j)
		{
			intTime += (*intBruteforceAlgorithm->getSolution()).getTime();
			doubleTime += (*doubleBruteforceAlgorithm->getSolution()).getTime();
		}
		std::cout << "int time for " << i << " threads " << intTime / testNumber << std::endl;
		std::cout << "double time for " << i << " threads " << doubleTime / testNumber << std::endl;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Bruteforce done!" << std::endl;
	getchar();
	*/
    return 0;
}
