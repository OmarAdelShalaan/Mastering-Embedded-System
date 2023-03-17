#include <stdio.h>
#include <stdlib.h>
//#include<string.h>


struct SData
{
    char ID;
    char name[40];
    float heigth;
};

struct SStudent
{
    struct SData student;
    struct SStudent * pNextStudent;
};

struct SStudent * gpFirstStudent = NULL;


void FillSudentStruct(struct SStudent * Student)
{
    printf("Enter Your Name: ");
    scanf("%s",Student->student.name);
    printf("Enter Your ID: ");
    scanf("%d",&Student->student.ID);
    printf("Enter Your Heigth: ");
    scanf("%f",&Student->student.heigth);
}
void AddStudent()
{
    struct SStudent * ptrStudent = gpFirstStudent;
    struct SStudent * newStudent = (struct SStudent *)malloc(sizeof(struct SStudent));
    if(!newStudent)
    {
        printf("Struct Not Save \n");
        return;
    }
    if( gpFirstStudent ) // gpFirstStudent != NULL
    {
        while( ptrStudent->pNextStudent)
        {
            ptrStudent = ptrStudent->pNextStudent;
        }
        ptrStudent->pNextStudent = newStudent;
    }
    else // gpFirstStudent == NULL
    {
        gpFirstStudent = newStudent;
    }
    newStudent->pNextStudent = NULL;
    FillSudentStruct(newStudent);
}
void PrintStudentData(struct SStudent * Student)
{
    printf("\nStudent Name: %s\n",Student->student.name);
    printf("Student ID: %d\n",Student->student.ID);
    printf("Student Heigth: %.1f\n",Student->student.heigth);
}
void DisplayListSudent()
{
    struct SStudent * ptrStudent = gpFirstStudent;
    if(gpFirstStudent)
    {
        while(ptrStudent)
        {
            PrintStudentData(ptrStudent);
            ptrStudent = ptrStudent->pNextStudent;
        }

    }
    else
    {
        printf("\nList Is Empty\n");
    }

}

int CountStudentList()
{
    struct SStudent * ptrStudent = gpFirstStudent;
    int count = 0;
    if(!ptrStudent)
    {
        printf("\nList IS Empty\n");
        return;
    }
    while(ptrStudent)
    {
        count++;
        ptrStudent = ptrStudent->pNextStudent;

    }
    printf("\nNumber Student In List: %d\n",count);
    return count;
}
void DeleteStudent()
{
    struct SStudent * ptrCurrentStudent = gpFirstStudent;
    struct SStudent * ptrPreviousStudent = NULL;
    int id;
    printf("\nEnter Student ID will Delete: ");
    scanf("%d",&id);
    if(!ptrCurrentStudent)
    {
        printf("\nDeleteStudent Fun");
        printf("\nList IS Empty\n");
        return;
    }
    if(ptrCurrentStudent->student.ID == id)
    {
        gpFirstStudent = gpFirstStudent->pNextStudent;
        free(ptrCurrentStudent);
        return;
    }
    /*
    **************************************************************
    */
    while(ptrCurrentStudent)
    {
        if( ptrCurrentStudent->student.ID == id)
        {
            ptrPreviousStudent->pNextStudent = ptrCurrentStudent->pNextStudent;
            free(ptrCurrentStudent);
            return;
        }
        ptrPreviousStudent = ptrCurrentStudent;
        ptrCurrentStudent = ptrCurrentStudent->pNextStudent;
    }
    printf("\nID Not Found\n");
    return;
}

void DeleteAllStudent()
{
    struct SStudent * ptrStudent = gpFirstStudent;
    if(!ptrStudent)
    {
        return;
    }
    while(ptrStudent)
    {
        struct SStudent * ptr = ptrStudent;
        ptrStudent = ptrStudent->pNextStudent;
        free(ptr);
    }
    gpFirstStudent = NULL;
    printf("\nDone Delete All Student List\n");
}
void StudentFromEndWithLengthMethod(int countFromEnd )
{
    if(!gpFirstStudent)
        return;
    struct SStudent * ptrStudent = gpFirstStudent;
    //int countFromEnd;
    int count = 0,len;
    //printf("\nEnter Num Student from End: ");
    //scanf("%d",&countFromEnd);
    len = CountStudentList();
    printf("\nUsing Length of List\n");
    if(countFromEnd >= len)
    {
        printf("\nYour Number Out of Range \n");
        return;
    }
    while( count != (len - countFromEnd - 1))
    {
        count++;
        ptrStudent = ptrStudent->pNextStudent;
    }
    PrintStudentData(ptrStudent);
    printf("\nDone Using Length of List\n");
}
void StudentFromEndWithMainReferenceMethod(int countFromEnd)
{
    printf("\nUsing Main Reference Method \n");
    if(!gpFirstStudent)
        return;
    struct SStudent * ptrMainStudent = gpFirstStudent;
    struct SStudent * ptrReferenceStudent = gpFirstStudent;
    while(countFromEnd)
    {
        if(!ptrReferenceStudent)
        {
            printf("\nOut OF Range\n");
            return;
        }
        ptrReferenceStudent = ptrReferenceStudent->pNextStudent;
        countFromEnd--;
    }
    while(ptrReferenceStudent)
    {
        if(!ptrReferenceStudent->pNextStudent)
        {
            PrintStudentData(ptrMainStudent);
            break;
        }
        ptrReferenceStudent = ptrReferenceStudent->pNextStudent;
        ptrMainStudent = ptrMainStudent->pNextStudent;
    }
    printf("\nDone Using Main Reference Method \n");
    return;
}
void StudentFromEnd()
{
    int countFromEnd;
    printf("\nEnter Num Student from End: ");
    scanf("%d",&countFromEnd);
    StudentFromEndWithLengthMethod(countFromEnd);
    printf("\n\n");
    StudentFromEndWithMainReferenceMethod(countFromEnd);
    printf("\n\n");
}

void ReverseStudentList()
{
    struct SStudent * ptrCurrentStudent = gpFirstStudent;
    struct SStudent * ptrPreviousStudent = NULL;
    struct SStudent * ptrNextStudent = NULL;
    if(!ptrCurrentStudent || !ptrCurrentStudent->pNextStudent )
        return;
    ptrPreviousStudent = ptrCurrentStudent;
    ptrNextStudent = ptrCurrentStudent->pNextStudent;
    while(ptrNextStudent)
    {
        ptrCurrentStudent = ptrNextStudent;
        ptrNextStudent = ptrNextStudent->pNextStudent;
        ptrCurrentStudent->pNextStudent = ptrPreviousStudent;
        ptrPreviousStudent = ptrCurrentStudent;
    }
    gpFirstStudent->pNextStudent = NULL;
    gpFirstStudent = ptrCurrentStudent;
    printf("\nDone Reverse Student List\n");
}

void DataStudentIndex()
{
    struct SStudent * ptrStudent = gpFirstStudent;
    int index;
    int count = 0;
    printf("\nEnter Index of Student: ");
    scanf("%d",&index);
    index--;
    if(!ptrStudent)
    {
        printf("\nList IS Empty\n");
        return;
    }
    while(count != index)
    {
        count++;
        ptrStudent = ptrStudent->pNextStudent;
    }
    PrintStudentData(ptrStudent);
}

void MiddleStudentInListSlowFastMethod()
{
    printf("\nMiddle Student in List\n");
    struct SStudent * ptrSlowStudent = gpFirstStudent->pNextStudent;
    struct SStudent * ptrFastStudent = gpFirstStudent->pNextStudent->pNextStudent;
    if(!gpFirstStudent)
    {
        printf("\nList IS Empty\n");
        return;
    }
    if(!ptrSlowStudent)
    {
        PrintStudentData(gpFirstStudent);
        return;
    }
    while(ptrFastStudent && ptrSlowStudent )
    {
        if(!ptrFastStudent->pNextStudent)
        {
            break;
        }
        ptrFastStudent = ptrFastStudent->pNextStudent->pNextStudent;
        ptrSlowStudent = ptrSlowStudent->pNextStudent;
    }

    PrintStudentData(ptrSlowStudent);
}
int StartApp()
{
    int choose;
    printf("\n================================\n");
    printf("Choose on of the following Options \n");
    printf("1: Add Student\n");//Done
    printf("2: Delete Student\n");//Done
    printf("3: View Student\n");//Done
    printf("4: Delete All\n");//Done
    printf("5: Reverse Student List\n");//Done
    printf("6: Counter Student In List\n");//Done
    printf("7: Number of Student In List From End \n");//Done
    printf("8: Middle Student in List\n");//Done==>
    printf("9: Data Student of Index\n");//Done
    printf("Enter Option Number: ");
    scanf("%d",&choose);
    if(!(choose >= 1 && choose <= 9))
        choose = StartApp();


    printf("\n================================\n");
    return choose;
}


int main()
{
    int choose;
    while(1)
    {
        choose = StartApp();
        switch(choose)
        {
        case 1:
            AddStudent();
            break;
        case 2:
            DeleteStudent();
            break;
        case 3:
            DisplayListSudent();
            break;
        case 4:
            DeleteAllStudent();
            break;
        case 5:
            ReverseStudentList();
            break;
        case 6:
            CountStudentList();
            break;
        case 7:
            StudentFromEnd();
            break;
        case 8:
            MiddleStudentInListSlowFastMethod();
            break;
        case 9:
            DataStudentIndex();
            break;
        default:
            printf("\n  Wrong  Choose\n");
            break;
        }

    }
    return 0;
}
