#include "����.h"
#include "����.h"
#include <iostream>

Position chessComputer::cptPlay(chessBoard board,int x, int y )
{

	//��ȡ���д�С
	int row = sizeof(board.intBoard) / sizeof(board.intBoard[0]);
	int col = sizeof(board.intBoard[0]) / sizeof(board.intBoard[0][0]);
	//��AI������������и�ֵ
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			AIBoard[i][j]=board.intBoard[i][j];
		}
	}
	//���غ���
	Position def=cptDefence(x, y);

	//cout << "cptDefence��������λ��x��" << def.x << endl;
	//cout << "cptDefence��������λ��y��" << def.y << endl;
	//cout << "cptDefence��������λ��power��" << def.pow << endl;

	//��������
	Position att = cptAttack( Turns);

	//cout << "cptAttack��������λ��x��" << att.x << endl;
	//cout << "cptAttack��������λ��y��" << att.y << endl;
	//cout << "cptAttack��������λ��power��" << att.pow << endl;

	//����or����
	if (att.pow > def.pow)
		return att;

	return def;
	
	

}

//���캯��
chessComputer::chessComputer(chessBoard board)
{ 
	//�Ե�ǰ���̸�ֵ
	cptBoard = board;
	//��ȡ���д�С
	int row = sizeof(board.intBoard) / sizeof(board.intBoard[0]);
	int col = sizeof(board.intBoard[0]) / sizeof(board.intBoard[0][0]);
	//��AI������������и�ֵ
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			AIBoard[i][j] = board.intBoard[i][j];
		}
	}
}

chessComputer::chessComputer()
{

}

//���Է���
Position chessComputer::cptDefence(int x, int y)
{


	//��ȡ���д�С
	int row = sizeof(AIBoard) / sizeof(AIBoard[0]); row--;
	int col = sizeof(AIBoard[0]) / sizeof(AIBoard[0][0]);
	//ȷ��λ��
	//ɨ�赱ǰ����
	//�Ե�ǰ���ӽ��д���
	AIBoard[x][y] = AIBoard[x][y] % 10;
	//ɨ���У����������ĸ�����ɨ��
	
	int westEast = 0;	//�����ж�������
	int putX, putY;		//Ҫ���ӵ�λ��
	Position pos;		//��������λ��
	int maxDeriction;	//�����ֵ
	//ɨ���Ҳࣺ
	for (int j = y,empty=0; j <= col && empty<2; j++) {
		if (AIBoard[x][j] == AIBoard[x][y])
			westEast++;
		else if (AIBoard[x][j] == 0)
		{
			empty++;
			putX = x;
			putY = j;
			
		}
		else if (AIBoard[x][j] != 0 && AIBoard[x][j] != AIBoard[x][y]){
			//westEast--;
			break;
		}
		//����������λ
		if (empty == 2 && AIBoard[x][j - 1] == 0) {
			putX = x;
			putY = j - 1;
		}
	}
	//ɨ����ࣺ
	for (int j = y, empty = 0; j >0 && empty < 2; j--) {
		if (AIBoard[x][j] == AIBoard[x][y])
			westEast++;
		else if (AIBoard[x][j] == 0){	//��λ���������ӣ���������������cont��������Ȩ��
			empty++;
			putX = x;
			putY = j;
			//AIBoard[x][j]=powReturn(westEast);
		}
			
		else if (AIBoard[x][j] != 0 && AIBoard[x][j] != AIBoard[x][y]) {
			//westEast--;
			break;
		}
		//����������λ
		if (empty == 2 && AIBoard[x][j + 1] == 0) {
			putX = x;
			putY = j + 1;
		}
	}
	//�����ֵ��ֵ
	maxDeriction = --westEast;
	//�������Ƿ���3������4������
	if (westEast >= 3) {		//���ڵ���3��ֱ������
		decided = true;			//����˼��	
		return giveMePos(westEast, putX, putY);
	}
	//����ɨ��
	int northSouth = 0;
	//ɨ���ϲࣺ
	for (int i = x, empty = 0; i >= 0 && empty < 2; i--) {
		if (AIBoard[i][y] == AIBoard[x][y])
			northSouth++;
		else if (AIBoard[i][y] == 0)
		{
			empty++;
			putX = i;
			putY = y;
			//AIBoard[i][y] = powReturn(northSouth);
		}
		else if (AIBoard[i][y] != 0 && AIBoard[i][y] != AIBoard[x][y]) {
			//northSouth--;
			break;
		}
		//����������λ
		if (empty == 2 && AIBoard[i + 1][y] == 0) {
			putX = i + 1;
			putY = y;
		}
	}
	//ɨ���²ࣺ
	for (int i = x, empty = 0; i <row && empty < 2; i++) {
		if (AIBoard[i][y] == AIBoard[x][y])
			northSouth++;
		else if (AIBoard[i][y] == 0)
		{
			empty++;
			putX = i;
			putY = y;
			//AIBoard[i][y]= powReturn(northSouth);
		}
		else if (AIBoard[i][y] != 0 && AIBoard[i][y] != AIBoard[x][y]) {
			//northSouth--;
			break;
		}
		//����������λ
		if (empty == 2 && AIBoard[i - 1][y] == 0) {
			putX = i - 1;
			putY = y;
		}
	}
	if (--northSouth > maxDeriction)
		maxDeriction = northSouth;
	//�������һ���ж��ٸ�����
	if (northSouth >= 3) {
		decided = true;			//����˼��
		return giveMePos(northSouth, putX, putY);
	}
	//ɨ��б��
	int southEast_northWest = 0;
	//ɨ�趫��
	for (int i = x, j = y, empty = 0; i < row && j < col && empty < 2; i++, j++) {
		if (AIBoard[i][j] == AIBoard[x][y])
			southEast_northWest++;
		else if (AIBoard[i][j] == 0)
		{
			empty++;
			putX = i;
			putY = j;
			//AIBoard[i][j] = powReturn(southEast_northWest);
		}
		else if (AIBoard[i][j] != 0 && AIBoard[i][j] != AIBoard[x][y]) {
			//southEast_northWest--;
			break;
		}
		//����������λ
		if (empty == 2 && AIBoard[i - 1][j - 1] == 0) {
			putX = i - 1;
			putY = j - 1;
		}
	}
	//ɨ������
	for (int i = x, j = y, empty = 0; i > 0 && j >0 && empty < 2; i--, j--) {
		if (AIBoard[i][j] == AIBoard[x][y])
			southEast_northWest++;
		else if (AIBoard[i][j] == 0)
		{
			empty++;
			putX = i;
			putY = j;
			//AIBoard[i][j] = powReturn(southEast_northWest);
		}
		else if (AIBoard[i][j] != 0 && AIBoard[i][j] != AIBoard[x][y]) {
			//southEast_northWest--;
			break;
		}
		//����������λ
		if (empty == 2 && AIBoard[i + 1][j + 1] == 0) {
			putX = i + 1;
			putY = j + 1;
		}
	}
	if (--southEast_northWest > maxDeriction)
		maxDeriction = southEast_northWest;
	//��鶫�� �������ٸ�����
	if (southEast_northWest >= 3) {
		decided = true;			//����˼��
		return giveMePos(southEast_northWest, putX, putY);
	}
	//ɨ�趫�� ����
	int northEast_southWest = 0;
	//ɨ�趫��
	for (int i = x, j = y, empty = 0; i > 0 && j <col && empty < 2; i--, j++) {
		if (AIBoard[i][j] == AIBoard[x][y])
			northEast_southWest++;
		else if (AIBoard[i][j] == 0)
		{
			empty++;
			putX = i;
			putY = j;
			//AIBoard[i][j] = powReturn(northEast_southWest);
		}
		else if (AIBoard[i][j] != 0 && AIBoard[i][j] != AIBoard[x][y]) {
			//northEast_southWest--;
			break;
		}
		//����������λ
		if (empty == 2 && AIBoard[i + 1][j - 1] == 0) {
			putX = i + 1;
			putY = j - 1;
		}
	}
	//ɨ������
	for (int i = x, j = y, empty = 0; i <row && j >0 && empty < 2; i++, j--) {
		if (AIBoard[i][j] == AIBoard[x][y])
			northEast_southWest++;
		else if (AIBoard[i][j] == 0)
		{
			empty++;
			putX = i;
			putY = j;
			//AIBoard[i][j] = powReturn(northEast_southWest);
		}
		else if (AIBoard[i][j] != 0 && AIBoard[i][j] != AIBoard[x][y]) {
			//northEast_southWest--;
			break;
		}
		//����������λ
		if (empty == 2 && AIBoard[i - 1][j + 1] == 0) {
			putX = i-1;
			putY = j+1;
		}

	}
	if (--northEast_southWest > maxDeriction)
		maxDeriction = northEast_southWest;
	//��鶫�� ������û���������ϵ�����λ��
	if (northEast_southWest >= 3) {
		decided = true;			//����˼��
		return giveMePos(northEast_southWest,  putX,  putY);
	}

	//��û�д��ڵ���3������������,�����ķ���ֵ
	return giveMePos(maxDeriction,putX,putY);
	
	//����Χ���ӻ��߽�����������



}

//���Խ���
Position chessComputer::cptAttack( int turns)
{
	if (decided == false) {

		Position p;
		p.x = 1;
		p.y = 1;
		p.pow = 0;
		return p;
	}

	cout << "Turns��" << turns << endl;

	//Position *all=new Position[turns];
	Position curPositions[255];
	Position maxPosition= All_Positions[turns];
	for (int i = turns; i > 0; i--) {
		//cout << "����֮ǰ����λ��x��" << All_Positions[i].x << endl;
		//cout << "����֮ǰ����λ��y��" << All_Positions[i].y << endl;
		//cout << "����֮ǰ����λ��power��" << All_Positions[i].pow << endl;

		curPositions[i] = cptDefence(All_Positions[i].x, All_Positions[i].y);

		//cout << "A���Խ�������λ��x��" << curPositions[i].x << endl;
		//cout << "A���Խ�������λ��y��" << curPositions[i].y << endl;
		//cout << "A���Խ�������λ��power��" << curPositions[i].pow << endl;

		if (curPositions[i].pow > maxPosition.pow)
			maxPosition = curPositions[i];

		if (curPositions[i].pow >= 94)
			return curPositions[i];
	}
	//cout << "max��������λ��x��" << maxPosition.x << endl;
	//cout << "max��������λ��y��" << maxPosition.y << endl;
	//cout << "max��������λ��power��" << maxPosition.pow << endl;
	return maxPosition;
}
////������
//Position chessComputer::countingPawns(int x, int y)
//{
//	//��ȡ���д�С
//	int row = sizeof(AIBoard) / sizeof(AIBoard[0]); row--;//ȥ��������
//	int col = sizeof(AIBoard[0]) / sizeof(AIBoard[0][0]);
//
//	//�Ե�ǰ���ӽ��д���
//	AIBoard[x][y] = AIBoard[x][y] % 10;
//	//ɨ���У��������ҷ���ɨ��
//	//��¼�����ж�������
//	int west,east,north,south;
//	int northEast, northWest, southEast, southWest;
//	int putX, putY;		//Ҫ���ӵ�λ��
//
//	int maxDeriction;	//�����ֵ
//	//ɨ���Ҳࣺ
//	for (int j = y, empty = 0; j <= col && empty < 2; j++) {
//		if (AIBoard[x][j] == AIBoard[x][y])
//			east++;
//		else if (AIBoard[x][j] == 0)
//		{
//			empty++;
//			putX = x;
//			putY = j;
//
//		}
//		else if (AIBoard[x][j] != 0 && AIBoard[x][j] != AIBoard[x][y]) {
//			//westEast--;
//			break;
//		}
//		//����������λ
//		if (empty == 2 && AIBoard[x][j - 1] == 0) {
//			putX = x;
//			putY = j - 1;
//		}
//	}
//	//ɨ����ࣺ
//	for (int j = y, empty = 0; j > 0 && empty < 2; j--) {
//		if (AIBoard[x][j] == AIBoard[x][y])
//			westEast++;
//		else if (AIBoard[x][j] == 0) {	//��λ���������ӣ���������������cont��������Ȩ��
//			empty++;
//			putX = x;
//			putY = j;
//			//AIBoard[x][j]=powReturn(westEast);
//		}
//
//		else if (AIBoard[x][j] != 0 && AIBoard[x][j] != AIBoard[x][y]) {
//			//westEast--;
//			break;
//		}
//		//����������λ
//		if (empty == 2 && AIBoard[x][j + 1] == 0) {
//			putX = x;
//			putY = j + 1;
//		}
//	}
//	//�����ֵ��ֵ
//	maxDeriction = --westEast;
//	//�������Ƿ���3������4������
//	if (westEast >= 3) {		//���ڵ���3��ֱ������
//		decided = true;			//����˼��	
//		return giveMePos(westEast, putX, putY);
//	}
//	//����ɨ��
//	int northSouth = 0;
//	//ɨ���ϲࣺ
//	for (int i = x, empty = 0; i >= 0 && empty < 2; i--) {
//		if (AIBoard[i][y] == AIBoard[x][y])
//			northSouth++;
//		else if (AIBoard[i][y] == 0)
//		{
//			empty++;
//			putX = i;
//			putY = y;
//			//AIBoard[i][y] = powReturn(northSouth);
//		}
//		else if (AIBoard[i][y] != 0 && AIBoard[i][y] != AIBoard[x][y]) {
//			//northSouth--;
//			break;
//		}
//		//����������λ
//		if (empty == 2 && AIBoard[i + 1][y] == 0) {
//			putX = i + 1;
//			putY = y;
//		}
//	}
//	//ɨ���²ࣺ
//	for (int i = x, empty = 0; i < row && empty < 2; i++) {
//		if (AIBoard[i][y] == AIBoard[x][y])
//			northSouth++;
//		else if (AIBoard[i][y] == 0)
//		{
//			empty++;
//			putX = i;
//			putY = y;
//			//AIBoard[i][y]= powReturn(northSouth);
//		}
//		else if (AIBoard[i][y] != 0 && AIBoard[i][y] != AIBoard[x][y]) {
//			//northSouth--;
//			break;
//		}
//		//����������λ
//		if (empty == 2 && AIBoard[i - 1][y] == 0) {
//			putX = i - 1;
//			putY = y;
//		}
//	}
//	if (--northSouth > maxDeriction)
//		maxDeriction = northSouth;
//	//�������һ���ж��ٸ�����
//	if (northSouth >= 3) {
//		decided = true;			//����˼��
//		return giveMePos(northSouth, putX, putY);
//	}
//	//ɨ��б��
//	int southEast_northWest = 0;
//	//ɨ�趫��
//	for (int i = x, j = y, empty = 0; i < row && j < col && empty < 2; i++, j++) {
//		if (AIBoard[i][j] == AIBoard[x][y])
//			southEast_northWest++;
//		else if (AIBoard[i][j] == 0)
//		{
//			empty++;
//			putX = i;
//			putY = j;
//			//AIBoard[i][j] = powReturn(southEast_northWest);
//		}
//		else if (AIBoard[i][j] != 0 && AIBoard[i][j] != AIBoard[x][y]) {
//			//southEast_northWest--;
//			break;
//		}
//		//����������λ
//		if (empty == 2 && AIBoard[i - 1][j - 1] == 0) {
//			putX = i - 1;
//			putY = j - 1;
//		}
//	}
//	//ɨ������
//	for (int i = x, j = y, empty = 0; i > 0 && j > 0 && empty < 2; i--, j--) {
//		if (AIBoard[i][j] == AIBoard[x][y])
//			southEast_northWest++;
//		else if (AIBoard[i][j] == 0)
//		{
//			empty++;
//			putX = i;
//			putY = j;
//			//AIBoard[i][j] = powReturn(southEast_northWest);
//		}
//		else if (AIBoard[i][j] != 0 && AIBoard[i][j] != AIBoard[x][y]) {
//			//southEast_northWest--;
//			break;
//		}
//		//����������λ
//		if (empty == 2 && AIBoard[i + 1][j + 1] == 0) {
//			putX = i + 1;
//			putY = j + 1;
//		}
//	}
//	if (--southEast_northWest > maxDeriction)
//		maxDeriction = southEast_northWest;
//	//��鶫�� �������ٸ�����
//	if (southEast_northWest >= 3) {
//		decided = true;			//����˼��
//		return giveMePos(southEast_northWest, putX, putY);
//	}
//	//ɨ�趫�� ����
//	int northEast_southWest = 0;
//	//ɨ�趫��
//	for (int i = x, j = y, empty = 0; i > 0 && j < col && empty < 2; i--, j++) {
//		if (AIBoard[i][j] == AIBoard[x][y])
//			northEast_southWest++;
//		else if (AIBoard[i][j] == 0)
//		{
//			empty++;
//			putX = i;
//			putY = j;
//			//AIBoard[i][j] = powReturn(northEast_southWest);
//		}
//		else if (AIBoard[i][j] != 0 && AIBoard[i][j] != AIBoard[x][y]) {
//			//northEast_southWest--;
//			break;
//		}
//		//����������λ
//		if (empty == 2 && AIBoard[i + 1][j - 1] == 0) {
//			putX = i + 1;
//			putY = j - 1;
//		}
//	}
//	//ɨ������
//	for (int i = x, j = y, empty = 0; i < row && j >0 && empty < 2; i++, j--) {
//		if (AIBoard[i][j] == AIBoard[x][y])
//			northEast_southWest++;
//		else if (AIBoard[i][j] == 0)
//		{
//			empty++;
//			putX = i;
//			putY = j;
//			//AIBoard[i][j] = powReturn(northEast_southWest);
//		}
//		else if (AIBoard[i][j] != 0 && AIBoard[i][j] != AIBoard[x][y]) {
//			//northEast_southWest--;
//			break;
//		}
//		//����������λ
//		if (empty == 2 && AIBoard[i - 1][j + 1] == 0) {
//			putX = i - 1;
//			putY = j + 1;
//		}
//
//	}
//	if (--northEast_southWest > maxDeriction)
//		maxDeriction = northEast_southWest;
//	//��鶫�� ������û���������ϵ�����λ��
//	if (northEast_southWest >= 3) {
//		decided = true;			//����˼��
//		return giveMePos(northEast_southWest, putX, putY);
//	}
//
//	//��û�д��ڵ���3������������,�����ķ���ֵ
//	return giveMePos(maxDeriction, putX, putY);
//	return Position();
//}

//���븴��
//����������������Ŀ������λ��Ȩ��ֵ
int chessComputer::powReturn(int cont) {

	if (cont == 4)
		return 94;
	if (cont == 3)
		return 83;
	if (cont == 2)
		return 42;
	if (cont == 1)
		return 31;
	else
		return 10;

}

Position chessComputer::giveMePos(int num, int x, int y)
{
	Position result;
	result.x = x;
	result.y = y;
	result.pow = 0;

	if (num == 4)
		result.pow = 94;
	if (num == 3)	
		result.pow = 83;
	if (num == 2)
		result.pow = 42;
	if (num == 1)
		result.pow = 31;

	return result;
}