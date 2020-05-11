#include<stdio.h>

enum valentine
{
		rose1=0xFFFFFFFF,
		rose2
};

int main(void)
{
		printf("valentine size: %d\n",sizeof(enum valentine));

		return 0;
}
