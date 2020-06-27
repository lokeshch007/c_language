#ifndef STACK_HEADER
#define STACK_HEADER

#define CAPACITY 10

int stack[CAPACITY];
int top;

extern int stack_init(void);
extern int push(int data);
extern int pop(void);
extern int isempty(void);
extern int isfull(void);
extern int size_of_stack(void);
extern int print_stack(void);
extern int peek(void);

#endif
