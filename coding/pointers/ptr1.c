#include<stdio.h>

int main(void)
{
		int i=65;
		int *iptr=NULL;
		iptr=&i;
		printf("%c\n",*iptr);
		printf("%u\n",*(iptr+1));
		return 0;
}
