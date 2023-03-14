/*
 * lifo_buf.c
 *
 *  Created on: Mar 9, 2023
 *      Author: Omar
 */


#include"lifo_buf.h"

void LIFO_init(LIFO_BUF_t* lifo,int * buf, int lenght )
{
	if(buf == 0)
		return ;
	lifo->head = buf;
	lifo->base = buf;
	lifo->lenght = lenght;
	lifo->count = 0;
}
void LIFO_add_item(LIFO_BUF_t * lifo, int item)
{
	if(lifo->lenght == lifo->count )
		return ;//full
	*(lifo->head) = item;
	lifo->head++;
	lifo->count++;
}

void LIFO_get_item(LIFO_BUF_t * lifo, int* item)
{
	if(-1 == lifo->count )
		return ;//empty
	lifo->head--;
	*item = *(lifo->head);
	lifo->count--;
}
