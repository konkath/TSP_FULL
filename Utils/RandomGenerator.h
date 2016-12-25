#pragma once

#include <random>
using namespace std;

template<typename T>
class RandomGenerator {
public:
	RandomGenerator(RandomGenerator const&) = delete;
	void operator=(RandomGenerator const&) = delete;

	static RandomGenerator& getGenerator();
	T getRandom(T begin, T end);
private:
	RandomGenerator() {}

	static random_device rd;
	static mt19937 generate;
};
