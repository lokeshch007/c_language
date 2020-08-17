#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[20] = "F U R Ui Ri Fi";
    char *token;

    token = strtok(str," ");
    while(token != NULL)
    {
        printf("%s\n",token);
        token = strtok(NULL," ");
    }

    return 0;
}