#include <stdio.h>

int main(){
	int i;
	printf("1~100 사이의 7의 배수 출력\n");
	for (i=1;i<=100;i++){
		if(i%7==0){
			printf(" %d ", i);
		}
	}
	printf("\n");
	return 0;
}
