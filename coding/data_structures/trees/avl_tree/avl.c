#include<stdio.h>
#include<stdlib.h>
#include"avl.h"


#define SPACE_COUNT 5


avl_node_t* root=NULL;
static int tree_ele_count=0;
static avl_node_t* temp=NULL;

static int MAX(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}

avl_node_t* create_new_node(int data)
{
	avl_node_t* temp=(avl_node_t*)malloc(sizeof(avl_node_t));
	if(!temp)
	{
		perror("malloc() error: ");
		exit(1);
	}
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=0;
	return temp;
}

avl_node_t* avl_rightrotate(avl_node_t* node_ptr)
{
	avl_node_t *x=node_ptr->left;
	avl_node_t *temp_right=x->right;

	x->right = node_ptr;
	node_ptr->left = temp_right;

	node_ptr->height = MAX(avl_node_height(node_ptr->left),avl_node_height(node_ptr->right))+1;
	x->height = MAX(avl_node_height(x->left),avl_node_height(x->right))+1;
	return x;
}

avl_node_t* avl_leftrotate(avl_node_t* node_ptr)
{
	avl_node_t *x=node_ptr->right;
	avl_node_t *temp_left=x->left;

	x->left = node_ptr;
	node_ptr->right = temp_left;

	node_ptr->height = MAX(avl_node_height(node_ptr->left),avl_node_height(node_ptr->right))+1;
	x->height = MAX(avl_node_height(x->left),avl_node_height(x->right))+1;

	return x;
}

avl_node_t* RR(avl_node_t* node_ptr)
{
	return avl_leftrotate(node_ptr);
}

avl_node_t* RL(avl_node_t* node_ptr)
{
	node_ptr->right=avl_rightrotate(node_ptr);
	return avl_leftrotate(node_ptr);
}

avl_node_t* LL(avl_node_t* node_ptr)
{
	return avl_rightrotate(node_ptr);
}

avl_node_t* LR(avl_node_t* node_ptr)
{
	node_ptr->left = avl_leftrotate(node_ptr);
	return avl_rightrotate(node_ptr);
}

int avl_balance(avl_node_t* node_ptr)
{
	if(!node_ptr)
		return 0;
	return ((avl_node_height(node_ptr->left)) - (avl_node_height(node_ptr->right)));
}

int avl_node_height(avl_node_t *node_ptr)
{
	if(!node_ptr)
		return -1;
	return node_ptr->height;
}


avl_node_t* avl_insert(avl_node_t* node_ptr,int data)
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

	if(data < node_ptr->data)
	{
		printf("avl_insert(): Inserted child on left\n");
		node_ptr->left = avl_insert(node_ptr->left,data);
	}
	else if(data > node_ptr->data)
	{
		printf("avl_insert(): Inserted child on right\n");
		node_ptr->right = avl_insert(node_ptr->right,data);
	}
	else ;

	/* Update height of this ancestor node */
	printf("MAX(%d,%d)=%d\n",avl_node_height(node_ptr->left),avl_node_height(node_ptr->right),1+MAX(avl_node_height(node_ptr->left),avl_node_height(node_ptr->right)));
	node_ptr->height = MAX(avl_node_height(node_ptr->left),avl_node_height(node_ptr->right))+1;
	printf("%d:%d:%d\n",node_ptr->data,node_ptr->height,avl_balance(node_ptr));

	int balance = avl_balance(node_ptr);
	printf("PASSED1\n");

	/* LL Case */
	if((balance >1) && (data < (node_ptr->left->data)))
		return LL(node_ptr);
	printf("PASSED2\n");

	/* RR Case */
	if((balance < -1) && (data > (node_ptr->right->data)))
		return RR(node_ptr);
	printf("PASSED3\n");

	/* LR Case */
	if((balance > 1) && (data > (node_ptr->left->data)))
		return LR(node_ptr);
	printf("PASSED4\n");

	/* RL Case */
	if((balance < -1) && (data < (node_ptr->right->data)))
		return RL(node_ptr);
	printf("PASSED5\n");

	return node_ptr;
}

int no_of_child(avl_node_t* node_ptr)
{
	if((!(node_ptr->left)) && (!(node_ptr->right)))
		return 0;
	else if((!(node_ptr->left)) || (!(node_ptr->right)))
		return 1;
	else
		return 2;

}

avl_node_t* min_of_avl(avl_node_t* node_ptr)
{
	if(!node_ptr)
	{
		return NULL;
	}
	while(node_ptr->left)
		node_ptr=node_ptr->left;
	return node_ptr;

}

avl_node_t* max_of_avl(avl_node_t* node_ptr)
{
	if(!node_ptr)
	{
		return NULL;
	}
	while(node_ptr->right)
		node_ptr=node_ptr->right;
	return node_ptr;

}

avl_node_t* avl_delete(avl_node_t* node_ptr,int data)
{

	printf("avl_delete(): current node is %d\n",node_ptr->data);
	if(!node_ptr)/* NULL case */
		return NULL;

	if(data < node_ptr->data)
		node_ptr->left=avl_delete(node_ptr->left,data);
	else if(data > node_ptr->data)
		node_ptr->right=avl_delete(node_ptr->right,data);
	else
	{
		switch(no_of_child(node_ptr))
		{
			case	0	:	/* Leaf node */
				printf("avl_delete(): Leaf node deletion\n");
				free(node_ptr);
				return NULL;
				break;

			case	1	:	/* Had one child */
				if(node_ptr->left != NULL) /* left child exists */
				{
					printf("avl_delete(): single child on left deletion\n");
					node_ptr->data = node_ptr->left->data;
					node_ptr->right = node_ptr->left->right;
					temp=node_ptr->left->left;
					free(node_ptr->left);
					node_ptr->left=temp;
				}
				else /* right child exists */
				{
					printf("avl_delete(): single child on right deletion\n");
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
				printf("avl_delet(): two child deletion. LEFT:%u\tRIGHT:%u\n",node_ptr->left,node_ptr->right);
				temp = min_of_avl(node_ptr->right);
				node_ptr->data = temp->data;
				node_ptr->right=avl_delete(node_ptr->right,temp->data);
				break;
		}
	}

	return node_ptr;
}

avl_node_t* avl_search(avl_node_t* node_ptr,int data)
{
	if(!node_ptr)
		return NULL;
	if(!((node_ptr->data)^data))
		return node_ptr;
	if(data < node_ptr->data)
		return avl_search(node_ptr->left,data);
	else
		return avl_search(node_ptr->right,data);
}

int avl_node_depth(avl_node_t *node_ptr)
{
}


void avl_print_inorder(avl_node_t* node_ptr)
{
	if(!node_ptr)
		return;
	avl_print_inorder(node_ptr->left);
	/* for DEBUG printf("[%u]%d[%u]\t",node_ptr->left,node_ptr->data,node_ptr->right);*/
	printf(" %d\t",node_ptr->data);
	avl_print_inorder(node_ptr->right);
}

void avl_print_in_2d(avl_node_t* node_ptr,int space)
{
	int i=0;
	if(!node_ptr)
		return;

	/* Increase distance between levels */
	space += SPACE_COUNT;

	/* Process right child first */
	avl_print_in_2d(node_ptr->right,space);

	/* Print current node after space */
	printf("\n");
	for(i=SPACE_COUNT;i<space;i++)
		printf(" ");
	printf("%d:%d:%d\n",node_ptr->data,node_ptr->height,avl_balance(node_ptr));

	/* Process left child */
	avl_print_in_2d(node_ptr->left,space);

}

int avl_size(avl_node_t* node_ptr)
{
	int left_size=0,right_size=0;

	if(!node_ptr)
		return 0;

	left_size=avl_size(node_ptr->left);
	right_size=avl_size(node_ptr->right);

	return left_size+right_size+1;
}

avl_node_t* avl_free(avl_node_t* node_ptr)
{
	if((!(node_ptr->left)) && (!(node_ptr->right))) /* Leaf node */
	{
		free(node_ptr);
		return NULL;
	}
	else if((node_ptr->left) && (!(node_ptr->right))) /* Node with left child */
	{
		node_ptr->left = avl_free(node_ptr->left);
	}
	else if((!(node_ptr->left)) && (node_ptr->right)) /* Node with right child */
	{
		node_ptr->right = avl_free(node_ptr->right);
	}
	else if((node_ptr->left) && (node_ptr->right)) /* Node with left and right child */
	{
		node_ptr->left = avl_free(node_ptr->left);
		node_ptr->right = avl_free(node_ptr->right);
		return avl_free(node_ptr);
	}

}
