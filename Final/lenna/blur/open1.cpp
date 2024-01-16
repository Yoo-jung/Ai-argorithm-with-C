#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"
#include "myFunc.cpp"
using namespace std;
using namespace cv;

int main(){
	int i,j,k;
	Neuron nn;
	cv::Mat img=imread("image.jpg", 1); // RGB:1 Gray:0
	//imshow("img",img);
	//waitKey(0);
	int F_size;
	double **F;
	int pad=0, strr, strc;
	int sizer, sizec;
	
	printf("ENTER size of Filter: ");
		scanf("%d",&F_size);
		F=(double**)malloc(sizeof(double*)*F_size);
		// Enter FILTER data
		printf("\n");
		for (int f=0;f<F_size;f++){
			*(F+f)=(double*)malloc(sizeof(double)*F_size);
				for (int ff=0;ff<F_size;ff++){
					F[f][ff]=1*(1.0/(F_size*F_size));
				}
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
		sizer=nn.sizer();
		sizec=nn.sizec();
		printf("\n  #----- Result -----#\n");
		for (int r=0;r<sizer;r++){
			for (int c=0;c<sizec;c++){
				printf(" %3d ",result_conv[r][c]);
			}
			printf("\n");
		}
		*(Result+t)=result_conv;
	}
	
	cv::Mat img_output=cv::Mat::zeros(sizer,sizec,CV_8UC3);
	for (i=0;i<img_output.rows;i++){
		for(j=0;j<img_output.cols;j++){
			for(k=0;k<3;k++){
				img_output.at<Vec3b>(i,j)[k]=Result[k][i][j];
			}
		}
	}
	imwrite("img_output_10.bmp",img_output);
	return 0;
}
