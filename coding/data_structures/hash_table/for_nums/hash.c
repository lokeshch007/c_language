#include"hash.h"
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

/* free() for hash table is not yet implemented */

int table_size=0;

unsigned int hash(const char *key)
{
	unsigned long int value = 0;
	unsigned int i = 0;
	unsigned int key_len = strlen(key);

	for(i=0;i<key_len;i++)
	{
		value = value +37+key[i];
	}

	value = value % table_size;

	return value;
}

ht_t *ht_create(int size)
{
	ht_t *hashtable = (ht_t*)malloc(sizeof(ht_t)*1);

	table_size=size;

	hashtable->entries = (entry_t**)malloc(sizeof(entry_t)*table_size);

	int i = 0;
	for(;i<table_size;i++)
	{
		hashtable->entries[i]=NULL;
	}

	return hashtable;
}

entry_t* ht_pair(const char *key,const int value)
{
	entry_t *entry=malloc(sizeof(entry));
	entry->key=(char*)malloc(strlen(key)+1);

	strcpy(entry->key,key);
	entry->value=value;

	entry->next=NULL;

	return entry;
}

void ht_set(ht_t *hashtable,const char *key,const int value)
{
	/* Get the hash code for the key */
	unsigned int slot = hash(key);

	/* Get the entry address for got hashcode of key */
	entry_t* entry = hashtable->entries[slot];

	/* Check if slot it empty, if yes create and insert key and pair in it */
	if(!entry)
	{
		hashtable->entries[slot]=ht_pair(key,value);
		return ;
	}

	entry_t *prev;
	/* Entry is not empty so two cases */
	/* 1. the entry slot has some value already
	 we check if given key is same which exists and update if yes*/
	while(entry)
	{
		/* If key found */
		if(!strcmp(entry->key,key))
		{
			/* Update the new value for the key */
			entry->value=value;
			return;
		}

		/* Move to next in the list */
		prev = entry;
		entry=entry->next;

	}
	/*2. End of list reached without a match, add new at end of list */
	prev->next = ht_pair(key,value);
}

int ht_get(ht_t *hashtable,const char *key)
{
	unsigned int slot = hash(key);

	entry_t *entry=hashtable->entries[slot];

	/* Slot entry is empty */
	if(!entry)
	{
		printf("slot entry is empty");
		return -1;
	}

	while(entry)
	{
		/* IF key found?*/
		if(!strcmp(entry->key,key))
		{
			/* Return its value */
			return entry->value;
		}
		entry=entry->next;
	}

	/* No key found */
	printf("Key not found");
	return -1;
}

void ht_dump(ht_t *hashtable)
{
	entry_t *entry=NULL;
	int i=0;
	for(i=0;i<table_size;i++)
	{
		entry=hashtable->entries[i];
		if(!entry)
			continue;

		printf("slot[%3d] : ",i);

		/* Traverse untill end of each entry */
		/* Multiple key,value pairs might be there for same slot */
		while(1)
		{
			printf("%s=%d ",entry->key,entry->value);
			if(!entry->next)
				break;/*no next pair found*/
			entry=entry->next;
		}
		printf("\n");
	}
}






