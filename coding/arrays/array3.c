#include<stdio.h>

int main(void)
{
		int arr[3]={1};
		int i=0;
		for(i=0;i<3;i++)
		{
				printf("%d\t",*(arr+i));
		}
		printf("\n");
		return 0;
}
