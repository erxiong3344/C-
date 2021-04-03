#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include "game.h"

//openr,openc保存最近打开的雷的行号与列号
int openc = 0;
int openr = 0;
//数组大小为(ROW+2)*(COL+2)是为了解决越界问题，ROW*COL给用户看
//(ROW+2)*(COL+2)用于后台管理
int mine[ROW + 2][COL + 2];
int score = 0;
IMAGE img[12];
//初始化游戏
void initGame()
{
	srand((unsigned)time(NULL));
	//初始化数组
	for (int i = 0; i < ROW + 2; i++)
	{
		for (int j = 0; j < COL + 2; j++)
		{
			mine[i][j] = 0;
		}
	}
	//处理一下数组的边界，随意，本人最外圈赋值为1000，只要方便区分即可
	for (int j = 0; j < ROW + 2; j++)
	{
		mine[0][j] = 1000;
		mine[ROW + 1][j] = 1000;
	}
	for (int i = 0; i < ROW + 2; i++)
	{
		mine[i][0] = 1000;
		mine[i][COL + 1] = 1000;
	}
	//埋雷，-1表示雷,随机埋十个雷
	for (int i = 0; i < MAX_MINE;)
	{
		int row = rand() % 10 + 1;
		int col = rand() % 10 + 1;
		//没有埋雷，则埋雷总计埋十个雷
		if (mine[row][col] == 0)
		{
			mine[row][col] = -1;
			i++;
		}
	}
	//以雷为中心，九宫格中数据加一，雷除外，生成0-8的数字
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			if (mine[i][j] == -1)
			{
				for (int m = i - 1; m <= i + 1; m++)
				{
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (mine[m][n] != -1)
						{
							mine[m][n]++;
						}
					}
				}
			}
		}
	}
	//加密格子，覆盖数字和雷
	for (int i = 0; i < ROW + 2; i++)
	{
		for (int j = 0; j < COL + 2; j++)
		{
			mine[i][j] += 20;
		}
	}
	//导入图片
	for (int i = 0; i < 12; i++)
	{
		char temp[30] = "";
		sprintf(temp, "./image/%d.jpg", i);
		loadimage(&img[i], temp, SIZE, SIZE);
	}

}


//鼠标控制，点击鼠标左键，打开格子，点击鼠标右键，插上小红旗
void mouseControl()
{
	//判断是否有鼠标消息
	if (MouseHit)
	{
		struct MOUSEMSG msg = GetMouseMsg();
		int col = msg.x / SIZE + 1;
		int row = (msg.y - 100) / SIZE + 1; //鼠标坐标转化为数组坐标
		//判断鼠标消息类型
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			//如果对格子进行了一次加密，则打开格子
			if (mine[row][col] >= 19 && mine[row][col] <= 28)
			{
				openr = row;
				openc = col;
				mine[row][col] -= 20;
				score += 1;
				openNull(row, col);
			}
			break;
		case WM_RBUTTONDOWN:
			//如果对格子进行了一次加密，则插上小红旗，二次加密
			if (mine[row][col] >= 19 && mine[row][col] <= 28)
			{
				mine[row][col] += 20;
			}
			//如果已经插上了小红旗，点击鼠标右键，则拔去小红旗
			else if (mine[row][col] >= 39 && mine[row][col] <= 48)
			{
				mine[row][col] -= 20;
			}
			break;
		default:
			break;
		}
	}
}


//打开空白格子，空白格子周围非雷格子弹开，递归实现
void openNull(int row, int col)
{
	if (mine[row][col] == 0)
	{
		for (int i = row - 1; i <= row + 1; i++)
		{
			for (int j = col - 1; j <= col + 1; j++)
			{
				//非雷一次加密格子炸开
				if (mine[i][j] != 19)
				{
					if (mine[i][j] >= 20 && mine[i][j] <= 28)
					{
						openr = i;
						openc = j;
						mine[i][j] -= 20;
						score += 1;
						//递归
						openNull(i, j);
					}
				}
			}
		}
	}
}


//打印数组到黑屏终端
void show()
{
	for (int i = 0; i < ROW + 2; i++)
	{
		for (int j = 0; j < COL + 2; j++)
		{
			printf("%5d", mine[i][j]);
		}
		printf("\n");
	}
}


//绘制扫雷地图
void drawGraph()
{
	char myscore[10] = "0";
	_itoa(score, myscore, 10);
	settextcolor(WHITE);
	settextstyle(50, 0, "楷体");
	outtextxy(COL*SIZE / 2 - SIZE / 2, 25, myscore);
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			int x = j - 1;
			int y = i - 1;
			//绘制地雷
			if (mine[i][j] == -1)
			{
				putimage(x*SIZE, y*SIZE + 100, &img[9]);
			}
			//绘制数字0-8
			else if (mine[i][j] >= 0 && mine[i][j] <= 8)
			{
				putimage(x*SIZE, y*SIZE + 100, &img[mine[i][j]]);
			}
			//绘制覆盖物
			else if (mine[i][j] >= 19 && mine[i][j] <= 28)
			{
				putimage(x*SIZE, y*SIZE + 100, &img[10]);
			}
			//绘制小红旗
			else if (mine[i][j] >= 39 && mine[i][j] <= 48)
			{
				putimage(x*SIZE, y*SIZE + 100, &img[11]);
			}
		}
	}
}


int isWin()
{
	if (mine[openr][openc] == -1)
	{
		score = score - 1;
		printf("游戏结束");
		return -1;

	}
	if (score == ROW * COL - MAX_MINE)
	{
		printf("游戏结束");
		return 1;
	}
}