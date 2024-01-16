#include <stdio.h>
#include <stdlib.h>
typedef struct St{
	int math, sci, his;
	double avg;
}St;

void avg(St *a, int num){
	for (int i=0;i<num;i++){
		(*(a+i)).avg=(*(a+i)).math+(*(a+i)).sci+(*(a+i)).his;
		(*(a+i)).avg/=3;
		printf("%f\n",(*(a+i)).avg);
	}
}

int main(){
	int num;
	printf("Number of students:");
	scanf("%d", &num);
	
	St *p;
	p = (St *)malloc(sizeof(St)*num);

	for (int i=0;i<num;i++){
		printf("Input score of std %d (math, sci, his): ", i+1);
		scanf("%d %d %d",&(*(p+i)).math, &(p+i)->sci, &p[i].his);
		printf("Std %d: %d %d %d\n",i+1,(*(p+i)).math, p[i].sci, p[i].his);
	}
	avg(p, num);
	return 0;
}

