#include <stdio.h>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(){
	int i,j,k;

	cv::Mat img=imread("image.jpg", 1); // RGB:1 Gray:0
	imshow("img", img);
	waitKey(0);

	cv::Mat result = cv::Mat::zeros(100,100,CV_8UC3);
	// result 변수에 cv::Mat 클래스 선언
	// result에 cv->Mat->zeros에 해당 변수 넣은 return 값 저장
	for (i=0;i<result.rows;i++){
		for(j=0;j<result.cols;j++){
			for(k=0;k<3;k++){
				result.at<Vec3b>(i,j)[k]=img.at<Vec3b>(i+100,j+100)[k];
			}
		}
	}
	imwrite("result.bmp",result);

	return 0;
}
