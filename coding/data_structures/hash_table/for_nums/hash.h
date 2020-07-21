
extern int table_size;

typedef struct entry_t
{
	char *key;
	int value;
	struct entry_t *next;
}entry_t;

typedef struct
{
	entry_t **entries;
}ht_t;

extern unsigned int hash(const char *key);

extern ht_t *ht_create(int size);

extern entry_t* ht_pair(const char *key,const int value);

extern void ht_set(ht_t *hashtable,const char *key,const int value);

extern int ht_get(ht_t *hashtable,const char *key);

extern void ht_dump(ht_t *hashtable);
