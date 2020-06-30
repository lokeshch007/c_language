#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

bst_node_t* root=NULL;
static int tree_ele_count=0;
static bst_node_t* temp=NULL;

bst_node_t* create_new_node(int data)
{
	bst_node_t* temp=(bst_node_t*)malloc(sizeof(bst_node_t));
	if(!temp)
	{
		perror("malloc() error: ");
		exit(1);
	}
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}


bst_node_t* bst_insert(bst_node_t* node_ptr,int data)
{
	if(!node_ptr)
	{
		node_ptr=create_new_node(data);
		if(!tree_ele_count)
		{
			root=node_ptr;
		}
		tree_ele_count++;
		return node_ptr;
	}

	if(data <= node_ptr->data)
	{
		printf("bst_insert(): Inserted child on left\n");
		node_ptr->left = bst_insert(node_ptr->left,data);
	}
	else
	{
		printf("bst_insert(): Inserted child on right\n");
		node_ptr->right = bst_insert(node_ptr->right,data);
	}
	return node_ptr;
}

int no_of_child(bst_node_t* node_ptr)
{
	if((!(node_ptr->left)) && (!(node_ptr->right)))
		return 0;
	else if((!(node_ptr->left)) || (!(node_ptr->right)))
		return 1;
	else
		return 2;

}

bst_node_t* min_of_bst(bst_node_t* node_ptr)
{
	printf("min_of_bst(): Received PTR:%u, PTR->LEFT=%u\tPTR->RIGHT=%u\n",node_ptr,node_ptr->left,node_ptr->right);
	if(!node_ptr)
	{
		return NULL;
	}

	switch(no_of_child(node_ptr))
	{
		case	0	:	/* MIN Element */
			return node_ptr;
		case	1	:	
		case	2	:/* Traverse left subtree to get min value */
			if(!node_ptr->left)/* NULL CHECK */
				return node_ptr;
			return min_of_bst(node_ptr->left);
		default:
			printf("min_of_bst(): Something went wrong\n");
			return NULL;
	}
}

bst_node_t* bst_delete(bst_node_t* node_ptr,int data)
{

	printf("bst_delete(): current node is %d\n",node_ptr->data);
	if(!node_ptr)/* NULL case */
		return NULL;
	
	if(data < node_ptr->data)
		node_ptr->left=bst_delete(node_ptr->left,data);
	else if(data > node_ptr->data)
		node_ptr->right=bst_delete(node_ptr->right,data);
	else
	{
		switch(no_of_child(node_ptr))
		{
			case	0	:	/* Leaf node */
				printf("bst_delete(): Leaf node deletion\n");
				free(node_ptr);
				return NULL;
				break;

			case	1	:	/* Had one child */
				if(node_ptr->left != NULL) /* left child exists */
				{
					printf("bst_delete(): single child on left deletion\n");
					node_ptr->data = node_ptr->left->data;
					node_ptr->right = node_ptr->left->right;
					temp=node_ptr->left->left;
					free(node_ptr->left);
					node_ptr->left=temp;
				}
				else /* right child exists */
				{
					printf("bst_delete(): single child on right deletion\n");
					node_ptr->data = node_ptr->right->data;
					node_ptr->left = node_ptr->right->left;
					temp=node_ptr->right->right;
					free(node_ptr->right);
					node_ptr->right = temp;
				}
				tree_ele_count--;
				break;

			case	2	:	/* had two child */
				/* Following MIN of right subtree replacement*/
				printf("bst_delet(): two child deletion. LEFT:%u\tRIGHT:%u\n",node_ptr->left,node_ptr->right);
				temp = min_of_bst(node_ptr->right);
				node_ptr->data = temp->data;
				node_ptr->right=bst_delete(node_ptr->right,temp->data);
				break;
		}
	}

	return node_ptr;
}

bst_node_t* bst_search(bst_node_t* node_ptr,int data)
{
	if(!node_ptr)
		return NULL;
	if(!((node_ptr->data)^data))
		return node_ptr;
	if(data < node_ptr->data)
		return bst_search(node_ptr->left,data);
	else
		return bst_search(node_ptr->right,data);
}

int bst_height(void)
{
}

int bst_node_height(int data)
{
}

int bst_node_depth(int data)
{
}

bst_node_t* get_successor(bst_node_t* node_ptr,int data)
{
	bst_node_t* current;
	current=bst_search(node_ptr,data);
	if(!current)
		return NULL;
	if(current->right)
		return min_of_bst(current->right);
}

void bst_print_inorder(bst_node_t* node_ptr)
{
	if(!node_ptr)
		return;
	bst_print_inorder(node_ptr->left);
	/* for DEBUG printf("[%u]%d[%u]\t",node_ptr->left,node_ptr->data,node_ptr->right);*/
	printf("%d\t",node_ptr->data);
	bst_print_inorder(node_ptr->right);
}

void bst_free(bst_node_t* node_ptr)
{
	if((!(node_ptr->left)) && (!(node_ptr->right))) /* Leaf node */
	{
		free(node_ptr);
		return NULL;
	}
	else if((node_ptr->left) && (!(node_ptr->right))) /* Node with left child */
	{
		node_ptr->left = bst_free(node_ptr->left);
	}
	else if((!(node_ptr->left)) && (node_ptr->right)) /* Node with right child */
	{
		node_ptr->right = bst_free(node_ptr->right);
	}
	else if((node_ptr->left)) && (node_ptr->right)) /* Node with left and right child */
	{
		node_ptr->left = bst_free(node_ptr->left);
		node_ptr->right = bst_free(node_ptr->right);
		return bst_free(node_ptr);
	}
	
}
