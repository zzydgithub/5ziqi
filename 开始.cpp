#include "��ʼ.h"
#include "����.h"
#include "����.h"
#include <iostream>
#include <string>

#include "ʱ��.h"
#include<Windows.h>
#include "����.h"
using namespace std;




LetsPlay::LetsPlay()
{
	//��ʼ��Ϸ
	StartGame();

}

void LetsPlay::StartGame()
{
	system("mode con cols=55 lines=35");
	system("color 60");
	cout << "��ӭʹ��������" << endl;

	//��ʼ������ʾ����
	chessBoard board;
	board.showBoard();

	cout << "��1����ʼ" << endl;

	string Start;
	cin >> Start;
	GameStart(Start);

	//��ʱ
	chessClock Clock;
	//Clock.run();


	//����
	chessRules rules;

	//����
	playChess play(board);

	//Sleep(5000);
	system("pause");
}
