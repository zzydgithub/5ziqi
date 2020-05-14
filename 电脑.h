#pragma once
#include <iostream>
#include <string>
#include "棋盘.h"
using namespace std;
/*
	这里是五子棋的AI，主要思想是先防守再进攻，如果进攻大于防守则进攻，如果防守大于进攻就防守
	两个函数，一个进攻位置，一个返回防守位置，哪个值大就用哪个
	防守：首先看当前所下的位置，先找有没有四个连在一起的，再找三个连一起的，再找2+1,2+2，3+3,4+4
	进攻：找4个，找3个包括优先3+3，找2个优先2+2，找一个。
*/

//下棋位置
struct Position {
			int x;		//x轴
			int y;		//y轴
			double pow;	//权重值
		};

class chessComputer {

	public:
		chessBoard cptBoard;
		//棋盘数组
		int AIBoard[16][16];
		//下棋的位置
		struct Position All_Positions[225];
		//回合数
		int Turns;
		//调用电脑下棋
		Position cptPlay(chessBoard board, int x, int y);
		//是否已经决定下棋位置
		bool decided = false;
		
		chessComputer(chessBoard board);
		chessComputer( );
	private:
		//防守函数
		Position cptDefence(int x,int y);
		//进攻函数
		Position cptAttack( int turns);
		//数棋子个数
		Position countingPawns(int x, int y);
		//给出位置结果
		Position giveMePos(int num, int x, int y);
		
		int powReturn(int cont);
};