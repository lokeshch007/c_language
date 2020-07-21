#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int data;

typedef struct array_sets
{
	int setcount;
	char *set;
}array_sets_t;

static char **array;
static char temp[12],sets=1;
static array_sets_t *sets_array=NULL;
static long int total_permutations=0;
static long int numerator=0,denominator=1;
static int size=0;

long int factorial(int n)
{
	if(!n)
		return 1;
	else 
		return factorial(n-1)*n;
}

void print_array(char **arr,int size)
{
	for(int i=0;i<size;i++)
		printf("%s\t",arr[i]);
	printf("\n");
}

void add_ele_to_array(array_sets_t *arr,int size,char *s)
{
	arr->set=(char*)malloc((strlen(s)+1)*size);
	if(!arr->set)
	{
		printf("relloc() error\n");
		exit(1);
	}

	arr->setcount=size;
	if(size>1)
	{
		for(int i=0,index=0;i<size;i++,index += strlen(s)+1)
			strcpy(arr->set+index,s);
	}
	else
		strcpy(arr->set,s);
}

void swap(char **x,char **y)
{
	char *temp=*x;
	*x=*y;
	*y=temp;
}

void permute(char **a,int l,int r)
{
	int i;
	if(l == r)
		print_array(a,size);
	else
	{
		for(i=l;i <= r; i++)
		{
			swap(&a[l],&a[i]);
			permute(a,l+1,r);
			swap(&a[l],&a[i]);
		}
	}
}

int main(void)
{

	scanf("%d",&size);
	array=(char**)calloc(size,sizeof(char*));
	if(!array)
	{
		perror("calloc() error");
		exit(1);
	}

	printf("Enter array: ");
	for(int i=0;i<size;i++)
	{
		array[i]=(char*)calloc(11,sizeof(char));
		if(!array[i])
		{
			perror("calloc() error");
			exit(1);
		}

		scanf("%s",array[i]);
	}

	print_array(array,size);

	for(int i=1;i<size;i++)
	{
		strcpy(temp,array[i]);
		if(strcmp(temp,array[i-1]) != 0)
		{
			sets++;
		}
	}

	sets_array=(array_sets_t*)malloc(sizeof(array_sets_t)*sets);
	if(!sets_array)
	{
		perror("malloc() error");
		return 1;
	}
	for(int i=0;i<sets;i++)
	{
		sets_array[i].setcount=0;
		sets_array[i].set=NULL;
	}

	
	int sets_array_index=0;
	int same_ele_occur=0;
	for(int i=0;i<size-1;i++)
	{
		strcpy(temp,array[i]);
		if(strcmp(temp,array[i+1]) != 0)/* Not equal */
		{
			if(same_ele_occur>0)
			{
				add_ele_to_array(&sets_array[sets_array_index],same_ele_occur+1,array[i]);
				same_ele_occur=0;
			}
			else
				add_ele_to_array(&sets_array[sets_array_index],1,array[i]);
			sets_array_index++;
		}
		else
		{
			same_ele_occur++;
		}
	}
	if(same_ele_occur>0)
	{
		add_ele_to_array(&sets_array[sets_array_index],same_ele_occur+1,array[size-1]);
		same_ele_occur=0;
	}
	else
	{
		add_ele_to_array(&sets_array[sets_array_index],1,array[size-1]);
	}

	printf("\nUnique sets are : %d\n",sets);
	for(int i=0;i<sets;i++)
	{
		printf("Set[%d] : ",i+1);
		for(int j=0,index=0;j<sets_array[i].setcount;j++,index += strlen(sets_array[i].set+index)+1)
		{
			printf("%s\t",sets_array[i].set+index);
		}
		printf("\n");
	}

	/* Permutations */
	numerator=factorial(size);

	for(int i=0;i<sets;i++)
	{
		denominator *= factorial(sets_array[i].setcount);
	}

	total_permutations=numerator/denominator;
	permute(array,0,size-1);

	return 0;
}
