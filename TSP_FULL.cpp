// TSP_FULL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"

#include <memory>
#include <iostream>

int main()
{
	std::unique_ptr<Map<int>> intMap = std::make_unique<Map<int>>(10);
	std::unique_ptr<Map<double>> doubleMap = std::make_unique<Map<double>>(10);

	std::cout << (*intMap) << std::endl << (*doubleMap) << std::endl;
	
	(*intMap)[2][0] = 5;
	std::cout << (*intMap)[2][0] << std::endl;

	(*doubleMap)[5][0] = 5;
	std::cout << (*doubleMap)[5][0] << std::endl;

	getchar();
    return 0;
}
