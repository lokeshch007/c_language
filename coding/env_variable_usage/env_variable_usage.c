#include<stdio.h>

int main(int argc, char *argv[], char *envp[])
{
		int i=00;
		for(i=0;envp[i]!=NULL;i++)
		{
				puts(envp[i]);
		}
		return 0;
}
