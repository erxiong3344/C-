#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include "game.h"
IMAGE img[3];
int flag = 0;//定义标志位，flag=1,电脑操作，flag=0，电脑等待
//初始化棋盘
void initBoard(int board[ROW][COL], int row, int  col)
{
	srand((unsigned)time(NULL));
	//初始化数组
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = 0;
		}
	}
	//导入图片
	//导入图片
	for (int i = 0; i < 3; i++)
	{
		char temp[30] = "";
		sprintf(temp, "./image/%d.jpg", i);
		loadimage(&img[i], temp, SIZE, SIZE);
	}	
}


//打印到黑屏终端
void show(int board[ROW][COL], int row, int  col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-4d", board[i][j]);
		}
		putchar('\n');
	}
}


//玩家操作
void playerMove(int board[ROW][COL], int row, int  col)
{
	//检测是否有鼠标消息
	if (MouseHit)
	{
		//从鼠标消息队列中获取鼠标消息
		struct MOUSEMSG msg = GetMouseMsg();
		//鼠标坐标转化为数组行号与列号
		int c=msg.x/SIZE;
		int r = msg.y / SIZE;
		//判断鼠标消息类型
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
				//玩家下棋数组中的元素变为1
		{
			if (board[r][c] == 0 && r >= 0 && r < ROW&&c >= 0 && c <= COL)
			{
				board[r][c] = 1;
				flag = 1;
			}
			
			
			break;
		}
		default:
			break;
		}
	}
}


//电脑操作
void computerMove(int board[ROW][COL], int row, int  col)
{
	if (flag == 1)
	{
		while (1)
		{
			int r = rand() % ROW;
			int c = rand() % COL;
			//电脑下棋，数组中的元素为-1
			if (board[r][c] == 0)
			{
				board[r][c] = -1;
				break;
			}
		}
		flag = 0;
	}
}


//绘制棋盘
void drawGraph(int board[ROW][COL], int row, int  col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//默认为空白
			if (board[i][j] == 0)
			{
				int x = j * SIZE;
				int y = i * SIZE;
				putimage(x, y, &img[0]);
			}
			//玩家的棋子为鸭梨
			else if (board[i][j] == 1)
			{
				int x = j * SIZE;
				int y = i * SIZE;
				putimage(x, y, &img[1]);
			}
			//电脑的棋子为苹果
			else if (board[i][j] == -1)
			{
				int x = j * SIZE;
				int y = i * SIZE;
				putimage(x, y, &img[2]);
			}
		}
	}
}


//判断数组中元素是否相同且不为0，如果是，则返回arr[0]，否则，返回0
int judgeArr(int* arr)
{
	for (int i = 1; i < COL; i++)
	{
		if (arr[i] != arr[0])
			return 0;
	}

	return arr[0];

}


//判断是否满了
int isFull(int board[ROW][COL], int row, int  col)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

//判断游戏输赢
int isWin(int board[ROW][COL], int row, int  col)
{
	int res = 0;
	//判断行
	for (int i = 0; i < ROW; i++)
	{
		res = judgeArr(board[i]);
		if (res!=0)
		{
			return res;
		}
	}
	//判断列
	int temp[ROW] = { 0 };
	for (int j = 0; j < COL; j++)
	{
		for (int i = 0; i < ROW; i++)
		{
			temp[i] = board[i][j];//取出数组中某一列的元素赋值给temp数组

		}
		res = judgeArr(temp);
		if (res != 0)
		{
			return res;
		}
	}
	//判断左对角线
	for (int i = 0; i < ROW; i++)
	{
		temp[i] = board[i][i];//取出数组中左角线的元素赋值给temp数组
	}
	res = judgeArr(temp);
	if (res != 0)
	{
		return res;
	}
	//判断右对角线
	for (int i = 0; i < ROW; i++)
	{
		temp[i] = board[i][ROW - i - 1];//取出数组中右角线的元素赋值给temp数组
	}
	res = judgeArr(temp);
	if (res != 0)
	{
		return res;
	}
	if (isFull(board, ROW, COL))
	{
		return 100;
	}
	return 0;
}