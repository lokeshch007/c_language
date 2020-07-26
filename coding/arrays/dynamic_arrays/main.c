#include<stdio.h>
#include<stdlib.h>

typedef struct temp
{
	int p;
}temp;

int main(void)
{
	temp *ptr=NULL;

	ptr=(temp*)realloc(ptr,sizeof(temp));
	(ptr+0)->p=10;
	return 0;
}
