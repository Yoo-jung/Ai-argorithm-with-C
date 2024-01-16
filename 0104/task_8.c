#include <stdio.h>

int main(){
	int arr1[4][4]={1,2,3,4,5,6,7,8,
	9,10,11,12,13,14,15,16};
	int arr2[4][4]={1,0,0,0,0,1,0,0,
		0,0,1,0,0,0,0,1};
	int arr_s[4][4];
	int arr_m[4][4]={};
	int i, j;

	printf("SUM		MULT\n");
	for (i=0;i<4;i++){
		for(j=0;j<4;j++){
			arr_s[i][j]=arr1[i][j]+arr2[i][j];
			for (int n=0;n<4;n++){
				arr_m[i][j]+=arr1[i][n]*arr2[n][j];
			}
			printf("%d ",arr_s[i][j]);
		}
		//print array mult
		printf("	");
		for (j=0;j<4;j++){
			printf("%d ",arr_m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

