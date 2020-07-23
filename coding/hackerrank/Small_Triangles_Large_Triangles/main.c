#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	 * Sort an array a of the length n
	 */
	double areas[100]={0.0};
	double p;
	double inside_squrt=1;
	for(int i=0;i<n;i++)
	{
		p=(tr[i].a+tr[i].b+tr[i].c)/(2.0);
		inside_squrt=(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
		areas[i]=sqrt(inside_squrt);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(areas[j]<areas[i])
			{
				/* Swap areas */
				int temp = tr[j].a;
				tr[j].a=tr[i].a;
				tr[i].a=temp;

				temp = tr[j].b;
				tr[j].b=tr[i].b;
				tr[i].b=temp;

				temp = tr[j].c;
				tr[j].c=tr[i].c;
				tr[i].c=temp;

				double temp2=areas[j];
				areas[j]=areas[i];
				areas[i]=temp2;
			}
		}
	}

}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
