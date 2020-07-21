
#define TABLE_SIZE 2

typedef struct entry_t
{
	char *key;
	char *value;
	struct entry_t *next;
}entry_t;

typedef struct
{
	entry_t **entries;
}ht_t;

extern unsigned int hash(const char *key);

extern ht_t *ht_create(void);

extern entry_t* ht_pair(const char *key,const char *value);

extern void ht_set(ht_t *hashtable,const char *key,const char *value);

extern char *ht_get(ht_t *hashtable,const char *key);

extern void ht_dump(ht_t *hashtable);
