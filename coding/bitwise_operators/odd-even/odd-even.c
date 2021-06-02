#include<stdio.h>

int main(void)
{
    int n=0;
    scanf("%d",&n);

    if(n&1)
    {
        printf("Odd\n");
    }
    else
    {
        printf("Even\n");
    }
    return 0;
}