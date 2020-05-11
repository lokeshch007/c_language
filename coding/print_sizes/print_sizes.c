#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	printf("int : %ld\n",sizeof(int));
	printf("char : %ld\n",sizeof(char));
	printf("float : %ld\n",sizeof(float));
	printf("double : %ld\n",sizeof(double));
	printf("void : %ld\n",sizeof(void));
	return 0;

}

int my_main(void)
{
		printf("my_main() called\n");
		main();
		printf("main() returned\n");
		exit(0);
}
