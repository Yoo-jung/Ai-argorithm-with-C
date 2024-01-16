#include <stdio.h>

int main(){
	int s[10]={1,2,3,4,5,6,7,8,9,10};

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
