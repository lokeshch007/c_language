#include"linear_search.h"

int linear_search(int *array,int element,int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		if(!(array[i]^element))
			return 1;
	}
	return 0;
}