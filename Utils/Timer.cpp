#include "stdafx.h"
#include "Timer.h"

#include <Windows.h>


Timer::Timer() : time(0)
{
	startTimer();
}

void Timer::startTimer() {
	startTime = static_cast<double>(timeGetTime());
}

void Timer::endTimer() {
	time = static_cast<double>(timeGetTime()) - startTime;
}

double Timer::getTime()
{
	return time;
}
