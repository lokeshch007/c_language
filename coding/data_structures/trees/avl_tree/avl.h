
typedef struct avl_node
{
	int data;
	struct avl_node* left;
	struct avl_node* right;
	int height;
}avl_node_t;

extern avl_node_t* root;

extern avl_node_t* create_new_node(int data);

extern avl_node_t* avl_rightrotate(avl_node_t* node_ptr);

extern avl_node_t* avl_leftrotate(avl_node_t* node_ptr);

extern int avl_balance(avl_node_t* node_ptr);

extern avl_node_t* avl_insert(avl_node_t* node_ptr,int data);

extern int no_of_child(avl_node_t* node_ptr);

extern avl_node_t* min_of_avl(avl_node_t* node_ptr);

extern avl_node_t* max_of_avl(avl_node_t* node_ptr);

extern avl_node_t* avl_delete(avl_node_t* node_ptr,int data);

extern avl_node_t* avl_search(avl_node_t* node_ptr,int data);

extern int avl_height(void);

extern int avl_node_height(avl_node_t *node_ptr);

extern int avl_node_depth(avl_node_t *node_ptr);

extern void avl_print_inorder(avl_node_t* node_ptr);

extern void avl_print_in_2d(avl_node_t* node_ptr,int space);

extern int avl_size(avl_node_t* node_ptr);

extern avl_node_t* avl_free(avl_node_t* root);

