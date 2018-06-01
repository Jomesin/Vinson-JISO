/*
 * 数组翻转.c
 *
 *  Created on: 2017年11月25日
 *      Author: 金松
 *      本次旨在学习数组的旋转（逆时针旋转90度）
 */
#include<stdio.h>
int main()
{
	int a[4][4], b[4][4], i, j; //a存储原数组数据，b存放旋转后的数组数据（逆时针旋转90度）
	printf("input 16 numbers:");//输入一组数据存放于数组a中，然后旋转后存放于b数组中
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
		{
			scanf("%d",&a[i][j]);
			b[3-j][i] = a[i][j];
		}
	printf("arrayb:\n");
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
			printf("%6d",b[i][j]);
		printf("\n");
	}
}

