// TSP_FULL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"

#include <memory>
#include <iostream>

int main()
{
	std::unique_ptr<Map<int>> intMap = std::make_unique<Map<int>>(Symetric, 10);
	std::unique_ptr<Map<double>> doubleMap = std::make_unique<Map<double>>(Asymetric, 10);

	std::cout << (*intMap) << std::endl << (*doubleMap) << std::endl;
	
	(*intMap)[2][0] = 5;
	std::cout << (*intMap)[2][0] << std::endl;

	(*doubleMap)[5][0] = 5.25;
	std::cout << (*doubleMap)[5][0] << std::endl << std::endl;
	
	/* */

	intMap = std::make_unique<Map<int>>();
	doubleMap = std::make_unique<Map<double>>();

	intMap->loadXml("burma14.xml");
	std::cout << (*intMap) << std::endl;

	doubleMap->loadXml("burma14.xml");
	std::cout << (*doubleMap) << std::endl;

	intMap->generateMap(Asymetric, 10);
	std::cout << (*intMap) << std::endl;

	intMap->generateMap(Symetric, 10);
	std::cout << (*intMap) << std::endl;
	
	doubleMap->generateMap(Asymetric, 10);
	std::cout << (*doubleMap) << std::endl;

	doubleMap->generateMap(Symetric, 10);
	std::cout << (*doubleMap) << std::endl;

	getchar();
    return 0;
}
