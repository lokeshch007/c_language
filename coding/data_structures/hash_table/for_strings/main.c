#include"hash.h"
#include<stdio.h>

int main(void)
{
	ht_t *ht=ht_create(); 
	ht_set(ht,"no1","one");
	ht_set(ht,"no2","two");
	ht_set(ht,"no3","three");
	ht_set(ht,"no4","four");
	ht_set(ht,"no5","five");
	ht_set(ht,"no6","six");
	ht_set(ht,"no7","seven");
	ht_set(ht,"no8","eight");
	ht_set(ht,"no9","nine");
	ht_set(ht,"no10","ten");

	ht_dump(ht);
	return 0;
}
