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

int NodeNumber = 0;//ͳ�Ƹ���
char MESSAGE[20] = { '\0' };//�����ļ����֣������ж��Ƿ��ظ�����
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
	printf("�����빦��ѡ�");
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
			printf("�������\n");
			system("PAUSE");
			system("CLS");
			Choice();
			break;
		}
		printf("�����빦��ѡ�");
	}
	return 0;
}

//����ѡ��
void Choice()
{
	printf("\t������������������������ӭ����ͨѶ¼����ϵͳ����������������������\n");
	printf("\t��                                                              ��\n");
	printf("\t��       ϵͳ����˵����                                         ��\n");
	printf("\t��                                                              ��\n");
	printf("\t��       1.���ļ���¼���λͬѧ�������Ϣ��                     ��\n");
	printf("\t��       2.����1λ��ͬѧ�������Ϣ��                            ��\n");
	printf("\t��       3.�޸�1λͬѧ�������Ϣ��                              ��\n");
	printf("\t��       4.ɾ��1λͬѧ��������Ϣ��                              ��\n");
	printf("\t��       5.����ǰϵͳ�е�������Ϣ���浽�ļ��У�                 ��\n");
	printf("\t��       6.��ӡĳλͬѧ�������������ֻ��Ų��ң������������Ϣ   ��\n");
	printf("\t��       7.��ӡĳ��ͬѧ�����������Ϣ����ѡ����                 ��\n");
	printf("\t��       8.������а༶�ɲ��������Ϣ��                         ��\n");
	printf("\t��       9.����ѧ��˳���ӡϵͳ������ͬѧ����Ϣ��               ��\n");
	printf("\t��      10.��ӡ���а�����ͬ�ֻ��ŵ�ͬѧ��Ϣ��                   ��\n");
	printf("\t��                                                              ��\n");
	printf("\t��            ---------�˳�ϵͳ������exit---------              ��\n");
	printf("\t��                                                              ��\n");
	printf("\t��������������������������ллʹ�á�������������������������������\n");
	printf("\n");
}

//���һ��ѧ����Ϣ
void Out(struct Student *t)
{
	printf("\tѧ  �ţ�%-13s��  ����%-13s\n", t->Number, t->Name);
	printf("\t��  ��%-13sְ  ��%-13s\n", t->Sex, t->Post);
	printf("\t�ֻ��ţ�%-13s�����ţ�%-13s\n", t->MainPhone, t->OtherPhone);
	printf("\t��  �䣺%s\n", t->Mail);
	printf("\t------------------------------------------\n");
	printf("\n");

}

//��������
void inrear(struct Student *p) //�����������У�
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
	NodeNumber++;//�ڵ�����һ
}

//��ѧ������
void Sort(){
	struct Student *p, *q, *r, *s; //qָ��p��ǰԪ�أ�rָ��p�ĺ�Ԫ��
	bool flag = true;
	s = (struct Student *)malloc(sizeof(struct Student)); //�ڱ�����
	s->Next = top;
	top = s;
	p = top->Next;
	q = s;
	while (flag&&p != NULL)
	{
		flag = false;
		while (p->Next != NULL) //��p��ͷɨ��β
		{
			r = p->Next; //rָ��p��
			if (strcmp(p->Number, r->Number) == 1)
			{
				q->Next = r;
				p->Next = r->Next;
				r->Next = p;
				q = r;
				flag = true;
			}
			else
			{ // q��p�����λ
				q = p;
				p = p->Next;
			}
		}
		q = s;//q��p���µ���һ��Ԫ��
		p = top->Next;
	}
	top = top->Next;//�ͷ��ڱ�����
	free(s);
}

//���ѧ���Ƿ��ظ�
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

//���ļ��ж�����Ϣ
void WriteMessage()
{
	FILE *f;
	char str[20] = { '\0' };
	printf("�������ļ�����:");
	scanf("%s", str);
	//�Ƚ��ļ������Ƿ��ظ�
	if (strcmp(MESSAGE, str) == 0)
	{
		printf("���󣬶������ͬһ�ļ���\n");
		printf("�Ƿ��������루Y or N��\n");
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
			printf("�ļ���ʧ�ܣ����������µ�%s�ļ�", str);
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
			printf("�ļ��ѳɹ�д�룡\n");
			printf("ѧ����Ϊ: %d\n", NodeNumber);
			system("PAUSE");
			system("CLS");
			Choice();
		}
		fclose(f);
	}
}


//����ѧ��
void AddStudent(){
	struct Student *p = (struct Student *)malloc(sizeof(struct Student));
	p->Next = NULL;
	printf("\n������ѧ��:");
	scanf("%s", &p->Number);
	while (p->Number[0] != '5' || p->Number[1] != '3')
	{
		printf("�������ѧ���ǲ��ǲ����أ�����������");
		scanf("%s", &p->Number);
		if (strlen(p->Number) != 8)
		{
			printf("�������ѧ���ǲ��ǲ����أ�����������");
			scanf("%s", &p->Number);
		}
	}
	while (strlen(p->Number) != 8)
	{
		printf("�������ѧ���ǲ��ǲ����أ�����������");
		scanf("%s", &p->Number);
		if (p->Number[0] != '5' || p->Number[1] != '3')
		{
			printf("�������ѧ���ǲ��ǲ����أ�����������");
			scanf("%s", &p->Number);
		}
	}
	printf("\n����������:");
	scanf("%s", &p->Name);
	for (int T = 67; T<122; T++)
	for (int i = 0; i<strlen(p->Name); i++)
	while (p->Name[i] == char(T))
	{
		printf("����������ָ�ʽ��������������");
		scanf("%s", &p->Name);
	}
	printf("\n�������Ա�:");
	scanf("%s", &p->Sex);
	while (strcmp(p->Sex, "��") != 0 && strcmp(p->Sex, "Ů") != 0 && strcmp(p->Sex, "����") != 0){
		printf("��������Ա��ʽ�д�������������");
		printf("\n");
		scanf("%s", &p->Sex);
	}
	printf("\n������ְ��:");
	scanf("%s", &p->Post);
	while (strcmp(p->Post, "�೤") != 0 && strcmp(p->Post, "ѧί") != 0 && strcmp(p->Post, "����ίԱ") != 0 && strcmp(p->Post, "����ίԱ") != 0){
		printf("�������ְ���д�������������");
		printf("\n");
		scanf("%s", &p->Post);
	}
	printf("\n��������Ҫ�ֻ���:");
	scanf("%s", &p->MainPhone);
	while (strlen(p->MainPhone) != 11)
	{
		printf("����������ֻ��Ÿ�ʽ����Ŷ������������");
		scanf("%s", &p->MainPhone);
	}
	for (int i = 0; i<strlen(p->MainPhone); i++)
	while (p->MainPhone[i] != char(48) && p->MainPhone[i] != char(49) && p->MainPhone[i] != char(50) && p->MainPhone[i] != char(51) && p->MainPhone[i] != char(52) && p->MainPhone[i] != char(53) && p->MainPhone[i] != char(54) && p->MainPhone[i] != char(55) && p->MainPhone[i] != char(56) && p->MainPhone[i] != char(57))
	{
		printf("����������ֻ��Ÿ�ʽ����Ŷ������������");
		scanf("%s", &p->MainPhone);
	}
	printf("\n�����������ֻ���:");
	scanf("%s", &p->OtherPhone);
	while (strlen(p->OtherPhone) != 11)
	{
		printf("������ĸ��ֻ��Ÿ�ʽ������Ŷ������������");
		scanf("%s", &p->OtherPhone);
	}
	while (strcmp(p->MainPhone, p->OtherPhone) == 0)
		printf("����������ֻ��ź͸��ֻ�����ͬ");
	printf("\n����������:");
	scanf("%s", &p->Mail);
	int j = 1;
	for (int L = 0; L<strlen(p->Mail); L++){
		if (p->Mail[L] == '@')
			j++;
	}

	if (j != 2)
	{
		printf("��������������ǲ��Ǵ�����,����������������");
		scanf("%s", &p->Mail);
	}


	if (Check(p))
		inrear(p);
	printf("�ѳɹ��洢��");
	system("PAUSE");
	system("CLS");
	Choice();
};

//�޸���Ϣ
void Amend(){
	printf("\n������Ҫ�޸ĵ�ͬѧ��ѧ�Ż�������");
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
		printf("\n��ѡ��Ҫ�޸ĵ���Ϣ��\n\n");
		printf("1.ѧ��  2.����  3.�Ա�  4.��Ҫ�绰���� 5.�����绰����  6.����\n\n");
		int n;
		scanf("%d", &n);
		while (n>0)
		{
			switch (n)
			{
			case 1:printf("�������µ�ѧ�ţ�");
				char NewNumber[9];
				scanf("%s", NewNumber);
				strcpy(p->Number, NewNumber);
				printf("�ѳɹ��޸ģ�\n");
				break;
			case 2:printf("�������µ�������");
				char NewName[9];
				scanf("%s", NewName);
				strcpy(p->Name, NewName);
				printf("�ѳɹ��޸ģ�\n");
				break;
			case 3:printf("�������µ��Ա�");
				char NewSex[3];
				scanf("%s", NewSex);
				strcpy(p->Sex, NewSex);
				printf("�ѳɹ��޸ģ�\n");
				break;
			case 4:printf("�������µ���Ҫ�ֻ����룺");
				char NewMainPhone[12];
				scanf("%s", NewMainPhone);
				strcpy(p->MainPhone, NewMainPhone);
				printf("�ѳɹ��޸ģ�\n");
				break;
			case 5:printf("�������µ������ֻ����룺");
				char NewOtherPhone[12];
				scanf("%s", NewOtherPhone);
				strcpy(p->OtherPhone, NewOtherPhone);
				printf("�ѳɹ��޸ģ�\n");
				break;
			case 6:printf("�������µ����䣺");
				char NewMail[30];
				scanf("%s", NewMail);
				strcpy(p->Mail, NewMail);
				printf("�ѳɹ��޸ģ�\n");
				break;
			default:printf("�������\n");
				break;
			}
			printf("\n�������޸�ѡ�������0�˳��޸ģ�\n");
			scanf("%d", &n);
		}
		system("PAUSE");
		system("CLS");
		Choice();
	}
	else
	{
		printf("��ϵͳ���޴�ѧ�����Ƿ���ӣ�Y or N��\n");
		char ch = getchar();//��ȥ�س�
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

//ɾ��ѧ��
void Delete(){
	printf("\n������Ҫɾ����ѧ����ѧ�Ż�������");
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
	NodeNumber--;//�ڵ�����һ

	printf("\n�Ƿ����ɾ����Y or N��\n\n");
	char ch = getchar();//��ȥ�س�
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

//������Ϣ���ļ�
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
	printf("�����ѳɹ������ļ�PresentMessage.txt��\n");
	system("PAUSE");
	system("CLS");
	Choice();
};

//��ӡָ��ѧ��
void PrintOne(){
	printf("������Ҫ��ӡ��ͬѧ���������ֻ��ţ�");
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
		printf("��ϵͳ���޴�ѧ�����������\n");
	system("PAUSE");
	system("CLS");
	Choice();

};

//��ӡָ���༶
void PrintClass(){
	bool flag = false;
	Sort();
	printf("������༶(����������)��");
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
		printf("��ϵͳ���޴˰༶��ѧ����\n");
	system("PAUSE");
	system("CLS");
	Choice();
};

//��ӡָ��ְ��
void PrintPosition(){
	bool flag;
	printf("������Ҫ��ӡ��ְ��");
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
		printf("��ϵͳ���޴�ְ��ѧ�����������\n");
	system("PAUSE");
	system("CLS");
	Choice();

};

//��ӡ����ѧ��
void PrintALL(){
	Sort();
	struct Student* p = top;
	printf("\tϵͳ�й���%d��ѧ��\n\n", NodeNumber);
	if (p == NULL)
		printf("�ļ���û��ѧ����Ϣ!\n");
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

//��ӡ������ͬ�ֻ��ŵ�ѧ��
void PrintSame(){
	int n = 1, m = 0;//n����ͳ��p,m����ͳ��q
	bool flag = true;//flag�жϵ�ǰ�ڵ�
	bool *Handle = (bool *)malloc(NodeNumber + 1);//��bool�͵������������true������ͬ��
	for (int i = 0; i<NodeNumber; i++)
		Handle[i] = true;
	struct Student *q = top, *p;
	if (q == NULL)
	{
		printf("ϵͳ����ѧ����Ϣ��\n");
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
					//��flag���Ƶ�ǰ�ڵ�����
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
			//�жϵ�ǰ�ڵ��Ƿ�ɷ���
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