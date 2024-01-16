#include <stdio.h>

int add (int a, int b){
	int sum=a+b;
	return sum;
}
int sub (int a, int b){
	int sub=a-b;
	return sub;
}
int mult (int a, int b){
	int mult=a*b;
	return mult;
}
double div (int a, int b){
	double div=(double)a/b;
	return div;
}
double mod (int a, int b){
	double rem=a%b;
	return rem;
}

int main(){
	int cal,a,b;
	int result;
	double result1;
	printf("** Select wanted calculation...\n");
	printf("** 1:add 2:sub 3:mult 4:div 5:mod\n");
	scanf("%d", &cal);
	printf("Enter Two value: ");
	scanf("%d %d",&a, &b);
	
	switch(cal){
		case 1: result=add(a,b);
			printf("ADD: %d + %d = %d\n", a, b, result);
			break;
		case 2: result=sub(a,b);
			printf("SUB: %d - %d = %d\n", a, b, result);
			break;
		case 3: result=mult(a,b);
			printf("MULT: %d * %d = %d\n", a, b, result);
			break;
		case 4: result1=div(a,b);
			printf("DIV: %d / %d = %.2f\n", a, b, result1);
			break;
		case 5: result1=mod(a,b);
			printf("MOD: %d %% %d = %.2f\n", a, b, result1);
			break;
	}
	//printf("Mode num is %d\n", cal);
	//printf("Result is %d
	return 0;
}
