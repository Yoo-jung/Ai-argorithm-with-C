#include <stdio.h>

int main(){
	int i;
	int number;
	printf("ENTER number: ");
	scanf("%d",&number);
	i=number;
	while(1){
		if(i==0) break;
		int n=i;
		while(1){
			if(n==0) break;
			printf("*");
			n--;
		}
		printf("\n");
		i--;
	}
	return 0;
}

