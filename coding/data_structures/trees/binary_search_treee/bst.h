
typedef struct bst_node
{
	int data;
	struct bst_node* left;
	struct bst_node* right;
}bst_node_t;

extern bst_node_t* root;

extern bst_node_t* create_new_node(int data);

extern bst_node_t* bst_insert(bst_node_t* root,int data);

extern int no_of_child(bst_node_t* node_ptr);

extern bst_node_t* min_of_bst(bst_node_t* node_ptr);

extern bst_node_t* bst_delete(bst_node_t* root,int data);

extern bst_node_t* bst_search(bst_node_t* root,int data);

extern int bst_height(void);

extern int bst_node_height(int data);

extern int bst_node_depth(int data);

extern bst_node_t* get_successor(bst_node_t* node_ptr,int data);

extern void bst_print_inorder(bst_node_t* root);

extern void bst_free(void);

