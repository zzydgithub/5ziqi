#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <iomanip>



using namespace std;

void GameStart(string Start);

// ±÷”¿‡
class chessClock {

	public:
		void run();
		chessClock();
		chessClock( int SetTime);
		~chessClock();
	private:
		int set_second;
		void clockShow(time_t StartTime);
		void clockTick();

};