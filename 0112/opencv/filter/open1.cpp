#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"
#include "myFunc.cpp"
using namespace std;
using namespace cv;

int main(){
	int i,j,k;
	Neuron nn;
	cv::Mat img=imread("five.bmp", 1); // RGB:1 Gray:0
	//imshow("img",img);
	//waitKey(0);
	int F_size;
	double **F;
	int pad=1, strr, strc;
	printf("ENTER size of Filter: ");
		scanf("%d",&F_size);
		F=(double**)malloc(sizeof(double*)*F_size);
		// Enter FILTER data
		printf("ENTER number of Filter.. Format is ");
		for (int i=0;i<F_size;i++){
			printf("[ ]");
		}
		printf("\n");
		for (int f=0;f<F_size;f++){
			*(F+f)=(double*)malloc(sizeof(double)*F_size);
			printf("#%d->  ",f);
			scanf("%lf %lf %lf",*(F+f),*(F+f)+1,*(F+f)+2);
		}
	// Enter padding and Stride value
	printf("ENTER number of stride[ ][ ]: ");
	scanf("%d %d", &strr, &strc);
	
	int ***Result;
	Result=(int***)malloc(sizeof(int**)*3);
	for (int t=0;t<3;t++){
		int **result_conv,**result_pool;
		int **M;
		int M_size_r, M_size_c;//row:행(세로), col:열(가로)
		M_size_r=img.rows;
		M_size_c=img.cols;
		
		M=(int**)malloc(sizeof(int*)*M_size_r);
		// Enter MATRIX data
		for (int m=0;m<M_size_r;m++){
			*(M+m)=(int*)malloc(sizeof(int)*M_size_c);
			for (int mm=0;mm<M_size_c;mm++) {M[m][mm]=img.at<Vec3b>(m,mm)[t];}
		}
		
		// Convolution
		Neuron nn;
		nn.setPS(pad,strr,strc,M_size_r,M_size_c,F_size);
		result_conv=nn.convolution(M,F);
		// Print result
		int sizer, sizec;
		sizer = nn.sizer();
		sizec = nn.sizec();
		printf("row: %d col: %d\n",sizer,sizec); 
		printf("\n  #----- Result -----#\n");
		for (int r=0;r<sizer;r++){
			for (int c=0;c<sizec;c++){
				printf(" %3d ",result_conv[r][c]);
			}
			printf("\n");
		}

		/*
		int mode;
		printf("Pooling mode 0->MAX, 1->AVER : ");
		scanf("%d",&mode);
		nn.setPS(0,strr,strc,M_size_r,M_size_c,F_size);
		result_pool=nn.pooling(M,F_size,mode);
		sizer=sizeof(result_pool)/sizeof(int);
		sizec=sizeof(*result_pool)/sizeof(int);
		printf("\n  #----- Result -----#\n");
		for (int r=0;r<sizer;r++){
			for (int c=0;c<sizec;c++){
				printf(" %3d ",result_pool[r][c]);
			}
			printf("\n");
		}*/
		*(Result+t)=result_conv;
		free(M);
	}
	
	cv::Mat img_output=cv::Mat::zeros(4,4,CV_8UC3);
	for (i=0;i<img_output.rows;i++){
		for(j=0;j<img_output.cols;j++){
			for(k=0;k<3;k++){
				img_output.at<Vec3b>(i,j)[k]=Result[k][i][j];
			}
		}
	}
	imwrite("img_output.bmp",img_output);
	free(F);
	free(Result);
	return 0;
}
