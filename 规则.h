#pragma once
#include <iostream>
#include <string>
#include "棋盘.h"



class chessRules {

	public:
		//显示规则
		void showRules();
	
		//游戏结束？
		bool gameOver(chessBoard curBoard,int x,int y);
		//当前棋盘
		chessBoard curBoard;
		//当前结果
		bool Result = false;
		//初始化
		chessRules(chessBoard board);

		chessRules();


};