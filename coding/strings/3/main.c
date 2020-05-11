#include<stdio.h>
#include<stdlib.h>

char* scan_string_dynamic(void)
{
		char *str=NULL,c;
		str=(char*)malloc(sizeof(char));
		while(((c=getchar()) != EOF) && (c != '\n'))
		{
				str=
		}
		return str;
}

int main(void)
{
		char *str;
		printf("Enter string: ");
		scanf("%s",str);
		printf("%s",str);
		return 0;
}
