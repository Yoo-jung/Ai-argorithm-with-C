#include <stdio.h>

int change(int *pa, int *pb){
	printf("Start Change box~!!!\n");
	printf("pa is %x, pa value is %d in this function.\n",pa,*pa);
	printf("pb is %x, pb value is %d in this function.\n",pb,*pb);
	
	int temp;
	temp=*pa;
	*pa=*pb;
	*pb=temp;
	printf("Close Change box...\n");
	return *pa, *pb;
}
int main(){
	int a=10, b=5;
        int *pa=a, *pb=b;
	printf("a: %d	b: %d\n",a,b);
	printf("\n");
	a, b = change(&a, &b);
	printf("\n");
	printf("a: %d	b: %d\n",a,b);

	return 0;
}	
