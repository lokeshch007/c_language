#include"insertion_sort.h"
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

void insertion_sort(int *array,int size)
{
	int i=0,j=0;
	int temp=0;
	for(i=1;i<size;i++)
	{
		temp=array[i];
		j=i-1;

		while(j>=0 && array[j]>temp)
		{
			array[j+1]=array[j];
			j=j-1;
		}
		array[j+1]=temp;
	}

}
