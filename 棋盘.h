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
		//��̬����ʱʹ��
		int chLong;
		int chLength;

		chessBoard();
		//��һ����ʼint����
		int intBoard[ChessBoardLong][ChessBoardLength];

		//��һ����ʼchar����
		string strBoard[ChessBoardLong][ChessBoardLength];

		//��ʾ����
		void showBoard();



	private:
		//��ʼ������
		void initialBoard();


};