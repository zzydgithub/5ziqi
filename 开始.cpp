#include "开始.h"
#include "棋盘.h"
#include "下棋.h"
#include <iostream>
#include <string>

#include "时钟.h"
#include<Windows.h>
#include "规则.h"
using namespace std;




LetsPlay::LetsPlay()
{
	//开始游戏
	StartGame();

}

void LetsPlay::StartGame()
{
	system("mode con cols=55 lines=35");
	system("color 60");
	cout << "欢迎使用五子棋" << endl;

	//初始化并显示棋盘
	chessBoard board;
	board.showBoard();

	cout << "按1键开始" << endl;

	string Start;
	cin >> Start;
	GameStart(Start);

	//计时
	chessClock Clock;
	//Clock.run();


	//规则
	chessRules rules;

	//下棋
	playChess play(board);

	//Sleep(5000);
	system("pause");
}
