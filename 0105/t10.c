#include <stdio.h>

int main(){
	char w_1[100] = {};
	char *p=w_1;
	int i=0;

	printf("I'm Waiting you...\n");
	scanf("%[^\n]", w_1);
	printf("%s\n",p);
	
	while(p-w_1<100){
		if (!*p){break;}
		i++;
		p++;
	}
	printf("Number of Character in string : %d\n", i);
	return 0;
}
