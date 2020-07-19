#include<stdio.h>
#include"avl.h"

/* some bugs are there in AVL tree implementation still */

int main(void)
{
	int opt=0,data=0;
	avl_node_t* main_temp=NULL;

	while(1)
	{
		printf("\n\n---TREE OPERATIONS---\n");
		printf("0.EXIT\n1.Insert\n2.Search\n3.Print\n4.Delete\n5.Min element\n6.Max element\n7.Height of element\n8.Print Tree in 2D\n");
		printf("9.Size of tree\n");
		printf("Enter your choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case	0	:	/* EXIT */
								break;
			case	1	:	/* Insert */
								printf("Enter data: ");
								scanf("%d",&data);
								avl_insert(root,data);
								break;

			case	2	:	/* Search */
								printf("Enter data: ");
								scanf("%d",&data);
								if(avl_search(root,data))
									printf("Element FOUND\n");
								else
									printf("Element NOT FOUND\n");
								break;

			case	3	:	/* PRINT */
								avl_print_inorder(root);
								break;

			case	4	:	/* Delete */
								printf("Enter data: ");
								scanf("%d",&data);
								avl_delete(root,data);
								break;

			case	5	:	/* Min Value */
								if(main_temp=min_of_avl(root))
									printf("Min element is : %d\n",main_temp->data);
								else
									printf("NULL POINTER\n");
								break;

			case	6	:	/* Max Value */
								if(main_temp=max_of_avl(root))
									printf("Max element is : %d\n",main_temp->data);
								else
									printf("NULL POINTER\n");
								break;

			case	7	:	/* Height of element */
								printf("Enter data: ");
								scanf("%d",&data);
								if(main_temp=avl_search(root,data))
									printf("Height of %d is %d\n",main_temp->data,avl_node_height(main_temp));
								else
									printf("Element not found\n");
								break;

			case	8	:	/* Print Tree in 2D */
								avl_print_in_2d(root,0);
								break;

			case	9	:	/* Size of tree */
								printf("\nSize of tree : %d\n",avl_size(root));
								break;

			default	:	/* Invalid choice */
								printf("INVALID CHOICE\n");
								break;

		}
		if(!opt)
			break;
	}
	avl_free(root);
	return 0;
}
