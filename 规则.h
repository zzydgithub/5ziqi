#pragma once
#include <iostream>
#include <string>
#include "����.h"



class chessRules {

	public:
		//��ʾ����
		void showRules();
	
		//��Ϸ������
		bool gameOver(chessBoard curBoard,int x,int y);
		//��ǰ����
		chessBoard curBoard;
		//��ǰ���
		bool Result = false;
		//��ʼ��
		chessRules(chessBoard board);

		chessRules();


};