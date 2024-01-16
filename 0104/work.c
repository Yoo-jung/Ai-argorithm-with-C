#include <stdio.h>

int main(){
	int s[10]={}, avr=0;
	// scan scores
	printf("ENTER scores!!!\n");
	for (int i=0;i<10;i++){
		printf("Score %d:",i);
		scanf("%d",s[i]);
		avr+=s[i];
	}
	avr/=10;
	


	int i;

	for (i=0;i<10;i++){
		printf("&s[%d]: %x\n",i,&s[i]);
	}
	printf("&s: %x\n", &s);
	printf("s: %x\n", s);

	printf("s+1: %x\n", s+1);
	printf("&s[1]: %x\n", &s[1]);
	printf("*(s+1): %x\n", *(s+1));
	printf("s[1]: %x\n", s[1]);
	
	return 0;
}
