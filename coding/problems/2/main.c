#include<stdio.h>

int main(void)
{
		int jack[4]={2,3,4,5};
		int *rose=jack+3;
		printf("%d %d\n",rose[-2],jack[*rose]);
		return 0;
}
