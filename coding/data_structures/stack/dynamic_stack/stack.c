#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

static int local_top=0;
static int local_size=0;
int *ptr=NULL;

int stack_init(int size)
{
	top=-1;
	local_top=-1;
	stack=(int*)malloc(size*sizeof(int));
	local_size=size;
	if(stack==NULL)
	{
		perror("malloc() call error : ");
		exit(1);
	}
	printf("malloc: %u\n",stack);
	ptr=(int*)malloc(size*sizeof(int));
	if(ptr==NULL)
	{
		perror("malloc() call error : ");
		exit(1);
	}
	printf("2malloc: %u\n",ptr);
	printf("Stack Created successfully with %d size\n",size);
	return 0;
}

int push(int data)
{
	if(isfull())
	{
		printf("Unable to push %d : stack is full\n",data);
		return -1;
	}
	stack[++top]=data;
	++local_top;
	return 0;
}

int pop(int *data)
{
	if(isempty())
	{
		printf("Unable to pop : stack is empty\n");
		return -1;
	}
	local_top--;
	*data=stack[top--];
	return 0;
}

int isempty(void)
{
	if(!(top^-1)) return 1;
	else return 0;
}

int isfull(void)
{
	if(!(top^(local_size-1))) return 1;
	else return 0;
}

int size_of_stack(int *size)
{
	if(top<-1)
		return -1;
	*size=local_top+1;
	return 0;
}

int peek(int *data)
{
	if(isempty())
	{
		printf("Stack is empty\n");
		return -1;
	}
	*data=stack[local_top];
	return 0;
}

int print_stack(void)
{
	if(isempty()) 
	{
		printf("Empty stack\n");
		return 0;
	}
	if(!(local_top^0))
	{
		printf("| %6d |\n",stack[local_top]);
		local_top=top;
		return 0;
	}
	printf("| %6d |\n",stack[local_top--]);
	print_stack();
	return 0;
}

int resize_stack(int size)
{
	if(size<=0)
	{
		printf("Invalid stack size\n");
		return -1;
	}
	stack=(int*)realloc(stack,sizeof(int)*(size+local_size));
	if(stack==NULL)
	{
		perror("realloc() error: ");
		exit(1);
	}
	printf("raalloc: %u\n",stack);
	local_size=size;
	return 0;
}
