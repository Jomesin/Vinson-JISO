#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


struct Student
{
	char Number[9];
	char Name[9];
	char Sex[20];
	char Post[4];
	char MainPhone[12];
	char OtherPhone[12];
	char Mail[30];
	struct Student* Next;
};

int NodeNumber = 0;//统计个数
char MESSAGE[20] = { '\0' };//保存文件名字，用来判断是否重复输入
struct Student *top = NULL, *rear = NULL;

void Choice();
void WriteMessage();
void AddStudent();
void Amend();
void Delete();
void Save();
void PrintOne();
void PrintClass();
void PrintPosition();
void PrintALL();
void PrintSame();


int main(){
	Choice();
	int num;
	printf("请输入功能选项：");
	while (scanf("%d", &num))
	{
		switch (num)
		{
		case 1:system("CLS");
			WriteMessage();
			break;
		case 2:system("CLS");
			AddStudent();
			break;
		case 3:system("CLS");
			Amend();
			break;
		case 4:system("CLS");
			Delete();
			break;
		case 5:system("CLS");
			Save();
			break;
		case 6:system("CLS");
			PrintOne();
			break;
		case 7:system("CLS");
			PrintClass();
			break;
		case 8:system("CLS");
			PrintPosition();
			break;
		case 9:system("CLS");
			PrintALL();
			break;
		case 10:system("CLS");
			PrintSame();
			break;
		default:system("CLS");
			printf("输入错误！\n");
			system("PAUSE");
			system("CLS");
			Choice();
			break;
		}
		printf("请输入功能选项：");
	}
	return 0;
}

//界面选项
void Choice()
{
	printf("\t※※※※※※※※※※※欢迎进入通讯录管理系统※※※※※※※※※※※\n");
	printf("\t※                                                              ※\n");
	printf("\t※       系统功能说明：                                         ※\n");
	printf("\t※                                                              ※\n");
	printf("\t※       1.从文件中录入多位同学的相关信息；                     ※\n");
	printf("\t※       2.增加1位新同学的相关信息；                            ※\n");
	printf("\t※       3.修改1位同学的相关信息；                              ※\n");
	printf("\t※       4.删除1位同学的所有信息；                              ※\n");
	printf("\t※       5.将当前系统中的所有信息保存到文件中；                 ※\n");
	printf("\t※       6.打印某位同学（按照姓名或手机号查找）的所有相关信息   ※\n");
	printf("\t※       7.打印某班同学的所有相关信息（可选）；                 ※\n");
	printf("\t※       8.输出所有班级干部的相关信息；                         ※\n");
	printf("\t※       9.按照学号顺序打印系统中所有同学的信息；               ※\n");
	printf("\t※      10.打印所有包含相同手机号的同学信息；                   ※\n");
	printf("\t※                                                              ※\n");
	printf("\t※            ---------退出系统请输入exit---------              ※\n");
	printf("\t※                                                              ※\n");
	printf("\t※※※※※※※※※※※※※谢谢使用※※※※※※※※※※※※※※※※\n");
	printf("\n");
}

//输出一个学生信息
void Out(struct Student *t)
{
	printf("\t学  号：%-13s姓  名：%-13s\n", t->Number, t->Name);
	printf("\t性  别：%-13s职  务：%-13s\n", t->Sex, t->Post);
	printf("\t手机号：%-13s其它号：%-13s\n", t->MainPhone, t->OtherPhone);
	printf("\t邮  箱：%s\n", t->Mail);
	printf("\t------------------------------------------\n");
	printf("\n");

}

//插入链表
void inrear(struct Student *p) //构建链表（队列）
{
	if (top == NULL)
	{
		top = p;
		rear = p;
	}

	else
	{
		rear->Next = p;
		rear = p;
	}
	NodeNumber++;//节点数加一
}

//对学号排序
void Sort(){
	struct Student *p, *q, *r, *s; //q指向p的前元素，r指向p的后元素
	bool flag = true;
	s = (struct Student *)malloc(sizeof(struct Student)); //哨兵变量
	s->Next = top;
	top = s;
	p = top->Next;
	q = s;
	while (flag&&p != NULL)
	{
		flag = false;
		while (p->Next != NULL) //用p从头扫到尾
		{
			r = p->Next; //r指向p后
			if (strcmp(p->Number, r->Number) == 1)
			{
				q->Next = r;
				p->Next = r->Next;
				r->Next = p;
				q = r;
				flag = true;
			}
			else
			{ // q，p向后移位
				q = p;
				p = p->Next;
			}
		}
		q = s;//q，p重新到第一个元素
		p = top->Next;
	}
	top = top->Next;//释放哨兵变量
	free(s);
}

//检查学生是否重复
bool Check(struct Student *t)
{
	struct Student *p = top;
	while (p != NULL)
	{
		if (strcmp(p->Number, t->Number) == 0 || strcmp(p->Name, t->Name) == 0)
			return false;
		p = p->Next;
	}
	return true;
}

//从文件中读入信息
void WriteMessage()
{
	FILE *f;
	char str[20] = { '\0' };
	printf("请输入文件名称:");
	scanf("%s", str);
	//比较文件名字是否重复
	if (strcmp(MESSAGE, str) == 0)
	{
		printf("错误，多次输入同一文件！\n");
		printf("是否重新输入（Y or N）\n");
		char ch = getchar();
		ch = getchar();
		if (ch == 'Y' || ch == 'y')
		{
			system("CLS");
			WriteMessage();
		}
		else
		{
			system("PAUSE");
			system("CLS");
			Choice();
		}
	}
	else
	{
		strcpy(MESSAGE, str);
		f = fopen(str, "r");
		if (!f)
		{
			printf("文件打开失败！即将创立新的%s文件", str);
			f = fopen(str, "w");
		}
		else
		{
			while (!feof(f))
			{
				struct Student *p = (struct Student *)malloc(sizeof(struct Student));
				p->Next = NULL;
				fscanf(f, "%s", &p->Number);
				fscanf(f, "%s", &p->Name);
				fscanf(f, "%s", &p->Sex);
				fscanf(f, "%s", &p->Post);
				fscanf(f, "%s", &p->MainPhone);
				fscanf(f, "%s", &p->OtherPhone);
				fscanf(f, "%s", &p->Mail);
				if (Check(p))
					inrear(p);
			}
			printf("文件已成功写入！\n");
			printf("学生数为: %d\n", NodeNumber);
			system("PAUSE");
			system("CLS");
			Choice();
		}
		fclose(f);
	}
}


//增加学生
void AddStudent(){
	struct Student *p = (struct Student *)malloc(sizeof(struct Student));
	p->Next = NULL;
	printf("\n请输入学号:");
	scanf("%s", &p->Number);
	while (p->Number[0] != '5' || p->Number[1] != '3')
	{
		printf("你输入的学号是不是不对呢，请重新输入");
		scanf("%s", &p->Number);
		if (strlen(p->Number) != 8)
		{
			printf("你输入的学号是不是不对呢，请重新输入");
			scanf("%s", &p->Number);
		}
	}
	while (strlen(p->Number) != 8)
	{
		printf("你输入的学号是不是不对呢，请重新输入");
		scanf("%s", &p->Number);
		if (p->Number[0] != '5' || p->Number[1] != '3')
		{
			printf("你输入的学号是不是不对呢，请重新输入");
			scanf("%s", &p->Number);
		}
	}
	printf("\n请输入姓名:");
	scanf("%s", &p->Name);
	for (int T = 67; T<122; T++)
	for (int i = 0; i<strlen(p->Name); i++)
	while (p->Name[i] == char(T))
	{
		printf("你输入的名字格式有误，请重新输入");
		scanf("%s", &p->Name);
	}
	printf("\n请输入性别:");
	scanf("%s", &p->Sex);
	while (strcmp(p->Sex, "男") != 0 && strcmp(p->Sex, "女") != 0 && strcmp(p->Sex, "不详") != 0){
		printf("你输入的性别格式有错误请重新输入");
		printf("\n");
		scanf("%s", &p->Sex);
	}
	printf("\n请输入职务:");
	scanf("%s", &p->Post);
	while (strcmp(p->Post, "班长") != 0 && strcmp(p->Post, "学委") != 0 && strcmp(p->Post, "体育委员") != 0 && strcmp(p->Post, "文艺委员") != 0){
		printf("你输入的职务有错误请重新输入");
		printf("\n");
		scanf("%s", &p->Post);
	}
	printf("\n请输入主要手机号:");
	scanf("%s", &p->MainPhone);
	while (strlen(p->MainPhone) != 11)
	{
		printf("你输入的主手机号格式有误哦，请重新输入");
		scanf("%s", &p->MainPhone);
	}
	for (int i = 0; i<strlen(p->MainPhone); i++)
	while (p->MainPhone[i] != char(48) && p->MainPhone[i] != char(49) && p->MainPhone[i] != char(50) && p->MainPhone[i] != char(51) && p->MainPhone[i] != char(52) && p->MainPhone[i] != char(53) && p->MainPhone[i] != char(54) && p->MainPhone[i] != char(55) && p->MainPhone[i] != char(56) && p->MainPhone[i] != char(57))
	{
		printf("你输入的主手机号格式有误哦，请重新输入");
		scanf("%s", &p->MainPhone);
	}
	printf("\n请输入其他手机号:");
	scanf("%s", &p->OtherPhone);
	while (strlen(p->OtherPhone) != 11)
	{
		printf("你输入的副手机号格式有问题哦，请重新输入");
		scanf("%s", &p->OtherPhone);
	}
	while (strcmp(p->MainPhone, p->OtherPhone) == 0)
		printf("你输入的主手机号和副手机号相同");
	printf("\n请输入邮箱:");
	scanf("%s", &p->Mail);
	int j = 1;
	for (int L = 0; L<strlen(p->Mail); L++){
		if (p->Mail[L] == '@')
			j++;
	}

	if (j != 2)
	{
		printf("你输入的邮箱名是不是错了呢,请重新输入邮箱名");
		scanf("%s", &p->Mail);
	}


	if (Check(p))
		inrear(p);
	printf("已成功存储！");
	system("PAUSE");
	system("CLS");
	Choice();
};

//修改信息
void Amend(){
	printf("\n请输入要修改的同学的学号或姓名：");
	char str[8];
	scanf("%s", str);
	struct Student *p = top;
	while (p != NULL)
	{
		if ((strcmp(str, p->Number) == 0) || (strcmp(str, p->Name) == 0))
			break;
		else
			p = p->Next;
	}
	if (p != NULL)
	{
		printf("\n请选择要修改的信息：\n\n");
		printf("1.学号  2.姓名  3.性别  4.主要电话号码 5.其它电话号码  6.邮箱\n\n");
		int n;
		scanf("%d", &n);
		while (n>0)
		{
			switch (n)
			{
			case 1:printf("请输入新的学号：");
				char NewNumber[9];
				scanf("%s", NewNumber);
				strcpy(p->Number, NewNumber);
				printf("已成功修改！\n");
				break;
			case 2:printf("请输入新的姓名：");
				char NewName[9];
				scanf("%s", NewName);
				strcpy(p->Name, NewName);
				printf("已成功修改！\n");
				break;
			case 3:printf("请输入新的性别：");
				char NewSex[3];
				scanf("%s", NewSex);
				strcpy(p->Sex, NewSex);
				printf("已成功修改！\n");
				break;
			case 4:printf("请输入新的主要手机号码：");
				char NewMainPhone[12];
				scanf("%s", NewMainPhone);
				strcpy(p->MainPhone, NewMainPhone);
				printf("已成功修改！\n");
				break;
			case 5:printf("请输入新的其它手机号码：");
				char NewOtherPhone[12];
				scanf("%s", NewOtherPhone);
				strcpy(p->OtherPhone, NewOtherPhone);
				printf("已成功修改！\n");
				break;
			case 6:printf("请输入新的邮箱：");
				char NewMail[30];
				scanf("%s", NewMail);
				strcpy(p->Mail, NewMail);
				printf("已成功修改！\n");
				break;
			default:printf("输入错误！\n");
				break;
			}
			printf("\n请输入修改选项或输入0退出修改！\n");
			scanf("%d", &n);
		}
		system("PAUSE");
		system("CLS");
		Choice();
	}
	else
	{
		printf("该系统中无此学生，是否添加（Y or N）\n");
		char ch = getchar();//滤去回车
		ch = getchar();
		if (ch == 'Y' || ch == 'y')
			AddStudent();
		if (ch == 'N' || ch == 'n')
		{
			system("PAUSE");
			system("CLS");
			Choice();
		}
	}
};

//删除学生
void Delete(){
	printf("\n请输入要删除的学生的学号或姓名：");
	char str[9];
	scanf("%s", str);
	struct Student *s = (struct Student *)malloc(sizeof(struct Student)), *p, *q;
	s->Next = top;
	top = s;
	q = s;
	p = q->Next;
	while (p != NULL)
	{
		if ((strcmp(str, p->Number) == 0) || (strcmp(str, p->Name) == 0))
		{
			q->Next = p->Next;
			p = p->Next;
		}
		else
		{
			q = q->Next;
			p = p->Next;
		}
	}
	top = top->Next;
	free(s);
	NodeNumber--;//节点数减一

	printf("\n是否继续删除（Y or N）\n\n");
	char ch = getchar();//滤去回车
	ch = getchar();
	if (ch == 'Y' || ch == 'y')
		Delete();
	if (ch == 'N' || ch == 'n')
	{
		system("PAUSE");
		system("CLS");
		Choice();
	}
};

//保存信息到文件
void Save(){
	FILE *out;
	out = fopen("PresentMessage.txt", "w");
	struct Student *p = top;
	while (p != NULL)
	{
		fprintf(out, "%s %s %s %s %s %s\n", p->Number, p->Name, p->Sex, p->MainPhone, p->OtherPhone, p->Mail);
		p = p->Next;
	}
	fclose(out);
	printf("数据已成功导入文件PresentMessage.txt！\n");
	system("PAUSE");
	system("CLS");
	Choice();
};

//打印指定学生
void PrintOne(){
	printf("请输入要打印的同学的姓名或手机号：");
	bool flag = false;
	char str[12];
	scanf("%s", str);
	struct Student *p = top;
	while (p != NULL)
	{
		if ((strcmp(str, p->MainPhone) == 0) || (strcmp(str, p->OtherPhone) == 0) || (strcmp(str, p->Name) == 0))
		{
			flag = true;
			Out(p);
			p = p->Next;
		}
		else
			p = p->Next;
	}
	if (!flag)
		printf("该系统中无此学生或输入错误！\n");
	system("PAUSE");
	system("CLS");
	Choice();

};

//打印指定班级
void PrintClass(){
	bool flag = false;
	Sort();
	printf("请输入班级(阿拉伯数字)：");
	int num;
	scanf("%d", &num);
	char ch[2];
	ch[0] = char(num % 10 + 48);
	ch[1] = char(num / 10 + 48);
	struct Student *p = top;
	while (p != NULL)
	{
		if (p->Number[4] == ch[1] && p->Number[5] == ch[0]){
			Out(p);
			flag = true;
		}
		p = p->Next;
	}
	if (!flag)
		printf("该系统中无此班级的学生！\n");
	system("PAUSE");
	system("CLS");
	Choice();
};

//打印指定职务
void PrintPosition(){
	bool flag;
	printf("请输入要打印的职务：");
	char str[12];
	scanf("%s", str);
	struct Student *p = top;
	while (p != NULL)
	{
		if ((strcmp(str, p->Post) == 0))
		{
			flag = true;
			Out(p);
			p = p->Next;
		}
		else
			p = p->Next;
	}
	if (!flag)
		printf("该系统中无此职务学生或输入错误！\n");
	system("PAUSE");
	system("CLS");
	Choice();

};

//打印所有学生
void PrintALL(){
	Sort();
	struct Student* p = top;
	printf("\t系统中共有%d个学生\n\n", NodeNumber);
	if (p == NULL)
		printf("文件中没有学生信息!\n");
	else
	{
		while (p != NULL)
		{
			Out(p);
			p = p->Next;
		}
	}
	system("PAUSE");
	system("CLS");
	Choice();
};

//打印含有相同手机号的学生
void PrintSame(){
	int n = 1, m = 0;//n用来统计p,m用来统计q
	bool flag = true;//flag判断当前节点
	bool *Handle = (bool *)malloc(NodeNumber + 1);//用bool型的数组关联链表，true代表相同的
	for (int i = 0; i<NodeNumber; i++)
		Handle[i] = true;
	struct Student *q = top, *p;
	if (q == NULL)
	{
		printf("系统中无学生信息！\n");
		system("PAUSE");
		system("CLS");
		Choice();
	}
	else
	{
		p = q->Next;
		while (q->Next != NULL)
		{
			while (p != NULL)
			{
				if ((strcmp(q->MainPhone, p->MainPhone) == 0) || (strcmp(q->OtherPhone, p->OtherPhone) == 0) || (strcmp(q->MainPhone, p->OtherPhone) == 0) || (strcmp(q->OtherPhone, p->MainPhone) == 0))
				{
					//用flag控制当前节点的输出
					if (flag)
					{
						Out(q);
						Out(p);
						flag = false;
						Handle[n++] = false;
					}
					else
					{
						Out(p);
						Handle[n++] = false;
					}
				}
				else
					n++;
				p = p->Next;
			}
			m++;
			q = q->Next;
			flag = true;
			//判断当前节点是否可访问
			while (Handle[m] == false)
			{
				q = q->Next;
				if (q->Next == NULL)
					break;
				m++;
			}
			n = m + 1;
			p = q->Next;
		}
	}
	system("PAUSE");
	system("CLS");
	Choice();
};