
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node_t;

extern int list_size;

extern node_t *create_node_memory(void);

extern node_t *list_init(int data);

extern int add_node_position(node_t *root,int position,int data);

extern int delete_node_position(node_t *root,int position);

extern node_t *add_node_at_head(node_t *root,int data);

extern void add_node_at_tail(node_t *root,int data);

extern node_t *delete_node_at_head(node_t *root);

extern void delete_node_at_tail(node_t *root);

extern void print_list(node_t *root);

extern void print_list_full_node(node_t *root);

extern void free_list(node_t *root);
