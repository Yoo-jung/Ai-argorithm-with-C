#include <stdio.h>

int main(){
	int a[4] = {1,2,3,4};
	int b[2] = {3,4};
	int *p;

	p=a; //p=&a;
	int i=0;	
	while(p-a<4){
		printf("a: %d\n",a);
		printf("p: %d\n",p);
		printf("*p: %d\n",*p);
		//printf("*(a+2): %d\n",*(a+2));
		p++;
	}
	return 0;
}
