#include"quick_sort.h"
#include<stdio.h>


static void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
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


int partition(int *array,int low,int high)
{
	int pivot=array[high];
	int i=low-1;

	for(int j=low;j<=high-1;j++)
	{
		if(array[j]<pivot)/* i didn't passed j*/
		{
			i++;
			swap(&array[i],&array[j]);
		}
		/* swap pivot element to its position that is j position */
		//			print_array(array,10);
	}
	swap(&array[i+1],&array[high]);
	return i+1;
}

void quick_sort_internal(int *array,int low,int high)
{
	if(low<high)
	{
		/* Do partition of array with pivot */
		int pivot_index=partition(array,low,high);

		/* Do quick sort for left partition */
		quick_sort_internal(array,low,pivot_index-1);

		/* DO quick sort for right partition */
		quick_sort_internal(array,pivot_index+1,high);
	}
}

void quick_sort(int *array,int size)
{
	quick_sort_internal(array,0,size-1);
}
