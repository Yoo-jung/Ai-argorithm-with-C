#include <stdio.h>

struct test{
	int *p;
};

int main(){
	int i;
	struct test b;
	struct test *p;
	
	p = &b;
	b.p = &i;

	*b.p=1;
	//(*p).p==b, *(*p).p=*b.p
	*(*p).p=2;
	printf("%d \n",i);
}
