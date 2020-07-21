#include"quick_sort.h"
#include<stdio.h>
#include<stdlib.h>

static int data;

typedef struct array_sets
{
	int setcount;
	int *set;
}array_sets_t;

void add_ele_to_array(array_sets_t *arr,int size,int ele)
{
	arr->set=(int*)malloc(sizeof(int)*size);
	if(!arr)
	{
		printf("relloc() error\n");
		exit(1);
	}

	arr->setcount=size;
	if(size>1)
	{
		for(int i=0;i<size;i++)
			arr->set[i]=ele;
	}
	else
		arr->set[0]=ele;
}

int main(void)
{
	int array[10];
	int size=10;

	printf("Enter array: ");
	for(int i=0;i<size;i++)
		scanf("%d",array+i);

	print_array(array,size);
	quick_sort(array,size);

	int temp,sets=1;
	for(int i=1;i<size;i++)
	{
		temp=array[i];
		if(temp^array[i-1])
		{
			sets++;
		}
	}

	array_sets_t *sets_array=(array_sets_t*)malloc(sizeof(array_sets_t)*sets);
	if(!sets_array)
	{
		perror("malloc() error");
		return 1;
	}
	for(int i=0;i<sets;i++)
	{
		sets_array[i].setcount=0;
		sets_array[i].set=NULL;
	}

	int sets_array_index=0;
	int same_ele_occur=0;
	for(int i=0;i<size-1;i++)
	{
		temp=array[i];
		if(temp^array[i+1]) /* Not equal */
		{
			if(same_ele_occur>0)
			{
				add_ele_to_array(&sets_array[sets_array_index],same_ele_occur+1,array[i]);
				same_ele_occur=0;
			}
			else
				add_ele_to_array(&sets_array[sets_array_index],1,array[i]);
			sets_array_index++;
		}
		else
		{
			same_ele_occur++;
		}
	}
	if(same_ele_occur>0)
	{
		add_ele_to_array(&sets_array[sets_array_index],same_ele_occur+1,array[size-1]);
		same_ele_occur=0;
	}
	else
	{
		add_ele_to_array(&sets_array[sets_array_index],1,array[size-1]);
	}

	printf("\nUnique sets are : %d\n",sets);
	for(int i=0;i<sets;i++)
	{
		printf("Set[%d] : ",i+1);
		for(int j=0;j<sets_array[i].setcount;j++)
		{
			printf("%d\t",sets_array[i].set[j]);
		}
		printf("\n");
	}


	return 0;
}
