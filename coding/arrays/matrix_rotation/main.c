#include<stdio.h>
int arr[3][3];

static int print_array(void)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int num=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j] = num++;
        }
    }

print_array();
    return 0;
}