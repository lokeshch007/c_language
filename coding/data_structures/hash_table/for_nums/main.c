#include"hash.h"
#include<stdio.h>

int main(void)
{
	ht_t *ht=ht_create(5); 
	ht_set(ht,"no1",1);
	ht_set(ht,"no2",2);
	ht_set(ht,"no3",3);
	ht_set(ht,"no4",2);
	ht_set(ht,"no5",2);
	ht_set(ht,"no6",6);
	ht_set(ht,"no7",7);
	ht_set(ht,"no8",8);
	ht_set(ht,"no9",6);
	ht_set(ht,"no10",10);

	ht_dump(ht);
	return 0;
}
