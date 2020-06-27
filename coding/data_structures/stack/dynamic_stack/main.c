#include<stdio.h>
#include"stack.h"

int main(void)
{
	int opt=0,data=0;

	printf("Enter size of stack : ");
	scanf("%d",&data);
	stack_init(data);

	while(1)
	{
		printf("\n---Stack operations---\n");
		printf("1.POP\n2.PUSH\n3.PEEK\n4.PRINT STACK\n5.SIZE OF STACK\n6.RESIZE STACK\n7.EXIT\n");
		printf("Enter choice : ");
		scanf("%d",&opt);
		switch(opt)
		{
			case	1	:	if(!(pop(&data))) 
									printf("popped %d\n",data);
								else	
									printf("pop error\n");
								break;

			case	2	:	printf("Enter data : ");
								scanf("%d",&data);
								if(push(data))
										printf("push error\n");
								break;

			case	3	:	if(!(peek(&data)))
									printf("Top element is : %d\n",data);
								else
									printf("peek error\n");
								break;

			case	4	:	print_stack();
								break;

			case	5	:	if(!(size_of_stack(&data)))
									printf("Size of stack : %d\n",data);
								else 
									printf("size of stack reading error\n");
								break;

			case	6	:	printf("Enter new stack size : ");
								scanf("%d",&data);
								if(!(resize_stack(data))) 
									printf("Stack resized successfully\n");
								else
									printf("Stack resize failed\n");
			case	7	:	break;

			default	:	printf("Invalid choice\n");
								break;
		}

		if(!(opt^7)) break;
	}
	return 0;
}
