/*
 * ����.c
 *
 *  Created on: 2018��1��11��
 *      Author: ����
 */

#include<stdio.h>
int main()
{
	int a[100] = {6, 3, 1, 7, 5, 8, 9, 2, 4}, head, tail;
	head = 0;
	tail = 9;                                             //tailָ����Ƕ�β��һ��λ�ã���ֹ���׺Ͷ�β��ϴ����鷳��
	while(head < tail)
	{
		printf("%d", a[head]);                            //��ӡ���ײ������׳���
		head++;

		a[tail] = a[head];                                //�Ƚ��¶��׵�����ӵ���β
		tail++;
		head++;
	}
	getchar();getchar();
	return 0;
}
struct formation
{
	int data[100]; //���е����壬�����洢����
	int head;      //����
	int tail;      //��β
};
