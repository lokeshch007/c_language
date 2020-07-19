
typedef struct bst_node
{
	int data;
	struct bst_node* left;
	struct bst_node* right;
}bst_node_t;

extern bst_node_t* root;

extern bst_node_t* create_new_node(int data);

extern bst_node_t* bst_insert(bst_node_t* node_ptr,int data);

extern int no_of_child(bst_node_t* node_ptr);

extern bst_node_t* min_of_bst(bst_node_t* node_ptr);

extern bst_node_t* max_of_bst(bst_node_t* node_ptr);

extern bst_node_t* bst_delete(bst_node_t* node_ptr,int data);

extern bst_node_t* bst_search(bst_node_t* node_ptr,int data);

extern int bst_height(void);

extern int bst_node_height(bst_node_t *node_ptr);

extern int bst_node_depth(bst_node_t *node_ptr);

extern void bst_print_inorder(bst_node_t* node_ptr);

extern void bst_print_in_2d(bst_node_t* node_ptr,int space);

extern int bst_size(bst_node_t* node_ptr);

extern bst_node_t* bst_free(bst_node_t* root);

