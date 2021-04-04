#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include "game.h"
IMAGE img[3];
int flag = 0;//�����־λ��flag=1,���Բ�����flag=0�����Եȴ�
//��ʼ������
void initBoard(int board[ROW][COL], int row, int  col)
{
	srand((unsigned)time(NULL));
	//��ʼ������
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = 0;
		}
	}
	//����ͼƬ
	//����ͼƬ
	for (int i = 0; i < 3; i++)
	{
		char temp[30] = "";
		sprintf(temp, "./image/%d.jpg", i);
		loadimage(&img[i], temp, SIZE, SIZE);
	}	
}


//��ӡ�������ն�
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


//��Ҳ���
void playerMove(int board[ROW][COL], int row, int  col)
{
	//����Ƿ��������Ϣ
	if (MouseHit)
	{
		//�������Ϣ�����л�ȡ�����Ϣ
		struct MOUSEMSG msg = GetMouseMsg();
		//�������ת��Ϊ�����к����к�
		int c=msg.x/SIZE;
		int r = msg.y / SIZE;
		//�ж������Ϣ����
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
				//������������е�Ԫ�ر�Ϊ1
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


//���Բ���
void computerMove(int board[ROW][COL], int row, int  col)
{
	if (flag == 1)
	{
		while (1)
		{
			int r = rand() % ROW;
			int c = rand() % COL;
			//�������壬�����е�Ԫ��Ϊ-1
			if (board[r][c] == 0)
			{
				board[r][c] = -1;
				break;
			}
		}
		flag = 0;
	}
}


//��������
void drawGraph(int board[ROW][COL], int row, int  col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//Ĭ��Ϊ�հ�
			if (board[i][j] == 0)
			{
				int x = j * SIZE;
				int y = i * SIZE;
				putimage(x, y, &img[0]);
			}
			//��ҵ�����ΪѼ��
			else if (board[i][j] == 1)
			{
				int x = j * SIZE;
				int y = i * SIZE;
				putimage(x, y, &img[1]);
			}
			//���Ե�����Ϊƻ��
			else if (board[i][j] == -1)
			{
				int x = j * SIZE;
				int y = i * SIZE;
				putimage(x, y, &img[2]);
			}
		}
	}
}


//�ж�������Ԫ���Ƿ���ͬ�Ҳ�Ϊ0������ǣ��򷵻�arr[0]�����򣬷���0
int judgeArr(int* arr)
{
	for (int i = 1; i < COL; i++)
	{
		if (arr[i] != arr[0])
			return 0;
	}

	return arr[0];

}


//�ж��Ƿ�����
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

//�ж���Ϸ��Ӯ
int isWin(int board[ROW][COL], int row, int  col)
{
	int res = 0;
	//�ж���
	for (int i = 0; i < ROW; i++)
	{
		res = judgeArr(board[i]);
		if (res!=0)
		{
			return res;
		}
	}
	//�ж���
	int temp[ROW] = { 0 };
	for (int j = 0; j < COL; j++)
	{
		for (int i = 0; i < ROW; i++)
		{
			temp[i] = board[i][j];//ȡ��������ĳһ�е�Ԫ�ظ�ֵ��temp����

		}
		res = judgeArr(temp);
		if (res != 0)
		{
			return res;
		}
	}
	//�ж���Խ���
	for (int i = 0; i < ROW; i++)
	{
		temp[i] = board[i][i];//ȡ������������ߵ�Ԫ�ظ�ֵ��temp����
	}
	res = judgeArr(temp);
	if (res != 0)
	{
		return res;
	}
	//�ж��ҶԽ���
	for (int i = 0; i < ROW; i++)
	{
		temp[i] = board[i][ROW - i - 1];//ȡ���������ҽ��ߵ�Ԫ�ظ�ֵ��temp����
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