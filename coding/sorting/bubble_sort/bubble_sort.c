#include"bubble_sort.h"
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

void bubble_sort(int *array,int size)
{
	int i=0,j=0;

	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(array[j]>array[j+1])
				swap(&array[j],&array[j+1]);
		}
	}
}
