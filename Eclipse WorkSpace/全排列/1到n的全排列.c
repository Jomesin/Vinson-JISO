/*
 * ö�ٻ���.c
 *
 *  Created on: 2018��1��13��
 *      Author: ����
 */
#include<stdio.h>
int a[10], book[10], n;

void full(int x)
{
	int i;
	if(x == n+1)
	{
		for(i = 1; i <= n; i++)
			printf("%d", a[i]);
		printf("\n");

		return;
	}
	for(i = 1; i <= n; i++)      //i��ʾ1��n����
	{
		if(book[i] == 0)         //��¼����i��0��ʾi��û�н�������a��
		{
			a[x] = i;            //������i��������a��X��λ��
			book[i] = 1;         //��ʾ����i��������a��
			full(x+1);            //
			book[i] = 0;         //�ջ�����i
		}
	}
	return;
}
int main()
{
	printf("please input a number(No more than 9 ):\n");
	scanf("%d", &n);
	full(1);
	getchar();getchar();
	return 0;
}

