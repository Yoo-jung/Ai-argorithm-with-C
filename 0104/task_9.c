#include <stdio.h>

int main(){
	int a=90;
	double b=180.1;

	printf("&a: %x\n",&a);
	printf("a: %d\n", a);
	printf("&b: %x\n",&b);
	printf("b: %f\n",b);

	return 0;
}
