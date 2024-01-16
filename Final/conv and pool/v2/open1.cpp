#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"
#include "myFunc.cpp"
using namespace std;
using namespace cv;

int main(){
	// Initial values
	int ***M, **F; // Matrix and Filter
	int **result;
	int time; // 3D Matrix (M*M*time)
	int mode; //select mode->convolution & pooling(->average & max)
	
	
	// Select what to do using 'mode' value [convolution: 0, pooling:1]
	printf("What you want to do? [convolution: 0, pooling:1]: ");
	scanf("%d",&mode);
	
	// Input repeat time & create Result Matrix
	printf("What time? ");
	scanf("%d",&time);
	M=(int***)malloc(sizeof(int**)*time);
	
	// time번 반복
	for(int t=0;t<time;t++){
		int M_size_r, M_size_c, F_size;//row:행(세로), col:열(가로)
		printf("ENTER size of Matrix[row][col]: ");
		scanf("%d %d",&M_size_r, &M_size_c);
		printf("ENTER size of Filter: ");
		scanf("%d",&F_size);

		*(M+t)=(int**)malloc(sizeof(int*)*M_size_r);
		F=(int**)malloc(sizeof(int*)*F_size);
		
		// Enter MATRIX data
		printf("ENTER number of Matrix.. Format is %d x %d\n", M_size_r, M_size_c);
		for (int m=0;m<M_size_r;m++){
			*(*(M+t)+m)=(int*)malloc(sizeof(int)*M_size_c);
			for (int mm=0;mm<M_size_c;mm++){scanf("%d",&M[t][m][mm]);}
		}
		
		int pad, strr, strc;
		Neuron nn;
		if(!mode){
			// Convolution
			printf("\n##---> Convolution!!!\n");
			// Enter FILTER data
			printf("ENTER number of Filter.. Format is %d x %d\n", F_size, F_size);
			for (int f=0;f<F_size;f++){
				*(F+f)=(int*)malloc(sizeof(int)*F_size);
				for (int ff=0;ff<F_size;ff++){scanf("%d",&F[f][ff]);}
			}
			// FILTER CHECK
			int sum=0;
			for (int f=0;f<F_size;f++){
				for (int ff=0;ff<F_size;ff++){
					sum+=F[f][ff];
				}
			}
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
			result=nn.convolution(*(M+t),F);
		}
		else{
			// Pooling
			printf("\n##---> Pooling!!!\n");
			// Enter Stride value
			printf("ENTER number of stride[ ][ ]: ");
			scanf("%d %d", &strr, &strc);
			int pmode;
			nn.setPS(0,strr,strc,M_size_r,M_size_c,F_size);
			printf("Pooling mode 0->MAX, 1->AVER : ");
			scanf("%d",&pmode);
			result=nn.pooling(*(M+t),F_size,pmode);
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
