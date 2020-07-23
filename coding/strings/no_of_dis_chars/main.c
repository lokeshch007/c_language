#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int no_of_dist_chars(const char *a)
{
	char *temp=(char*)calloc(strlen(a)+1,sizeof(char));
	strcpy(temp,a);
	qsort(temp,strlen(temp),sizeof(char),strcmp);
	printf("\n\n%s\n",temp);

	char temp2,sets=1;
	for(int i=1;i<strlen(temp);i++)
	{
		temp2=temp[i];
		if(temp2==temp[i-1])
			sets++;
	}
	return sets;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	char** arr;
	arr = (char**)malloc(n * sizeof(char*));

	for(int i = 0; i < n; i++){
		*(arr + i) = malloc(1024 * sizeof(char));
		scanf("%s", *(arr + i));
		*(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
	}

	return 0;
}

