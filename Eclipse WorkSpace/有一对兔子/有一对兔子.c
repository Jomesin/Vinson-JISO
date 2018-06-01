/*
 * 有一对兔子.c
 *
 *  Created on: 2017年11月18日
 *      Author: 金松
 *      从出生后第3个月起每个月都生一对兔子，小兔子长到
 *  第3个月后每个月又生一对兔子，假如兔子都不死，问每个
 *  月的兔子总数是多少？
 */
#include<stdio.h>
int main()
{
	int f1, f2;
	int i;
	f1 = f2 = 1;
	for(i = 1; i <= 20; i++)
	{
		printf("%d %d",f1,f2);
		if(i%2 == 0)
			printf("\n");
		f1 = f1 + f2;
		f2 = f1 + f2;
	}
}

