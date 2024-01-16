#include <stdio.h>
#include <stdlib.h>

int main(){
	int num=0;
	int l, n, m;
	printf("Input l, n, m in matrix[l][n][m]:");
	scanf("%d %d %d",&l,&n,&m);
	
	int ***p;
	p=(int ***)malloc(sizeof(int**)*l);
	
	for(int i=0;i<l;i++){
		*(p+i)/*p[l][m]*/ = (int **)malloc(sizeof(int*)*m);// 주소를 저장
		for (int j=0;j<m;j++){
			*(*(p+i)+j)/*p[l][m][n]*/ = (int *)malloc(sizeof(int)*n);// 주소를 저장
			for (int k=0;k<n;k++){
				*(*(*(p+i)+j)+k) = 0;
				*(*(*(p+i)+j)+k) = m*n*i+n*j+k;
				printf("p[%d][%d][%d]: %d\n",i,j,k,*(*(*(p+i)+j)+k));
			}
		}
	}
	free(p);
	//p[0][1]=1;
	//printf("%d\n", p[0][1]);
	//printf("%d\n", *(*(p+0)+1));
	return 0;
}
