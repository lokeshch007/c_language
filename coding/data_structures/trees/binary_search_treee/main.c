#include<stdio.h>
#include"bst.h"

int main(void)
{
	int opt=0,data=0;

	while(1)
	{
		printf("\n\n---TREE OPERATIONS---\n");
		printf("0.EXIT\n1.Insert\n2.Search\n3.Print\n4.Delete\nEnter your choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case	0	:	/* EXIT */
								break;
			case	1	:	/* Insert */
								printf("Enter data: ");
								scanf("%d",&data);
								bst_insert(root,data);
								break;

			case	2	:	/* Search */
								printf("Enter data: ");
								scanf("%d",&data);
								if(bst_search(root,data))
									printf("Element FOUND\n");
								else
									printf("Element NOT FOUND\n");
								break;

			case	3	:	/* PRINT */
								bst_print_inorder(root);
								break;

			case	4	:	/* Delete */
								printf("Enter data: ");
								scanf("%d",&data);
								bst_delete(root,data);
								break;

			default	:	/* Invalid choice */
								printf("INVALID CHOICE\n");
								break;

		}
		if(!opt)
			break;
	}
	bst_free(root);
	return 0;
}
