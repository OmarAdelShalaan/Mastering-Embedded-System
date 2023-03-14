/*
 * lifo_buf.h
 *
 *  Created on: Mar 9, 2023
 *      Author: Omar
 */

#ifndef LIFO_BUF_H_
#define LIFO_BUF_H_

typedef struct{
	unsigned int lenght;
	unsigned int count;
	unsigned int* head;
	unsigned int* base;
}LIFO_BUF_t;

void LIFO_init(LIFO_BUF_t* lifo,int * buf, int lenght );
void LIFO_add_item(LIFO_BUF_t * lifo, int item);
void LIFO_get_item(LIFO_BUF_t * lifo, int* item);


#endif /* LIFO_BUF_H_ */
