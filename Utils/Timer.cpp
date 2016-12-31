#include "stdafx.h"
#include "Timer.h"

#include <Windows.h>


Timer::Timer() : time(0)
{
	checkFrequency();
	startTimer();
}

void Timer::startTimer() {
	LARGE_INTEGER start;
	QueryPerformanceCounter(&start);
	startTick = static_cast<double>(start.QuadPart);
}

void Timer::endTimer() {
	LARGE_INTEGER stop;
	QueryPerformanceCounter(&stop);

	// result in ms
	time = (static_cast<double>(stop.QuadPart) - startTick) / frequency * 1000;
}

double Timer::getTime()
{
	return time;
}

void Timer::checkFrequency() {
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	frequency = static_cast<double>(freq.QuadPart);
}