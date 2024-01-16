#include <stdio.h>

int main(){
	int kor; int eng; int mat;
	double avr;
	printf("Enter Your Score of Korean: ");
	scanf("%d", &kor);
	printf("Enter Your Score of English: ");
	scanf("%d", &eng);
	printf("Enter Your Score of Math: ");
	scanf("%d", &mat);
	avr = (double)(kor+eng+mat)/3;
	printf("\n** Your Total Average score is %.2f\n", avr);
	
	printf("\n*** 등급 ***\n");
	if (avr<=100&&avr>=95){
		printf("축하합니다. 당신은 특별 장학생입니다.\n");
	}else if(avr<95&&avr>=90){
		printf("당신은 장학생입니다!\n");
	}else if(avr<90&&avr>=50){
		printf("수고하셨습니다...\n");
	}else if(avr<50){
		printf("!!! 학사 경고 !!!\n");
	}else{
		printf("ERROR::!!!");
	}

	return 0;
}
