#pragma once
#include <iostream>
#include <string>
#include "棋盘.h"
#include "规则.h"
#include "开始.h"
#include "电脑.h"
using namespace std;



class playChess {

	public:
		//黑棋还是白棋走？
		int WhosTurn = 1;
		//构造函数
		playChess(chessBoard board );

		//棋子上棋盘
		void PawnOnBoard(int x, int y);

		//当前棋盘
		chessBoard cheBoard;

		//规则
		chessRules cheRules;

		//黑棋走
		void BlackGo(int x, int y);
		//黑棋落实
		void BlackDown(int x, int y);

		//白棋落实
		void WhiteDown(int x, int y);
		//白棋走
		void WhiteGo(int x, int y);
		//之前上一步的坐标
		int beforeX=0;
		int beforeY=0;
		
		//电脑
		chessComputer computerPlay;
		//电脑下棋
		void PlayWithComputer(chessBoard board, int beforeX, int beforeY);


	private:
		//下棋键入
		void ChessInput();
		//判断位置是否合理
		void Prejuge(string x, string y);
		

};