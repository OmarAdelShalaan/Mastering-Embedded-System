/*
 * main.c
 *
 *  Created on: Mar 9, 2023
 *      Author: Omar
 */

#include<stdio.h>
#include"lifo_buf.h"
/*
 *
void LIFO_init(LIFO_BUF_t* lifo,int * buf, int lenght );
void LIFO_add_item(LIFO_BUF_t * lifo, int item);
void LIFO_get_item(LIFO_BUF_t * lifo, int* item);
 *
 *
 */
int buf[5];
int main()
{
	LIFO_BUF_t* lifo;
	LIFO_init(lifo,buf, 5);

	int i = 0;
	int item;
	for(i = 1; i < 7 ; i++)
	{
		LIFO_add_item(lifo,i);
	}
	for(i = 0; i < 5 ; i++)
	{
		LIFO_get_item(lifo,&item);
		printf("%d\n",item);
	}

	return 0;
}
