#include<stdio.h>
#include<stdlib.h>

int main(void)
{
		int **pptr=NULL,i=0,n=3,j=0;
		if((pptr=(int**)malloc(n*sizeof(int*))) == NULL)
		{
				exit(1);
		}
		for(i=0;i<n;i++)
		{
				if((pptr[i]=(int*)malloc(n*sizeof(int))) == NULL)
				{
						exit(1);
				}
		}

		for(i=0;i<n;i++)
		{
				for(j=0;j<n;j++)
				{
						(pptr[i]!= NULL) ? pptr[i][j]=2 : printf("Memory not allocated\n");
				}
		}

		for(i=0;i<n;i++)
		{
				for(j=0;j<n;j++)
				{
						(pptr[i] != NULL) ? printf("%d\t",pptr[i][j]) : printf("Memory not allocated\n");
				}
				printf("\n");
		}

		/* free */
		for(i=0;i<n;i++)
		{
				free(pptr[i]);
		}
		free(pptr);
		return 0;
}
