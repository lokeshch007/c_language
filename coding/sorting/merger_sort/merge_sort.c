#include"merge_sort.h"
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

void merge(int *array,int l,int m,int r)
{
	printf("merge\n");
	int i,j,k;

	/* Calculcate size of both arrays */
	int size_of_left_array=m-l+1;
	int size_of_right_array=r-m;

	/* Create temporary arrays */
	int temp_left[size_of_left_array];
	int temp_right[size_of_right_array];

	/* Copy data to temp arrays */
	for(i=0;i<size_of_left_array;i++)
		temp_left[i]=array[l+i];
	for(j=0;j<size_of_right_array;j++)
		temp_right[j]=array[m+1+j];

	i=j=0;
	k=l;

	while(i<size_of_left_array && j<size_of_right_array)
	{
		if(temp_left[i]<=temp_right[j])
			array[k]=temp_left[i++];
		else
			array[k]=temp_right[j++];
		k++;
	}

	/* Copy the remaining elements of left array if exists */
	while(i<size_of_left_array)
	{
		array[k]=temp_left[i];
		i++;k++;
	}

	/* Copy the remaining elements of right array if exists */
	while(j<size_of_right_array)
	{
		array[k]=temp_right[j];
		j++;k++;
	}
}

void merge_sort_internal(int *array,int l,int r)
{
	printf("internal\n");
	if(l<r)
	{
		int m=(l+r)/2;

		/* Left half sort */
		merge_sort_internal(array,l,m);
		/* Right half sort */
		merge_sort_internal(array,m+1,r);

		merge(array,l,m,r);
	}
}

void merge_sort(int *array,int size)
{
	merge_sort_internal(array,0,size-1);
}
