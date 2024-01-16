#include <stdio.h>

int main(){
	int mode;
	printf("### MODE ###\n");
	printf("### 1: Hello\n");
	printf("### 2: Sing\n");
	printf("### 3: Dance\n");
	
	scanf("%d", &mode);

	switch(mode){
		case 1:
			printf("Hello~!!\n"); break;
		case 2:
			printf("Rararara~~~ Rarara~~!!!\n"); break;
		case 3:
			printf("Dungsil~ Doongsil~\n"); break;
		default:
			printf("Wrong~~~\n"); break;
	}

	return 0;
}
