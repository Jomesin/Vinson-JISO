/*
 * 枚举火柴棍.c
 *
 *  Created on: 2018年1月13日
 *      Author: 金松
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
	for(i = 1; i <= n; i++)      //i表示1到n的数
	{
		if(book[i] == 0)         //记录数字i，0表示i还没有进入数组a中
		{
			a[x] = i;            //将数字i放入数组a第X个位置
			book[i] = 1;         //表示数字i进入数组a中
			full(x+1);            //
			book[i] = 0;         //收回数字i
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

