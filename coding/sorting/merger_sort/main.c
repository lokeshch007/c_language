#include"merge_sort.h"
#include<stdio.h>

int main(void)
{
	int array[]={9,2,-66,10,125,66};
	int size=6;

	print_array(array,size);

	merge_sort(array,size);

	print_array(array,size);
	return 0;
}
