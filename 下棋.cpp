/*

*/

#include "����.h";
#include "����.h";
#include "��ʼ.h";
#include "����.h";
#include "����.h";
#include <time.h>
#include <stdio.h>
#include<iostream>
#include <sstream>template <typename T>



//��ǰ�º���
void playChess::BlackGo(int x, int y)
{
	//cout << "��ǰ�º���!" << endl;
	//�ó������еĵ�
	string pawn=cheBoard.strBoard[x][y];
	
	//������µ�����:
	pawn.replace(pawn.length()-4, pawn.length() - 2, "��");

	//cout << "pawn length:" << pawn.length() << endl;
	//���µĺ��壬���������̸�ֵΪ11
	cheBoard.intBoard[x][y] = 11;
	//�޸�����
	cheBoard.strBoard[x][y] = pawn;
	//��ӡ����
	cheBoard.showBoard();
	//��ֵ����ǰλ�ø�ֵ��������ʵ���Ӹı�ͼ��

	//cout << "BlackGo x:" << x << "y:" << y << endl;
	//cout << "BlackGo beforex:" << beforeX << "beforey:" << beforeY << endl;
	//*PbeforeX = x;
	//*PbeforeY = y;
	//cout << "BlackGo *PbeforeX:" << *PbeforeX << " *PbeforeY:" << *PbeforeY << endl;
	beforeX = x;
	beforeY = y;
	//cout << "BlackGo beforex:" << beforeX << "beforey:" << beforeY << endl;
}

//��֮ǰ���µĺ����Ϊ��ʵ�ĺ���
void playChess::BlackDown(int x, int y)
{
	//cout << "������!" << endl;
	//cout << "������! x:" << x <<"y:"<<y<< endl;
	if (cheBoard.intBoard[x][y] == 11) {
		
		//�ó������еĵ�
		string pawn = cheBoard.strBoard[x][y];
		//������µĺ���
		//pawnst = pawnst[0] + chePawn.BlackPawn + pawnst[2];
		//pawnst = pawnst[0] +"" + pawnst[2];

		//cout << "������! pawnst:" << pawn << endl;
		//cout << "������! pawnst length:" << pawn.length() << endl;

		pawn.replace(pawn.length() - 2, pawn.length() - 0, "��");

		//cout << "������! pawnst:" << pawn << endl;
		//�޸�����
		cheBoard.strBoard[x][y] = pawn;
		//��ӡ����
		cheBoard.showBoard();
		//���壬���������̸�ֵΪ1
		cheBoard.intBoard[x][y] = 1;
	}
}


//��ǰ�°���
void playChess::WhiteGo(int x, int y)
{
	//cout << "��ǰ�°���!" << endl;
	//�ó������еĵ�
	string pawnst = cheBoard.strBoard[x][y];
	//������µ�����
	//pawnst = pawnst[0] + chePawn.WhiteJustDown + pawnst[2];

	//cout << "��ǰ�°���! pawnst:" << pawnst << endl;
	//cout << "��ǰ�°���! pawnst length:" << pawnst.length() << endl;


	//ͨ���ַ����滻��ʹ���̼�������
	pawnst.replace(pawnst.length()-4, pawnst.length() - 2, "��");

	//cout << "��ǰ�°���! pawnst:" << pawnst << endl;
	//���µİ��壬���������̸�ֵΪ22
	cheBoard.intBoard[x][y] = 22;
	//�޸�����
	cheBoard.strBoard[x][y] = pawnst;
	//��ӡ����
	cheBoard.showBoard();
	//��ֵ����ǰλ�ø�ֵ��������ʵ���Ӹı�ͼ��
	beforeX = x;
	beforeY = y;

}

//��֮ǰ���µİ����Ϊ��ʵ�İ���
void playChess::WhiteDown(int x, int y)
{
	//cout << "�����䣡"  << endl;
	//cout << "WhiteDown x:" << x << "y:" << y << endl;
	//cout << "WhiteDown cheBoard.intBoard:" << cheBoard.intBoard[x][y] << endl;

	if (cheBoard.intBoard[x][y] == 22) {

		
		//�ó������еĵ�
		string pawnst = cheBoard.strBoard[x][y];

		//cout << "WhiteDown pawnst:" << pawnst << endl;
		//cout << "WhiteDown pawnst length:" << pawnst.length() << endl;
		//ͨ���ַ����滻��ʹ���̼�������
		pawnst.replace(pawnst.length() - 2, pawnst.length() - 0, "��");
		//�޸�����
		cheBoard.strBoard[x][y] = pawnst;
		//��ӡ����
		cheBoard.showBoard();
		//���壬���������̸�ֵΪ2
		cheBoard.intBoard[x][y] = 2;
	}
}

//��������
void playChess::PlayWithComputer(chessBoard board, int beforeX, int beforeY)
{
	
	Position whereDownPawn = computerPlay.cptPlay(board, beforeX, beforeY);
	//cout << "��������whereDownPawn.x=" << whereDownPawn.x << endl;
	//cout << "��������whereDownPawn.y=" << whereDownPawn.y << endl;
	//cout << "��������whereDownPawn.pow=" << whereDownPawn.pow << endl;

	//��¼����λ��
	whereDownPawn.pow = 0;//���ԭ����Ȩ��ֵ��
	computerPlay.All_Positions[WhosTurn / 2] = whereDownPawn;
	computerPlay.Turns = WhosTurn / 2;
	//��������������
	PawnOnBoard(whereDownPawn.x, whereDownPawn.y);

}

//�������
void playChess::ChessInput()
{
	//cheRules.showRules;
	
	do {
		string sx, sy;
		cout << "������λ��" << endl;
		cin >> sx >> sy;

		Prejuge(sx, sy);	//�ж�λ���Ƿ����
		if (cheRules.Result)//��Ϸ�Ƿ����
			break;
		if (WhosTurn % 2 == 0)
			PlayWithComputer(cheBoard,beforeX,beforeY);	//�����°���
	} while (!cheRules.Result);
	//system("cls");
	cout << "��������������������Ϸ������������������������:" << cheRules.Result << endl;
}

//�ж�����λ���Ƿ����
void playChess::Prejuge(string x, string y)
 {

	int ix=atoi(x.c_str());	//stringתint
	int iy=0;
	cout << "ix=" <<ix<< endl;

	string letter = "ABCDEFGHIJKLMNO";

	cout << "�ж�����λ���Ƿ����:" << endl;
	bool flag = false;
	while (1) {
		if (ix >= 1 && ix <= ChessBoardLong - 1 && y.length()==1) {

			//��ĸ�Ƿ����
			for (int i = 0; i < 16; i++) {
				if (y[0]== letter[i]) {
					iy = i;
					
					flag = true;
					break;//for
				}
			}
			//������λ���Ѿ��¹�������
			iy++;//����
			ix = ChessBoardLength - 1 - ix;
			if (cheBoard.intBoard[ix][iy] != 0) {

				cout << "������λ���Ѿ��¹�������:" << cheBoard.intBoard[ix][iy] << endl;
				flag = false;
			}
				

			if (flag == false) {
				cout << "��������ȷλ��" << endl;
				cin >> x >> y;
				ix = atoi(x.c_str());
				cout << "ix=" << ix << endl;
			}
			else 
				break;	//while
		}
		else {
			cout << "����������λ��" << endl;
			cin >> x >> y;
			ix = atoi(x.c_str());
			cout << "ix=" << ix << endl;
		}
	}//while

			cout << "�� " <<x<<" , "<<y<<" ������"<< endl;
			//��������������
			PawnOnBoard(ix,iy);

}


//����
void playChess::PawnOnBoard(int x,int y)
{

	//cout << "x=" << x << "  y=" << y << endl;
	//cout << "WhosTurn=" << WhosTurn << " �غ�"  << endl;

	//�º��廹�ǰ��壿
	if (WhosTurn %2== 1) {

		//������
		WhiteDown(beforeX,beforeY);
		
		//������
		BlackGo(x,y);

		//�ж���Ӯ
		cheRules.Result = cheRules.gameOver(cheBoard, x, y);
		if (cheRules.Result) {
			cout << "����Ӯ��" << endl;
			system("pause");
		}
		//��һ�غ�
		WhosTurn++;
	}
	else {
		
		//������
		BlackDown(beforeX, beforeY);
		//������
		WhiteGo(x,y);
		//�ж���Ӯ
		cheRules.Result = cheRules.gameOver(cheBoard, x, y);
		if (cheRules.Result) {
			cout << "����Ӯ��" << endl;
			system("pause");
		}
			
		WhosTurn++;
	}

}

//����
playChess::playChess(chessBoard board)
{	
	//��ֵ����
	cheBoard = board;
	//��ʼ���غ�
	WhosTurn = 1;
	//��ʼ����һ��
	beforeX = 0; beforeY = 0;
	//��ʼ���������
	cheRules = chessRules(board);
	//��ʼ������
	computerPlay = chessComputer(board);

	//��ʼ�������
	ChessInput();
	
}
