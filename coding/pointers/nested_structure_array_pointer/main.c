#include<stdio.h>

typedef struct paper_t
{
	int value[2][2];
}paper_t;

typedef struct papers_t
{
	paper_t left;
	paper_t right;
}papers_t;

typedef union sheet_t
{
	papers_t papers;
	int sheet_map[4][2];
}sheet_t;


static void print_sheet(void);
static void swap(int *val1,int *val2);

sheet_t sheet;

int main(void)
{
	int val=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<2;j++)
			sheet.sheet_map[i][j]=val++;
	}

	print_sheet();
	printf("\n");
	swap(&sheet.papers.left.value[0][0],&sheet.papers.left.value[1][0]);
	print_sheet();
	return 0;
}

static void print_sheet(void)
{
	/* Left paper */
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			printf("%d ",sheet.papers.left.value[i][j]);
		printf("\n");
	}

	printf("\n");
	
	/* Right paper */
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			printf("%d ",sheet.papers.right.value[i][j]);
		printf("\n");
	}

}

static void swap(int *val1,int *val2)
{
	int temp=*val1;
	*val1=*val2;
	*val2=temp;
}


