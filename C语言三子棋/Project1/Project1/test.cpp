//��Ϸ������ҵ�����ΪѼ�棬���Ե�����Ϊƻ��
//����������£����ֵ������£��Դ�����
//1.��������
//������һ����ά����
//����ʼ����ά���飬��ֵΪ��
//����ӡ���鵽�����ն�
//2.�������̣�����ͼƬ���������ά������ͼƬ֮���һһ��Ӧ��ϵ
//3.������壬Ȼ���������
//4.�ж���Ӯ
//�����Ӯ
//������Ӯ
//��ƽ��
//������
//���ؼ�����Խ��ߡ��ҶԽ��ߡ��С��С��Ƿ���
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
		printf("���Ӯ\n");
		//MessageBox (���, ��ʾ����,����,MB_OK) ;
				//�������ΪNULL����ʾ��ǰ����ľ��.
				//	���һ����������ʾ����ʾ���еİ�ť���ͣ�
				//	MB_ABORTRETRYIGNORE
				//	MB_OKCANCEL
				//	MB_RETRYCANCEL
				//	MB_YESNO
				//	MB_YESNOCANCEL
				//	MB_OK
				//	��ѡ��һ��־��
		HWND hnd = GetHWnd();
		int isok = MessageBox(hnd, "���Ӯ�ˣ��Ƿ�����", "��Ϸ����", MB_YESNO);
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
		printf("����Ӯ\n");
		HWND hnd = GetHWnd();
		int isok = MessageBox(hnd, "����Ӯ�ˣ��Ƿ�����", "��Ϸ����", MB_YESNO);
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
		printf("ƽ��\n");
		HWND hnd = GetHWnd();
		int isok = MessageBox(hnd, "ƽ���ˣ��Ƿ�����", "��Ϸ����", MB_YESNO);
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
