#include<stdio.h>

int main(void)
{
		int *ptr=NULL;
		ptr=temp();
		printf("%d\n",*ptr);
		return 0;
}

int temp(void)
{
		int n=10;
		return &n;
}
