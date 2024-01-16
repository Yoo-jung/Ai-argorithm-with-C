#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"
#include "myFunc.cpp"
using namespace std;
using namespace cv;

int main(){
	// Initial values
	int **M, **F; // Matrix and Filter
	int **result;
	int time; // 3D Matrix (M*M*time)
	int mode; //select mode->convolution & pooling(->average & max)
	
	// Select what to do using 'mode' value [convolution: 0, pooling:1]
	printf("What you want to do? [convolution: 0, pooling:1]: ");
	scanf("%d",&mode);
	
	// Input repeat time & create Result Matrix
	printf("What time? ");
	scanf("%d",&time);
	
	// time번 반복
	for(int t=0;t<time;t++){
		
		int M_size_r, M_size_c, F_size;//row:행(세로), col:열(가로)
		printf("ENTER size of Matrix[row][col]: ");
		scanf("%d %d",&M_size_r, &M_size_c);
		printf("ENTER size of Filter: ");
		scanf("%d",&F_size);

		M=(int**)malloc(sizeof(int*)*M_size_r);
		F=(int**)malloc(sizeof(int*)*F_size);
		
		// Enter MATRIX data
		printf("ENTER number of Matrix.. Format is ");
		for (int i=0;i<M_size_c;i++){
			printf("[ ]");
		}
		printf("\n");
		for (int m=0;m<M_size_r;m++){
			*(M+m)=(int*)malloc(sizeof(int)*M_size_c);
			printf("#%d->  ",m);
			scanf("%d %d %d %d",&M[m][0],&M[m][1],&M[m][2],&M[m][3]);
		}
		
		int pad, strr, strc;
		Neuron nn;
		if(!mode){
			// Convolution
			printf("Convolution!!!\n");
			// Enter FILTER data
			printf("ENTER number of Filter.. Format is ");
			for (int i=0;i<F_size;i++){
				printf("[ ]");
			}
			printf("\n");
			int sum=0;
			for (int f=0;f<F_size;f++){
				*(F+f)=(int*)malloc(sizeof(int)*F_size);
				printf("#%d->  ",f);
				scanf("%d %d %d",*(F+f),*(F+f)+1,*(F+f)+2);
				sum+=F[f][0]+F[f][1]+F[f][2];
			}
			// FILTER CHECK
			if(sum!=0){
				printf("Sum of filter isn't ZERO...\n");
				for (int f=0;f<F_size;f++){
					for (int ff=0;ff<F_size;ff++){
						F[f][ff]/=sum;
					}
				}
			}
			// Enter padding and Stride value
			printf("ENTER number of pad[ ] stride[ ][ ]: ");
			scanf("%d %d %d", &pad, &strr, &strc);
			nn.setPS(pad,strr,strc,M_size_r,M_size_c,F_size);
			result=nn.convolution(M,F);
		}
		else{
			// Pooling
			printf("Pooling!!!\n");
			// Enter Stride value
			printf("ENTER number of stride[ ][ ]: ");
			scanf("%d %d", &strr, &strc);
			int pmode;
			nn.setPS(0,strr,strc,M_size_r,M_size_c,F_size);
			printf("Pooling mode 0->MAX, 1->AVER : ");
			scanf("%d",&pmode);
			result=nn.pooling(M,F_size,pmode);
		}
		
		// Print result
		int sizer, sizec;
		sizer=nn.sizer();
		sizec=nn.sizec();
		printf("\n  #----- Result -----#\n");
		for (int r=0;r<sizer;r++){
			for (int c=0;c<sizec;c++){
				printf(" %3d ",result[r][c]);
			}
			printf("\n");
		}
	}
	return 0;
}
