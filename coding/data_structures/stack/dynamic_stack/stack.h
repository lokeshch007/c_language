#ifndef STACK_HEADER
#define STACK_HEADER

int *stack;
int top;

extern int stack_init(int size);
extern int push(int data);
extern int pop(int *data);
extern int isempty(void);
extern int isfull(void);
extern int size_of_stack(int *size);
extern int print_stack(void);
extern int peek(int *data);
extern int resize_stack(int size);

#endif
