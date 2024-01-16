#include <stdio.h>

int print_hello(){
	printf("Hello, I'm MOON~ :)\n");
	return 0;
}

int main(){
	printf("Function run: ");
	if(print_hello()) printf("ERROR~~!!!\n");
	return 0;
}
