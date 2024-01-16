#include <stdio.h>

int main(){
	int a;
	printf("한자리 자연수 입력:");
	scanf("%d", &a);

	if (a%2==0){
		printf("Input number is even number\n");
	}
	else{
		printf("Input number is odd number\n");
	}

	return 0;
}
