/*

*/

#include "ʱ��.h";

//��ʼʱ��
void GameStart(string Start) {

	while (1) {
		if (Start == "1")
		{
			cout << "��Ϸ��ʼ��" << endl;
			break;
		}
		else
		{
			
			cout << "��1����ʼ��Ϸ" << endl;	//Ϊʲô������ܶ���� ������ĳ�string
		
			cin >> Start;
		}
	}
}

chessClock ::chessClock(int SetSecond) {

	//��ʼ��ʱ��ʱ�������
	set_second = SetSecond;
	//�߱��ʱ
	//clockTick();
}

chessClock::chessClock() {

	//Ĭ��ʱ��ʱ����5s
	set_second = 10;
	//�߱��ʱ
	//clockTick();
}

//��ʱ��
void chessClock::clockTick() {

	cout << "��ʼ��ʱ��" << endl;

	int t = set_second;//���õ�ÿһ��ʹ�õ�ʱ��

	time_t StartTime;//��ʼʱ��

	time(&StartTime);//��ֵ��ʼʱ��

	//cout << "��ʼʱ�䣺"<<StartTime<< endl;

	//��ʾ����ʱ
	clockShow(StartTime);

	 
	//��ʱ������ʱ�䳬ʱ
	cout << "ʱ�䳬ʱ!" << endl;

}

void chessClock::run() {

	clockTick();
}

chessClock::~chessClock() {

}

void chessClock::clockShow(time_t StartTime) {

	//��ǰʱ��
	time_t CurTime;
	
	do {
	time(&CurTime);
	cout << setw(2) << setfill('0') <<set_second - (CurTime - StartTime)<<"\r";
	Sleep(1000);
	} while ((CurTime - StartTime) < set_second);

}