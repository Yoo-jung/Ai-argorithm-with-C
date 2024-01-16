#include <stdio.h>


int main(){
	int a=10;
	int * p1;

	printf("&a: %x\n",&a);
	printf("a: %d\n",a);

	p1 = &a;
	*p1 = 77;

	printf("p1: %x\n", p1);
	printf("*p1: %d\n", *p1);

	return 0;
}
