typedef struct
{
	int data;
	single_node_t *next_node_addr;
}single_node_t;

extern int add_node(single_node_t*,int);

extern int delete_node(single_node_t*,int);

extern void print_list(single_node_t*);

