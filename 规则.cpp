#include "规则.h";
#include "棋盘.h";

void chessRules::showRules()
{
	cout << "二、五子棋比赛规则:•	行棋顺序\n"
		<< "黑先、白后，从天元开始相互顺序落子。\n"
		<< "•	判断胜负\n"
		<< "o	最先在棋盘横向、竖向、斜向形成连续的相同色五个棋子的一方为胜。\n"
		<< "o	黑棋禁手判负(Lose)，白棋无禁手。黑棋禁手包括“三、三”(Double Three)、“四、四”(Double Four)、“长连”(Overline)。\n"
		<< "o	如分不出胜负，则定为平局(Draw)。\n"
		<< "o	对局中中途退场(死机)判为负。\n"
		<< "o	五连与禁手同时形成，先五为胜。\n"
		<< "o	黑方禁手形成时，白方的程序应立即指出。若白方未发现或发现后未指明而继续应子，则不能判黑方负。\n"
		<< "o	每步计算机“思考”时间不得长于15秒。否则判负。\n";

}
//游戏是否结束？
bool chessRules::gameOver(chessBoard curBoard,int x,int y)
{
	
	//获取行和列
	int row = sizeof(curBoard.intBoard) / sizeof(curBoard.intBoard[0]);
	int col = sizeof(curBoard.intBoard[0]) / sizeof(curBoard.intBoard[0][0]);
	
	//检测各行是否有五个棋子
	int five = 0;
	for (int i = 0; i < row; i++) {
		//cout << "检测行是否有五个棋子five = " << five << endl;
		if (curBoard.intBoard[x][i] != 0)
			if (curBoard.intBoard[x][i] % 10 == curBoard.intBoard[x][y] % 10){
				five++;
				//cout << "检测各行是否有五个棋子five = "<< five << endl;
			}
			else
				five = 0;
		if (five >= 5) return true;

	}
	if (five >= 5) return true;
	else	five = 0;
	
	//检测列是否有五个
	for (int i = 0; i < col ; i++) {
		//cout << "检测列是否有五个棋子five = " << five << endl;
		if (curBoard.intBoard[i][y] != 0)
			if (curBoard.intBoard[i][y] % 10 == curBoard.intBoard[x][y] % 10) {
				five++;
				//cout << "检测各列是否有五个棋子five = " << five << endl;
			}
			else
				five=0;
		if (five >= 5) return true;
		
	}


	if (five >= 5) return true;
	else	five = 0;
	//检测 东南 是否有五个
	for (int i = x,j=y; i < row&&j<col && five < 5; i++,j++) {
		//cout << "检测 东南 是否有五个棋子five = " << five << endl;
		if (curBoard.intBoard[i][j] != 0)
			if (curBoard.intBoard[i][j] % 10 == curBoard.intBoard[x][y] % 10)
				five++;
			else
				break;
		else
			break;
	}
	//cout << "检测 东南 是否有五个棋子five = " << five << endl;
	if (five >= 5) return true;
	else five--;
	//检测 西北 是否有五个
	for (int i = x, j = y; i > 0 && j > 0 && five < 5; i--, j--) {
		//cout << "检测 西北 是否有五个棋子five = " << five << endl;
		if (curBoard.intBoard[i][j] != 0)
			if (curBoard.intBoard[i][j] % 10 == curBoard.intBoard[x][y] % 10)
				five++;
			else
				break;
		else
			break;
	}
	//cout << "检测 西北 是否有五个棋子five = " << five << endl;
	if (five >= 5) return true;
	else	five = 0;
	//检测 东北 是否有五个
	for (int i = x, j = y; i > 0 && j < col && five < 5; i--, j++) {
		//cout << "检测 东北是否有五个棋子five = " << five << endl;
		if (curBoard.intBoard[i][j] != 0)
			if (curBoard.intBoard[i][j] % 10 == curBoard.intBoard[x][y] % 10)
				five++;
			else
				break;
		else
			break;
	}
	//cout << "检测 东北是否有五个棋子five = " << five << endl;
	if (five == 5) return true;
	else five--;
	//检测 西南 是否有五个
	for (int i = x, j = y; i < row && j >0 && five < 5; i++, j--) {
		//cout << "检测 西南 是否有五个棋子five = " << five << endl;
		if (curBoard.intBoard[i][j] != 0)
			if (curBoard.intBoard[i][j] % 10 == curBoard.intBoard[x][y] % 10)
				five++;
			else
				break;
		else
			break;
	}
	//cout << "检测 西南 是否有五个棋子five = " << five << endl;
	if (five >= 5) return true;
	else	five = 0;
	//cout << "游戏继续！" << endl;

	return false;
}

chessRules::chessRules(chessBoard board)
{

	curBoard = board;
}

chessRules::chessRules()
{

}











