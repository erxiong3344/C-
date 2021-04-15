#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<memory.h>
#include<string.h>
#include "contact.h"


static int  FindByName(struct Contact* ps, char* name)
{
	int pos = 0;
	for (pos = 0; pos < ps->size; pos++)
	{
		if (strcmp(ps->data[pos].name, name) == 0)
		{
			return pos;
		}
	}
	return -1;
}

static void mySwap(char* elem1, char* elem2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *elem1;
		*elem1 = *elem2;
		*elem2 = temp;
		elem1++;
		elem2++;
	}
}
static int mystrcmp(void* elem1, void* elem2)
{
	return ((struct UserInfo*)elem1)->age - ((struct UserInfo*)elem2)->age;
}


//初始化通讯录
void InitContact(struct Contact* ps)
{
	//保存用户信息的结构体数组清零
	memset(ps->data, 0, sizeof(ps->data));
	//通讯录中元素个数为0
	ps->size = 0;
}


//打印通讯录
void ShowContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else {
		int i = 0;
		//打印标题
		printf("%20s\t%5s\t%5s\t%15s\t%20s\n", "姓名", "年龄", "性别", "电话号码", "家庭住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%20s\t%5d\t%5s\t%15s\t%20s\n", ps->data[i].name, ps->data[i].age, ps->data[i].sex,ps->data[i].tele, ps->data[i].addr);
		}
	}
}


//通讯录中添加用户
void AddContact(struct Contact* ps)
{
	//判断通讯录是否已满
	if (ps->size == MAX_SIZE)
	{
		printf("通讯录已满\n");
	}
	else {
		printf("请输入用户名:\n");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:\n");
		scanf("%d", &ps->data[ps->size].age);
		printf("请输入电话号码:\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入家庭住址:\n");
		scanf("%s", ps->data[ps->size].addr);
		printf("请输入性别:\n");
		scanf("%s", ps->data[ps->size].sex);
		ps->size++;
		printf("用户信息添加成功\n");
	} 
}


//删除通讯录中用户信息
void DelContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空，删除失败:\n");
	}
	else {
		char name[MAX_NAME];
		int i = 0;
		printf("请输入要删除的用户的姓名:\n");
		scanf("%s", name);
		//在通讯录中查找该用户
		//调用FindByName函数查找用户
		//查找成功，返回该用户在结构体数组中的下标
		//查找失败，返回-1
		int pos = FindByName(ps, name);
		if (pos == -1)
		{
			printf("通讯录中没有找到该用户\n");
			
		}
		else
		{
			int j = 0;
			//删除用户
			for (j = pos; j < ps->size - 1; j++)
			{
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			printf("删除用户成功\n");
		}
	}

}


//查找通讯录中的用户信息
void SearchContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空,无法查找\n");
	}
	else {
		char name[MAX_NAME];
		printf("请输入要查找的用户的姓名:\n");
		scanf("%s", name);
		//在通讯录中查找该用户
		//调用FindByName函数查找用户
		//查找成功，返回该用户在结构体数组中的下标
		//查找失败，返回-1
		int pos=FindByName(ps, name);
		if (pos == -1)
		{
			printf("通讯录中没有找到该用户\n");
		}
		else {
			//打印标题
			printf("%20s\t%5s\t%5s\t%15s\t%20s\n", "姓名", "年龄", "性别", "电话号码", "家庭住址");
			//打印用户信息
			printf("%20s\t%5d\t%5s\t%15s\t%20s\n", 
				ps->data[pos].name, 
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
		}
	}
}


//修改指定用户的信息
void ModifyContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空,无法查找\n");
	}
	else {
		//1.查找用户
		char name[MAX_NAME];
		printf("请输入要修改的用户的姓名:\n");
		scanf("%s", name);
		//在通讯录中查找该用户
		//调用FindByName函数查找用户
		//查找成功，返回该用户在结构体数组中的下标
		//查找失败，返回-1
		int pos = FindByName(ps, name);
		if (pos == -1)
		{
			printf("通讯录中没有找到该用户\n");
		}
		else {
			//2.修改(将用户信息重新输入一遍)
			printf("请输入用户名:\n");
			scanf("%s", ps->data[pos].name);
			printf("请输入年龄:\n");
			scanf("%d", &ps->data[pos].age);
			printf("请输入电话号码:\n");
			scanf("%s", ps->data[pos].tele);
			printf("请输入家庭住址:\n");
			scanf("%s", ps->data[pos].addr);
			printf("请输入性别:\n");
			scanf("%s", ps->data[pos].sex);
			printf("用户信息修改成功\n");
		}   
	}
}


//按照年龄排序通讯录中的用户
void SortContact(struct Contact*ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else {
		int i = 0;
		int j = 0;
		int flag = 0;
		int width = sizeof(ps->data[0]);
		for (i = 0; i < ps->size - 1; i++)
		{
			flag = 0;
			for (j = 0; j < ps->size - i - 1; j++)
			{
				if (mystrcmp(((char*)(ps->data)) + j * width, ((char*)(ps->data)) + (j + 1) * width) > 0)
				{

					mySwap(((char*)(ps->data)) + j * width, ((char*)(ps->data)) + (j + 1)* width, width);
					flag = 1;
				}
			}
			if (flag == 0)
			{
				break;
			}
		}
		printf("排序完毕\n");
	}
}