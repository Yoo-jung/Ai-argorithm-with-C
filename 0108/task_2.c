#include <stdio.h>

struct Test{
	int a, b;
};
int int_st(struct Test *st, int a, int b){
	//(*st).a=a;
	st->a=a;
	//(*st).b=b;
	st->b=b;
}
int main(){
	struct Test st1={1,2};
	int_st(&st1,1,2);
	printf("st1's a:%d, b:%d\n", st1.a, st1.b);
return 0;
}
