#include<stdio.h>
#include<stdlib.h>

int main(void)
{
		char ch;
		FILE *fp=fopen("file.txt","w");
		if(fp==NULL)
		{
				printf("Unsuccesfull file opening\n");
				exit(1);
		}
		else
		{
				/*while((ch=getchar()) != EOF)*/
				while((ch=fgetc(stdin)) != EOF)
				{
						fputc(ch,fp);
				}
		}
		fclose(fp);

		fp=fopen("file.txt","r");
		while((ch=(unsigned char)fgetc(fp)) != EOF)
		{
				fputc(ch,stdout);
		}
		fclose(fp);
		return 0;
}

