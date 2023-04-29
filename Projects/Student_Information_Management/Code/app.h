/*
 * app.h
 *
 *  Created on: Apr 25, 2023
 *      Author: Omar
 */

#ifndef APP_H_
#define APP_H_



#include "fifo_buf.h"

#define DPrint(...) printf(__VA_ARGS__);\
					 fflush(stdin)



#define DScanf(Data) scanf(Data);\
					 fflush(stdin)
#define len 55

typedef enum{
	false,
	true
}bool;

typedef enum{
	not_equal,
	equal
}strCmpStatu_t;

void App_init();
void App_start();

void DPrint_Get_Choose(int * choose);
void Switch_Fun(int choose);


void AddStudent_Manually(); //done
void AddStudent_From_Text_File();//done
void FindStudent_IDNum(); //done
void FindStudent_FName();//done
void FindStudent_CId();
void TotalStudents_Num();//done
void DeleteStudent_IDNum();//done
void UpdataStudent_IDNum();//done
void DiplayStudent_Info(SStudentInfo_t * SStudent);//done
void DiplayAllStudent_Info();//done

bool FindID(int ID);


strCmpStatu_t cmpStr(char *str1, char *str2);

#endif /* APP_H_ */
