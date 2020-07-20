#include"linear_search.h"
#include<stdio.h>

int main(void)
{
	int array[5]={5,6,9,7,2};
	int element=0;
	
	printf("Enter element to search: ");
	scanf("%d",&element);
	
	if(linear_search(array,element,5))
		printf("Element found\n");
	else
		printf("Element not found\n");
	
	return 0;
}