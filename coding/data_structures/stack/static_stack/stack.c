#include<stdio.h>
#include"stack.h"

static int local_top=0;

int stack_init(void)
{
	top=-1;
	local_top=-1;
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

int pop(void)
{
	if(isempty())
	{
		printf("Unable to pop : stack is empty\n");
		return -1;
	}
	local_top--;
	return stack[top--];
}

int isempty(void)
{
	if(!(top^-1)) return 1;
	else return 0;
}

int isfull(void)
{
	if(!(top^(CAPACITY-1))) return 1;
	else return 0;
}

int size_of_stack(void)
{
	return top+1;
}

int peek(void)
{
	if(isempty())
	{
		printf("Stack is empty\n");
		return 0;
	}
	return stack[top];
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
