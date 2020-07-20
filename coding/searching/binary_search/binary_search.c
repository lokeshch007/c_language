#include"binary_search.h"
#include"quick_sort.h"
#include<stdio.h>
#include<stdlib.h>

static int array_size=0;
static int *temp_array=NULL;

static int free_temp_array(void)
{
	free(temp_array);
}

static int binary_search_internal(int *array,int element,int low_index,int high_index)
{
	int mid=(low_index+high_index)/2;
	if(low_index<0 || low_index>=array_size || high_index<0 || high_index>=array_size)
	{
		free_temp_array();
		return 0;	
	}
	if(!(array[mid]^element))
	{
		free_temp_array();
		return 1;
	}
	else if(element > array[mid])
		return binary_search_internal(temp_array,element,mid+1,high_index);
	else if(element < array[mid])
		return binary_search_internal(temp_array,element,0,mid-1);
}


int binary_search(int *array,int element,int size)
{
	int i=0;
	array_size=size;
	temp_array=malloc(sizeof(int)*size);
	if(!temp_array)
	{
		printf("malloc() error");
		return -1;
	}
	for(i=0;i<size;i++)
	{
		temp_array[i]=array[i];
	}
	
	quick_sort(temp_array,size);
	if(binary_search_internal(temp_array,element,0,size-1))
		return 1;
	else 
		return 0;
}
