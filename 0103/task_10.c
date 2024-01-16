#include <stdio.h>

int main(){
	int i;
	int number;
	printf("ENTER number: ");
	scanf("%d",&number);

	for (i=number;i>0;i--){
		for (int n=i;n>0;n--){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

