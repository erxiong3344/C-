//1.创建通讯录，使用结构体数组
//2.定义一个整形变量size，记录当前通讯录中的元素个数
//3.为了方便传递参数，对结构体数组和size进行封装，定义一个结构体变量
//struct Contact
//4.进行增删改查、排序函数的编写

#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "contact.h"
void menu()
{

	printf("****************************\n");
	printf("****************************\n");
	printf("**  1.add     2.delete    **\n");
	printf("**  3.modify  4.search    **\n");
	printf("**  5.show    6.sort      **\n");
	printf("**    0.exit              **\n");
	printf("****************************\n");
	printf("****************************\n");
	printf("请输入您要执行的操作:>");

}


int main()
{
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出程序\n");
			break;
		default:
			printf("请输入0-6之间的数字\n");
			break;
		}
	} while (input);
}