//1.设置扫雷地图
//·用一个二维数组表示扫雷地图
//·初始化二维数组
//·埋雷，-1表示雷,随机埋十个雷
//·以雷为中心，九宫格中数据加一，雷除外，生成0-8的数字
//2.导入图片，绘制扫雷地图，数组中的元素映射为相应的图片
//3.加密格子，覆盖数字和雷
//4.鼠标控制，点击鼠标左键，打开格子，点击鼠标右键，插上小红旗
//·判断是否有鼠标消息
//·从鼠标消息队列中获取鼠标消息
//·鼠标坐标转化为数组行号与列号
//·判断鼠标消息类型，点击鼠标左键，打开格子，点击鼠标右键，插上小红旗
//5.打开空白格子，空白格子周围非雷格子弹开，递归实现
//6.统计分数，判断输赢，score用来计算分数

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
	//游戏主循环为死循环
	while (1)
	{
		mouseControl();
		flag = isWin();
		drawGraph();
		FlushBatchDraw();
		//-1表示点到雷游戏结束
		if (flag == -1)
			break;
		//1表示排雷成功结束游戏
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
			int isok = MessageBox(hnd, "是否重玩！", "点到雷了游戏结束~", MB_YESNO);
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
			int isok = MessageBox(hnd,"恭喜你，过关成功~是否重玩~", "YOU WIN!", MB_YESNO);
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