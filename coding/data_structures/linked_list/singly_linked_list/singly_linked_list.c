#include<stdio.h>
#include<stdlib.h>
#include"singly_linked_list.h"

int add_node(single_node_t *head,int data)
{
	if(!head)/*Null head pointer*/
	{
		printf("Null Head pointer\n");
		return 1;
	}
	else
	{
		/* Traverse untill end of list*/
		while(head->next_node_addr)
		{
			head=head->next_node_addr;
		}
		head->next_node_addr=(single_node_t*)malloc(sizeof(single_node_t));
		head=head->next_node_addr;
		head->data=data;
		head->next_node_addr=NULL;
	}

	return 0;
}

int delete_node(single_node_t *head,int node_num)
{
	int i=0;
	single_node_t prev_node;
	if(!head)/*Null head pointer*/
	{
		printf("Null Head pointer\n");
		return 1;
	}
	else
	{
		while(head->next_node_addr)
		{
			prev_node.next_node_addr=head;
			head=head->next_node_addr;
			if(!(i^node_num))
			{

			}
		}
	}
	return 0;
}
