#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char **arr=NULL;
	int count=3;
	arr=(char**)calloc(count,sizeof(char*));
	if(!arr)
	{
		perror("calloc() error");
		exit(1);
	}

	printf("Enter strings: ");
	for(int i=0;i<count;i++)
	{
		arr[i]=(char*)calloc(11,sizeof(char));
		if(!arr[i])
		{
			perror("calloc() error");
			exit(1);
		}
		scanf("%s",arr[i]);
	}

	for(int i=0;i<count;i++)
	{
		printf("%s\n",arr[i]);
		free(arr[i]);
	}
	return 0;
}
