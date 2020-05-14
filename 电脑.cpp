#include "电脑.h"
#include "下棋.h"
#include <iostream>

Position chessComputer::cptPlay(chessBoard board,int x, int y )
{

	//获取行列大小
	int row = sizeof(board.intBoard) / sizeof(board.intBoard[0]);
	int col = sizeof(board.intBoard[0]) / sizeof(board.intBoard[0][0]);
	//对AI的棋盘数组进行赋值
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			AIBoard[i][j]=board.intBoard[i][j];
		}
	}
	//防守函数
	Position def=cptDefence(x, y);

	//cout << "cptDefence电脑下棋位置x：" << def.x << endl;
	//cout << "cptDefence电脑下棋位置y：" << def.y << endl;
	//cout << "cptDefence电脑下棋位置power：" << def.pow << endl;

	//进攻函数
	Position att = cptAttack( Turns);

	//cout << "cptAttack电脑下棋位置x：" << att.x << endl;
	//cout << "cptAttack电脑下棋位置y：" << att.y << endl;
	//cout << "cptAttack电脑下棋位置power：" << att.pow << endl;

	//进攻or防守
	if (att.pow > def.pow)
		return att;

	return def;
	
	

}

//构造函数
chessComputer::chessComputer(chessBoard board)
{ 
	//对当前棋盘赋值
	cptBoard = board;
	//获取行列大小
	int row = sizeof(board.intBoard) / sizeof(board.intBoard[0]);
	int col = sizeof(board.intBoard[0]) / sizeof(board.intBoard[0][0]);
	//对AI的棋盘数组进行赋值
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			AIBoard[i][j] = board.intBoard[i][j];
		}
	}
}

chessComputer::chessComputer()
{

}

//电脑防守
Position chessComputer::cptDefence(int x, int y)
{


	//获取行列大小
	int row = sizeof(AIBoard) / sizeof(AIBoard[0]); row--;
	int col = sizeof(AIBoard[0]) / sizeof(AIBoard[0][0]);
	//确定位置
	//扫描当前棋子
	//对当前棋子进行处理
	AIBoard[x][y] = AIBoard[x][y] % 10;
	//扫描行，上下左右四个方向扫描
	
	int westEast = 0;	//横向有多少棋子
	int putX, putY;		//要下子的位置
	Position pos;		//返回下棋位置
	int maxDeriction;	//最大方向值
	//扫描右侧：
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
		//连续两个空位
		if (empty == 2 && AIBoard[x][j - 1] == 0) {
			putX = x;
			putY = j - 1;
		}
	}
	//扫描左侧：
	for (int j = y, empty = 0; j >0 && empty < 2; j--) {
		if (AIBoard[x][j] == AIBoard[x][y])
			westEast++;
		else if (AIBoard[x][j] == 0){	//空位，可以下子，根据连续棋子数cont给出下子权重
			empty++;
			putX = x;
			putY = j;
			//AIBoard[x][j]=powReturn(westEast);
		}
			
		else if (AIBoard[x][j] != 0 && AIBoard[x][j] != AIBoard[x][y]) {
			//westEast--;
			break;
		}
		//连续两个空位
		if (empty == 2 && AIBoard[x][j + 1] == 0) {
			putX = x;
			putY = j + 1;
		}
	}
	//最大方向值赋值
	maxDeriction = --westEast;
	//检查横向是否有3个或者4个棋子
	if (westEast >= 3) {		//大于等于3个直接下子
		decided = true;			//结束思考	
		return giveMePos(westEast, putX, putY);
	}
	//上下扫描
	int northSouth = 0;
	//扫描上侧：
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
		//连续两个空位
		if (empty == 2 && AIBoard[i + 1][y] == 0) {
			putX = i + 1;
			putY = y;
		}
	}
	//扫描下侧：
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
		//连续两个空位
		if (empty == 2 && AIBoard[i - 1][y] == 0) {
			putX = i - 1;
			putY = y;
		}
	}
	if (--northSouth > maxDeriction)
		maxDeriction = northSouth;
	//检查纵向一共有多少个棋子
	if (northSouth >= 3) {
		decided = true;			//结束思考
		return giveMePos(northSouth, putX, putY);
	}
	//扫描斜向
	int southEast_northWest = 0;
	//扫描东南
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
		//连续两个空位
		if (empty == 2 && AIBoard[i - 1][j - 1] == 0) {
			putX = i - 1;
			putY = j - 1;
		}
	}
	//扫描西北
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
		//连续两个空位
		if (empty == 2 && AIBoard[i + 1][j + 1] == 0) {
			putX = i + 1;
			putY = j + 1;
		}
	}
	if (--southEast_northWest > maxDeriction)
		maxDeriction = southEast_northWest;
	//检查东南 西北多少个棋子
	if (southEast_northWest >= 3) {
		decided = true;			//结束思考
		return giveMePos(southEast_northWest, putX, putY);
	}
	//扫描东北 西南
	int northEast_southWest = 0;
	//扫描东北
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
		//连续两个空位
		if (empty == 2 && AIBoard[i + 1][j - 1] == 0) {
			putX = i + 1;
			putY = j - 1;
		}
	}
	//扫描西南
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
		//连续两个空位
		if (empty == 2 && AIBoard[i - 1][j + 1] == 0) {
			putX = i-1;
			putY = j+1;
		}

	}
	if (--northEast_southWest > maxDeriction)
		maxDeriction = northEast_southWest;
	//检查东北 西南有没有三个以上的棋子位置
	if (northEast_southWest >= 3) {
		decided = true;			//结束思考
		return giveMePos(northEast_southWest,  putX,  putY);
	}

	//都没有大于等于3个的连续棋子,找最大的方向值
	return giveMePos(maxDeriction,putX,putY);
	
	//在周围下子或者交给进攻函数



}

//电脑进攻
Position chessComputer::cptAttack( int turns)
{
	if (decided == false) {

		Position p;
		p.x = 1;
		p.y = 1;
		p.pow = 0;
		return p;
	}

	cout << "Turns：" << turns << endl;

	//Position *all=new Position[turns];
	Position curPositions[255];
	Position maxPosition= All_Positions[turns];
	for (int i = turns; i > 0; i--) {
		//cout << "电脑之前下棋位置x：" << All_Positions[i].x << endl;
		//cout << "电脑之前下棋位置y：" << All_Positions[i].y << endl;
		//cout << "电脑之前下棋位置power：" << All_Positions[i].pow << endl;

		curPositions[i] = cptDefence(All_Positions[i].x, All_Positions[i].y);

		//cout << "A电脑进攻下棋位置x：" << curPositions[i].x << endl;
		//cout << "A电脑进攻下棋位置y：" << curPositions[i].y << endl;
		//cout << "A电脑进攻下棋位置power：" << curPositions[i].pow << endl;

		if (curPositions[i].pow > maxPosition.pow)
			maxPosition = curPositions[i];

		if (curPositions[i].pow >= 94)
			return curPositions[i];
	}
	//cout << "max电脑下棋位置x：" << maxPosition.x << endl;
	//cout << "max电脑下棋位置y：" << maxPosition.y << endl;
	//cout << "max电脑下棋位置power：" << maxPosition.pow << endl;
	return maxPosition;
}
////数棋子
//Position chessComputer::countingPawns(int x, int y)
//{
//	//获取行列大小
//	int row = sizeof(AIBoard) / sizeof(AIBoard[0]); row--;//去掉坐标轴
//	int col = sizeof(AIBoard[0]) / sizeof(AIBoard[0][0]);
//
//	//对当前棋子进行处理
//	AIBoard[x][y] = AIBoard[x][y] % 10;
//	//扫描行，上下左右方向扫描
//	//记录方向有多少棋子
//	int west,east,north,south;
//	int northEast, northWest, southEast, southWest;
//	int putX, putY;		//要下子的位置
//
//	int maxDeriction;	//最大方向值
//	//扫描右侧：
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
//		//连续两个空位
//		if (empty == 2 && AIBoard[x][j - 1] == 0) {
//			putX = x;
//			putY = j - 1;
//		}
//	}
//	//扫描左侧：
//	for (int j = y, empty = 0; j > 0 && empty < 2; j--) {
//		if (AIBoard[x][j] == AIBoard[x][y])
//			westEast++;
//		else if (AIBoard[x][j] == 0) {	//空位，可以下子，根据连续棋子数cont给出下子权重
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
//		//连续两个空位
//		if (empty == 2 && AIBoard[x][j + 1] == 0) {
//			putX = x;
//			putY = j + 1;
//		}
//	}
//	//最大方向值赋值
//	maxDeriction = --westEast;
//	//检查横向是否有3个或者4个棋子
//	if (westEast >= 3) {		//大于等于3个直接下子
//		decided = true;			//结束思考	
//		return giveMePos(westEast, putX, putY);
//	}
//	//上下扫描
//	int northSouth = 0;
//	//扫描上侧：
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
//		//连续两个空位
//		if (empty == 2 && AIBoard[i + 1][y] == 0) {
//			putX = i + 1;
//			putY = y;
//		}
//	}
//	//扫描下侧：
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
//		//连续两个空位
//		if (empty == 2 && AIBoard[i - 1][y] == 0) {
//			putX = i - 1;
//			putY = y;
//		}
//	}
//	if (--northSouth > maxDeriction)
//		maxDeriction = northSouth;
//	//检查纵向一共有多少个棋子
//	if (northSouth >= 3) {
//		decided = true;			//结束思考
//		return giveMePos(northSouth, putX, putY);
//	}
//	//扫描斜向
//	int southEast_northWest = 0;
//	//扫描东南
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
//		//连续两个空位
//		if (empty == 2 && AIBoard[i - 1][j - 1] == 0) {
//			putX = i - 1;
//			putY = j - 1;
//		}
//	}
//	//扫描西北
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
//		//连续两个空位
//		if (empty == 2 && AIBoard[i + 1][j + 1] == 0) {
//			putX = i + 1;
//			putY = j + 1;
//		}
//	}
//	if (--southEast_northWest > maxDeriction)
//		maxDeriction = southEast_northWest;
//	//检查东南 西北多少个棋子
//	if (southEast_northWest >= 3) {
//		decided = true;			//结束思考
//		return giveMePos(southEast_northWest, putX, putY);
//	}
//	//扫描东北 西南
//	int northEast_southWest = 0;
//	//扫描东北
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
//		//连续两个空位
//		if (empty == 2 && AIBoard[i + 1][j - 1] == 0) {
//			putX = i + 1;
//			putY = j - 1;
//		}
//	}
//	//扫描西南
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
//		//连续两个空位
//		if (empty == 2 && AIBoard[i - 1][j + 1] == 0) {
//			putX = i - 1;
//			putY = j + 1;
//		}
//
//	}
//	if (--northEast_southWest > maxDeriction)
//		maxDeriction = northEast_southWest;
//	//检查东北 西南有没有三个以上的棋子位置
//	if (northEast_southWest >= 3) {
//		decided = true;			//结束思考
//		return giveMePos(northEast_southWest, putX, putY);
//	}
//
//	//都没有大于等于3个的连续棋子,找最大的方向值
//	return giveMePos(maxDeriction, putX, putY);
//	return Position();
//}

//代码复用
//根据连续的棋子数目给出空位的权重值
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