/*


*/

#include "下棋.h" 
#include "棋盘.h" 
#include <string>
#include <time.h>
#include <stdio.h>
#include <sstream>template <typename T>



void chessBoard::initialBoard() {

	//获取数组长度
	int lines = sizeof(intBoard) / sizeof(intBoard[0][0]);
	int row = sizeof(intBoard) / sizeof(intBoard[0]);
	int column = lines / row;

	
	//初始化棋盘

	const string seed = "ABCDEFGHIJKLMNO";

	int sn = 0;	//方便行遍历
	int sb = 15;	//方便列遍历用
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < column; j++) {
			//棋盘下标
			if (i == 15&&j>0) {
				stringstream sSseed;
				sSseed << "  " << seed[sn] ;//补空格

				strBoard[i][j] = sSseed.str();
				sn++;
				//cout << " "<<seed[sn++]<<" ";
			}
			//棋盘上标
			if (j == 0 ) {
				
				//int 转string
				std::stringstream sbTemp;
				sbTemp << setw(2) << setfill('0') << sb;//共二位 空位补零

				strBoard[i][j] = sbTemp.str();
				sb--;
				//cout << setw(2) << setfill('0')<< sb--;

			}
			//第一行线
			if (i == 0 && j > 1 && j < 15) {
				strBoard[i][j] = "─┬─";
				//cout << " ┬ ";
			}
			//最后一行线
			if (i == 14 && j > 1 && j < 15) {
				strBoard[i][j] = "─┴─";
				//cout << " ┴ ";
			}
			//第二列线
			if (j == 1 && i > 0 && i < 14) {
				strBoard[i][j] = "  ├─";
				//cout << " ├ ";
			}
			//最后一列线
			if (j == 15 && i > 0 && i < 14) {
				strBoard[i][j] = "─┤  ";
				//cout << " ┤ ";
			}
			//中间十字区
			if (i > 0 && i < 14 && j>1 && j < 15) {
				strBoard[i][j] = "─┼─";
				//cout << " ┼ ";
			}
			//左上角
			if (i == 0 && j == 1) {
				strBoard[i][j] = "  ┌─";
				//cout << " ┌ ";
			}
			//右上角
			if (i == 0 && j == 15) {
				strBoard[i][j] = "─┐  ";
				//cout << " ┐ ";
			}
			//左下角
			if (i == 14 && j == 1) {
				strBoard[i][j] = "  └─";
				//cout << " └ ";
			}
			//右下角
			if (i == 14 && j == 15) {
				strBoard[i][j] = "─┘  ";
				//cout << " ┘ ";
			}
			//把int数组初始化
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

	//获取数组长度
	int lines = sizeof(strBoard) / sizeof(strBoard[0][0]);
	int row = sizeof(strBoard) / sizeof(strBoard[0]);
	int column = lines / row;

	//中间行填充
	string fill = "    │  │  │  │  │  │  │  │  │  │  │  │  │  │  │";
	//清屏
	system("cls");
	//打印string棋盘
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