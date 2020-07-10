#include<stdio.h>
#include"queue.h"

int main(void)
{
	int opt=0,data=0;

	printf("Enter size of queue : ");
	scanf("%d",&data);
	q_init(data);
	while(1)
	{
		printf("\n\n---QUEUE OPERATIONS---\n");
		printf("0.EXIT\n1.Enqueue\n2.Dequeue\n3.Front elemnt\n4.Size of queue\n5.print\n");
		printf("Enter your choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case	0	:	/* EXIT */
								break;
			case	1	:	/* Enqueue */
								printf("Enter data: ");
								scanf("%d",&data);
								q_enqueue(data);
								break;

			case	2	:	/* Dequeue */
								q_dequeue();
								break;

			case	3	:	/* Front element */
								data=q_front();
								printf("Front element : %d\n",data);
								break;

			case	4	:	/* Size of queue */
								printf("Size of queue : %d\n",cur_size);
								break;

			case	5	:	/* Print queue */
								q_print();
								break;

			default	:	/* Invalid choice */
								printf("INVALID CHOICE\n");
								break;

		}
		if(!opt)
			break;
	}
	q_free();
	return 0;
}
