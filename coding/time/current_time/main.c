#include<time.h>
#include<stdio.h>

int main(void)
{
    time_t rawtime;
    struct tm *timeinfo;

    char output[20];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    sprintf(output, "%d %d %d %d:%d:%d",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    printf("%s\n",output);
    return 0;
}