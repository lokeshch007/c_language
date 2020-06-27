#include<stdio.h>
#include"single_circular_linked_list.h"

int list_size =0;

int main(void)
{
	int opt=0,data=0,pos=0;
	node_t *root=NULL;

	while(1)
	{
		printf("\n---LINKED LIST operations---\n");
		printf("1.Add element at end\n2.Add element at start\n3.Delete at end\n4.Delete at start\n5.Add element at position\n6.Delete element at position\n7.Print List\n8.Print size of list\n9.Exit\n");
		printf("Enter choice : ");
		scanf("%d",&opt);
		switch(opt)
		{
			case	1	:	/* Add element at end */
								printf("Enter data : ");
								scanf("%d",&data);
								if(!list_size)
									root=add_node_at_head(root,data);
								else if(!(add_node_position(root,list_size,data)-1))
									printf("Unable to add element\n");
								break;

			case	2	:	/* Add element at start */
								printf("Enter data : ");
								scanf("%d",&data);
								root=add_node_at_head(root,data);
								break;

			case	3	:	/* Delete at end */
								if(!(delete_node_position(root,list_size-1)^-1))
										printf("unable to delete element\n");
								break;

			case	4	:	/* Delete at start */
								root=delete_node_at_head(root);
								break;
			
			case	5	:	/* Add element at position */
								printf("Enter position : ");
								scanf("%d",&pos);
								printf("Enter data : ");
								scanf("%d",&data);
								if(!(pos^0))
									root=add_node_at_head(root,data);
								else if(!(add_node_position(root,pos,data)-1))
									printf("Unable to add element\n");
								break;

			case	6	:	/* Delete element at position */
								printf("Enter position : ");
								scanf("%d",&pos);
								if(!pos)/* Delete node at head */
									root=delete_node_at_head(root);
								else if(!(delete_node_position(root,pos)^-1))
										printf("unable to delete element\n");
								break;

			case	7	:	/* Print list */
								print_list(root);
								break;

			case	8	:	/* Print size of list */
								printf("Size of list is : %d\n",list_size);
								break;

			case	9	:	/* Exit */
								break;

			default	:	/* Invalid choice */
								printf("Invalid choice\n");
								break;
		}

		if(!(opt^9)) break;
	}
	free_list(root);
	return 0;

}
