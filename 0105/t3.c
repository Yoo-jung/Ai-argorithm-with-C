#include <stdio.h>

int main(){
	int a[2][3]={{1,2,3},{4,5,6}};

	for (int i=0;i<2;i++){
		for (int j=0;j<3;j++){
			printf("&a[%d][%d] : %x \n",i,j,&a[i][j]);
		}
	}
	printf("a: %x \n", a);
	printf("&a[0] : %x \n", &a[0]);
	printf("a[0] : %x \n", a[0]);
	printf("&a[1] : %x \n", &a[1]);
	printf("a[1] : %x \n", a[1]);
	printf("&a[0][0] : %x \n", &a[0][0]);
	printf("&a[1][0] : %x \n", &a[1][0]);

	return 0;
}
