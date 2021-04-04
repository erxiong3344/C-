//游戏规则：玩家的棋子为鸭梨，电脑的棋子为苹果
//首轮玩家先下，次轮电脑先下，以此类推
//1.设置棋盘
//·定义一个二维数组
//·初始化二维数组，赋值为零
//·打印数组到黑屏终端
//2.绘制棋盘，导入图片，建立起二维数组与图片之间的一一对应关系
//3.玩家下棋，然后电脑下棋
//4.判断输赢
//·玩家赢
//·电脑赢
//·平局
//·继续
//·关键：左对角线、右对角线、行、列、是否满
#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include "game.h"
void judgeGame(int board[ROW][COL], int row, int  col)
{
	int myflag = 0;
	myflag = isWin(board, ROW, COL);
	if (myflag == 1)
	{
		printf("玩家赢\n");
		//MessageBox (句柄, 显示内容,标题,MB_OK) ;
				//句柄可以为NULL，表示当前窗体的句柄.
				//	最后一个参数是显示在提示框中的按钮类型：
				//	MB_ABORTRETRYIGNORE
				//	MB_OKCANCEL
				//	MB_RETRYCANCEL
				//	MB_YESNO
				//	MB_YESNOCANCEL
				//	MB_OK
				//	可选任一标志。
		HWND hnd = GetHWnd();
		int isok = MessageBox(hnd, "玩家赢了，是否重玩", "游戏结束", MB_YESNO);
		if (isok == IDYES)
		{
			
			initBoard(board, ROW, COL);
		}
		else if (isok == IDNO)
		{
			exit(0);
		}
	}
	else if (myflag == -1)
	{
		printf("电脑赢\n");
		HWND hnd = GetHWnd();
		int isok = MessageBox(hnd, "电脑赢了，是否重玩", "游戏结束", MB_YESNO);
		if (isok == IDYES)
		{
			
			initBoard(board, ROW, COL);
		}
		else if (isok == IDNO)
		{
			exit(0);
		}
	}
	else if (myflag == 100)
	{
		printf("平局\n");
		HWND hnd = GetHWnd();
		int isok = MessageBox(hnd, "平局了，是否重玩", "游戏结束", MB_YESNO);
		if (isok == IDYES)
		{
			myflag = 0;
			initBoard(board, ROW, COL);
		}
		else if (isok == IDNO)
		{
			exit(0);
		}
	}
}
void test()
{
	
	int board[ROW][COL];
	initBoard(board, ROW, COL);
	initgraph(COL*SIZE, ROW*SIZE, SHOWCONSOLE);
	BeginBatchDraw();
	while (1)
	{
		playerMove(board, ROW, COL);
		drawGraph(board, ROW, COL);
		FlushBatchDraw();
		judgeGame(board, ROW, COL);
		computerMove(board, ROW, COL);
		drawGraph(board, ROW, COL);
		FlushBatchDraw();
		judgeGame(board, ROW, COL);
			
	}
	EndBatchDraw();
	getchar();
	closegraph();

}
int main()
{
	test();
	
	return 0;
}
