#include<stdio.h>

int main(void)
{
		char str[5],*sptr=str;
		printf("Enter string:");
		scanf("%[^\n]s",str);
		printf("%s\n",str);
		return 0;
}
