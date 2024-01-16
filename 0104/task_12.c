#include <stdio.h>

int main(){
	int data = 0x12345678, i;
	int *p1 = &data; //int *p1; p1=&data;
	char *p2;
	short *p3;

	p2=(char*)&data;
	p3=(short*)&data;

	printf("*p1: %x\n",*p1);
	printf("*p2: %x\n",*p2);
	printf("*p3: %x\n",*p3);
	
	printf("*p2+1: %x\n",*p2+1);
	printf("*(p2+1): %x\n",*(p2+1));
	printf("*(p2+2): %x\n",*(p2+2));
	printf("*(p3+1): %x\n",*(p3+1));
	
	
	return 0;
}
