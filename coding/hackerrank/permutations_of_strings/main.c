#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	int k,l;

	/* 1.Find largest index k such that s[k]<s[k+1] */
	/* Since k need to be compared with k+1, k init value
	 should be n-2*/
	for(k=n-2;k>=0;k--)
	{
		if(strcmp(s[k],s[k+1])<0) break;
	}
	/* if no index found as s[k]<s[k+1] then no more permutations exists */
	if(k<0) return 0;

	/* 2.Find the largest index l>k such that s[k]<s[l] */
	for(l=n-1;l>k;l--)
	{
		if(strcmp(s[k],s[l])<0) break;
	}

	/* 3. Swap s[k],s[l] */
	char* temp=s[k];
	s[k]=s[l];
	s[l]=temp;

	/* 4. Reverse the remaining elements after s[k+1] to end s[n-1] */
	for(int i=k+1,j=n-1;i<j;i++,j--)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}
	/* Next permutation found and updated in string */
	return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
