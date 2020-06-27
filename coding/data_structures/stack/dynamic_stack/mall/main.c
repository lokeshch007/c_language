#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int *ptr=NULL;
	int *temp;
	ptr=(int*)malloc(3*sizeof(int));
	*ptr=10;
	*(ptr+1)=20;
	*(ptr+2)=30;
	*(ptr+4)=40;
	temp=ptr;

	printf("ptr=%u\n",ptr);
	printf("temp=%u\n",temp);
	free(ptr);
	printf("ptr=%u\n",ptr);
	printf("temp=%u\n",temp);
	*ptr=10;
	*(ptr+1)=20;
	*(ptr+2)=30;

	printf("ptr[4] = %d\n",ptr[4]);
	return 0;
}
