/* Transpose means make rows as columns, columns as rows */
#include<stdio.h>

#define N 3

int arr[N][N];

static void print_array(void);
static void transpose(void);
static void swap(int *val1,int *val2);
static void rotate_90(void);

int main(void)
{
	int num=1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			arr[i][j] = num++;
		}
	}

	print_array();
	printf("\n");

	rotate_90();

	print_array();
	printf("\n");

	return 0;
}

static void print_array(void)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}

static void transpose(void)
{
	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			swap(&arr[i][j],&arr[j][i]);
		}
	}

}
static void swap(int *val1,int *val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

static void rotate_90(void)
{
	transpose();

	/* Reverse rows elements */
	for(int i=0;i<N;i++)
	{
		for(int j=0,k=N-1; (j<k); j++,k--)
			swap(&arr[j][i],&arr[k][i]);
	}
}
