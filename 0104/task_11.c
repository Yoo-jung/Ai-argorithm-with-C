#include <stdio.h>

int main(){
/*	int *p, a, b;

	p=&a;
	*p=2;
	p=&b;
	*p=4;

	printf("a: %d\n",a);
	printf("b: %d\n",b);
*/
	int *p1, *p2, a, b;
	printf("&p1: %x\n",&p1);
	p1=&a;
	*p1=2;
	p2=&p1;
	printf("*p1: %d\n",*p1);
	printf("*p2: %x\n",p2);
		
	return 0;
}
