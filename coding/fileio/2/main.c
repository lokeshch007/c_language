#include<stdio.h>
#include<stdlib.h>

int main(void)
{
		FILE *fp=fopen("file.txt","a+");
		char str[20];
		fgets(str,sizeof(str),stdin);
		fputs(str,fp);
		return 0;
}
