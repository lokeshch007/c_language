#include<stdio.h>
#include"stack.h"

int main(void)
{
	int opt=0,data=0;

	stack_init();

	while(1)
	{
		printf("\n---Stack operations---\n");
		printf("1.POP\n2.PUSH\n3.PEEK\n4.PRINT STACK\n5.SIZE OF STACK\n6.EXIT\n");
		printf("Enter choice : ");
		scanf("%d",&opt);
		switch(opt)
		{
			case	1	:	printf("popped %d\n",pop());
								break;

			case	2	:	printf("Enter data : ");
								scanf("%d",&data);
								push(data);
								break;

			case	3	:	printf("Top element is : %d\n",peek());
								break;

			case	4	:	print_stack();
								break;

			case	5	:	printf("Size of stack : %d\n",size_of_stack());
								break;

			case	6	:	break;

			default	:	printf("Invalid choice\n");
								break;
		}

		if(!(opt^6)) break;
	}
	return 0;
}
