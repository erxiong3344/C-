//1.����ͨѶ¼��ʹ�ýṹ������
//2.����һ�����α���size����¼��ǰͨѶ¼�е�Ԫ�ظ���
//3.Ϊ�˷��㴫�ݲ������Խṹ�������size���з�װ������һ���ṹ�����
//struct Contact
//4.������ɾ�Ĳ顢�������ı�д

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
	printf("��������Ҫִ�еĲ���:>");

}


int main()
{
	//����ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
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
			printf("�˳�����\n");
			break;
		default:
			printf("������0-6֮�������\n");
			break;
		}
	} while (input);
}