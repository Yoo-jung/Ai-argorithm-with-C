#include <stdio.h>

int adder (int a, int b){
	int sum=a+b;
	return sum;
}

int main(){
	int a, b;
	printf("Enter A value: ");
	scanf("%d",&a);
	printf("Enter B value: ");
	scanf("%d",&b);

	printf("%d + %d = %d\n",a, b, adder(a,b));
	return 0;
}
