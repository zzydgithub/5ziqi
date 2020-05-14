/*

*/

#include "时钟.h";

//开始时钟
void GameStart(string Start) {

	while (1) {
		if (Start == "1")
		{
			cout << "游戏开始！" << endl;
			break;
		}
		else
		{
			
			cout << "按1键开始游戏" << endl;	//为什么会输出很多个？ 解决：改成string
		
			cin >> Start;
		}
	}
}

chessClock ::chessClock(int SetSecond) {

	//初始化时钟时间的设置
	set_second = SetSecond;
	//走表计时
	//clockTick();
}

chessClock::chessClock() {

	//默认时钟时间是5s
	set_second = 10;
	//走表计时
	//clockTick();
}

//计时器
void chessClock::clockTick() {

	cout << "开始计时！" << endl;

	int t = set_second;//设置的每一次使用的时间

	time_t StartTime;//开始时间

	time(&StartTime);//赋值开始时间

	//cout << "开始时间："<<StartTime<< endl;

	//显示倒计时
	clockShow(StartTime);

	 
	//计时结束，时间超时
	cout << "时间超时!" << endl;

}

void chessClock::run() {

	clockTick();
}

chessClock::~chessClock() {

}

void chessClock::clockShow(time_t StartTime) {

	//当前时间
	time_t CurTime;
	
	do {
	time(&CurTime);
	cout << setw(2) << setfill('0') <<set_second - (CurTime - StartTime)<<"\r";
	Sleep(1000);
	} while ((CurTime - StartTime) < set_second);

}