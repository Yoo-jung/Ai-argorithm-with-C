#include <stdio.h>
#include <stdlib.h>

int main(){
	int num=0;
	//int *p[3];
	int **p, n, m;
	printf("Input n, m in matrix[n][m]:");
	scanf("%d %d", &n,&m);
	p=(int **)malloc(sizeof(int*)*n);
	//int [3][5];
	
	//p = (int *)malloc(sizeof(int)*3*5);
	for(int i=0;i<n;i++){
		*(p+i)/*p[i]*/ = (int *)malloc(sizeof(int)*m);// 주소를 저장
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			*(*(p+i)+j) = 0;
			*(*(p+i)+j) = 5*i+j;
			printf("p[%d][%d]: %d\n",i,j,*(*(p+i)+j));
		}
	}
	free(p);
	//p[0][1]=1;
	//printf("%d\n", p[0][1]);
	//printf("%d\n", *(*(p+0)+1));
	return 0;
}
