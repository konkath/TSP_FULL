#pragma once

class Timer
{
public:
	Timer();

	void startTimer();
	void endTimer();

	double getTime();
	
private:
	double startTime;
	double time;
};