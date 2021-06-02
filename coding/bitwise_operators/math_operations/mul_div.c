#include<stdio.h>

int main(void)
{
    int a= 0,b=0,c=0;
    scanf("%d",&a);

    b = (a >> 2) - (a >> 1);/* divide by 5*/
    c = (a << 2) + a;
    printf("%d  %d\n",b,c);
    return 0;
}