/*
 * student.h
 *
 *  Created on: Apr 25, 2023
 *      Author: Omar
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct student_info{
	char fname[50];
	char lname[50];
	int ID;
	float GPA;
	int cid[10];
}SStudentInfo_t;

#endif /* STUDENT_H_ */
