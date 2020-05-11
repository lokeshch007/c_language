#include<stdio.h>

typedef union
{
		struct
		{
				unsigned int pin0:1;
				unsigned int pin1:1;
				unsigned int pin2:1;
				unsigned int pin3:1;
				unsigned int pin4:1;
				unsigned int pin5:1;
				unsigned int pin6:1;
				unsigned int pin7:1;
		}PINS;
		long unsigned int value;
}PORTA;

int main(void)
{
		PORTA A1;
		A1.PINS.pin0=1;
		printf("%ld\n",sizeof(PORTA));
		printf("%d\n%d\n%x\n",A1.PINS.pin0,A1.PINS.pin1,A1.value);
		return 0;
}
