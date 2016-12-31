#pragma once

class Timer
{
public:
	Timer();

	void startTimer();
	void endTimer();

	double getTime();
	
private:
	void checkFrequency();

	double frequency;
	double startTick;
	double time;
};