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

//初始化通讯录
void InitContact(struct Contact* ps);
//打印通讯录
void ShowContact(struct Contact* ps);
//通讯录中添加用户
void AddContact(struct Contact* ps);
//删除通讯录中用户信息
void DelContact(struct Contact* ps);
//查找通讯录中的用户信息
void SearchContact(struct Contact* ps);
//修改指定用户的信息
void ModifyContact(struct Contact* ps);
//按照年龄排序通讯录中的用户
void SortContact(struct Contact*ps);