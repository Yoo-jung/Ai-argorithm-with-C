#include <stdio.h>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(){
	int i,j,k;

	cv::Mat result = cv::Mat::zeros(20,20,CV_8UC3);
	// result 변수에 cv::Mat 클래스 선언
	// result에 cv->Mat->zeros에 해당 변수 넣은 return 값 저장
	for (i=0;i<result.rows;i++){
		for(j=0;j<result.cols;j++){
			for(k=0;k<3;k++){
				if(i%3==0) result.at<Vec3b>(i,j)[0]=255;
				if(i%3==1) result.at<Vec3b>(i,j)[1]=255;
				if(i%3==2) result.at<Vec3b>(i,j)[2]=255;
			}
		}
	}
	imwrite("result.bmp",result);

	return 0;
}
