#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int ChessBoardLong = 16;
const int ChessBoardLength = 16;
const string BoardButton = "ABCDEFGHIJKLMNO";

int GetIntArrayLength(int array[]);

class chessBoard {
	
	public:
		//动态设置时使用
		int chLong;
		int chLength;

		chessBoard();
		//做一个初始int棋盘
		int intBoard[ChessBoardLong][ChessBoardLength];

		//做一个初始char棋盘
		string strBoard[ChessBoardLong][ChessBoardLength];

		//显示棋盘
		void showBoard();



	private:
		//初始化棋盘
		void initialBoard();


};