#include<stdio.h>

int main(void)
{
		int a=100,hexa=0xff;
		printf("%d<<1 = %d\t %d*2^1 = %d\n",a,a<<1,a,a*2);
		printf("%d>>1 = %d\t %d/2^1 = %d\n",a,a>>1,a,a/2);
		printf("%x<<1 = %x\t %x*2^1 = %x\n",hexa,hexa<<1,hexa,hexa*2);
		printf("%x>>1 = %x\t %x/2^1 = %x\n",hexa,hexa>>1,hexa,hexa/2);
		return 0;
}
