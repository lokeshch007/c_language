#include<stdio.h>

double factorial(int num);

int main(void)
{
	int num=0;
	double fact_result=0;

	printf("Calculate factorial for : ");
	scanf("%d",&num);

	fact_result=num*factorial(num-1);
	printf("Factorial of %d is : %0.lf\n",num,fact_result);
	return 0;
}

double factorial(int num)
{
	double m =1;
	if(num>1) m=num*factorial(num-1);
	return m;
}
