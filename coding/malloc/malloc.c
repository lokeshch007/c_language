#include<stdio.h>
#include<stdlib.h>

int main(void)
{
		int *ptr=NULL;
		ptr=(int*)malloc(sizeof(int));
		*ptr=10;
		printf("%d\n",*ptr);
//		free(ptr);
		return 0;
}
