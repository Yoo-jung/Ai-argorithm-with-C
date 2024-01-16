#include <stdio.h>

int main(){
	int d;
	float f;
	char s;
	
	printf("Enter flt value:");
	scanf("%f", &f);
	printf("Enter chr value:");
	scanf("%s", &s);
	printf("Enter int value:");
	scanf("%d", &d);

	printf("\n!!----------  Result  ----------!!\n");
	printf("Int is: %6d\nFlt is: %.2f\nChr is: %c\n",d,f,s);

	return 0;
}
