#define MAX_SIZE 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 15
#define MAX_ADDR 20
enum Option {
	EXIT,//0
	ADD,//1
	DEL,
	MODIFY,
	SEARCH,
     SHOW,
	 SORT
	
};
struct UserInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
struct Contact
{
	struct UserInfo data[MAX_SIZE];
	int size;
};

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);
//��ӡͨѶ¼
void ShowContact(struct Contact* ps);
//ͨѶ¼������û�
void AddContact(struct Contact* ps);
//ɾ��ͨѶ¼���û���Ϣ
void DelContact(struct Contact* ps);
//����ͨѶ¼�е��û���Ϣ
void SearchContact(struct Contact* ps);
//�޸�ָ���û�����Ϣ
void ModifyContact(struct Contact* ps);
//������������ͨѶ¼�е��û�
void SortContact(struct Contact*ps);