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


//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
	//�����û���Ϣ�Ľṹ����������
	memset(ps->data, 0, sizeof(ps->data));
	//ͨѶ¼��Ԫ�ظ���Ϊ0
	ps->size = 0;
}


//��ӡͨѶ¼
void ShowContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else {
		int i = 0;
		//��ӡ����
		printf("%20s\t%5s\t%5s\t%15s\t%20s\n", "����", "����", "�Ա�", "�绰����", "��ͥסַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%20s\t%5d\t%5s\t%15s\t%20s\n", ps->data[i].name, ps->data[i].age, ps->data[i].sex,ps->data[i].tele, ps->data[i].addr);
		}
	}
}


//ͨѶ¼������û�
void AddContact(struct Contact* ps)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (ps->size == MAX_SIZE)
	{
		printf("ͨѶ¼����\n");
	}
	else {
		printf("�������û���:\n");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:\n");
		scanf("%d", &ps->data[ps->size].age);
		printf("������绰����:\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ͥסַ:\n");
		scanf("%s", ps->data[ps->size].addr);
		printf("�������Ա�:\n");
		scanf("%s", ps->data[ps->size].sex);
		ps->size++;
		printf("�û���Ϣ��ӳɹ�\n");
	} 
}


//ɾ��ͨѶ¼���û���Ϣ
void DelContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�ɾ��ʧ��:\n");
	}
	else {
		char name[MAX_NAME];
		int i = 0;
		printf("������Ҫɾ�����û�������:\n");
		scanf("%s", name);
		//��ͨѶ¼�в��Ҹ��û�
		//����FindByName���������û�
		//���ҳɹ������ظ��û��ڽṹ�������е��±�
		//����ʧ�ܣ�����-1
		int pos = FindByName(ps, name);
		if (pos == -1)
		{
			printf("ͨѶ¼��û���ҵ����û�\n");
			
		}
		else
		{
			int j = 0;
			//ɾ���û�
			for (j = pos; j < ps->size - 1; j++)
			{
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			printf("ɾ���û��ɹ�\n");
		}
	}

}


//����ͨѶ¼�е��û���Ϣ
void SearchContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�����\n");
	}
	else {
		char name[MAX_NAME];
		printf("������Ҫ���ҵ��û�������:\n");
		scanf("%s", name);
		//��ͨѶ¼�в��Ҹ��û�
		//����FindByName���������û�
		//���ҳɹ������ظ��û��ڽṹ�������е��±�
		//����ʧ�ܣ�����-1
		int pos=FindByName(ps, name);
		if (pos == -1)
		{
			printf("ͨѶ¼��û���ҵ����û�\n");
		}
		else {
			//��ӡ����
			printf("%20s\t%5s\t%5s\t%15s\t%20s\n", "����", "����", "�Ա�", "�绰����", "��ͥסַ");
			//��ӡ�û���Ϣ
			printf("%20s\t%5d\t%5s\t%15s\t%20s\n", 
				ps->data[pos].name, 
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
		}
	}
}


//�޸�ָ���û�����Ϣ
void ModifyContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�����\n");
	}
	else {
		//1.�����û�
		char name[MAX_NAME];
		printf("������Ҫ�޸ĵ��û�������:\n");
		scanf("%s", name);
		//��ͨѶ¼�в��Ҹ��û�
		//����FindByName���������û�
		//���ҳɹ������ظ��û��ڽṹ�������е��±�
		//����ʧ�ܣ�����-1
		int pos = FindByName(ps, name);
		if (pos == -1)
		{
			printf("ͨѶ¼��û���ҵ����û�\n");
		}
		else {
			//2.�޸�(���û���Ϣ��������һ��)
			printf("�������û���:\n");
			scanf("%s", ps->data[pos].name);
			printf("����������:\n");
			scanf("%d", &ps->data[pos].age);
			printf("������绰����:\n");
			scanf("%s", ps->data[pos].tele);
			printf("�������ͥסַ:\n");
			scanf("%s", ps->data[pos].addr);
			printf("�������Ա�:\n");
			scanf("%s", ps->data[pos].sex);
			printf("�û���Ϣ�޸ĳɹ�\n");
		}   
	}
}


//������������ͨѶ¼�е��û�
void SortContact(struct Contact*ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
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
		printf("�������\n");
	}
}