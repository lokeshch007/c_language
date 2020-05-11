#include<stdio.h>

int main(void)
{
		int a[5]={1,2,3,4,5};
		int i=0,temp=0;
		int count=0;

		printf("Count of rotation: ");
		scanf("%d",&count);
		while(count>0)
		{
				i=0;
				temp=a[0];
				while(i<5)
				{
						if(i==4)
						{
								a[0] += temp;
								temp=a[0]-temp;
								a[0] -= temp;
								break;
						}
						a[i+1] += temp;
						temp=a[i+1]-temp;
						a[i+1] -= temp;
						i++;
						printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
				}
				count--;
				printf("\n");
		}

		printf("\n\n%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
		return 0;
}
