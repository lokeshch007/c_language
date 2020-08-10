#include<stdio.h>

static void update_by_1(int (*b)[2][2])
{
	**b[0]=1;
}

int main(void)
{
	int arr[2][2][2]={0};

	update_by_1(arr);

	printf("%d\n",arr[0][0][0]);
	return 0;
}
