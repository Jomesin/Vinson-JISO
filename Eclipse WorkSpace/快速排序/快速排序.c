/*
 * ��������.c
 *
 *  Created on: 2018��1��9��
 *      Author: ����
 */
#include<stdio.h>
int a[100], n;                        //��������ȫ�ֱ���

void quicksort(int left, int right)
{
	int i, j, t, temp;
	if(left > right)
		return;

	temp = a[left];                   //temp�д�ľ��ǻ�׼��
	i = left;
	j = right;
	while(i != j)
	{
		while(a[j] >= temp && i < j)  //����������Ѱ�Ȼ�׼����ġ�
			j--;
		while(a[i] <= temp && i < j)  //�������ң���Ѱ�Ȼ�׼��С�ġ�
			i++;

		if(i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);            //�������
	quicksort(i + 1, right);           //�����ұ�
	return;
}

int main()
{
	int i;
	scanf("%d", &n);                   //��������Ҫ���������������
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);            //��������Ҫ���������

	quicksort(0, n - 1);

	for(i = 0; i < n; i++)
		printf("%d ", a[i]);

	getchar();getchar();
	return 0;
}
/*��������
 * 10
 * 30 22 15 64 89 70 85 32 11 15
 * ������Ϊ��11 15 15 22 30 32 64 70 85 89
 */
