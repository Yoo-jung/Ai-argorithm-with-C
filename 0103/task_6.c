#include <stdio.h>

int main(){
	int score;

	printf("Enter your score: ");
	scanf("%d", &score);
	if(score>100){
		printf("ERROR::Wrong input...\n");
	}
	else if(score>=50&&score<=100){
		printf("PASS~!!!\n");
	}
	else{
		printf("FAIL...\n");
	}
	return 0;
}
