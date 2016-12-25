#include "stdafx.h"
#include "RandomGenerator.h"

template<typename T>
random_device RandomGenerator<T>::rd;
template<typename T>
mt19937 RandomGenerator<T>::generate(RandomGenerator<T>::rd());

template<typename T>
RandomGenerator<T> & RandomGenerator<T>::getGenerator()
{
	static RandomGenerator<T> instance;
	return instance;
}

template<typename T>
T RandomGenerator<T>::getRandom(T begin, T end)
{
	return T();
}

template<>
int RandomGenerator<int>::getRandom(int begin, int end)
{
	uniform_int_distribution<> rInt(begin, end);
	return rInt(generate);
}

template<>
double RandomGenerator<double>::getRandom(double begin, double end)
{
	uniform_real_distribution<> rDouble(begin, end);
	return rDouble(generate);
}

template class RandomGenerator<int>;
template RandomGenerator<int>& RandomGenerator<int>::getGenerator();
template int RandomGenerator<int>::getRandom(int begin, int end);

template class RandomGenerator<double>;
template RandomGenerator<double>& RandomGenerator<double>::getGenerator();
template double RandomGenerator<double>::getRandom(double begin, double end);
