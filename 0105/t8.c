#include <stdio.h>

int score_box();

int main(){
	double score[6] = {100,87,93};
	score_box(score);
	printf("sum: %f, avr; %f\n",score[3], score[4]);
	return 0;
}

int score_box(double *a){
	double sum=0;
	for (int i=0;i<3;i++){
		sum+=a[i];
	}
	a[3]=sum;
	a[4]=sum/3.0;
	return 0;
}
