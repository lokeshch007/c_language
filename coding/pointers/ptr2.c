#include<stdio.h>

int main(void)
{
		void *vptr=NULL;
		int i=300;
		vptr=&i;
		printf("%d\n",(int*)vptr);
		printf("%d\n",(char*)vptr);
		(char*)vptr++;
		printf("%d\n",(char*)vptr);
		return 0;
}
