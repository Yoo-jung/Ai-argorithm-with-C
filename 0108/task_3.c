#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	int *p;
	printf("Number of element:");
	scanf("%d", &num);
	p = (int *)malloc(sizeof(int)*num);
	
	for (int i=0;i<num;i++){
		*(p+i)=i;	//p[i]=i와 같다.
	}
	for (int i=0;i<num;i++){
		printf("%d: %d \n",i,*(p+i));
	}
	free(p);

	return 0;
}
