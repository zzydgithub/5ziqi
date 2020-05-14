#pragma once
#include <iostream>
#include <string>
#include "����.h"
using namespace std;
/*
	�������������AI����Ҫ˼�����ȷ����ٽ���������������ڷ����������������ش��ڽ����ͷ���
	����������һ������λ�ã�һ�����ط���λ�ã��ĸ�ֵ������ĸ�
	���أ����ȿ���ǰ���µ�λ�ã�������û���ĸ�����һ��ģ�����������һ��ģ�����2+1,2+2��3+3,4+4
	��������4������3����������3+3����2������2+2����һ����
*/

//����λ��
struct Position {
			int x;		//x��
			int y;		//y��
			double pow;	//Ȩ��ֵ
		};

class chessComputer {

	public:
		chessBoard cptBoard;
		//��������
		int AIBoard[16][16];
		//�����λ��
		struct Position All_Positions[225];
		//�غ���
		int Turns;
		//���õ�������
		Position cptPlay(chessBoard board, int x, int y);
		//�Ƿ��Ѿ���������λ��
		bool decided = false;
		
		chessComputer(chessBoard board);
		chessComputer( );
	private:
		//���غ���
		Position cptDefence(int x,int y);
		//��������
		Position cptAttack( int turns);
		//�����Ӹ���
		Position countingPawns(int x, int y);
		//����λ�ý��
		Position giveMePos(int num, int x, int y);
		
		int powReturn(int cont);
};