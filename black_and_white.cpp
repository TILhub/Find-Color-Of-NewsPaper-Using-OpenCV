/*
18-03-2018
Author: Sahil Malik
Technology Used:OpenCV 3.3.0, C++11 
*/
#include <iostream>
#include <string>
#include <algorithm>
#include "opencv2\core\core.hpp"
#include "opencv2/face.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\opencv.hpp"
#define COLOR_THRESHOLD 1
using namespace std;
using namespace cv;
int main(int a,char* ch[])
{
	if(a==1)	return -1;
	Mat img = imread("e:/test5.jpg", CV_LOAD_IMAGE_COLOR);
	//imshow("SAM", img);
	if (img.empty())
	{
		cout << "File Not Found\n";
		return -1;
	}

	//waitKey(100);
	int rr = img.rows;
	int c = img.cols;
	int b=0, g=0, r = 0;
	for (int i = 0;i < rr;i++) {
		for (int j = 0;j < c;j++) {
			if (abs(img.at<Vec3b>(i, j)[0] - img.at<Vec3b>(i, j)[1])<= COLOR_THRESHOLD)		b++;
			if (abs(img.at<Vec3b>(i, j)[1] - img.at<Vec3b>(i, j)[2]) <= COLOR_THRESHOLD)	g++;
			if (abs(img.at<Vec3b>(i, j)[2] - img.at<Vec3b>(i, j)[0]) <= COLOR_THRESHOLD)	r++;
		}
	}
	int diff = b + g + r;
	float f = float(diff / (rr*c));
	cout << f << endl;
	if (f >= 1)	return 1;	//color
	else 	return 0;	//bw
	return 0;
}