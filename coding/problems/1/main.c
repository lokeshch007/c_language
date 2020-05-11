#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int arr_size=0,**array=NULL,trav_1=0,trav_2=0,difference=0;
	printf("Enter size of array: ");
	scanf("%d",&arr_size);
	
	/*Memory allocation for array main address*/
	if(!(array=(int**)malloc(arr_size*sizeof(int*))))
	{
		printf("Insufficient memory\n");
		exit(1);
	}
	else
	{
		/*Mmeory allocation for array elements*/
		for(trav_1=0;trav_1<arr_size;trav_1++)
		{
		    if(!(array[trav_1]=(int*)malloc(arr_size*sizeof(int))))
		    {
			    printf("Insufficient memory\n");
			    exit(1);
		    }
		    else
		    {
		        /*do nothing*/
		    }
		}
		
		/*Matrix reading*/
		printf("Enter array values in order: ");
		for(trav_1=0;trav_1<arr_size;trav_1++)
		{
			for(trav_2=0;trav_2<arr_size;trav_2++)
			{
				scanf("%d",&array[trav_1][trav_2]);
			}
		}				
		
		/*Diagonal difference calculation*/
		for((trav_1=0,trav_2=arr_size-1);(trav_1<arr_size,trav_2>=0);(trav_1++,trav_2--))
		{
			if(!(trav_1^trav_2))/*center value ignoring in odd order matrix*/
			{
				continue;
			}
			else
			{
				difference += array[trav_1][trav_1]-array[trav_1][trav_2];
			}
		}
		
		if(difference<0)
		{
			difference *= -1;
		}
		
		printf("Difference = %d\n",difference);
	}

	/* Freeing allocated memory */
	for(trav_1=0;trav_1<arr_size;trav_1++)
	{
			free(array[trav_1]);
	}
	free(array);
	return 0;
}
