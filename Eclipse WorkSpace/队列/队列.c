/*
 * 队列.c
 *
 *  Created on: 2018年1月11日
 *      Author: 金松
 */

#include<stdio.h>
int main()
{
	int a[100] = {6, 3, 1, 7, 5, 8, 9, 2, 4}, head, tail;
	head = 0;
	tail = 9;                                             //tail指向的是队尾后一个位置，防止队首和队尾相合带来麻烦。
	while(head < tail)
	{
		printf("%d", a[head]);                            //打印队首并将队首出队
		head++;

		a[tail] = a[head];                                //先将新队首的数添加到队尾
		tail++;
		head++;
	}
	getchar();getchar();
	return 0;
}
struct formation
{
	int data[100]; //队列的主体，用来存储内容
	int head;      //队首
	int tail;      //队尾
};
