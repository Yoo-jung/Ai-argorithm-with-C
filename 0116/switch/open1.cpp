#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"
#include "myFunc.cpp"
using namespace std;
using namespace cv;

int main(){
	int i,j,k;
	Neuron nn;
	cv::Mat img=imread("Me.png", 1); // RGB:1 Gray:0
	//imshow("img",img);
	//waitKey(0);
	int F_size;
	double **F;
	int pad=0, strr, strc;
	int sizer, sizec;
	
	
	int ***Result;
	Result=(int***)malloc(sizeof(int**)*3);
	int **result_conv,**result_pool;
	int **M;
	int M_size_r, M_size_c;//row:행(세로), col:열(가로)
	M_size_r=img.rows;
	M_size_c=img.cols;
	for (int t=0;t<3;t++){
		M=(int**)malloc(sizeof(int*)*M_size_r);
		*(Result+t)=(int**)malloc(sizeof(int*)*M_size_r);
		// Enter MATRIX data
		for (int m=0;m<M_size_r;m++){
			*(M+m)=(int*)malloc(sizeof(int)*M_size_c);
			*(*(Result+t)+m)=(int*)malloc(sizeof(int)*M_size_c);
			for (int mm=0;mm<M_size_c;mm++) {M[m][mm]=img.at<Vec3b>(m,mm)[t];}
		}
		// 좌우반전
		for (int m=0;m<M_size_r;m++){
			for (int mm=0;mm<M_size_c;mm++) {Result[t][m][mm]=M[m][M_size_c-mm];}
		}
	}
	cv::Mat img_output=cv::Mat::zeros(M_size_r,M_size_c,CV_8UC3);
	for (i=0;i<img_output.rows;i++){
		for(j=0;j<img_output.cols;j++){
			for(k=0;k<3;k++){
				img_output.at<Vec3b>(i,j)[k]=Result[k][i][j];
			}
		}
	}
	imwrite("output_Me.bmp",img_output);
	return 0;
}
