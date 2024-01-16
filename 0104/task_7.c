#include <stdio.h>

int main(){
	int arr [4][3][5]={1,1,1,1,1,1,2,3,4,5,5,4,1,2,3,0};

	int i, k, j;

	for (i=0;i<4;i++){
		for (j=0;j<3;j++){
			for (k=0;k<5;k++){
				printf("%d",arr[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
