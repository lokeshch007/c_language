#include<stdio.h>

int main(void)
{
		const long int var_int=10L;
		printf("var_int = %ld\n",var_int);
		var_int=20;/* Error will raise during compilation as updating read only variable*/
		printf("var_int = %ld\n",var_int);
		return 0;
}
