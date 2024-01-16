#include <stdio.h>

int main(){
	int n[10]={0,};
	int *p=n;
	int i=1;

	//printf("ENTER the number(0<i<10): ");
	//scanf(
	
	while (p-n<10){
		*(p+1)=*p+i;
		/*
		for (int j=0;j<=i;j++){
			*p+=j;
		}*/
		printf("n[%d] : %d\n",i,*p);
		i++;
		p++;
	}
	return 0;
}
