/*
 * app.c
 *
 *  Created on: Apr 25, 2023
 *      Author: Omar
 */


#include "app.h"


SStudentInfo_t StudentBuf_g[len];
FIFO_BUF_t *StudentFifo_Buf;

void DPrint_Get_Choose(int * choose)
{
	DPrint("\nChoose The Task that you want to perform\n");
	DPrint("1. Add The Student Details Manually\n");
	DPrint("2. Add The Student Details From Text File\n");
	DPrint("3. Find the Student Details by ID Number\n");
	DPrint("4. Find the Student Details by First Name\n");
	DPrint("5. Find the Student Details by Course Id\n");
	DPrint("6. Find the Total number of Students\n");
	DPrint("7. Delete the Students Details by ID Number\n");
	DPrint("8. Update the Students Details by ID Number\n");
	DPrint("9. Show all information\n");
	DPrint("10. Exit\n");
	DPrint("Enter your choice to perform the task: ");
	scanf("%d",choose);
	DPrint("\n");
}

void App_init()
{
	StudentFifo_Buf = (FIFO_BUF_t*) malloc(sizeof(FIFO_BUF_t));
	FIFO_BUF_init( StudentFifo_Buf, StudentBuf_g, len);
}

void App_start()
{
	int choose = 0;
	while(1)
	{
		DPrint_Get_Choose(&choose);
		Switch_Fun(choose);
		//DiplayAllStudent_Info();
	}
}

void Switch_Fun(int choose)
{
	switch(choose)
	{
	case 1:
		// Add The Student Details Manually
		AddStudent_Manually();
		break;
	case 2:
		// Add The Student Details From Text File
		AddStudent_From_Text_File();
		break;
	case 3:
		// Find the Student Details by ID Number
		FindStudent_IDNum();
		break;
	case 4:
		// Find the Student Details by First Name
		FindStudent_FName();
		break;
	case 5:
		// Find the Student Details by Course Id
		FindStudent_CId();
		break;
	case 6:
		// Find the Total number of Students
		TotalStudents_Num();
		break;
	case 7:
		// Delete the Students Details by ID Number
		DeleteStudent_IDNum();
		break;
	case 8:
		// Update the Students Details by ID Number
		UpdataStudent_IDNum();
		break;
	case 9:
		// Show all information
		DiplayAllStudent_Info();
		break;
	case 10:
		exit(0);
	}
}



void AddStudent_Manually()
{
	int tempID;
	SStudentInfo_t *tempStudent = (SStudentInfo_t*) malloc(sizeof(SStudentInfo_t));
	DPrint("\nEnter Your ID: ");
	scanf("%d",&tempID);
	if(FindID(tempID))
	{
		DPrint("This ID already Found \n");
		return ;
	}
	tempStudent->ID = tempID;
	DPrint("Enter Your First Name: ");
	scanf("%s",tempStudent->fname);
	DPrint("Enter Your Last  Name: ");
	scanf("%s",tempStudent->lname);
	enqueue(StudentFifo_Buf,*tempStudent);
	free(tempStudent);
}

void FindStudent_IDNum()
{
	if(isEmpty(StudentFifo_Buf))
	{
		DPrint("This is Empty\n");
		return ;
	}
	int ID;
	SStudentInfo_t *tempStudent = StudentFifo_Buf->tail;
	DPrint("Enter ID Number: ");
	scanf("%d",&ID);
	while( StudentFifo_Buf->head != tempStudent)
	{
		if(tempStudent->ID == ID)
		{
			DiplayStudent_Info(tempStudent);
			return;
		}
		tempStudent++;
		if( tempStudent == (StudentFifo_Buf->base + StudentFifo_Buf->length) )
		{
			tempStudent = StudentFifo_Buf->base;
		}
	}
	DPrint("This ID Not Found\n");
	return ;

}
void FindStudent_FName()
{
	if(isEmpty(StudentFifo_Buf))
	{
		DPrint("This is Empty\n");
		return ;
	}
	char name[50];
	SStudentInfo_t *tempStudent = StudentFifo_Buf->tail;
	DPrint("Enter First Name : ");
	scanf("%s", name);
	while( StudentFifo_Buf->head != tempStudent)
	{
		if(cmpStr(name ,tempStudent->fname ))
		{
			DiplayStudent_Info(tempStudent);
			return;
		}
		tempStudent++;
		if( tempStudent == (StudentFifo_Buf->base + StudentFifo_Buf->length) )
		{
			tempStudent = StudentFifo_Buf->base;
		}
	}
	DPrint("This Name Not Found\n");
	return ;
}
void FindStudent_CId()
{

}
void TotalStudents_Num()
{
	int count = 0;
	if(isEmpty(StudentFifo_Buf))
	{
		DPrint("No Student Save Yet\n");
		return ;
	}

	SStudentInfo_t *tempStudent = StudentFifo_Buf->tail;
	while( StudentFifo_Buf->head != tempStudent)
	{
		count++;
		tempStudent++;
		if( tempStudent == (StudentFifo_Buf->base + StudentFifo_Buf->length) + 1)
		{
			tempStudent = StudentFifo_Buf->base;
		}
	}
	DPrint("Number Student Save is %d\n",count);
	return ;

}
void DeleteStudent_IDNum()
{
	if(isEmpty(StudentFifo_Buf))
	{
		DPrint("This is Empty\n");
		return ;
	}
	int ID;
	SStudentInfo_t *tempStudent = StudentFifo_Buf->tail;
	DPrint("Enter ID Number: ");
	scanf("%d",&ID);
	while( StudentFifo_Buf->head != tempStudent)
	{
		if(tempStudent->ID == ID)
		{
			while( StudentFifo_Buf->head != tempStudent + 1)
			{
				*tempStudent = *( tempStudent + 1 );
				tempStudent++;
			}
			StudentFifo_Buf->head--;
			return;
		}
		tempStudent++;
		if( tempStudent == (StudentFifo_Buf->base + StudentFifo_Buf->length) )
		{
			tempStudent = StudentFifo_Buf->base;
		}
	}
	DPrint("This ID Not Found\n");
	return ;
}
void UpdataStudent_IDNum()
{
	if(isEmpty(StudentFifo_Buf))
	{
		DPrint("This is Empty\n");
		return ;
	}
	int oldID;
	int newID;
	SStudentInfo_t *tempStudent = StudentFifo_Buf->tail;
	DPrint("Enter Old ID Number: ");
	scanf("%d",&oldID);
	while( StudentFifo_Buf->head != tempStudent)
	{
		if(tempStudent->ID == oldID)
		{
			DPrint("\nEnter Your New ID: ");
			scanf("%d",&newID);
			if(newID != oldID )
			{
				if(FindID(newID))
				{
					DPrint("This ID already Found \n");
					return ;
				}
			}
			tempStudent->ID = newID;
			DPrint("Enter Your First Name: ");
			scanf("%s",tempStudent->fname);
			DPrint("Enter Your Last  Name: ");
			scanf("%s",tempStudent->lname);
			return;
		}
		tempStudent++;
		if( tempStudent == (StudentFifo_Buf->base + StudentFifo_Buf->length) )
		{
			tempStudent = StudentFifo_Buf->base;
		}
	}
	DPrint("This ID Not Found\n");
	return ;
}
void DiplayStudent_Info(SStudentInfo_t * SStudent)
{
	DPrint("\n\n");
	DPrint("First Name : %s\n",SStudent->fname);
	DPrint("Last  Name : %s\n",SStudent->lname);
	DPrint("ID : %d\n",SStudent->ID);
}
void DiplayAllStudent_Info()
{
	SStudentInfo_t *tempStudent = StudentFifo_Buf->tail;
	if(isEmpty(StudentFifo_Buf))
	{
		DPrint("No Student Save Yet\n");
		return ;
	}
	while( StudentFifo_Buf->head != tempStudent)
	{
		DiplayStudent_Info(tempStudent);
		tempStudent++;
		if( tempStudent == (StudentFifo_Buf->base + StudentFifo_Buf->length + 1) )
		{
			tempStudent = StudentFifo_Buf->base;
		}
	}
}
bool FindID(int ID)
{
	SStudentInfo_t *tempStudent = StudentFifo_Buf->tail;
	if(isEmpty(StudentFifo_Buf))
		return false;
	while( StudentFifo_Buf->head != tempStudent)
	{
		if(tempStudent->ID == ID)
		{
			return true;
		}
		tempStudent++;
		if( tempStudent == (StudentFifo_Buf->base + StudentFifo_Buf->length) )
		{
			tempStudent = StudentFifo_Buf->base;
		}
	}
	return false;
}
strCmpStatu_t cmpStr(char *str1, char *str2)
{
	while( *str1 !='\0' ||  *str2 !='\0' )
	{
		if( *str1 != *str2)
			return not_equal;
		str1++;
		str2++;
	}
	return equal;
}



void AddStudent_From_Text_File()
{
	int id = 0,i,j;
	//char FName[50];
	//char LName[50];
	char FileName[50];
	printf("Please Enter File Name with (.txt): ");
	scanf("%s",FileName);

	FILE *ptrfile = fopen(FileName, "r");

	if (ptrfile == NULL)
	{
		printf("Error: could not open file %s", FileName);
		return ;
	}

	// reading line by line, max 256 bytes
	const unsigned MAX_LENGTH = 256;
	char buffer[MAX_LENGTH];

	while (fgets(buffer, MAX_LENGTH, ptrfile))
	{
		SStudentInfo_t *tempStudent = (SStudentInfo_t*) malloc(sizeof(SStudentInfo_t));
		//printf("%s\n", buffer);
		id = 0;
		i = 4;
		while(buffer[i] != ' ')
		{
			id = id * 10 + ( buffer[i] - '0');
			i++;
		}
		if(FindID(id))
		{
			DPrint("%d This ID is Already Found\n",id);
			continue;
		}
		i += 8;
		j = 0;
		while(buffer[i] != ' ')
		{
			tempStudent->fname[j] =  buffer[i] ;
			i++;
			j++;
		}
		tempStudent->fname[j] = '\0';
		i += 8;
		j = 0;
		while(buffer[i] != '\0')
		{
			tempStudent->lname[j] =  buffer[i] ;
			i++;
			j++;
		}
		tempStudent->lname[j] = '\0';
		tempStudent->ID = id;
		enqueue(StudentFifo_Buf,*tempStudent);
		free(tempStudent);
		if(isFull(StudentFifo_Buf))
			return ;
	}

	fclose(ptrfile);
}




