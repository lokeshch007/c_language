#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the miniMaxSum function below.
void miniMaxSum(int arr_count, int* arr) {
    long long int i=0,total_sum=0,min_sum=0,max_sum=0,temp=0;
    for(i=0;i<arr_count;i++)
    {
        total_sum += arr[i];
    }
    printf("%ld total sum\n\n",total_sum);

    min_sum=total_sum-arr[0];
    printf("%ld max sum\n",total_sum);
    max_sum=min_sum;
    printf("%ld max sum\n\n",total_sum);
    for(i=1;i<arr_count;i++)
    {
		temp=total_sum-arr[i];
		printf("temp = %ld\ttotal_sum = %ld\n\n",temp,total_sum);
        if((long long int)temp < (long long int)min_sum)
        {
			printf("%ld  < %ld -->",temp,min_sum);
            min_sum=(long long int)total_sum-arr[i];
		    printf("%ld min\n",total_sum);
        }
        else
        {
        }

        if(temp > max_sum)
        {
            max_sum = total_sum-arr[i];
		    printf("%ld max\n",total_sum);
        }
        else
        {
        }
		printf("\n");
    }
    printf("%ld %ld\n",min_sum,max_sum);

}

int main()
{
    char** arr_temp = split_string(readline());

    int* arr = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int arr_count = 5;

    miniMaxSum(arr_count, arr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

