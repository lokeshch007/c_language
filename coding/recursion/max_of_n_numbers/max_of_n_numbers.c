#include<stdio.h>
#include<stdlib.h>

static int count=0;

int max(int large,int size,int *data);

int main(void)
{
	int num_count=0,trav=0;
	int *n_nums=NULL;

	printf("Give count of numbers: ");
	scanf("%d",&num_count);

	n_nums=(int*)malloc(sizeof(int)*num_count);
	if(!n_nums)
	{
		perror("malloc() call error: ");
		return 1;
	}

	printf("Enter numbers: ");
	while(trav<num_count)
	{
		scanf("%d",n_nums+trav++);
	}
	printf("Read complete\n");
	printf("Maximum of n numbers is : %d\n",max(n_nums[0],num_count,n_nums));
	return 0;
}

int max(int large,int size,int *data)
{
	if(size==1)
	{
		if(large>data[size-1])
			return large;
		else
			return data[size-1];
	}
	if(large<data[size-1])
	{
		return max(data[size-1],size-1,data);
	}
	else
	{
		return max(large,size-1,data);
	}
}
