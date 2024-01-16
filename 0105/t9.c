#include <stdio.h>

void score_box();

int main(){
	int score[6] = {10,87,93,99,42,55};
	int max=0;
	int stack=0;
	score_box(score, sizeof(score)/sizeof(int),&max,&stack);
	printf("Max score is score[%d]: %d\n",stack, max);
	return 0;
}

void score_box(int *a, int n, int *max, int *s){
	for (int i=0;i<n;i++){
		if(*a>*max) {*max=*a; *s=i;}
		a++;
	}
}
