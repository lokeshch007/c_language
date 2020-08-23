#include <time.h>
#include <stdio.h>
#include<stdlib.h>

int main(void)
{
    time_t rawtime;
    struct tm *timeinfo;

    char time_val[20];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    sprintf(time_val, "%d%d%d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    int opt = atoi(time_val) % 5;
    printf("%s\n%d\n", time_val,opt);
    return 0;
}
