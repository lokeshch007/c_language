#include<stdio.h>
#include<string.h>

int main(void)
{
	char input[3];
	scanf("%s",input);

	switch(input[0])
	{
		case 'R':
			if(input[1]=='i')
				printf("Ri\n");
			else
				printf("R\n");
			break;

		default:
			printf("0\n");
			break;
	}
	return 0;
}
