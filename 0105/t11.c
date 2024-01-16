#include <stdio.h>
struct scr{
	char name[50];
	int score[5];
	int total, avr;
	int pass_fail;
};

int score(struct scr *a){
	int sum=0;
	for (int j=0;j<3;j++){
		a[j].score[0]=100;
		a[j].score[1]=97;
		a[j].score[2]=98;

		for (int i=0; i<3; i++){
			sum +=a[j].score[i];
		}
		printf("total: %d\n", sum);
		printf("avr: %.2f\n",sum/3.0);
	}
	return 0;
}

int main(){
	int i;
	struct scr a[10];
	score(a);
		
	return 0;
}
