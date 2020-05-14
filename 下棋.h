#pragma once
#include <iostream>
#include <string>
#include "����.h"
#include "����.h"
#include "��ʼ.h"
#include "����.h"
using namespace std;



class playChess {

	public:
		//���廹�ǰ����ߣ�
		int WhosTurn = 1;
		//���캯��
		playChess(chessBoard board );

		//����������
		void PawnOnBoard(int x, int y);

		//��ǰ����
		chessBoard cheBoard;

		//����
		chessRules cheRules;

		//������
		void BlackGo(int x, int y);
		//������ʵ
		void BlackDown(int x, int y);

		//������ʵ
		void WhiteDown(int x, int y);
		//������
		void WhiteGo(int x, int y);
		//֮ǰ��һ��������
		int beforeX=0;
		int beforeY=0;
		
		//����
		chessComputer computerPlay;
		//��������
		void PlayWithComputer(chessBoard board, int beforeX, int beforeY);


	private:
		//�������
		void ChessInput();
		//�ж�λ���Ƿ����
		void Prejuge(string x, string y);
		

};