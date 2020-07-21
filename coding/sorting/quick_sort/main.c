#include"quick_sort.h"
#include<stdio.h>

int main(void)
{
	int array[]={8,6,8,1,2,6,7,7,6,3};
	int size=10;

	print_array(array,size);

	quick_sort(array,size);

	print_array(array,size);
	return 0;
}
