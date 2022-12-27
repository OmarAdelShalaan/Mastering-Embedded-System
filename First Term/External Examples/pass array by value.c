/*
pass_arr_by_value with using struct
*/
#include<stdio.h>

struct SArr{
	int arr[5];
};

void pass_arr_by_value(struct SArr arr_st)
{
    int i = 0;
    for(; i < 5; i++)
    {
        printf("%d ",i[arr_st.arr]);
    }
}

int main()
{
	struct SArr arr_st;
	printf("sizeof struct:  %d\n",sizeof(arr_st));
	arr_st.arr[0] = 1;
	arr_st.arr[1] = 2;
	arr_st.arr[2] = 3;
	arr_st.arr[3] = 4;
	arr_st.arr[4] = 5;
	pass_arr_by_value(arr_st);
	return 0;
}