#include <stdio.h>
struct scr{
	char name[50];
	int score[5];
	double total, avg;
	int pass_fail;
};

int score(struct scr *a){
	for (int j=0;j<3;j++){
		(*(a+j)).score[0]=100;
		(*(a+j)).score[1]=95;
		(*(a+j)).score[2]=98;
		(*(a+j)).total=0;
		for (int i=0;i<3;i++){
			(*(a+j)).total += (*(a+j)).score[i];
		}
		(*(a+j)).avg=(*(a+j)).total/3.0;
		printf("sum: %.2f \n",(*(a+j)).total);
		printf("avg: %.2f \n",(*(a+j)).avg);
	}
	return 0;
}

int main(){
	struct scr a[10];
	score(a);
	printf("Avg: %.2f\n",a[0].avg);	
	return 0;
}
