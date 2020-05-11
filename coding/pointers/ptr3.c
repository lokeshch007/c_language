#include<stdio.h>

int main(void)
{
		int *iptr=NULL,**ipptr=NULL,i=65;
		iptr=&i;
		ipptr=&iptr;
		printf("%d\n%d\n",*iptr,**ipptr);
		return 0;
}
