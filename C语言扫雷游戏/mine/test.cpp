//1.����ɨ�׵�ͼ
//����һ����ά�����ʾɨ�׵�ͼ
//����ʼ����ά����
//�����ף�-1��ʾ��,�����ʮ����
//������Ϊ���ģ��Ź��������ݼ�һ���׳��⣬����0-8������
//2.����ͼƬ������ɨ�׵�ͼ�������е�Ԫ��ӳ��Ϊ��Ӧ��ͼƬ
//3.���ܸ��ӣ��������ֺ���
//4.�����ƣ�������������򿪸��ӣ��������Ҽ�������С����
//���ж��Ƿ��������Ϣ
//���������Ϣ�����л�ȡ�����Ϣ
//���������ת��Ϊ�����к����к�
//���ж������Ϣ���ͣ�������������򿪸��ӣ��������Ҽ�������С����
//5.�򿪿հ׸��ӣ��հ׸�����Χ���׸��ӵ������ݹ�ʵ��
//6.ͳ�Ʒ������ж���Ӯ��score�����������

#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include "game.h"
#include<windows.h>
extern int score;
int test()
{
	int flag = 0;
	initGame();
	show();
	initgraph(COL*SIZE, ROW*SIZE + 100, SHOWCONSOLE);
	BeginBatchDraw();
	//��Ϸ��ѭ��Ϊ��ѭ��
	while (1)
	{
		mouseControl();
		flag = isWin();
		drawGraph();
		FlushBatchDraw();
		//-1��ʾ�㵽����Ϸ����
		if (flag == -1)
			break;
		//1��ʾ���׳ɹ�������Ϸ
		else if (flag == 1)
			break;
	}
	EndBatchDraw();
	return flag;
}


int main()
{
	int myflag = 0;
	
	while (1)
	{
		if (myflag == 0)
		{
			myflag = test();
		}
		else if (myflag == -1)
		{
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
			int isok = MessageBox(hnd, "�Ƿ����棡", "�㵽������Ϸ����~", MB_YESNO);
			if (isok == IDYES)
			{
				
				score = 0;
				myflag=test();
			}
			else if (isok == IDNO)
			{
				
				break;
			}
		}
		else if (myflag == 1)
		{
			HWND hnd = GetHWnd();
			int isok = MessageBox(hnd,"��ϲ�㣬���سɹ�~�Ƿ�����~", "YOU WIN!", MB_YESNO);
			if (isok == IDYES)
			{
				score = 0;
				myflag = test();
			}
			else {
				break;
			}
		}

	}
	closegraph();
	return 0;
}