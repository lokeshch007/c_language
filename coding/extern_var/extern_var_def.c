#include"extern_var_dec.h"

/* remove this definition then, error will raise during linking*/
/*error: undefined reference to var1 in main in text section since no definition is there just declaration in there if removed*/
int var1=10;

int main(void)
{
		printf("exetern_var = %d\n",var1);
		return 0;
}
