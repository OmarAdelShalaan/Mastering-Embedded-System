/*
 * main.c
 *
 *  Created on: Mar 14, 2023
 *      Author: Omar
 */

#include<stdio.h>
#include"fifo_buf.h"


int buf[5];

/*
void FIFO_BUF_init(FIFO_BUF_t fifo_buf, int * buf,  int length);
void enqueue(FIFO_BUF_t fifo_buf, Element_type data);
Element_type dequeue(FIFO_BUF_t fifo_buf);

int isFull(FIFO_BUF_t fifo_buf);
int isEmpty(FIFO_BUF_t fifo_buf);
 */

int main()
{
	FIFO_BUF_t *fifo_buf;
	FIFO_BUF_init(fifo_buf, buf,  5);
	int i,temp;
	for(i = 0; i <10; i++)
		enqueue(fifo_buf,i);
	printf("isFull: %d\n",isFull(fifo_buf));
	for(i = 0; i <10; i++)
	{
		dequeue(fifo_buf,&temp);
	}
	printf("isEmpty: %d\n",isEmpty(fifo_buf));
	printf("isFull: %d\n",isFull(fifo_buf));
	return 0;
}
