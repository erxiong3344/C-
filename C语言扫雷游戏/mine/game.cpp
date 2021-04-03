#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include "game.h"

//openr,openc��������򿪵��׵��к����к�
int openc = 0;
int openr = 0;
//�����СΪ(ROW+2)*(COL+2)��Ϊ�˽��Խ�����⣬ROW*COL���û���
//(ROW+2)*(COL+2)���ں�̨����
int mine[ROW + 2][COL + 2];
int score = 0;
IMAGE img[12];
//��ʼ����Ϸ
void initGame()
{
	srand((unsigned)time(NULL));
	//��ʼ������
	for (int i = 0; i < ROW + 2; i++)
	{
		for (int j = 0; j < COL + 2; j++)
		{
			mine[i][j] = 0;
		}
	}
	//����һ������ı߽磬���⣬��������Ȧ��ֵΪ1000��ֻҪ�������ּ���
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
	//���ף�-1��ʾ��,�����ʮ����
	for (int i = 0; i < MAX_MINE;)
	{
		int row = rand() % 10 + 1;
		int col = rand() % 10 + 1;
		//û�����ף��������ܼ���ʮ����
		if (mine[row][col] == 0)
		{
			mine[row][col] = -1;
			i++;
		}
	}
	//����Ϊ���ģ��Ź��������ݼ�һ���׳��⣬����0-8������
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
	//���ܸ��ӣ��������ֺ���
	for (int i = 0; i < ROW + 2; i++)
	{
		for (int j = 0; j < COL + 2; j++)
		{
			mine[i][j] += 20;
		}
	}
	//����ͼƬ
	for (int i = 0; i < 12; i++)
	{
		char temp[30] = "";
		sprintf(temp, "./image/%d.jpg", i);
		loadimage(&img[i], temp, SIZE, SIZE);
	}

}


//�����ƣ�������������򿪸��ӣ��������Ҽ�������С����
void mouseControl()
{
	//�ж��Ƿ��������Ϣ
	if (MouseHit)
	{
		struct MOUSEMSG msg = GetMouseMsg();
		int col = msg.x / SIZE + 1;
		int row = (msg.y - 100) / SIZE + 1; //�������ת��Ϊ��������
		//�ж������Ϣ����
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			//����Ը��ӽ�����һ�μ��ܣ���򿪸���
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
			//����Ը��ӽ�����һ�μ��ܣ������С���죬���μ���
			if (mine[row][col] >= 19 && mine[row][col] <= 28)
			{
				mine[row][col] += 20;
			}
			//����Ѿ�������С���죬�������Ҽ������ȥС����
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


//�򿪿հ׸��ӣ��հ׸�����Χ���׸��ӵ������ݹ�ʵ��
void openNull(int row, int col)
{
	if (mine[row][col] == 0)
	{
		for (int i = row - 1; i <= row + 1; i++)
		{
			for (int j = col - 1; j <= col + 1; j++)
			{
				//����һ�μ��ܸ���ը��
				if (mine[i][j] != 19)
				{
					if (mine[i][j] >= 20 && mine[i][j] <= 28)
					{
						openr = i;
						openc = j;
						mine[i][j] -= 20;
						score += 1;
						//�ݹ�
						openNull(i, j);
					}
				}
			}
		}
	}
}


//��ӡ���鵽�����ն�
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


//����ɨ�׵�ͼ
void drawGraph()
{
	char myscore[10] = "0";
	_itoa(score, myscore, 10);
	settextcolor(WHITE);
	settextstyle(50, 0, "����");
	outtextxy(COL*SIZE / 2 - SIZE / 2, 25, myscore);
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			int x = j - 1;
			int y = i - 1;
			//���Ƶ���
			if (mine[i][j] == -1)
			{
				putimage(x*SIZE, y*SIZE + 100, &img[9]);
			}
			//��������0-8
			else if (mine[i][j] >= 0 && mine[i][j] <= 8)
			{
				putimage(x*SIZE, y*SIZE + 100, &img[mine[i][j]]);
			}
			//���Ƹ�����
			else if (mine[i][j] >= 19 && mine[i][j] <= 28)
			{
				putimage(x*SIZE, y*SIZE + 100, &img[10]);
			}
			//����С����
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
		printf("��Ϸ����");
		return -1;

	}
	if (score == ROW * COL - MAX_MINE)
	{
		printf("��Ϸ����");
		return 1;
	}
}