/*
 * ���鷭ת.c
 *
 *  Created on: 2017��11��25��
 *      Author: ����
 *      ����ּ��ѧϰ�������ת����ʱ����ת90�ȣ�
 */
#include<stdio.h>
int main()
{
	int a[4][4], b[4][4], i, j; //a�洢ԭ�������ݣ�b�����ת����������ݣ���ʱ����ת90�ȣ�
	printf("input 16 numbers:");//����һ�����ݴ��������a�У�Ȼ����ת������b������
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

