#include <stdio.h>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(){
	int i,j,k;

	cv::Mat img=imread("image.jpg", 1); // RGB:1 Gray:0
	w1=img.rows;
	w2=img.cols;
	
	***inp=;
	malloc
	inp[img.rows][img.cols][c]
	
	for (i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			for(k=0;k<3;k++){
				inp????=img.at<Vec3b>(i,j)[k];
				//3차원 배열 생성 후 이미지에서 읽어온 값 저장
			}
		}
	}
	// result 변수에 cv::Mat 클래스 선언
	// result에 cv->Mat->zeros에 해당 변수 넣은 return 값 저장
	for (i=0;i<img.rows;i++){
		for(j=0;j<img.cols;j++){
			for(k=0;k<3;k++){
				img.at<Vec3b>(i,j)[k]-=100;
			}
		}
	}
	imwrite("img.bmp",img);

	//conv, pool후 3중 포인터 result
	***res
	cv:Mat result = cv::Mat::zeros(?,?,CV_8UC3);
	for (i=0;i<r1;i++){
		for(j=0;j<r2;j++){
			for(k=0;k<3;k++){
				mat에다 3차원 배열 값 저장
				result=res[];
			}
		}
	}
	imwrite("result.bmp",result);
	//imwrite("result.jpg",result);
	return 0;
}
