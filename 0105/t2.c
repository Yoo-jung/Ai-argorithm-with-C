#include <stdio.h>
int pf(int a){
	if (a>=60) printf("Pass!!!\n");
	else printf(" FAIL...\n");
	return 0;
	}

int main(){
	int std[10];
	int i, *p;
	p=std;

	for (i=0;i<10;i++){
		printf("ENTER Student %d's scores:",i+1);
		scanf("%d",p+i);
	}
	// Average
	double avr=0;
	while(p-std<10){
		avr+=*p;
		p++;
	}
	avr=avr/10;
	printf("\n\n###########################\n");
	printf("Average Score is %.2f\n",avr);
	//p=std;
	p-=10;
	// Pass or Fail
	printf("\n\n###########################\n");
	while (p-std<10){
		printf("Student %d is ", i+1);
		pf(*p);
		p++;
	}
	
	return 0;
}

