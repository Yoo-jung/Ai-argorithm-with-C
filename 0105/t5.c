#include <stdio.h>

int main(){
	int score[10]={95,47,28,62,86,77,20,98,36,59};
	int *p=score;
	int max=0, n=0, num=0;

	while(p-score<10){
		if(*p>max) {max=*p; num=n;}
		p++;
		n++;
	}
	printf("Max score is score[%d]'s %d\n", num, max);
	return 0;
}


