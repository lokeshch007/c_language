#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
	if(a[0]<b[0])
		return -1;
	else if(a[0]>b[0])
		return 1;
	else {
		if(strlen(a)<=0)
			return 0;
		return lexicographic_sort(a+1, b+1);
	}
}

int lexicographic_sort_reverse(const char* a, const char* b) {
	if(a[0]<b[0])
		return 1;
	else if(a[0]>b[0])
		return -1;
	else {
		if(strlen(a)<=0)
			return 0;
		return lexicographic_sort_reverse(a+1, b+1);
	}
}


int no_of_dist_chars(const char *a)
{
	char *temp=(char*)calloc(strlen(a)+1,sizeof(char));
	strcpy(temp,a);
	qsort(temp,strlen(temp),sizeof(char),strcmp);

	char temp2,sets=1;
	for(int i=1;i<strlen(temp);i++)
	{
		temp2=temp[i];
		if(temp2==temp[i-1])
			sets++;
	}
	printf("----------------%s:%d:%d\n",a,strlen(a),sets);
	return sets;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
	int a_count=0,b_count=0;
	/*printf("%d\n",no_of_dist_chars(a)-no_of_dist_chars(b));*/
	return (no_of_dist_chars(a)-no_of_dist_chars(b));
}

int sort_by_length(const char* a, const char* b) {
	if(strlen(a)<strlen(b))
		return -1;
	else if(strlen(a)>strlen(b))
		return 1;
	else 
		return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
	char *temp=NULL;
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(cmp_func(arr[j],arr[i])<0)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
			else if(cmp_func(arr[j],arr[i])==0)
			{
				if(lexicographic_sort(arr[j], arr[i])<0)
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
	}
}


int main() 
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

	string_sort(arr, n, lexicographic_sort);
	for(int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, lexicographic_sort_reverse);
	for(int i = 0; i < n; i++)
		printf("%s\n", arr[i]); 
	printf("\n");

	string_sort(arr, n, sort_by_length);
	for(int i = 0; i < n; i++)
		printf("%s\n", arr[i]);    
	printf("\n");

	string_sort(arr, n, sort_by_number_of_distinct_characters);
	for(int i = 0; i < n; i++)
		printf("%s\n", arr[i]); 
	printf("\n");
}
