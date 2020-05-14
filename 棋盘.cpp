/*


*/

#include "����.h" 
#include "����.h" 
#include <string>
#include <time.h>
#include <stdio.h>
#include <sstream>template <typename T>



void chessBoard::initialBoard() {

	//��ȡ���鳤��
	int lines = sizeof(intBoard) / sizeof(intBoard[0][0]);
	int row = sizeof(intBoard) / sizeof(intBoard[0]);
	int column = lines / row;

	
	//��ʼ������

	const string seed = "ABCDEFGHIJKLMNO";

	int sn = 0;	//�����б���
	int sb = 15;	//�����б�����
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < column; j++) {
			//�����±�
			if (i == 15&&j>0) {
				stringstream sSseed;
				sSseed << "  " << seed[sn] ;//���ո�

				strBoard[i][j] = sSseed.str();
				sn++;
				//cout << " "<<seed[sn++]<<" ";
			}
			//�����ϱ�
			if (j == 0 ) {
				
				//int תstring
				std::stringstream sbTemp;
				sbTemp << setw(2) << setfill('0') << sb;//����λ ��λ����

				strBoard[i][j] = sbTemp.str();
				sb--;
				//cout << setw(2) << setfill('0')<< sb--;

			}
			//��һ����
			if (i == 0 && j > 1 && j < 15) {
				strBoard[i][j] = "���Щ�";
				//cout << " �� ";
			}
			//���һ����
			if (i == 14 && j > 1 && j < 15) {
				strBoard[i][j] = "���ة�";
				//cout << " �� ";
			}
			//�ڶ�����
			if (j == 1 && i > 0 && i < 14) {
				strBoard[i][j] = "  ����";
				//cout << " �� ";
			}
			//���һ����
			if (j == 15 && i > 0 && i < 14) {
				strBoard[i][j] = "����  ";
				//cout << " �� ";
			}
			//�м�ʮ����
			if (i > 0 && i < 14 && j>1 && j < 15) {
				strBoard[i][j] = "���੤";
				//cout << " �� ";
			}
			//���Ͻ�
			if (i == 0 && j == 1) {
				strBoard[i][j] = "  ����";
				//cout << " �� ";
			}
			//���Ͻ�
			if (i == 0 && j == 15) {
				strBoard[i][j] = "����  ";
				//cout << " �� ";
			}
			//���½�
			if (i == 14 && j == 1) {
				strBoard[i][j] = "  ����";
				//cout << " �� ";
			}
			//���½�
			if (i == 14 && j == 15) {
				strBoard[i][j] = "����  ";
				//cout << " �� ";
			}
			//��int�����ʼ��
			intBoard[i][j] = 0;
		}
		//cout << "\n\n";
	}


}


chessBoard::chessBoard()
{
	initialBoard();
}



void chessBoard::showBoard() {

	//��ȡ���鳤��
	int lines = sizeof(strBoard) / sizeof(strBoard[0][0]);
	int row = sizeof(strBoard) / sizeof(strBoard[0]);
	int column = lines / row;

	//�м������
	string fill = "    ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��";
	//����
	system("cls");
	//��ӡstring����
	for (int i = 0; i < row; i++) {

		
		for (int j = 0; j < column; j++) {

			cout  << strBoard[i][j] ;

		}
		cout << "\n";
		if (i<row-2) {
			cout << fill<<endl;
		}
	}

}

int GetIntArrayLength(int array[]) {

	//int lines = sizeof(array) / sizeof(array[0][0]);
	int row = sizeof(array) / sizeof(array[0]);

	return row;
}