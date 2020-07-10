#include"double_circular_linked_list.h"
#include"queue.h"
#include<stdio.h>

node_t* q=NULL;
int max_size=0;
int cur_size=0;

int q_init(int size)
{
	if(size<=0)
	{
		printf("Invalid queue size\n");
		return -1;
	}

	max_size=size;
	q=list_init(0);
	return 0;
}

int q_enqueue(int data)
{
	if(cur_size>= max_size)
	{
		printf("Queue full\n");
		return -1;
	}
	if(!cur_size)
		q->data=data;
	else
		add_node_at_tail(q,data);
	cur_size++;
	return 0;
}

int q_dequeue(void)
{
	if(cur_size<=0)
	{
		printf("Empty queue\n");
		return -1;
	}

	q=delete_node_at_head(q);
	cur_size--;
	return 0;
}

int q_isempty(void)
{
	if(!cur_size)
		return 1;
	else
		return 0;
}

int q_isfull(void)
{
	if(!(cur_size^max_size))
		return 1;
	else
		return 0;
}

int q_front(void)
{
	if(!cur_size)
	{
		printf("Empty queue\n");
		return -1;
	}
	return q->data;

}


void q_print(void)
{
	print_list(q);
}


void q_free(void)
{
	free_list(q);
}


