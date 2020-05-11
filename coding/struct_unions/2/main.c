#include<stdio.h>
#include<stdlib.h>

typedef struct
{
		char name[11];
		char grade;
		int roll_no;
}student_t;

int main(void)
{
		student_t *sptr=NULL;
		sptr=(student_t*)malloc(sizeof(student_t));
		printf("Name: ");
		scanf("%s",sptr->name);
		sptr->grade='A';
		sptr->roll_no=412;
		
		printf("%s\n%c\n%d\n",sptr->name,sptr->grade,sptr->roll_no);
		free(sptr);
		return 0; 
}
