#include"quick_sort.h"
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


int partition(int *array,int start,int end)
{
	int pivot=start;
	int i=start,j=end;
	int temp;
	while(i<j)
	{
	    while(array[i]<=array[pivot] && i<=end) i++;
	    while(array[j]>array[pivot] && j>=start) j--;
	    if(i<j)/* i didn't passed j*/
	    {
	       temp=array[i];
	       array[i]=array[j];
	       array[j]=temp;
	    }
    	/* swap pivot element to its position that is j position */
	    temp=array[pivot];
	    array[pivot]=array[j];
	    array[j]=temp;
	}
	return j;
}

void quick_sort_internal(int *array,int start,int end)
{
	if(start<end)
	{
		/* Do partition of array with pivot */
		int pivot_index=partition(array,start,end);

		/* Do quick sort for left partition */
		quick_sort_internal(array,start,pivot_index-1);

		/* DO quick sort for right partition */
		quick_sort_internal(array,pivot_index+1,end);
	}
}

void quick_sort(int *array,int size)
{
	quick_sort_internal(array,0,size-1);
}
