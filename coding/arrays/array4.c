#include<stdio.h>

int main(void)
{
		int arr[]={1,1,1};
		int i=0;
		for(i=0;i<3;i++)
		{
				arr[i]=20;
				printf("%d\t",*(arr+i));
		}
		printf("\n%u\t%u\n",&arr,&arr+1);
		return 0;
}
