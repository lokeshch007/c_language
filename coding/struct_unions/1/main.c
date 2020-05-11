#include<stdio.h>

typedef struct
{
		int num;
		char c;
		char c2;
		char c3;
		char c4;
		char c5;
}rollno_t;

int main(void)
{
		printf("%ld\n",sizeof(rollno_t));
		return 0;
}

