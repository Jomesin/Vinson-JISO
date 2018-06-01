/*
 * 快速排序.c
 *
 *  Created on: 2018年1月9日
 *      Author: 金松
 */
#include<stdio.h>
int a[100], n;                        //定义两个全局变量

void quicksort(int left, int right)
{
	int i, j, t, temp;
	if(left > right)
		return;

	temp = a[left];                   //temp中存的就是基准数
	i = left;
	j = right;
	while(i != j)
	{
		while(a[j] >= temp && i < j)  //从右往左，找寻比基准数大的。
			j--;
		while(a[i] <= temp && i < j)  //从左往右，找寻比基准数小的。
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

	quicksort(left, i - 1);            //处理左边
	quicksort(i + 1, right);           //处理右边
	return;
}

int main()
{
	int i;
	scanf("%d", &n);                   //读入你所要排序的数的数量。
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);            //读入你所要排序的数。

	quicksort(0, n - 1);

	for(i = 0; i < n; i++)
		printf("%d ", a[i]);

	getchar();getchar();
	return 0;
}
/*读入数据
 * 10
 * 30 22 15 64 89 70 85 32 11 15
 * 输出结果为：11 15 15 22 30 32 64 70 85 89
 */
