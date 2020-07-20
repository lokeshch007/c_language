#include"selection_sort.h"
#include<stdio.h>


static void swap(int *x,int *y)
{
	*x=*x+*y;
	*y=*x-*y;
	*x=*x-*y;
}

void print_array(int *array,int size)
{
	int i=0;
	if(size<0)
	{
		printf("print_array(): Invalid size of array\n");
		return;
	}
	for(i=0;i<size;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
}

void selection_sort(int *array,int size)
{
	int i=0,j=0;
	int i_min=0;
	int sort_flag=0;

	for(i=0;i<size-1;i++)
	{
		i_min=i;
		for(j=i+1;j<size;j++)
		{
			if(array[j]<array[i_min])
			{
				i_min=j;
				sort_flag=1;
			}
		}
		if(sort_flag)
			swap(&array[i_min],&array[i]);
		sort_flag=0;
		printf("\n");
	}
}
