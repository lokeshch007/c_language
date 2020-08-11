#include<stdio.h>

static void update_by_1(int *val)
{
	*val=1;
}

int main(void)
{
	int arr[2][2][2]={0};

	update_by_1(&arr[0][0][0]);

	printf("%d\n",arr[0][0][0]);
	return 0;
}
