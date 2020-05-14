/*

*/

#include "下棋.h";
#include "棋盘.h";
#include "开始.h";
#include "规则.h";
#include "电脑.h";
#include <time.h>
#include <stdio.h>
#include<iostream>
#include <sstream>template <typename T>



//当前下黑子
void playChess::BlackGo(int x, int y)
{
	//cout << "当前下黑子!" << endl;
	//拿出棋盘中的点
	string pawn=cheBoard.strBoard[x][y];
	
	//加入刚下的棋子:
	pawn.replace(pawn.length()-4, pawn.length() - 2, "▲");

	//cout << "pawn length:" << pawn.length() << endl;
	//刚下的黑棋，将数字棋盘赋值为11
	cheBoard.intBoard[x][y] = 11;
	//修改棋盘
	cheBoard.strBoard[x][y] = pawn;
	//打印棋盘
	cheBoard.showBoard();
	//传值给当前位置赋值，用于落实棋子改变图形

	//cout << "BlackGo x:" << x << "y:" << y << endl;
	//cout << "BlackGo beforex:" << beforeX << "beforey:" << beforeY << endl;
	//*PbeforeX = x;
	//*PbeforeY = y;
	//cout << "BlackGo *PbeforeX:" << *PbeforeX << " *PbeforeY:" << *PbeforeY << endl;
	beforeX = x;
	beforeY = y;
	//cout << "BlackGo beforex:" << beforeX << "beforey:" << beforeY << endl;
}

//将之前刚下的黑棋改为落实的黑棋
void playChess::BlackDown(int x, int y)
{
	//cout << "黑棋落!" << endl;
	//cout << "黑棋落! x:" << x <<"y:"<<y<< endl;
	if (cheBoard.intBoard[x][y] == 11) {
		
		//拿出棋盘中的点
		string pawn = cheBoard.strBoard[x][y];
		//加入刚下的黑棋
		//pawnst = pawnst[0] + chePawn.BlackPawn + pawnst[2];
		//pawnst = pawnst[0] +"" + pawnst[2];

		//cout << "黑棋落! pawnst:" << pawn << endl;
		//cout << "黑棋落! pawnst length:" << pawn.length() << endl;

		pawn.replace(pawn.length() - 2, pawn.length() - 0, "●");

		//cout << "黑棋落! pawnst:" << pawn << endl;
		//修改棋盘
		cheBoard.strBoard[x][y] = pawn;
		//打印棋盘
		cheBoard.showBoard();
		//黑棋，将数字棋盘赋值为1
		cheBoard.intBoard[x][y] = 1;
	}
}


//当前下白子
void playChess::WhiteGo(int x, int y)
{
	//cout << "当前下白子!" << endl;
	//拿出棋盘中的点
	string pawnst = cheBoard.strBoard[x][y];
	//加入刚下的棋子
	//pawnst = pawnst[0] + chePawn.WhiteJustDown + pawnst[2];

	//cout << "当前下白子! pawnst:" << pawnst << endl;
	//cout << "当前下白子! pawnst length:" << pawnst.length() << endl;


	//通过字符串替换，使棋盘加上棋子
	pawnst.replace(pawnst.length()-4, pawnst.length() - 2, "△");

	//cout << "当前下白子! pawnst:" << pawnst << endl;
	//刚下的白棋，将数字棋盘赋值为22
	cheBoard.intBoard[x][y] = 22;
	//修改棋盘
	cheBoard.strBoard[x][y] = pawnst;
	//打印棋盘
	cheBoard.showBoard();
	//传值给当前位置赋值，用于落实棋子改变图形
	beforeX = x;
	beforeY = y;

}

//将之前刚下的白棋改为落实的白棋
void playChess::WhiteDown(int x, int y)
{
	//cout << "白棋落！"  << endl;
	//cout << "WhiteDown x:" << x << "y:" << y << endl;
	//cout << "WhiteDown cheBoard.intBoard:" << cheBoard.intBoard[x][y] << endl;

	if (cheBoard.intBoard[x][y] == 22) {

		
		//拿出棋盘中的点
		string pawnst = cheBoard.strBoard[x][y];

		//cout << "WhiteDown pawnst:" << pawnst << endl;
		//cout << "WhiteDown pawnst length:" << pawnst.length() << endl;
		//通过字符串替换，使棋盘加上棋子
		pawnst.replace(pawnst.length() - 2, pawnst.length() - 0, "○");
		//修改棋盘
		cheBoard.strBoard[x][y] = pawnst;
		//打印棋盘
		cheBoard.showBoard();
		//白棋，将数字棋盘赋值为2
		cheBoard.intBoard[x][y] = 2;
	}
}

//电脑下棋
void playChess::PlayWithComputer(chessBoard board, int beforeX, int beforeY)
{
	
	Position whereDownPawn = computerPlay.cptPlay(board, beforeX, beforeY);
	//cout << "电脑下棋whereDownPawn.x=" << whereDownPawn.x << endl;
	//cout << "电脑下棋whereDownPawn.y=" << whereDownPawn.y << endl;
	//cout << "电脑下棋whereDownPawn.pow=" << whereDownPawn.pow << endl;

	//记录下棋位置
	whereDownPawn.pow = 0;//清除原来的权重值！
	computerPlay.All_Positions[WhosTurn / 2] = whereDownPawn;
	computerPlay.Turns = WhosTurn / 2;
	//将棋子落入棋盘
	PawnOnBoard(whereDownPawn.x, whereDownPawn.y);

}

//下棋键入
void playChess::ChessInput()
{
	//cheRules.showRules;
	
	do {
		string sx, sy;
		cout << "请输入位置" << endl;
		cin >> sx >> sy;

		Prejuge(sx, sy);	//判断位置是否合理
		if (cheRules.Result)//游戏是否结束
			break;
		if (WhosTurn % 2 == 0)
			PlayWithComputer(cheBoard,beforeX,beforeY);	//电脑下白棋
	} while (!cheRules.Result);
	//system("cls");
	cout << "！！！！！！！！！游戏结束！！！！！！！！！！:" << cheRules.Result << endl;
}

//判断输入位置是否合理
void playChess::Prejuge(string x, string y)
 {

	int ix=atoi(x.c_str());	//string转int
	int iy=0;
	cout << "ix=" <<ix<< endl;

	string letter = "ABCDEFGHIJKLMNO";

	cout << "判断输入位置是否合理:" << endl;
	bool flag = false;
	while (1) {
		if (ix >= 1 && ix <= ChessBoardLong - 1 && y.length()==1) {

			//字母是否合理
			for (int i = 0; i < 16; i++) {
				if (y[0]== letter[i]) {
					iy = i;
					
					flag = true;
					break;//for
				}
			}
			//如果这个位置已经下过棋子了
			iy++;//对齐
			ix = ChessBoardLength - 1 - ix;
			if (cheBoard.intBoard[ix][iy] != 0) {

				cout << "如果这个位置已经下过棋子了:" << cheBoard.intBoard[ix][iy] << endl;
				flag = false;
			}
				

			if (flag == false) {
				cout << "请输入正确位置" << endl;
				cin >> x >> y;
				ix = atoi(x.c_str());
				cout << "ix=" << ix << endl;
			}
			else 
				break;	//while
		}
		else {
			cout << "请重新输入位置" << endl;
			cin >> x >> y;
			ix = atoi(x.c_str());
			cout << "ix=" << ix << endl;
		}
	}//while

			cout << "在 " <<x<<" , "<<y<<" 处下棋"<< endl;
			//将棋子落入棋盘
			PawnOnBoard(ix,iy);

}


//下棋
void playChess::PawnOnBoard(int x,int y)
{

	//cout << "x=" << x << "  y=" << y << endl;
	//cout << "WhosTurn=" << WhosTurn << " 回合"  << endl;

	//下黑棋还是白棋？
	if (WhosTurn %2== 1) {

		//白棋落
		WhiteDown(beforeX,beforeY);
		
		//黑棋下
		BlackGo(x,y);

		//判断输赢
		cheRules.Result = cheRules.gameOver(cheBoard, x, y);
		if (cheRules.Result) {
			cout << "黑棋赢了" << endl;
			system("pause");
		}
		//下一回合
		WhosTurn++;
	}
	else {
		
		//黑棋落
		BlackDown(beforeX, beforeY);
		//白棋下
		WhiteGo(x,y);
		//判断输赢
		cheRules.Result = cheRules.gameOver(cheBoard, x, y);
		if (cheRules.Result) {
			cout << "白棋赢了" << endl;
			system("pause");
		}
			
		WhosTurn++;
	}

}

//构造
playChess::playChess(chessBoard board)
{	
	//赋值棋盘
	cheBoard = board;
	//初始化回合
	WhosTurn = 1;
	//初始化上一步
	beforeX = 0; beforeY = 0;
	//初始化比赛结果
	cheRules = chessRules(board);
	//初始化电脑
	computerPlay = chessComputer(board);

	//开始下棋键入
	ChessInput();
	
}
