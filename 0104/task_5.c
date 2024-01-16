#include <stdio.h>
int pf(int a){
	if (a>=60) printf("Pass!!!\n");
	else printf(" FAIL...\n");
	return 0;
	}

int main(){
	int std[10];
	int i;
	for (i=0;i<10;i++){
		printf("ENTER Student %d's scores:",i+1);
		scanf("%d",&std[i]);
	}
	double avr=0;
	for (i=0; i<10; i++){
		avr+=std[i];
	}
	avr=avr/10;
	printf("\n\n###########################\n");
	printf("Average Score is %.2f\n",avr);
	printf("\n\n###########################\n");
	for (i=0; i<10;i++){
		printf("Student %d is ", i+1);
		pf(std[i]);
	}
	
	return 0;
}

